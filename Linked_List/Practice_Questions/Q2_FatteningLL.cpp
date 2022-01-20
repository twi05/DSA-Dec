#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
Node *merge(Node *a, Node *b)
{
    Node *res = new Node(0);
    Node *temp = res;
    while (a->bottom != NULL && b->bottom != NULL)
    {
        if (a->data > b->data)
        {
            temp->bottom = b;
            b = b->bottom;
        }
        if (a->data < b->data)
        {
            temp->bottom = a;
            a = a->bottom;
        }
        temp = temp->bottom;
    }
    if (a->bottom != NULL)
    {
        temp->bottom = a;
    }
    else
    {
        temp->bottom = b;
    }
    return res->bottom;
}

/*  Function which returns the  root of
    the flattened linked list. */
Node *flatten(Node *root)
{
    if (root == NULL || root->next == NULL)
    {
        return root;
    }
    root->next = flatten(root->next);
    root = merge(root, root->next);
    return root;
}



int main()
{

    return 0;
}