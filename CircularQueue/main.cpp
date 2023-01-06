#include <iostream>

#define SIZE 5

using namespace std;

//circular Queue
class Queue
{
private:
    int myQ[SIZE];
    int head, tail;

public:
    //constructor
    Queue()
    {
        head = -1;
        tail = -1;
    }

    //check the availability of the queue (full or empty)
    int isFull()
    {
        if (head == 0 && tail == SIZE - 1)
        {
            return 1;
        }
        if (head == tail + 1)
        {
            return 1;
        }
        return 0;
    }

    int isEmpty()
    {
        if (head == -1)
            return 1;
        else
            return 0;
    }

    //push value to the queue
    void enQueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full";
        }
        else
        {
            if (isEmpty())
                head = 0;
            tail = (tail + 1) % SIZE;
            myQ[tail] = value;
        }
    }

    //pop value from the queue
    int deQueue()
    {
        int value;
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            value = myQ[head];
            if (head == tail)
            {
                head = -1;
                tail = -1;
            }
            // Q has only one element,
            // so we reset the queue after deleting it.
            else
            {
                head = (head + 1) % SIZE;
            }
            return (value);
        }
    }

    //print the values in the queue
    void printQueue()
    {
        int i;
        if (isEmpty())
        {
            cout << endl<< "Empty Queue" << endl;
        }
        else
        {
            for (i = head; i != tail; i = (i + 1) % SIZE)
                cout << myQ[i]<<" ";
            cout << myQ[i]<<" "<<endl;

        }
    }
};

int main()
{
    Queue q;
    //push values to the queu
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);

    //print the values
    cout<<"Values of all items in circular queue is: "<<endl;
    q.printQueue();
    cout<<endl;

    //pop value
    q.deQueue();
    cout<<"Values of q items after dequeue is: "<<endl;
    q.printQueue();
    cout<<endl;

    //push value
    q.enQueue(7);
    cout<<"Values of q items after enqueue no. 7 is: "<<endl;
    q.printQueue();
    cout<<endl;

    //try to push one more element when the queue is full
    q.enQueue(8);
    cout<<endl;

    return 0;
}

