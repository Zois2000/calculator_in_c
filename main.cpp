#include <iostream>
#include <vector>

int main() {
    std::vector<int> zahlen;
    int zahl;
    char stop;

    std::cout << "Geben Sie Zahlen ein. Geben Sie 'x' ein, um zu stoppen." << std::endl;

    while (true) {
        std::cout << "Eingabe: ";
        if (std::cin >> zahl) {  
            zahlen.push_back(zahl);  // Zahl in den Vektor speichern
        } else {  
            std::cin.clear();  
            std::cin >> stop;  
            if (stop == 'x') {  
                break;
            }
        }
    }

    // Ausgabe der gespeicherten Zahlen
    std::cout << "Eingegebene Zahlen: ";
    for (int num : zahlen) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
