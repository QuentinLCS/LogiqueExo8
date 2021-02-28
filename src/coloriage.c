/**
 * @file coloriage.c
 * @author Quentin LECHASLES (contact@quentinlcs.fr)
 * @brief Fonctions permettant de déterminer si un graphe est coloriable en 3 couleurs ou non.
 * @version 0.1
 * @date 2021-02-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/struct.h"
#include "../include/affichage.h"

/**
 * @brief Ecrit la formule DIMACS dans un fichier.
 * 
 * @param chaineDeCaracteres Caractères à écrire dans le fichier de sauvegarde.
 */
void sauvegarderDansUnFichier(char* chaineDeCaracteres) {

    FILE* fichier = NULL;

    fichier = fopen( "./saves/last-save.txt", "r+" );

    system(">./saves/last-save.txt");

    if (fichier != NULL)
    {
        
        fseek(fichier, 0, SEEK_END);

        fprintf(fichier, "%s", chaineDeCaracteres);

        fclose(fichier);
    }
    else
    {
        erreurFonctionnelle(3);
    }
}

/**
 * @brief Execute un code openSource à l'aide des informations précédemment obtenues et donne le coloriage du graphe s'il est possible.
 * 
 */
void colorierLeGraphe(int nbSommets) {

    int curseur = 14, tempInt = 0;
    char couleurs[3] = {ROUGE, VERT, BLEU};

    if (system("./solver/cadet -c ./solver/result.aig ./saves/last-save.txt")) {

        FILE* fichier = NULL;

        fichier = fopen( "./solver/result.aig", "r+" );
        fseek(fichier, curseur, SEEK_SET);

        if (fichier != NULL)
        {
            printf("--------------  COLORATION POSSIBLE  --------------\n\n");
            for (int sommetNum = 1; sommetNum <= nbSommets; sommetNum++) {
                for (int colorNum= 0; colorNum < 3; colorNum++)
                {

                    fscanf(fichier, "%d", &tempInt);

                    if (tempInt) printf("(%d) : %c\n", sommetNum, couleurs[colorNum]);
                    
                }
            }

            fscanf(fichier, "%d", &tempInt);
            if (tempInt) printf("SAT - LE GRAPHE EST COLORIABLE EN 3 COULEURS !");
            else if (tempInt) printf("UNSAT - GRAPHE NON COLORABLE EN 3 COULEURS...");
        
            fclose(fichier);
            
        }
        else {

            erreurFonctionnelle(5);

        }
        

    } else {

        erreurFonctionnelle(4);

    }

    printf("\n\n\n");

}