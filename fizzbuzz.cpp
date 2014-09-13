#include <iostream>
#define _ std::cout
int main(int l,char**){return(l<101)?(!(l%3)&&(_<<"Fizz"),!(l%5)&&(_<<"Buzz"),(l%3&&l%5)&&(_<<l),_<<" ",main(++l,0)):0;}
