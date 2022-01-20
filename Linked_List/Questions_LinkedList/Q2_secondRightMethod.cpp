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
    struct Node *current = head;
    while (current->next != NULL)
    {
         
              struct Node *ptr =current->next;
          if(current->data == ptr->data){
              current->next = ptr->next;
          }
          else
          current = ptr;
          delete ptr;
         
    }
    /*
    while (current->next != NULL)
    {
         
               ListNode *ptr =current->next;
          if(current->val == ptr->val){
              current->next = ptr->next;
          }
          else
          current =ptr;
         delete ptr;
    }
    */
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
   head=  deleteDuplicates(head);
    cout << endl;
    cout << endl;
    cout << endl;
    display();

    return 0;
}