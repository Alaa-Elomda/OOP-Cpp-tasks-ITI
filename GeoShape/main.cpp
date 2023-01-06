#include <iostream>

using namespace std;

//class geoshape
class Geoshape
{
protected:
    float dim1,dim2;

public:
    void setDim1(float _dim1){dim1 = _dim1;}
    void setDim2(float _dim2){dim2 = _dim2;}
    float getDim1(){return dim1;}
    float getDim2(){return dim2;}
    Geoshape(){dim1=dim2=0;}
    Geoshape(float _dim1,float _dim2){dim1 = _dim1; dim2 = _dim2;}
    Geoshape(const Geoshape& old){this->dim1 = old.dim1; this->dim2 = old.dim2;}
    ~Geoshape(){}

};

//class Rectangular
class Rect:public Geoshape
{
public:
    Rect(float _dim1,float _dim2):Geoshape(_dim1,_dim2){}
    float CArea(){return dim1*dim2;}
};

//class Square
class Square:public Rect
{
public:
    Square(float _dim):Rect(_dim,_dim){}
};

//class Circle
class Circle:protected Geoshape
{
public:
    Circle(float _radius):Geoshape(_radius,_radius){}
    float CArea(){return 3.14*dim1*dim2;}
};

//class Triangle
class Tri:public Geoshape
{
public:
    Tri(float _base,float _height):Geoshape(_base,_height){}
    float CArea(){return 0.5*dim1*dim2;}

};


int main()
{
    Rect r(3,4);
    Square s(4);
    Circle c(5);
    Tri t(3,4);

    cout<<"Area of The Rectangle: " << r.CArea()<<endl;
    cout<<"Area of The Square: " << s.CArea()<<endl;
    cout<<"Area of The Circle: " << c.CArea()<<endl;
    cout<<"Area of The Triangle: " << t.CArea()<<endl;

    return 0;
}
