#pragma once
#ifndef INPUT_H
#define INPUT_H


#include <cstdint>
#include <string>
#include <vector>
#include "ECAVue.h"
#include "Monde.h"
#include "LecteurFichier.h"

class Controleur
{
public:
	
	void changerEtatMonde();
	void changerRegle();
	void changerBordure();
	void changerCouleur();
	void modifierVitesse(int vitesse);
	void randomizeCellule(double pourcentage);
	void basculerCouleur();
	void boucleJeu();
	void fichierRlePrecedent();
	void fichierRleCourant();
	void fichierRleSuivant();
	Controleur();
	void CommandeToDO(uint8_t input);

	~Controleur() = default;

private:
	bool quit{ false };
	int vitesseJeu {1};
	ECAVue v;
	Monde monde;
	LecteurFichier mLecteurFichiersRle;
};

#endif // INPUT_H