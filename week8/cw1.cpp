#include <iostream>
using namespace std;
class Fraction
{
    private:
    int num;
    int den;
    
    int gcd(int num,int den)
    {
        int gcdd;
        for(int i=1;i<=num;i++)
        {
            if(num%i==0 && den%i==0)
            {
                gcdd=i;
            }
        }
        return gcdd;
    }
    
    void reduce()
    {
        int hcf=gcd(num,den);
        num/=hcf;
        den/=hcf;
        if(den<0)
        {
            den=-den;
            num=-num;
        }
    }
    public:
    Fraction(int n=0,int d=1):num(n),den(d){reduce();}
    Fraction operator+(const Fraction& other)
    {
        return Fraction((num*other.den)+(den*other.num),den*other.den);
    }
    Fraction operator-(const Fraction& other)
    {
        return Fraction((num*other.den)-(den*other.num),den*other.den);
    }
    Fraction operator*(const Fraction& other)
    {
        return Fraction((num*other.num),den*other.den);
    }
    Fraction operator/(const Fraction& other)
    {
        return Fraction((num*other.den),den*other.num);
    }
    bool operator==(const Fraction& other)
    {
        return num==other.num && den==other.den;
    }
    bool operator!=(const Fraction& other)
    {
        return !(*this==other);
    }
    bool operator<(const Fraction& other) const
    {
        return num*other.den < other.num*den;
    }
    bool operator>(const Fraction& other)
    {
        return other< *this;
    }
    bool operator>=(const Fraction& other)
    {
        return !(*this<other);
    }
    bool operator<=(const Fraction& other)
    {
        return !(*this<other);
    }
    friend ostream& operator<<(ostream& os, const Fraction& f)
    {
        os<<f.num;
        if(f.den!=1)
        {
            os<<"/"<<f.den;
        }
        return os;
    }
    friend istream& operator>>(istream& is,Fraction& f)
    {
        cout<<"Enter numerator and denominator respectively: "<<endl;
        is>>f.num>>f.den;
        if(f.den ==0)
        {
            cout<<"Denominator cannot be zero!"<<endl;
        }
        f.reduce();
        return is;
    }
    
};
int main()
{
    Fraction f1(2, 4),f2(3, 6);
    cout<<"Sum: "<<(f1 + f2)<<endl;
    cout<<"Difference: "<<(f1 - f2)<< endl;
    cout<<"Product: "<<(f1 * f2)<< endl;
    cout<<"Quotient: "<<(f1 / f2)<< endl;
    cout << "f1 == f2: " << (f1 == f2) << endl;
    cout << "f1 != f2: " << (f1 != f2) << endl;
    cout << "f1 < f2: " << (f1 < f2) << endl;
    cout << "f1 > f2: " << (f1 > f2) << endl;
    
    
    return 0;
}
