<p align="center">
  <img src="https://img.shields.io/badge/Networking-Subnetting-blue?style=for-the-badge" alt="Subnetting"/>
  <img src="https://img.shields.io/badge/Static_Routing-Labs-success?style=for-the-badge" alt="Routing"/>
  <img src="https://img.shields.io/badge/Levels-10-informational?style=for-the-badge" alt="Levels"/>
</p>

[Home](../../README.md)

# 🌐 NetPractice — Adressage et routage réseau

> Atelier interactif pour maîtriser adressage IP, masques CIDR, passerelles par défaut et routage statique, avec visualisation avant/après (`lvl/` ➜ `correction/`) et exports `git/level*.json`.

## 🎯 Objectif

NetPractice est un entraînement interactif dans le navigateur. Le but est de configurer les adresses IP, masques, passerelles et routes de chaque niveau afin de rétablir la connectivité entre les machines.

Chaque niveau dispose :
- d'une capture **initiale** dans `lvl_subject/` ;
- d'une capture **corrigée** dans `lvl_corrected/` ;

Ces artefacts montrent comment les IP, masques et routes ont été ajustés pour rétablir la connectivité.

## 🗺️ Notions rencontrées
- **Level 1 — LAN unique :** IPs cohérentes + même masque pour tous → tout le monde dans le même sous-réseau.
- **Level 2 — Masques vs classes :** corriger un masque implicite trop large (126.x en /8) vers un `/27` partagé.
- **Level 3 — Dimensionner en /25 :** deux hôtes dans la même plage, éviter adresse réseau/broadcast.
- **Level 4 — Premier routeur :** interconnexion en /28, IP de chaque côté et même masque pour traverser le routeur.
- **Level 5 — Passerelles par défaut :** hôtes pointent vers le routeur ; route amont sur le routeur sans couvrir des plages inutiles.
- **Level 6 — Edge Internet fictif :** /27 LAN, IP publique sur le routeur, route par défaut vers “Somewhere on the Net” + route de retour vers le LAN.
- **Level 7 — P2P multiples :** liens /28 chaînés, routes par défaut symétriques entre routeurs.
- **Level 8 — Résumé + next-hop :** LANs en /28, résumé /24, routes spécifiques (ex. `131.38.34.0/24` via next-hop) + défaut vers la sortie.
- **Level 9 — Deux préfixes (/25 + /18) :** transit /30, next-hop distinct pour chaque préfixe, redistribution vers “Internet”.
- **Level 10 — Masques mixtes :** /25, /26, /30 ; passerelles par segment, défaut sur le cœur, annonce du /24 partagé.

## 🚀 Utilisation

### Lancer l'interface

```bash
./net_practice.1.9/net_practice/run.sh
```

Prérequis : Python 3, `ss` et `xdg-open` ou `open` pour l'ouverture automatique du navigateur.

### Résoudre un niveau

1. Ouvrir l'onglet *Training* et choisir un niveau.
2. Renseigner les IP et masques de chaque interface.
3. Ajouter les passerelles et routes nécessaires sur les routeurs.
4. Utiliser la vérification de connectivité jusqu'à obtenir un résultat valide.

### Exporter une solution

1. Cliquer sur **Export configuration**.
2. Renommer le fichier en `levelX.json`.
3. Placer les dix exports à la racine du dépôt (`level1.json` à `level10.json`).

Les exemples de solutions sont conservés dans `submission/`.

## 🧠 Compétences développées

- Adressage IPv4 et notation CIDR
- Calcul des adresses réseau, broadcast et plages d'hôtes
- Passerelles par défaut et routage statique
- Routes par défaut, next-hop et agrégation de réseaux
- Compréhension des rôles des switches et routeurs
- Cheminement des paquets entre les couches 2 et 3 du modèle OSI

## 📂 Structure du projet

```text
NetPractice/
├── lvl_subject/       # Captures initiales des 10 niveaux
├── lvl_corrected/     # Captures corrigées
├── submission/        # Exports JSON des solutions
└── net_practice.1.9/  # Interface web et script de lancement
```

## 📚 Ressources

- [Subnetting Cheat Sheet](https://www.aelius.com/njh/subnet_sheet.html)
- [NetPractice — documentation complémentaire](https://github.com/lpaube/NetPractice)

[Home](../../README.md)

<p align="center"><i>Projet réalisé dans le cadre du cursus 42 — Cercle 4</i></p>
