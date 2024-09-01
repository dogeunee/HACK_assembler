#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype> 
using namespace std;

enum commandType{A,C,S};
class Parser{
    private:
   
    string dest, comp, jump, label;
    int rowNum;
    ifstream ifile;
    ofstream ofile;
    string current_line;
    enum commandType cType;
    

	public:
    ~Parser();
    
    void open(string s);
    
    bool endOfLine();
    void nextLine();
    enum commandType commandType();
    void C_seperator();
    string destReturn();
    string compReturn();
    string jumpReturn();
    string labelReturn();

    void write(string s);

    std::vector<std::string> split(const std::string& str, const std::string& delimiter);

    bool is_label_number();
    string symbolReturn();
    int rowNumReturn();
    void to_firstline();
};