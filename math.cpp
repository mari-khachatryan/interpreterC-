#include <iostream> 
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>

void addition(std::string a) {
    std::string additive;
    int additiveInt;
    float additiveFloat;
    std::string additiveStr;
    std::string firstAdd;
    std::string seconAdd;
    int start = 0;
    size_t pos = a.find("+");
    size_t endPos = a.find("=");
    int end = endPos - pos;
    firstAdd = a.substr(start, pos - 1);
    seconAdd = a.substr(pos + 2, end - 3);
    // additiveInt = stoi(firstAdd) + stoi(seconAdd);
    // additiveFloat = stod(firstAdd) + stod(seconAdd);

    for(int i = 0, j = 0; i < firstAdd.length(), j < seconAdd.length(); i++, j++) {
      if(isdigit(firstAdd[i]) && isdigit(seconAdd[j])) {
            int add;
            add = stoi(firstAdd) + stoi(seconAdd);
            additive = std::to_string(add); 
            std::cout << firstAdd << " + " << seconAdd << " = " << add << std::endl;
      } else if ((firstAdd.find(".") != std::string::npos) && (seconAdd.find(".") != std::string::npos)) {
            std::size_t firstPos;
            std::size_t secondPos;
            firstPos = firstAdd.find(".");
            secondPos = seconAdd.find(".");
            if((isdigit(firstAdd[i]) || i == firstPos) && (isdigit(seconAdd[j]) || j == secondPos)) {
                    float addf;
                    addf = stof(firstAdd) + stof(seconAdd);
                    additive = std::to_string(addf); 
                    std::cout << firstAdd << " + " << seconAdd << " = " << addf << std::endl;
            } else {
                    std::cout << "the addition don't allow" << std::endl;
                    exit(0);

            }
      } else {
        std::cout << "the addition don't allow" << std::endl;
                    exit(0);
      }
    }
      
   //return additive;
 }

int main() {  
    std::ifstream myfile;
    myfile.open("nowCode.txt");  
    std::string codeLine;
    std::string str = "";
    std::string nowLine;
    if(!myfile.is_open())
    {
       std::cout << "Could not open the file " << std::endl;
       std::cout << "Program terminating.\n";
    } else {
        while (!myfile.eof())
    {
      myfile >> codeLine;
      if(codeLine != "|") {
      str += codeLine + " ";
      codeLine.clear();
      } else {
         str += codeLine  + '\n';
         codeLine.clear();
      }
    }
    }
int a = 8;
    
    //std::cout << str << std::endl;
    if(str.find("+") != std::string::npos) {
        addition(str);
    }

    return 0;
}