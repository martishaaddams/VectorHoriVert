#ifndef SCAN
#define SCAN
#include<fstream>
#include "complexvector.hpp"
#include "complexvector1.hpp"
#include "complexvector0.hpp"
/*void scan(const char *inp)
{
    FILE *in;
    int n,c;
    //int a,b;
    int sizearr;
    char out[80];
    CComplexVector **arr;
    in=freopen(inp,"r",stdin);
    arr=(CComplexVector**)malloc(10*sizeof(CComplexVector*));
    int i=0;
   while(fscanf(in,"%d %s %d",&c,out,&n)!=EOF)
   {
       if(c==0)
       {
        arr[i]=new CComplexVector0(n);
        for(int k=0;k<80;k++)
        {
            arr[i]->Filename[k]=out[k];
        }
        arr[i]->setdata();
        //printf("%s",arr[i]->Filename);

       }
       else if(c==1)
       {
            arr[i]=new CComplexVector1 (n);
            for(int k=0;k<80;k++)
            {
                arr[i]->Filename[k]=out[k];
            }
            arr[i]->setdata();
            //printf("%s",arr[i]->Filename);


       }
       //arr[i]->out();
       i++;
       if(i==10)
       {
           arr=(CComplexVector**)realloc(arr,2*i*sizeof(CComplexVector));
       }
    }
    fclose(stdin);
    freopen("CON","w",stdin);
    sizearr=i;
    for(i=0;i<sizearr;i++)
    {
        //printf("%s",arr[i]->Filename);
        arr[i]->output(arr[i]->Filename);

    }
    for(int k=0;k<sizearr;k++)
    {
       delete arr[k];
    }
    free(arr);
    arr=nullptr;
}*/
void scan(const char *inp)
{
    ifstream in;
    in.open(inp);
    int n,c;
    int sizearr;
    char out[80];
    CComplexVector **arr;
    arr=new CComplexVector* [10];
    int i=0;
    sizearr=10;
    if(!in.is_open())
        cout<<"Something went wrong, there is no such file: "<<inp;
    else
    {
        while(in>>c)
        {
            in>>out;
            in>>n;
            if(c==0)
            {
                arr[i]=new CComplexVector0(n);
                for(int k=0;k<80;k++)
                {
                    arr[i]->Filename[k]=out[k];
                }
                //arr[i]->setdata(in);
                for (int k=0;k<n;k++)
                {
                    in>>arr[i]->arr[k].a;
                    in>>arr[i]->arr[k].b;
                }

                //printf("%s",arr[i]->Filename);
            }
            else if(c==1)
            {
            arr[i]=new CComplexVector1 (n);
            for(int k=0;k<80;k++)
            {
                arr[i]->Filename[k]=out[k];
            }
            //arr[i]->setdata();
            for (int k=0;k<n;k++)
                {
                    in>>arr[i]->arr[k].a;
                    in>>arr[i]->arr[k].b;
                }
            //printf("%s",arr[i]->Filename);


            }
                   //arr[i]->out();
           i++;
           if(i==sizearr)
           {
               arr=(CComplexVector**)realloc(arr,2*i*sizeof(CComplexVector));
               CComplexVector** tmp;
               tmp=new CComplexVector* [10];
               for(int k=0;k<10;k++)
                    tmp[k]=arr[k];
               delete arr;
               arr=new CComplexVector* [sizearr*2];
               for(int k=0;k<10;k++)
               {
                   arr[k]=tmp[k];
               }
               delete tmp;

           }
        }
        in.close();
        //fclose(stdin);
        //freopen("CON","w",stdin);
        sizearr=i;
        for(i=0;i<sizearr;i++)
        {
            //printf("%s",arr[i]->Filename);
            arr[i]->output(arr[i]->Filename);

        }
        for(int k=0;k<sizearr;k++)
        {
           delete arr[k];
        }
        delete arr;
        arr=nullptr;

    }
}


#endif
