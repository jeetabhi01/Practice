#include<iostream>

using namespace std;
int *readQuizmarks(int &n);
int main()
{
 int numstudents;
 int *  A;
 cin>>numstudents;
 //A = new int[numstudents];
 
 /*if (A==NULL)
 cout<<"Null pointer encountered"<<endl;
 else
 */
 A    = readQuizmarks(numstudents);
delete  []A;
 return 0;
 }
 
 int * readQuizmarks(int &n)
 {
 int *marks;
 
 marks = new int[n];
 if (marks!=NULL)
 {for(int i=0; i<n;i++)
 cin>>marks[i];
 for(int i=0; i<n;i++)
 cout<<"Marks{"<<i+1<<"]="<<marks[i]<<endl;
 return(marks);}
 else {cout<<"Program crashed";
 return NULL;}}
