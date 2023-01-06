#include <iostream>

using namespace std;
//Complex
class Complex
{
private:
    int real;
    int img;
public:
    void setReal(int _real);
    int getReal()const ;
    void setImg(int _img);
    int getImg()const ;
    Complex Add(const Complex& right);
    void printComplex();
    Complex();
    Complex(int _real,int _img);
    Complex(int _num);
    ~Complex();
};

Complex Sub( const Complex& left,const Complex& right)
{
    Complex retVal;
    retVal.setReal(left.getReal()-right.getReal());
    retVal.setImg(left.getImg()-right.getImg());
    return retVal;
}


int main()
{
    Complex c1,c2,c3(0,0);
    c1.setReal(1);
    c1.setImg(2);
    c2.setReal(3);
    c2.setImg(4);
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



















/*#include <iostream>

using namespace std;

class Complex
{
private:
    int real;
    int img;
public:
    void setReal(int _real);
    int getReal();
    void setImg(int _img);
    int getImg();
    Complex Add(Complex right);
    void printComplex();
    Complex();
    Complex(int _real,int _img);
    Complex(int _num);
    ~Complex();
};

Complex Sub(Complex left,Complex right)
{
    Complex retVal;
    retVal.setReal(left.getReal()-right.getReal());
    retVal.setImg(left.getImg()-right.getImg());

    return retVal;
}


int main()
{
    Complex c1,c2,c3,c4;
    c1.setReal(-1);
    c1.setImg(-2);
    c2.setReal(-3);
    c2.setImg(-4);

    c1.printComplex();
    c2.printComplex();

    c3= c1.Add(c2);
    c3.printComplex();

    c4=Sub(c1,c2);
    c4.printComplex();

    return 0;
}



void Complex::setReal(int _real)
{
    real = _real;
}

int Complex::getReal()
{
    return real;
}

void Complex::setImg(int _img)
{
    img = _img;
}

int Complex::getImg()
{
    return img;
}

Complex Complex::Add(Complex right)
{
    Complex retVal;
    retVal.real=this->real+right.real;
    retVal.img=this->img+right.img;
    return retVal;
}

void Complex::printComplex()
{
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

    else if(real>0 && img<0)
    {
        if(img==-1)
        {
            cout<<real<<"-"<<"i"<<endl;
        }
        else
        {
            cout<<real<<"-"<<img<<"i"<<endl;
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
            cout<<"-"<<img<<"i"<<endl;
        }

    }


    else if(real==0 && img==0)
    {
        cout<<"0"<<endl;
    }

    else if(real>0 && img==0)
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
}*/














