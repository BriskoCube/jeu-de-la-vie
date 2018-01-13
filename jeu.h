/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo05
 Fichier     : jeu.h
 Auteur(s)   : Hugo Jeanneret, Julien Quartier
 Date        : 08.01.2018
 But         :

 Remarque(s) :

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */


#ifndef JEU_DE_LA_VIE_JEU_H
#define JEU_DE_LA_VIE_JEU_H

#include <cstdlib>
#include <vector>

void evolution(const std::vector<std::vector<bool>> &grilleJeu, std::vector<std::vector<bool>> &anticipation);

bool estVivant(const std::vector<std::vector<bool>> &grilleJeu, size_t posx, size_t posy);

/**
 * \brief Vérifie si une valeur est compris dans un interval de deux valeurs.
 * \param value Valeur à tester
 * \param interval Interval 0: min(compris), 1: max(compris)
 * \return Si la valeur est comprise ou non dans l'interval
 */
bool estDansInterval(unsigned value, const int interval[2]);

#endif //JEU_DE_LA_VIE_JEU_H
