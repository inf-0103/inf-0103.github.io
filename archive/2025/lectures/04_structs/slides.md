---
title:
- "INF-0103 Sammensatte datatyper (structs)"
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

* Sammensatte datatyper (structs)

. . .

# Hvordan lagre flere verdier i en verdi

. . .

# Syntax

```c
struct min_struct {
    int forste_verdi;
    int andre_verdi;
}

typedef struct min_struct min_struct_t;
```

. . .

# Initialisering

```c
min_struct_t a = {.foerste_verdi = 10, .andre_verdi = 20};
min_struct_t b = {0};
min_struct_t c = {.andre_verdi = 5};
return (min_struct_t){.foerste_verdi = 20, .andre_verdi = 40};
```

. . .

# Hvor stor er en struct?

```c
sizeof(min_struct) == 8;
```

. . .

# Padding & alignment

Feltene i en struct er alignet med det største elementet.

```c
typedef struct {
    char a;
    int b;
    char c;
} struct_a;

typedef struct {
    int b;
    char a;
    char c;
} struct_b;

printf("%d\n", sizeof(struct_a));
printf("%d\n", sizeof(struct_b));

. . .

# Unions

En annen nyttig struktur er unions, hvor flere mulige datatyper lagres i samme minneområde.

```c

typedef union {
    int number;
    char word[4];
} my_u;

my_u a = {.number = 10};
```
