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

//class line
class Line
{
private:
    Point start;
    Point end;
    int color;
public:
    void setStart(Point _start){start= _start;}
    void setEnd(Point _end){end= _end;}
    Point getStart(){return start;}
    Point getEnd(){return end;}
    void setColor(int _color){color = _color;}
    int getColor(){return color;}

    Line()
    {
        color = 0;
    }
    Line(int x1, int y1, int x2, int y2, int _color)
    {
        start.setX(x1);
        start.setY(y1);
        end.setX(x2);
        end.setY(y2);
        color=_color;
    }
    Line(Point _start, Point _end, int _color)
    {
        start=_start;
        end=_end;
        color=_color;
    }
    ~Line(){}
    Line(const Line& old)
    {
        start=old.start;
        this->end=old.end;
        this->color=old.color;
    }

    //draw
    void Draw()
    {
        setcolor(color);
        line(start.getX(),start.getY(),end.getX(),end.getY());
    }
};


//rectangular class
class Rect
{
    Point ul;
    Point lr;
    int color;
public:
    void setUL(Point _ul){ul=_ul;}
    void setLR(Point _lr){lr=_lr;}
    Point getUL(){return ul;}
    Point getLR(){return lr;}
    void setColor(int _color){color=_color;}
    int getColor(){return color;}
    Rect()
    {
        color=0;
    }
    Rect(int x1,int y1,int x2,int y2,int _color):
    ul(x1,y1),lr(x2,y2)
    {
        color=_color;
    }
    ~Rect(){}
    Rect(const Rect& old):ul(old.ul),lr(old.lr)
    {
        color=old.color;
    }
    void Draw()
    {
        setcolor(color);
        rectangle(ul.getX(),ul.getY(),lr.getX(),lr.getY());
    }

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

//triangle
class Triangle
{
    Point p1;
    Point p2;
    Point p3;
    int color;
    public:
    void setP1(Point _p1){p1=_p1;}
    void setP2(Point _p2){p2=_p2;}
    void setP3(Point _p3){p3=_p3;}
    void setColor(int _color){color=_color;}
    Point getP1(){return p1;}
    Point getP2(){return p2;}
    Point getP3(){return p3;}
    int getColor(){return color;}

    Triangle()
    {
      color=0;
    }
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3, int _color):p1(x1,y1),p2(x2,y2),p3(x3,y3)
    {
        color=_color;
    }
    Triangle(const Triangle& old):p1(old.p1),p2(old.p2),p3(old.p3)
    {
        color=old.color;
    }
    ~Triangle(){}

    void Draw()
    {
        setcolor(color);
        line(p1.getX(),p1.getY(),p2.getX(),p2.getY());
        line(p2.getX(),p2.getY(),p3.getX(),p3.getY());
        line(p3.getX(),p3.getY(),p1.getX(),p1.getY());

    }
};


int main()
{
    initgraph();

    Circle c1(404,130,55,80);
    Line l1(379,130,350,323,5);
    Line l2(430,130,460,323,5);
    Circle c2(404,323,110,80);
    Rect r1(300,400,520,450,60);
    Rect r2(390,370,420,400,15);
    Triangle t1(485,415,500,430,470,430,50);

    c1.Draw();
    l1.Draw();
    l2.Draw();
    c2.Draw();
    r1.Draw();
    r2.Draw();
    t1.Draw();

    int x;
    cin>>x;


    return 0;
}
/*Circle c3(307,456,50,80);
    Line l3(282,456,257,292,5);
    Line l4(332,456,357,292,5);
    Circle c4(307,292,110,80);
    Rect r3(207,220,407,169,60);
    Rect r4(294,242,320,220,15);
    Triangle t2(381,207,395,182,367,182,50);*/

    /*c3.Draw();
    l3.Draw();
    l4.Draw();
    c4.Draw();
    r3.Draw();
    r4.Draw();
    t2.Draw();*/

    /*Circle c1(525,109,80,80);
    Line l1(561,111,640,425,5);
    Line l2(490,109,420,412,5);
    Circle c2(525,438,210,80);
    Rect r1(511,531,536,553,60);
    Rect r2(338,554,738,602,15);
    Triangle t1(692,571,705,590,679,590,50);*/

