#include <iostream>

using namespace std;

template <class T>

class Node
{
public:

    T data;
    Node<T>* next;

    Node()
    {
        data = T();
        next = nullptr;
    }

    Node(T d)
    {
        data = d;
        next = nullptr;
    }
};

template <class T>

class Stack
{
    int Count;
    Node<T>* top;

public:
    Stack()
    {
        Count = 0;
        top = nullptr;
    }

    Stack(Stack& s)
    {
        Count = 0;
        top = nullptr;

        Node<T>* Copy = s.top;
        while(Copy != nullptr)
        {
            append(Copy->data);
            Copy = Copy->next;
        }
    }

    void append(int value)
	{
		Node<T>* temp = top;
		Node<T>* newnode = new Node<T>(value);
		if (temp==nullptr){
            top=newnode;
		}
		else
        {
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }

		Count++;

	}


    bool isEmpty()
    {
        return (top == nullptr);
    }

    void push(T item)
    {
        Node<T>* temp = new Node<T>(item);
        if(isEmpty())
        {
            temp->next = nullptr;
            top = temp;
        }
        else
        {
            temp->next = top;
            top = temp;
        }
        Count++;
    }

    T pop()
    {
        T value;
        if(isEmpty())
        {
            cout<<"Stack is empty you can't pop anymore.";
        }
        else
        {
            Node<T>* temp = top;
            top = top->next;
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
            cout<<"Stack is Empty";
        }
        else
        {
            Node<T>* temp = top;
            while(temp != nullptr)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }

    int Couter()
    {
        int Count = 0;
        Node<T>* temp = top;
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
    Stack<int> S;

    int num = 0, item;

    cout<<"Enter the number of items you want to push: ";
    cin>>num;

    for(int i=1; i<=num; i++)
    {
        cout<<"Enter item no."<<i<<" you want to push:"<<endl;
        cin>>item;
        S.push(item);
    }

    cout<<"The items in the stack:"<<endl;
    S.display();

    Stack<int> lst(S);
	cout<<"The copied Stack:"<<endl;
	lst.display();

	S.pop();
	S.pop();

	cout<<"The items in the stack after using pop:"<<endl;
    S.display();

    cout<<"Number of items in the stack: "<<S.Couter()<<endl;


    return 0;
}
