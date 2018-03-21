#include <iostream>
#include <math.h>
using namespace std;

#define dim 3

int a[dim]= {3,4,5};
float gradie( float x[])
{
    float temp=0;
    for (int i=0; i<dim; i++)
    {
        temp+=pow(x[i],2);
    }
    return sqrt(temp);
}

int main()
{
    float x[]= {100,100,100};
    float grad[]= {1,1,1};
    int count=0;

    float stepsize=0;
    float pers1=0,pers2=0;

    while (gradie(grad)>1.e-5)
    {
        //menghitung gradient
        for (int i=0; i<dim; i++)
        {
            grad[i]=2*a[i]*x[i]+1;
        }

        //menghitung stepsize
        for (int i=0; i<dim; i++)
        {
            pers1+=2*a[i]*x[i]*grad[i]+grad[i];
            pers2+=2*a[i]*grad[i]*grad[i];

        }
        stepsize= pers1/pers2;

        for(int i=0; i<dim; i++)
        {
            x[i]=x[i]+stepsize*(-1*grad[i]);
        }
    count++;
        printf("nilai turunan %d di (%f, %f, %f) = %f , %f , %f dengan stepsize %f \n", count, x[0],x[1],x[2],grad[0],grad[1], grad[2],stepsize);
    }

}
