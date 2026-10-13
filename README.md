# 07.10 - Les boucles

Une boucle permet de **répéter** un bloc de code tant qu'une condition est vraie.
Le C propose trois boucles : `while`, `do ... while` et `for`.

## La boucle `while`

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

## La boucle `do ... while`

```c
int cpt = 11;
do {
    printf("cpt : %d\n", cpt); // affiché une fois, même si cpt vaut 11
    cpt++;
} while (cpt <= 10);
```

- La condition est testée **après** chaque tour : le bloc est exécuté **au moins une fois**.
- Ne pas oublier le `;` après le `while (...)`.

## La boucle `for`

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

## Quelle boucle choisir ?

| Boucle | Quand l'utiliser |
|---|---|
| `for` | le nombre de tours est **connu** à l'avance (compter de 0 à 10) |
| `while` | on répète **tant que** quelque chose est vrai, le nombre de tours n'est pas connu |
| `do ... while` | le bloc doit être exécuté **au moins une fois** (ex. redemander une saisie) |

## Opérateurs d'affectation composée

| Écriture courte | Équivalent |
|---|---|
| `i++` | `i = i + 1` |
| `i--` | `i = i - 1` |
| `i += 2` | `i = i + 2` |
| `i -= 2` | `i = i - 2` |
| `i *= 2` | `i = i * 2` |
| `i /= 2` | `i = i / 2` |

Voir [boucle.c](boucle.c) pour l'exemple complet.

## Théorie

- [Les boucles](https://heig-tin-info.github.io/handout/content/control-structures.html#les-boucles) : [`while`](https://heig-tin-info.github.io/handout/content/control-structures.html#while), [`do-while`](https://heig-tin-info.github.io/handout/content/control-structures.html#do-while), [`for`](https://heig-tin-info.github.io/handout/content/control-structures.html#for), [boucles infinies](https://heig-tin-info.github.io/handout/content/control-structures.html#boucles-infinies)

## Exercices

- [Exercices sur la boucle `while`](https://github.com/tony-maulaz/info1-exercices/blob/main/ex90-boucle-while.md)
- [Exercices sur la boucle `for`](https://github.com/tony-maulaz/info1-exercices/blob/main/ex91-boucle-for.md)

---

## Questions

**1. Quelle est la différence entre une boucle `while` et une boucle `do ... while` ?**

**2. Combien de fois le bloc d'une boucle `while (cpt <= 10)` est-il exécuté si `cpt` vaut 11 au départ ? Et pour un `do ... while` ?**

**3. Dans `for (int i = 0; i < 5; i++)`, dans quel ordre sont exécutées les trois parties ? Combien de tours fait la boucle ?**

**4. Qu'affiche `for (int i = 10; i > 0; i -= 3) printf("%d ", i);` ?**

**5. Qu'est-ce qu'une boucle infinie ? Donner un exemple.**

**6. Écrire une boucle qui affiche tous les multiples de 7 entre 1 et 100.**

**7. Quelle boucle choisir pour redemander une valeur à l'utilisateur tant qu'elle n'est pas valide ? Pourquoi ?**


# 30.09 - `printf` et `scanf`

`printf` **affiche** une valeur, `scanf` **lit** une valeur entrée au clavier.
Les deux utilisent le même principe : une **chaîne de format** avec des `%` qui indiquent le type de la valeur.

## Lire une valeur avec `scanf`

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

## Formater l'affichage avec `printf`

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

Voir [scanf.c](scanf.c) pour l'exemple complet.

---

## Questions

**1. À quoi sert la chaîne de format dans `printf` et `scanf` ?**

**2. Quel format utilise-t-on pour lire un `int` avec `scanf` ? Et un `double` ?**

**3. Pourquoi faut-il mettre un `&` devant la variable dans `scanf` ? En faut-il un dans `printf` ?**

**4. Qu'affiche `printf("[%5d]", 42);` ? Et `printf("[%-5d]", 42);` ?**

**5. Qu'affiche `printf("[%04d]", 7);` ?**

**6. Qu'affiche `printf("[%8.3lf]", 3.14159);` ?**

**7. Qu'affiche `printf("[%3d]", 12345);` ?**


# 24.09 - Les conditions

Une condition permet d'exécuter un bloc de code **seulement si** une expression est vraie.

```c
if (cpt > 0) {
    printf("Le compteur est positif\n");
}
else if (cpt < -10) {
    printf("Le compteur est plus petit que -10\n");
}
else if (cpt < 0) {
    printf("Le compteur est négatif\n");
}
else {
    printf("Le compteur vaut 0\n");
}
```

- `if` : le bloc est exécuté si la condition est vraie.
- `else if` : testé **seulement si** les conditions précédentes étaient fausses. On peut en mettre plusieurs.
- `else` : exécuté si **aucune** condition n'était vraie. Il est facultatif.

Les conditions sont testées dans l'ordre : dès qu'une est vraie, son bloc est exécuté et les suivantes sont ignorées.

> [!NOTE]
> En C, une valeur égale à `0` est **fausse**, toute autre valeur est **vraie**. `if (3)` est donc toujours exécuté.

## Opérateurs de comparaison

Le résultat d'une comparaison vaut `1` (vrai) ou `0` (faux).

| Opérateur | Signification |
|---|---|
| `==` | égal |
| `!=` | différent |
| `<` | plus petit |
| `<=` | plus petit ou égal |
| `>` | plus grand |
| `>=` | plus grand ou égal |

> [!WARNING]
> `=` est une **affectation**, `==` est une **comparaison**. `if (a = 5)` modifie `a` et est toujours vrai !

On combine plusieurs conditions avec les opérateurs logiques : `&&` (ET), `||` (OU) et `!` (NON).

```c
if (cpt > 0 && condition1) {
    printf("Le compteur est positif et condition1 est vraie\n");
}

if (!condition1) { // équivalent à : condition1 == false
    printf("condition1 est fausse\n");
}
```

## Le type `bool`

On peut stocker le résultat d'une condition dans une variable de type `bool`, qui vaut `true` ou `false`.
Pour l'utiliser, il faut inclure `stdbool.h`.

```c
#include <stdbool.h>

bool condition1 = false;    // false vaut 0, true vaut 1
bool est_positif = cpt > 0; // résultat d'une comparaison

if (est_positif) {
    printf("Le compteur est positif\n");
}
```

## Conventions de nommage

| Convention | Exemple |
|---|---|
| snake_case | `cpt_machine` |
| camelCase | `cptMachine` |
| PascalCase | `CptMachine` |

Le C est sensible à la casse : ces trois noms désignent trois variables **différentes**. Choisir une convention et s'y tenir.

Voir [condition.c](condition.c) pour l'exemple complet.

## Exercices

- [Exercices sur les conditions](https://github.com/tony-maulaz/info1-exercices/blob/main/ex20-conditions.md)

---

## Questions

**1. Quelle est la différence entre `if`, `else if` et `else` ?**

**2. Si plusieurs conditions d'une suite `if` / `else if` sont vraies, lesquelles sont exécutées ?**

**3. Quelle est la différence entre `=` et `==` ?**

**4. Que vaut l'expression `5 > 3` ? Et `5 == 3` ?**

**5. Le bloc de `if (7 / 9)` est-il exécuté ? Pourquoi ?**

**6. Écrire une condition qui est vraie si `x` est compris entre 10 et 20 (inclus).**

**7. Que faut-il inclure pour utiliser le type `bool` ? Quelles valeurs peut-il prendre ?**


# 23.09 - Variables et types

Une **déclaration** demande un **type** et un **nom** : `int compteur;`

On **initialise** la variable avec `=`. Sans initialisation, sa valeur est **inconnue**.

```c
int compteur;        // valeur inconnue
double force = 1.2e3; // déclaration + initialisation
```

## Les types de base

| Type | Taille | Contenu | `printf` |
|---|---|---|---|
| `int` | 32 bits signés | entier | `%d` |
| `double` | 64 bits | nombre à virgule | `%lf` |
| `char` | 8 bits signés | caractère (= un entier, code ASCII) | `%c` ou `%d` |

> [!NOTE]
> Un `char` s'écrit avec des guillemets **simples** : `'A'` et non `"A"`.

## Dépassement de capacité

Si le résultat ne tient pas dans le type, les bits en trop sont perdus et la valeur
obtenue est fausse — souvent négative, car le bit de poids fort devient le bit de signe.

```c
char c = 100;
printf("%d\n", (char)(2 * c)); // affiche -56 et non 200
```

Un `char` signé ne va que de -128 à 127. Voir [variable.c](variable.c) pour les exemples complets.

---

## Les nombres et les bases
- nombre : https://heig-tin-info.github.io/handout/content/datatype.html#les-nombres-reels
- binaire : https://heig-tin-info.github.io/handout/content/numeration.html#systeme-binaire
- hexadécimal : https://heig-tin-info.github.io/handout/content/numeration.html#systeme-hexadecimal
- complement à 2 : https://heig-tin-info.github.io/handout/content/numeration.html#complement-a-deux

- ASCII : https://heig-tin-info.github.io/handout/content/ascii.html


## Questions

**1. Que faut-il indiquer pour déclarer une variable ?**

**2. Que vaut une variable déclarée mais non initialisée ?**

**3. Quels sont les trois types de base vus au cours, et combien de bits occupent-ils ?**

**4. Quel format `printf` utilise-t-on pour un `int`, un `double`, un `char` ?**

**5. Quelle est la différence entre `'A'` et `"A"` ?**

**6. Que vaut `'g' - 'a' + 1` ? Pourquoi peut-on faire des calculs avec des `char` ?**

**7. Un `char` vaut 120. Que donne `2 * 120` stocké dans un `char` ? Expliquer le résultat.**

**8. Quelle est la plage de valeurs d'un `char` signé ?**


# 22.09 - Numération

Dans l'ordinateur, tout est stocké sous forme de bits. Une même suite de bits peut représenter des valeurs différentes selon la façon dont on l'interprète. Pour savoir comment une valeur est stockée, il faut connaître :

- le **nombre de bits** utilisés (8, 16, 32, 64…) ;
- si la valeur est **signée** ou **non signée**.

> [!NOTE]
> Par exemple, `1111 1111` sur 8 bits vaut **255** en non signé, mais **-1** en signé.

## Complément à 2

Pour représenter les nombres négatifs, on utilise le **complément à 2**. Pour passer d'un nombre positif à son opposé (et inversement) :

1. inverser tous les bits (complément à 1) ;
2. ajouter 1.

Exemple sur 8 bits : `5` = `0000 0101` → inversion `1111 1010` → +1 → `1111 1011` = `-5`.

Sur *n* bits signés, le bit de poids fort indique le signe : `0` pour positif, `1` pour négatif. La plage représentable va de -2^(n-1) à 2^(n-1) - 1.

## À retenir

Vous devez savoir :

- changer de base entre le binaire (2), le décimal (10) et l'hexadécimal (16) ;
- interpréter un nombre binaire, signé ou non signé, en connaissant le nombre de bits ;
- additionner et soustraire deux nombres binaires.

---

## Questions

**1. Convertir 37 en binaire, puis en hexadécimal.**

**2. Convertir `0x2F` en base 10, puis en binaire.**

**3. Donner la valeur en base 10 de `1101` sachant que le nombre est codé sur 4 bits non signés. Même question si le nombre est codé sur 4 bits signés.**

**4. Qu'est-ce que le complément à 2 ? Comment obtient-on l'opposé d'un nombre binaire ?**

**5. Représenter -5 sur 8 bits en complément à 2.**

**6. Quelle est la plage de valeurs représentables sur 8 bits non signés ? Sur 8 bits signés ?**

**7. Calculer `0101 + 0011` en binaire sur 4 bits. Quel est le résultat en base 10 ?**

**8. Calculer `0110 - 0011` en binaire sur 4 bits en utilisant le complément à 2.**

**9. Que se passe-t-il si l'on additionne `1000` et `1000` sur 4 bits non signés ? Comment s'appelle ce phénomène ?**

**10. Pourquoi est-il indispensable de connaître le nombre de bits et le caractère signé ou non signé pour interpréter une valeur stockée en mémoire ?**

# 17.09 - Git et Workflow labo
Git est un outil qui **garde l'historique** du code. Il permet de revenir en arrière, de voir ce qui a changé et de partager le travail.

- **Dépôt (repository, « repo »)** : un dossier de projet suivi par Git.
- **Dépôt distant** : la copie du repo sur un serveur (GitHub, GitLab…).
- **Dépôt local** : une copie du repo sur l'ordinateur.
- **Commit** : une « photo » du projet à un moment donné.

## Les commandes essentielles

| Commande | À quoi ça sert |
|---|---|
| `git clone <url>` | Copier un dépôt distant sur l'ordinateur (une seule fois, au début) |
| `git status` | Voir l'état des fichiers : modifiés, sélectionnés pour le commit, non suivis |
| `git add <fichier>` | Sélectionner un fichier pour le prochain commit (`git add .` = tous les fichiers modifiés) |
| `git commit -m "message"` | Enregistrer les fichiers sélectionnés dans l'historique **local** |
| `git push` | Envoyer les commits locaux vers le dépôt distant |
| `git pull` | Récupérer les nouveautés du dépôt distant sur l'ordinateur |
| `git log` | Afficher l'historique des commits |

> [!WARNING]
> Un `commit` reste **sur l'ordinateur**. Tant que la commande `git push` n'as pas été faite, rien n'est envoyé sur le serveur.

## Le flux de travail pour les labos

```bash
git clone <url-du-repo>
cd <nom-du-repo>

(git add .)
git commit -am "Ajout de la fonction moyenne()"

git push
```

```mermaid
flowchart LR
    A[Dépôt distant<br/>GitHub] -- git clone / git pull --> B[Dépôt local<br/>ton PC]
    B -- git add --> C[Fichiers sélectionnés]
    C -- git commit --> D[Historique local]
    D -- git push --> A
```

### Bonnes pratiques

- Faire des commits **petits et fréquents**, pas un seul gros commit à la fin.
- Écrire des messages **clairs** : `Correction du calcul de la moyenne` plutôt que `modif` ou `truc`.
- Toujours faire `git push` avant de quitter la salle de labo.

---

## Questions

**1. Qu'est-ce qu'un dépôt (repository) Git ?**

**2. Comment récupère-t-on un dépôt qui se trouve sur GitHub ?**

**3. Que fait la commande `git add .` ?**

**4. Qu'est-ce qu'un commit ?**

**5. J'ai fait un commit. Est-ce que l'on peut voir mon travail sur GitHub ? Pourquoi ?**

**6. Quelle est la différence entre `git push` et `git pull` ?**

**7. Comment savoir quels fichiers ont été modifiés depuis le dernier commit ?**

**9. J'ai travaillé sur le labo à la maison et fait un `push`. De retour à l'école, que dois-je faire avant de continuer ?**


# 16.09 - Introduction au cours
- Comme outils, on utilisera : 
  - Cyberlearn : https://cyberlearn.hes-so.ch/course/view.php?id=26109
  - GitHub : https://github.com/Info1-MI-2026
  - Teams : r1oyk10

### Les commandes de bases sous Linux
- `ls -la` : liste les fichiers et dossiers dans le répertoire courant
- `cd` : change de répertoire
- `pwd` : affiche le chemin du répertoire courant
- `mkdir` : crée un nouveau répertoire
- `cd ..` : remonte d'un niveau dans l'arborescence
- `rm` : supprime un fichier

Labo 0 - Installation :
https://cyberlearn.hes-so.ch/mod/resource/view.php?id=2076886

### Questions 
```bash
~
├── documents
└── info
    └── demo
        └── main.c
```

1) Quelle commande affiche la liste des fichiers d'un répertoire ? Quelle est la différence avec `ls -la` ?

2) Depuis le répertoire `~`, quelles commandes permettent d'accéder au répertoire `info`, puis de revenir au répertoire parent ?

3) Comment créer un répertoire nommé `tp1` ?

4) Qu'est-ce que la compilation, et pourquoi est-il nécessaire de compiler un programme C ?

5) Dans la commande `gcc main.c -o app`, que représente `app` ?

6) Qu'est-ce que WSL ? Que fait la commande `code .` ?

7) Depuis le répertoire `~`, sachant qu'un fichier `main.c` se trouve dans `~/info/demo/`, quelles commandes permettent de compiler puis d'exécuter le programme ?

