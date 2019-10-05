#include<iostream>
using namespace std;
class complex{
    public:
complex(){real=imag=0;}
complex(double r, double i){real=r,imag=i;}
friend complex operator +(const complex &c1, const complex &c2);
friend complex operator -(const complex &c1, const complex &c2);
friend complex operator *(const complex &c1, const complex &c2);
friend complex operator /(const complex &c1, const complex &c2);
void print(const complex &c);

    private:
double real,imag;
};

//接下来是四个友元函数函数的定义，以及print函数的定义
complex operator +(const complex &c1, const complex &c2)
{return complex(c1.real+c2.real, c1.imag+c2.imag);}
complex operator -(const complex &c1, const complex &c2)
{return complex(c1.real-c2.real, c1.imag-c2.imag);}
complex operator *(const complex &c1, const complex &c2)
{return complex(c1.real*c2.real-c1.imag*c2.imag, c1.real*c2.imag-c1.imag*c2.real);}
complex operator /(const complex &c1, const complex &c2)
{return complex((c1.real*c2.real+c1.imag*c2.imag)/(c2.real*c2.real+c2.imag*c2.imag),
(c1.imag*c2.real-c1.real*c2.imag)/(c2.real*c2.real+c2.imag*c2.imag));}

void complex::print(const complex &c){
    if (c.imag<0)
        cout<<c.real<<c.imag<<'i';
    else
    {
        cout<<c.real<<'+'<<c.imag<<'i';
    }
}

int main()
{
    complex c1(2.0,3.0),c2(4.0,-2.0),c3;
    complex dt;
    c3=c1+c2;
    cout<<"c1+c2=";
    dt.print(c3);
    c3=c1-c2;
    cout<<"\nc1-c2=";
    dt.print(c3);
    c3=c1*c2;
    cout<<"\nc1*c2=";
    dt.print(c3);
    c3=c1/c2;
    cout<<"\nc1/c2=";
    dt.print(c3);
    c3=(c1+c2)*(c1-c2)*c2/c1;
    cout<<"\n(c1+c2)*(c1-c2)*c2/c1=";
    dt.print(c3);
    cout<<endl;
}
