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
    Polynom d=a.proizvodnaya(a);
    cout<<"Производная от первого полинома "<<endl;
    cout<<d<<endl<<endl;
    Polynom e=a.integral(a);
    cout<<"Интеграл от первого полинома "<<endl;
    cout<<e<<",где 0=const"<<endl<<endl<<endl;


    return 0;
}
