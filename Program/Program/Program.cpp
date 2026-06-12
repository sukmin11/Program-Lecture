#include <iostream>

using namespace std;

template<typename T>
class List
{
private:
    struct Node {
        T data;
        Node* next;
        Node* previous;
    };

    int size;
    Node* head;
    Node* tail;

public:
    List()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    void push_front(T data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        if (size == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            head->previous = newNode;
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
};

int main()
{
    List<int> list;
    list.push_front(10);

    return 0;
}

