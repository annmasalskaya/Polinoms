#include <iostream>
using namespace std;
class Polynom
{
private:
    int n;
    double *x;     // массив коэффициентов
public:
    Polynom();
    Polynom(int a);
    ~ Polynom();
    Polynom(const Polynom &org); //конструктор копирования
    Polynom operator+(Polynom &); //перегрузка операторов
    Polynom operator*(Polynom &);
    Polynom proizvodnaya (Polynom ar );
    friend ostream& operator<<(ostream &out ,const Polynom &a);
    friend istream& operator>>(istream& in,Polynom &a);

};
Polynom::Polynom():
    n(0), x(0)
{
};

Polynom::Polynom(int a):
    n(a), x(0)
{
    x=new double[n];
};
Polynom::~Polynom()
{
    delete[]x;
}
Polynom::Polynom(const Polynom& org): // конструктор копирования
    n(org.n), x(0)
{
    x=new double[n];
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
Polynom Polynom::operator*( Polynom &ar)
{
    Polynom temp(n+ar.n);
    //temp.n=n+ar.n;
    //temp.x=new double[temp.n+1];
    for(int i=n; i>=0; --i)
    {
        for(int j=ar.n; j>=0; --j)
        {
            temp.x[i+j]+=x[i]*ar.x[j];
        }
    }
    return temp;
}
Polynom Polynom::operator+(Polynom &sum)
{
    Polynom temp;
    int i, j;
    if(n>sum.n)
    {

        temp.x= new double[n+1];

        for(i=0; i<sum.n+1; i++)
        {
            temp.x[i]=x[i]+sum.x[i];
        }
        for(j=i; j<n+1; j++)
        {
            temp.x[j]=x[j];
        }

    }
    else
    {
        temp.x= new double[sum.n+1];
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

Polynom Polynom::proizvodnaya (Polynom ar )
{
    Polynom result;
    int  k=n;
    result.x= new double[k];
    int j=n;
    for ( int i=n-1; i>=0; --i)
    {
       result.x[i]=ar.x[j]*j;
            --j ;
    }
    return result;
}

int main()
{

    Polynom a(4);
    cin>>a;
    cout<<a;
    cout<<endl<<endl;
    Polynom b(4);
    cin>>b;
    cout<<b;
    cout<<endl;
    Polynom c(4);
    c=a+b;
    cout<<c;
    /*
    int n1, n2;
    double *x_1=NULL;
    cout<<"Введите степень первого многочлена : ";
    cin>>n1;
    x_1= new double[n1+1];
    cout<<" Введите коэффициенты при 'x' "<<endl;
    input( x_1, n1);
    output ( x_1, n1);
    cout<<endl<<endl;
    // integral( x_1,  n1 );
    double *proiz=NULL;
    int k=n1;
    proiz= new double[k];
    cout<<"Производная "<<endl;
    proizvodnaya ( x_1,n1,proiz);
    output ( proiz, k-1);
    delete [] proiz;
    cout<<endl<<endl;
    double *x_2=NULL;
    cout<<"Введите степень второго многочлена : ";
    cin>>n2;
    x_2 = new double[n2+1];
    cout<<" Введите коэффициенты при 'x' "<<endl;
    input ( x_2, n2);
    output ( x_2, n2);
    cout<<endl;
    double *x_3=NULL;
    x_3=new double[n1+n2+1];
    cout<<"Произведение 2-х полиномов"<<endl;
    multiplication(x_1, x_2,x_3,  n1,  n2);
    output(x_3, (n1+n2));
    delete [] x_3;
    cout<<endl;
    cout<<"Сумма 2-х полиномов"<<endl;
    if(n1>n2)
    {
        double *sum=NULL;
        sum= new double[n1+1];
        summ ( x_1,x_2 ,n1, n2, sum);
        output(sum,n1);
        delete [] sum;
    }
    else
    {
        double *sum=NULL;
        sum= new double[n2+1];
        summ ( x_1,x_2 ,n1, n2, sum);
        output (sum,n2);
        delete [] sum;
    }
    cout<<endl;
    delete [] x_1;
    delete [] x_2;*/

    return 0;
}
