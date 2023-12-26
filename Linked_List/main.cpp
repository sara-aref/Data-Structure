#include <iostream>

using namespace std;

template<class T>

class Node
{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node<T>()
    {
        data=T();
        next=prev=nullptr;
    }
    Node<T>(T d)
    {
        data=d;
        next=prev=nullptr;
    }
    ~Node<T>() {}
};

template<class T>

class linkedList
{
    Node<T>* head;
    Node<T>* tail;

    int Count;
public:
    linkedList()
    {
        head = tail = nullptr;
        Count = 0;
    }

    linkedList(linkedList& List)
    {
        head = tail = nullptr;
        Count = 0;
        Node<T>* Copy=List.head;
        while (Copy != nullptr)
        {
            this->add(Copy->data);
            Copy = Copy->next;
        }
    }

    bool isEmpty()
    {
        return (head == nullptr);
    }

    void add(T item)
    {
        Node<T>* pItem = new Node<T>(item);
        if(isEmpty())
        {
            head = tail = pItem;
        }
        else
        {
            tail->next = pItem;
            pItem->prev = tail;
            tail = pItem;
        }
        Count++;
    }

    void display()
	{
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void clearList()
	{
	    Node<T>* temp = head;
		while (temp != nullptr)
		{
			head = head->next;
			delete temp;
			temp = head;
		}
		head = tail = nullptr;
		Count = 0;
	}

	Node<T>* Search(T item)
	{
		Node<T>* temp = head;
		while ((temp != nullptr) && (temp->data != item))
		{
			temp = temp->next;
		}
		return temp;
	}

	void Delete(T data)
	{
	    Node<T>* temp = Search(data);
	    if(temp == nullptr)
        {
            cout<<"Data not found";
        }
        else
        {
            if(temp == head)
            {
                if(temp == tail)
                {
                    delete temp;
                    head = tail = nullptr;
                }
                else
                {
                    head = head->next;
                    head->prev = nullptr;
                    delete temp;
                }
            }
            else
            {
                if(temp == tail)
                {
                    tail = tail->prev;
                    tail->next = nullptr;
                    delete temp;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                }
            }
            Count--;
        }
	}

	void insertAfter(T after, T data)
	{
	    Node<T>* temp = Search(after);
	    if(temp == nullptr)
        {
            cout<<"Data not found";
        }
        else
        {
            if(temp == tail)
            {
                add(data);
            }
            else
            {
                Node<T>* pnew = new Node<T>(data);
                pnew->prev = temp;
                pnew->next = temp->next;
                temp->next = pnew;
                temp->next->prev = pnew;
            }
            Count++;
        }
	}

	int counter()
	{
		int Count = 0;
		Node<T>* temp = head;
		while (temp != NULL)
		{
			Count++;
			temp = temp->next;
		}
		return Count;
	}

};


int main()
{
    linkedList<int> lst;

    int num = 0, item = 0;

    cout<<"Enter number of items you want to insert: ";
    cin>>num;

    for(int i=1; i<=num; i++)
    {
        cout << "Enter Item no."<<i<<" to insert in the list."<<endl;
        cin >> item;
        lst.add(item);
    }

	lst.display();

    cout<<endl;


	cout << "Enter  item to delete:"<<endl;
	cin >> item;
	lst.Delete(item);

	lst.display();

	cout<<endl;

	int newvalue;

	cout << "Enter new Item to insert:"<<endl;
	cin >> newvalue;
	cout << "Enter Item you will insert after:"<<endl;
	cin >> item;

	lst.insertAfter(item, newvalue);

	lst.display();

	cout<<endl;

	cout << "The List contains: " << lst.counter() << endl;

	linkedList<int> List = lst;
	cout<<"The copied Linked List:"<<endl;
	List.display();

	cout<<endl;

	lst.clearList();

	if (lst.isEmpty())
    {
        cout << "The List is Empty \n";
    }
	else
    {
        cout << "The List contains: " << lst.counter() << endl;
    }


    return 0;
}
