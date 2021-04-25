#ifndef CALCUL_SCORE
#include<string>
#include<vector>

/**
 * \brief Fonction qui calcule le score du joueur à la fin de la partie
 * \param resultatManche  Le tableau de résultat des manches
 * \param essaisRestant  Le nombre d'éssais restants dans chaque manche
 * \param motMystere Le mot qui était à deviner dans chaque manche
 * 
 * \return Le score de la partie et les informations sur les manches joués 
*/
std::string calculScore(std::vector<std::string> resultatManche, std::vector<int> essaisRestant, std::vector<std::string> motMystere);

#endif // !CALCUL_SCORE