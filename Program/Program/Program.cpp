#include <iostream>

using namespace std;

template<typename T>
class PriorityQueue
{
private:
    T* container;
    int capacity;
    int index;
public:
    PriorityQueue()
    {
        container = nullptr;
        capacity = 0;
        index = 0;
    }

    void resize(int newSize)
    {
        capacity = newSize;

        T* temporary = new T[capacity];

        for (int i = 0; i < capacity; i++)
        {
            temporary[i] = NULL;
        }
        for (int i = 0; i < index; i++)
        {
            temporary[i] = container[i];
        }

        delete[] container;

        container = temporary;
    }
};

int main()
{
    PriorityQueue<int> priorityQueue;

    priorityQueue.resize(2);

    return 0;
}

