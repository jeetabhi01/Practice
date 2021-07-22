#include<iostream>

using namespace std;

int main()

{
int m,n;
int* ptrint;
int** Ptrptrint;
Ptrptrint = &ptrint;
cout<<"enter the input value of 'n'= "<<endl;
cin>>n;
ptrint = &n;
cout<<*(*Ptrptrint)<<endl;

cout<<"enter the input value of 'm'= "<<endl;
cin>>m;
ptrint=&m;
cout<<*(*Ptrptrint)<<endl;
return 0;
}
