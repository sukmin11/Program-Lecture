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

    void push(T data)
    {
        if (m_front == (m_rear + 1) % SIZE)
        {
            cout << "circle queue overflow" << endl;
        }
        else
        {
            m_rear = (m_rear + 1) % SIZE;

            container[m_rear] = data;
        }
    }

    void pop()
    {
        if (m_front == m_rear)
        {
            cout << "circle queue is empty" << endl;
        }
        else
        {
            m_front = (m_front + 1) % SIZE;

            container[m_front] == NULL;
        }
    }

    const bool& empty()
    {
        return m_front == m_rear;
    }

    const T& front()
    {
        return container[(m_front + 1) % SIZE];
    }
};

int main()
{
    Queue<int> queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);

    while (queue.empty() == false)
    {
        cout << queue.front() << endl;
        queue.pop();
    }

    queue.push(10);
    queue.push(20);
    queue.push(30);

    return 0;
}

