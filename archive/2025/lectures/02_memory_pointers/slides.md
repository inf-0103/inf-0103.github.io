---
title:
- "INF-0103 Minne I: Pekere, tabeller, generell oversikt"
author:
- "Jakob Peder Pettersen, UiT – Norges arktiske universitet"
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

* Pass-by-value og pass-by-reference

. . .

* Hva er pekere?

. . .

* Tabeller (**arrays**)

. . .

* Peker-aritimetikk

. . .

Tilsvarer kapittel 16 av Patt & Patel

# Et (forhåpentligvis) kjent eksempel: `printf()` og `scanf()`

* Vi kan skrive `printf("Tallet er: %d\n", tall);`

. . .

* Hva er da problemet med `scanf("%d", tall);`?

. . .

* Hvorfor må vi skrive `scanf("%d", &tall);`?

. . .

* Hva er feil med `printf("Tallet er: %d\n", &tall);`?

. . .

* Hva gjør egenlig `&`?

# Forskjell på pass-by-reference og pass-by-value

* `printf()` bruker **pass-by-value**; verdiene som skrives ut kopieres inn i funksjonen

. . .

* Hvorfor vil dette ikke fungere for `scanf()`?

. . .

* `scanf()` må bruke **pass-by-reference**; en referanse til variablene blir sendt til funksjonen uten kopiering av de underliggende verdiene



# Pekere (**pointers**)

* Alle C-funksjoner bruker **pass-by-value**, men det finnes en egen kategori variabler som inneholder referansen til andre variabler

. . .

* Disse kalles   **pekere** (**pointers**)

. . .

* Notasjon for type: Grunntype med `*` etter (`int` -> `int*`, `double` -> `double*`).

. . .

* `&` er en operator som returerer **minneadressen** til en variabel

. . .

* Derefereningsoperatoren `*` (brukt unitært) gjør det motsatte, den henter ut verdien som det pekes på


# Eksempel med pass-by-value og pass-by-reference

# Hva foregår her?

![Variabler og adresser i programmet vårt](memory_layout.pdf){ width=350px }


# Semantikk for verdier

Hvorfor fungerer ikke dette?

```C
int a = 4;
int b = 9;
int *tall_sum_peker = &(a + b);
```

. . .

* `a` og `b` er venstreverdier (**lvalues**) -> Har sin egen plass i minnet. Man kan tilordne verdier og ta adressen.
* `4` og `(a + b)` er høyreverdier (**rvalues**) -> Har ikke sin egen plass i minnet. Man kan **ikke** tilordne verdier eller ta adressen.

# Forskjellige typer pekere

* Fundamentale datatyper: `int*`, `char*`, `double*`

. . .

* Sammensatte strukturer (**structs**): `Person*`

. . .

* Andre pekere: `int**`, `char**`

. . .

* Funksjoner: `void (*)(int *)` (signaturen til `&bar` i eksemplet vårt)

. . .

* Ubestemt type: `void*`

# Minneadresser er "bare" tall

* Pekere kan hardkodes til å peke på en bestemt adresse:

```C
// Nesten alltid en dårlig idé
int *p = x03ab; // Heksadesimale tall for minneadresser
```

. . .

* Vanligvis er det bare *en* hardkodet adresse vi behøver å bry oss om: `NULL` med definisjonen:

```C
#define NULL ((void*)0)
```

. . .

* Brukes ofte som feilkode eller for å indikere at pekeren ikke er i bruk


# Oppgave: Hva er galt her?

```C
int *foo() {
    int verdi = 204;
    return &verdi;
}

int main() {
    int *p = foo();
    int verdi = *p;
    return 0;
}
```

# Pekere og gyldighet


* Å dereferere ugyldig minne er udefinert oppførsel (**undefined behavior**)

. . .

* Å *ha* en peker som peker på ugyldig minne er derimot OK (jamfør `NULL`)

. . .

* Vi må selv avgjøre utefra konteksten når det er trygt å bruke en peker

. . .

* Vi har ingen garanti for hva som skjer

. . .

* Ikke garantert noe kræsj, kan endre seg av hvilken som helst grunn


# Statiske tabeller (**arrays**)

* Struktur der flere elementer av samme type ligger etter hverandre

. . .

* Kompilatoren må vite størrelsen på tabellen på forhånd

. . .

* Syntaks:

```C
int arr[5];
```

. . .

* eller

```C
int arr[] = {-4, 5, 2, 130, -11};
```

. . .

* Oppfører seg som en mellomting mellom "vanlige" datatyper og pekere

# Peker-aritimetikk

* Mest relevant med tabeller og liknende strukturer

. . .

* Aritmetriske operasjoner på pekere og tabeller

. . .

* For variabler bestående av flere bytes bruker vi den første adressen

. . .

* Tabeller er null-indekserte av naturlige grunner

. . .

* Ofte er indekseringsnotasjonen `arr[3]` (`*(arr + 3)`) mer hensiktsmessig

# Eksempel med pekeraritimetikk

# Oppførsel til tabeller i funksjoner

* Kan være argument til andre funksjoner, men i virkeligheten det er adressen til tabellen som kopieres (unntak fra pass-by-value)

. . .

* Fenomenet kalles **pointer decay**

. . .

* Ingen informasjon om antall elementer det pekes til -> Vi må often oppgi lengden i tillegg til pekeren

# Eksempel med sortering av tabell


# Hva hvis antall elementer ikke kjent på forhånd?

*  Buffer: Lag en tabell som forhåpentligvis er stor nok til å romme data

. . .

*  Bruk bare den første biten
  
. . .

*  Ofte brukt til tekststrenger (mer om det senere i kurset)

. . .

*  Sløsing med minne

. . .

*  To hovedstrategier:
   - Tabeller med variabel lengde (**variable-length array**, **VLA**)
   - Dynamisk minneallokering (kommer senere i kurset)

# Tabeller med variabel lengde

* Deklareres på samme måte som statiske tabeller, men lengden er ikke et konstantuttrykk

. . .

* Allokeres ved deklarasjon

. . .

* Deallokeres automatisk når tabellen går ut av scope

. . .

* Oppfører seg ellers som en statisk tabell

. . .

* Ikke tilgjengelig i C++

# Eksemplet vårt med brukerbestemt lengde
