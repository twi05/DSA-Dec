#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    struct ListNode *next;
};

int length_of_LL(ListNode *head)
{

    struct ListNode *slow = head;
    struct ListNode *fast = head;
    int len = 0;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            do
            {
                slow = slow->next;
                len++;
            } while (fast != slow);
        }
        return len;
    }

    int main()
    {
        cout << length_of_LL(head);
        return 0;
    }