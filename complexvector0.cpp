#include"complexvector0.hpp"
CComplexVector0::CComplexVector0(const CComplexVector1 &k)
{
    n=k.n;
    arr.resize(n);
    for(int i=0;i<n;i++)
    {
        arr[i]=k.arr[i];
    }
}
/*CComplexVector0::CComplexVector0(const int k)
{
    n=k;
    arr=new ComplexNumber [n];
    for(int i=0;i<n;i++)
    {
        arr[i].SetZero();
    }
}*/
const CComplexVector0 CComplexVector0::operator +(const CComplexVector0 &k)
{
    CComplexVector0 z(n);
    for(int i=0;i<n;i++)
    {
        z.arr[i]=arr[i]+k.arr[i];
    }
    return z;
}
const CComplexVector0 CComplexVector0::operator -(const CComplexVector0 &k)
{
    CComplexVector0 z(n);
    for(int i=0;i<n;i++)
    {
        z.arr[i]=arr[i]-k.arr[i];
    }
    return z;
}
const CComplexVector0 CComplexVector0::operator *(const CComplexVector0 &k)
{
     CComplexVector0 z(n);
    for(int i=0;i<n;i++)
    {
        z.arr[i]=arr[i]*k.arr[i];

    }
    return z;
}
/*CComplexVector0& CComplexVector0::operator =(const CComplexVector0 &k)
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
int CComplexVector0::output(const std::string& Filename)
{
        {
        //FILE *o=stdout;
        //freopen(Filename,"a",stdout);
        ofstream fout(Filename,ios_base::app);
        if(!fout.is_open())
        {
            cout<<"Something went wrong,there is no such file: "<<Filename;
            return -1;
        }

        else
        { fout<<"(";
            for(int i=0;i<n;i++)
             {
                 //arr[i].outp();
                 fout<<arr[i].a;
                 fout<<"+";
                 fout<<"i*";
                 fout<<arr[i].b;
                 if(i!=n-1)fout<<",";

             }
             fout<<")";
             fout<<endl;
             fout.close();
            return 0;
        }
         //fclose(stdout);
         //freopen("CON","a",stdout);
         //*stdout=*o;

    }


}
