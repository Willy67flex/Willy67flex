<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="C"/>
  <img src="https://img.shields.io/badge/Grade-100%2F100-brightgreen?style=for-the-badge" alt="Grade"/>
  <img src="https://img.shields.io/badge/Norminette-Passing-success?style=for-the-badge" alt="Norm"/>
  <img src="https://img.shields.io/badge/Data%20Races-0-success?style=for-the-badge" alt="No Data Races"/>
</p>

[Home](../../README.md)

# 🍝 Philosophers — Le Problème du Dîner des Philosophes

> Implémentation multi-threadée du classique problème de synchronisation en informatique, avec gestion des mutex et prévention des deadlocks.

---

## 🎯 Objectif

**Philosophers** résout le célèbre problème du **Dîner des Philosophes** de Dijkstra. N philosophes sont assis autour d'une table ronde, chacun alternant entre **manger**, **dormir** et **penser**. Pour manger, un philosophe doit saisir les deux fourchettes adjacentes (partagées avec ses voisins).

Le défi : éviter les **deadlocks** (interblocages) et les **data races** (accès concurrents) tout en s'assurant qu'aucun philosophe ne meurt de faim.

---

## 🧩 Le Problème

```
         🍝 Philosophe 1
        /              \
   🍴 Fork 1        🍴 Fork 2
      |                  |
🍝 Philo 4          🍝 Philo 2
      |                  |
   🍴 Fork 4        🍴 Fork 3
        \              /
         🍝 Philo 3

```

### Règles

- Chaque philosophe a besoin de **2 fourchettes** pour manger (sa gauche et sa droite)
- Les fourchettes sont **partagées** entre voisins
- Un philosophe **meurt** s'il ne mange pas dans le temps imparti (`time_to_die`)
- La simulation s'arrête dès qu'un philosophe meurt ou que tous ont mangé suffisamment

---

## ⚙️ Architecture Multi-Threadée

### Un thread par philosophe + un moniteur

```
┌──────────────────────────────────────────────────────────────┐
│                      THREAD PRINCIPAL                         │
│                                                              │
│  Initialisation → Création threads → Monitoring → Cleanup    │
└──────┬────────────────────┬──────────────────────┬───────────┘
       │                    │                      │
       ▼                    ▼                      ▼
┌─────────────┐    ┌─────────────┐        ┌─────────────┐
│  Thread P1  │    │  Thread P2  │  ...   │  Thread PN  │
│             │    │             │        │             │
│  ┌───────┐  │    │  ┌───────┐  │        │  ┌───────┐  │
│  │ PENSER│  │    │  │ PENSER│  │        │  │ PENSER│  │
│  └───┬───┘  │    │  └───┬───┘  │        │  └───┬───┘  │
│      ▼      │    │      ▼      │        │      ▼      │
│  ┌───────┐  │    │  ┌───────┐  │        │  ┌───────┐  │
│  │PRENDRE│  │    │  │PRENDRE│  │        │  │PRENDRE│  │
│  │FORKS  │  │    │  │FORKS  │  │        │  │FORKS  │  │
│  └───┬───┘  │    │  └───┬───┘  │        │  └───┬───┘  │
│      ▼      │    │      ▼      │        │      ▼      │
│  ┌───────┐  │    │  ┌───────┐  │        │  ┌───────┐  │
│  │ MANGER│  │    │  │ MANGER│  │        │  │ MANGER│  │
│  └───┬───┘  │    │  └───┬───┘  │        │  └───┬───┘  │
│      ▼      │    │      ▼      │        │      ▼      │
│  ┌───────┐  │    │  ┌───────┐  │        │  ┌───────┐  │
│  │ DORMIR│  │    │  │ DORMIR│  │        │  │ DORMIR│  │
│  └───┬───┘  │    │  └───┬───┘  │        │  └───┬───┘  │
│      └──→ boucle │      └──→ boucle     │      └──→ boucle
└─────────────┘    └─────────────┘        └─────────────┘
```

### Cycle de vie d'un philosophe

```
1. 🤔 PENSER   → attente (pas de ressources)
2. 🍴 PRENDRE  → verrouiller fork gauche (mutex lock)
3. 🍴 PRENDRE  → verrouiller fork droite (mutex lock)
4. 🍝 MANGER   → mise à jour de last_meal_time (protégé par meal_lock)
                → dormir pendant time_to_eat ms
5. 🍴 RELÂCHER → déverrouiller les deux fourchettes
6. 😴 DORMIR   → dormir pendant time_to_sleep ms
7. → Retour à l'étape 1
```

---

## 🔒 Stratégie de Synchronisation

### 4 types de mutex

| Mutex | Protège | Utilisé dans |
|-------|---------|-------------|
| `forks[i]` | Fourchette i (partagée entre philosophes adjacents) | Routine (manger) |
| `meal_lock` | `last_meal_time` et `meals_eaten` de chaque philosophe | Routine + Moniteur |
| `write_lock` | Appels à `printf` (évite les messages entrelacés) | Toutes les actions |
| `dead_lock` | Flag `dead_flag` (arrêt global de la simulation) | Routine + Moniteur |

### Prévention des deadlocks

Le programme utilise un **décalage temporel** (staggering) pour empêcher tous les philosophes de saisir leur fourchette gauche simultanément :

```c
// Les philosophes pairs attendent 1ms avant de commencer
if (philo->id % 2 == 0)
    usleep(1000);
```

### Détection de la mort

Le **thread moniteur** (dans le thread principal) vérifie en continu :

```c
while (!simulation_over)
{
    for each philosopher:
        lock(meal_lock)
        if (current_time - last_meal_time >= time_to_die)
            → philosopher is dead!
            → set dead_flag = 1
        unlock(meal_lock)
}
```

### Timing précis

Une fonction `ft_usleep()` personnalisée assure une précision sub-milliseconde :
- Vérifie le `dead_flag` toutes les 500 µs
- Permet un arrêt réactif de la simulation dès qu'une mort est détectée

---

## 🚀 Utilisation

```bash
make
./philo <nb_philo> <time_to_die> <time_to_eat> <time_to_sleep> [nb_meals]
```

| Paramètre | Description |
|-----------|-------------|
| `nb_philo` | Nombre de philosophes (et de fourchettes) — 1 à 200 |
| `time_to_die` | Temps max (ms) sans manger avant de mourir |
| `time_to_eat` | Durée (ms) d'un repas |
| `time_to_sleep` | Durée (ms) du sommeil |
| `nb_meals` | *(optionnel)* Nombre de repas pour arrêter la simulation |

### Exemples

```bash
# 4 philosophes, personne ne meurt
./philo 4 800 200 200

# 5 philosophes, chacun mange 7 fois puis la simulation s'arrête
./philo 5 800 200 200 7

# 1 seul philosophe → meurt inévitablement (ne peut pas prendre 2 fourchettes)
./philo 1 800 200 200

# Test limite : un philosophe devrait mourir
./philo 4 310 200 100
```

### Format de sortie

```
timestamp_ms  philo_id  action
─────────────────────────────────
0             1         has taken a fork
0             1         has taken a fork
0             1         is eating
200           1         is sleeping
200           3         has taken a fork
...
```

---

## 📂 Structure du Projet

```
philo/
├── Makefile
├── philo.h                  # Header — structures t_philo et t_setting
├── philo.c                  # Main — initialisation et lancement
├── check_input.c            # Validation des arguments (1-200 philos)
├── init_simu.c              # Création des mutex et initialisation
├── create_pthreads.c        # Création et join des threads
├── routine.c                # Boucle de vie du philosophe (eat/sleep/think)
├── monitor.c                # Détection de mort et fin de simulation
├── utils.c                  # Cleanup, ft_atol, messages d'erreur
└── utils_pthread.c          # Timing, vérification mort, output formaté
```

**Total : 8 fichiers sources** — conception minimaliste et efficace

---

## 🛡️ Garanties

| Aspect | Vérification |
|--------|-------------|
| **Data races** | 0 — vérifié avec `helgrind` et `ThreadSanitizer` |
| **Fuites mémoire** | 0 — vérifié avec `valgrind` |
| **Deadlocks** | Prévenu par le décalage temporel des philosophes pairs |
| **Précision temporelle** | ± 1ms grâce au polling haute fréquence |

---

## 🔑 Compétences Développées

- **Programmation multi-threadée** : `pthread_create`, `pthread_join`, routines de thread
- **Synchronisation** : `pthread_mutex_lock/unlock`, sections critiques, exclusion mutuelle
- **Problèmes classiques** : compréhension et résolution du Dining Philosophers Problem
- **Prévention des deadlocks** : stratégies de scheduling et d'ordonnancement
- **Race conditions** : identification et élimination des accès concurrents non protégés
- **Timing système** : `gettimeofday()`, `usleep()`, mesure précise du temps

---

[Home](../../README.md)

<p align="center">
  <i>Projet réalisé dans le cadre du cursus 42 — Cercle 3</i>
</p>
