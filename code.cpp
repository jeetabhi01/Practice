#include<iostream>
//Pragma Optimisations
#pragma GCC optimise("Os")
#pragma GCC optimise("O2")
#pragma GCC optimise("unroll-loops")
#pragma GCC target("avx2")

//Libraries
#include<bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define nl " \n"
#define  fr(i,a,n) for(int i; i < n; i++)
#define rfr(i,a,n) for(int i  ; i>= n   ; i--)
#define ll long long int
#define MOD 1E9+7

void sync() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void solve();

signed main() {
	sync();
	int t=1;
	cin>>t;
	while(t--)
	solve();

return 0 ;
}

void solve(){

}
