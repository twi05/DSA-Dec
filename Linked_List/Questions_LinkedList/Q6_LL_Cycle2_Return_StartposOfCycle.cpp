#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
    int val;
    struct ListNode *next;
};

bool hascycle(ListNode *head, int *length)
{
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast->next != NULL && fast != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {

            slow = slow->next;
            (*length)++;

            while (fast != slow)
            {
                (*length)++;
            }

            return true;
        }
    }
    return false;
}

ListNode *detectCycle(ListNode *head)
{
    int length = 0;
    if (!hascycle(head, &length))
    {
        return NULL;
    }
    ListNode *second = head;
    ListNode *first = head;
    int position;
    while (length != 0)
    {
        second = second->next;
    }
    while (first != second)
    {
        first = first->next;
        second = second->next;
        position++;
    }
}

void increase(int *length)
{
    for (int i = 0; i < 10; i++)
    {
        (*length)++;
    }
}
int main()
{
    int length = 0;
    increase(&length);
    cout << length;
    return 0;
}