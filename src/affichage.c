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
 * @brief Produit le graphe en format DIMACS.
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