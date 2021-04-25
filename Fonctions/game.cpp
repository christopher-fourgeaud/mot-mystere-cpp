#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "../Headers/melangerLettres.h"
#include "../Headers/comparerMots.h"
#include "../Headers/calculScore.h"
#include "../Headers/choisirRandomMotDictionnaire.h"
#include "../Headers/game.h"


void game()
{
  std::string motMystere;
  std::string motMystereMelange;
  std::string motSoumis;
  std::string rejouer = "o";
  int nombreJoueurs;

  //Je stocke le résultat de chaque manche w = win l = loose
  std::vector<std::string> resultatsManches;

  //Je stocke le nombre d'essais restants de la manche jouée
  std::vector<int> essaisRestants;

  //Je stocke le mot mystère de la manche jouée
  std::vector<std::string> motsMysteres;

  //Boucle du jeu complet
  do
  { 
    int essai = 5;

    //Clear la ligne de commande
    system("cls");

    std::cout << "********** Bienvenue dans le jeu du mot mystere! **********" << std::endl;

    do
    {
      //Demander si c'est une partie à un ou deux joueurs
      std::cout << "Choisisez le nombre de joueurs (1/2)" << std::endl;
      std::cin >> nombreJoueurs;
    } while (nombreJoueurs != 1 && nombreJoueurs != 2);
    
    //Clear la ligne de commande
    system("cls");
    

    //Si on est tout seul, on va chercher un mot dans le fichier texte, sinon on demande au joueur 2 de choisir le mot
    if (nombreJoueurs == 2)
    {
      //Demander au joueur 1 de saisir le mot à trouver
      std::cout << "Joueur 1: Veuillez choisir le mot mystere a faire deviner au second joueur:" << std::endl;

      //Stocker le mot à trouver
      std::cin >> motMystere;
    }else
    {
      motMystere = choisirRandomMotDictionnaire();
    }
    
    
    //Je stocke le mot mystere dans un tableau pour pouvoir y acceder pour les scores
    motsMysteres.push_back(motMystere);

    //Utiliser une fonction pour melanger les lettres du mot
    motMystereMelange = melangerLettres(motMystere);

    //Clear la ligne de commande
    system("cls");

    //Boucle permettant de faire de nouvelles tentatives
    do
    {
      //Afficher le mot à trouver au joueur 2 
      std::cout << "Quel est ce mot ? " << essai << " try restant" << std::endl;
      std::cout << motMystereMelange << std::endl;

      //Demander au joueur 2 de saisir un mot
      std::cout << "Essayez de deviner le mot mystere :" << std::endl;

      //Stocker le mot suggéré du joueur 2
      std::cin >> motSoumis;

      //utiliser une fonction qui compare le mot à trouver et le mot suggérer et renvoie un succès ou un echec
      if (comparerMots(motSoumis, motMystere))
      {
        std::cout << "Bravo tu a trouver le mot mystere !" << std::endl;

        //Je stock une win dans mon tableau de résultat
        resultatsManches.push_back("win");
      }else
      {
        std::cout << "Mauvais reponse !" << std::endl << std::endl;
        essai--;
      }

      // Si les essais tombent à 0 alors le joueurs perd et une nouvelle partie est proposé
      if (essai == 0)
      {
        std::cout << "Vous avez perdu !" << std::endl;

        //Je stock une lose dans mon tableau de résultat
        resultatsManches.push_back("lose");

        break;
      }
      
    } while (!comparerMots(motSoumis, motMystere));

    //Je stocke le nombre d'éssais restants 
      essaisRestants.push_back(essai);

    // Une fois la partie terminée on en propose une autre
    std::cout << "Souhaitez vous rejouer? (o/n)" << std::endl;
    std::cin >> rejouer;

    //Clear la ligne de commande
    system("cls");

  } while (rejouer == "o");
  
  //Calculer et donner le score du joueur
  std::cout << calculScore(resultatsManches, essaisRestants, motsMysteres) << std::endl;

  //Attend un input utilisateur pour fermer la
  std::cin.ignore();
  std::cin.get();
}

