#include "Code.h"

string Code::dest(string d){
    // Define the mapping of string values to binary strings

    // Find the value in the map
    auto it = destMap.find(d);
    
    // Return the corresponding binary string if found, otherwise return a default value
    if (it != destMap.end()) {
        return it->second;
    }
    
    return "222";  // Default value for unrecognized strings
}

string Code::comp(string c){

    // Find the value in the map
    auto it = binaryMap.find(c);
    
    // Return the corresponding binary string if found, otherwise return a default value
    if (it != binaryMap.end()) {
        return it->second;
    }
    
    return "2222222";  // Default value for unrecognized strings

}
string Code::jump(string j){

    // Find the value in the map
    auto it = jumpMap.find(j);
    
    // Return the corresponding binary string if found, otherwise return a default value
    if (it != jumpMap.end()) {
        return it->second;
    }
    
    return "222";
}

string Code::label(string l){
    int num = stoi(l);
    std::bitset<15> binary(num);
    return binary.to_string();
}
