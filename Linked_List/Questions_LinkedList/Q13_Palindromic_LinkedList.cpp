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

    ListNode *prev = NULL;
    ListNode *current = head;
    ListNode *next = current->next;

    while (current != NULL)
    {
        current->next = prev;
        prev = current;
        current = next;

        if (next != NULL)
            next = next->next;
    }

    return prev;
}

bool isPalindrome(ListNode *head, ListNode *mid)
{

    ListNode *secondHead = mid;
    ListNode *ptr1 = head;
    ListNode *ptr2 = mid;

    while (ptr2 != NULL)
    {

        if (ptr1->val != ptr2->val)
        {
            break;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    reverseLL(secondHead);

    return head == NULL || ptr2 == NULL;
}

int main()
{

    // for (int i = 1; i <= 10; i++)

    // {
    //     head = insertLast(head, i);
    // }

    head = insertLast(head, 1);
    head = insertLast(head, 5);
    head = insertLast(head, 5);
    head = insertLast(head, 5);
    head = insertLast(head, 1);
    display(head);
    cout << endl;

    ListNode *mid = middleNode(head);
    mid = reverseLL(mid);

    isPalindrome(head, mid) ? cout << "Palindromic LL" : cout << "NOT a Palindromic LL" << endl;

    cout << endl;
    display(head);

    return 0;
}