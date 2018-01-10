/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : jeu.h
 Auteur(s)   : Julien
 Date        : 10.01.2018

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 7.1.0
 -----------------------------------------------------------------------------------
*/


#ifndef JEU_DE_LA_VIE_JEU_H
#define JEU_DE_LA_VIE_JEU_H

    #include <cstdlib>
    #include <vector>

    //Doit être impaire
    const size_t ZONE_INFLUANCE = 3;

    void evolution(const std::vector<std::vector<bool>> &grilleJeu, std::vector<std::vector<bool>> &anticipation);
    bool estVivant(const std::vector<std::vector<bool>> &grilleJeu, size_t posx, size_t posy );

#endif //JEU_DE_LA_VIE_JEU_H
