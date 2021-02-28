/**
 * @file affichage.c
 * @author Quentin LECHASLES (contact@quentinlcs.fr)
 * @brief Fichier contenant toutes les fonctions liées à l'affichage de données.
 * @version 0.1
 * @date 2021-02-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include "../include/struct.h"

/**
 * @brief Affiche un tableau d'ARETES.
 * 
 * @param size Taille de la première dimension du tableau
 * @param tableau tableau à afficher.
 */
void afficherAretes(int size, ARETE* tableau) {

    for (int i = 0; i < size; i++)
    {
    
        printf("[%d] >> (%c) %d ---- %d (%c)\n", i+1, tableau[i].premierSommet.couleur, tableau[i].premierSommet.id, tableau[i].secondSommet.id, tableau[i].premierSommet.couleur);
        
    }
    
}


/**
 * @brief Affiche le code format DIMACS du graphe.
 * 
 * @param nbSommets Nombre de sommets du graphe.
 * @param nbAretes Nombre d'aretes du graphe.
 * @param tableau Tableau d'aretes du graphe.
 */
void afficherAretesDimacs(int nbSommets, int nbAretes, ARETE* tableau) {

    printf("\n\n-----------------  DIMACS FORMAT  -----------------\n\n");
    
    int nbVariables = nbSommets * 3;
    int nbClauses = nbSommets + nbSommets * 3 + nbAretes * 3;
    printf("p cnf %d %d\n", nbVariables, nbClauses);
    
    for (int i = 1; i <= nbSommets; i++)
    {
    
        int Si = i * 3;
        // 1) Chaque sommet i = 1, . . . n prend au moins une couleur.
        printf("%d %d %d 0\n", Si, Si-1, Si-2);

        // 2) Chaque sommet i = 1, . . . prend au plus une couleur 
        // (si le sommet est en vert alors il n’est pas en rouge, etc).
        printf("%d %d 0\n", -Si, -Si+1);
        printf("%d %d 0\n", -Si, -Si+2);
        printf("%d %d 0\n", -Si+1, -Si+2);
        
    }

    for (int i = 0; i < nbAretes; i++) {

        for (int j = 1; j <= 3; j++) {

            // Les deux sommets d’une arˆete (Si, Sj) ne prennent pas la même
            // couleur c pour 1 ≤ i < j ≤ n, pour c ∈ {v,r, b}.
            printf("%d %d 0\n", -((tableau[i].premierSommet.id-1)*3 + j), -((tableau[i].secondSommet.id-1)*3 + j));

        }
            
    }

    printf("\n----------------------  FIN  ----------------------\n\n");
    
}

void erreurFonctionnelle(int valeur) {

    fprintf(stderr, "\n--------------------------\n");

    switch (valeur)
    {
    case 1:
        fprintf(stderr, "Nombre d'arguments insuffisant. \nERREUR : Minimum 5 et le nombre de paramètres doit être pair.");
        break;

    case 2:
        fprintf(stderr, "Nombre d'arguments incohérent. \nERREUR : les 2 extrêmités des aretes doivent être renseignées.");
        break;
    
    default:
        break;
    }

    fprintf(stderr, "\n--------------------------\n");

}