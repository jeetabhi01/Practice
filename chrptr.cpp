#include<iostream>

using namespace std;

int main()

{
  
char charr[] = "TEXT";
int arr[3] = {1,2,3};
char * chrptr;
chrptr = charr;

cout<<*chrptr<<endl;
cout<< static_cast<const void*>(chrptr)<<endl;
cout<<charr<<endl;

cout<<&(*chrptr)<<endl;
return 0;}
