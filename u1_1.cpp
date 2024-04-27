#include <iostream>

void show_excercise_infos();

int main() {

	show_excercise_infos();

   int sideLength;

	// Falls Eingabe = String --> Endlosschleife!
	// weiß aber nicht warum und auch nicht wie ich zahlen oder buchstaben gleichzeitig abfragen kann
	do{
		std::cout << "Welche Seitenlaenge soll die Raute besitzen?\nBitte eingeben: ";
		std::cin >> sideLength;

		if (sideLength >= 1)
			break;
		else {
			std::cout << "Falsche Eingabe (Wert kleiner 1 - bitte wiederholen!!)" << std::endl << std::endl;
			std::cout << "--------------------------------" << std::endl << std::endl;
		}
	} while(true); // beabsichtigte Endlosschleife - ausbrechen via "break"
	
	sideLength++;

	// Obere Haelfte der Raute inklusive Mitte ----------------
	for(int i = 0; i < sideLength; i++) 
	{
		for (int j = 0; j < sideLength - i - 1; j++) { std::cout << " "; }
		for (int j = 0; j < 2 * i + 1; j++) { std::cout << "*"; }
		std::cout << std::endl;
    }

    // Untere Haelfte der Raute --------------------
    for(int i = sideLength - 2; i >= 0; i--) {
        for (int j = 0; j < sideLength - i - 1; j++) { std::cout << " "; }
        for (int j = 0; j < 2 * i + 1; j++) { std::cout << "*"; }
        std::cout << std::endl;
    }

    return 0;
}

void show_excercise_infos()
{
	std::cout << "*******************************************************************" << std::endl;
	std::cout << "** Aufgabe 1 von Uebung 1 - Raute zeichnen                       **" << std::endl;
	std::cout << "** Ersteller: Sebastian Baier                                    **" << std::endl;
	std::cout << "** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - **" << std::endl;
	std::cout << "** Aufgabe: Erstellung einer Raute unter Angabe der Seitenlaenge **" << std::endl;
	std::cout << "** Der Wert muss hierbei gleich oder größer 1 sein               **" << std::endl; 
	std::cout << "*******************************************************************" << std::endl << std::endl; 
}