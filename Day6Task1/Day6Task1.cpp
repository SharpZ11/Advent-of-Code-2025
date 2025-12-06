#include <fstream>
#include <vector>
#include <string>
#include <iostream>

int main(){

    std::ifstream file("homework.txt");
    std::string line;
    std::vector<std::string> numbersRow;
    std::vector<std::string> operandsRow;
    
    while (file >> line) {
        if (line == "+" || line == "*") {
            operandsRow.push_back(line);
        } else {
            numbersRow.push_back(line);
        }
    }

    int anzahlRechnungen = operandsRow.size(); // bei Test.txt = 4
    int anzahlZahlen = numbersRow.size(); // bei Test.txt = 12

    for(int i = 0; i < numbersRow.size(); i++){
        // std::cout << i << ": (" << numbersRow[i] << ")" << " ";
        if((i+1) % anzahlRechnungen == 0){
            // std::cout << "\n";
        }
    }

    std::cout << "\n";

    for(int i = 0; i < operandsRow.size(); i++){
        // std::cout << i+1 << ".Zeile: " << operandsRow[i] << "\n";
    }

    std::cout << "\n";

    long long summe = 0;

    // Schleife für jeden Operanden
    for(int i = 0; i < anzahlRechnungen; i++){

        long long ergebnis = stoll(numbersRow[i]);

        // Schleife für jede verrechnete Zahl
        for(int j = i + anzahlRechnungen; j < anzahlZahlen; j += anzahlRechnungen){
            if(operandsRow[i] == "*"){
                ergebnis *= stoll(numbersRow[j]);
            } else if(operandsRow[i] == "+"){
                ergebnis += stoll(numbersRow[j]);
            }
        }

        // std::cout << "Ergebnis nach " << i << ". Iteration: " << ergebnis << "\n";

        summe += ergebnis;
    }

    std::cout << "Summe: " << summe << "\n";

    file.close();

    return 0;
}