# 42 Cursus - Portfolio

Bienvenue sur mon dépôt de suivi du cursus 42. Ici, je regroupe mes projets réalisés à **42 Lausanne**.

## À propos de moi
Étudiant à **42 Lausanne**, passionné par le développement système, l'algorithmique et la programmation bas niveau en C. J'aime relever des **défis** techniques et comprendre le fonctionnement intime de la machine.

---

## Compétences (Tech Stack)

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Shell](https://img.shields.io/badge/shell_script-%23121011.svg?style=for-the-badge&logo=gnu-bash&logoColor=white)
![Git](https://img.shields.io/badge/git-%23F05033.svg?style=for-the-badge&logo=git&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![Docker](https://img.shields.io/badge/Docker-2496ED?style=for-the-badge&logo=docker&logoColor=white)
![Nginx](https://img.shields.io/badge/NGINX-009639?style=for-the-badge&logo=nginx&logoColor=white)
![MariaDB](https://img.shields.io/badge/MariaDB-003545?style=for-the-badge&logo=mariadb&logoColor=white)
![WordPress](https://img.shields.io/badge/WordPress-21759B?style=for-the-badge&logo=wordpress&logoColor=white)

* **Programmation C :** Gestion manuelle de la mémoire (`malloc`/`free`), pointeurs, listes chaînées, file descriptors, parsing et création de bibliothèques.
* **C++ :** C++98, programmation orientée objet, forme canonique orthodoxe, héritage, polymorphisme, classes abstraites, exceptions, templates et STL.
* **Système Unix :** Processus (`fork`, `exec`, `pipe`), signaux UNIX, variables d'environnement, redirections, permissions et administration Linux.
* **Concurrence :** Threads POSIX, mutex, synchronisation, gestion des ressources partagées et prévention des deadlocks.
* **Réseaux :** Sockets TCP, communication inter-processus, multiplexage avec `poll()`, protocoles HTTP/1.0, parsing de requêtes, CGI et gestion des connexions simultanées.
* **Administration système :** Machines virtuelles, Debian, LVM, chiffrement, SSH, `sudo`, UFW, politiques de mots de passe et scripts de monitoring.
* **Conteneurisation et services :** Docker, Docker Compose, réseaux bridge, volumes persistants, Docker secrets, NGINX, MariaDB, WordPress et PHP-FPM.
* **Graphisme et algorithmique :** MiniLibX, raycasting, algorithme DDA, collisions, tris optimisés, piles, arbres et analyse de complexité.
* **Outils :** Makefile, Git, Valgrind, GDB, Vim et VS Code.

---

## Projets 42 Fini

### [Cercle 0](Cercle_0)
* **[libft](Cercle_0/libft/README.md)** : Ma propre bibliothèque de fonctions C standard (plus de 40 fonctions recodées).

### [Cercle 1](Cercle_1)
* **[ft_printf](Cercle_1/ft_printf/README.md)** : Recodage complet de la fonction `printf`.
* **[get_next_line](Cercle_1/get_next_line/README.md)** : Lecture efficace d'un fichier ligne par ligne (gestion des buffers).
* **[Born2beRoot](Cercle_1/Born2beRoot/README.md)** : Administration et sécurisation d'une machine virtuelle Debian.
    * *Challenge* : Configuration du stockage chiffré, des utilisateurs, de sudo, SSH, UFW et d'un système de monitoring.

### [Cercle 2](Cercle_2)
* **[Push_Swap](Cercle_2/Push_Swap/README.md)** : Algorithme de tri de données sur pile.
    * *Challenge* : Optimisation du nombre d'opérations avec un jeu d'instructions limité.
* **[Minitalk](Cercle_2/Minitalk/README.md)** : Système de communication client/serveur via signaux.
    * *Challenge* : Transmission de données bit par bit via `SIGUSR1` et `SIGUSR2`.
* **[So_long](Cercle_2/So_long/README.md)** : Jeu 2D en C.
    * *Challenge* : Gestion d'une bibliothèque graphique (MiniLibX) et des événements clavier.

### [Cercle 3](Cercle_3)
* **[Minishell](Cercle_3/minishell/README.md)** : Création d'un shell complet type Bash.
    * *Challenge* : Parsing complexe, gestion des processus, pipes, redirections et variables d'environnement.
* **[Philosophers](Cercle_3/philo/README.md)** : Simulation du problème des philosophes (Dîner des philosophes).
    * *Challenge* : Programmation concurrente, synchronisation de threads et prévention des *deadlocks*.

### [Cercle 4](Cercle_4)
* **[cub3D](Cercle_4/cub3d/README.md)** : Moteur 3D en raycasting avec MiniLibX, textures, collisions, portes et mini-carte.
    * *Challenge* : Calculs vectoriels, algorithme DDA, parsing de cartes et gestion des événements graphiques.
* **[NetPractice](Cercle_4/NetPractice/README.md)** : Exercices interactifs d'adressage IP, de sous-réseaux et de routage statique.
    * *Challenge* : Calcul des masques CIDR, passerelles, next-hop et chemins réseau entre plusieurs routeurs.

* **[C++](Cercle_4/cpp/)**:

    * **[Module 00](Cercle_4/cpp/cpp_module_00/README.md)** : Découverte des classes, de l'encapsulation et des bases de la programmation orientée objet.
    * **[Module 01](Cercle_4/cpp/cpp_module_01/README.md)** : Gestion mémoire, pointeurs, références et pointeurs vers fonctions membres.
    * **[Module 02](Cercle_4/cpp/cpp_module_02/README.md)** : Forme canonique orthodoxe, surcharge d'opérateurs et nombres à virgule fixe.
    * **[Module 03](Cercle_4/cpp/cpp_module_03/README.md)** : Héritage simple et multiple avec la hiérarchie de robots `ClapTrap`.
    * **[Module 04](Cercle_4/cpp/cpp_module_04/README.md)** : Polymorphisme, classes abstraites, interfaces et copie profonde.

### [Cercle 5](Cercle_5)

* **[C++](Cercle_5/cpp/)**:

    * **[C++ Module 05](Cercle_5/cpp/cpp_module_05/README.md)** : Exceptions, grades, formulaires et création dynamique avec un `Intern`.
    * **[C++ Module 06](Cercle_5/cpp/cpp_module_06/README.md)** : Conversions de types, sérialisation et RTTI avec les différents casts C++.
    * **[C++ Module 07](Cercle_5/cpp/cpp_module_07/README.md)** : Templates de fonctions, itération générique et classe `Array`.
    * **[C++ Module 08](Cercle_5/cpp/cpp_module_08/README.md)** : Conteneurs STL, itérateurs, recherche générique et adaptateurs.
    * **[C++ Module 09](Cercle_5/cpp/cpp_module_09/README.md)** : Parsing, `map`, `stack`, algorithmes de tri et comparaison de performances.

* **[Webserv](Cercle_5/webserv/README.md)** : Serveur HTTP non bloquant développé en C++98.
    * *Challenge* : Gérer plusieurs clients avec `poll()`, les méthodes HTTP, les uploads, les redirections et l'exécution de scripts CGI.

* **[Inception](Cercle_5/inception/README.md)** : Infrastructure WordPress conteneurisée avec Docker Compose.
    * *Challenge* : Faire communiquer NGINX, WordPress et MariaDB via un réseau Docker, avec TLS, secrets et volumes persistants.

---

## Projets 42 en cour

### [Cercle 6](Cercle_6)
* **[ft_transcendence](Cercle_6/ft_transcendence/README.md)**:

---

## Statistiques GitHub
![Stats de Willy67flex](https://github-readme-stats.vercel.app/api?username=Willy67flex&show_icons=true&theme=tokyonight)

---

## Me contacter
* **Localisation** : Renens / Lausanne, Suisse
* **Email** : williamhollebeque@gmail.com
* **[Profil LinkedIn](https://www.linkedin.com/in/william-hollebeque-3900ab3b7/?lipi=urn%3Ali%3Apage%3Ad_flagship3_profile_view_base_contact_details%3BLynStMcqRCm4ieV0dT4GzA%3D%3D)**
