#include "FileHandler.h"
#include <fstream>
using namespace std;
bool FileHandler::read(const string& filepath,string& content){
    ifstream file(filepath);
    if(!file.is_open())    {
        return false;
    }
    string line;
    content=" ";
    while(getline(file,line)){
        content=line+"\n";
        }
        file.close();
        return true;
    }
    bool FileHandler::write(const string& filepath,const string &content){
        ofstream file(filepath);
        if(!file.is_open()){
            return false;
        }
        file<<content;
        file.close();
        return true;
    }