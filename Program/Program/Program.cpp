#include <iostream>

using namespace std;

template <typename T>
class Graph
{
private:
    int count; // 인접 행렬의 크기
    int size; // 정점의 개수
    int capacity; // 최대 용량

    T* vertex; // 정점의 집합
    int** matrix; // 인접 행렬
public:
    Graph()
    {
        count = 0;
        size = 0;
        capacity = 0;
        
        vertex = nullptr;
        matrix = nullptr;
    }

    void resize(int newSize)
    {
        capacity = newSize;

        T * container = new T[capacity];

        for (int i = 0; i < capacity; i++)
        {
            container[i] = NULL;
        }

        for (int i = 0; i < size; i++)
        {
            container[i] = vertex[i];
        }

        delete [] vertex;

        vertex = container;
    }

    void push(T data)
    {
        if (capacity <= 0)
        {
            resize(1);
        }
        else if(capacity <= size)
        {
            resize(capacity * 2);
        }

        vertex[size++] = data;
    }

    void edge(int i, int j)
    {
        if (vertex == nullptr)
        {
            cout << "adjacency matrix is empty" << endl;
            return;
        }
        else if (i >= size || j >= size)
        {
            cout << "index out of range" << endl;
            return;
        }

        matrix = new int[size];


        for (int i = 0; i < size; i++)
        {
            matrix[i] = new int[size];
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                matrix[i][j] = NULL;
            }
        }

    }
};

int main()
{
    Graph<char> graph;

    return 0;
}