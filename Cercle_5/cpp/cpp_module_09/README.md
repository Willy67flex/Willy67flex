<p align="center">
  <img src="https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=c%2B%2B" alt="C++"/>
  <img src="https://img.shields.io/badge/Module-09-informational?style=for-the-badge" alt="Module 09"/>
</p>

[Home](../../../README.md)

# 📊 C++ Module 09 — STL et algorithmes

> Résolution de problèmes pratiques avec les conteneurs STL, les piles et les algorithmes de tri.

## 🎯 Objectif

Le module met en œuvre trois programmes complets : lecture d'un historique de Bitcoin, évaluation d'expressions en notation polonaise inversée et comparaison de tris hybrides sur plusieurs conteneurs.

## 📚 Exercices

| Exercice | Projet | Notions principales |
|----------|--------|---------------------|
| `ex00` | [BitcoinExchange](ex00) | Parsing de fichiers CSV, dates et recherche dans une `map` |
| `ex01` | [RPN](ex01) | Évaluation d'expressions avec une pile |
| `ex02` | [PmergeMe](ex02) | Tri Ford-Johnson et comparaison de performances |

## 🚀 Utilisation

```bash
cd ex00
make
./btc input.txt
```

Chaque exercice possède son propre `Makefile` et ses propres fichiers d'entrée lorsque nécessaire.

## 🔑 Compétences développées

- Parsing et validation de données
- `std::map`, `std::stack`, `std::vector` et `std::deque`
- Algorithmes de tri et analyse de performances
- Gestion des erreurs d'entrée
- Comparaison du temps d'exécution selon le conteneur

<p align="center"><i>Projet réalisé dans le cadre du cursus 42 — Cercle 5</i></p>
