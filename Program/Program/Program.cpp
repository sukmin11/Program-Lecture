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

    void erase(T data)
    {
        Node* parentNode = nullptr;
        Node* currentNode = root;

        while (currentNode != nullptr && currentNode->data != data)
        {
            parentNode = currentNode;

            if (currentNode->data > data)
            {
                currentNode = currentNode->left;
            }
            else
            {
                currentNode = currentNode->right;
            }
        }

        if (currentNode == nullptr)
        {
            cout << "the data does not exist" << endl;

            return;
        }
        else if (currentNode->left == nullptr && currentNode->right == nullptr)
        {
            if (parentNode != nullptr)
            {
                if (parentNode->left == currentNode)
                {
                    parentNode->left = nullptr;
                }
                else
                {
                    parentNode->right = nullptr;
                }
            }
            else
            {
                root = nullptr;
            }

            delete currentNode;
        }
        else if (currentNode->left == nullptr || currentNode->right == nullptr)
        {
            Node* childNode = currentNode->left;

            if (currentNode->left == nullptr)
            {
                childNode = currentNode->right;
            }

            if (parentNode != nullptr)
            {
                if (parentNode->left == currentNode)
                {
                    parentNode->left = childNode;
                }
                else
                {
                    parentNode->right = childNode;
                }
            }
            else
            {
                root = childNode;
            }

            delete currentNode;
        }
    
    }

    void inorder(Node* root)
    {
        if (root != nullptr)
        {
            inorder(root->left);

            cout << root->data << " ";

            inorder(root->right);
        }

    }

    void render()
    {
        inorder(root);
    }

};

int main()
{
    Tree<int> tree;
    tree.insert(10);
    tree.insert(7);
    tree.insert(15);
    tree.insert(19);
    tree.erase(15);

    tree.render();

    return 0;
}