#include <iostream>
#include "graphics.h"

using namespace std;

//class point
class Point
{
    int x;
    int y;
public:
    void setX(int _x){x = _x;}
    void setY(int _y){y = _y;}
    int getX (){return x;}
    int getY (){return y;}
    Point(){x=y=0;}
    Point(int _x,int _y){x=_x;y=_y;}
    Point(int _num){x=y=_num;}
    ~Point(){}
    Point(const Point& old){x=old.x;y=old.y;}
};

//clas Circle
class Circle
{
    Point center;
    int radius;
    int color;
public:
    Point setCenter(Point _center){center=_center;}
    void setRadius(int _radius){radius=_radius;}
    void setColor(int _color){color=_color;}
    Point getCenter(){return center;}
    int getRadius(){return radius;}
    int getColor(){return color;}

    Circle()
    {
        radius=0;
        color=0;
    }
    Circle(int x, int y, int _radius, int _color): center(x,y)
    {
        radius = _radius;
        color = _color;
    }
    Circle(const Circle& old): center(old.center)
    {
        radius= old.radius;
        color= old.color;
    }

    ~Circle(){}

    void Draw()
    {
        setcolor(color);
        circle(center.getX(),center.getY(),radius);
    }
};

int main()
{
    initgraph();

    //paint coordinate
    /*Circle c1(505,143,150,80);
    Circle c2(711,286,150,80);
    Circle c3(505,423,150,80);
    Circle c4(305,286,150,80);

    Circle c5(629,178,150,80);
    Circle c6(620,404,150,80);
    Circle c7(370,418,150,80);
    Circle c8(370,174,150,80);*/

    //CAD coordinate
    Circle c1(274,415,140,5);
    Circle c2(429,260,140,5);
    Circle c3(274,105,140,5);
    Circle c4(120,260,140,5);

    Circle c5(384,369,140,5);
    Circle c6(384,151,140,5);
    Circle c7(165,151,140,5);
    Circle c8(165,369,140,5);






    while(1)
    {
        c1.Draw();
        c2.Draw();
        c3.Draw();
        c4.Draw();

        Sleep(50);
        system("cls");

        c5.Draw();
        c6.Draw();
        c7.Draw();
        c8.Draw();

        Sleep(50);
        system("cls");


    }

    return 0;
}
