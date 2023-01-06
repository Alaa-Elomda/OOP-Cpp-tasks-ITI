#include <iostream>

#define SIZE 5

using namespace std;

//static shift Queue
class Queue
{
private:
    int myQueue[SIZE];
    int head, tail;

public:
    //constructor
    Queue()
    {
        head = -1;
        tail = -1;
    }

    //check the availability of the queue (empty or full)
    int isFull()
    {
        if(head == 0 && tail ==SIZE-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int isEmpty()
    {
        if(head == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    //push value to the queue
    void enQueue(int value)
    {
        if(isFull())
        {
            cout<< endl<< "Queue is Full!!!";
        }
        else
        {
            if(head == -1)
            {
                head =0;
            }
            tail++;
            myQueue[tail] = value;
            cout<<value<<" ";
        }
    }

    //pop value from the queue
    int deQueue()
    {
        int value;
        if(isEmpty())
        {
            cout<<"Queue is Empty!!" << endl;
            return -1;
        }
        else
        {
            value = myQueue[head];
            if(head >= tail)       //only one element in queue
            {
                head = -1;
                tail = -1;
            }
            else
            {
                head++;
            }
            cout << endl << "Deleted => " << value << " from myqueue";
            return(value);
        }
    }

    //print the values in the queue
    void printQueue()
    {
        int i;
        if(isEmpty())
        {
            cout << endl << "Queue is Empty!!" << endl;
        }
        else
        {
            cout << endl << "Head = " << head;
            cout << endl << "Queue elements : ";
            for(i=head; i<=tail; i++)
                cout << myQueue[i] << "\t";
            cout << endl << "Tail = " << tail << endl;
        }
    }
};

int main()
{
    Queue myq;

    myq.deQueue();

    cout<<"Queue created:"<<endl;
    myq.enQueue(10);
    myq.enQueue(20);
    myq.enQueue(30);
    myq.enQueue(40);
    myq.enQueue(50); //enqueue 60 => queue is full
    myq.enQueue(60);

    myq.printQueue();

    //deQueue (removes 10)
    myq.deQueue();

    //queue after dequeue
    myq.printQueue();

    return 0;
}
