#ifndef COMPARER_MOTS
#include<string>

/**
 * \brief Fonction qui compare le mot mystère au mot soumis par le joueur
 * \param motMystere  Le mot soumis par le joueur 1
 * \param motSoumis  Le mot suggéré par le joueur 2
 * \return True si les deux mots correspondent
*/
bool comparerMots(std::string motSoumis, std::string motMystere);

#endif // !COMPARER_MOTS