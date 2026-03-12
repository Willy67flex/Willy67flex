<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/Grade-125%2F100-brightgreen?style=for-the-badge" alt="Grade"/>
  <img src="https://img.shields.io/badge/Norminette-Passing-success?style=for-the-badge" alt="Norm"/>
  <img src="https://img.shields.io/badge/Graphics-MiniLibX-orange?style=for-the-badge" alt="MiniLibX"/>
</p>

[Home](../../README.md)

# 🎮 So_long — Jeu 2D en C

> Un jeu 2D top-down en C avec la MiniLibX : exploration d'une carte, collecte d'objets, ennemis et animations sprite.

---

## 🎯 Objectif

**So_long** est un jeu 2D en vue de dessus développé en C avec la bibliothèque graphique **MiniLibX**. Le joueur explore une carte tile-based, collecte des pièces et atteint la sortie tout en évitant les ennemis.

Ce projet introduit la **programmation graphique**, la **gestion d'événements**, le **rendu par tiles** et les **boucles de jeu** (game loop).

---

## 🕹️ Gameplay

### Contrôles

| Touche | Action |
|:------:|--------|
| `W` / `↑` | Déplacement vers le haut |
| `A` / `←` | Déplacement vers la gauche |
| `S` / `↓` | Déplacement vers le bas |
| `D` / `→` | Déplacement vers la droite |
| `ESC` | Quitter le jeu |

### Règles

- 🪙 **Collecter** toutes les pièces dispersées sur la carte
- 🚪 **Atteindre la sortie** une fois toutes les pièces récupérées
- 👾 **Éviter les ennemis** qui se déplacent et poursuivent le joueur
- ❤️ **3 vies** — chaque contact avec un ennemi retire une vie et reset la position
- 📊 Le **compteur de mouvements** s'affiche en temps réel dans le HUD

### Conditions de victoire/défaite

| Condition | Résultat |
|-----------|----------|
| Toutes les pièces collectées + sortie atteinte | 🏆 **Victoire** |
| 0 vies restantes (3 touches par les ennemis) | 💀 **Game Over** |

---

## 🗺️ Système de Cartes

Les cartes sont des fichiers `.ber` au format texte :

```
1111111111
10C00000E1
1010101011
1M00C00001
100P0000C1
1111111111
```

| Caractère | Élément |
|:---------:|---------|
| `1` | Mur (infranchissable) |
| `0` | Sol (traversable) |
| `P` | Position de départ du joueur |
| `E` | Sortie |
| `C` | Pièce à collecter |
| `M` | Ennemi |

### Validation de la carte

Le programme effectue une **validation exhaustive** avant de lancer le jeu :

- ✅ Forme rectangulaire
- ✅ Entourée de murs (`1`) sur tout le périmètre
- ✅ Exactement 1 joueur (`P`) et 1 sortie (`E`)
- ✅ Au moins 1 pièce (`C`)
- ✅ **Flood fill** : vérification que toutes les pièces et la sortie sont accessibles depuis le joueur
- ✅ Ennemis placés à ≥ 5 cases du joueur (spawn sécurisé)

---

## 🎨 Rendu Graphique

### Tiles & Sprites (32×32 pixels)

Le jeu utilise plus de **100 sprites XPM** pour un rendu riche et animé :

| Catégorie | Sprites | Détails |
|-----------|:-------:|---------|
| **Joueur** | 32 | 8 frames d'animation × 4 directions |
| **Ennemis** | 16 | 4 frames × 4 directions |
| **Murs** | 35+ | Périmètre, coins, intersections, variations |
| **Pièces** | 10 | Frames d'animation de collecte |
| **Sortie** | 2 | État verrouillé / ouvert |
| **Cœurs** | 10 | Pleins et brisés (HUD) |
| **Herbe** | 3 | Variations de sol (bruit procédural) |

### HUD (Affichage Tête Haute)

Le HUD affiche en temps réel :
- 📊 Nombre de mouvements
- 🪙 Pièces restantes à collecter
- ❤️ Vies restantes (avec animation de cœurs brisés)

---

## 👾 Intelligence Artificielle des Ennemis

Les ennemis **traquent activement** le joueur avec un algorithme de poursuite basé sur la distance :

```
Pour chaque ennemi :
  1. Calculer dx = joueur_x - ennemi_x
  2. Calculer dy = joueur_y - ennemi_y
  3. Si |dx| ≥ |dy| → priorité déplacement horizontal
     Sinon           → priorité déplacement vertical
  4. Si direction prioritaire bloquée → tenter la perpendiculaire
```

Les ennemis ne peuvent pas traverser les murs, la sortie, les pièces, ni d'autres ennemis. Leur vitesse de déplacement est configurable via les constantes `DIFFICULTY` et `SPEED`.

---

## 🏗️ Architecture

```
so_long (main)
    │
    ├── Check_input/        → Validation des arguments (.ber)
    │
    ├── Check_map/          → Lecture, parsing et flood fill
    │   ├── map_read.c      → Lecture du fichier .ber
    │   ├── map_check.c     → Comptage des éléments
    │   ├── map_path.c      → Flood fill (accessibilité)
    │   └── verif_enemy.c   → Validation placement ennemis
    │
    ├── Run_game/           → Boucle de jeu et rendu
    │   ├── init_window.c   → Création de la fenêtre MLX
    │   ├── game_loop.c     → Boucle principale (animations, IA)
    │   ├── render_map.c    → Rendu de la carte tile par tile
    │   ├── player_move.c   → Gestion des déplacements
    │   ├── enemy.c         → IA de poursuite
    │   ├── ui_hud.c        → Affichage du HUD
    │   └── Init_image/     → Chargement des 100+ sprites
    │       ├── init_image_player.c
    │       ├── init_image_enemy.c
    │       ├── init_image_item.c
    │       └── init_image_wall.c
    │
    └── Draw_wall/          → Rendu intelligent des murs
        ├── put_perimeter_wall.c
        └── put_other_wall.c
```

---

## 🛠️ Compilation & Utilisation

```bash
# Compiler le jeu
make

# Lancer avec une carte
./so_long Map/map1.ber

# Nettoyer
make clean    # Supprime les .o
make fclean   # Nettoyage complet
make re       # Recompilation
```

### Dépendances

- **MiniLibX** (incluse dans le projet)
- **X11** (`libXext`, `libX11`) — Linux uniquement

---

## 📂 Structure du Projet

```
So_long/
├── Makefile
├── so_long                  # Exécutable
├── SRC/                     # 29 fichiers sources
│   ├── so_long.c            # Point d'entrée
│   ├── Check_input/         # Validation des arguments
│   ├── Check_map/           # Parsing et validation de carte
│   └── Run_game/            # Boucle de jeu, rendu, IA
├── Include/
│   ├── so_long.h            # Header — structures et constantes
│   └── libft/               # Bibliothèque utilitaire
├── Map/                     # 25 cartes jouables (.ber)
├── img/                     # 100+ sprites (.xpm, 32×32)
└── mlx_linux/               # Bibliothèque graphique MiniLibX
```

---

## 🔑 Compétences Développées

- **Programmation graphique** : fenêtrage, rendu par tiles, gestion d'événements clavier
- **Game loop** : boucle de jeu avec animation frame-by-frame
- **Parsing de fichiers** : lecture et validation de cartes avec flood fill
- **Intelligence artificielle** : algorithme de poursuite pour les ennemis
- **Gestion des sprites** : chargement, affichage et animation de textures XPM
- **Architecture logicielle** : séparation modulaire (input → validation → rendu → gameplay)

---

[Home](../../README.md)

<p align="center">
  <i>Projet réalisé dans le cadre du cursus 42 — Cercle 2</i>
</p>
