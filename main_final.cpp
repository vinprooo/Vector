#include <iostream>

using namespace std;

class myVector
{
private:
    int number;
    int capacity;
    int *ptr;

public:
    friend ostream &operator<<(ostream &cout, myVector &rhs)
    {
        for (int i = 0; i < rhs.number; i++)
        {
            cout << rhs.ptr[i] << " ";
        }

        cout << " || ";

        for (int i = rhs.number; i < rhs.capacity; i++)
        {
            cout << rhs.ptr[i] << " ";
        }

        cout << endl;

        return cout;
    }

    // Constructor
    myVector()
        : number{0}, capacity{5}, ptr{new int[capacity]}
    {
    }

    myVector(const initializer_list<int> &list)
        : number{0}, capacity{list.size() + 5}, ptr{new int[capacity]}
    {
        for (int i : list)
        {
            push_back(i);
        }
    }

    // Copy Constructor
    myVector(const myVector &rhs)
        : number{rhs.number}, capacity{rhs.capacity + 5}, ptr{new int[capacity]}
    {
        for (int i = 0; i < rhs.number; ++i)
        {
            ptr[i] = rhs.ptr[i];
        }
    }

    // Deep Copying
    myVector(int element, int value = 0)
        : number{element}, capacity{element + 5}, ptr{new int[capacity]}
    {
        for (int i = 0; i < number; ++i)
        {
            ptr[i] = value;
        }
    }

    // Destructor
    ~myVector()
    {
        delete[] ptr;
    }

    // Copy Assignment Constructor
    myVector &operator=(const myVector &rhs)
    {
        if (rhs.number > number)
        {
            delete[] ptr;
            capacity = rhs.number + 5;
            ptr = new int[capacity];
        }
        for (int i = 0; i < rhs.number; i++)
        {
            ptr[i] = rhs.ptr[i];
        }
        number = rhs.number;

        return *this;
    }

    // function to add element at the last
    void push_back(int data)
    {
        if (number < capacity)
        {
            ptr[number] = data;
            number++;
        }
        else
        {
            capacity *= 2;
            int *new_ptr = new int[capacity];
            for (int i = 0; i < number; i++)
            {
                new_ptr[i] = ptr[i];
            }
            new_ptr[number] = data;
            number++;
            delete[] ptr;
            ptr = new_ptr;
        }
    }

    // function to delete last element
    void pop_back()
    {
        if (number == 0)
        {
            cout << "Empty vector!";
        }
        number--;
    }

    // function to check vector empty
    bool empty()
    {
        return number == 0;
    }

    // function to get size of the vector
    int size()
    {
        return number;
    }

    // function to get capacity of the vector
    int capa()
    {
        return capacity;
    }

    // function to get the first element
    int front()
    {
        return ptr[0];
    }

    // function to get the last element
    int back()
    {
        return ptr[number - 1];
    }

    // function to access element at any index
    int operator[](int index)
    {
        return ptr[index];
    }

    int At(int index)
    {
        if ((index < 0) || (index >= number))
        {
            cout << "AT - Index out of range!";
        }
        return ptr[index];
    }

    // function to add element at any index
    void insert(int data, int index)
    {
        if ((index < 0) || (index >= number))
        {
            cout << "Insert - Index out of range!";
        }

        if (number != capacity)
        {
            for (int i = number - 1; i >= index; --i)
            {
                ptr[i + 1] = ptr[i];
            }
            ptr[index] = data;
            number++;
        }
        else
        {
            capacity *= 2;
            int *new_ptr = new int[capacity];
            for (int i = 0; i < number; i++)
            {
                new_ptr[i] = ptr[i];
            }
            delete[] ptr;
            ptr = new_ptr;
            insert(index, data);
        }
    }

    // function to erase element at any index
    void erase(int index)
    {
        if ((index < 0) || (index >= number))
        {
            cout << "Erase - Index out of range!";
        }

        for (int i = index; i < number - 1; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        number--;
    }

    // function to clear vector
    void clear()
    {
        number = 0;
    }
};

int main()
{
    myVector v;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
        cout << v;
    }

    myVector w;
    w.push_back(4);

    w = v;
    cout << w;
    w.erase(4);
    cout << w;
    w.erase(7);
    cout << w;

    w.insert(4, 1); // data - index
    cout << w;

    cout << w.size() << endl;

    v.clear();

    cout << v.size() << endl;


    // v.push_back(10); // OK
    // v.push_back(20);
    // v.push_back(30);
    // v.push_back(40);
    // v.pop_back(); // OK

    // cout << v << endl;

    // // Use copy constructor
    // myVector cp{v};
    // cout << cp << endl;

    // myVector vv{1, 2, 3, 4, 5, 6, 7, 8, 9};
    // cout << vv << endl;

    return 0;
}