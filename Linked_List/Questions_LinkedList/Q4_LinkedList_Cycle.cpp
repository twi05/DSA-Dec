#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
};

/*
bool hasCycle(ListNode *head)
    {
        if(head == NULL){
            return false;
        }
        struct ListNode* slow = head;
        struct ListNode* fast = head;

    if(slow->next == NULL){
                return false;
            }
        while(slow->next != fast->next)
        {
            if(fast->next==NULL || slow->next == NULL){
                return false;
            }
            if(slow->next!=NULL){
            slow = slow->next;
            }
            else 
            return false;

            if(fast->next!=NULL && fast!=NULL){
            fast = fast->next->next;}
            else return false;
        }
    return true;
}
*/
bool hasCycle(ListNode *head)
    {

                struct ListNode* slow = head;
        struct ListNode* fast = head;

    while(fast!=NULL && fast->next!=NULL)
    {      fast = fast->next->next;
             slow = slow->next;
        if(fast == slow){
            return true;
        }

    }
    return false;
    }
int main()
{
    cout << hasCycle(head);
    return 0;
}