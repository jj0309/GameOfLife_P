#pragma once
#ifndef CELLULE_H
#define CELLULE_H

#include<cstdint>

class Cellule
{
public:
	enum class Valeur : uint8_t {
		Inactive = 0,
		Active = 1
	};

	Cellule();
	Cellule(Valeur v);
	~Cellule() = default;

	Valeur value() const;
	void setValue(Valeur v);
	void randomize(double probabilite = 0.5);

private:
	Valeur mValeur{ Valeur::Inactive };
};


#endif // CELLULE_H



