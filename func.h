#ifndef FUNC_H
#define FUNC_H
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
    Polynom operator+(const Polynom &sum);
    Polynom operator*(Polynom &);
    Polynom proizvodnaya (Polynom ar);
    Polynom & operator=(const Polynom &org);
    friend ostream& operator<<(ostream &out ,const Polynom &a);
    friend istream& operator>>(istream& in,Polynom &a);

};



#endif