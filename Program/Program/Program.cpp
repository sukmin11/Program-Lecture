#include <iostream>

using namespace std;

template<typename T>
class Tree
{
private:
    struct Node
    {
        T data;
        Node* left;
        Node* right;
        
        Node(T data)
        {
            this->data = data;

            left = nullptr;
            right = nullptr;
        }
    };

    Node* root;

public:
    Tree()
    {
        root = nullptr;
    }

    void insert(T data)
    {
        if (root == nullptr)
        {
            root = new Node(data);
        }
        else
        {
            Node* currentNode = root;
            while (currentNode != nullptr)
            {
                if (currentNode->data == data)
                {
                    return;
                }

                if (data < currentNode->data)
                {
                    if (currentNode->left == nullptr)
                    {
                        currentNode->left = new Node(data);
                    }
                    else
                    {
                        currentNode = currentNode->left;
                    }
                }
                else if (data > currentNode->data)
                {
                    if (currentNode->right == nullptr)
                    {
                        currentNode->right = new Node(data);
                    }
                    else
                    {
                        currentNode = currentNode->right;
                    }
                }
                else
                {
                    break;
                }
            }

        }

    }

    void inorder(Node* root)
    {
        if (root == nullptr)
        {
            return;
        }

        inorder(root->left);

        render();
    }

    void render()
    {
        
    }
};

int main()
{
    Tree<int> tree;
    tree.insert(10);
    tree.insert(7);
    tree.insert(15);
    tree.insert(19);

    return 0;
}