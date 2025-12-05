#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <algorithm>

int main()
{

    std::ifstream file("ids.txt");
    std::string line;
    std::vector<std::string> idRanges;
    std::vector<long long> linesX;
    std::vector<long long> linesY;

    long long counter = 0;

    while (getline(file, line))
    {

        if (line.find("-") != std::string::npos)
        {
            idRanges.push_back(line);
        }
    }

    for (int i = 0; i < idRanges.size(); i++)
    {
        std::string range = idRanges[i];

        std::string start = range.substr(0, range.find("-"));
        std::string end = range.substr(range.find("-") + 1, range.size());

        long long startNum = stoll(start);
        long long endNum = stoll(end);

        linesX.push_back(startNum);
        linesY.push_back(endNum);

    }

    // linesX und linesY in paare umwandeln und nach groesse sortieren
    std::vector<std::pair<long long, long long>> ranges;
    ranges.reserve(linesX.size());
    for (size_t i = 0; i < linesX.size(); ++i)
    {
        ranges.emplace_back(linesX[i], linesY[i]);
    }

    std::sort(ranges.begin(), ranges.end(),
              [](const auto &a, const auto &b)
              {
                  return a.first < b.first;
              });

    for (int i = 0; i < ranges.size(); i++)
    {
        std::cout << i + 1 << ".range: " << ranges[i].first << "-" << ranges[i].second << "\n";
    }

    // Erste Range
    long long x1 = ranges[0].first;
    long long y1 = ranges[0].second;

    int j = 1;

    while (j < ranges.size())
    { // idRange j ->    x1 |---------| y1
      // idRange j+1 ->      x2 |---------| y2
      // wird zu ->      x1 |-------------| y1

        // sonst ->        x1 |---------| y1 <- wird addiert
        //                                 x1=x2 |---------| y1=y2 <- wird neuer anfang
        long long x2 = ranges[j].first;
        long long y2 = ranges[j].second;

        // Falls sich die Ranges nicht schneiden wird vorherige range addiert
        if (x2 > y1 + 1)
        {
            counter += (y1 - x1 + 1);

            // Nächste Range wird nun betrachtet
            x1 = x2;
            y1 = y2;
        }
        else
        {
            // Ranges überlappen sich, Endpunkt wird um y2 erweitert, neue Range
            if (y2 > y1)
            {
                y1 = y2;
            }
        }

        j++;
    }
    // Letzte Range wird verrechnet und aufaddiert
    counter += (y1 - x1 + 1);

    std::cout << "\n" << counter;

    file.close();

    return 0;
}
