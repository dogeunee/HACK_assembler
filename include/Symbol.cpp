#include "Symbol.h"
bool Symbol::in_table(string key){
    auto it = SymbolTable.find(key);
    return it != SymbolTable.end();
}
void Symbol::addToTable(string symbol,string num){
    SymbolTable.insert({symbol,num});
}
string Symbol::returnAddr(string symbol){
    auto it = SymbolTable.find(symbol); // Look for the key in the SymbolTable
    return it->second; // Return the value if found
}

void Symbol::addNewVar(string var){
    addToTable(var,to_string(n++));
}