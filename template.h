// #include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<map>

using namespace std;
template <typename T1, typename T2>
inline std::ostream &operator<< (std::ostream &os, const std::pair<T1,T2> &p)
{
    return os<<"{"<<p.first<<", "<<p.second<<"}, ";
}


template<typename T1, typename T2>
inline std::ostream &operator << (std::ostream & os,const std::unordered_map<T1, T2>& v)
{
    bool first = true;
    os << "[";
    for (typename std::unordered_map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii)
    {
        if(!first)
            os << ", ";
        os << *ii ;
        first = false;
    }
    return os << "]";
}
template<typename T>
inline std::ostream &operator<<(std::ostream &os, const std::vector<T> &v ){
    bool first = true;
    os<<"[";
    for(typename std::vector<T>::const_iterator i = v.begin(); i != v.end(); i++){
        if(!first)
        os<<", ";
        os<<*i;
        first = false;
    }
    return os <<"] \n"; 
}