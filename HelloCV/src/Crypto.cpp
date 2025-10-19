#include "Crypto.h"
#include <iostream>
using namespace std;
string crypto::encrypt(const string& text,int key){
string result=text;
for(int i=0;i<result.length();i++){
    char c=result[i];
    if((c>=65)&&(c<=90)){
        c=(c-65+key)%26+65;
    }
    if((c>=97)&&(c<=122)){
        c=(c-97+key)%26+97;
    }
    result[i]=c;
}
return result;
}
string crypto:: decrypt(const string& text,int key){
    return encrypt(text,26-(key %26));
}

