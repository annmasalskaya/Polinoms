#include "func.h"
Polynom::Polynom(int a):
    n(a), x(0)
{
    x=NULL;
    x=new double[n+1];
};
Polynom::~Polynom()
{
    delete[]x;
    x=0;
}
Polynom::Polynom(const Polynom& org): // конструктор копирования
    n(org.n), x(0)
{
    double *x=NULL;
    x=new double[n+1];
    for(int i=n-1; i>=0; i--)
        x[i]=org.x[i];
}
istream& operator>>(istream& in,Polynom &a)
{
    for ( int i=a.n-1; i>=0; --i)
    {
        cout << "x^" << i << ":";
        in >> a.x[i];
    }
    return in;
}
ostream& operator<<(ostream &out ,const Polynom &a)
{
    for ( int i =a.n-1; i >= 0; i-- )
    {
        out << a.x[i];
        if (i!=0) cout << "*x^" << i <<" + ";
    }
    return out;
}
Polynom Polynom::operator*(const Polynom&ar)
{
    Polynom temp(n+ar.n-1);
    for(int i=n; i>=0; --i)
    {
        for(int j=ar.n; j>=0; --j)
        {
            temp.x[i+j]+=x[i]*ar.x[j];
        }
    }
    return temp;
}
Polynom &Polynom::operator=(const Polynom &org)
{
    if(this==&org)
        return *this;
    delete [] x;
    n=org.n;
   // double *x=NULL;
    x=new double[n+1];
    for(int i=0; i<n+1; ++i)
        x[i]=org.x[i];
    return *this;
}

Polynom Polynom::operator+(const Polynom &sum)
{
    Polynom temp(n);
    int i, j;
    if(n==sum.n)
    {
        for(i=0; i<sum.n+1; ++i)
            temp.x[i]=x[i]+sum.x[i];

    }
    if(n>sum.n)
    {
       // Polynom temp(n+1);
        for(i=0; i<sum.n+1; i++)
        {
            temp.x[i]=x[i]+sum.x[i];
        }
        for(j=i; j<n+1; j++)
        {
            temp.x[j]=x[j];
        }

    }
    if(n<sum.n)
    {
       // Polynom temp(sum.n);
        for( i=0; i<n+1; i++)
        {
            temp.x[i]=x[i]+sum.x[i];
        }
        for( j=i; j<sum.n+1; j++)
        {
            temp.x[j]=sum.x[j];
        }

    }

    return temp;
}

Polynom Polynom::proizvodnaya (Polynom ar)
{

    Polynom result(n);
    int j=n;
    for ( int i=n-1; i>=0; --i)
    {
        result.x[i]=ar.x[j]*j;
        --j ;
    }
    return result;
}
Polynom Polynom::integral (Polynom ar )
{
    Polynom result(n+2);
    int j=n;
    for ( int i=n+1; i>=0; --i)
    {
        if(i==0)
        {
            result.x[i]=0;
        }
        else
        {
            result.x[i]=ar.x[j]/(j+1);
            --j ;
        }
    }

    return result;
}


