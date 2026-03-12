<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/Grade-125%2F100-brightgreen?style=for-the-badge" alt="Grade"/>
  <img src="https://img.shields.io/badge/Norminette-Passing-success?style=for-the-badge" alt="Norm"/>
</p>

[Home](../../README.md)

# 🔄 Push_Swap — Tri de Piles avec Opérations Limitées

> Trier une pile d'entiers avec le minimum d'opérations possible, en utilisant uniquement deux piles et un jeu restreint de commandes.

---

## 🎯 Objectif

**Push_Swap** est un projet d'algorithmique pur. Le défi : trier une séquence d'entiers en utilisant **deux piles** (A et B) et un ensemble de **11 opérations** prédéfinies, tout en minimisant le nombre total d'instructions générées.

Ce projet enseigne la **complexité algorithmique**, l'**optimisation**, et la capacité à choisir le bon algorithme pour chaque taille d'entrée.

---

## 📐 Opérations Disponibles

| Opération | Description |
|:---------:|-------------|
| `sa` | **Swap A** — Intervertit les 2 premiers éléments de la pile A |
| `sb` | **Swap B** — Intervertit les 2 premiers éléments de la pile B |
| `ss` | **Swap A+B** — `sa` et `sb` simultanément |
| `pa` | **Push A** — Place le sommet de B au sommet de A |
| `pb` | **Push B** — Place le sommet de A au sommet de B |
| `ra` | **Rotate A** — Le premier élément de A passe en dernier |
| `rb` | **Rotate B** — Le premier élément de B passe en dernier |
| `rr` | **Rotate A+B** — `ra` et `rb` simultanément |
| `rra` | **Reverse Rotate A** — Le dernier élément de A passe en premier |
| `rrb` | **Reverse Rotate B** — Le dernier élément de B passe en premier |
| `rrr` | **Reverse Rotate A+B** — `rra` et `rrb` simultanément |

---

## 🧠 Algorithme — Stratégie Adaptative

### Petites entrées (≤ 5 éléments) — Résolution directe

| Taille | Stratégie | Opérations max |
|:------:|-----------|:-:|
| 2 | Simple swap si nécessaire | 1 |
| 3 | Résolution par cas (6 permutations) | 2 |
| 4 | Extraction du min + tri de 3 | ~5 |
| 5 | Extraction récursive des minimums | ~8 |

### Grandes entrées (> 5 éléments) — Algorithme Turk

L'algorithme **Turk** optimise le coût global en 5 phases :

```
Phase 1 : INDEXATION
    [42, 23, 0, -15, 100]  →  [3, 2, 1, 0, 4]
    Les valeurs sont remplacées par leur rang dans l'ordre trié

Phase 2 : CONSTRUCTION DE B (coût minimum)
    Pour chaque élément de A :
    ├── Calculer le coût de déplacement vers B
    │   ├── Rotations nécessaires dans A pour l'atteindre
    │   ├── Rotations nécessaires dans B pour l'insérer
    │   └── Optimisation : rr/rrr si même direction
    └── Choisir l'élément le MOINS coûteux → pb

Phase 3 : TRI DES 3 DERNIERS
    Résolution directe des 3 éléments restants dans A

Phase 4 : RECONSTRUCTION DE A
    Ramener tous les éléments de B vers A
    ├── Trouver la position d'insertion optimale
    └── Rotation + pa

Phase 5 : ROTATION FINALE
    Rotation de A pour placer le minimum au sommet
```

### Optimisation du coût

```
Coût A (rotations) :
  ├── Position ≤ taille/2 → ra  (coût = position)
  └── Position > taille/2 → rra (coût = taille - position)

Coût B (insertion) :
  ├── Même direction que A → rr ou rrr (1 op au lieu de 2)
  └── Direction opposée → ra + rb (coûts additionnés)

Coût total = max(|A|, |B|) si même direction
           = |A| + |B|     si directions opposées
```

---

## 📊 Performance

| Taille d'entrée | Opérations générées | Benchmark 42 |
|:---:|:---:|:---:|
| 3 | ≤ 3 | ✅ 3 max |
| 5 | ≤ 8 | ✅ 12 max |
| 100 | ~550 | ✅ < 700 |
| 500 | ~5 000 | ✅ < 5 500 |

---

## 🚀 Utilisation

```bash
make

# Tri d'une séquence
./push_swap 4 67 3 87 23

# Compter le nombre d'opérations
./push_swap 4 67 3 87 23 | wc -l

# Vérifier le tri avec le checker (bonus)
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
# Affiche : OK

# Générer une séquence aléatoire et tester
ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l
```

---

## ✅ Bonus — Checker

Le programme **checker** lit les instructions sur `stdin` et vérifie si elles trient correctement la pile :

```bash
# Validation d'une séquence d'opérations
echo -e "pb\nra\nsa\npa" | ./checker 3 2 1
# OK  → La pile est triée
# KO  → La pile n'est pas triée
```

Le checker simule l'exécution de chaque opération en mode silencieux, puis vérifie que la pile A est triée et que la pile B est vide.

---

## 📂 Structure du Projet

```
Push_Swap/
├── Makefile
├── Include/
│   ├── push_swap.h              # Header — structures et prototypes
│   └── libft/                   # Bibliothèque utilitaire
├── Mandatory_part/
│   ├── push_swap.c              # Point d'entrée
│   ├── Commandes/
│   │   ├── commande_stack_a.c   # sa, pa, ra, rra
│   │   ├── commande_stack_b.c   # sb, pb, rb, rrb
│   │   └── commande_stack_a+b.c # ss, rr, rrr
│   ├── Algo/
│   │   ├── n_args.c             # Algorithme Turk (> 5 éléments)
│   │   ├── indexing.c           # Normalisation des valeurs
│   │   ├── cost.c               # Calcul du coût optimal
│   │   ├── moves.c              # Exécution des mouvements
│   │   └── utils_n_args.c       # Détection "nearly sorted"
│   ├── Algo_args_lt_5/
│   │   ├── args_lt_5.c          # Tri direct (2-5 éléments)
│   │   └── utils_args_lt_5.c    # Fonctions utilitaires
│   └── Check_input/
│       └── check_input.c        # Validation des arguments
└── Bonus_part/
    └── checker.c                # Vérificateur de tri
```

---

## 🔑 Compétences Développées

- **Algorithmique** : complexité temporelle, optimisation combinatoire
- **Structures de données** : manipulation de piles (stack) avec opérations contraintes
- **Optimisation** : minimisation du nombre d'opérations par calcul de coût global
- **Pensée algorithmique** : adapter la stratégie selon la taille de l'entrée
- **Gestion de la mémoire** : allocation dynamique, indexation, validation d'entrée

---

[Home](../../README.md)

<p align="center">
  <i>Projet réalisé dans le cadre du cursus 42 — Cercle 2</i>
</p>
