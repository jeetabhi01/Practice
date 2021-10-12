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

for(int i =0 ; i < M ; i++){
  for(int j = 0 ; j < N ;j++){
    cout<<matrix[i][j]<<" ";
  }
    cout<<endl;
}
displaymatrix(matrix,M,N);
for(int i =0 ; i < M; i++){
  delete matrix[i];
}
delete matrix;
return 0;}

int ** readmatrix(int m, int n)
{
	int **memalloc;
	
      memalloc = new int * [m];
      for(int i = 0; i < m; i++){
        memalloc[i] = new int[n];
      }
      if (memalloc != NULL)
      {      
         for ( int i=0; i<m;i++){
            
            for (int j=0;j<n;j++)
              cin>>memalloc[i][j];
           }
          return (memalloc);
       }    
       cout<<"Couldn't allocate memory"<<endl;
       return NULL;

 }       
 void displaymatrix(int **k, int m, int n)
     {  
        cout<<m<<" "<<n<<endl;
        for(int i=0; i<m; i++)
           { cout<<endl;
             for(int j=0;j<n;j++)
             cout<<k[i][j]<<" ";
            } return;
      }       
