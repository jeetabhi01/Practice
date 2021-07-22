#include<iostream>

#define int long long int

using namespace std;
class Fibonacci {

    int fibonacciHelper(int n, int * arr) {
        if(n <= 1) {
            arr[n] = n;
            return n;
        }
        if(arr[n-1] == 0) {
            arr[n-1] = fibonacciHelper(n-1,arr);
        }
        if(arr[n-2] == 0) {
            arr[n-2] = fibonacciHelper(n-2,arr);
        }
        arr[n] = arr[n-1] + arr[n-2];
        return arr[n];
    }

    int fibonacciDPHelper(int n,int * arr) {
        arr[0] = 0;
        arr[1] = 1;
        for(int i = 2; i <= n ; i++) {
            arr[i] = arr[i-1] + arr[i-2];
        }
        return arr[n];
    }
public:
    int fibonacci(int n) {
        int * arr = new int[n+1] {0};
        auto ans = fibonacciHelper(n,arr);
        delete []arr;
        return ans;
    }

    int fibonacciDP(int n) {
        int * ans = new int[n+1] {0};
        auto  output =  fibonacciDPHelper(n,ans);
        delete []ans;
        return output;
    }
};

signed main() {
    // freopen("output.txt","w",stdout);
    Fibonacci a;
    cout<<a.fibonacci(65)<<endl;
    cout<<a.fibonacciDP(65)<<endl;
    return 0;
}