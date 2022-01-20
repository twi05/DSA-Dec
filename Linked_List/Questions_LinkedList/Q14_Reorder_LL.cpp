#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *head = NULL;
struct ListNode *tail = NULL;

struct ListNode *insertLast(struct ListNode *head, int val)
{
    struct ListNode *new_node = new ListNode;
    new_node->val = val;
    if (head == NULL)
    {
        head = new_node;

        new_node->next = NULL;
    }

    else
    {
        struct ListNode *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        if (ptr->next == NULL)
        {
            ptr->next = new_node;
            new_node->next = NULL;
        }
    }
    tail = new_node;
    return head;
}

void display(struct ListNode *head)
{
    struct ListNode *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->val << " -> ";
        ptr = ptr->next;
    }
    cout << "end";
}

ListNode *middleNode(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

ListNode *reverseLL(ListNode *head)
{
    if (head == NULL)
    {
        return head;
    }

    ListNode *prev = NULL;
    ListNode *current = head;
    ListNode *next = current->next;

    while (current != NULL)
    {
        current->next = prev;
        prev = current;
        current = next;

        if (next != NULL)
        {
            next = next->next;
        }
    }

    return prev;
}

void reorderLL(ListNode *head, ListNode *mid)
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    ListNode *ptr1 = head;
    ListNode *ptr2 = mid;
    ListNode *temp;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        temp = ptr1->next;
        ptr1->next = ptr2;
        ptr1 = temp;

        temp = ptr2->next;
        ptr2->next = ptr1;
        ptr2 = temp;
    }
    
    if (ptr1 != NULL)
    {
        ptr1->next = NULL;
    }
}

int main()
{

    for(int i=1; i < 5;i++)
    head = insertLast(head, i);
    // head = insertLast(head, 2);

    display(head);
    cout << endl;

    ListNode *mid = middleNode(head);
    mid = reverseLL(mid);

    cout << "Check reverse LL: ";
    display(head);
    cout << endl;
    cout << "Check reverse LL: ";
    display(mid);
    reorderLL(head, mid);
    cout << endl;
    display(head);

    return 0;
}