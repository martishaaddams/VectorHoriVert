#ifndef CCOMPLEXVECTOR_H
#define CCOMPLEXVECTOR_H
#include "complexnumber.h"
void scan(const char* inp);
class CComplexVector
{
public:
    int n;
    char Filename[80];
    ComplexNumber *arr;
    CComplexVector();
    CComplexVector(const int k);
    CComplexVector(const int k, const ComplexNumber *str);
    CComplexVector(const CComplexVector& k);
    void setdata();
    ~CComplexVector();
    /*const CComplexVector& operator +(const CComplexVector &k );
    const CComplexVector& operator -(const CComplexVector &k );
    const CComplexVector& operator *(const CComplexVector &k );*/
    CComplexVector& operator =(const CComplexVector &k );
    void out();
    virtual int output(const char *Filename=nullptr)=0;
};
#endif // CCOMPLEXVECTOR_H

