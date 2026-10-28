# Semaine 6 — switch, break et continue

[← Retour à l'index](../README.md)

## 28.10 - Le `switch`

Le `switch` remplace une suite de `if` / `else if` qui comparent **toujours la même variable** à des valeurs différentes.

```c
// version if / else if
if (choix == 1) {
    printf("Démarrer\n");
}
else if (choix == 2) {
    printf("Arrêter\n");
}
else {
    printf("Choix invalide\n");
}

// version switch
switch (choix) {
    case 1:
        printf("Démarrer\n");
        break;
    case 2:
        printf("Arrêter\n");
        break;
    default:
        printf("Choix invalide\n");
}
```

- `switch (variable)` : la valeur de la variable est comparée à chaque `case`.
- `case valeur:` : le code qui suit est exécuté si la variable vaut `valeur`. Ces lignes s'appellent des **labels**.
- `break` : sort du `switch`.
- `default:` : exécuté si **aucun** `case` ne correspond. Il est facultatif, mais recommandé pour traiter les cas d'erreur.

> [!NOTE]
> Après un `case`, on ne peut mettre qu'une **valeur entière constante** : un nombre (`case 3:`) ou un caractère (`case 'A':`).
> Pas de `double`, pas de variable et pas de comparaison : `case x > 10:` est interdit. Pour tester un intervalle, il faut un `if`.

### L'oubli du `break`

Sans `break`, l'exécution **continue dans les `case` suivants**, sans tester leur valeur, jusqu'au prochain `break` ou jusqu'à la fin du `switch`.

```c
int niveau = 2;

switch (niveau) {
    case 1:
        printf("Débutant\n");
    case 2:
        printf("Moyen\n");   // pas de break : on continue dans le case 3
    case 3:
        printf("Expert\n");
        break;
    default:
        printf("Inconnu\n");
}
// affiche Moyen puis Expert
```

> [!WARNING]
> Un `break` oublié compile sans erreur, mais le code des `case` suivants est aussi exécuté.
> C'est l'erreur la plus fréquente avec le `switch`.

### Regrouper plusieurs valeurs

Plusieurs `case` placés à la suite, sans instruction entre eux, exécutent le **même code**.

```c
char choix = ' ';

printf("Votre choix (a : ajouter, q : quitter) : ");
scanf("%c", &choix);

switch (choix) {
    case 'a':
    case 'A':
        printf("Ajouter\n");
        break;
    case 'q':
    case 'Q':
        printf("Quitter\n");
        break;
    default:
        printf("Choix '%c' inconnu\n", choix);
}
```

> [!NOTE]
> Dans une boucle, le `break` d'un `switch` sort **seulement du `switch`** : la boucle continue au tour suivant.

### `switch` ou `if` ?

| Situation | Choix |
|---|---|
| une **même variable** comparée à des valeurs **précises** (`1`, `2`, `'q'`…) | `switch` |
| un **intervalle** (`x > 10`), un `double` ou des conditions sur **plusieurs variables** | `if` / `else if` |

### `break` et `continue` dans les boucles

- `break` **arrête** la boucle immédiatement : le programme continue après la boucle.
- `continue` **saute la fin du tour** : on passe directement au tour suivant.

```c
for (int i = 1; i <= 10; i++) {
    if (i % 3 == 0) {
        continue; // les multiples de 3 ne sont pas affichés
    }
    if (i == 8) {
        break;    // on sort de la boucle à 8
    }
    printf("%d ", i);
}
// affiche : 1 2 4 5 7
```

> [!WARNING]
> Dans un `for`, `continue` exécute quand même l'incrément (`i++`) avant le tour suivant.
> Dans un `while`, si l'incrément est placé **après** le `continue`, il est sauté : la boucle peut devenir infinie.

### Théorie

- [`switch`](https://heig-tin-info.github.io/handout/content/control-structures.html#switch)
- [`break`](https://heig-tin-info.github.io/handout/content/control-structures.html#break) et [`continue`](https://heig-tin-info.github.io/handout/content/control-structures.html#continue)

### Exercices

- [Exercices sur le `switch`](https://github.com/tony-maulaz/info1-exercices/blob/main/ex100-switch.md)
- [Exercices sur `break` et `continue`](https://github.com/tony-maulaz/info1-exercices/blob/main/ex92-boucle.md) (Ex 1 à 3)

---

### Questions

**1. Dans quel cas peut-on remplacer une suite de `if` / `else if` par un `switch` ?**

**2. À quoi sert le `break` dans un `switch` ? Que se passe-t-il si on l'oublie ?**

**3. À quoi sert `default` ? Est-il obligatoire ?**

**4. Peut-on écrire `case 2.5:` ou `case x > 10:` ? Pourquoi ?**

**5. Comment exécuter le même code pour les valeurs `'o'` et `'O'` ?**

**6. Qu'affiche le code suivant si `n` vaut 1 ? Et si `n` vaut 3 ?**

```c
switch (n) {
    case 1:
        printf("A");
    case 2:
        printf("B");
        break;
    default:
        printf("C");
}
```

**7. Réécrire le code suivant avec un `switch` :**

```c
if (note == 6) {
    printf("Excellent\n");
}
else if (note == 5) {
    printf("Bien\n");
}
else if (note == 4) {
    printf("Suffisant\n");
}
else {
    printf("Insuffisant\n");
}
```

**8. Un `break` placé dans un `switch`, lui-même dans une boucle `for`, arrête-t-il la boucle ?**

**9. Quelle est la différence entre `break` et `continue` dans une boucle ?**

**10. Qu'affiche le code suivant ?**

```c
for (int i = 0; i < 6; i++) {
    if (i == 2) {
        continue;
    }
    if (i == 4) {
        break;
    }
    printf("%d ", i);
}
```

**11. Pourquoi la boucle suivante ne s'arrête-t-elle jamais ?**

```c
int i = 0;
while (i < 10) {
    if (i == 5) {
        continue;
    }
    printf("%d ", i);
    i++;
}
```
