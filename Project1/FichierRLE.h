

#pragma once
#ifndef InfoFichierRLE_H
#define InfoFichierRLE_H

#include <fstream>  // requis pour ifstream 
#include <string>  // requis pour string et getline 
#include <array>   // requis pour array 
#include <algorithm> // requis pour for_each 
#include <list>  // requis pour la liste
#include <string> // requis pour la chaîne de caractères 
#include <regex>  // requis pour l'expression régulière
#include "Cellule.h"
#include <ctype.h>
                             

class FichierRLE{

private:
	std::string mfileName{};
	

public:
	FichierRLE() = default;
	~FichierRLE();

	FichierRLE(int X, int Y, std::string patron, std::string regle);
	FichierRLE(int X, int Y, std::string patron);
	void copyMatch(std::list<std::string> const& from, std::list<std::string>& to, std::string const& regexMatch);

	std::vector<int> getmNaissance();
	std::vector<int> getmSurvie();
	std::vector<std::vector<Cellule>> getPatron();

	int charToInt(char toInt);

	std::vector<std::string> getRegex(std::string source, std::string regexCapture);
	void setRegle();
	void setPatron();
	
	int mX;
	int mY;
	std::string mRegle;
	std::string mPatron; 



private:
	std::vector<int> mNaissance;
	std::vector<int> mSurvivre;
	std::vector<std::vector<Cellule>> vecPatron;
};




#endif
