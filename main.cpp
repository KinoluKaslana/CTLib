#include <iostream>
#include <type_traits>
#include "_HeaderCore.h"
#include "CT_tuple.h"
template<class T,class ...D>
struct Td{
    size_t  d = sizeof...(D);
    using TY = Td<T>;
};
int main() {
    using CTL::ct_tuple;
    Td<int> d;
    ct_tuple<int,float,double,short,bool,char,long double> the(1,2,3,4,5,6,7);
    std::cout<<"Test ting ct_tuple ..."<<std::endl<<
    CTL::get<0>(the)<<CTL::get<1>(the)<<CTL::get<2>(the)<<CTL::get<3>(the)<<
    CTL::get<4>(the)<<CTL::get<5>(the)<<CTL::get<6>(the)<<std::endl;
    return 0;
}
