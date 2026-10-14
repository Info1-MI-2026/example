# Semaine 5 — scanf avec plusieurs valeurs et ternaire

[← Retour à l'index](../README.md)

## 14.10 - `scanf` avec plusieurs valeurs

Un seul `scanf` peut lire **plusieurs valeurs** : on met un `%` par valeur dans le format,
et une variable (avec son `&`) pour chacune, **dans le même ordre**.

```c
int val1 = 0;
double val2 = 0;

printf("Entrer A et B : ");
scanf("%d %lf", &val1, &val2); // saisie : 12 3.5
```

### Vérifier la saisie avec la valeur de retour

`scanf` **retourne le nombre de valeurs lues correctement**. On la stocke dans une variable pour vérifier que tout a été lu.

```c
int check = scanf("%d %lf", &val1, &val2); // check vaut 0, 1 ou 2

if (check == 2) {
    printf("Tout est ok\n");
}
else {
    printf("Il y a une erreur\n");
}
```

| Saisie | `check` | Explication |
|---|---|---|
| `12 3.5` | `2` | les deux valeurs sont lues |
| `12 abc` | `1` | seul `val1` est lu, `val2` n'est pas modifié |
| `abc` | `0` | rien n'est lu |

> [!WARNING]
> `scanf` s'arrête à la **première erreur** : les variables suivantes ne sont pas modifiées.
> Toujours tester la valeur de retour avant d'utiliser les valeurs lues.

### Les séparateurs dans le format

Les caractères du format indiquent ce que l'utilisateur **doit** taper entre les valeurs.

| Format | Saisie acceptée | Remarque |
|---|---|---|
| `"%d %lf"` | `12 3.5` | un espace dans le format accepte un ou plusieurs espaces, ou un retour à la ligne |
| `"%d,%lf"` | `12,3.5` | la virgule doit être tapée ; `12 3.5` donne `check == 1` |
| `"%d %c %lf"` | `12,3.5` ou `12 / 3.5` | le séparateur est lu dans un `char` pour être vérifié |

Pour accepter plusieurs séparateurs, on lit le séparateur dans un `char` puis on le teste :

```c
char c = ' ';
int check = scanf("%d %c %lf", &val1, &c, &val2);

if (check == 3 && (c == ',' || c == '/')) {
    printf("Saisie ok : %d %lf\n", val1, val2);
}
```

### L'opérateur ternaire

L'opérateur ternaire `condition ? valeur_si_vrai : valeur_si_faux` remplace un `if` / `else` simple
qui **choisit une valeur**.

```c
// version if / else
if (val1 > 0) {
    is_positive = true;
}
else {
    is_positive = false;
}

// version ternaire
is_positive = val1 > 0 ? true : false;

int val_abs = val1 > 0 ? val1 : -val1;  // valeur absolue
char result = check == 3 ? 'Y' : 'N';   // 'Y' si la saisie est complète
```

> [!NOTE]
> Le ternaire est pratique pour une affectation courte. Dès que le code devient long, un `if` / `else` est plus lisible.

Voir [saisie_multiple.c](../saisie_multiple.c) pour l'exemple complet.

### Théorie

- [`scanf`](https://heig-tin-info.github.io/handout/content/stdio.html#scanf) et les [entrées formatées](https://heig-tin-info.github.io/handout/content/stdio.html#entrees-formatees)
- [Opérateur ternaire](https://heig-tin-info.github.io/handout/content/operators.html#operateur-ternaire)

---

### Questions

**1. Comment lire un `int` et un `double` avec un seul `scanf` ?**

**2. Que retourne `scanf` ? À quoi sert cette valeur ?**

**3. Avec `scanf("%d %lf", &a, &b);`, que vaut le retour si l'utilisateur tape `5 abc` ? Que valent `a` et `b` ?**

**4. Avec le format `"%d,%lf"`, l'utilisateur tape `12 3.5`. Que se passe-t-il ?**

**5. Écrire un `scanf` qui lit une date au format `jour/mois/annee` (par exemple `14/10/2026`) et vérifie que les trois valeurs ont été lues.**

**6. Réécrire avec l'opérateur ternaire : `if (a > b) max = a; else max = b;`**

**7. Que vaut `x` après `int x = 7 % 2 == 0 ? 10 : 20;` ?**
