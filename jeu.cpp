/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : jeu.cpp
 Auteur(s)   : Julien
 Date        : 10.01.2018

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ 7.1.0
 -----------------------------------------------------------------------------------
*/


#include "jeu.h"

using namespace std;

void evolution(const vector<vector<bool>> &grilleJeu, vector<vector<bool>> &anticipation) {

    for(size_t i = 0; i < grilleJeu.size(); i++){
        for(size_t j = 0; j < grilleJeu[0].size(); j++){
            anticipation[i][j] = estVivant(grilleJeu, j, i);
        }
    }
}



bool estVivant(const vector<vector<bool>> &grilleJeu, size_t posx, size_t posy ){

    unsigned cpt = 0;

    bool estVivant = grilleJeu[posy][posx];

    int domaineDef = ZONE_INFLUANCE / 2;

    for(int i = -domaineDef; i <= domaineDef; i++){
        for(int j = -domaineDef; j <= domaineDef; j++){

            if((i != 0 || j != 0)
               && posy + i >=0 && posx + j >= 0
               && posy + i < NB_LIGNES && posx + j < NB_COLL
               && grilleJeu[posy + i][posx + j]){
                cpt++;
            }

        }
    }


    if(estVivant && (cpt == 2 || cpt == 3)){
        return true;
    }
    else if(!estVivant && cpt == 3){
        return true;
    }

    return false;

}
