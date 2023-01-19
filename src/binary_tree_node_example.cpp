#include <iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* newNode(int idata)
{
    Node* node = new Node;
    node->data = idata;
    node->left = nullptr;
    node->right = nullptr;

    return node;
}

int main()
{
    Node* root = newNode(9);
    root->left = newNode(4);
    (*root).right = newNode(3);

}