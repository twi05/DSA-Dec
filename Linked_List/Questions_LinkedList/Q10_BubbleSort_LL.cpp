#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *insertLast(ListNode *head, int val)
{
    ListNode *new_node = new ListNode;
    new_node->val = val;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        ListNode *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    new_node->next = NULL;

    return head;
}

void display_LL(ListNode *head)
{
    struct ListNode *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->val << " >> ";
        ptr = ptr->next;
    }
    cout << "end";
}

void bubbleSort(ListNode *head)
{
    struct ListNode *i = head;
    struct ListNode *j = head;
    while (i != NULL)
    {
        while (j->next != NULL)
        {

            if (j->val > j->next->val)
            {
                int temp = j->val;
                j->val = j->next->val;
                j->next->val = temp;
            }
          j = j->next;
        }  
        i=i->next;
       j=head;
    }
}

int main()
{

    ListNode *head = NULL;

    head = insertLast(head, 1);
    head = insertLast(head, 100);
    head = insertLast(head, 1);
    head = insertLast(head, 3);
    head = insertLast(head, -5);
    display_LL(head);
    bubbleSort(head);
    cout<<endl<<"Sorted LL: ";
    display_LL(head);
    return 0;
}