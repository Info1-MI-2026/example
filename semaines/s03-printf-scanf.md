# Semaine 3 — printf et scanf

[← Retour à l'index](../README.md)

## 30.09 - `printf` et `scanf`

`printf` **affiche** une valeur, `scanf` **lit** une valeur entrée au clavier.
Les deux utilisent le même principe : une **chaîne de format** avec des `%` qui indiquent le type de la valeur.

### Lire une valeur avec `scanf`

```c
double ask_value = 0;

printf("Entrer une valeur entre -10 et +10 : ");
scanf("%lf", &ask_value);
printf("Valeur saisie : %lf\n", ask_value);
```

- Le **format** (`"%lf"`) indique le type à lire, comme pour `printf` : `%d` pour un `int`, `%lf` pour un `double`.
- Il faut mettre un **`&`** devant le nom de la variable : `scanf` a besoin de savoir **où** ranger la valeur lue.

> [!WARNING]
> Oublier le `&` (`scanf("%lf", ask_value);`) compile, mais le programme plante ou donne un résultat faux.
> Dans `printf`, il n'y a **pas** de `&`.

### Formater l'affichage avec `printf`

Entre le `%` et la lettre du type, on peut ajouter une **largeur**, une **précision** et des options.

| Code | Exemple | Affichage | Explication |
|---|---|---|---|
| `%d` | `printf("%d", 12345)` | `12345` | valeur seule |
| `%6d` | `printf("%6d", -12)` | `   -12` | largeur de 6, aligné à droite |
| `%-6d` | `printf("%-6d", -12)` | `-12   ` | largeur de 6, aligné à gauche |
| `%06d` | `printf("%06d", 12345)` | `012345` | complète avec des `0` |
| `%.2lf` | `printf("%.2lf", 123.45)` | `123.45` | 2 chiffres après la virgule |
| `%10.2lf` | `printf("%10.2lf", 123.45)` | `    123.45` | largeur totale de 10, 2 décimales |
| `%010.2lf` | `printf("%010.2lf", -12300.45)` | `-012300.45` | largeur 10, complété par des `0` |

> [!NOTE]
> La largeur compte **tous** les caractères : le signe `-`, les chiffres et le point.
> Si la valeur est plus longue que la largeur, elle est affichée en entier (rien n'est coupé).

La largeur est utile pour **aligner** des valeurs en colonnes :

```
Value :     123.45 [V]
Value :    1230.45 [V]
```

Voir [scanf.c](../scanf.c) pour l'exemple complet.

---

### Questions

**1. À quoi sert la chaîne de format dans `printf` et `scanf` ?**

**2. Quel format utilise-t-on pour lire un `int` avec `scanf` ? Et un `double` ?**

**3. Pourquoi faut-il mettre un `&` devant la variable dans `scanf` ? En faut-il un dans `printf` ?**

**4. Qu'affiche `printf("[%5d]", 42);` ? Et `printf("[%-5d]", 42);` ?**

**5. Qu'affiche `printf("[%04d]", 7);` ?**

**6. Qu'affiche `printf("[%8.3lf]", 3.14159);` ?**

**7. Qu'affiche `printf("[%3d]", 12345);` ?**
