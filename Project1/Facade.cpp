#include "Facade.h"
#include "Cellule.h"

#include <iostream>


using namespace std;

Facade::Facade(vector<vector<Cellule>> & paramEspace,vector<int>vecActive,vector<int>vecInnac, int posX, int posY, int paramLongeur, int paramLargeur)
	: espace{ paramEspace }, currentX{ posX }, currentY{ posY }, longeur{ paramLongeur }, largeur{ paramLargeur }, vecActive{ vecActive }, vecInnac{ vecInnac }
{
}
/*
	METHOD POUR RETOURNER LA NOUVELLE ETAT DE LA CELLULE
	PARAM: LA CELLULE
	RETURN: NOUVELLE ETAT DE LA CELLULE
*/
bool Facade::getNouvelleEtat(Cellule cell) {
	return verificationAutours(vecActive, vecInnac, cell);
}

void Facade::setCurrentX(int x)
{
	currentX = x;
}

void Facade::setCurrentY(int y)
{
	currentY = y;
}

void Facade::setFacade(vector<vector<Cellule>>& paramEspace, vector<int> vecActive, vector<int> vecInnac, int posX, int posY, int longeur, int largeur)
{
	espace = paramEspace;
	this->vecActive = vecActive;
	this->vecInnac = vecInnac;
	currentX = posX;
	currentY = posY;
	this->longeur = longeur;
	this->largeur = largeur;
}

/*
	METHOD POUR VERIFIER ET RETOURNER LE NOUVELLE ETAT DE LA CELLULE
	PARAM 1: VECTEUR QU'ON UTILISE SI LA CELLULE EST ACTIVE AU DEPART
	PARAM 2: VECTEUR QU'ON UTILISE SI LA CELLULE EST INNACTIVE AU DEPART
	PARAM 3: LA CELLULE
	RETURN: NOUVELLE ETAT DE LA CELLULE
*/
bool Facade::verificationAutours(vector<int>vecActive, vector<int>vecInnac, Cellule cell) {
	int compteurDeCell{};
	
	compteurDeCell += castBoolToInt(verifLeftShift(currentX));
	compteurDeCell += castBoolToInt(verifRightShift(currentX));
	compteurDeCell += castBoolToInt(verifTopShift(currentY));
	compteurDeCell += castBoolToInt(verifBottomShift(currentY));
	compteurDeCell += castBoolToInt(verifTopLeftShift(currentX, currentY));
	compteurDeCell += castBoolToInt(verifTopRightShift(currentX, currentY));
	compteurDeCell += castBoolToInt(verifBottomLeftShift(currentX, currentY));
	compteurDeCell += castBoolToInt(verifBottomRightShift(currentX, currentY));
	vector<int> toVerif = vecActive;
	if (!(bool)cell.value())
		toVerif = vecInnac;
	return find(toVerif.begin(), toVerif.end(), compteurDeCell) != toVerif.end() ? 1 : 0;;
}
/*
	METHOD POUR CASTER UN BOOLEAN A UN INTEGER
	PARAM 1: LE BOOLEAN QU'ON VEUT CAST A UN INT
	RETURN: 1 OU 0
*/
int Facade::castBoolToInt(bool toInt) {
	return toInt ? 1 : 0;
}

/*
	ENSEMBLES DE METHODES QUI VERIFIE AUTOURS DE LA CELLULE
	PARAMS: LA POSITION X ET/OU POSITION Y DE LA CELLULE 
*/
bool Facade::verifLeftShift(int current) {
	int index = gestionDesCoins(current - 1, longeur);
	return (bool)espace[currentY][index].value();
}
bool Facade::verifRightShift(int current) {
	int index = gestionDesCoins(current + 1, longeur);
	return (bool)espace[currentY][index].value();
}
bool Facade::verifTopShift(int current) {
	int index = gestionDesCoins(current - 1, largeur);
	return (bool)espace[index][currentX].value();
}
bool Facade::verifBottomShift(int current) {
	int index = gestionDesCoins(current + 1, largeur);
	return (bool)espace[index][currentX].value();
}
bool Facade::verifTopLeftShift(int currentLong, int currentLarg) {
	int indexHori = gestionDesCoins(currentLong - 1, longeur);
	int indexVerti = gestionDesCoins(currentLarg - 1, largeur);
	return (bool)espace[indexVerti][indexHori].value();;
}
bool Facade::verifTopRightShift(int currentLong, int currentLarg) {
	int indexHori = gestionDesCoins(currentLong - 1, longeur);
	int indexVerti = gestionDesCoins(currentLarg + 1, largeur);
	return (bool)espace[indexVerti][indexHori].value();
}
bool Facade::verifBottomLeftShift(int currentLong, int currentLarg) {
	int indexHori = gestionDesCoins(currentLong + 1, longeur);
	int indexVerti = gestionDesCoins(currentLarg - 1, largeur);
	return (bool)espace[indexVerti][indexHori].value();
}
bool Facade::verifBottomRightShift(int currentLong, int currentLarg) {
	int indexHori = gestionDesCoins(currentLong + 1, longeur);
	int indexVerti = gestionDesCoins(currentLarg + 1, largeur);
	return (bool)espace[indexVerti][indexHori].value();
}

/*
	METHOD POUR GERER LES COINS(EXTREMITE) DE LA PARTIE SI LA CELLULE EST A L'EXTREMITE
	PARAM 1: LA POSITION X OU Y DE LA CELLULE
	PARAM 2: LE MAXIMUM DE CETTE POSITION X OU Y
*/
int Facade::gestionDesCoins(int position, int limit) {
	int index = offSide(position, limit);
	if (index == -1)
		index = position;
	return index;
}
/*
	METHODE POUR RETOURNER LE INDEX SI HORS DU BORDER
	PARAM 1: POSITION X OU Y DE LA CELLULE
	PARAM 2: LE MAXIMUM DE CETTE POSITION X OU Y
	RETURN: -1 SI ON EST PAS HORS
	RETURN: LA POSITION A LAQUEL ON DOIT VERIFIER SI ELLE EST HORS
*/
int Facade::offSide(int position, int offLimit) {
	if (position <= 0)
		return offLimit - 1;
	else if (position >= offLimit)
		return 0;
	return -1; // -1 = cellule qu'on vérifie n'est pas hors de la bordure
}
/*
	METHODE POUR CAST UN BOOLEAN EN UNE CELLULE
	PARAM: BOOLEAN 1 OU 0 SELON SI ACTIVE
	RETURN: CELLULE ACTIVE OU INNACTIVE
*/
Cellule::Valeur toValeur(bool newVal) {
	return newVal ? Cellule::Valeur::Active : Cellule::Valeur::Inactive;
}
