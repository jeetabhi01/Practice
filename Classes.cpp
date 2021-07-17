//Libraries
#include<bits/stdc++.h>

//Class
class  V3{
    private: 
    double x, y, z;
    double length(){
        return(sqrt(x*x+y*y+z*z));
    }
    public:
    //Default constructor which takes no arguments (More generally this will 
    //be used);   
    V3(){
        x=0.0;y=0.0;z=0.0;
        return;
    }
    //Non-default Constructor of a class.
    V3(double dx, double dy, double dz){
        x=dx;y=dy;z=dz;
    }
    //Copy constructor
    V3(const V3 &src){
        x=src.x;
        y=src.y;
        z=src.z;
    }
    
 //Destructor 
 	~V3(){
 			if(length()==0.0)
 			std::cout<<"Zero vector"<<std::endl;
 		return;
 		}

    //Member Functions
    V3 scale(double const factor){
        V3 v;
        v.x=factor*x;
        v.y=factor*y;
        v.z=factor*z;
        return v;
    }
    void printLength(){
        std::cout<<"The length of the vector is "<<length();
        return;
    }
    V3 sum(V3 const &b){
        V3 v;
        v.x=x+b.x;
        v.y=y+b.y;
        v.z=z+b.z;
        return v;
    }
    
};

signed main(){ 

return 0;
}

  
