#include<iostream>

using namespace std;

int ** readmatrix( int m, int n);

void displaymatrix(int **k, int m, int n);

int main()
{
int **matrix;
int M,N;

cout<<"Enter the number of rows m = ";
cin>>M;
cout<<endl<<"Enter the number of columns n = ";
cin>>N;

matrix = readmatrix(M,N);
displaymatrix(matrix,M,N);
delete [][] matrix;
return 0;}

int ** readmatrix(int m, int n)
{
	int **memalloc;
	
      memalloc = new int[m][n];
      if (memalloc != NULL)
      {
      
         for ( int i=0; i<m;i++)
           { for (int j=0;j<n;j++)
            cin>>memalloc[i][j];
           return (memalloc);
           
           }
       }    
       else
        {
          cout<<"Couldn't allocate memory"<<endl;
          return NULL;
         }
 }       
 void displaymatrix(int **k, int m, int n)
     {
        for(int i=0; i<m; i++)
           { cout<<endl;
             for(int j=0;j<n;j++)
             cout<<k[i][j]<<" ";
            } return;
      }       
