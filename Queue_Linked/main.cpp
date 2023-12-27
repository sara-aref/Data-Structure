#include <iostream>

using namespace std;

template <class T>

class Node
{
public:

    T data;
    Node<T>* next;
    Node<T>* prev;

    Node()
    {
        data = T();
        next = prev = nullptr;
    }

    Node(T d)
    {
        data = d;
        next = prev = nullptr;
    }
};

template <class T>

class Queue
{
    int Count;
    Node<T>* Front;
    Node<T>* Rear;

public:
    Queue()
    {
        Count = 0;
        Front = Rear = nullptr;
    }

    bool isEmpty()
    {
        return ((Front == nullptr) && (Rear == nullptr));
    }

    void enqueue(int item)
    {
        Node<T>* temp = new Node<T>(item);
        if(isEmpty())
        {
            temp->next = temp->prev = nullptr;
            Front = Rear = temp;
        }
        else
        {
            Rear->next = temp;
            Rear = temp;
            temp->next = nullptr;
        }
        Count++;
    }

    T dequeue()
    {
        T value;
        if(isEmpty())
        {
            cout<<"Queue is empty you can't dequeue any more.";
        }
        else
        {
            Node<T>* temp = Front;
            Front = Front->next;
            value = temp->data;
            delete temp;
            Count--;
            return value;
        }
    }

    void display()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty";
        }
        else
        {
            Node<T>* temp = Front;
            while(temp != nullptr)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }

    int Counter()
    {
        int Count = 0;
        Node<T>* temp = Front;
        while(temp != nullptr)
        {
            Count++;
            temp = temp->next;
        }
        return Count;
    }
};

int main()
{
    Queue<int> q;

    int num = 0, item;

    cout<<"Enter the number of items you want to enqueue: ";
    cin>>num;

    for(int i=1; i<=num; i++)
    {
        cout<<"Enter item no."<<i<<" you want to enqueue:"<<endl;
        cin>>item;
        q.enqueue(item);
    }

    cout<<"The items in the queue:"<<endl;
    q.display();

    q.dequeue();
    q.dequeue();

    cout<<"The items in the queue after using dequeue:"<<endl;
    q.display();

    cout<<"Number of items in the queue: "<<q.Counter()<<endl;

    return 0;
}
