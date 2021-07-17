//A Simple Motion simulator

//Libraries

#include<cmath>
#include<bits/stdc++.h>

using namespace std;
//Object with member functions 
struct V3{
    double x,y,z;
    struct V3   add(struct V3 const &b){
        V3 v;
        v.x=x+b.x;
        v.y=y+b.y;
        v.z=z+b.z;
        return v;
    }
        double length(){
        return(sqrt(x*x+y*y+z*z));
    };
    struct V3 scale(double const factor){
        V3 v;
        v.x=x*factor;
        v.y=y*factor;
        v.z=z*factor;
        return v;
    }
    
    void print(){
        cout<<"x="<<x<<" y="<<y<<" z="<<z<<endl;
    }
    };

//Accessing member function
signed main(){
V3 acc,vel,pos;//The initial accelerataion, velocity and position
V3 curr_disp,curr_pos;//The curret displacement and position
double delta_t,total_t,t=0.0;

//User input values
cout<<"Give the initial position \n";
cin>>pos.x>>pos.y>>pos.z;

cout<<"Give the initial components of velocity\n";
cin>>vel.x>>vel.y>>vel.z;

cout<<"Give the initial components of acceleration\n";
cin>>acc.x>>acc.y>>acc.z;

 cout<<"Give the total time of simulation\n";
 cin>>total_t;
 cout<<"Give the simulation time granularity\n";
 cin>>delta_t;
 if((total_t<0)||(delta_t<0)){
 cout<<"Invalid input\n";
 return -1;
}
else{
 
 //Program for motion simulator
//Calculating the current displacement using member functions
while(t<=total_t){
curr_disp = (vel.scale(t)).add(acc.scale(0.5*t*t));
curr_pos=curr_disp.add(pos);
cout<<"Time "<<t<<" ";
curr_disp.print();
t+=delta_t;
}

}
return 0;
}
