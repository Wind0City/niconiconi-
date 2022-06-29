//赋值相关只能写成成员函数，返回值类型是引用
//重载流插入和流提取只能是全局函数实现

#include <iostream>
using namespace std;
class Complex
{
    friend ostream &operator<<(ostream &out,const Complex &a)
    {
        out << "(" << a.real << "," << a.imag << ")";
        return out;
    }
    friend istream &operator>>(istream &in,Complex &a)
    {    //in.ignore();
        in >> a.real >> a.imag;
        return in;
    }
    friend Complex operator+(Complex &a, Complex &b);
    friend Complex operator*(Complex &a, double n)
    {
        return Complex(a.real * n, a.imag * n);
    }
    //  friend Complex operator*(double n, Complex &a)
    //{
    //    return Complex(a.real * n, a.imag * n);
    //}

public:
    Complex &operator++() //== ++a;
    {
        /*code*/
    }
    Complex &operator++(int) //== a++;
    {
        /*code*/
    }
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    /*Complex operator+(Complex &c) //***
    {
        return Complex(real + c.real, imag + c.imag);
    }*/

private:
    double real;
    double imag;
};
Complex operator+(Complex &a, Complex &b)
{
    return Complex(a.real + b.real, b.imag + a.imag);
}
int main()
{
    Complex a, b;
    Complex c = a + b; //****
    Complex d = a * 5;
    // Complex e=5*a;
    ++a;
    a++;
}