/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : grille.cpp
 Auteur(s)   : Julien
 Date        : 10.01.2018

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 7.1.0
 -----------------------------------------------------------------------------------
*/


#include <iostream>
#include "grille.h"

using namespace std;



void initialisationGrilleJeu(vector<vector<bool>>& grilleJeu, const vector<string>& motif, int motifX, int motifY){
    for(size_t i = 0; i < motif.size(); i++){
        for(size_t j = 0; j < motif[i].length(); j++){
            grilleJeu[i + motifY][j + motifX] = motif[i][j] == CAR_EN_VIE;
        }
    }
}

void afficherGrilleJeu(const vector<vector<bool>>& grilleJeu){

    string ecran = "";

    size_t col, ligne;

    if((ligne = grilleJeu.size()) != 0 && (col = grilleJeu[0].size()) != 0){

        for(size_t i = 0; i < ligne; i++){
            for(size_t j = 0; j < col; j++){
                ecran += string(1, grilleJeu[i][j] ? CAR_EN_VIE : CAR_MORT) + " ";
            }
            ecran += "\n\r";
        }

        cout << ecran << endl;
    }
}
