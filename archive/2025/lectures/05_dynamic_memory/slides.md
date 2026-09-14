---
title:
- "INF-0103 Minne II: Dynamisk minnehåndtering"
author:
- "Edvard Pedersen, UiT – Norges arktiske universitet"
theme:
- default
colortheme:
- seagull
aspectratio:
- 169
font:
- serif
fontsize:
- 14pt
date:
- "Høst 2025"
---

# Dagens tema

* Dynamisk minnehåndtering


# `sizeof`-operatoren

* Forteller hvor mange bytes en variabel eller en datatype tar opp i minnet

* Kan brukes direkte på datatypen `sizeof(int)` eller på en variabel `sizeof(x)`.

* Alle pekere tar like mye plass (de er alle minneaddresser)

* Relasjon til peker-aritimetikk: `p + n` gir en peker som er `n * sizeof(*p)` bytes lenger framme enn `p`

# Allokere minne (stdlib.h)

* malloc - alloker minne, returnerer en peker til det allokerte minnet
* calloc - samme som malloc, men setter minnet til 0
* free - frigjør minne som har blitt allokert tidligere
* (realloc - øk eller minsk størrelsen på allokert minne, kan flytte dataen)

# Minnehåndtering (string.h)

* memcpy - kopiere minne fra en plass til en annen
* strlen - telle antall bytes frem til en 0-byte
