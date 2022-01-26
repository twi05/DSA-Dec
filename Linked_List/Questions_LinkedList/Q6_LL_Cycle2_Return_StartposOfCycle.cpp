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

void increase(int *length,int i)
{
    if(i<10)
        (*length)++;
    increase(length, i+1);
}
int main()
{
    int length = 0;
    increase(&length,0);
    cout << length;
    return 0;
}
