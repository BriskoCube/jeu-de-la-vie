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

using namespace std;


const size_t NB_COLL = 11;
const size_t NB_LIGNES = 10;

const unsigned ITERATION = 8;

const char CAR_EN_VIE = 'X';
const char CAR_MORT = '.';

//Doit être impaire
const size_t ZONE_INFLUANCE = 3;

const size_t MOTIF_X = 4;
const size_t MOTIF_Y = 4;

//forme à insérer
vector<string> MOTIF_PAR_DEFAULT {
    ".x.",
    "..x",
    "xxx"
};



//void evolution(vector<vector<bool>> grilleJeu, const vector<vector<bool>> &anticipation);


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




/*void nombreVoisin(const vector<vector<bool>> &grilleJeu, vector<vector<int>> &){

    string ecran = "";

    size_t col, ligne;


    if((ligne = grilleJeu.size()) != 0 && (col = grilleJeu[0].size()) != 0){

        for(size_t i = 0; i < ligne; i++){
            for(size_t j = 0; j < col; j++){
            }
        }
    }

}*/