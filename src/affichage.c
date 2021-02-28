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
 * @param sizeA Taille de la première dimension du tableau
 * @param tableau tableau à afficher.
 */
void afficherAretes(int size, ARETE* tableau) {

    for (int i = 0; i < size; i++)
    {
    
        printf("[%d] >> %d (%c) ---- %d (%c)", size, tableau[i].premierSommet.id, tableau[i].premierSommet.couleur, tableau[i].secondSommet.id, tableau[i].premierSommet.couleur);
        
    }
    
}