/**
 * @file struct.h
 * @author Quentin LECHASLES (contact@quentinlcs.fr)
 * @brief Header contenant les structures nécessaires au programme.
 * @version 0.1
 * @date 2021-02-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#if !defined(STRUCT_H)
#define STRUCT_H

    typedef enum 
    {
        JAUNE =  'J',
        BLEU = 'J',
        VERT = 'V',
        ROUGE = 'R'
    } COULEUR;

    typedef struct 
    {
        int id;
        COULEUR couleur;
    } SOMMET;

    typedef struct 
    {
        SOMMET premierSommet;
        SOMMET secondSommet;
    } ARETE;

#endif // STRUCT_H