//Pragma Optimisations
#pragma GCC optimise("Os")
#pragma GCC optimise("O2")
#pragma GCC optimise("unroll-loops")
#pragma GCC target("avx2")
#pragma GCC target("sse4")

//Libraries
#include<bits/stdc++.h>

using namespace std;

#define fast            ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define int             long long int
#define mod            (int) 10E9+7L
#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define eb              emplace_back
#define nl 				"\n"
#define inf				1e18
#define setbits(x)		__builtin_popcountll(x)
#define zerobits(x)		__builtin_ctzll(x)

template<typename T1,typename T2>
inline std::ostream &operator<<(std::ostream &os, const std::pair<T1,T2> p) {
	return os<<"{"<<p.ff<<", "<<p.ss<<"}";
}

template<typename T>
int binarysearch(std::vector<T> arr, int start, int end, T key) {
	int mid = (start + end)/2;
	if(arr[mid]== key) {
		return mid;
	}
	else if(key < arr[mid]) {
		return binarysearch(arr,start,mid -1, key);
	}
	else
		return binarysearch(arr,mid+1,end,key);

}


int fastpow(int base, int n) {
	int res = 1;
	// cout<<"power function called\n";
	while(n > 0) {
		if(n & 1) {
			res *= base;
		}
		base *= base;
		n = n >> 1;
	}
	return res;
}

void sync() {
	fast;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
template <typename T>
inline std::ostream &operator<<(std::ostream &os,const std::vector<T> &v) {
	bool first = true;
	os<<"[";
	for(unsigned int i = 0 ; i < v.size(); i++) {
		if(!first)
			os<<",";
		cout<<v[i];
		first = false;
	}

	return os<<"]";
}

bool sol(int, int , int);


class Solution {
public:
	void solve();
};

signed main() {
	sync();
#ifdef LOCAL_DEFINE
	cout<<"Time elapsed: "<<1.0 * clock()<<" clocks per sec";
#endif
	int t=1;
	Solution ob;
	cin>>t;
	cin.get();

	while(t--)
		ob.solve();

	return 0 ;
}

void Solution::solve() {
	std::string s;
	getline(cin,s);
	// cout<<s<<endl;
	char temp = 'a';

	auto j  = s.rbegin();
	for(int i =0 ; i < s.length(); i++, j++ , temp++) {
		cout<<temp<<nl;
		if(s[i] == temp || *j == temp) {
			continue;
		}
		cout<<"NO"<<nl;
		return;
	}
	cout<<"YES"<<nl;
}
