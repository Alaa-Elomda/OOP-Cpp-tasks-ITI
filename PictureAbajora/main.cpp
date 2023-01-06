#include <iostream>
#include "graphics.h"

using namespace std;


//class shape
class Shape
{
protected:
    int color;
public:
    void setColor(int _color){color = _color;}
    int getColor(){return color;}
    Shape(){color=0;}
    Shape(int _color){color = _color;}
    ~Shape(){}
    Shape(const Shape& old){color = old.color;}

};
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
class Line:public Shape
{
private:
    Point start;
    Point end;
public:
    void setStart(Point _start){start= _start;}
    void setEnd(Point _end){end= _end;}
    Point getStart(){return start;}
    Point getEnd(){return end;}
    Line(){}
    Line(int x1, int y1, int x2, int y2, int _color):start(x1,y1),end(x2,y2),Shape(_color){}
    Line(Point _start, Point _end, int _color):start(_start),end(_end),Shape(_color){}
    ~Line(){}
    Line(const Line& old):start(old.start),end(old.end),Shape(old.color){}

    //draw
    void Draw()
    {
        setcolor(color);
        line(start.getX(),start.getY(),end.getX(),end.getY());
    }
};


//rectangular class
class Rect:public Shape
{
    Point ul;
    Point lr;
public:
    void setUL(Point _ul){ul=_ul;}
    void setLR(Point _lr){lr=_lr;}
    Point getUL(){return ul;}
    Point getLR(){return lr;}
    Rect(){}
    Rect(int x1,int y1,int x2,int y2,int _color):
    ul(x1,y1),lr(x2,y2),Shape(_color){}
    ~Rect(){}
    Rect(const Rect& old):ul(old.ul),lr(old.lr),Shape(old.color){}
    void Draw()
    {
        setcolor(color);
        rectangle(ul.getX(),ul.getY(),lr.getX(),lr.getY());
    }

};

//clas Circle
class Circle:public Shape
{
    Point center;
    int radius;
public:
    Point setCenter(Point _center){center=_center;}
    void setRadius(int _radius){radius=_radius;}
    Point getCenter(){return center;}
    int getRadius(){return radius;}

    Circle(){radius=0;}
    Circle(int x, int y, int _radius, int _color): center(x,y),Shape(_color)
    {
        radius = _radius;
    }
    Circle(const Circle& old): center(old.center),Shape(old.color)
    {
        radius= old.radius;
    }

    ~Circle(){}

    void Draw()
    {
        setcolor(color);
        circle(center.getX(),center.getY(),radius);
    }
};

//triangle
class Triangle:public Shape
{
    Point p1;
    Point p2;
    Point p3;
    public:
    void setP1(Point _p1){p1=_p1;}
    void setP2(Point _p2){p2=_p2;}
    void setP3(Point _p3){p3=_p3;}
    Point getP1(){return p1;}
    Point getP2(){return p2;}
    Point getP3(){return p3;}

    Triangle(){}
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3, int _color):p1(x1,y1),p2(x2,y2),p3(x3,y3),Shape(_color){}
    Triangle(const Triangle& old):p1(old.p1),p2(old.p2),p3(old.p3),Shape(old.color){}
    ~Triangle(){}

    void Draw()
    {
        setcolor(color);
        line(p1.getX(),p1.getY(),p2.getX(),p2.getY());
        line(p2.getX(),p2.getY(),p3.getX(),p3.getY());
        line(p3.getX(),p3.getY(),p1.getX(),p1.getY());

    }
};

//class picture
class Picture
{
private:
    Line* lptr;
    int lsize;
    Rect* rptr;
    int rsize;
    Circle* cptr;
    int csize;
    Triangle* tptr;
    int tsize;

public:
    void setLines(Line* _lptr,int _lsize)
    {
        lptr= _lptr;
        lsize= _lsize;
    }
     void setRects(Rect* _rptr,int _rsize)
    {
        rptr= _rptr;
        rsize= _rsize;
    }
     void setCircles(Circle* _cptr,int _csize)
    {
        cptr= _cptr;
        csize= _csize;
    }
     void setTriangles(Triangle* _tptr,int _tsize)
    {
        tptr= _tptr;
        tsize= _tsize;
    }

    Picture()
    {
        lptr=NULL;
        lsize=0;
        rptr=NULL;
        rsize=0;
        cptr=NULL;
        csize=0;
        tptr=NULL;
        tsize=0;
    }
    Picture(Line* _lptr, int _lsize,Rect* _rptr, int _rsize,Circle* _cptr, int _csize,Triangle* _tptr, int _tsize)
    {
        lptr=_lptr;
        lsize=_lsize;
        rptr=_rptr;
        rsize=_rsize;
        cptr=_cptr;
        csize=_csize;
        tptr=_tptr;
        tsize=_tsize;
    }

    void DoIt()
    {
        for(int i=0; i<lsize;i++)
        {
            lptr[i].Draw();
        }
        for(int i=0; i<rsize;i++)
        {
            rptr[i].Draw();
        }
        for(int i=0; i<csize;i++)
        {
            cptr[i].Draw();
        }
        for(int i=0; i<tsize;i++)
        {
            tptr[i].Draw();
        }
    }

};


int main()
{
    initgraph();

    Picture p1;

    Line larr[2]={Line(379,130,350,323,5),Line(430,130,460,323,5)};
    Circle carr[2]={Circle(404,130,55,80),Circle(404,323,110,80)};
    Rect rarr[2]={Rect(300,400,520,450,60),Rect(390,370,420,400,15)};
    Triangle t(485,415,500,430,470,430,50);

    //Make relationship
    p1.setLines(larr,2);
    p1.setCircles(carr,2);
    p1.setRects(rarr,2);
    p1.setTriangles(&t,1);

    p1.DoIt();

    //cancel relationship
    p1.setLines(NULL,0);
    p1.setRects(NULL,0);
    p1.setCircles(NULL,0);
    p1.setTriangles(NULL,0);



    int x;
    cin>>x;



    return 0;
}
