#include "func.h"
int main()
{
    cout<<"Введите степень первого многочлена : "<<endl;
    cout<<" Введите коэффициенты при 'x' "<<endl;
    Polynom a(3);
    cin>>a;
    cout<<a;
    cout<<endl<<endl;
    Polynom b(3);
    cout<<"Введите степень второго многочлена : "<<endl;
    cout<<" Введите коэффициенты при 'x' "<<endl;
    cin>>b;
    cout<<b;
    cout<<endl;
    Polynom summa(4);
    summa=a+b;
    cout<<"Сумма 2-х полиномов"<<endl;
    cout<<summa;
    Polynom c(7);
    c=a*b;
    cout<<"Произведение 2-х полиномов"<<endl;
    cout<<c;
    cout<<"Производная "<<endl;
    a.proizvodnaya(a);
    cout<<a;

    return 0;
}
