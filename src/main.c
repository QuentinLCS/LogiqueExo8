/**
 * @file main.c
 * @author Quentin LECHASLES (contact@quentinlcs.fr)
 * @brief LogiqueExo8, répond aux questions.
 * @version 0.1
 * @date 2021-02-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include "../include/struct.h"
#include "../include/affichage.h"

/**
 * @brief Fonction principale du programme.
 * 
 * @param argc Nombre d'arguments de la commande.
 * @param argv Arguments de la commande.
 * @return int Code d'erreur.
 */
int main(int argc, char const *argv[])
{

    if (argc >= 5 && ( argc % 2 != 0 )) {

        int nbSommets = atoi(argv[1]);
        int nbAretes = atoi(argv[2]);
        
        if ( ( (argc-3) / 2 ) == nbAretes ) {

            int j = 0;
            ARETE aretes[nbAretes];

            for (int i = 0; i < nbAretes; i++)
            {

                j = 3 + i*2;
                aretes[i].premierSommet.id = atoi(argv[j]);
                aretes[i].secondSommet.id = atoi(argv[j+1]);
            
            }
            
            afficherAretes(nbAretes, aretes);
        } else {
            erreurFonctionnelle(2);
        }

    } else
        erreurFonctionnelle(1);
    
    return 0;
}
