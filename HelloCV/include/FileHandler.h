#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <iostream>
#include <string>
using namespace std;
class FileHandler{
public:
static bool read(const string& filepath,string& content);
static bool write(const string& filepath,const string &content);
};
#endif
