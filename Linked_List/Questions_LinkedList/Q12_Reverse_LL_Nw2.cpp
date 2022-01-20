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

ListNode *reverseOnly(int left, int right)
{
    if (left >= right)
    {
        return head;
    }

    ListNode *current = head;
    ListNode *prev = NULL;

    for (int i = 1; current != NULL && i <= left - 1; i++)
    {
        prev = current;
        current = current->next;
    }

    ListNode *last = prev;
    ListNode *newEnd = current;
    ListNode *next = current->next;
                                    
    // reverse between left and right
    for (int i = 1; current != NULL && i <= right - left + 1; i++)
    {
        current->next = prev;
        prev = current;
        current = next;
        if (next != NULL)
        {
            next = next->next;
        }
    }

    if (last != NULL)
    {
        last->next = prev;
    }
    else
    {
        head = prev;
    }
    newEnd->next = current;
    return head;
}

int main()
{

    for (int i = 1; i <= 10; i++)
    {
        head = insertLast(head, i);
    }

    display(head);
    cout << "\nReversing a LL:\n";
    int left = 2;
    int right = 15;

    // reverse only specific part of LL
    reverseOnly(left, right);
    display(head);

    return 0;
}