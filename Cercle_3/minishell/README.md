<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/Grade-101%2F100-brightgreen?style=for-the-badge" alt="Grade"/>
  <img src="https://img.shields.io/badge/Norminette-Passing-success?style=for-the-badge" alt="Norm"/>
  <img src="https://img.shields.io/badge/Leaks-0-success?style=for-the-badge" alt="No Leaks"/>
</p>

[Home](../../README.md)

# Minishell — Notre Propre Shell Unix

> Réimplémentation d'un shell bash-like en C, avec gestion des pipes, redirections, variables d'environnement, et builtins.

*Projet réalisé en binôme avec [ele-moig](https://github.com/noceolo)*

---

## Objectif

**Minishell** est le projet le plus ambitieux du tronc commun 42. L'objectif est de recréer un **shell interactif** capable d'exécuter des commandes, de gérer les **pipes** (`|`), les **redirections** (`<`, `>`, `>>`, `<<`), les **variables d'environnement** (`$VAR`), et les **signaux** (`Ctrl-C`, `Ctrl-D`, `Ctrl-\`).

Ce projet combine la maîtrise de la gestion de processus, des file descriptors, du parsing de langage, et de la programmation système UNIX.

---

## Fonctionnalités

### Commandes Builtins

| Commande | Description |
|----------|-------------|
| `echo [-n]` | Affiche du texte (option `-n` : sans retour à la ligne) |
| `cd [path]` | Change le répertoire courant |
| `pwd` | Affiche le répertoire de travail actuel |
| `export [VAR=val]` | Définit ou affiche les variables d'environnement |
| `unset VAR` | Supprime une variable d'environnement |
| `env` | Affiche toutes les variables d'environnement |
| `exit [code]` | Quitte le shell avec un code de retour |

### Redirections

| Syntaxe | Type | Description |
|:-------:|------|-------------|
| `< file` | Input | Redirige l'entrée standard depuis un fichier |
| `> file` | Output | Redirige la sortie standard vers un fichier (écrasement) |
| `>> file` | Append | Redirige la sortie en mode ajout |
| `<< DELIM` | Heredoc | Lit l'entrée jusqu'au délimiteur spécifié |

### Pipes & Chaînage

```bash
# Pipe simple
ls -la | grep ".c" | wc -l

# Pipes multiples avec redirections
cat < input.txt | sort | uniq > output.txt

# Heredoc dans un pipe
cat << EOF | grep hello
hello world
goodbye world
EOF
```

### Variables d'Environnement

```bash
echo $HOME              # Expansion de variable
echo $?                 # Code de retour de la dernière commande
export MY_VAR="hello"   # Création de variable
MY_VAR="coucou"         # Ou on peux aussi la creer ou l'acctualiser comme ca
echo $MY_VAR            # → coucou
unset MY_VAR            # Suppression
```

### Quoting

| Type | Comportement |
|------|-------------|
| `'single'` | Aucune interprétation (tout est littéral) |
| `"double"` | Expansion de `$VAR` et `$?` uniquement |

### Signaux

| Signal | Comportement |
|--------|-------------|
| `Ctrl-C` | Interrompt la commande en cours / nouvelle ligne |
| `Ctrl-D` | Ferme le shell (EOF) |
| `Ctrl-\` | Ignoré (comme bash) |

---

## Architecture — Pipeline de Traitement

```
┌─────────────────────────────────────────────────────────────────┐
│                        ENTRÉE UTILISATEUR                       │
│                     (readline + historique)                     │
└─────────────────┬───────────────────────────────────────────────┘
                  │
                  ▼
┌─────────────────────────────────────────────────────────────────┐
│  LEXER (Tokenisation)                                           │
│  "ls -la | grep .c > out" → [ls][-la][|][grep][.c][>][out]      │
│  Gestion des quotes, séparation par espaces et opérateurs       │
└─────────────────┬───────────────────────────────────────────────┘
                  │
                  ▼
┌─────────────────────────────────────────────────────────────────┐
│  EXPANDER (Expansion des variables et quotes)                   │
│  $HOME → /home/user   |   $? → 0   |   Suppression des quotes   │
└─────────────────┬───────────────────────────────────────────────┘
                  │
                  ▼
┌─────────────────────────────────────────────────────────────────┐
│  PARSER (Construction de l'arbre de commandes)                  │
│  Tokens → cmd_node { args[], redirs[], next_pipe }              │
│  Chaque nœud = une commande dans le pipeline                    │
└─────────────────┬───────────────────────────────────────────────┘
                  │
                  ▼
┌─────────────────────────────────────────────────────────────────┐
│  EXECUTOR (Exécution)                                           │
│  ├── Builtin ? → Exécution directe (dans le processus parent)   │
│  └── Externe ? → fork() + execve()                              │
│      ├── Configuration des pipes (pipe(), dup2())               │
│      ├── Configuration des redirections (open(), dup2())        │
│      └── Résolution du PATH + exécution                         │
└─────────────────────────────────────────────────────────────────┘
```

### Modules détaillés

| Module | Fichiers | Rôle |
|--------|:--------:|------|
| **Lexer** | 2 | Tokenisation de l'entrée (quotes, opérateurs, mots) |
| **Expander** | 4 | Expansion `$VAR`, `$?`, suppression des quotes |
| **Parser** | 4 | Construction de la liste chaînée de commandes |
| **Executor** | 5 | Fork, pipes, redirections, `execve()` |
| **Builtins** | 9 | `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit` |
| **Environment** | 4 | Gestion de l'environnement (liste chaînée) |
| **Redirections** | 3 | `<`, `>`, `>>`, `<<` (heredoc) |
| **Signaux** | 1 | Handlers pour `SIGINT`, `SIGQUIT`, `SIGPIPE` |
| **Assignment** | 2 | Gestion de `VAR=value command` |
| **Cleanup** | 1 | Libération mémoire complète (0 leaks) |

---

## Compilation & Utilisation

```bash
make
./minishell
```

### Exemples de session

```bash
minishell$ echo "Hello, World!"
Hello, World!
minishell$ ls -la | grep Makefile | wc -l
1
minishell$ export NAME="William"
minishell$ echo "Hello $NAME, exit code: $?"
Hello William, exit code: 0
minishell$ cat << EOF > greeting.txt
> Hello from minishell!
> EOF
minishell$ cat greeting.txt
Hello from minishell!
minishell$ cd /tmp && pwd
/tmp
minishell$ exit 42
```

---

## Structure du Projet

```
minishell/
├── Makefile
├── inc/
│   └── minishell.h              # Header — structures et prototypes
├── src/
│   ├── main.c                   # Boucle principale (readline)
│   ├── main_utils.c             # Utilitaires de réinitialisation
│   ├── lexer/                   # Tokenisation
│   │   ├── lexer.c
│   │   └── lexer_utils.c
│   ├── parser/                  # Construction de l'AST
│   │   ├── parser.c
│   │   ├── parser_utils.c
│   │   ├── parser_utils2.c
│   │   └── parser_free.c
│   ├── expander/                # Expansion des variables
│   │   ├── expander.c
│   │   ├── dollar.c
│   │   ├── rm_quote.c
│   │   └── utils.c
│   ├── executor/                # Exécution des commandes
│   │   ├── execve/
│   │   │   ├── execve.c
│   │   │   ├── select_exec.c
│   │   │   ├── cmd_handlers.c
│   │   │   ├── fd_handlers.c
│   │   │   └── utils_execve.c
│   │   ├── built_in/
│   │   │   ├── echo/echo_handler.c
│   │   │   ├── cd/cd.c, cd_utils.c
│   │   │   ├── export/export_handler.c, export_sort.c, ...
│   │   │   ├── exit/exit.c
│   │   │   ├── unset.c
│   │   │   └── builtin_utils.c
│   │   └── print_error.c
│   ├── env/                     # Gestion de l'environnement
│   │   ├── env.c
│   │   ├── env_utils1.c
│   │   ├── env_utils2.c
│   │   └── empty_env.c
│   ├── redir/                   # Redirections et heredoc
│   │   ├── redir_handler.c
│   │   ├── redir_utils.c
│   │   └── redir_utils2.c
│   ├── signal/                  # Gestion des signaux
│   │   └── signal_handler.c
│   ├── assignment/              # Assignation de variables
│   │   ├── assignment.c
│   │   └── assignment_utils.c
│   └── free/                    # Libération mémoire
│       └── free_all.c
└── libft/                       # Bibliothèque utilitaire
```

**Total : 35+ fichiers sources C** organisés en 10 modules

---

## Compétences Développées

- **Programmation système UNIX** : `fork()`, `execve()`, `pipe()`, `dup2()`, `wait()`
- **Lexer / Parser** : tokenisation et construction d'arbre de commandes
- **File descriptors** : manipulation avancée avec redirections et pipes multiples
- **Gestion des signaux** : `sigaction`, comportement contextuel (interactif vs exécution)
- **Gestion de la mémoire** : zéro fuite mémoire (vérifié avec Valgrind)
- **Travail en équipe** : collaboration en binôme, intégration de modules indépendants
- **Compatibilité bash** : reproduction fidèle du comportement de bash

---

[Home](../../README.md)

<p align="center">
  <i>Projet réalisé dans le cadre du cursus 42 — Cercle 3</i>
</p>
