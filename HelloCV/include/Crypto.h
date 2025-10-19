#ifndef CRYPTO_H
#define CRYPTO_H
#include <iostream>
using namespace std;
class crypto{
public:
static string encrypt (const string& text,int key);
static string decrypt (const string& text,int key);
};
#endif