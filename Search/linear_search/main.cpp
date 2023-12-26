#include <iostream>
#include <string.h>

using namespace std;

class employee
{
private:
    int id;
    string name;
    int salary;

public:
    employee(int _id, string _name, int _salary)
    {
        id = _id;
        name = _name;
        salary = _salary;
    }
    void setId(int _id)
    {
        id = _id;
    }
    int getId()
    {
        return id;
    }
    void setName(string _name)
    {
        name = _name;
    }
    string getName()
    {
        return name;
    }
    void setSalary(int _salary)
    {
        salary = _salary;
    }
    int getSalary()
    {
        return salary;
    }
};

int SearchId(employee arr[], int Size, int item)
{
    int index=-1;
    for(int i=0; i<Size ;i++)
    {
        if(arr[i].getId() == item)
        {
            cout<<"Found ID"<<endl;
            index =i;
            return index;
        }
    }
}

int SearchName(employee arr[], int Size, string item)
{
    int index=-1;
    for(int i=0; i<Size ;i++)
    {
        if(arr[i].getName() == item)
        {
            cout<<"Found Name"<<endl;
            index =i;
            return index;
        }
    }
}

int SearchSalary(employee arr[], int Size, int item)
{
    int index=-1;
    for(int i=0; i<Size ;i++)
    {
        if(arr[i].getSalary() == item)
        {
            cout<<"Found Salary"<<endl;
            index =i;
            return index;
        }
    }
}

int main()
{
    employee e1(50, "Sara", 2000);
    employee e2(6, "Aya", 3000);
    employee e3(16, "Menna", 5000);
    employee e4(7, "Shimaa", 6000);

    employee employees[] = {e1, e2, e3, e4};

    cout<< SearchId( employees, 4, 50)<<endl;


    cout<< SearchName(employees, 4, "Aya")<<endl;


    cout<< SearchSalary( employees, 4, 6000)<<endl;



    return 0;
}
