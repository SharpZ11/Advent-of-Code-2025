#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <set>

int main(){

    std::ifstream file("ids.txt");
    std::string line;
    std::vector<std::string> idRanges;
    std::vector<std::string> ingredientIds;

    std::set<long long> counter;

    while(getline(file,line)){

        if(line.find("-") != std::string::npos){
            idRanges.push_back(line);
        } else if(!line.empty()) {
            ingredientIds.push_back(line);
        }

    }

    for (std::string id : ingredientIds){

        //std::cout << "Current Id: " << id << "\n";
        long long idNum = stoll(id);

        for(std:: string range : idRanges){

           //std::cout << "Current Range: " << range << "\n";

            std::string start = range.substr(0,range.find("-")); ;
            std::string end = range.substr(range.find("-")+1, range.size());
            

            long long startNum = stoll(start);
            long long endNum = stoll(end);


            // In ID Range
            if(idNum >= startNum && idNum <= endNum){
                counter.insert(idNum);
                //std::cout << "Variable gefunden" << idNum << "\n";
            }

        }
    }

    std::cout << counter.size();

    return 0;
}