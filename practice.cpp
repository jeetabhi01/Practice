#include<iostream>

using namespace std;

int main()

{
int a;
float b;char c; int *ptrA;
float * ptrB; char * ptrC;
a= 0x02abc;
ptrA=&a;

ptrB=&b;

ptrC=&c;

cout<<"Address of a is "<<ptrA<<endl;
cout<<"value at the Address of a is "<<*ptrA<<endl;

cout<<"Address of b is "<<ptrB<<endl;

cout<<"Address of c is "<<ptrC<<endl;
return 0;}
