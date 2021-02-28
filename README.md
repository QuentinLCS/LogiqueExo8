# LogiqueExo8

## Exercice réalisé dans le cadre d'un cours de Logique en 2nd Semestre à l'ENSIIE ! Cf. fin du README pour lire le sujet.

[<img src="https://www.ensiie.fr/wp-content/uploads/2018/04/ENSIIE01.png" alt="drawing" width="100"/>](https://www.ensiie.fr/)



## Utilisation

> Le programme a été conçu sous **Ubuntu 20.04.1 LTS**. 

1. Clonez le dépot en local.
2. Entrez dans le dossier cloné.
3. Exécutez le fichier nommé "`executableExo8`" dans votre console de la manière suivante :

``` 

./executableExo8 nbSommets nbAretes [nbAretes * 2 sommets]


Exemple : ./executableExo8 4 5 1 2 2 3 3 4 1 3 2 4

```

4. Félicitations, vous devriez voir apparaitre dans votre console les résultats souhaités sous cette forme : 

``` 

------------------  ARETES LUES  ------------------

[1] >> 1 ---- 2
[2] >> 2 ---- 3
[3] >> 3 ---- 4
[4] >> 1 ---- 3
[5] >> 2 ---- 4


-----------------  DIMACS FORMAT  -----------------

p cnf 12 31
3 2 1 0
-3 -2 0
-3 -1 0
-2 -1 0
6 5 4 0
-6 -5 0
-6 -4 0
-5 -4 0
9 8 7 0
-9 -8 0
-9 -7 0
-8 -7 0
12 11 10 0
-12 -11 0
-12 -10 0
-11 -10 0
-1 -4 0
-2 -5 0
-3 -6 0
-4 -7 0
-5 -8 0
-6 -9 0
-7 -10 0
-8 -11 0
-9 -12 0
-1 -7 0
-2 -8 0
-3 -9 0
-4 -10 0
-5 -11 0
-6 -12 0


--------------  COLORATION POSSIBLE  --------------

(1) : R
(2) : V
(3) : B
(4) : R
SAT - LE GRAPHE EST COLORIABLE EN 3 COULEURS !

```

# Annexe

## Le sujet
[<img src="https://i.gyazo.com/d23906eeac8d44f810e0b9204b7291cc.png" alt="drawing"/>](https://i.gyazo.com/d23906eeac8d44f810e0b9204b7291cc.png)