/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo05
 Fichier     : jeu.h
 Auteur(s)   : Hugo Jeanneret, Julien Quartier
 Date        : 08.01.2018
 But         : Fonctions permettant de la faire évoluer les états du jeu. Analyse de chaques cases indépendamment

 Remarque(s) :

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */


#ifndef JEU_DE_LA_VIE_JEU_H
#define JEU_DE_LA_VIE_JEU_H

#include <cstdlib>
#include <vector>

/**
 * \brief Calcule l'état suivant de la grille
 * \param grilleJeu Grille de l'état actuel
 * \param anticipation Etat suivant
 */
void evolution(const std::vector<std::vector<bool>> &grilleJeu, std::vector<std::vector<bool>> &anticipation);

/**
 * \brief Si la cellule en x,y, est vivante au prochain état
 * \param grilleJeu Grille du jeu a analyser
 * \param posx Posision horitontale de la case à analyser
 * \param posy Posision verticale de la case à analyser
 * \return
 */
bool estVivant(const std::vector<std::vector<bool>> &grilleJeu, size_t posx, size_t posy);

/**
 * \brief Vérifie si une valeur est compris dans un interval de deux valeurs.
 * \param value Valeur à tester
 * \param interval Interval 0: min(compris), 1: max(compris)
 * \return Si la valeur est comprise ou non dans l'interval
 */
bool estDansInterval(unsigned value, const int interval[2]);

/**
 * \brief Compte le nombre de voisins dans la zone d'influance. Normalement une case
 * \param grilleJeu Grille du jeu
 * \param posx Posision horitontale de la case à analyser
 * \param posy Posision verticale de la case à analyser
 * \param zoneInfluance Rayon de case qui influance la vide de la case
 * \return Nombre de voisins
 */
unsigned nombreVoisins(const std::vector<std::vector<bool>> &grilleJeu, size_t posx, size_t posy, int zoneInfluance);

#endif //JEU_DE_LA_VIE_JEU_H
