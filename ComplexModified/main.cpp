#include <iostream>

using namespace std;
//Complex
class Complex
{
private:
    int real;
    int img;

public:
    //setter & getter
    void setReal(int _real);
    int getReal()const ;
    void setImg(int _img);
    int getImg()const ;
    //add
    Complex Add(const Complex& right);
    //print
    void printComplex();
    //copy constractor
    Complex(Complex& old)
    {
        this->real=old.real;
        img=old.img;
        cout<<"cpy ctor"<<endl;
    }
    //constructors
    Complex();
    Complex(int _real,int _img);
    Complex(int _num);
    //destructor
    ~Complex();

    //=operator
    Complex& operator=(const Complex& right)
    {
        this->real=right.real;
        img=right.img;
        return *this;
    }

    //+operator
    Complex operator+(const Complex& right)
    {
        Complex retVal;
        retVal.real=this->real+right.real;
        retVal.img=img+right.img;
        return retVal;
    }

    //-operator
    Complex operator-(const Complex& right)
    {
        Complex retVal;
        retVal.real=this->real-right.real;
        retVal.img=img-right.img;
        return retVal;
    }

    //++c operator
     Complex operator++()
    {
        real++;
        img++;
        return *this;
    }

    //c++ operator
     Complex operator++(int dummy)
    {
        Complex retVal(this->real,this->img);
        this->real++;
        img++;
        return retVal;
    }

    //c1+=c2
    Complex& operator+=(const Complex& right)
    {
        this->real=real+right.real;
        img+=right.img;
        return *this;
    }

    //c1+10
    Complex operator+(int num)
    {
        Complex retVal;
        retVal.real=this->real+num;
        retVal.img=img;
        return retVal;
    }

    //c1>c2
    int operator>(Complex right)
    {
        return this->real>right.real&&img>right.img;
    }


    //c1<c2
    int operator<(Complex right)
    {
        return this->real<right.real&&img<right.img;
    }

    //c1==c2
    int operator==(Complex right)
    {
        return this->real==right.real&&img==right.img;
    }

    //int x=(int)c1;
    operator int()
    {
        return this->real;
    }

    friend Complex Sub(Complex left,Complex right);
};

Complex Sub(Complex left,Complex right)
{
    Complex retVal;
    retVal.setReal(left.getReal()-right.getReal());
    retVal.setImg(left.getImg()-right.getImg());
    return retVal;
}

//10+c1
Complex operator+(int num,Complex right)
{
    Complex retVal;
    retVal.setReal(num+right.getReal());
    retVal.setImg(right.getImg());
    return retVal;
}


int main()
{
    Complex c1,c2,c3(0,0);
    c1.setReal(-1);
    c1.setImg(-2);
    c2.setReal(-3);
    c2.setImg(-4);
    //print the complex num
    c1.printComplex();
    c2.printComplex();
    //sum 2 complex
    c3= c1.Add(c2);
    cout<<endl<<"Sum two Complex: "<<endl;
    c3.printComplex();
    //subtract 2 complex
    c3=Sub(c1,c2);
    cout<<endl<<"Subtract two Complex: "<<endl;
    c3.printComplex();

    //c1+c2
    c3=c1+c2;
    c3.printComplex();

    //c1+10
    c3=c1+10;
    c3.printComplex();

    return 0;
}



void Complex::setReal(int _real)
{
    real = _real;
}

int Complex::getReal() const
{
    return real;
}

void Complex::setImg(int _img)
{
    img = _img;
}

int Complex::getImg() const
{
    return img;
}

Complex Complex::Add(const Complex& right)
{
    Complex retVal;
    retVal.real=this->real+right.real;
    retVal.img=this->img+right.img;
    return retVal;
}

void Complex::printComplex()
{
    cout<<endl<<"the complex num is: "<<endl;
    if(real>0 && img>0)
    {
        if(img==1)
        {
            cout<<real<<"+"<<"i"<<endl;
        }

        else
        {
           cout<<real<<"+"<<img<<"i"<<endl;
        }
    }

    else if(real <0 && img<0)
    {
        cout<<real<<img<<"i"<<endl;
    }

    else if(real>0 && img<0)
    {
        if(img==-1)
        {
            cout<<real<<"i"<<endl;
        }
        else
        {
            cout<<real<<img<<"i"<<endl;
        }
    }


    else if(real==0 && img>0)
    {
        if(img==1)
    {
        cout<<"i"<<endl;
    }
        else
        {
          cout<<img<<"i"<<endl;
        }

    }

    else if(real==0 && img<0)
    {
        if(img==-1)
        {
            cout<<"-"<<"i"<<endl;
        }
        else
        {
         cout<<img<<"i"<<endl;
        }

    }


    else if(real==0 && img==0)
    {
        cout<<"0"<<endl;
    }

    else if(real !=0 && img==0)
    {
        cout<<real<<endl;
    }


}

Complex::Complex()
{
    cout<<"Def ctor"<<endl;
    this->real=0;
    img=0;
}
Complex::Complex(int _real,int _img)
{
    cout<<"2P ctor"<<endl;
    real=_real;
    img=_img;
}
Complex::Complex(int _num)
{
    cout<<"1P ctor"<<endl;
    this->real=_num;
    img=_num;
}

Complex::~Complex()
{
    cout<< "Dest called"<<endl;
}
