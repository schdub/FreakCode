#include <iostream>
template <class T, size_t N> void fib(T(&_)[N], size_t i=N) {
    for(0[_]=0,1[_]=1,i=2;i<N;_[i]=_[i-1]+_[i-2],++i);
}
int main() {
    double a[1000];
    fib(a);
    for (unsigned i=0; i<sizeof(a)/sizeof(*a); std::cout<<a[i++]<<std::endl);
}
