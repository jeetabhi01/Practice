#include<iostream>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;

class Dynamic{
    private:
        int minimumHelper(int n ,int * arr);
    public:
       int minimumR(int n){
        if(n==1){
           return 0;
        }
        int x = minimumR(n-1);
        int y = __INT_MAX__;
        int z = __INT_MAX__;
        if(n%2==0){
            y =minimumR(n/2);
        }
        if(n%3==0){
           z = minimumR(n/3);
        }

        int ans = std::min(x,std::min(y,z)) + 1;
        return ans;
    }

    int minimum(int n);

};

signed main(){
    Dynamic a;
    int n = 10;
    
    cout<<a.minimumR(10)<<endl;
    cout<<a.minimum(10)<<endl;
    
    return 0;
}


int Dynamic::minimumHelper(int n , int *ans){
    if(n == 1){
        ans[n] = 0;
        return 0;
    }
    else{
    int y = __INT_MAX__;
    int z = __INT_MAX__;
    if(ans[n-1] == -1){
        ans[n-1] = minimumHelper(n-1,ans);
    }
    int x = ans[n-1];
    if(n%2==0){
        if(ans[n/2] == -1){
            ans[n/2] = minimumHelper(n/2,ans);
        }
        y = ans[n/2];
    }

    if(n%3 == 0){
        if(ans[n/3]==-1){
            ans[n/3] = minimumHelper(n/3,ans);
        }
        z = ans[n/3];
    }
    cout<<x<<" "<<y<<" "<<z<<endl;
    ans[n] = std::min(x,std::min(y,z))+1;
    return ans[n];
    }
}
int Dynamic::minimum(int n){
    int * ans = new int[n+1]{-1};
    int output = Dynamic::minimumHelper(n,ans);
    delete []ans;
    return output;
}
