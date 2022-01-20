#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int value)
{
    struct Node *new_node = new struct Node;
    new_node->data = value;
    new_node->next = head;

    head = new_node;
}

void insertUsingRecursion(int value, int index, struct Node *ptr)
{

    if (index == 1)
    {
        struct Node *new_node = new struct Node;
        new_node->data = value;
        new_node->next = ptr->next;

        ptr->next = new_node;
        return;
    }
    insertUsingRecursion(value, index - 1, ptr->next);
    return;
}
void display()
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

int main()
{

    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insertUsingRecursion(15, 2, head);

    display();
    return 0;
}