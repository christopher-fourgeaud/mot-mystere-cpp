#include<iostream>
#include<string>

// Includes permettant d'obtenir les fonctionnalités de génération de nombres aléatoires
#include<ctime>
#include<cstdlib>

#include "../Headers/melangerLettres.h"

// Fonction pour mélanger les lettres du mot
std::string melangerLettres(std::string mot){
  std::string motMystere;
  int nombreAleatoire;

    do
    {
      // On génère un nombre aléatoire entre 0 et la taille du mot
      srand(time(0));
      nombreAleatoire = rand() % mot.size();

      //Je rajoute la lettre qui correspond a ma variable motMystere
      motMystere.push_back(mot[nombreAleatoire]);

      //Je retire la lettre situé à la position du nombre aléatoire
      mot.erase(nombreAleatoire, 1);

    } while (mot != ""); //Tant que le mot n'est pas vide on continue de boucler
  return motMystere;
}