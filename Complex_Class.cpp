#include<iostream>
using namespace std;

class Complex
{
    int real, imaginary;

    public :

        Complex();
        Complex(int real, int imag): real(real), imaginary(imag) {} 
        Complex(const Complex &ob);
        Complex operator+(const Complex &ob);
        Complex operator-(const Complex &ob);
        Complex operator*(const Complex &ob);
        Complex operator=(const Complex &ob);
        bool operator==(const Complex &ob);
        friend istream& operator>>(istream &in, Complex &ob);
        friend ostream& operator<<(ostream &out, const Complex &ob);

};

Complex::Complex()
{
    this->real = this->imaginary = 0;
}

Complex::Complex(const Complex &ob)
{
    this->real = ob.real;
    this->imaginary = ob.imaginary;
}

Complex Complex::operator+(const Complex &ob)
{
    return Complex(this->real + ob.real, this->imaginary + ob.imaginary);
}

Complex Complex::operator-(const Complex &ob)
{
    return Complex(this->real - ob.real, this->imaginary - ob.imaginary);
}

Complex Complex::operator*(const Complex &ob)
{
    return Complex(this->real * ob.real + (-1) * (this->imaginary * ob.imaginary), this->real * ob.imaginary + this->imaginary * ob.real);
}

Complex Complex::operator=(const Complex &ob)
{
    this->real = ob.real;
    this->imaginary = ob.imaginary;

    return *this;
}

bool Complex::operator==(const Complex &ob)
{
    return (this->real == ob.real && this->imaginary == ob.imaginary);
}

istream& operator>>(istream &in, Complex &ob)
{
    cout<<"Enter the value of real and imaginary part of the Complex number : "<<endl;
    in>>ob.real>>ob.imaginary;
    return in;
}

ostream& operator<<(ostream &out, const Complex &ob)
{
    out<<"Displaying the Complex Number : "<<endl;
    out<<ob.real<<" + "<<"i*"<<ob.imaginary<<endl;
    return out;
}

int main()
{
    Complex c1;
    cout<<"Working of Input and Output functions for Complex Number :-"<<endl;
    cin>>c1;
    cout<<c1;

    Complex c2(c1);
    cout<<"Working of Copy Constructor for Complex Number :-"<<endl;
    cout<<c2;

    cout<<"Working of Operator overloading '==' for Complex Number :-"<<endl;
    if(c1 == c2)
        cout<<"c1 is equal to c2"<<endl;
    else
        cout<<"c1 is not equal to c2"<<endl;

    Complex res, c3(3, 2);
    cout<<"Working of Operator overloading '+' for Complex Number :-"<<endl;
    res = c1 + c3;
    cout<<res;
    cout<<"Working of Operator overloading '-' for Complex Number :-"<<endl;
    res = c1 - c3;
    cout<<res;
    cout<<"Working of Operator overloading '*' for Complex Number :-"<<endl;
    res = c1 * c3;
    cout<<res;
    cout<<"Working of Operator overloading '=' for Complex Number :-"<<endl;
    res = c1 = c3;
    cout<<res;

    return 0;
}