/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo05
 Fichier     : grille.h
 Auteur(s)   : Hugo Jeanneret, Julien Quartier
 Date        : 08.01.2018
 But         : Gestion de la grille totale avec l'affichage et l'initalisation

 Remarque(s) :

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */



#ifndef JEU_DE_LA_VIE_GRILLE_H
#define JEU_DE_LA_VIE_GRILLE_H

#include <vector>

#include <string>


/**
 * \brief Inintialise la grille avec un motif.
 * \param grilleJeu Grille à initialiser
 * \param motif Motif à insérer
 * \param motifX Position en x du coin en haut à gauche
 * \param motifY Position en y du coin en haut à gauche
 */
void initialisationGrille(std::vector<std::vector<bool>> &grilleJeu, const std::vector<std::string> &motif,
                          int motifX, int motifY, char carVivant);

/**
 * \brief Affiche la grille de jeu passé en paramètre
 * \param grilleJeu Grille à 2 dimentions qui va être affichée dans la console
 * \param carVivant Caractère à afficher pour une cellule vivante
 * \param carMort Caractère à afficher pour une cellule morte
 */
void afficherGrille(const std::vector<std::vector<bool>> &grilleJeu, char carVivant, char carMort);

#endif //JEU_DE_LA_VIE_GRILLE_H
