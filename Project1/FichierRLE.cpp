#include "FichierRLE.h"
#include <iostream>



FichierRLE::~FichierRLE()
{
}

FichierRLE::FichierRLE(int X, int Y, std::string patron, std::string regle)
	: mX{ X }, mY{ Y }, mPatron{ patron }, mRegle{regle}
{
}

FichierRLE::FichierRLE(int X, int Y, std::string patron)
	: mX{ X }, mY{ Y }, mPatron{ patron }
{
}

std::vector<int> FichierRLE::getmNaissance() {
	return mNaissance;
}
std::vector<int> FichierRLE::getmSurvie() {
	return mSurvivre;
}
std::vector<std::vector<Cellule>> FichierRLE::getPatron() {
	return vecPatron;
}


std::vector<std::string> FichierRLE::getRegex(std::string source, std::string regex)
{
	std::vector<std::string> resultat;

	std::regex e(regex);

	const char* cible = source.c_str();

	for (auto it = std::cregex_iterator(cible, cible + std::strlen(cible), e); it != std::cregex_iterator(); ++it)
	{
		std::cmatch match = *it;
		if (match.str() != "") {
			resultat.push_back(match.str());
		}
	}
	return resultat;
}

void FichierRLE::setRegle() {
	  
	if (!mNaissance.empty() || !mSurvivre.empty()) {
		mNaissance.clear();
		mSurvivre.clear();
	}
	
	std::vector<std::string> n = getRegex(mRegle, "[0-9]*");

	for (int i = 0; i < n[0].size(); i++) {
		mNaissance.push_back(n[0][i] - '0');
	}


	for (int i = 0; i < n[1].size(); i++) {
		mSurvivre.push_back(n[1][i] - '0');
	}
}

/*
	METHODE POUR TRANSFORMER UN CHAR POUR UN INT
	PARAM : CHAR
	RETURN: INTEGER DE LA VALEUR DE CHAR EN PARAM
*/
int FichierRLE::charToInt(char toInt) 
{
	return toInt - '0';
}

void FichierRLE::setPatron() {
	if (!vecPatron.empty())
		vecPatron.clear();
	int charAtX{};
	std::vector<Cellule> vecToAppend;
	while (charAtX < mPatron.size())
	{
		char charToVerif = mPatron.at(charAtX);
		if (isdigit(charToVerif)) {
			std::string cleanMultip = "";
			while (isdigit(charToVerif)) {
				cleanMultip += charToVerif;
				charAtX++;
				charToVerif = mPatron.at(charAtX);
			}
			int multiplier = std::stoi(cleanMultip);
			if (charToVerif == '$') {
				for (int i = 0; i < multiplier; i++) {
					while (vecToAppend.size() < mX) {
						Cellule newCell;
						vecToAppend.push_back(newCell);
					}
					vecPatron.push_back(vecToAppend);
					vecToAppend.clear();
				}
			}
			charToVerif = mPatron.at(charAtX);
			for (int multiplierIndex{}; multiplierIndex < multiplier; ++multiplierIndex) {
				Cellule newCellule;
				switch (charToVerif)
				{
				case 'b':
					vecToAppend.push_back(newCellule);
					break;
				case 'o':
					newCellule.setValue(Cellule::Valeur::Active);
					vecToAppend.push_back(newCellule);
				}
			}
		}
		else {
			if (charToVerif == '$') {
				while (vecToAppend.size() < mX) {
					Cellule newCell;
					vecToAppend.push_back(newCell);
				}
				vecPatron.push_back(vecToAppend);
				vecToAppend.clear();
			}
			else {
				Cellule newCell;
				if (charToVerif == 'b') {
					vecToAppend.push_back(newCell);
				}
				else if (charToVerif == 'o') {
					newCell.setValue(Cellule::Valeur::Active);
					vecToAppend.push_back(newCell);
				}
			}
		}
		++charAtX;
	}
	vecPatron.push_back(vecToAppend);
	vecToAppend.clear();
	for (int indexY = vecPatron.size() - 1; indexY < mY; ++indexY) {
		for (int indexX = vecPatron.at(indexY).size(); indexX < mX; ++indexX) {
			Cellule newCell;
			vecPatron.at(indexY).push_back(newCell);
		}
	}

}

// Transfert les chaînes de caractères d'une liste dans une autre  
// liste. Le transfert est conditionnel à la conformité de la  
// chaîne de caractères à une expression régulière. 
void FichierRLE::copyMatch(std::list<std::string> const& from,
	std::list<std::string>& to,
	std::string const& regexMatch) {
	// Vide la liste de résultats  
	to.clear();
	// Construit le regex  
	std::regex matchRegex(regexMatch);
	// Pour toutes les chaînes de caractères sources  
	for (auto const& str : from) {
		// Si la chaîne de caractères est conforme   
		if (std::regex_match(str, matchRegex)) {
			// Ajoute une copie    
			to.push_back(str);
		}
	}
}

