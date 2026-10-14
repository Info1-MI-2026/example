# Semaine 4 — Arguments et boucles

[← Retour à l'index](../README.md)

## 06.10 - Les arguments de `main`

Les **arguments** sont des valeurs passées au programme **au moment de le lancer**, dans le terminal :

```bash
./app 12 -h
```

Pour les récupérer, `main` reçoit deux paramètres :

```c
int main(int argc, char *argv[])
```

- `argc` (*argument count*) : le **nombre** d'arguments, nom du programme compris. Il vaut donc **au moins 1**.
- `argv` (*argument vector*) : un **tableau de textes** qui contient les arguments. On y accède avec un indice qui commence à 0.

| `./app 12 -h` | Valeur |
|---|---|
| `argc` | `3` |
| `argv[0]` | `"./app"` (le nom du programme) |
| `argv[1]` | `"12"` |
| `argv[2]` | `"-h"` |

Un argument s'affiche avec le format `%s` (texte) : `printf("%s\n", argv[1]);`

### Toujours tester `argc`

Avant d'accéder à `argv[i]`, il faut vérifier que l'argument existe, c'est-à-dire que `argc > i`.

```c
if (argc < 2) {
    printf("Il faut au moins un argument\n");
    return 1; // code d'erreur : le programme s'arrête ici
}
printf("Premier argument : %s\n", argv[1]); // argv[1] existe
```

> [!WARNING]
> Lire `argv[1]` alors que l'utilisateur n'a rien passé (`argc` vaut 1) fait planter le programme.

Le `return` dans `main` arrête le programme. Par convention, `0` signifie « tout s'est bien passé » et une autre valeur indique une erreur.

### Convertir un argument en nombre avec `sscanf`

Un argument est **toujours un texte** : `"12"` n'est pas le nombre `12`.
Pour le convertir, on utilise `sscanf`, qui fonctionne comme `scanf` mais lit dans un **texte** au lieu du clavier.

```c
int val1 = 0;
int nbr_conv = sscanf(argv[1], "%d", &val1); // ne pas oublier le &

if (nbr_conv == 1) {
    printf("2 * val1 = %d\n", 2 * val1);
}
else {
    printf("'%s' n'est pas un entier\n", argv[1]);
    return 3;
}
```

Comme `scanf`, `sscanf` **retourne le nombre de valeurs converties**. Il faut toujours le tester : `./app abc` donne `nbr_conv == 0`.

### Accéder à un caractère d'un argument

`argv[2]` est un texte, et `argv[2][0]` est son **premier caractère**. C'est pratique pour reconnaître une option comme `-h` :

```c
if (argc > 2 && argv[2][0] == '-' && argv[2][1] == 'h') {
    printf("Aide : ./app <entier> [-h]\n");
}
```

Voir [arg.c](../arg.c) pour l'exemple complet.

### Théorie

- [Entrées formatées et `sscanf`](https://heig-tin-info.github.io/handout/content/stdio.html#entrees-formatees)
- [Arguments et options](https://heig-tin-info.github.io/handout/content/processus.html#arguments-et-options), [fonction `main`](https://heig-tin-info.github.io/handout/content/processus.html#fonction-main) et sa [valeur de retour](https://heig-tin-info.github.io/handout/content/processus.html#valeur-de-retour)

### Exercices

- [Exercices sur les arguments](https://github.com/tony-maulaz/info1-exercices/blob/main/ex60-arguments.md)

---

### Questions

**1. Que contiennent `argc` et `argv` ? Quelle est la valeur minimale de `argc` ? Pourquoi ?**

**2. Que valent `argc`, `argv[0]` et `argv[2]` pour la commande `./app 3.5 bonjour` ?**

**3. Pourquoi faut-il tester `argc` avant d'utiliser `argv[1]` ?**

**4. `argv[1]` vaut `"12"`. Pourquoi ne peut-on pas écrire directement `int x = argv[1];` ? Comment convertir cet argument en `int` ?**

**5. Quelle est la différence entre `scanf` et `sscanf` ?**

**6. Que retourne `sscanf(argv[1], "%d", &val)` si l'utilisateur lance `./app abc` ?**

**7. Que vaut `argv[1][0]` pour la commande `./app -h` ?**

**8. Écrire un programme qui reçoit deux entiers en arguments et affiche leur somme, avec tous les contrôles d'erreur.**

---

## 07.10 - Les boucles

Une boucle permet de **répéter** un bloc de code tant qu'une condition est vraie.
Le C propose trois boucles : `while`, `do ... while` et `for`.

### La boucle `while`

```c
int cpt = 0;
while (cpt <= 10) {
    printf("cpt : %d\n", cpt);
    cpt += 1; // équivalent à cpt++ ou cpt = cpt + 1
}
```

- La condition est testée **avant** chaque tour.
- Si elle est fausse dès le départ, le bloc n'est **jamais** exécuté.
- Il faut modifier une variable de la condition dans le bloc, sinon la boucle ne s'arrête jamais (**boucle infinie**).

### La boucle `do ... while`

```c
int cpt = 11;
do {
    printf("cpt : %d\n", cpt); // affiché une fois, même si cpt vaut 11
    cpt++;
} while (cpt <= 10);
```

- La condition est testée **après** chaque tour : le bloc est exécuté **au moins une fois**.
- Ne pas oublier le `;` après le `while (...)`.

### La boucle `for`

```c
for (int i = 0; i <= 10; i += 2) {
    printf("i : %d\n", i); // i vaut 0, 2, 4, 6, 8, 10
}
```

`for (initialisation; condition; incrément)` :

1. l'**initialisation** est exécutée une seule fois, au début ;
2. la **condition** est testée avant chaque tour ;
3. l'**incrément** est exécuté à la fin de chaque tour.

> [!NOTE]
> Une variable déclarée dans le `for` (`int i`) n'existe **que** dans la boucle.

On peut compter à l'envers, et même avec des `char` (un `char` est un entier, son code ASCII) :

```c
for (char c = 'X'; c >= 'E'; c--) {
    printf("%c", c); // XWVUTSRQPONMLKJIHGFE
}
```

### Quelle boucle choisir ?

| Boucle | Quand l'utiliser |
|---|---|
| `for` | le nombre de tours est **connu** à l'avance (compter de 0 à 10) |
| `while` | on répète **tant que** quelque chose est vrai, le nombre de tours n'est pas connu |
| `do ... while` | le bloc doit être exécuté **au moins une fois** (ex. redemander une saisie) |

### Opérateurs d'affectation composée

| Écriture courte | Équivalent |
|---|---|
| `i++` | `i = i + 1` |
| `i--` | `i = i - 1` |
| `i += 2` | `i = i + 2` |
| `i -= 2` | `i = i - 2` |
| `i *= 2` | `i = i * 2` |
| `i /= 2` | `i = i / 2` |

Voir [boucle.c](../boucle.c) pour l'exemple complet.

### Théorie

- [Les boucles](https://heig-tin-info.github.io/handout/content/control-structures.html#les-boucles) : [`while`](https://heig-tin-info.github.io/handout/content/control-structures.html#while), [`do-while`](https://heig-tin-info.github.io/handout/content/control-structures.html#do-while), [`for`](https://heig-tin-info.github.io/handout/content/control-structures.html#for), [boucles infinies](https://heig-tin-info.github.io/handout/content/control-structures.html#boucles-infinies)

### Exercices

- [Exercices sur la boucle `while`](https://github.com/tony-maulaz/info1-exercices/blob/main/ex90-boucle-while.md)
- [Exercices sur la boucle `for`](https://github.com/tony-maulaz/info1-exercices/blob/main/ex91-boucle-for.md)

---

### Questions

**1. Quelle est la différence entre une boucle `while` et une boucle `do ... while` ?**

**2. Combien de fois le bloc d'une boucle `while (cpt <= 10)` est-il exécuté si `cpt` vaut 11 au départ ? Et pour un `do ... while` ?**

**3. Dans `for (int i = 0; i < 5; i++)`, dans quel ordre sont exécutées les trois parties ? Combien de tours fait la boucle ?**

**4. Qu'affiche `for (int i = 10; i > 0; i -= 3) printf("%d ", i);` ?**

**5. Qu'est-ce qu'une boucle infinie ? Donner un exemple.**

**6. Écrire une boucle qui affiche tous les multiples de 7 entre 1 et 100.**

**7. Quelle boucle choisir pour redemander une valeur à l'utilisateur tant qu'elle n'est pas valide ? Pourquoi ?**
