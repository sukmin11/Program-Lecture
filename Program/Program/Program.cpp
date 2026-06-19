#include <iostream>

using namespace std;

template<typename T>
class Stack
{
private:
    int capacity;
    int highset;

    T* container;

public:

    Stack()
    {
        capacity = 0;
        highset = -1;
        container = nullptr;
    }

    void resize(int newSize)
    {
        capacity = newSize;
        T* temporary = new T[capacity];
        for (int i = 0; i < capacity; i++)
        {
            temporary[i] = NULL;
        }
        for (int i = 0; i < highset + 1; i++)
        {
            temporary[i] = container[i];
        }
        delete[] container;
        container = temporary;
    }

    void push(T data)
    {
        if (capacity <= 0)
        {
            resize(1);
        }
        else if (highset + 1 >= capacity)
        {
            resize(capacity * 2);
        }

        container[++highset] = data;
    }

    void pop()
    {
        if (highset <= -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            container[highset--] = NULL;
        }
    }

    const bool& empty()
    {
        return highset == -1;
    }

    const int& size()
    {
        return highset + 1;
    }

    const T& top()
    {
        return container[highset];
    }

    ~Stack()
    {
        while (highset != -1)
        {
            pop();
        }
    }
};

int main()
{
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    while (stack.empty() != 1)
    {
        cout << stack.top() << endl;
        stack.pop();
    }

    return 0;
}

