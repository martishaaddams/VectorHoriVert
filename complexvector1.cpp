#include"complexvector1.hpp"
const CComplexVector1 CComplexVector1::operator +(const CComplexVector1 &k)
{
    CComplexVector1 z(k.n);
   // z.out();
    //cout<<endl;
    for(int i=0;i<n;i++)
    {
        z.arr[i]=arr[i]+k.arr[i];
        //z.arr[i].outp();
        //cout<<endl;
    }
    return z;
}
const CComplexVector1 CComplexVector1::operator -(const CComplexVector1 &k)
{
    CComplexVector1 z(n);
    for(int i=0;i<n;i++)
    {
        z.arr[i]=arr[i]-k.arr[i];
    }
    return z;
}
const CComplexVector1 CComplexVector1::operator *(const CComplexVector1 &k)
{
     CComplexVector1 z(n);
    for(int i=0;i<n;i++)
    {
        z.arr[i]=arr[i]*k.arr[i];

    }
    return z;
}
/*CComplexVector1& CComplexVector1::operator =(const CComplexVector1 &k)
{
    n=k.n;
    delete arr;
    arr=new ComplexNumber [n];
    for(int i=0;i<n;i++)
    {
        arr[i]=k.arr[i];
    }
   // cout<<"basic"<<endl;
    return *this;
}*/
int CComplexVector1::output(const char* Filename)
{

    //FILE *o=stdout;
    //freopen(Filename,"a",stdout);
    ofstream fout(Filename,ios_base::app);
    if(!fout.is_open()){
        cout<<"Something went wrong,there is no such file: "<<Filename;
        return -1;
        }
    else
    {
        for(int i=0;i<n;i++)
        {
             fout<<arr[i].a;
             fout<<"+";
             fout<<"i*";
             fout<<arr[i].b;
             fout<<endl;
        }
        fout<<endl;
        fout.close();
         return 0;
    }
    //fclose(stdout);
    //freopen("CON","a",stdout);
    //stdout = fdopen(0, "w");
    //printf("dupa2");
    //*stdout=*o;




}
