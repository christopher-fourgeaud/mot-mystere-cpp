#include<iostream>
#include<string>
#include "../Headers/calculScore.h"

std::string calculScore(std::vector<std::string> const& resultatManche, std::vector<int> const& essaisRestant, std::vector<std::string> const& motMystere){
  std::string resultat = "=================== RESULTATS ======================== \n";
  int score = 0;

  //Je parcour mon tableau de resultat, ce qui me donne le nombre de manche.
  for (int i = 0; i < resultatManche.size(); i++)
  {
    // Pour chaque win je rajoute un point à mon score
    if (resultatManche[i] == "win")
    {
      score += 1;
    }

    //Pour chaque essais restants j'augmente le score
    score += essaisRestant[i];
    
    // Manche N° 1:
    resultat += "\nManche numero : " + std::to_string(i+1) + "\n";
    // resultat += ":\n";

    // Resultat : Win || Essais restants = 2 || Mot mystère = chat
    resultat += "Resultat : " + resultatManche[i] + " || ";
    resultat += "Essais restants : " + std::to_string(essaisRestant[i]);
    resultat += " || Mot mystere : " + motMystere[i] + "\n";
    resultat += "___________________________________________________________";
  }
  
  resultat += "\nScore final : " + std::to_string(score) + " points! \n";
  
  resultat += "\n=============== FIN DES RESULTAT ===================== \n"; 
  return resultat;
}