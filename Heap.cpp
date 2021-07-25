#include<bits/stdc++.h>
#include"Heap.hpp"
        
signed main(){
    Heap<int> heap;
    std::pair<int,int> * arr = new std::pair<int,int> [6];
      
        arr[0] = { 34 , 4};
        arr[1] = { 23 , 2};
        arr[2] = { 21, 1};
        arr[3] = { 27 , 3};
        arr[4] = { 28, 5};
        arr[5] = { 34, 5};
         
        heap.Buildmaxheap(arr,6);
        for(int i = 0 ; i < 6; i++)
        cout<<arr[i];

    return 0;
}
