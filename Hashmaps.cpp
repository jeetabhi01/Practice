#include<iostream>
#include"Hashmaps.h"


int main(){
    string key  = "abc";
    char c = '0';
    Ourmap<int> a;
    for(int i = 0 ; i < 10 ; i++){
        c = c + i;
        key = key + c;
        a.insert(key, i+1);
        std::cout<<a.Getloadfactor()<<std::endl;
        cout<<a.size()<<std::endl;
    }
    return 0;
}