#include<iostream>
#include<fstream>
#include<vector>
// Includes permettant d'obtenir les fonctionnalités de génération de nombres aléatoires
#include<ctime>
#include<cstdlib>
#include "../Headers/choisirRandomMotDictionnaire.h"

std::string choisirRandomMotDictionnaire(){
  std::vector<std::string> motsDictionnaire;
  std::string mot;
  std::string motMystere;

  std::ifstream dictionnaire("./Ressources/words.txt");
  if (dictionnaire)
  {  
    // On prépare une génération de nombre
    srand(time(0));

    // On prends un mot de chaque ligne du fichier text et on le stock dans le tableau de mots "motsDictionnaire"
    int compteur = 0;
    while (std::getline(dictionnaire, mot))
    {
      compteur++;
      motsDictionnaire.push_back(mot);
    }
    
    // On génère un nombre aléatoire entre 0 et le nombre total de mot dans le tableau
    int randomNumber = rand() %compteur;
    
    motMystere = motsDictionnaire[randomNumber];

  }else
  {
    std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture.";
  }

  return motMystere;
}

