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
    //pure virtual fn
    virtual float CArea()=0;

};

//class Rectangular
class Rect:public Geoshape
{
public:
    Rect(float _dim1,float _dim2):Geoshape(_dim1,_dim2) {}
    float CArea() override
    {
        return dim1*dim2;
    }
};

//class Square
class Square:public Rect
{
public:
    Square(float _dim):Rect(_dim,_dim){}
};

//class Circle
class Circle:public Geoshape
{
public:
    Circle(float _radius):Geoshape(_radius,_radius) {}
    float CArea() override
    {
        return 3.14*dim1*dim2;
    }
};

//class Triangle
class Tri:public Geoshape
{
public:
    Tri(float _base,float _height):Geoshape(_base,_height) {}
    float CArea() override
    {
        return 0.5*dim1*dim2;
    }

};
float SumOfAreas(Geoshape* gparam[],int size)
{
    float sum=0;
    for(int i=0;i<size;i++)
    {
        sum+=gparam[i]->CArea();
    }
    return sum;
}



int main()
{


    Rect r(3,4);
    Square s(4);
    Circle c(5);
    Tri t(3,4);

    Geoshape* gptr[4] = {&r,&s,&c,&t};

    cout<<"Area of The Rectangle: " << gptr[0]->CArea()<<endl;
    cout<<"Area of The Square: " << gptr[1]->CArea()<<endl;
    cout<<"Area of The Circle: " << gptr[2]->CArea()<<endl;
    cout<<"Area of The Triangle: " << gptr[3]->CArea()<<endl<<endl;

    cout<<"Sum of Areas: "<<SumOfAreas(gptr,4)<<endl;



    return 0;
}
