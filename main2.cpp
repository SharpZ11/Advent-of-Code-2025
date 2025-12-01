#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream file("rotations.txt");
    std::string line;

    int pointer = 50;
    int oldpointer = 0;
    int zeroCounter = 0;
    int oldZeroCounter = 0;

    int lineIndex = 0;

    while(std::getline(file, line))
    {
        lineIndex++;

        // get direction and rotation of line in file
        //std::cout << "Current Line: " << line << " | Direction:";
        std::string direction = line.substr(0,1);
        int rotations = std::stoi(line.substr(1,line.length()-1));
        //std::cout << direction << " | Rotations: " << rotations << "\n";

        // calc new pointer position
        if(direction == "R")
        {
            oldpointer = pointer;
            pointer += rotations;
            pointer = pointer%100;

        }
        else
        {
            oldpointer = pointer;
            pointer -= rotations;
            pointer = pointer%100;

            if (pointer < 0) pointer = pointer + 100;
        }

        oldZeroCounter = zeroCounter;

        
        // Fall 1: Rechts Rotation, Zeiger landet bei kleiner Zahl als vorheriger Zeiger, start von 0 ausgehend wird nicht beachtet
        if((direction == "R" && pointer <= oldpointer) && oldpointer != 0){
            zeroCounter++;
        }
         // Fall 2: Links Rotation, Zeiger landet bei größeren Zahl als vorheriger Zeiger, start von 0 ausgehend wird nicht beachtet
        if((direction == "L" && pointer >= oldpointer) && oldpointer != 0){
            zeroCounter++;
        }
        // Fall 3: Zeiger dreht sich mindestens einmal komplett um, drehungen werden aufaddiert
        if(rotations > 100){
            zeroCounter = (zeroCounter + rotations/100);
        }
        // Fall 4: Zeiger landet genau auf 0, Fälle 1 und 2 werden somit ignoriert, da sonst doppelt gezählt wird
        if (pointer == 0 && !((direction == "R" && pointer <= oldpointer)||(direction == "L" && pointer >= oldpointer))){
            zeroCounter++;
        }

        if(lineIndex <= 20 || lineIndex >= 500){
            std::cout << " Alte Pointer Position: " << oldpointer 
            << " | Direction: " << direction 
            << " | Rotations: " << rotations 
            << " | Neue Pointer Position: " << pointer 
            << " | Zero counter: " << zeroCounter 
            << " | Zero difference: " << zeroCounter - oldZeroCounter << "\n";
        }
        
    }

    std::cout << zeroCounter;

    file.close();

    return 0;
}