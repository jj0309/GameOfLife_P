#include "ECAVue.h"
#include <iostream>

using namespace windows_console;
using namespace std;

const int MAXROWVECTOR = 450;
const int MAXCOLUMNVECTOR = 250;
//black = 0, red = 4, green = 2, blue = 1, yellow = 6, cyan = 3, magenta = 5, white = 7
const std::array<color_type, 7> ECAVue::CouleurBase{ red,green,blue,yellow,cyan,magenta,white };



ECAVue::ECAVue()
{
	csl << window::title("GAME OF LIFE BETA")
		<< window::fit(450,250 , "Consolas", 3, 1.0)
		<< window::unresizable
		<< window::unclosable
		<< window::center
		<< cursor::invisible;


}

void ECAVue::PrintLife(Monde monde) {
	
	image im;
	if (celluleMorteBackground) {
		if (couleur == white)
			im << brush(dot, text_color(black), background_color(dark))
			<< fill;
		else
			im << brush(dot, text_color(couleur), background_color(dark, couleur))
			<< fill;
	}
	else {
		im << brush(dot, text_color(black), background_color(dark))
			<< fill;
	}


	for (int row = 0; row < MAXROWVECTOR;row++) {
		for (int col = 0; col < MAXCOLUMNVECTOR; col++) {
			if (monde.getCellule(col,row).value() == Cellule::Valeur::Active) {
				im << pen(dot, text_color(couleur), background_color(couleur))
					<< point(row, col);
			}

			
		}
	}
	csl << im;
}

void ECAVue::couleurSuivante()
{
	idCouleur = (++idCouleur) % CouleurBase.size();
	couleur = CouleurBase[idCouleur];
}

void ECAVue::basculerCouleur()
{
	celluleMorteBackground = !celluleMorteBackground;
}

ECAVue::~ECAVue()
{
}
