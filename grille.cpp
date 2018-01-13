/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo05
 Fichier     : grille.cpp
 Auteur(s)   : Hugo Jeanneret, Julien Quartier
 Date        : 08.01.2018
 But         :

 Remarque(s) :

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */


#include <iostream>
#include "grille.h"

using namespace std;


void initialisationGrille(vector<vector<bool>> &grilleJeu, const vector<string> &motif, int motifX, int motifY,
                          char carVivant) {

   for (size_t i = 0; i < motif.size(); i++) {
      for (size_t j = 0; j < motif[i].length(); j++) {
         grilleJeu[i + motifY][j + motifX] = motif[i][j] == carVivant;
      }
   }
}

void afficherGrille(const vector<vector<bool>> &grilleJeu, char carVivant, char carMort) {

   string ecran = "";

   size_t col, ligne;

   if ((ligne = grilleJeu.size()) != 0 && (col = grilleJeu[0].size()) != 0) {

      for (size_t i = 0; i < ligne; i++) {
         for (size_t j = 0; j < col; j++) {
            ecran += string(1, grilleJeu[i][j] ? carVivant : carMort) + " ";
         }
         ecran += "\n\r";
      }

      cout << ecran << endl;
   }
}
