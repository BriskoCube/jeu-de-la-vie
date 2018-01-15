/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo04
 Fichier     : main.cpp
 Auteur(s)   : Hugo Jeanneret, Julien Quartier
 Date        : 08.01.2018
 But         :

 Remarque(s) :

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


const size_t NB_COLL = 11;
const size_t NB_LIGNES = 10;

const unsigned ITERATION = 8;



const size_t MOTIF_X = 4;
const size_t MOTIF_Y = 4;

//forme à insérer
vector<string> MOTIF_PAR_DEFAULT {
    ".x.",
    "..x",
    "xxx"
};


int main() {

    // False : vide, True : vie
    vector<vector<bool>> grilleJeu(NB_LIGNES, vector<bool>(NB_COLL, false));
    vector<vector<bool>> anticipation(NB_LIGNES, vector<bool>(NB_COLL));
    
    initialisationGrilleJeu(grilleJeu, MOTIF_PAR_DEFAULT, MOTIF_X, MOTIF_Y);

    afficherGrilleJeu(grilleJeu);

    for(int i = 0; i <= ITERATION; ++i){

      evolution(grilleJeu, anticipation);
      grilleJeu = anticipation;
      afficherGrilleJeu(grilleJeu);
    
    }

    return EXIT_SUCCESS;
}