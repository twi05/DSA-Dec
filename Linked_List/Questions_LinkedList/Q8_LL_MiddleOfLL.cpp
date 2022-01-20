#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
};

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

int main()
{
    cout << middle(head);
    // cout<<square_of_digits(150);
    return 0;
}