#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void insert(struct Node *new_node, struct Node *next_Address, int new_data)
{

    new_node->data = new_data;
    new_node->next = next_Address;
}

void display(struct Node *head)
{

    struct Node *ptr = head;
    cout << ptr->data << " ";
    ptr = ptr->next;
    while (ptr != head )
    {
     
        // cout<<"yes";
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
struct Node* insertStart(struct Node *head, int value){

        struct Node *new_node = new struct Node ;
        
        struct Node *ptr = head;
        new_node->data = value;
        new_node->next = head;
    ptr=ptr->next;
for(int i=0; ptr!=head ; i++){
     cout<<"yes";
    ptr=ptr->next;
}
ptr->next = new_node;
head  = new_node;        
return head;


}
int main()
{

    struct Node *first = new struct Node;
    struct Node *second = new struct Node;
    struct Node *third = new struct Node;
    struct Node *forth= new struct Node;

    struct Node *head = first;
    insert(first, second, 1);
    insert(second, third, 6);
    insert(third, forth, 4);
    insert(forth, head, 3);

    // cout<<second->data<<endl;
    // cout<<third->data<<endl;
    // cout<<second->data<<endl;
    head = insertStart(head, 58 );
    
    display(head);

    return 0;
}