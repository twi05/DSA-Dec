#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
int size =0;

void insert(int new_data)
{
    struct Node *new_node = new struct Node;
    new_node->data = new_data;
    new_node->next = head;
    head = new_node;
    size++;
}

void display()
{
    struct Node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "end";
}

void insertLast(int val)
{
    struct Node *new_node = new struct Node;
    new_node->data = val;

    struct Node *ptr = head;
    while (ptr->next != NULL)
    {
        // cout << "1";
        ptr = ptr->next;
    }
    if (ptr->next == NULL)
    {
        // cout << "asdf";
        ptr->next = new_node;
        new_node->next = NULL;
    }

    // struct Node *ptr2 = head;
    // while (ptr2 != NULL)
    // {
    //     cout << "5";
    // }
}

void insertInBetween(int val)
{
    struct Node *new_node = new struct Node;
    new_node->data = val;
    struct Node *ptr = head;
    int i = 0;

    while (i < 1)
    {
        ptr = ptr->next;
        cout << "previous pointer" << ptr->next;
        i++;
    }

    new_node->next = ptr->next;
    ptr->next = new_node;
}

void insertAtBegg(int val)
{

    struct Node *new_node = new struct Node;
    new_node->data = val;
    new_node->next = head;

    head = new_node;
}
/*
void insertAfter(string pointer, int val)
{

    struct Node *prevPtr = (struct Node *) pointer;

    struct Node *new_node = new struct Node;
    new_node->data = val;
    new_node->next = prevPtr->next;

    prevPtr->next = new_node;
}
*/
void deleteFirst()
{
    struct Node *ptr = head;

    head = head->next;
    delete ptr;
}

void deleteInBetween(int index)
{
    if (index == 0)
    {
        deleteFirst();
        return;
    }
    struct Node *ptr = head;
    int i = 0;

    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    struct Node *q = ptr->next;
    ptr->next = q->next;
    delete q;
}
void deleteLast()
{
    struct Node *p = head;
    struct Node *q = p->next;
    for (int i = 0; q->next != NULL; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    delete q;
}
void deleteNodeValue(int value)
{
    struct Node *p = head;
    struct Node *q = head->next;

    for (int i = 0; q->next != NULL && q->data != value; i++)
    {
        p = p->next;
        q = q->next;
    }
    if(q->data == value){
        p->next = q->next;
        delete q;
    }
}
int main()
{

    insert(1);
    insert(2);
    insert(3);

    insert(4);
    display();
    cout << endl;

    // Insert Operations
    insertLast(6);
    //  insertAtBegg(5);
    //  display();

    // insertInBetween(3);
    // cout << endl;
    // display();

    // insertAfter("0x727a88",100);

    // Delete Operations
    //  deleteFirst();
    // deleteInBetween(0);
    // deleteLast();

    deleteNodeValue(3);

    display();
    return 0;
}