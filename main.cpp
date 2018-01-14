/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo05
 Fichier     : main.cpp
 Auteur(s)   : Hugo Jeanneret, Julien Quartier
 Date        : 08.01.2018
 But         : Simulation du jeu de la vie de John Horton. La simulation est réalisée pour un nombre donné d'essais
               avec une position initiale donnée.

 Remarque(s) : Aucune saisie possible par l'utilisateur. Toute la fonfiguration est effectuée dans le code

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */


#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

#include "jeu.h"
#include "grille.h"

using namespace std;

// Taille de la grille
const size_t NB_COLL = 11;
const size_t NB_LIGNES = 10;

// Nombre d'itérations à effectuer
const unsigned ITERATION = 8;

// Caractères à afficher dans la console pour une case de la grille
const char CAR_VIVANT = 'x';
const char CAR_MORT = '.';


// Position du coin supérieur gauche du motif
const size_t MOTIF_X = 4;
const size_t MOTIF_Y = 4;

// Forme à insérer
const vector<string> MOTIF_PAR_DEFAULT{
        ".x.",
        "..x",
        "xxx"
};


int main() {

   // False : vide, True : vie
   vector<vector<bool>> grilleJeu(NB_LIGNES, vector<bool>(NB_COLL, false));
   vector<vector<bool>> anticipation(NB_LIGNES, vector<bool>(NB_COLL));

   initialisationGrille(grilleJeu, MOTIF_PAR_DEFAULT, MOTIF_X, MOTIF_Y, CAR_VIVANT);

   afficherGrille(grilleJeu, CAR_VIVANT, CAR_MORT);

   for (int i = 0; i <= ITERATION; ++i) {

      evolution(grilleJeu, anticipation);
      grilleJeu = anticipation;
      afficherGrille(grilleJeu, CAR_VIVANT, CAR_MORT);

   }

   system("PAUSE");

   return EXIT_SUCCESS;
}