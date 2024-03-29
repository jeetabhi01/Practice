#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//#define LOCAL //Comment in if custom header not set //Comment out when submitting
#define endl '\n' //Comment out if interactive
#define int long long //Comment out if memory exceeds

using namespace std;

//const int MOD=1000000007; //Comment in if question asks to take mod by this number

void solve() {
    //Write your solution here
    int n;
    cin>>n;
    int a[n];
    int max = INT_MIN;
    double sum = 0;
    for(int i  = 0; i<n; i++) {
        cin>>a[i];
        sum += a[i];
        if(a[i] > max) max = a[i];
    }
    sum -= max;
    double ans = max + (sum)/(n-1);
    printf("%.9f \n",ans);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start_timer = chrono::high_resolution_clock::now();
#endif

    int t=1;
    cin>>t; //Comment out if single test case
    while (t--) {
        solve();
    }

#ifdef LOCAL
    auto stop_timer = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(stop_timer - start_timer);
    cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;
#endif
    return 0;
}
