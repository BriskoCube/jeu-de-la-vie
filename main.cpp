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

void initialisationGrilleJeu(vector<vector<bool>> &grilleJeu);
void afficherGrilleJeu(const vector<vector<bool>> &grilleJeu);
void nombreVoisin(const vector<vector<bool>> &grilleJeu, vector<vector<int>> &voisins);


int main() {

    // False : vide, True : vie
    vector<vector<bool>> grilleJeu(NB_LIGNES, vector<bool>(NB_COLL, false));

    initialisationGrilleJeu(grilleJeu);



    afficherGrilleJeu(grilleJeu);



    return EXIT_SUCCESS;
}

void initialisationGrilleJeu(vector<vector<bool>>& grilleJeu){

    grilleJeu[4][4] = true;
    grilleJeu[4][5] = true;
    grilleJeu[4][6] = true;
    grilleJeu[5][5] = true;

}

void afficherGrilleJeu(const vector<vector<bool>>& grilleJeu){

    string ecran = "";

    size_t col, ligne;

    if((ligne = grilleJeu.size()) != 0 && (col = grilleJeu[0].size()) != 0){

        for(size_t i = 0; i < ligne; i++){
            for(size_t j = 0; j < col; j++){
                ecran += (grilleJeu[i][j] ? "x " : ". ");
            }
            ecran += "\n\r";
        }

        cout << ecran << endl;
    }
}

void nombreVoisin(const vector<vector<bool>> &grilleJeu, vector<vector<int>> &voisins){

    string ecran = "";

    size_t col, ligne;


    if((ligne = grilleJeu.size()) != 0 && (col = grilleJeu[0].size()) != 0){

        for(size_t i = 0; i < ligne; i++){
            for(size_t j = 0; j < col; j++){
            }
        }
    }

}