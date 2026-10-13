<p align="center">
    <img src="https://img.shields.io/badge/Language-C%2B%2B98-blue?style=for-the-badge&logo=c%2B%2B" alt="C++98"/>
    <img src="https://img.shields.io/badge/Protocol-HTTP%2F1.0-green?style=for-the-badge" alt="HTTP/1.0"/>
    <img src="https://img.shields.io/badge/I%2FO-poll-orange?style=for-the-badge" alt="poll"/>
</p>

[Home](../../README.md)

# Webserv — Serveur HTTP non bloquant

> Projet réalisé dans le cadre du cursus 42 par jroh, whollebe et ele-moig.

## Présentation

Webserv est un serveur HTTP écrit en **C++98**. Le projet nous a permis de comprendre le fonctionnement d'un serveur réseau, depuis la création des sockets jusqu'au parsing des requêtes et à la construction des réponses.

Nous avons choisi une architecture non bloquante afin qu'un seul processus puisse gérer plusieurs serveurs, clients et exécutions CGI en parallèle. Le serveur respecte les contraintes du sujet HTTP/1.0 tout en prenant en charge les cas courants rencontrés avec des clients HTTP modernes.

## Architecture

Le serveur repose sur une boucle d'événements unique basée sur `poll()` :

1. Les sockets d'écoute sont enregistrées dans le tableau de descripteurs.
2. Une nouvelle connexion est acceptée lorsqu'une socket devient disponible.
3. Les requêtes des clients sont lues uniquement lorsqu'elles sont prêtes.
4. Le parsing transforme les données reçues en objet `Request`.
5. La réponse est construite selon la route, la méthode et la configuration associées.
6. Les données sont envoyées lorsque le descripteur est prêt à écrire.

Les pipes utilisés par les CGI sont intégrés dans la même boucle `poll()`. Ainsi, l'attente d'un script externe ne bloque pas les autres connexions. Des délais d'expiration permettent également de fermer les clients qui restent inactifs trop longtemps.

## Fonctionnalités réalisées

- Hébergement de fichiers statiques : HTML, CSS, JavaScript et médias.
- Méthodes HTTP `GET`, `POST` et `DELETE`.
- Upload de fichiers vers un répertoire configuré.
- Autoindex pour afficher le contenu d'un répertoire.
- Exécution de scripts CGI, notamment Python, avec transmission des variables d'environnement.
- Gestion des requêtes avec `Content-Length` et décodage du transfert `chunked`.
- Pages d'erreur personnalisées et pages par défaut lorsqu'aucune page n'est configurée.
- Redirections HTTP avec les codes `301` et `307`.
- Plusieurs blocs `server`, ports d'écoute et racines de documents indépendants.
- Limitation de la taille des requêtes selon la route.
- Gestion des méthodes autorisées par bloc `location`.

## Configuration

La configuration est inspirée de la syntaxe NGINX. Chaque bloc `server` définit un hôte et un port d'écoute ; chaque bloc `location` applique des règles à un préfixe d'URL.

La configuration de démonstration contient notamment :

- un serveur sur `127.0.0.1:8080` qui sert le dossier `www` ;
- un second serveur sur `127.0.0.1:9090` qui sert `www2` ;
- une route `/uploads` pour `GET`, `POST`, `DELETE` et l'autoindex ;
- une route `/cgi-bin` qui exécute les scripts `.py` avec `/usr/bin/python3` ;
- des limites de taille différentes pour les routes de test ;
- des redirections vers une autre URL, une autre route ou le second serveur ;
- une page d'erreur personnalisée pour les réponses `404`.

Extrait représentatif :

```nginx
server {
        listen 8080;
        host 127.0.0.1;
        root ./www;
        index index.html;
        error_page 404 /404_custom.html;

        location /uploads {
                allow_methods GET POST DELETE;
                upload_store ./www/uploads;
                autoindex on;
        }

        location /cgi-bin {
                allow_methods GET POST;
                cgi_ext .py;
                cgi_path /usr/bin/python3;
        }
}
```

Cette séparation entre le parsing de configuration et la logique réseau permet de modifier les routes, les droits et les ressources servies sans modifier le code du serveur.

## CGI et contenu dynamique

Lorsqu'une requête cible une extension CGI autorisée, le serveur prépare l'environnement du script à partir de la requête, crée un processus enfant et redirige sa sortie vers un pipe. Le processus parent surveille ce pipe avec `poll()` et transforme la sortie reçue en réponse HTTP.

Cette approche nous a obligés à gérer plusieurs états en parallèle : la réception du corps de la requête, l'exécution du processus enfant, la lecture de sa sortie et la fermeture propre des descripteurs à la fin du traitement.

## Compilation et tests

Le projet est compilé avec les contraintes du sujet :

```bash
make
./webserv ConfigFile/webserv.config
```

Le `Makefile` utilise `-Wall -Wextra -Werror -std=c++98`. Les commandes de nettoyage sont :

```bash
make clean
make fclean
make re
```

Vous pourrez enssuite vous connecter au webserv en tapant: http://127.0.0.1:8080 dans votre bar de recherche.

Et vous pouvez aussi tester le server avec des commandes `curl` ou `siege` pour observer directement les requêtes et les réponses. Les tests couvrent les méthodes HTTP, les erreurs, les redirections, les connexions simultanées, l'upload, l'autoindex et les scripts CGI.

Exemple de commande de test:

- `curl -i http://127.0.0.1:8080/` -> ca vous donnera le html de la page principale (www/index.html)
- `curl -i http://127.0.0.1:8080/page-inexistante` -> vous donnera la page d'erreur 404 personnalisee
- `curl -i http://127.0.0.1:8080/uploads/` -> vous donnera une page html qui liste ce qu'il y a dans /uploads
- `curl -X POST -F "file=@./www/cat.html" http://127.0.0.1:8080/uploads/` -> devrais sauvegarde le fichier dans le dossier configuré et retourne un succès (au bout de quelques secondes)
- `curl -X DELETE http://127.0.0.1:8080/uploads/ok.txt` -> devrais supprime le fichier ciblé du serveur
- `curl -X POST -d "Ceci est un message beaucoup trop long pour etre poste" http://127.0.0.1:8080/post_body` -> devrais renvoier une erreur 413 Payload Too Large
- `siege -b -c 100 -t 10S http://127.0.0.1:8080/` -> cela va lancer un "siege" de 100 personnes, qui vont se connecter en meme temps, et spam le server de request pendant 10 second, au bout des 10s, ca vous donnera un compte rendu de ce qu'il c'est passer, ce qui est interssant de regarder c'est:
    * *"transactions"* : le nombre de transaction effectuer pendant 10s.
    * *"availability"* : le pourcentage de transaction reussite.
    * *"response_time"* : le temps moyen que met le server pour repondre.
    * *"successful_transactions"* : le nombre de transaction reussite.
    * *"failed_transactions"* : le nombre de transaction echouer.
    * *"longest_transaction"* : la transaction la plus longue.
    * *"shortest_transaction"* : la transaction la plus courte.

## Ce que nous avons appris

Ce projet nous a permis de mieux comprendre :

- la création et le cycle de vie des sockets TCP ;
- le multiplexage d'entrées-sorties avec `poll()` ;
- le parsing d'un protocole textuel et de ses en-têtes ;
- la gestion d'états pour des connexions simultanées ;
- les processus, pipes et variables d'environnement pour les CGI ;
- les différences entre une réponse statique et une réponse dynamique ;
- l'importance des timeouts et de la fermeture correcte des descripteurs.

## Ressources

- [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/)
- [RFC 1945 — HTTP/1.0](https://datatracker.ietf.org/doc/html/rfc1945)
- [C++ Reference](https://en.cppreference.com/cpp)
- [Linux man-pages](https://man7.org/linux/man-pages/index.html)
- [NGINX Documentation](https://nginx.org/en/docs/beginners_guide.html)

---

[Home](../../README.md)

<p align="center">
    <i>Projet réalisé dans le cadre du cursus 42 — Cercle 5</i>
</p>