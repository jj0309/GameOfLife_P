#pragma once

#ifndef ECAVUE_H
#define ECAVUE_H

#include <vector>
#include "Cellule.h"
#include "Monde.h"
#include <windows_console.h>

class ECAVue
{
public:
	ECAVue();
	~ECAVue();
	void PrintLife(Monde monde);

	void couleurSuivante();
	void basculerCouleur();

private:
	uint8_t idCouleur;
	bool celluleMorteBackground{false};
	windows_console::color_type couleur;
	static const std::array<windows_console::color_type, 7> CouleurBase;
};

#endif // ECAVUE_H