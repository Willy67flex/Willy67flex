<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/Graphics-MiniLibX-informational?style=for-the-badge" alt="MiniLibX"/>
  <img src="https://img.shields.io/badge/Project-cub3D-success?style=for-the-badge" alt="cub3D"/>
</p>

[Home](../../README.md)

# 🕹️ cub3D — Raycasting avec MiniLibX

> Création d'un moteur 3D à la première personne à partir d'une carte 2D, inspiré de *Wolfenstein 3D*.

## 🎯 Objectif

**cub3D** utilise le raycasting pour calculer l'intersection entre les rayons du joueur et les murs de la carte. La distance obtenue sert à dessiner des bandes verticales dont la hauteur simule la profondeur et la perspective.

## ✨ Fonctionnalités

- Rendu 3D avec l'algorithme DDA et la MiniLibX.
- Textures différentes pour les murs nord, sud, est et ouest.
- Couleurs configurables pour le sol et le plafond.
- Déplacements, collisions et rotation à la souris.
- Mini-carte affichant le niveau et la position du joueur.
- Portes interactives avec le caractère `D`.
- Fermeture propre avec `ESC` ou la croix de la fenêtre.

## 🚀 Compilation et exécution

```bash
make
./cub3D maps/example.cub
```

Règles disponibles : `make clean`, `make fclean` et `make re`.

## 🎮 Contrôles

| Touche | Action |
|--------|--------|
| `W` / `S` | Avancer / reculer |
| `A` / `D` | Se déplacer latéralement |
| Souris | Tourner la caméra |
| `E` | Ouvrir ou fermer une porte |
| `SHIFT` | Accélérer le déplacement |
| `ESC` | Quitter |

## 🗺️ Format d'une carte `.cub`

Les textures et couleurs doivent être déclarées avant la carte :

```text
NO ./texture/north.xpm
SO ./texture/south.xpm
WE ./texture/west.xpm
EA ./texture/east.xpm
F 80,80,80
C 120,180,220
```

| Symbole | Signification |
|---------|---------------|
| `0` | Espace libre |
| `1` | Mur |
| `N`, `S`, `E`, `W` | Position et orientation initiales |
| `D` | Porte interactive |

La carte doit être fermée par des murs et contenir une seule position de départ valide.

## 🔑 Compétences développées

- Raycasting, vecteurs et trigonométrie
- Algorithme DDA et calcul de distances
- Gestion d'une fenêtre et d'images avec MiniLibX
- Parsing et validation d'une configuration
- Gestion des événements clavier et souris
- Collisions, textures et libération complète des ressources

## 📚 Ressources

- [Lode's Computer Graphics Tutorial — Raycasting](https://lodev.org/cgtutor/raycasting.html)
- Documentation MiniLibX

[Home](../../README.md)

<p align="center"><i>Projet réalisé dans le cadre du cursus 42 — Cercle 4</i></p>
