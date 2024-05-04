#include <iostream>

void show_excercise_infos();
std::string umgekehrte_worte(const std::string& satz);

int main() {
    show_excercise_infos();
	
	std::string eingabe;
    std::cout << "Bitte Text eingeben: ";
    std::getline(std::cin, eingabe);
    
    std::string ausgabe = umgekehrte_worte(eingabe);
    std::cout << "Ausgabe: " << ausgabe << std::endl;
    
    return 0;
}

std::string umgekehrte_worte(const std::string& eingabe) {
    std::string umgedrehter_satz;
    std::string wort;
    int wort_start = 0;
    
    for (int i = 0; i <= eingabe.size(); i++) {
		std::cout << "eingabe.size(): " << eingabe.size() << std::endl;
		std::cout << "eingabe[i]: " << eingabe[i] << std::endl;
        if (i == eingabe.size() || eingabe[i] == ' ') {
            std::string umgedrehtes_wort = eingabe.substr(wort_start, i - wort_start);
            for (int j = umgedrehtes_wort.size() - 1; j >= 0; j--) {
                umgedrehter_satz += umgedrehtes_wort[j];
            }
            umgedrehter_satz += " ";
            wort_start = i + 1;
        }
    }
    
    return umgedrehter_satz;
}


void show_excercise_infos()
{
	std::cout << "***************************************************************************" << std::endl;
	std::cout << "** Aufgabe 1 von Uebung 1 - Raute zeichnen                               **" << std::endl;
	std::cout << "** Ersteller: Sebastian Baier                                            **" << std::endl;
	std::cout << "** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -         **" << std::endl;
	std::cout << "** Erstellen Sie ein Programm, das den eingegeben Text umkehrt.          **" << std::endl;
	std::cout << "** Eingabe: Text                                                         **" << std::endl;
	std::cout << "** Ausgabe: Text, bei dem die einzelnen Worte verkehrt geschrieben sind. **" << std::endl;
	std::cout << "** Hierbei soll jedes Wort mit einem Großbuchstaben beginnen und         **" << std::endl;
	std::cout << "** der Rest des Wortes klein geschrieben werden. Die Worte selbst        **" << std::endl;
	std::cout << "** bleiben jedoch in der richtigen Reihenfolge.                          **" << std::endl; 
	std::cout << "***************************************************************************" << std::endl << std::endl; 
}