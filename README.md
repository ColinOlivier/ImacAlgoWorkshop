# 💻 Programmation algorithmique - IMAC 1 - WORKSHOP 💻
<p align="center">
    <img src="res/IMAC_logo.png" alt="drawing" width="200"/>
</p>

📆 20 - 27 Novembre 2023

*Contributeur : Angèle DOUET - Colin OLIVIER
Super Superviseur : Jules FOUCHY*

- [💻 Programmation algorithmique - IMAC 1 - WORKSHOP 💻](#-programmation-algorithmique---imac-1---workshop-)
  - [Introduction](#introduction)
  - [Résultats](#résultats)
    - [⭐ Ne garder que le vert](#-ne-garder-que-le-vert)
    - [⭐ Échanger les canaux](#-échanger-les-canaux)
    - [⭐ Noir \& Blanc](#-noir--blanc)
    - [⭐ Négatif](#-négatif)
    - [⭐ Dégradé](#-dégradé)
    - [⭐⭐ Miroir](#-miroir)
    - [⭐⭐ Image bruitée](#-image-bruitée)
    - [⭐⭐ Rotation de 90°](#-rotation-de-90)
    - [⭐⭐ RGB split](#-rgb-split)
    - [⭐⭐ Luminosité](#-luminosité)
    - [⭐⭐ Disque](#-disque)
    - [⭐ Cercle](#-cercle)
    - [⭐⭐⭐ Rosace](#-rosace)
    - [⭐⭐ Mosaïque](#-mosaïque)
    - [⭐⭐⭐ Mosaïque miroir](#-mosaïque-miroir)
    - [⭐⭐⭐ Glitch](#-glitch)
    - [⭐⭐⭐ Fractale de Mandelbrot](#-fractale-de-mandelbrot)
    - [⭐⭐⭐(⭐) Vortex](#-vortex)
    - [⭐⭐⭐(⭐) Tramage](#-tramage)
    - [⭐⭐⭐⭐ Convolutions](#-convolutions)
    - [⭐ Netteté, Contours, etc.](#-netteté-contours-etc)
    - [⭐⭐⭐⭐ Tri de pixels](#-tri-de-pixels)
    - [⭐⭐⭐⭐⭐ Filtre de Kuwahara (effet peinture à l'huile)](#-filtre-de-kuwahara-effet-peinture-à-lhuile)


## Introduction
Au cours du premier semestre d’enseignement à l’IMAC, nous avons eu l’opportunité de participer à un workshop de programmation algorithmique encadré par Jules Fouchy. L’occasion parfaite pour approfondir nos connaissances en C++. 

Nous avons pu découvrir (ou redécouvrir) comment coder des effets sur des images ainsi que certains concepts de synthèse d'image. Nous nous sommes donc transformés en véritables Photoshop manuels pendant une semaine.
Ayant des niveaux très hétérogène en C++, nous nous sommes beaucoup apportés tant en connaissances qu’en conseils. 

En vue de rendre compte de manière fidèle de ces cinq jours de programmation intensive, nous présenterons les effets réalisés dans le temps impartis, accompagnés parfois de quelques commentaires explicatifs.



## Résultats


### ⭐ Ne garder que le vert

| ![Input Image](images/logo.png) | ![Output Image](output/gardervert.png) |
| ------------------------------- | -------------------------------------- |
| **Input**                       | **Output**                             |

<!---
TODO :  Add explication.
-->

```cpp
    for (glm::vec3& color : image.pixels())
    {
        color.r = 0.f;
        color.b=0.f;
    }
```

### ⭐ Échanger les canaux

### ⭐ Noir & Blanc

### ⭐ Négatif

### ⭐ Dégradé

### ⭐⭐ Miroir

### ⭐⭐ Image bruitée

### ⭐⭐ Rotation de 90°

### ⭐⭐ RGB split

### ⭐⭐ Luminosité

### ⭐⭐ Disque

### ⭐ Cercle

### ⭐⭐⭐ Rosace

### ⭐⭐ Mosaïque

### ⭐⭐⭐ Mosaïque miroir

### ⭐⭐⭐ Glitch

### ⭐⭐⭐ Fractale de Mandelbrot

### ⭐⭐⭐(⭐) Vortex

### ⭐⭐⭐(⭐) Tramage

### ⭐⭐⭐⭐ Convolutions

### ⭐ Netteté, Contours, etc.

### ⭐⭐⭐⭐ Tri de pixels

### ⭐⭐⭐⭐⭐ Filtre de Kuwahara (effet peinture à l'huile)