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

    return head;
}
void display(struct ListNode *head)
{
    struct ListNode *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->val << " -> ";
        ptr = ptr->next;
    }
    cout << "end";
}
ListNode *rotateRightOLD(ListNode *head, int k)
{
    if (head == NULL || k == 0 || head->next == NULL)
        return head;

    struct ListNode *ptr = head;
    int i = 1;
    while (ptr != NULL)
    {
        i++;
        ptr = ptr->next;
    }

    k = k % i;
    // cout<<"Value of k: "<<k;
    if (k == 0)
    {
        return head;
    }
    struct ListNode *current = head;
    struct ListNode *next = current->next;

    while (k != 0)
    {
        while (next->next != NULL)
        {
            current = next;
            if (next->next != NULL)
                next = next->next;
        }
        current->next = NULL;
        next->next = head;
        k--;
        head = next;
    }

    return next;
}

ListNode *rotateRight(ListNode *head, int k)
{
    if (!head || !head->next)
    {
        return head;
    }

    struct ListNode *ptr = head;
    int count = 0;

    while (ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    // cout << "count of NODES" << count << "\n";

    k = k % count;
    if (k == 0 || k == count)
    {
        return head;
    }

    struct ListNode *prev = NULL;
    struct ListNode *curr = head;

    while (k != 0)
    {

        while (curr->next != NULL)
        {
            prev = curr;
            if (curr->next != NULL)
                curr = curr->next;
            else
            {
                break;
            }
        }
        prev->next = NULL;
        curr->next = head;
        head = curr;
        k--;
    }

    return head;
}

int main()
{
    struct ListNode *head = NULL;

    for (int i = 1; i <= 3; i++)
    {
        head = insertLast(head, i);
    }
    int k = 5;

    head = rotateRight(head, k);
    display(head);
    return 0;
}