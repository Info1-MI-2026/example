# Semaine 5 — scanf avec plusieurs valeurs, ternaire et buffer d'entrée

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

## 15.10 - Le buffer d'entrée

### Le buffer d'entrée

Quand l'utilisateur tape au clavier, les caractères ne vont pas directement dans les variables du programme.
Ils sont d'abord stockés dans une zone mémoire appelée **buffer d'entrée** (`stdin`).

Le programme ne reçoit la ligne qu'au moment où l'utilisateur appuie sur **Entrée**.
La touche Entrée est elle aussi un caractère : `'\n'` (code ASCII 10).

Si l'utilisateur tape `abc12` puis Entrée, le buffer contient :

```
'a'  'b'  'c'  '1'  '2'  '\n'
```

### Comment `scanf` lit le buffer

`scanf` lit les caractères **un par un depuis le début du buffer** et s'arrête dès qu'un caractère
ne correspond pas au format demandé.

Les caractères qui ne sont pas utilisés **restent dans le buffer**. Le prochain `scanf` (ou `getchar`) repartira de là.

| Saisie | `scanf("%d", &value)` retourne | `value` | Reste dans le buffer |
|---|---|---|---|
| `12` | `1` | `12` | `'\n'` |
| `12abc` | `1` | `12` | `abc\n` |
| `abc12` | `0` | non modifié | `abc12\n` |

> [!WARNING]
> Même une saisie réussie laisse au minimum le `'\n'` dans le buffer.

### `getchar`

`getchar()` lit **un seul caractère** dans le buffer et le retire du buffer.
Si le buffer est vide, `getchar()` attend que l'utilisateur tape une nouvelle ligne.

`getchar()` retourne un `int` (le code du caractère).

### Exemple : voir ce qui reste dans le buffer

Le programme [buffer.c](../buffer.c) fait deux `scanf("%d", …)` puis lit six caractères avec `getchar()`.
Résultat avec la saisie `abc12` :

```
Entrez un entier : abc12
scanf retourne 0, value = 0
2e scanf retourne 0, value = 0
Caractère 1 : 'a' (code 97)
Caractère 2 : 'b' (code 98)
Caractère 3 : 'c' (code 99)
Caractère 4 : '1' (code 49)
Caractère 5 : '2' (code 50)
Caractère 6 : '
' (code 10)
```

On constate que :

- le premier `scanf` échoue sur le `'a'` et ne le retire pas du buffer ;
- le deuxième `scanf` **n'attend pas** de saisie : il retombe sur le même `'a'` et échoue à nouveau ;
- tous les caractères tapés sont encore dans le buffer, y compris le `'\n'`.

À essayer : relancer le programme avec `12abc`, puis avec seulement `a`.

### Vider le buffer

Pour repartir sur une saisie propre, on lit et on jette tous les caractères jusqu'au `'\n'` inclus :

```c
while (getchar() != '\n') {}
```

On vide le buffer **après chaque `scanf`**, que la saisie ait réussi ou non.

### Application : redemander une saisie

Sans vidage du buffer, une boucle de re-saisie tourne à l'infini : `scanf` retombe toujours sur les mêmes
caractères invalides. Avec le vidage, l'utilisateur peut recommencer :

```c
double x;
int ret;

do {
    printf("Coordonnée x : ");
    ret = scanf("%lf", &x);
    while (getchar() != '\n') {}

    if (ret != 1) {
        printf("Valeur invalide, recommencez\n");
    }
} while (ret != 1);
```

> [!NOTE]
> À retenir :
> - les caractères tapés vont dans un buffer ; Entrée ajoute un `'\n'` ;
> - `scanf` s'arrête au premier caractère invalide et le laisse dans le buffer ;
> - toujours tester la valeur de retour de `scanf` ;
> - vider le buffer après chaque `scanf` avec `while (getchar() != '\n') {}`.

### Théorie

- [Entrées/sorties](https://heig-tin-info.github.io/handout/content/stdio.html)

---

### Questions

**1. Que contient le buffer après que l'utilisateur a tapé `42` puis Entrée, et qu'un `scanf("%d", &n)` a été exécuté ?**

**2. Avec `scanf("%d", &n)`, l'utilisateur tape `7x`. Que retourne `scanf`, que vaut `n` et que reste-t-il dans le buffer ?**

**3. Pourquoi un deuxième `scanf("%d", &n)` n'attend-il pas de saisie après une saisie invalide ?**

**4. Quel est le type de retour de `getchar()` ?**

**5. Écrire la ligne qui vide le buffer jusqu'au retour à la ligne.**

**6. Écrire une boucle qui redemande un entier entre 1 et 10 tant que la saisie est invalide ou hors limites.**
