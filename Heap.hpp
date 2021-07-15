#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::cin;

#define a first
#define b second

template<typename T1,typename T2>
inline std::ostream &operator<<(std::ostream &os, const std::pair<T1,T2> &p ){
    return os<<"{"<<p.a<<","<<p.b<<"},";
}

template <typename T>
inline std::ostream &operator <<(std::ostream &os ,const std::vector<T> &v){
    os<<"[";
    bool first = true;
    for(int i  = 0 ; i < v.size(); i++){
        if(!first)
        os<<",";
        os<<v[i];
    }
    return os <<"]"<<endl;
}
template <typename T> 
class Heap{
    private:
        std::vector<std::pair<T,int> > * Maxheap;
        inline int parentindex(int index){
           return (index -1)/ 2;
        }
        inline int rightchildindex(int index){
            return 2 * index+ 2;
        }

       inline int leftchildindex(int index){
            return 2 * index + 1;
        }
        void shiftup(int index){
            if(index = 0){
            return;
            }
            if(Maxheap->at(index) > Maxheap->at(parentindex(index))){
                std::swap(Maxheap->at(index) , Maxheap->at(parentindex(index)));        
                shiftup(parentindex(index));
            }
            return;
        }

        void shiftdown(int index){
            int size = Maxheap->size();
            int largest  = index;
            int left = leftchildindex(index);
            int right = rightchildindex(index);
            if(Maxheap->at(largest) < Maxheap->at(left) && left < size)
                largest = left;

            if(Maxheap->at(largest) < Maxheap->at(right) && right < size)
                largest = right;

            if(largest!= index){
                std::swap(Maxheap->at(largest),Maxheap->at(index));
                shiftdown(largest);
            }
                
            return;            
            
        }


        void Heapify(std::pair<T,int> p[], int index , int size){
            int largest = index;
            int l = leftchildindex(index);
            int r = rightchildindex(index);
            if(p[l].second > p[largest].b && l < size)
                largest = l;
            if(p[r].second > p[largest].b && r < size)
                largest = r;
            if(largest!= index){
                std::swap(p[largest],p[index]);
                Heapify(p,largest,size);
            }
            return;
        }
        
    public:
        Heap(){
            Maxheap = new std::vector<std::pair<T,int> >();
            
        }
        ~Heap(){
            delete Maxheap;
        }

      inline  int Getsize(){return Maxheap->size();}

        void insert(std::pair<T,int> priority){
            
            Maxheap->push_back(priority);
       
            shiftup(Maxheap->size()-1);
        }

       inline std::vector<std::pair<T,int> > * Getheap(){
            return Maxheap;
        }
        
        void Buildmaxheap(std::pair<T,int> p[],int size){
            for(int i = size/2 -1 ; i  >= 0 ; i--){
                Heapify(p,i,size);
            }

            for(size -1 ;  size > 0 ; ){
                std::swap(p[0],p[size-1]);
                Heapify(p,0,--size);
            }
            return;
        }
       
       std::pair<T,int> * Getmax(){
           return Maxheap->at(0);
       }

        std::pair<T,int> Extractmax(){
            std::pair<T,int>  value = Maxheap->at(0);
            int i = 0 ;
            Maxheap->pop_back();
            if(Maxheap->size()>0)
            shiftdown(i);
           return value; 
        }

};

        
