#include "func.h"
int main()

{
    //cout<<"Введите степень первого многочлена : "<<endl;
    Polynom a(4);
    cout<<"#1 Введите коэффициенты при 'x' "<<endl;
    cin>>a;
    cout<<a;
    cout<<endl<<endl;
    Polynom b(2);
    //cout<<"Введите степень второго многочлена : "<<endl;
    cout<<"#2 Введите коэффициенты при 'x' "<<endl;
    cin>>b;
    cout<<b;
    cout<<endl<<endl;
    Polynom summa(6);
    summa=a+b;
    cout<<"Сумма 2-х полиномов"<<endl;
    cout<<summa<<endl<<endl;
    Polynom c(2);
    c=a*b;
    cout<<"Произведение 2-х полиномов"<<endl;
    cout<<c<<endl<<endl;
    cout<<"Производная от первого "<<endl;
    a.proizvodnaya(a);
    cout<<a;
    cout<<"Интеграл от первого "<<endl;
    a.integral(a);
    cout<<a;

    return 0;
}
