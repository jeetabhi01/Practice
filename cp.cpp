//Optimisations
#pragma GCC optimise("O2")
#pragma GCC optimise("Os")
#pragma GCC optimise("unroll-loops")
#pragma GCC target("avx2")

//Libraries
#include<bits/stdc++.h>
#include<cstdio>
//Definitions
using namespace std;
#define nl " \n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fr(i,a,n) for(int i=a; i<n; i++)
#define rfr(i,a,n) for(int i=a;i>=n;i--)
#define ll long long int

void solve();
signed main(){
	fast;
/*  #ifndef	ONLINE_JUDGE
	freopen("C://input.txt","r",stdin)
	freopen("C://output.txt","w",stdout)
	#endif	
		*/
	solve();
	return 0;
	} 
	
void solve(){
	int X;
	double Y;
	
	cin>>X>>Y;
	if((X%5==0)&&(Y>X)){
	Y = Y - (static_cast<double>(X))-0.50;
	printf("%.2f",Y);
	}
	else
	printf("%.2f",Y);
	return;
	}
	
		
