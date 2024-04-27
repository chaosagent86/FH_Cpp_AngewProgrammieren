#include <iostream>

void show_excercise_infos();

int main()
{
	int zu_pruefende_zahl;
	bool primzahl;

	show_excercise_infos();

	// Falls Eingabe = String --> Endlosschleife!
	// weiß aber nicht warum und auch nicht wie ich zahlen oder buchstaben gleichzeitig abfragen kann
	do{
		std::cout << "Zahl soll geprueft werden?\nBitte eingeben: ";
		std::cin >> zu_pruefende_zahl;

		if (zu_pruefende_zahl > 0)
			break;
		else {
			std::cout << "Bitte nur Werte groeßer Null eingeben!" << std::endl << std::endl;
			std::cout << "--------------------------------" << std::endl << std::endl;
		}
	} while(true); // beabsichtigte Endlosschleife - ausbrechen via "break"

	std::cout << "\n--------------------------------" << std::endl;
	std::cout << "Pruefung ob Zahl = Primzahl!" << std::endl;
	std::cout << "--------------------------------" << std::endl << std::endl;

	if(zu_pruefende_zahl<= 1)
	{
		std::cout << "Wert = 1, daher keine Primzahl!" << std::endl;
		return 0; //direkt Programmende
	}

	for (int i = 2; i * i <= zu_pruefende_zahl; i++) {
		if (zu_pruefende_zahl % i == 0) {
			primzahl = false;
			break;
		}
    }

	if (primzahl) {
        std::cout << zu_pruefende_zahl << " ist eine Primzahl." << std::endl;
    } else {
        std::cout << zu_pruefende_zahl << " ist keine Primzahl." << std::endl;
		std::cout << "Daher nun Ausgabe aller Zahlen," << std::endl;
		std::cout << "durch die ohne Rest geteilt werden kann" << std::endl << std::endl;

		for (int i = 2; i <= zu_pruefende_zahl; i++) {
			if (zu_pruefende_zahl % i == 0) {
			std::cout << i << std::endl;
			}
    	}
    }

	return 0;
}


void show_excercise_infos()
{
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << "** Aufgabe 2 von Uebung 1 - Primzahl-Pruefung                                               **" << std::endl;
	std::cout << "** Ersteller: Sebastian Baier                                                               **" << std::endl;
	std::cout << "** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -**" << std::endl;
	std::cout << "** Erstellen Sie ein Programm, das prüft, ob die eingegebene Zahl eine Primzahl ist.        **" << std::endl;
	std::cout << "** Eingabe: positive ganze Zahl, die geprüft werden soll                                    **" << std::endl;
	std::cout << "** Ausgabe: Handelt es sich dabei um eine Primzahl?                                         **" << std::endl;
	std::cout << "** Wenn es sich um keine Primzahl handelt, gibt das Programm alle möglichen Zahlen aus,     **" << std::endl;
	std::cout << "** durch die ohne Rest geteilt werden kann (hier muss nicht darauf geachtet werden, ob die  **" << std::endl;
	std::cout << "** Teiler Primzahlen oder Nicht-Primzahlen sind).                                           **" << std::endl; 
	std::cout << "** Als Primzahl zählt jede Zahl, die nur durch 1 oder sich selbst ohne Rest teilbar ist.    **" << std::endl;
	std::cout << "** Hinweis: Der Modulo-Operator in C++ ist %                                                **" << std::endl; 
	std::cout << "**********************************************************************************************" << std::endl << std::endl; 
}