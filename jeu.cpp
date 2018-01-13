/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo05
 Fichier     : jeu.cpp
 Auteur(s)   : Hugo Jeanneret, Julien Quartier
 Date        : 08.01.2018
 But         :

 Remarque(s) :

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */


#include "jeu.h"
#include "grille.h"

using namespace std;

// Distance depuis la cellule centrale qui l'influance
const int ZONE_INFLUANCE = 1;

const int INTERVAL_SURVIT[] = {2, 3};


void evolution(const vector<vector<bool>> &grilleJeu, vector<vector<bool>> &anticipation) {

   for (size_t i = 0; i < grilleJeu.size(); i++) {
      for (size_t j = 0; j < grilleJeu[0].size(); j++) {
         anticipation[i][j] = estVivant(grilleJeu, j, i);
      }
   }
}


bool estVivant(const vector<vector<bool>> &grilleJeu, size_t posx, size_t posy) {

   unsigned cpt = 0;

   bool estVivant = grilleJeu[posy][posx];

   for (int i = -ZONE_INFLUANCE; i <= ZONE_INFLUANCE; i++) {
      for (int j = -ZONE_INFLUANCE; j <= ZONE_INFLUANCE; j++) {

         if ((i != 0 || j != 0)
             && posy + i >= 0 && posx + j >= 0
             && posy + i < grilleJeu.size() && posx + j < grilleJeu[0].size()
             && grilleJeu[posy + i][posx + j]) {
            cpt++;
         }

      }
   }


   if (estVivant && estDansInterval(cpt, INTERVAL_SURVIT)) {
      return true;
   } else if (!estVivant && cpt == 3) {
      return true;
   }

   return false;

}

bool estDansInterval(unsigned value, const int interval[2]) {
   return value >= interval[0] && value <= interval[1];
}
