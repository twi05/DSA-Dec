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

ListNode *reverse_LL_Twinshu(ListNode *head)
{
    ListNode *ptr1 = head;
    ListNode *ptr2 = head;
    ListNode *temp;

    ptr2 = ptr2->next;
    temp = ptr2;
    while (ptr2->next != NULL)
    {
        // cout << ptr1->next << "\n";
        ptr2 = ptr2->next;
        // x = ptr1->next;
        temp->next = ptr1;

        ptr1 = temp;

        temp = ptr2;
    }
    ptr2->next = ptr1;
    head->next = NULL;
    head = ptr2;

    return head;
}

void reversing_Recursion_LL(ListNode *curr_node)
{

    if (curr_node == tail)
    {
        head = curr_node;
        return;
    }

    reversing_Recursion_LL(curr_node->next);

    tail->next = curr_node;
    tail = curr_node;
    curr_node->next = NULL;
}

ListNode *reverse_LL_iterative_kk(ListNode *head)
{

    if (head == NULL)
    {
        return head;
    }
    ListNode *prev = NULL;
    ListNode *present = head;
    ListNode *next = present->next;

    while (present != NULL)
    {

        present->next = prev;

        prev = present;
        present = next;

        if (next != NULL)
        {
            next = next->next;
        }
    }
    return prev;
}

int main()
{

    for (int i = 0; i <= 100; i++)
    {
        head = insertLast(head, i);
    }

    display(head);
    cout << "\nReversing a LL:\n";
    head = reverse_LL_Twinshu(head);

    // head = reverse_LL_iterative_kk(head);

    // reversing_Recursion_LL(head);

    display(head);

    return 0;
}