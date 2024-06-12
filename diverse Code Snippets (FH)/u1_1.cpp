#include <iostream>

using namespace std; // damit ich nicht immer std:: schreiben muss vor STandardfunktionen wie cout, cin, etc

int main() {
    int n; // das ist die Variable für die Seitenlänge der Raute.
    
    cout << "Gib' bitte eine Seitenlaenge fuer deine gewuenschte Raute an: ";
    cin >> n; // Hiermit erfolgt die Eingabe der Seitenlänge vim Terminal als input.

    // Kurz mal überprüfen, ob die eingegebene Seitenlänge gültig ist...sei 'ma sich ehrlich...irgendjmd. wird was anderes eingeben als gewollt
    if (n < 1) {
        cout << "Bitte gib' eine positive ganze Zahl ein, die groeszer oder gleich 1 ist." << endl;
        return 1; // hier wird das Programm mit Fehlercode 1 beendet, wenn die Eingabe ungültig ist.
    }

    // Die Schleife für die Raute
    for (int i = -n; i <= n; ++i) { 
        int absI = abs(i); 
        // Ausgabe von Leerzeichen für die Einrückungen, damit es wirklich eine Raute wird, die in der MItte ist
        for (int j = 0; j < absI; ++j) { //
            cout << " ";
        }
        // hier wird die Ausgabe der *-Zeichen für die i-te Zeile definiert
        for (int j = 0; j < 2 * (n - absI) + 1; ++j) {
            cout << "*";
        }
        cout << endl;
    }
    return 0; // und das Programm wird schlussendlich beendet.
}
