/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : grille.h
 Auteur(s)   : Julien
 Date        : 10.01.2018

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 7.1.0
 -----------------------------------------------------------------------------------
*/


#ifndef JEU_DE_LA_VIE_GRILLE_H
#define JEU_DE_LA_VIE_GRILLE_H

#include <vector>

#include <string>

void initialisationGrilleJeu(std::vector<std::vector<bool>>& grilleJeu, const std::vector<std::string>& motif, int motifX, int motifY);
void afficherGrilleJeu(const std::vector<std::vector<bool>> &grilleJeu);

#endif //JEU_DE_LA_VIE_GRILLE_H
