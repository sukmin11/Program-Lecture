#include <iostream>

using namespace std;

template<typename KEY, typename VALUE>
class HashTable
{
private:
    struct Node
    {
        KEY key;
        VALUE value;
        Node* next;
    };

    struct Bucket
    {
        int count;
        Node* head;
    };

    int size;
    int capacity;

    Bucket* bucket;

public:
    HashTable()
    {
        size = 0;
        capacity = 8;
        bucket = new Bucket[capacity];
        
        for (int i = 0; i < capacity; i++)
        {
            bucket[i].head = nullptr;
            bucket[i].count = 0;
        }
    }

    template<typename KEY>
    unsigned int hash_function(KEY key)
    {
        return (unsigned int)key % capacity;
    }

    template<>
    unsigned int hash_function(const char* key)
    {
        int sum = 0;
        while (*key != NULL)
        {
            sum = (unsigned int)*(key++);
        }
        return sum % capacity;
    }

};

int main()
{
    HashTable<const char *, int> hashTable;
    cout << hashTable.hash_function("League of Legend") << endl;
    cout << hashTable.hash_function("Yasuo") << endl;
    cout << hashTable.hash_function("Janna") << endl;

    return 0;
}

