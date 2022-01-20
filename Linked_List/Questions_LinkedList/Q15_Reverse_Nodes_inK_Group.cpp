#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    cout << "rev\t";
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
    display(head);
    return head;
}
bool safe(ListNode *ptr, int k)
{

    while (k != 1)
    {

        if (ptr == NULL)
        {
            return false;
        }
        ptr = ptr->next;
        k--;
    }
    return true;
}

ListNode *reverseK_Group(ListNode *head, int k)
{
    if (k <= 1 || head == NULL)
    {
        return head;
    }
    struct ListNode *ptr = head;
    int i = 1;
    while (ptr != NULL || ptr->next == NULL)
    {
        if (safe(ptr, k))
        {
            cout << "yes";
            head = reverseOnly(i, i + k-1);
        }
        for (int i = 0; i < k; i++)
        {
            ptr = ptr->next;
        }
        i += k ;
    }
    return head;
}
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL || k == 1)
        return head;
    int num = 0;
    ListNode *preheader = new ListNode(-1);
    preheader->next = head;
    ListNode *cur = preheader, *nex, *pre = preheader;
    while (cur = cur->next)
        num++;
    while (num >= k)
    {
        cur = pre->next;
        nex = cur->next;
        for (int i = 1; i < k; ++i)
        {
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        num -= k;
    }
    return preheader->next;
}

int main()
{

    for (int i = 1; i <= 5; i++)
    {
        head = insertLast(head, i);
    }

    display(head);
    cout << "\nReversing a LL:\n";
    int k = 2;
    // r;everse only specific part of LL
  head =   reverseK_Group(head, k);
    // head = reverseKGroup(head, k);
    // reverseOnly(1,3);
    // reverseOnly(4,6);
    // reverseOnly(7,9);
    // reverseOnly(1,3);
    display(head);

    return 0;
}