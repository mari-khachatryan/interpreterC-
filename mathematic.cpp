#include <iostream> 
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>

int sum (int a, int b) {
    return a + b;
}
int sub (int a, int b) {
    return a - b;
}
int mul (int a, int b) {
    return a * b;
}
int divison (int a, int b) {
    if(b == 0) {
        std::cout << "error!!, the divison by 0 not allow" << "\n";
        exit(0);
    }
    return a / b;
}
int mod (int a, int b) {
    if(b == 0) {
        std::cout << "error!!, the divison by 0 not allow" << "\n";
        exit(0);
    }
    return a % b;
}
double sumd (double a, double b) {
    return a + b;
}
double subd (double a, double b) {
    return a - b;
}
double muld (double a, double b) {
    return a * b;
}
double divd (double a, double b) {
    if(b == 0) {
        std::cout << "error!!, the divison by 0 not allow" << "\n";
        exit(0);
    }    
    return a / b;
}
std::string sumStr (std::string a, std::string b) {
    return a + b;
}

std::string firstpart(std::string a){
    std::string firstPlace;
    char n;
    for(int i = 0; i < a.length(); i++) {
        if(a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '%') {
            n = a[i];
        }
    }
    int i, j, k;
    i = a.find("=");
    j = a.find(n);
    k = j - i;
    firstPlace = a.substr(i + 2, k - 3);
    return firstPlace;
}
std::string secondpart (std::string a) {
    std::string secondPlace;
    char n;
    for(int i = 0; i < a.length(); i++) {
        if(a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/' || a[i] == '%') {
            n = a[i];
        }
    }
    int i, j, k;
    i = a.find(n);
    j = a.find("|");
    k = j - i;
    secondPlace = a.substr(i + 2, k - 2);
    return secondPlace;
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
 std::string mytype;
 if (str.find("+") != std::string::npos || str.find("-") != std::string::npos ||
     str.find("*") != std::string::npos || str.find("/") != std::string::npos || str.find("%") != std::string::npos) {
   if(str.find("well") == std::string::npos) {
    std::cout << "incorect declaretion" << std::endl;
    exit(0);
   } 
   std::size_t firstPos; 
   firstPos = str.find("well") + 5;
   std::size_t secondPos;
   if(str.find("str") != std::string::npos) {
      secondPos = 3; 
   } else if (str.find("int") != std::string::npos){
      secondPos = 3;
   } else if (str.find("double") != std::string::npos) {
       secondPos = 6;
   } else {
      std::cout << "you haven't any declaration" << std::endl;
      return 0;
   }
   mytype = str.substr(firstPos, secondPos);
     }   
 
    if(mytype == "int") {
        std::string firstNum = firstpart(str);
        std::string secundNum = secondpart(str);
        for(int i = 0; i < firstNum.length(); i++) {
            if(!isdigit(firstNum[i])){
                std::cout << "first number is not int" << std::endl;
                exit(0);
            }
        }
        for(int i = 0; i < secundNum.length(); i++) {
            if(!isdigit(secundNum[i])){
                std::cout << "second number is not int" << std::endl;
                exit(0);
            }
            char n;
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%') {
                n = str[i];
            }
        }
        switch (n)
        {
        case '+':
            std::cout << firstNum << " + " << secundNum << " = " << sum(stoi(firstNum), stoi(secundNum)) << std::endl; 
            break;
        case '-':
            std::cout << firstNum << " - " << secundNum << " = " << sub(stoi(firstNum), stoi(secundNum)) << std::endl; 
            break;    
        case '*':
            std::cout << firstNum << " * " << secundNum << " = " << mul(stoi(firstNum), stoi(secundNum)) << std::endl; 
            break;
        case '/':
            std::cout << firstNum << " / " << secundNum << " = " << divison(stoi(firstNum), stoi(secundNum)) << std::endl; 
            break;
        case '%':
            std::cout << firstNum << " % " << secundNum << " = " << mod(stoi(firstNum), stoi(secundNum)) << std::endl; 
            break;
        default:
            break;
        }    
    }
    }

    if(mytype == "double") {
        std::string firstNum = firstpart(str);
        std::string secundNum = secondpart(str);
        char n;
        for(int i = 0; i < firstNum.length(); i++) {
            if(!isdigit(firstNum[i]) && firstNum[i] != '.' || firstNum.find(".") == std::string::npos){
                std::cout << "second number type is not double" << std::endl;
                exit(0);
            }
        }
        for(int i = 0; i < secundNum.length(); i++) {
            if(!isdigit(secundNum[i]) && secundNum[i] != '.' || secundNum.find(".") == std::string::npos) {
                std::cout << "second number type is not double" << std::endl;
                exit(0);
            }       
        }
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%') {
                n = str[i];
                if(n == '%'){
                    std::cout << "not defined" <<"\n";
                    exit(0);
                }
            }
        }
        switch (n)
        {
        case '+':
            std::cout << firstNum << " + " << secundNum << " = " << sumd(stod(firstNum), stod(secundNum)) << std::endl; 
            break;
        case '-':
            std::cout << firstNum << " - " << secundNum << " = " << subd(stod(firstNum), stod(secundNum)) << std::endl; 
            break;    
        case '*':
            std::cout << firstNum << " * " << secundNum << " = " << muld(stod(firstNum), stod(secundNum)) << std::endl; 
            break;
        case '/':
            std::cout << firstNum << " / " << secundNum << " = " << divd(stod(firstNum), stod(secundNum)) << std::endl; 
            break;
        default:
            break;
        }      
}

if(mytype == "str") {
    std::string firstStr = firstpart(str);
    std::string secundStr = secondpart(str);
    char n;
    if(firstStr[0] != '"' || firstStr[firstStr.length() - 1] != '"'){
       std::cout << "Error!, first operand is not string" << "\n";
       exit(0);
    }
    if(secundStr[0] != '"' || secundStr[secundStr.length() - 1] != '"'){
       std::cout << "Error!, the second operand is not string" << "\n";
    }
    int i = firstStr.length() - 1;
    int j = secundStr[0];
    std::string newfirstStr;
    newfirstStr = firstStr.substr(0, i);
    std::string newsecundStr;
    newsecundStr = secundStr.substr(1);
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%') {
                n = str[i];
                if(n == '%' || n == '-' || n == '/' || n == '*'){
                    std::cout << "not defined" <<"\n";
                    exit(0);
                }
            }
        }
    switch (n)
    {
    case '+':
        std::cout << firstStr << " + " << secundStr << " = " << sumStr(newfirstStr, newsecundStr) << std::endl; 
        break;
    default:
        break;
    }      
}

return 0;
}