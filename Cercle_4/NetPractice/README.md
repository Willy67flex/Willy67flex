*This project has been created as part of the 42 curriculum by whollebe.*

<p align="center">
  <img src="https://img.shields.io/badge/Networking-Subnetting-blue?style=for-the-badge" alt="Subnetting"/>
  <img src="https://img.shields.io/badge/Static_Routing-Labs-success?style=for-the-badge" alt="Routing"/>
  <img src="https://img.shields.io/badge/Levels-10-informational?style=for-the-badge" alt="Levels"/>
</p>

# 🌐 NetPractice — Parcours de 10 niveaux réseau

> Atelier interactif pour maîtriser adressage IP, masques CIDR, passerelles par défaut et routage statique, avec visualisation avant/après (`lvl/` ➜ `correction/`) et exports `git/level*.json`.

## 🎯 Description
NetPractice est un entraînement 100% navigateur. Chaque niveau dispose :
- d’une capture **initiale** dans `lvl_subject/` ;
- d’une capture **corrigée** dans `lvl_corrected/` ;

Ces artefacts montrent comment les IP, masques et routes ont été ajustés pour rétablir la connectivité.

## 🗺️ Aperçu des niveaux (ce que j’ai découvert et comment je les ai gérés)
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

## 🚀 Instructions
1) **Lancer l’interface**
   - Depuis la racine : `./net_practice.1.9/net_practice/run.sh`
   - Prérequis : Python 3 ; `ss` pour détecter un port libre (49152–65535) ; `xdg-open`/`open` pour ouvrir le navigateur automatiquement.
2) **Résoudre un niveau**
   - Onglet *Training* → choisir le niveau.
   - Renseigner IP et masque de chaque interface ; ajouter routes/gateways sur les routeurs.
   - Utiliser le check de connectivité intégré jusqu’à tout vert.
3) **Exporter la configuration**
   - Bouton **“Export configuration”** (en haut à droite).
   - Renommer en `levelX.json` (1–10).
4) **Soumission attendue**
   - Placer les **10 fichiers exportés** à la **racine du dépôt** (`level1.json` … `level10.json`). Des exemples actuels sont dans `submission/`.

## 🧠 Concepts clés travaillés
- Adressage TCP/IP, masques de sous-réseau (CIDR), calcul de plage (réseau/broadcast).
- Passerelle par défaut et routage statique (next-hop, route par défaut, résumé /24, transit /30).
- Rôles routeur vs switch, liens P2P, agrégation (/18), cheminement couches 2–3 (OSI).

## 📂 Structure du dépôt
```
NetPractice/
├── lvl_corrected/       # Captures initiales des 10 niveaux (avant correction)
├── lvl_subject/         # Captures corrigées (état cible)
├── submission/          # Exports JSON `level*.json` servant d’exemple de solutions
└── net_practice.1.9/net_practice/
    ├── run.sh           # Lance le serveur HTTP local
    ├── *.html           # Interface web (Training / Evaluation)
    ├── js/*.js          # Logique d’affichage/simulation
    └── css/img          # Styles et assets
```

## 📑 Resources
- **Références** :
  - https://www.aelius.com/njh/subnet_sheet.html
  - https://github.com/lpaube/NetPractice?tab=readme-ov-file
- **Usage de l’IA** : Pour faire ce readme, et comprendre la base et le fonctionnement des adresses IP, mask...
