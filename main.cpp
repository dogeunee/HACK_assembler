#include "include/Parser.h"
#include "include/Code.h"
#include "include/Symbol.h"

int main(){
    Parser parser;
    Code code;
    Symbol symbol;
    parser.open("asm_code/Pong.asm");

    //first pass
    while(!parser.endOfLine()){
        parser.nextLine();
        enum commandType ctype = parser.commandType();
        if(ctype==commandType::S){
            string sym = parser.symbolReturn();
            string rowNum = to_string(parser.rowNumReturn()+1);
            symbol.addToTable(sym, rowNum);
            //cout<< "symbol: "<<sym<<" "<<rowNum<<"main.cpp.firstpass\n";
        }
    }

    parser.to_firstline();

    //second pass
    while(!parser.endOfLine()){
        parser.nextLine();
        enum commandType ctype = parser.commandType();
        if(ctype!=commandType::S){
        string binCode="" ;
        if(ctype==commandType::A){
            binCode.append("0");
            string l=parser.labelReturn();
            if(!parser.is_label_number()){//symbol is a var
                if(!symbol.in_table(l)){//symbol is not in table therefore must make a new var and alocate address 
                    symbol.addNewVar(l);
                }
                l=symbol.returnAddr(l);
            }
            binCode.append(code.label(l));
        }else if(ctype==commandType::C){
            
            parser.C_seperator();
            binCode.append("111");
            string c = parser.compReturn();
            string d = parser.destReturn();
            string j = parser.jumpReturn();
            binCode.append(code.comp(c));
            binCode.append(code.dest(d));
            binCode.append(code.jump(j));
        }
        binCode.append("\n");
        parser.write(binCode);
        //cout<<binCode;
        
    }
    }
    return 0;
}
