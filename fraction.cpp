#include<bits/stdc++.h>
using namespace std;

class Fraction{
private:
	int numerator,denominator;
public:
	Fraction(int n,int d){
		numerator = n;
		denominator = d;

	}

	Fraction(){
		numerator = 0;
		denominator =0;
	}

	void print(){
		cout<<numerator/gcd(numerator,denominator)<<"/"<<denominator/gcd(numerator,denominator)<<"\n";
	}

	int gcd(int n,int d){
		if(d==0){
			return n;
		}
		return gcd(d,n%d);
	}

	Fraction operator+(Fraction f){
		Fraction fans;
		fans.numerator = (numerator*f.denominator) + (f.numerator*denominator);
		fans.denominator = f.denominator * denominator;
		return fans;
	}

	Fraction operator-(Fraction f){
		Fraction fans;
		fans.numerator = (numerator*f.denominator) - (f.numerator*denominator);
		fans.denominator = f.denominator * denominator;
		return fans;
	}

	Fraction operator*(Fraction f){
		Fraction fans;
		fans.numerator = numerator * f.numerator;
		fans.denominator = denominator * f.denominator;
		return fans;
	}

};

int main(){
	Fraction f1(2,4);
	Fraction f2(3,2);
	Fraction f6(1,5);

	cout<<"addition"<<"\n";
	Fraction f3;
	f3 = f1+f2+f6;
	f3.print();

	cout<<"subtraction"<<"\n";
	Fraction f4;
	f4 = f1-f2;
	f4.print();

	cout<<"multiplication"<<"\n";
	Fraction f5;
	f5 = f1*f2;
	f5.print();

	return 0;
}