/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<stdlib.h>
class Solution {
public:
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

    void deleteNodeValue(struct ListNode *head,int value)
{
    struct ListNode *p = head;
    struct ListNode *q = head->next;

    for (int i = 0; q->next != NULL && q->val != value; i++)
    {
        p = p->next;
        q = q->next;
    }
    if (q->val == value)
    {
        p->next = q->next;
        delete q;
    }
}
    
    ListNode* deleteDuplicates(ListNode* head) {

         struct ListNode *ptr = head;
    int lastValue = 0;
    while (ptr != NULL)
    {
        if (lastValue == ptr->val)
        {
            if (lastValue == head->val)
            {
                head = head->next;
                delete ptr;
            }
            else
                deleteNodeValue(head,ptr->val);
        }
        lastValue = ptr->val;
        ptr = ptr->next;
    }
    return head;
}};