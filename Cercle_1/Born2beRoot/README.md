<p align="center">
    <img src="https://img.shields.io/badge/Project-Born2beroot-blue?style=for-the-badge" alt="Born2beroot"/>
    <img src="https://img.shields.io/badge/OS-Debian-red?style=for-the-badge&logo=debian" alt="Debian"/>
    <img src="https://img.shields.io/badge/Cursus-42-brightgreen?style=for-the-badge" alt="42"/>
</p>

[Home](../../README.md)

# Born2beRoot — Administration système

> Projet 42 consacré à la création et à la sécurisation d'une machine virtuelle Debian.

## Présentation

Born2beRoot m'a permis de mettre en place une machine virtuelle Debian avec une configuration pensée pour limiter les accès, protéger les données et garder une visibilité sur l'état du système.

L'objectif n'était pas seulement d'installer un système d'exploitation, mais de comprendre les choix qui rendent une machine administrable et plus sûre : stockage chiffré, séparation des privilèges, accès réseau limité et surveillance régulière.

## Environnement choisi

J'ai utilisé **Debian** dans une machine virtuelle **VirtualBox**.

J'ai choisi Debian parce que sa documentation est claire, que son système de paquets est adapté à l'administration système et qu'il permet de configurer chaque composant de manière explicite. La virtualisation permet de travailler dans un environnement isolé sans modifier le système principal.

La machine utilise :

- un disque virtuel au format VDI ;
- une organisation des partitions basée sur **LVM** ;
- un volume chiffré, protégé par une phrase secrète au démarrage ;
- un nom d'hôte construit à partir de mon identifiant 42.

## Gestion des utilisateurs et des privilèges

La configuration distingue le compte `root` de mon compte utilisateur personnel. Mon utilisateur appartient aux groupes nécessaires, notamment `user42` et `sudo`, afin de pouvoir administrer la machine sans travailler en permanence avec les droits administrateur.

J'ai appliqué une politique de mots de passe imposant notamment :

- une longueur minimale ;
- des caractères de natures différentes ;
- une durée de validité et un délai de modification ;
- une limitation des répétitions de caractères.

Cette séparation réduit le risque d'exécuter accidentellement une commande sensible avec les droits `root` et permet de tracer les opérations privilégiées.

## Sécurisation des services

### Sudo

`sudo` est configuré pour limiter et journaliser l'utilisation des privilèges administrateur. Cela permet d'identifier les commandes exécutées avec des droits élevés, tout en évitant une utilisation directe et permanente du compte `root`.

### SSH

L'administration distante passe par **SSH** sur le port `4242`, conformément au sujet. La connexion directe de `root` est désactivée. Ainsi, une connexion distante doit d'abord s'effectuer avec un utilisateur identifié avant toute élévation de privilèges.

### UFW

Le pare-feu **UFW** est actif et n'autorise que le port nécessaire à SSH, `4242`. Réduire le nombre de ports ouverts diminue la surface d'attaque de la machine.

## Monitoring

J'ai mis en place un script de monitoring exécuté régulièrement par `cron` et affiché avec `wall`. Il fournit notamment :

- l'architecture et la version du système ;
- le nombre de processeurs et leur utilisation ;
- la mémoire vive disponible et utilisée ;
- l'espace disque et l'utilisation des partitions ;
- la charge du système ;
- la date du dernier démarrage ;
- le nombre de connexions actives ;
- l'adresse IP et l'adresse MAC ;
- le nombre de commandes exécutées avec `sudo`.

Ce script donne un état rapide de la machine sans devoir vérifier chaque service séparément. Son exécution périodique permet également de repérer plus facilement une consommation anormale de ressources ou une modification de la configuration.

## Vérifications réalisées

J'ai vérifié la configuration à l'aide des commandes d'administration usuelles :

```bash
uname -a
lsblk
df -h
free -m
groups nom_utilisateur
sudo -l
sudo ufw status
sudo systemctl status ssh
```

Ces vérifications permettent de confirmer l'état du système, l'organisation du stockage, les groupes de l'utilisateur, les droits `sudo`, le pare-feu et le service SSH.

La signature du disque virtuel a également été conservée afin de pouvoir vérifier que la machine n'a pas été modifiée après la validation du projet.

## Ce que j'ai appris

Ce projet m'a permis de mieux comprendre :

- le fonctionnement d'une machine virtuelle et de son isolation ;
- la différence entre partitions classiques, LVM et chiffrement ;
- la gestion des utilisateurs, groupes et privilèges sous Linux ;
- le rôle de `sudo`, SSH et d'un pare-feu ;
- la planification de tâches avec `cron` ;
- la lecture des informations système dans `/proc` et via les commandes Linux ;
- l'importance de vérifier une configuration plutôt que de supposer qu'elle est correcte.

## Ressources

- [Debian Handbook](https://debian-handbook.info/)
- [Documentation VirtualBox](https://www.virtualbox.org/manual/)
- [Documentation UFW](https://help.ubuntu.com/community/UFW)

---

[Home](../../README.md)

<p align="center">
    <i>Projet réalisé dans le cadre du cursus 42 — Cercle 1</i>
</p>
