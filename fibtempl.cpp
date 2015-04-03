#include <iostream>
template <class T, size_t N> void fib(T(&a)[N], size_t i=N) {
  for(0[a]=0,1[a]=1,i=2;i<N;a[i]=a[i-1]+a[i-2],++i);
}
int main() {
  double a[1000];
  fib(a);
  for (unsigned i=0; i<sizeof(a)/sizeof(*a); std::cout<<a[i++]<<std::endl);
}
