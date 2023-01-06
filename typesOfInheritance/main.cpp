#include <iostream>

using namespace std;

class Parent
{
    private:
    int x;
    protected:
    int y;
    public:
    int z;
    void setX(int _x){x=_x;}
    void setY(int _y){y=_y;}
    void setZ(int _z){z=_z;}
    int getX(){return x;}
    int getY(){return y;}
    int getZ(){return z;}
    Parent()
    {
        x=y=z=0;
    }
    Parent(int _x, int _y, int _z)
    {
        x=_x;
        y=_y;
        z=_z;
    }
    Parent(const Parent &p)
    {
        x=p.x;
        y=p.y;
        z=p.z;
    }
    ~Parent()
    {
    }
    int sum()
    {
        return x+y+z;
    }
};
class Child :public Parent
{
    private:
    int a;
    protected:
    int b;
    public:
    int c;
    void setA(int _a){a=_a;}
    void setB(int _b){b=_b;}
    void setC(int _c){c=_c;}
    int getA(){return a;}
    int getB(){return b;}
    int getC(){return c;}
    Child()
    {
        a=b=c=0;
    }
    Child(int _x,int _y, int _z,int _a,int _b,int _c):Parent(_x,_y,_z)
    {
        a=_a;
        b=_b;
        c=_c;
    }
   Child(Child &ch):Parent(ch.getX(),ch.y,ch.z)
    {
        a=ch.a;
        b=ch.b;
        c=ch.c;
    }
    ~Child()
    {
    }
    int sum()
    {
        return a+b+c+y+z+getX();
    }
};
class SubChild:protected Child
{
    private:
    int j;
    protected:
    int k;
    public:
    int l;
    SubChild()
    {
        j=k=l=0;
    }
    SubChild(int _x,int _y, int _z,int _a,int _b,int _c,int _j,int _k,int _l)
    :Child(_x,_y,_z,_a,_b,_c)
    {
        j=_j;
        k=_k;
        l=_l;
    }
   SubChild(SubChild &sch)
   :Child(sch.getA(),sch.b,sch.c,sch.getX(),sch.y,sch.z)
    {
        j=sch.j;
        k=sch.k;
        l=sch.l;
    }
    ~SubChild()
    {
    }
    int sum()
    {
        return j+k+l+Child::sum();
    }
};
class SubChildTwo:private Child
{
    private:
    int j;
    protected:
    int k;
    public:
    int l;
    SubChildTwo()
    {
        j=k=l=0;
    }
    SubChildTwo(int _x,int _y, int _z,int _a,int _b,int _c,int _j,int _k,int _l)
    :Child(_x,_y,_z,_a,_b,_c)
    {
        j=_j;
        k=_k;
        l=_l;
    }
   SubChildTwo(SubChildTwo &sch)
   :Child(sch.getA(),sch.b,sch.c,sch.getX(),sch.y,sch.z)
    {
        j=sch.j;
        k=sch.k;
        l=sch.l;
    }
    ~SubChildTwo()
    {
    }
    int sum()
    {
        return j+k+l+Child::sum();
    }
};

int main()
{
    Parent p1(1,2,3);
    Child c1(1,2,3,4,5,6);
    SubChild sc1(1,2,3,4,5,6,7,8,9);
    SubChildTwo sc2(1,2,3,4,5,6,7,8,9);

    cout << sc2.sum() << endl;
    return 0;
}
