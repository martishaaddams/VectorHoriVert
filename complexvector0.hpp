#ifndef CCOMPLEXVECTOR0_H
#define CCOMPLEXVECTOR0_H
#include "complexvector.hpp"
#include"complexvector1.hpp"
#include"fstream"


class CComplexVector0:public CComplexVector
{
public:
    CComplexVector0():CComplexVector(){};
    CComplexVector0(const int k):CComplexVector(k){};
    CComplexVector0(const int k, const ComplexNumber *str): CComplexVector(k,str){};//*
    CComplexVector0(const CComplexVector& k):CComplexVector(k){};
    CComplexVector0(const CComplexVector1 &k);
    const CComplexVector0 operator +(const CComplexVector0 &k );
    const CComplexVector0 operator -(const CComplexVector0 &k );
    const CComplexVector0 operator *(const CComplexVector0 &k );
    using CComplexVector::operator =;
    int output(const char* Filename);
};

#endif // CCOMPLEXVECTOR0_H

