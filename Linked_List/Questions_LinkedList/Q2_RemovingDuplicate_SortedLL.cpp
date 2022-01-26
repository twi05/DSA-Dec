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

void deleteNodeValue(struct Node *head,int value)
{
    struct Node *p = head;
    struct Node *q = head->next;

    for (int i = 0; q->next != NULL && q->data != value; i++)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        delete q;
    }
}
void deleteFirst()
{
    struct Node *ptr = head;

    head = head->next;
    delete ptr;
}

void removeDuplicates()
{
    struct Node *ptr = head;
    int lastValue = 0;

    while (ptr != NULL)
    {

        if (lastValue == ptr->data)
        {
            if (lastValue == head->data)
            {
                deleteFirst();
            }
            else
                deleteNodeValue(head,ptr->data);
        }
        lastValue = ptr->data;
        ptr = ptr->next;
    }
}
struct Node *deleteDuplicates(struct Node *head)
{
    struct Node *ptr = head;
    int lastValue = 0;
    while (ptr != NULL)
    {
        if (lastValue == ptr->data)
        {
            if (lastValue == head->data)
            {
                head = head->next;
                delete ptr;
            }
            else
                deleteNodeValue(head,ptr->data);
        }
        lastValue = ptr->data;
        ptr = ptr->next;
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
    insert(4);
    insert(4);


    display();
    // removeDuplicates();
    deleteDuplicates(head);
    cout << endl;
    display();

    return 0;
}