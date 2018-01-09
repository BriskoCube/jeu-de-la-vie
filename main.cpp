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
void evolution(const vector<vector<bool>> &grilleJeu, vector<vector<bool>> &anticipation);
bool estVivant(const vector<vector<bool>> &grilleJeu, size_t posx, size_t posy );
//void evolution(vector<vector<bool>> grilleJeu, const vector<vector<bool>> &anticipation);


int main() {

    // False : vide, True : vie
    vector<vector<bool>> grilleJeu(NB_LIGNES, vector<bool>(NB_COLL, false));


    vector<vector<bool>> anticipation(NB_LIGNES, vector<bool>(NB_COLL));
    
    initialisationGrilleJeu(grilleJeu);
    afficherGrilleJeu(grilleJeu);

    
    for(int i = 0; i <= 10; ++i){
       
    
      evolution(grilleJeu, anticipation);
      grilleJeu = anticipation;
      afficherGrilleJeu(grilleJeu);
    
    

    
    
    }



    return EXIT_SUCCESS;
}

void initialisationGrilleJeu(vector<vector<bool>>& grilleJeu){

    grilleJeu[4][4] = true;
    grilleJeu[4][5] = true;
    grilleJeu[4][6] = true;
    grilleJeu[5][5] = true;
}

void evolution(const vector<vector<bool>> &grilleJeu, vector<vector<bool>> &anticipation) {
   
   size_t col, ligne;
   int iCompteur = 0;
   
   for(size_t i = 0; i < ligne; i++){
            for(size_t j = 0; j < col; j++){
               
               anticipation[i][j] = estVivant(grilleJeu, j, i);
            }
        }
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

bool estVivant(const vector<vector<bool>> &grilleJeu, size_t posx, size_t posy ){

   unsigned cpt = 0;
   
   bool estVivant = grilleJeu[posy][posx];
   
   for(int i = -1; i < 2; i++){
      for(int j = -1; j < 2; j++){
         
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