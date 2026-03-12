<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/Grade-125%2F100-brightgreen?style=for-the-badge" alt="Grade"/>
  <img src="https://img.shields.io/badge/Norminette-Passing-success?style=for-the-badge" alt="Norm"/>
</p>

[Home](../../README.md)

# 📚 Libft — Ma Première Bibliothèque C

> Réimplémentation d'une partie de la bibliothèque standard C, enrichie de fonctions utilitaires pour tous les projets 42.

---

## 🎯 Objectif

**Libft** est le tout premier projet du cursus 42. L'objectif est de recoder depuis zéro un ensemble de fonctions de la libc (`string.h`, `stdlib.h`, `ctype.h`...), puis d'y ajouter des fonctions supplémentaires absentes de la bibliothèque standard. Cette bibliothèque est ensuite réutilisée dans **tous les projets suivants**.

Ce projet m'a permis de comprendre en profondeur le fonctionnement interne des fonctions que l'on utilise au quotidien en C : gestion mémoire, manipulation de chaînes, I/O bas niveau.

---

## 🧩 Fonctions Implémentées

### Fonctions libc (Partie 1)

| Catégorie | Fonctions |
|-----------|-----------|
| **Classification** | `ft_isalpha` · `ft_isdigit` · `ft_isalnum` · `ft_isascii` · `ft_isprint` |
| **Conversion** | `ft_toupper` · `ft_tolower` · `ft_atoi` |
| **Mémoire** | `ft_memset` · `ft_bzero` · `ft_memcpy` · `ft_memmove` · `ft_memchr` · `ft_memcmp` · `ft_calloc` |
| **Chaînes** | `ft_strlen` · `ft_strchr` · `ft_strrchr` · `ft_strncmp` · `ft_strnstr` · `ft_strlcpy` · `ft_strlcat` · `ft_strdup` |

### Fonctions additionnelles (Partie 2)

| Fonction | Description |
|----------|-------------|
| `ft_substr` | Extraction d'une sous-chaîne |
| `ft_strjoin` | Concaténation de deux chaînes (allocation dynamique) |
| `ft_strtrim` | Suppression de caractères en début/fin de chaîne |
| `ft_split` | Découpage d'une chaîne selon un délimiteur → tableau de chaînes |
| `ft_itoa` | Conversion entier → chaîne de caractères |
| `ft_strmapi` | Application d'une fonction sur chaque caractère (nouvelle chaîne) |
| `ft_striteri` | Application d'une fonction sur chaque caractère (modification en place) |
| `ft_putchar_fd` | Écriture d'un caractère sur un file descriptor |
| `ft_putstr_fd` | Écriture d'une chaîne sur un file descriptor |
| `ft_putendl_fd` | Écriture d'une chaîne + retour à la ligne sur un fd |
| `ft_putnbr_fd` | Écriture d'un entier sur un file descriptor |

### Bonus — Listes chaînées

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Fonction | Description |
|----------|-------------|
| `ft_lstnew` | Création d'un nouveau nœud |
| `ft_lstadd_front` | Ajout en tête de liste |
| `ft_lstadd_back` | Ajout en fin de liste |
| `ft_lstsize` | Nombre d'éléments dans la liste |
| `ft_lstlast` | Récupération du dernier nœud |
| `ft_lstdelone` | Suppression d'un nœud (avec fonction de suppression personnalisée) |
| `ft_lstclear` | Suppression de la liste entière |
| `ft_lstiter` | Itération avec application d'une fonction |
| `ft_lstmap` | Création d'une nouvelle liste par application d'une fonction |

---

## 🛠️ Compilation & Utilisation

```bash
# Compiler la bibliothèque (partie obligatoire)
make

# Compiler avec les bonus (listes chaînées)
make bonus

# Nettoyer les fichiers objets
make clean

# Nettoyage complet (objets + bibliothèque)
make fclean

# Recompiler entièrement
make re
```

### Utilisation dans un projet

```c
#include "libft.h"

int main(void)
{
    char *str = ft_strjoin("Hello, ", "World!");
    ft_putendl_fd(str, 1);  // Affiche: Hello, World!
    free(str);
    return (0);
}
```

```bash
cc main.c -L. -lft -o programme
```

---

## 📂 Structure du Projet

```
libft/
├── libft.h          # Header — prototypes et structure t_list
├── Makefile         # Système de compilation
├── ft_is*.c         # Fonctions de classification (5 fichiers)
├── ft_to*.c         # Fonctions de conversion (2 fichiers)
├── ft_mem*.c        # Opérations mémoire (6 fichiers)
├── ft_str*.c        # Manipulation de chaînes (14 fichiers)
├── ft_put*.c        # Sortie sur file descriptor (4 fichiers)
├── ft_lst*.c        # Listes chaînées — bonus (9 fichiers)
├── ft_atoi.c        # String → int
├── ft_itoa.c        # Int → string
├── ft_calloc.c      # Allocation mémoire initialisée
├── ft_bzero.c       # Mise à zéro d'une zone mémoire
└── ft_split.c       # Découpage de chaîne
```

**Total : 44 fichiers sources** compilés en une archive statique `libft.a`

---

## 🔑 Compétences Développées

- **Programmation C bas niveau** : pointeurs, arithmétique de pointeurs, casts
- **Gestion mémoire** : `malloc`, `free`, détection de fuites, protection contre les overflows
- **Structures de données** : listes chaînées simples avec opérations CRUD
- **Programmation modulaire** : conception d'une API réutilisable
- **Makefile** : compilation conditionnelle, gestion des dépendances

---

[Home](../../README.md)

<p align="center">
  <i>Projet réalisé dans le cadre du cursus 42 — Cercle 0</i>
</p>
