#include "Cellule.h"
#include "RandomUtil.h"



Cellule::Cellule()
	:mValeur{Cellule::Valeur::Inactive}
{
}

Cellule::Cellule(Valeur v)
	: mValeur{v}
{
}

Cellule::Valeur Cellule::value() const
{
	return mValeur;
}

void Cellule::setValue(Valeur v)
{
	mValeur = v;
}

void Cellule::randomize(double probabilite)
{
	mValeur = (Valeur)RandomUtil::generateEvent(probabilite);
}