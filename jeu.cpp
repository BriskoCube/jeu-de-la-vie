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

const int INTERVAL_NAISSANCE[] = {3, 3};


void evolution(const vector<vector<bool>> &grilleJeu, vector<vector<bool>> &anticipation) {

   for (size_t i = 0; i < grilleJeu.size(); i++) {
      for (size_t j = 0; j < grilleJeu[0].size(); j++) {
         anticipation[i][j] = estVivant(grilleJeu, j, i);
      }
   }
}


bool estVivant(const vector<vector<bool>> &grilleJeu, size_t posx, size_t posy) {

   bool estVivant = grilleJeu[posy][posx];

   unsigned nbVoisins = nombreVoisins(grilleJeu, posx, posy, ZONE_INFLUANCE);


   if (estVivant && estDansInterval(nbVoisins, INTERVAL_SURVIT)) {
      return true;
   } else if (!estVivant && estDansInterval(nbVoisins, INTERVAL_NAISSANCE)) {
      return true;
   }

   return false;

}

bool estDansInterval(unsigned value, const int interval[2]) {
   return value >= interval[0] && value <= interval[1];
}

unsigned nombreVoisins(const std::vector<std::vector<bool>> &grilleJeu, size_t posx, size_t posy, int zoneInfluance){

   unsigned cpt = 0;

   for (int i = -zoneInfluance; i <= zoneInfluance; i++) {
      for (int j = -zoneInfluance; j <= zoneInfluance; j++) {
         if ((i != 0 || j != 0)
             && posy + i >= 0 && posx + j >= 0
             && posy + i < grilleJeu.size() && posx + j < grilleJeu[0].size()
             && grilleJeu[posy + i][posx + j]) {
            cpt++;
         }
      }
   }

   return cpt;
}