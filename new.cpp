//               ReadMe
//լեզվի անունը կարելի է դնել c+js, քանի որ կան տրամաբանական տարրեր c++ -ից և js -ից
//նոր փոփոխական հայտարարում եմ well keyword-ով, օրինակ՝ well double x = 1.2|
//կա 3 տիպի փոփոխական int, double, str
//str-ն գրվում է չակերտներով, օրինակ՝ "mar", բայց ոչ 'mar'
//արտահայտությունը ավարտվում է "|" նշանով
//while ցիկլերը անվանում եմ cicle օրինակ՝ cicle(1 == 1){tpi ut}|
//for` bicycle օրինակ՝ bicycle(i = 1|true|i++){tpi ut}

#include <iostream> 
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

//------>well - ով փոփոխական հայտարարման լոգիկան այստեղից սկսվում է 
std::string functype(std::string a) {
   std::size_t firstPos; 
   firstPos = a.find("well") + 5;
   std::size_t secondPos;
   if(a.find("str") != std::string::npos) {
      secondPos = 3; 
   } else if (a.find("int") != std::string::npos){
      secondPos = 3;
   } else if (a.find("double") != std::string::npos) {
       secondPos = 6;
   } else {
      std::cout << "you haven't any declaration" << std::endl;
      exit(0);
   }
   std::string mytype;
   mytype = a.substr(firstPos, secondPos);
  return mytype; 
}

std::string funcdeclar(std::string b) {
   int start = b.find("well");
   int slid = 4;      
   std::string declaration;
   declaration = b.substr(start, slid);

   if(start == std::string::npos) {
      std::cout << "incorect declaration word, mabie you main 'well'" << std::endl;
      return 0;
   } 
   return declaration;
}

std::string funcvarname(std::string c) {
   std::size_t firstPos;
   std::size_t secondPos;
   std::size_t pos;
   if(c.find("str") != std::string::npos) {
      firstPos = c.find("str") + 4; 
   } else if (c.find("int") != std::string::npos){
      firstPos = c.find("int") + 4;
   } else if (c.find("double") != std::string::npos) {
       firstPos =c.find("double") + 6;
   } else {
      std::cout << "you haven't any declaration" << std::endl;
      exit(0);
   } 
   if(c.find(" =") != std::string::npos){
     secondPos = c.find(" =");
   } else {
      std::cout << "no space" << std::endl;
   }
   pos = secondPos - firstPos;
   std::string variable;
   variable = c.substr(firstPos, pos);
   if(pos != std::string::npos) {
        if(isdigit(variable[0])){
            std::cout << "Variable can't start with digit" << std::endl;
            exit(0);
        }
   } else {
      std::cout << "You forgote '=' sing";
      exit(0);
   }
   return variable; 
}

std::string funcVar(std::string d) {
   size_t start;
   size_t slice;
   int pos;
   start = d.find("=") + 2;
   slice = d.find("|");
   pos = slice - start;
   std::string variable;
   variable = d.substr(start, pos);
   return variable;
}

int func1(std::string a, std::string d) {
   if(a == "int") {
   for(int i = 0; i < d.length() - 1; i++) {
      if(!isdigit(d[i])) {
      std::cout << d << " you declarate an integer, but write not interger" << std::endl;
      exit(0);
      } 
   }
   }
   
   if(a == "double") {
        if(d.find(".") != std::string::npos) { 
         std::size_t pointPos;
         pointPos = d.find(".");
         for(int i = 0; i < d.length() - 3; i++) {
          if (!isdigit(d[i]) && i != pointPos) {
            std::cout << i << " u " << pointPos  << "number " << d[i] << std::endl;
               std::cout << d << " this is not float number" << std::endl;
               exit(0);
            }
         }
      } else {
         std::cout << "you entered not float number" << std::endl;
         exit(0);
      }  
   }
   if(a == "str") {
      std::size_t secondPos;
      if ((d[0] != '"') || d[d.length() - 1] != '"') {
         std::cout << "Error!, the veribol its not string " << std::endl;
         exit(0);
      }
   }
   return 1;
}
//------>well - ով փոփոխական հայտարարման լոգիկան այստեղ ավարտվում է 

//------>if - ի լոգիկան այստեղից սկսվում է
std::string func1(std::string a) {
  int start = 0;
size_t pos;
pos = a.find("(");
std::string keyWord;
keyWord = a.substr(start, pos);
if(a.find("(") == std::string::npos) {
   std::cout << "Incorect declaration maybe you have forgotten '(' sign" << std::endl;
} 
return keyWord;
}

std::string func2(std::string b) {
   std::string exp;
   size_t firstPos;
   size_t secondPos;
   firstPos = b.find("(") + 1;
   secondPos = b.find(")") - b.find("(") -1;
   exp = b.substr(firstPos, secondPos);
return exp;
}

std::string checkExpFunc(std::string c) {
   std::string boolExp;
   if((c.find("!=") == std::string::npos) && (c.find("==") == std::string::npos) && (c.find(">") == std::string::npos)
   && (c.find(">=") == std::string::npos) && (c.find("<") == std::string::npos) && (c.find("<=") == std::string::npos)) {
            if(c == "true" || (c != "" && c != "0") ) {
               boolExp = "true";
            } else if (c == "false" || c == "0" || c == "") {
               boolExp = "false";
            } else {
               boolExp = "true";
            }
   } else {
            if(c.find("==") != std::string::npos) {
               std::string onePos;
               std::string twoPos;
               size_t midelPos;
               int start = 0;
               midelPos = c.find("==");
               onePos = c.substr(start, midelPos - 1);
               twoPos = c.substr(midelPos + 2);
               if(onePos.find("+") && onePos.find("-") && onePos.find("*") && onePos.find("/") && onePos.find("%") && onePos.find("=") ){
                   std::cout << "Error!, not defined";
                   exit(0);
               } else if (twoPos.find("+") && twoPos.find("-") && twoPos.find("*") && twoPos.find("/") && twoPos.find("%") && onePos.find("=")){
                  std::cout << "Error!, not defined";
                   exit(0);
               } else {
                     if(onePos == twoPos) {
                     boolExp = "true";
                     } else {
                     boolExp = "false";
                     }
               }
            } else if (c.find("!=") != std::string::npos)
            {
               
            } else if (c.find("<") != std::string::npos)
            {
              
            } else if(c.find("<=") != std::string::npos) 
            {

            } else if (c.find(">") != std::string::npos)
            {
               
            } else if(c.find(">=") != std::string::npos){

            }
   }              
   return boolExp;
}

std::string doBody(std::string d) {
   std::string body;
   size_t bodyStart;
   size_t bodyEnd;
   int pos;
   bodyStart = d.find("{") + 1;
   bodyEnd = d.find("}");
   pos = bodyEnd - bodyStart;
   body = d.substr(bodyStart, pos);
   return body;
}
//------>if - ի լոգիկան այստեղ ավարտվում է 
 
//------>while - ի լոգիկան այստեղից սկսվում է
 std::string condition(std::string a) {
   std::string condition;
   size_t firstPos;
   size_t endPos;
   size_t pos;
   firstPos = a.find("(") + 1;
   endPos = a.find(")");
   if(a.find("(") == std::string::npos || a.find(")") == std::string::npos) {
      std::cout << "Error!, unexpected token ( or )" << std::endl;
      exit(0);
   }
   pos = endPos - firstPos;
   if(pos == 0) {
      std::cout << "no condition" << std::endl;
      exit(0);
   }
   condition = a.substr(firstPos, pos);
   return condition;
 }

 std::string bodyfunc(std::string b){
   std::string body;
   size_t bodyStart;
   size_t bodyEnd;
   int pos;
   bodyStart = b.find("{") + 1;
   bodyEnd = b.find("}");
   if(b.find("{") == std::string::npos || b.find("}") == std::string::npos) {
      std::cout << "Error!, unexpected token { or }" << std::endl;
      exit(0);
   }
   pos = bodyEnd - bodyStart;
   if(pos == 0) {
      std::cout << "no body" << std::endl;
      exit(0);
   }
   body = b.substr(bodyStart, pos);
   if(body == " ") {
      std::cout << "no body" << std::endl;
      exit(0);
   }
   return body;
 }
//------>while - ի լոգիկան այստեղ ավարտվում է

//------>for - ի լոգիկան այստեղից սկսվում է
std::string conditAnalysisType(std::string a) {
std::string type;
   size_t typeStart = 0;
   size_t typeEnd;
   typeEnd = a.find("|");
   int pos;
   type = a.substr(typeStart, typeEnd);
   return type;
}

std::string conditAnalysisCondition(std::string b) {
   std::string condition;
   std::string secondPart;
   size_t conStart;
   size_t conEnd;
   conStart = b.find("|") + 1;
   secondPart = b.substr(conStart);
   int i;
   i = secondPart.find("|");
   condition = secondPart.substr(0, i);
   return condition;
}

std::string conditAnalysisValue(std::string b) {
   std::string value;
   std::string secondPart;
   size_t conStart;
   size_t conEnd;
   conStart = b.find("|") + 1;
   secondPart = b.substr(conStart);
   int i;
   i = secondPart.find("|");
   value = secondPart.substr(i + 1);
   return value;
}

//------>for - ի լոգիկան այստեղ ավարտվում է


std::string actionCeck(std::string textLine)
{
   int start = 0;
   size_t pos;
   if(textLine.find("(") != std::string::npos) {
      pos = textLine.find("(");  
   } else {
      pos = textLine.find(" ");  
   }   
   std::string firstWord;
   firstWord = textLine.substr(start, pos);
   return firstWord;
}
void checkParametrs(std::string a) {
   if(a.find("|") != std::string::npos) {   
   } else {
       std::cout << "Invalid code, please put '|' sign" << '\n';
   }
   if(a.find("well") != std::string::npos) {
   } else {
      std::cout << "Invalid code, please put 'well' declar word" << '\n';
   }
   if(a.find("=") != std::string::npos) {
   } else {
      std::cout << "Invalid code, please put '=' declar word" << '\n';
   }
}
    
int main() {  
    std::ifstream myfile;
    std::vector<std::string> vec;
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
      // vec.push_back(codeLine);
      //codeLine.clear();
      // for(int i = 0; i < vec.size(); ++i)
      // {
      //    std::cout << vec[i] << std::endl;
      // }
      codeLine.clear();
      } else {
         str += codeLine  + '\n';
         codeLine.clear();
    }
    }
    }

    std::string firstWord = actionCeck(str);

  if(firstWord == "well") {
     //std::cout << "our string " << str << std::endl;
     checkParametrs(str);
     std::string myDeclar = funcdeclar(str);
     std::string myType = functype(str);
     std::string myVarName = funcvarname(str);
     std::string myVariable = funcVar(str);

   std::cout << myDeclar << " " << myType << " " << myVarName <<  " = "  <<  myVariable << "|" << std::endl;

     func1(myType, myVariable);
     if (myType == "int") {
       stoi(myVariable);
     }
     if (myType == "float") {
       stof(myVariable);
     }
  }

  if(firstWord == "if") {
    std::string keyWord = func1(str);
    std::string expression = func2(str);
    std::string checkExp = checkExpFunc(expression);
    std::string body = doBody(str);

  std::cout << keyWord  << "(" <<expression << ")" << "{" << body << "}" << std::endl;
  std::cout << "bool is: " << checkExp << std::endl;
   bool value;
   if(expression == "true") {
      if(true) {
         body;
      }
   } else {
      if(false) {
        body;
      }
   }
  }

  if(firstWord == "cicle") {

    std::string condit = condition(str);
    std::string body = bodyfunc(str);
    std::cout <<firstWord << "(" << condit << ")" << "{" << body << "}" << std::endl;
  
  }

  if(firstWord == "bicycle") {
    std::string condit = condition(str);
    std::string body = bodyfunc(str);

    std::string conditType  = conditAnalysisType(condit);
    std::string conditCondition  = conditAnalysisCondition(condit);
    std::string conditvalue  = conditAnalysisValue(condit);
    
    std::cout << firstWord << "(" << condit << ")"  << "{" << body << "}" << std::endl;
    std::cout << "type is: " << conditType << std::endl;
    std::cout << "condition is: " << conditCondition << std::endl;
    std::cout << "value is: " << conditvalue << std::endl;
  }

  if(firstWord != "well" && (firstWord != "if") && (firstWord != "cicle") && (firstWord != "bicycle")) {
   std::cout << "Error!, incorect code" << std::endl;
   exit(0);
  }
 return 0;    
}
