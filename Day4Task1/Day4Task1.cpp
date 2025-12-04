#include <fstream>
#include <vector>
#include <string>
#include <iostream>

int main()
{

    std::ifstream file("rolls.txt");
    std::string line;
    std::vector<std::string> row;

    int rollCount = 0;

    while (getline(file, line))
    {

        //std::cout << line << "\n";

        row.push_back(line);
    }

    // std::cout << "\n";

    for (int i = 0; i < row.size(); i++)
    {

        //std::cout << "i-schleife: " << row[i] << "\n";

        

        for (int j = 0; j < row[i].size(); j++)
        {
            int counter = -1;
            //std::cout << "j-schleife: " << row[i][j] << "\n";

            // bei rolle starten
            if (row[i][j] == '@')
            {
                // benachbarten positionen checken
                for (int k = -1; k <= 1; k++)
                {
                    for (int l = -1; l <= 1; l++)
                    {
                        int zeiger1 = i+k;
                        int zeiger2 = j+l;

                        if (zeiger1 >= 0 && zeiger2 >= 0 && zeiger1 < row.size() && zeiger2 < row[i].size())
                        {
                            if (row[zeiger1][zeiger2] == '@')
                            {
                                counter++;
                                //std::cout << "counter: " << counter << "\n";
                            }
                        }
                    }
                }

                if (counter < 4)
                {
                    rollCount++;
                }
            }
        }

        //std::cout << row[i] << "\n";
    }

    std::cout << rollCount;

    return 0;
}