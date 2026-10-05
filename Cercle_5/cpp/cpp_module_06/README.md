<p align="center">
  <img src="https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=c%2B%2B" alt="C++"/>
  <img src="https://img.shields.io/badge/Module-06-informational?style=for-the-badge" alt="Module 06"/>
</p>

[Home](../../../README.md)

# 🔄 C++ Module 06 — Casts et conversions

> Compréhension des conversions de types et des opérateurs de cast en C++.

## 🎯 Objectif

Les exercices traitent la conversion scalaire, la sérialisation d'adresses et l'identification dynamique du type réel d'objets via une hiérarchie polymorphe.

## 📚 Exercices

| Exercice | Projet | Notions principales |
|----------|--------|---------------------|
| `ex00` | [ScalarConverter](ex00) | Conversion de chaînes vers `char`, `int`, `float` et `double` |
| `ex01` | [Serializer](ex01) | Conversion pointeur/entier et retour vers un pointeur |
| `ex02` | [Identify](ex02) | `dynamic_cast`, RTTI et identification de types |

## 🚀 Utilisation

```bash
cd ex00
make
./convert 42.0f
```

## 🔑 Compétences développées

- `static_cast`, `reinterpret_cast` et `dynamic_cast`
- Analyse et validation de chaînes numériques
- RTTI et hiérarchies polymorphes
- Sérialisation d'une adresse mémoire
- Gestion des valeurs impossibles et non représentables

<p align="center"><i>Projet réalisé dans le cadre du cursus 42 — Cercle 5</i></p>
