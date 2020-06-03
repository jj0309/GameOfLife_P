#pragma once
#ifndef FACADE_H
#define FACADE_H


#include <vector>
#include <string>
#include "Cellule.h"
using namespace std;
class Facade
{
public:
	Facade(vector<vector<Cellule>> & paramEspace, vector<int>vecActive, vector<int>vecInnac, int posX, int posY, int longeur, int largeur);

	// la methode nouvelleEtat retourne la nouvelle etat de la cellule
	bool getNouvelleEtat(Cellule cell);
	void setCurrentX(int x);
	void setCurrentY(int y);
	void setFacade(vector<vector<Cellule>> & paramEspace, vector<int>vecActive, vector<int>vecInnac, int posX, int posY, int longeur, int largeur);

	~Facade() = default;

private:
	vector<vector<Cellule>> & espace;
	//vector<Cellule>::const_iterator stateIt;
	vector<int>vecActive;
	vector<int>vecInnac;
	// pour position de la cellule dans les vecteurs
	int currentX;
	int currentY;
	/*
		POUR LIMIT
	*/
	int longeur;
	int largeur;
	/*
	METHODES POUR SHIFT DANS LE VECTOR
	RETURN: LA CELLULE DANS LAQUEL ON SHIFT
	*/
	
	bool verifLeftShift(int current);
	bool verifRightShift(int current);
	bool verifTopShift(int current);
	bool verifBottomShift(int current);
	bool verifTopLeftShift(int currentLong, int currentLarg);
	bool verifTopRightShift(int currentLong, int currentLarg);
	bool verifBottomLeftShift(int currentLong, int currentLarg);
	bool verifBottomRightShift(int currentLong, int currentLarg);
	
	/*
		METHODE POUR CAST LES BOOL EN INT
	*/
	int castBoolToInt(bool toInt);
	/*
		METHODE POUR VERIFIER LES DEPASSEMENTS, RETOURNE NOUVELLE INDEX DE VECTEUR SI C'EST LE CAS
	*/
	int gestionDesCoins(int position, int limit);
	/*
	METHODE POUR VERIFIER AUTOURS DE LA CELLULE SELON LA REGLE
	PARAM 1: LA REGLE
	RETURN: BOOL: 1 SI VIE, 0 SI MORT
	*/
	bool verificationAutours(vector<int>vecActive, vector<int>vecInnac, Cellule cell);

	int offSide(int position, int offLimit);
};
Cellule::Valeur toValeur(bool newVal);


#endif // !FACADE_H