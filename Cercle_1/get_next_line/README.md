<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/Grade-125%2F100-brightgreen?style=for-the-badge" alt="Grade"/>
  <img src="https://img.shields.io/badge/Norminette-Passing-success?style=for-the-badge" alt="Norm"/>
</p>

[Home](../../README.md)

# 📖 Get Next Line — Lecture Ligne par Ligne

> Une fonction qui lit et retourne une ligne depuis un file descriptor, un appel à la fois.

---

## 🎯 Objectif

**Get Next Line** implémente une fonction capable de lire le contenu d'un fichier (ou de `stdin`) **ligne par ligne**, en retournant une nouvelle ligne à chaque appel successif. Ce projet enseigne la gestion de **variables statiques**, la lecture par **buffer**, et la manipulation fine de la mémoire en C.

```c
char *get_next_line(int fd);
```

Chaque appel retourne la ligne suivante du fichier (incluant le `\n`), ou `NULL` lorsque le fichier a été entièrement lu.

---

## ⚙️ Fonctionnement

### Principe de la lecture par buffer

```
Fichier:  "Hello\nWorld\n42\n"
                                      BUFFER_SIZE = 5
Appel 1:  read → "Hello"  → storage = "Hello"
          read → "\nWorl"  → storage = "Hello\nWorl"
          ✂️ Extraction: "Hello\n"    → storage = "Worl"
          → return "Hello\n"

Appel 2:  read → "d\n42\n" → storage = "World\n42\n"
          ✂️ Extraction: "World\n"   → storage = "42\n"
          → return "World\n"

Appel 3:  '\n' trouvé dans storage
          ✂️ Extraction: "42\n"      → storage = ""
          → return "42\n"

Appel 4:  read → 0 octets (EOF)
          → return NULL
```

### Cycle de vie du buffer statique

```
get_next_line(fd)
    │
    ├── 1. read_from_file()
    │       └── Lecture par chunks de BUFFER_SIZE
    │           └── Concaténation au storage (ft_strjoin_and_free)
    │           └── Arrêt dès qu'un '\n' est détecté
    │
    ├── 2. ft_extract_line()
    │       └── Copie du début du storage jusqu'au '\n' inclus
    │       └── Retourne la ligne extraite
    │
    └── 3. ft_update_storage()
            └── Supprime la ligne extraite du storage
            └── Conserve le reste pour le prochain appel
```

---

## 🌟 Partie Bonus — File Descriptors Multiples

La version bonus permet de lire **simultanément** depuis plusieurs fichiers sans perte de données :

```c
// Version obligatoire : 1 seul fd à la fois
static char *storage;           // Variable statique unique

// Version bonus : jusqu'à 1024 fd simultanés
static char *storage[1024];     // Tableau de storages indexé par fd
```

### Exemple d'utilisation multi-fd

```c
int fd1 = open("file1.txt", O_RDONLY);
int fd2 = open("file2.txt", O_RDONLY);

get_next_line(fd1);  // → Ligne 1 de file1     (storage[fd1])
get_next_line(fd2);  // → Ligne 1 de file2     (storage[fd2])
get_next_line(fd1);  // → Ligne 2 de file1     (continue depuis storage[fd1])
get_next_line(fd2);  // → Ligne 2 de file2     (continue depuis storage[fd2])
```

Chaque file descriptor possède son propre buffer indépendant, garantissant l'intégrité des lectures entrelacées.

---

## 🛡️ Gestion de la Mémoire

| Protection | Détail |
|------------|--------|
| **Overflow `SIZE_MAX`** | Vérification avant concaténation pour éviter les integer overflows |
| **NULL checks** | Protection systématique sur chaque allocation |
| **Libération propre** | `ft_strjoin_and_free()` libère l'ancien buffer après concaténation |
| **Nettoyage EOF** | Le storage est libéré et mis à `NULL` en fin de fichier |
| **Validation fd** | Rejet des fd négatifs et supérieurs à 1023 (bonus) |

---

## 🛠️ Compilation & Utilisation

Le `BUFFER_SIZE` est configurable à la compilation :

```bash
# Compilation avec un buffer de 42 octets (valeur par défaut)
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl

# Compilation de la version bonus (multi-fd)
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1024 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus

# Tester avec différentes tailles de buffer
cc -D BUFFER_SIZE=1 ...    # Lecture octet par octet
cc -D BUFFER_SIZE=10000 ... # Gros buffer
```

### Exemple d'utilisation

```c
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("text.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

---

## 📂 Structure du Projet

```
get_next_line/
├── get_next_line.h              # Header — prototypes (version obligatoire)
├── get_next_line.c              # Fonction principale (1 fd)
├── get_next_line_utils.c        # Fonctions utilitaires
├── get_next_line_bonus.h        # Header — version bonus
├── get_next_line_bonus.c        # Fonction principale (multi-fd)
├── get_next_line_utils_bonus.c  # Fonctions utilitaires (bonus)
└── main.c                       # Programme de test
```

### Fonctions utilitaires

| Fonction | Rôle |
|----------|------|
| `ft_strlen` | Longueur d'une chaîne (gère `NULL`) |
| `ft_strjoin_and_free` | Concaténation avec libération de `s1` |
| `ft_strchr_found` | Détection de la présence d'un caractère |
| `ft_extract_line` | Extraction de la ligne courante du storage |
| `ft_update_storage` | Mise à jour du storage après extraction |

---

## 🔑 Compétences Développées

- **Variables statiques** : persistance de données entre les appels de fonction
- **Lecture buffererisée** : optimisation des appels système `read()`
- **Gestion mémoire avancée** : allocation, réallocation, libération sans fuite
- **File descriptors** : compréhension du système d'I/O Unix
- **Edge cases** : fichiers vides, lignes sans `\n`, buffers de taille 1, lectures simultanées

---

[Home](../../README.md)

<p align="center">
  <i>Projet réalisé dans le cadre du cursus 42 — Cercle 1</i>
</p>
