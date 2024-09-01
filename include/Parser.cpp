#include "Parser.h"
    Parser::~Parser(){
        ifile.close();
        ofile.close();
    }
    void Parser::open(string s){
        ifile.open(s);
        ofile.open("result.hex");
        rowNum=-1;
    }
    bool Parser::endOfLine(){
        return ifile.eof();
    }
    void Parser::nextLine(){
        getline(ifile, current_line);
        current_line.erase(remove_if(current_line.begin(), current_line.end(), ::isspace), current_line.end());
        while(current_line.size()==0||current_line[0]=='/'){
            getline(ifile, current_line);
            current_line.erase(remove_if(current_line.begin(), current_line.end(), ::isspace), current_line.end());
        }
        if(current_line[0]!='('){
            rowNum++;
            //cout<<current_line<<", rownum: "<<rowNum<< "-Parcer.cpp.nextLine()\n";
        }else{
            
        }
        
    }
    enum commandType Parser::commandType(){
        if(current_line[0]=='@'){
            return commandType::A;
        }else if(current_line[0]=='('){
            return commandType::S;
        }else
            return commandType::C;
    }

    //A=B;C B;C A=B
    void Parser::C_seperator(){
        /*auto new_end = remove_if(current_line.begin(), current_line.end(), [](char c) {
        return isspace(static_cast<unsigned char>(c));
        });

    // Erase the spaces from the end
        current_line.erase(new_end, current_line.end());*/

        std::vector<std::string> result = split(current_line, "=");
        if(result.size()==2)dest = result[0]; 
        else dest="null";
        std::vector<std::string> second = split(result.back(),";");
        if(second.size()==2){
            comp=second[0];
            jump=second[1];
        }else{
            comp=second[0];
            jump="null";
        }
        //cout<<"(c,d,j): ("<<comp<<","<<dest<<","<<jump<<")"<<"  -Parser.C_seperator()\n";
    }

    string Parser::destReturn(){
        return dest;
    }
    string Parser::compReturn(){
        return comp;
    }
    string Parser::jumpReturn(){
        return jump;
    }
    string Parser::labelReturn(){
        current_line.erase(0, 1);
        return current_line;
    }

    bool Parser::is_label_number()
    {
        string s = current_line;
        std::string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    }

    void Parser::write(string s){
        ofile<<s;
    }

std::vector<std::string> Parser::split(const std::string& str, const std::string& delimiter) {
    std::vector<std::string> tokens;
    std::string s = str;
    size_t pos = 0;
    std::string token;

    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        tokens.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    tokens.push_back(s); // Add the last token

    return tokens;
}

string Parser::symbolReturn(){
    current_line.erase(0, 1);
    current_line.erase(current_line.length() - 1, 1);
    return current_line;
}
int Parser::rowNumReturn(){
    return rowNum;
}
void Parser::to_firstline(){
    ifile.clear();
    ifile.seekg(0);
    rowNum=-1;
}
