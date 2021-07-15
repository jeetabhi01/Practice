#include<iostream>

using namespace std;

class Shape{ 
    protected:
    int numberofsides = 0;	
    virtual int getnumsides() = 0;
};


class Rectangle:public Shape{
  public: 
    Rectangle:numberofsides(x)(int x){
    }
    return;
    int getnumsides(){
      return numberofsides;
    }
};


