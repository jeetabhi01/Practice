#include<bits/stdc++.h>
#include<cmath>

using namespace std;

inline double fast(double &m, int n) 
{
   return (pow(m,n));
 }
 
 void display(double &k)
 {
 cout<<k<<endl;
 return;
 }
 
 signed main()
 { int power;
  double num, ans;
  char answer;
  cout <<" Enter the number"<<endl;
  cin>>num;
  cout<<"Do you want to give the power manually Y/N?"<<endl;
  cin>>answer;
  switch(answer)
  {
   case 'Y': cin>>power; 
  ans = fast(num, power);break;
   default :
   power=2;
  ans = fast(num,power);
   }
   display(ans);
   return 0;
   }