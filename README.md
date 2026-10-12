<div align="center">

# FASTAtools

**Quelques outils de bio-informatique pour des séquences ADN.**

<img alt="C" src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white"/> <img alt="Make" src="https://img.shields.io/badge/Make-427819?style=for-the-badge&logo=gnu&logoColor=white"/> <img alt="Criterion" src="https://img.shields.io/badge/Criterion-4B4B4B?style=for-the-badge"/>

<sub>Projet solo · 2023</sub>

</div>

<br/>

<p align="center"><img src=".github/assets/term-fasta-tools.png" alt="FASTAtools" width="820"/></p>

## Le projet en quelques mots

Un petit outil en ligne de commande qui lit des séquences au format **FASTA** et les transforme.

## Ce que ça fait

- Option 1 : affichage normalisé (majuscules, caractères invalides retirés)
- Option 2 : transcription ADN → ARN
- Option 3 : brin complémentaire inverse
- Séquences d'exemple dans [`examples/`](examples)
- Tests unitaires Criterion

## Lancer le projet

```bash
make
./FASTAtools 2 < examples/sequences.fasta
./FASTAtools 3 < examples/sequences.fasta
```
