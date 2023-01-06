#include <iostream>

using namespace std;

//Modified Dynamic stack
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

    //copy constructor
    Stack(const Stack& old)
    {
        this->tos=old.tos;
        size=old.size;
        arr=new int[size];
        for(int i=0; i<tos; i++)
        {
            this->arr[i]=old.arr[i];
        }
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
    void push(int value)
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
    int pop()
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

    //stack reverse
    Stack reverseStack()
    {
        Stack retVal(*this);
        for(int i = 0; i < tos; i++)
        {
            retVal.arr[i] = arr[tos -(i+1)];
        }
        return retVal;
    }

    //=operator s1=s2
    Stack& operator=(const Stack& right)
    {
        delete [] this->arr;
        this->tos=right.tos;
        size=right.size;
        arr=new int[size];
        for(int i=0; i<tos; i++)
        {
            this->arr[i]=right.arr[i];
        }

        return *this;
    }

    //concat 2 stacks s3=s1+s2
    Stack operator+(Stack right)
    {
        Stack retVal(size+right.size);
        retVal.tos= tos + right.tos;
        for (int i=0 ; i<tos ; i++)
        {
            retVal.arr[i] = arr[i];
        }
        for (int i=0 ; i<right.tos; i++)
        {
            retVal.arr[i+tos] =right.arr[i];
        }

        return retVal;
    }

    //s1 == s2
    bool operator==(Stack& right)
    {
        bool isEqualNormal = true;
        bool isEqualReversed = true;

        Stack temp = right.reverseStack();

        for (int i = 0; i < tos; i++)
        {
            if (arr[i] != temp.arr[i])
            {
                isEqualReversed = false;
                break;
            }
        }
        return (isEqualNormal || isEqualReversed);
    }



    void printStack()
    {
        for(int i=0 ; i<tos ; i++)
        {
            cout<<arr[i]<<endl;
        }
    }


};




//initialization for static counter
int Stack::counter=0;


int main()
{
    Stack s1(5), s2(10), s3(15);
    s1.push(10);
    s1.push(20);
    s1.push(30);

    s2.push(10);
    s2.push(20);
    s2.push(30);


    if(s1 == s2)
    {
        cout<<"the same"<<endl;
    }
    else
    {
        cout<<"not the same"<<endl;
    }

    s3=s1+s2;
    cout<<"concat: "<<endl;
    s3.printStack();


    cout<<"reverse: "<<endl;
    s3=s1.reverseStack();
    s3.printStack();

    /*Stack s1,s2,s3,s4(10);
    //push values to s1
    s1.push(10);
    s1.push(20);
    s1.push(60);
    //push values to s4
    s4.push(200);
    s4.push(300);
    //print values
    PrintStack(s1);
    PrintStack(s4);
    //print counter of objects
    cout<<"Number of Objects is: "<<Stack::getCounter()<<endl;*/


    return 0;
}
