/**
 * @file affichage.h
 * @author Quentin LECHASLES (contact@quentinlcs.fr)
 * @brief Header contenant les fonctions d'affichages.
 * @version 0.1
 * @date 2021-02-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "struct.h"

#if !defined(AFFICHAGE_H)
#define AFFICHAGE_H

    void afficherAretes(int , ARETE* );

    void afficherAretesDimacs(int , ARETE* );

    void erreurFonctionnelle(int);

#endif // AFFICHAGE_H