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

void display()
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

struct Node *deleteDuplicates(struct Node *head)
{
    Node *curr = head;
    Node *next = curr->next;

    while (curr->next != NULL)
    {
        if (curr->data == next->data)
        {
            curr->next = next->next;
            // curr = curr->next;
            if (curr->next != NULL)
                next = curr->next;
        }
        else
        {
            curr = next;
            if (next->next != NULL)
                next = next->next;
        }
    }
    return head;
}

int main()
{

   insert(2);
    insert(2);
    insert(2);
    insert(2);
    insert(2);
    insert(2);
    insert(2);
    insert(2);
    insert(2);
    insert(2);
    insert(2);
    insert(2);
    insert(3);
    insert(3);
    insert(3);
    insert(3);
    insert(3);
    insert(3);
    insert(3);
    insert(3);
    insert(3);
    insert(4);
    insert(4);
    insert(4);
    insert(4);
    insert(4);
    insert(4);
    insert(4);
    insert(4);
    insert(4);
    display();
    // removeDuplicates();
    head = deleteDuplicates(head);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Removed Duplicates:\n";
    display();

    return 0;
}