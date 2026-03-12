<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/Grade-125%2F100-brightgreen?style=for-the-badge" alt="Grade"/>
  <img src="https://img.shields.io/badge/Norminette-Passing-success?style=for-the-badge" alt="Norm"/>
</p>

[Home](../../README.md)

# 📡 Minitalk — Communication Inter-Processus par Signaux

> Un système client-serveur qui transmet des messages textuels en utilisant uniquement les signaux UNIX (`SIGUSR1` / `SIGUSR2`).

---

## 🎯 Objectif

**Minitalk** implémente un protocole de communication entre deux processus utilisant exclusivement les signaux POSIX. Le **serveur** écoute en permanence et affiche les messages reçus, tandis que le **client** encode chaque caractère en une séquence de 8 signaux (représentation binaire) et les envoie bit par bit.

Ce projet permet de comprendre les **signaux UNIX**, la **communication inter-processus (IPC)** et la conception d'un **protocole de communication** fiable.

---

## ⚙️ Protocole de Communication

### Encodage binaire

Chaque caractère est transmis **bit par bit**, du bit de poids fort (MSB) au bit de poids faible (LSB) :

```
Caractère 'A' = 65 = 01000001 en binaire

Envoi : SIGUSR2 → SIGUSR1 → SIGUSR2 → SIGUSR2 → SIGUSR2 → SIGUSR2 → SIGUSR2 → SIGUSR1
         (0)        (1)        (0)        (0)        (0)        (0)        (0)        (1)
```

| Signal | Signification |
|:------:|:---:|
| `SIGUSR1` | Bit à **1** |
| `SIGUSR2` | Bit à **0** |

### Handshake — Synchronisation fiable

```
CLIENT                              SERVER
  │                                    │
  ├── SIGUSR1 (bit=1) ──────────────►  │  Reçoit bit, reconstruit le caractère
  │                                    │
  │  ◄────────────────── SIGUSR1 (ACK) ┤  Confirme la réception
  │                                    │
  ├── SIGUSR2 (bit=0) ──────────────►  │  Bit suivant
  │                                    │
  │  ◄────────────────── SIGUSR1 (ACK) ┤
  │          ...                       │
  │     (8 bits = 1 caractère)         │
  │          ...                       │
  ├── '\0' (8 × SIGUSR2) ───────────►  │  Fin du message
  │                                    │
  │  ◄────────────────── SIGUSR2 (FIN) ┤  Message complet !
  │                                    │
```

Le client **attend l'accusé de réception** (ACK) du serveur avant d'envoyer chaque bit suivant, garantissant qu'aucune donnée n'est perdue.

---

## 🚀 Utilisation

### Démarrer le serveur

```bash
make
./server
```

Le serveur affiche son **PID** et reste en écoute :

```
Server PID: 12345
```

### Envoyer un message

```bash
./client 12345 "Hello, World!"
```

**Résultat :**
- Le serveur affiche : `Hello, World!`
- Le client affiche : `Message send!`

---

## 🏗️ Architecture

```
               CLIENT                                  SERVER
    ┌──────────────────────────┐            ┌──────────────────────────┐
    │  main(server_pid, msg)   │            │  main() → affiche PID   │
    │         │                │            │         │                │
    │    send_bit(pid, char)   │  SIGUSR1/2 │    handler(sig, info)   │
    │    ┌────┴─────┐         │ ─────────► │    ┌────┴─────┐         │
    │    │ Extraction│         │            │    │ Accum.   │         │
    │    │ bit par   │         │            │    │ des bits │         │
    │    │ bit (>> &)│         │            │    │ (|= <<)  │         │
    │    └────┬─────┘         │            │    └────┬─────┘         │
    │    Attend ACK ◄─────────│── SIGUSR1 ─│── kill(client, SIGUSR1) │
    │    (g_ack flag)          │            │         │                │
    │         │                │            │    8 bits → putchar()   │
    │    Bit suivant...        │            │         │                │
    └──────────────────────────┘            └──────────────────────────┘
```

### Fichiers

| Fichier | Rôle |
|---------|------|
| `server.c` | Réception des signaux, décodage bit par bit, affichage |
| `client.c` | Encodage des caractères, envoi signal par signal avec handshake |
| `Makefile` | Compilation des deux exécutables avec libft |
| `Include/` | Headers et bibliothèque utilitaire |

---

## 🛡️ Robustesse

| Aspect | Implémentation |
|--------|---------------|
| **Signaux fiables** | Utilisation de `sigaction()` avec `SA_SIGINFO` au lieu de `signal()` |
| **Identification du client** | Récupération du PID émetteur via `siginfo_t->si_pid` |
| **Timeout** | Détection de perte de signal (500ms d'attente max par bit) |
| **Validation** | Vérification du retour de `kill()` pour détecter les PID invalides |
| **Acquittement** | Protocole ACK garantissant la réception de chaque bit |

---

## 🛠️ Compilation

```bash
make          # Compile server et client
make clean    # Supprime les fichiers objets
make fclean   # Nettoyage complet
make re       # Recompilation
```

---

## 🔑 Compétences Développées

- **Signaux UNIX** : `SIGUSR1`, `SIGUSR2`, `sigaction`, `kill`
- **Communication inter-processus (IPC)** : conception d'un protocole binaire
- **Opérations bit à bit** : extraction et reconstruction de données binaires
- **Programmation asynchrone** : gestion d'événements par handlers de signaux
- **Fiabilité réseau** : mécanismes d'acquittement (ACK) et gestion des timeouts

---

[Home](../../README.md)

<p align="center">
  <i>Projet réalisé dans le cadre du cursus 42 — Cercle 2</i>
</p>
