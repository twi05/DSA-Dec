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
ListNode *addTwoNumbers_OLD_MY(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL || l2 == NULL)
    {
        return NULL;
    }
    struct ListNode *first = l1;
    struct ListNode *second = l2;
    struct ListNode *sumL = new ListNode();

    int carry = 0;
    while (first->next != NULL && second->next != NULL)
    {
        int sum = 0;

        sum = first->val + second->val;
        ListNode *new_node = new ListNode(sum);
        cout << "\nsum is" << sum;
        if (sum < 10)
        {
            new_node->val = sum + carry;
            carry = 0;
        }
        else
        {
            new_node->val = sum % 10 + carry;
            carry = 1;
        }
        first = first->next;
        second = second->next;
    }
    if (first != NULL)
    {

        ListNode *new_node = new ListNode(first->val);
        cout << "yes";
        first = first->next;
    }
    if (second->next != NULL)
    {
        ListNode *new_node = new ListNode(second->val);

        second = second->next;
    }

    return sumL->next;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode();
    ListNode *temp = dummy;

    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry)
    {
        int sum = 0;
        if (l1 != NULL)
        {
            sum = l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        sum += carry;
        carry = sum / 10;
        ListNode *new_node = new ListNode(sum % 10);
        temp->next = new_node;
        temp = temp->next;
    }
    return dummy->next;
}

int main()
{

    struct ListNode *l1_head = NULL;
    struct ListNode *l2_head = NULL;

    for (int i = 1; i <= 3; i++)
    {
        l1_head = new ListNode(i, l1_head);
        // l1_head = insertLast(l1_head, i);
    }
    for (int i = 1; i <= 3; i++)
    {
        l2_head = new ListNode(i, l2_head);
        // //l2_head = insertLast(l2_head, i);
    }

    display(addTwoNumbers(l1_head, l2_head));

    return 0;
}