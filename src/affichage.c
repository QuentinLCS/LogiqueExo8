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
#include <stdlib.h>
#include <string.h>
#include "../include/struct.h"
#include "../include/coloriage.h"


/**
 * @brief Affiche un tableau d'ARETES.
 * 
 * @param size Taille de la première dimension du tableau
 * @param tableau tableau à afficher.
 */
void afficherAretes(int size, ARETE* tableau) {

    for (int i = 0; i < size; i++)
    {
    
        printf("[%d] >> %d ---- %d\n", i+1, tableau[i].premierSommet.id, tableau[i].secondSommet.id);
        
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
    
    for (int save = 0; save < 2; save++) {

        char resultat[10000] = "";
        char tempString[200] = "";
        int nbVariables = nbSommets * 3;
        int nbClauses = nbSommets + nbSommets * 3 + nbAretes * 3;
        sprintf(resultat, "p cnf %d %d\n", nbVariables, nbClauses);
        
        if (save) {

            sprintf(tempString, "a 0\ne ");
            strcat(resultat, tempString);

            for (int i = 1; i <= nbSommets*3; i++) {
                sprintf(tempString, "%d ", i);
                strcat(resultat, tempString);
            }

            sprintf(tempString, "0\n");
            strcat(resultat, tempString);

        }
        

        for (int i = 1; i <= nbSommets; i++)
        {
            int Si = i * 3;
            // 1) Chaque sommet i = 1, . . . n prend au moins une couleur.
            sprintf(tempString, "%d %d %d 0\n", Si, Si-1, Si-2);
            strcat(resultat, tempString);


            // 2) Chaque sommet i = 1, . . . prend au plus une couleur 
            // (si le sommet est en vert alors il n’est pas en rouge, etc).
            sprintf(tempString, "%d %d 0\n", -Si, -Si+1);
            strcat(resultat, tempString);

            sprintf(tempString, "%d %d 0\n", -Si, -Si+2);
            strcat(resultat, tempString);

            sprintf(tempString, "%d %d 0\n", -Si+1, -Si+2);
            strcat(resultat, tempString);
            
        }

        for (int i = 0; i < nbAretes; i++) {

            for (int j = 1; j <= 3; j++) {

                // Les deux sommets d’une arˆete (Si, Sj) ne prennent pas la même
                // couleur c pour 1 ≤ i < j ≤ n, pour c ∈ {v,r, b}.
                sprintf(tempString, "%d %d 0\n", -((tableau[i].premierSommet.id-1)*3 + j), -((tableau[i].secondSommet.id-1)*3 + j));
                strcat(resultat, tempString);

            }
                
        }

        if (save) sauvegarderDansUnFichier(resultat);
        else printf("%s", resultat);
    }
    

    printf("\n----------------------  FIN  ----------------------\n\n");

}

/**
 * @brief Affiche les erreurs en fonction de l'entier donné en paramètre.
 * 
 * @param valeur Code d'erreur. ( 1 ou 2 )
 */ 
void erreurFonctionnelle(int valeur) {

    char erreur[1000] = "\n--------------------------\n";

    switch (valeur)
    {
    case 1:
        strcat(erreur, "Nombre d'arguments insuffisant. \nERREUR : Minimum 5 et le nombre de paramètres doit être pair.");
        break;

    case 2:
        strcat(erreur, "Nombre d'arguments incohérent. \nERREUR : les 2 extrêmités des aretes doivent être renseignées.");
        break;

    case 3:
        strcat(erreur, "Sauvegarde du résultat impossible. \nERREUR : Vérifiez que le dossier \"./saves\" dispose des droits requis à l'écriture ainsi qu'à la lecture d'un fichier format DIMACS.");
        break;

    case 4:
        strcat(erreur, "Execution du solver impossible. \nERREUR : vérifiez que vous disposez du dossier solver et que ses droits sont suffisants afin que le programme puisse utiliser un executable.");
        break;

    case 5:
        break;

    default:
        strcat(erreur, "Lecture du solver impossible. \nERREUR : Vérifiez que le fichier .\"/solver/result.aig\" existe et que les droits requis sont définis.");
        break;
    }

    strcat(erreur, "\n--------------------------\n");
    
    fprintf(stderr, "%s", erreur);

}

