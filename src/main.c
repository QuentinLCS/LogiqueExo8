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
    if (argc >= 5 && argc % 2 != 0) {

        int j = 0;
        int nbSommets = atoi(argv[1]);
        int nbAretes = atoi(argv[2]);
        ARETE aretes[nbAretes];

        for (int i = 4; i < argc; i+=2)
        {
            aretes[j].premierSommet.id = atoi(argv[i]);
            aretes[j++].secondSommet.id = atoi(argv[i+1]);
        }
        
        afficherAretes(nbAretes, 2, aretes);


    } else
        fprintf(stderr, "--------------------------\nNombre d'arguments insuffisants. \nERREUR : Minimum 5 et le nombre de paramètres doit être pair)\n--------------------------\n");
    
    return 0;
}
