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
        unsigned int sum = 0;

        for (int i = 0; *key != '\0'; i++)
        {
            sum += key[i];

            key = key + 1;
        }

        return sum % capacity;
    }


    void insert(KEY key, VALUE value)
    {
        int hashIndex = hash_function(key);

        Node* newNode = new Node;
        newNode->key = key;
        newNode->value = value;
        newNode->next = nullptr;

        if (bucket[hashIndex].count == 0)
        {
            bucket[hashIndex].head = newNode;
        }
        else
        {
            newNode->next = bucket[hashIndex].head;

            bucket[hashIndex].head = newNode;
        }

        bucket[hashIndex].count++;

        size++;
    }

    void erase(KEY key)
    {
        int hashIndex = hash_function(key);

        Node* currentNode = bucket[hashIndex].head;

        Node* previousNode = nullptr;

        if (currentNode == nullptr)
        {
            cout << "not key found..." << endl;
        }
        else
        {
            while (currentNode != nullptr)
            {
                if (currentNode->key == key)
                {
                    if (currentNode == bucket[hashIndex].head)
                    {
                        bucket[hashIndex].head = currentNode->next;
                    }
                    else
                    {
                        previousNode->next = currentNode->next;
                    }

                    size--;

                    bucket[hashIndex].count--;

                    delete currentNode;

                    return;
                }
                else
                {
                    previousNode = currentNode;

                    currentNode = currentNode->next;
                }
            }

            cout << "not key found..." << endl;
        }
    }

    const int& bucket_count()
    {
        return capacity;
    }

    const float& load_factor()
    {
        return (float)size / capacity;
    }

    ~HashTable()
    {
        Node* deleteNode = bucket[0].head;
        Node* nextNode = bucket[0].head;
    }
};

int main()
{
    HashTable<const char*, int> hashTable;
    cout << hashTable.hash_function("League of Legend") << endl;
    cout << hashTable.hash_function("Yasuo") << endl;
    cout << hashTable.hash_function("Janna") << endl;

    hashTable.insert("Abyssal Mask", 3000);
    hashTable.insert("Bami's cinder", 1000);
    hashTable.insert("chain Vest", 800);

    hashTable.erase("Abyssal Mask");
    hashTable.erase("Void staff");

    cout << "Load Factor : " << hashTable.load_factor() << endl;
    cout << "Bucket Count : " << hashTable.bucket_count() << endl;

    return 0;
}

