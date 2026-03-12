<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/Grade-100%2F100-brightgreen?style=for-the-badge" alt="Grade"/>
  <img src="https://img.shields.io/badge/Norminette-Passing-success?style=for-the-badge" alt="Norm"/>
</p>

[Home](../../README.md)

# 🖨️ ft_printf — Réimplémentation de printf

> Recoder la fonction `printf` de la libc en gérant les arguments variadiques et les conversions de format.

---

## 🎯 Objectif

**ft_printf** reproduit le comportement de la fonction `printf()` de la bibliothèque standard C. Ce projet introduit le concept de **fonctions variadiques** (`va_list`, `va_start`, `va_arg`, `va_end`) et l'analyse d'une chaîne de format avec spécificateurs de conversion.

La fonction retourne le nombre total de caractères imprimés, comme la vraie `printf`.

---

## 📋 Spécificateurs Supportés

| Spécificateur | Type | Description | Exemple |
|:---:|---|---|---|
| `%c` | `char` | Affiche un caractère unique | `ft_printf("%c", 'A')` → `A` |
| `%s` | `char *` | Affiche une chaîne de caractères | `ft_printf("%s", "Hello")` → `Hello` |
| `%p` | `void *` | Affiche une adresse mémoire en hexadécimal | `ft_printf("%p", ptr)` → `0x7fff5fbff8ac` |
| `%d` | `int` | Affiche un entier signé en base 10 | `ft_printf("%d", -42)` → `-42` |
| `%i` | `int` | Affiche un entier signé en base 10 | `ft_printf("%i", 42)` → `42` |
| `%u` | `unsigned int` | Affiche un entier non signé en base 10 | `ft_printf("%u", 42)` → `42` |
| `%x` | `unsigned int` | Affiche en hexadécimal (minuscule) | `ft_printf("%x", 255)` → `ff` |
| `%X` | `unsigned int` | Affiche en hexadécimal (majuscule) | `ft_printf("%X", 255)` → `FF` |
| `%%` | — | Affiche le caractère `%` littéral | `ft_printf("%%")` → `%` |

---

## 🏗️ Architecture

```
ft_printf(format_string, ...)
    │
    ├── Initialisation de va_list
    │
    ├── Parcours de la chaîne de format
    │   ├── Caractère normal → ft_write_count() → écriture + compteur
    │   └── '%' détecté → ft_percent() → dispatch vers le handler
    │       ├── %c → ft_write_count()
    │       ├── %s → ft_print_str_count()     (gère NULL → "(null)")
    │       ├── %d/%i → ft_is_d_i()           (récursif, gère le signe)
    │       ├── %u → ft_is_u()                (conversion unsigned)
    │       ├── %x/%X → ft_putnbr_base()      (conversion récursive)
    │       ├── %p → ft_puthex_ptr()           (préfixe "0x" + hex)
    │       └── %% → ft_write_count('%')
    │
    └── return (count_print)                   // Nombre de caractères écrits
```

### Modules

| Fichier | Rôle |
|---------|------|
| `ft_printf.c` | Point d'entrée, parsing du format, dispatch |
| `ft_write_count.c` | Écriture d'un caractère + incrémentation du compteur |
| `ft_print_str_count.c` | Affichage de chaîne avec gestion de `NULL` |
| `ft_putnbr_base.c` | Conversion récursive d'un nombre dans une base quelconque |
| `ft_puthex_ptr.c` | Conversion d'adresse mémoire en hexadécimal |
| `ft_put_unsigned_nbr_fd.c` | Affichage récursif d'un unsigned int |
| `ft_intsize.c` | Calcul du nombre de chiffres d'un int signé |
| `ft_unsigned_intsize.c` | Calcul du nombre de chiffres d'un unsigned int |

---

## 🛠️ Compilation & Utilisation

```bash
# Compiler la bibliothèque
make

# Nettoyer
make clean    # Supprime les .o
make fclean   # Supprime les .o + libftprintf.a
make re       # Recompile tout
```

### Utilisation dans un projet

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("Hello %s! You are %d years old.\n", "William", 42);
    ft_printf("Characters printed: %d\n", count);
    ft_printf("Pointer: %p\n", &count);
    ft_printf("Hex: %x | HEX: %X\n", 255, 255);
    return (0);
}
```

**Sortie :**
```
Hello William! You are 42 years old.
Characters printed: 39
Pointer: 0x7ffd5e8b3a4c
Hex: ff | HEX: FF
```

---

## 📂 Structure du Projet

```
ft_printf/
├── ft_printf.h                  # Header — prototypes
├── ft_printf.c                  # Fonction principale + dispatcher
├── ft_write_count.c             # Écriture unitaire avec compteur
├── ft_print_str_count.c         # Affichage de chaîne
├── ft_putnbr_base.c             # Conversion base numérique (récursif)
├── ft_puthex_ptr.c              # Conversion pointeur → hex
├── ft_put_unsigned_nbr_fd.c     # Affichage unsigned int
├── ft_intsize.c                 # Taille d'un int signé
├── ft_unsigned_intsize.c        # Taille d'un unsigned int
├── Makefile                     # Système de compilation
└── libft/                       # Bibliothèque utilitaire intégrée
```

---

## 🔑 Compétences Développées

- **Fonctions variadiques** : maîtrise de `va_list` et de l'extraction d'arguments typés dynamiquement
- **Parsing de format** : analyse caractère par caractère d'une chaîne de spécificateurs
- **Conversion de bases** : algorithme récursif pour la conversion décimale, hexadécimale
- **Gestion des types** : casting entre `int`, `unsigned int`, `uintptr_t`, `char *`
- **Architecture modulaire** : séparation des responsabilités par fichier

---

[Home](../../README.md)

<p align="center">
  <i>Projet réalisé dans le cadre du cursus 42 — Cercle 1</i>
</p>
