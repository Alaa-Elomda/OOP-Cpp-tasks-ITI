#include <iostream>

using namespace std;

//Dynamic stack
class Stack
{
private:
    int* arr;
    int tos;
    int size;

    static int counter;

public:
    static int getCounter()
    {
        return counter;
    }

    //constructor
    Stack()
    {
        counter++;
        cout<<"def ctor"<<endl;
        tos=0;
        size=5;
        arr=new int[size];
    }

    Stack(int _size)
    {
        counter++;
        cout<<"ctor"<<endl;
        tos=0;
        size=_size;
        arr=new int[size];
    }

    //destructor
    ~Stack()
    {
        counter--;
        cout<<"dest"<<endl;
        //Redundant
        for(int i=0; i<size; i++)
        {
            arr[i]=-55;
        }
        delete[] arr;
    }

    //push values to the stack
    void Push(int value)
    {
        if(!IsFull())
        {
            arr[tos]=value;
            tos++;
        }
        else
        {
            cout<<"FULL !!!"<<endl;
        }
    }

    //pop values from the stack
    int Pop()
    {
        int retVal=-11111;
        if(!IsEmpty())
        {
            tos--;
            retVal=arr[tos];
        }
        else
        {
            cout<<"EMPTY !!!"<<endl;
        }

        return retVal;
    }

    //check if the stack is full or empty
    int IsFull()
    {
        return this->tos==size;
    }
    int IsEmpty()
    {
        return this->tos==0;
    }

    //make it friend to access tos and arr[i]
    friend void PrintStack(Stack param);
};

//standalone fn for print
void PrintStack(Stack param)
{
    cout<<"Values in the Stack: "<<endl;

    for(int i=0; i<param.tos; i++)
    {
        cout<<param.arr[i]<<endl;
    }
}

//initialization for static counter
int Stack::counter=0;


int main()
{
    Stack s1,s2,s3,s4(10);
    //push values to s1
    s1.Push(10);
    s1.Push(20);
    s1.Push(60);
    //push values to s4
    s4.Push(200);
    s4.Push(300);
    //print values
    PrintStack(s1);
    PrintStack(s1);
    PrintStack(s4);
    //print counter of objects
    cout<<"Number of Objects is: "<<Stack::getCounter()<<endl;


    return 0;
}


