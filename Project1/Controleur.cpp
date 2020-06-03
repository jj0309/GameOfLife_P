#include "Controleur.h"
#include "windows_console.h"

using namespace windows_console;

int main() {
	Controleur c;
	c.boucleJeu();

}

Controleur::Controleur()
	: mLecteurFichiersRle("FichiersRLE\\")
{
	monde.randomize(0.1);
	v.PrintLife(monde);
}

void Controleur::boucleJeu(){
	csl << key_events::add_filter<key_filter_up>;
	console_events consoleEvents;
	while (!quit) {
	      consoleEvents.read_events();
	      while (consoleEvents.key_events_count() > 0) {
			   CommandeToDO(consoleEvents.next_key_event().ascii_value());
	      }
		  if (monde.getEtatMonde() == false) {
			  for (int i{ 0 }; i < vitesseJeu; ++i) {
				  monde.evolution();
			  }
		  }
		  v.PrintLife(monde);
	 }
}

void Controleur::CommandeToDO( uint8_t input ){
	if (input >= '1' && input <= '9') {
		switch (input)
		{
		case '1': modifierVitesse(1); break;
		case '2': modifierVitesse(2); break;
		case '3': modifierVitesse(3); break;
		case '4': modifierVitesse(4); break;
		case '5': modifierVitesse(5); break;
		case '6': modifierVitesse(6); break;
		case '7': modifierVitesse(7); break;
		case '8': modifierVitesse(8); break;
		case '9': modifierVitesse(9); break;

		default:
			break;
		}
	}
	else {
		input = toupper(input);
		switch (input)
		{
		case ' ': changerEtatMonde(); break;
		case 'R': changerRegle(); break;
		case 'B': changerBordure(); break;
		case 'P': changerCouleur(); break;
		case 'O': basculerCouleur(); break;
		case 'A': randomizeCellule(0.01); break;
		case 'S': randomizeCellule(0.05); break;
		case 'D': randomizeCellule(0.1); break;
		case 'F': randomizeCellule(0.15); break;
		case 'G': randomizeCellule(0.25); break;
		case 'H': randomizeCellule(0.50); break;
		case 'Z': fichierRlePrecedent(); break;
		case 'X': fichierRleCourant(); break;
		case 'C': fichierRleSuivant(); break;
		case 27 : quit = true; break;

		default:
			break;
		}
	}
 }

void Controleur::randomizeCellule(double pourcentage) {
	monde.randomize(pourcentage);
}

void Controleur::changerEtatMonde() {
	monde.changerEtatMonde();
}

void Controleur::fichierRlePrecedent() {
	mLecteurFichiersRle.fichierRlePrecedent();
	monde.setMonde(mLecteurFichiersRle.getPatron(), mLecteurFichiersRle.getNaissance(), mLecteurFichiersRle.getSurvie());
}
void Controleur::fichierRleCourant() {
	mLecteurFichiersRle.fichierRleCourant();
	monde.setMonde(mLecteurFichiersRle.getPatron(), mLecteurFichiersRle.getNaissance(), mLecteurFichiersRle.getSurvie());
}
void Controleur::fichierRleSuivant() {
	mLecteurFichiersRle.fichierRleSuivant();
	monde.setMonde(mLecteurFichiersRle.getPatron(), mLecteurFichiersRle.getNaissance(), mLecteurFichiersRle.getSurvie());

}


void Controleur::changerRegle() {
	monde.changerRegle();
}

void Controleur::changerBordure() {
	monde.changerBordure();
}
void Controleur::changerCouleur() {
	v.couleurSuivante();
}
void Controleur::basculerCouleur() {
	v.basculerCouleur();
}

void Controleur::modifierVitesse(int vitesse){
	 vitesseJeu = vitesse;
}



