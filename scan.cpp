#ifndef SCAN
#define SCAN
#include<fstream>
#include "complexvector.hpp"
#include "complexvector1.hpp"
#include "complexvector0.hpp"
#include"factory.h"
#include"factoryhori.h"
#include"factoryvirt.h"
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
void scan(const std::string& inp)
{
    ifstream in;
    in.open(inp);
    int n,c;
    int sizearr;
    std::string out;
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
                /*for(int k=0;k<80;k++)
                {
                    arr[i]->Filename[k]=out[k];
                }*/
                arr[i]->Filename=out;
                //std::cout<<"fine "<<out<<" hah"<<arr[i]->Filename;
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
            /*for(int k=0;k<80;k++)
            {
                arr[i]->Filename[k]=out[k];
            }*/
            arr[i]->Filename=out;
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
void scan1(const std::string& inp)
{
    factoryhori* hori=new factoryhori;
    factoryvirt* vert=new factoryvirt;
    ifstream in;
    in.open(inp);
    int n,c;

    //int sizearr1;
    std::string out;
    //CComplexVector **arr;
    std::vector<CComplexVector*> arr;
    //arr.resize(1);
    //arr.reserve(1);
    //int i=0;
    std::vector<CComplexVector*>::iterator it;//=arr.begin();
    //std::vector<CComplexVector*>::iterator sizearr=arr.end();
    std::vector<CComplexVector*>::iterator ik;
    //sizearr1=10;
    if(!in.is_open())
        cout<<"Something went wrong, there is no such file: "<<inp;
    else
    {
        while(in>>c)
        {
            arr.resize(arr.size()+1);
            if(arr.size()==1)
                it=arr.begin();
            else
                it++;
           cout<<arr.size();
            in>>out;
            in>>n;
            if(c==0)
            {
                (*it)=hori->create(n,out);
                //arr.push_back(hori->create(n,out));
                //(*it)->Filename=out;
                std::cout<<"fine "<<out<<" hah"<<(*it)->Filename<<endl;
                for (int k=0;k<n;k++)
                {
                     in>>(*it)->arr[k].a;
                    in>>(*it)->arr[k].b;
                }
            }
            else if(c==1)
            {
                *it=vert->create(n,out);
            //it=arr.end();
            //(*it)->Filename=out;
                for (int k=0;k<n;k++)
                {
                    in>>(*it)->arr[k].a;
                    in>>(*it)->arr[k].b;
                }
                std::cout<<"fine "<<out<<" hah"<<(*it)->Filename<<endl;

            }
                        //arr[i]->out();
            (*it)->out();
            //it++;

        }
        in.close();
        //fclose(stdin);
        //freopen("CON","w",stdin);
        //sizearr=it;
        for(it=arr.begin();it!=arr.end();++it)
        {
            int k=1;
            cout<<k;
            ik=arr.begin();
            ik++;
            ik++;
            //printf("%s",arr[i]->Filename);
            std::cout<<"fine "<<(*ik)->Filename;

            (*it)->output((*it)->Filename);
            cout<<k<<endl;


        }
        for(it=arr.begin();it!=arr.end();++it)
        {
           delete *it;
        }

    }
}



#endif
