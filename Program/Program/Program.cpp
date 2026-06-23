#include <iostream>
#define SIZE 4

using namespace std;

template<typename T>
class Queue
{
private:
    T container[SIZE];
    
    int m_rear, m_front;
public:
    Queue()
    {
        m_rear = SIZE - 1, m_front = SIZE - 1;
        for (int i = 0; i < SIZE; i++)
        {
            container[i] = NULL;
        }
    }
};

int main()
{
    Queue<int> queue;


    return 0;
}

