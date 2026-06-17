#include <iostream>

using namespace std;

template<typename T>
class Vector
{
private:
    T* container;
    int m_size;
    int capacity;

public:

    Vector()
    {
        m_size = 0;
        capacity = 0;
        container = nullptr;
    }

    const int& size()
    {
        return m_size;
    }

    const int& operator [] (int index)
    {
        return container[index];
    }

    ~Vector()
    {
        delete [] container;
    }
};

int main()
{
    Vector<int> vector;


    return 0;
}

