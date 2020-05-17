#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string>
#include<vector>
#include"complexvector.hpp"
#include"complexnumber.h"
#include"complexvector1.hpp"
#include"complexvector0.hpp"
#include"factory.h"
#include"factoryhori.h"
#include"factoryvirt.h"
int autotest();
void scan1(const std::string& inp);
int main(void)
{
    std::cout<<"begin"<<endl;
    ofstream lout("my.txt");
    if(!lout.is_open())
        cout<<"There is no my.txt";
    lout.close();
    lout.open("your.txt");
    if(!lout.is_open())
        cout<<"There is no your.txt";
    lout.close();

    scan1("data.txt");
    cout<<autotest();
   /* CComplexVector1 a(3);
    CComplexVector1 b(3);
    a.setdata();
    b.setdata();
    CComplexVector1 m;
    cout<<"hey,16"<<endl;
    m=a+b;
    m.out();
    CComplexVector0 k(a);
    CComplexVector0 l(b);
    m.output("your.txt");
    cout<<"hey,16"<<endl;
    CComplexVector0 n;
    n=k*a;
    k.out();
    n.output("my.txt");*/


    return 0;
}
