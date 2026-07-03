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
            if (currentNode == root)
            {
                if (currentNode->left != nullptr)
                {
                    root = currentNode->left;
                }
                else
                {
                    root = currentNode->right;
                }
            }
            else
            {
                Node* childNode = nullptr;

                if (currentNode->left != nullptr)
                {
                    childNode = currentNode->left;
                }
                else
                {
                    childNode = currentNode->right;
                }

                if (parentNode->left == currentNode)
                {
                    parentNode->left = childNode;
                }
                else
                {
                    parentNode->right = childNode;
                }
            }

            delete currentNode;
        }
        else
        {
            Node* childNode = currentNode->right;
            Node* traceNode = currentNode;

            while (childNode->left != nullptr)
            {
                traceNode = childNode;

                childNode = childNode->left;
            }

            currentNode->data = childNode->data;

            if (traceNode == currentNode)
            {
                traceNode->right = childNode->right;
            }
            else
            {
                traceNode->left = childNode->right;
            }

            delete childNode;
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

    void release(Node* root)
    {
        if (root != nullptr)
        {
            release(root->left);

            release(root->right);

            delete root;
        }
    }

    ~Tree()
    {
        release(root);
    }
};

int main()
{
    Tree<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(13);
    tree.insert(22);
    tree.insert(17);
    tree.insert(19);
    tree.erase(20);

    tree.render();

    return 0;
}