#include <fstream>
#include <vector>
#include <string>
#include <iostream>

int main(){

    std::ifstream file("joltage.txt");
    std::string banks;

    int sum = 0;

    while(getline(file,banks)){

        int firstSignificantBiggestNum = 0;
        int secSignificantBiggestNum = 0;

        std::cout << "\n" << "Banks length: " << banks.length() << "\n";
        std::cout << "Current Bank: "<< banks << "\n";
        std::cout << "\n";

        // Erste Schleife fuer erste groesste Zahl
        for(int i = 0; i < banks.length()-1; i++){

            //std::cout << "banks[i]: " << banks[i] << "\n";

            char bankCharVali = banks[i];
            int bankIntVali = bankCharVali - '0';
            int stelleI = 0;
            int stelleJ = 0;

            // Speichern der groessten Zahl, abgleich mit den restlichen Zahlen
            if(bankIntVali > firstSignificantBiggestNum){
                firstSignificantBiggestNum = bankIntVali;
                secSignificantBiggestNum = 0; // zweitgroesste signif. nummer zuruecksetzen
                                              // da diese nicht "links" von der ersten stehen darf
                stelleI = i;
            }

            if (stelleI == i){
                std::cout << "Groesste Zahl: " << firstSignificantBiggestNum << " liegt an Stelle: " << stelleI << "\n";
            }

            // Zweite Schleife fuer alle Zahlen die nach der Momentan groeßten ersten signif. Zahl kommen
            for(int j = i+1; j <= banks.length(); j++){

                //std::cout << "banks[j]: " << banks[j] << "\n";

                char bankCharValj = banks[j];
                int bankIntValj = bankCharValj - '0';
                //int stelleJ = 0;

                if(bankIntValj > secSignificantBiggestNum){
                    secSignificantBiggestNum = bankIntValj;
                    stelleJ = j;
                }

                if (stelleJ == j){
                    std::cout << "Zweitgroesste Zahl: " << secSignificantBiggestNum << " liegt an Stelle: " << stelleJ << "\n";
                }

                //std::cout << "Iteration von j: " << j << "\n";
            }

        }

        std::cout << "\n";
        std::cout << "firstNum: " << firstSignificantBiggestNum << "\n";
        std::cout << "secondNum: " << secSignificantBiggestNum << "\n";
        std::cout << "\n";

        // Nummern zussammensetzen
        std::string strJolts = std::to_string(firstSignificantBiggestNum) + std::to_string(secSignificantBiggestNum);

        // Ausgabe Jolts von der jeweiligen Bank
        std::cout << "strJolts: " << strJolts << "\n";

        // Ausgabe der Summe von Jolts
        sum += stoi(strJolts);

    }

    std::cout << "Endsumme: " << sum << "\n";

    file.close();
    return 0;
}