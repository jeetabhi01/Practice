#include<bits/stdc++.h>

using namespace std;
	
int32_t main(){
	int n, clearbit;
	cin>>n>>clearbit;
	n &= ~(1<<clearbit);
	cout<<n<<endl;	
return 0;
}
