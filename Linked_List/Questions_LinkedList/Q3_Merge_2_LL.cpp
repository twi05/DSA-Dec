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
    struct ListNode *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->val << " -> ";
        ptr = ptr->next;
    }
    cout << "end";
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *ptr1 = list1;
    ListNode *ptr2 = list2;
    ListNode *res = new ListNode();
    ListNode *mergedList = res;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->val <= ptr2->val)
        {
            ListNode *Node = new ListNode(ptr1->val);
            ptr1 = ptr1->next;
            mergedList->next = Node;
        }

        else if (ptr1->val > ptr2->val)
        {
            ListNode *Node = new ListNode(ptr2->val);
            ptr2 = ptr2->next;
            mergedList->next = Node;
        }
        mergedList = mergedList->next;
    }

    if (ptr1 != NULL)
    {
        mergedList->next = ptr1;
    }

    else
        mergedList->next = ptr2;

    return res->next;
}

int main()
{
    struct ListNode *list1 = NULL;

    list1 = insertLast(list1, 1);

    list1 = insertLast(list1, 2);
    list1 = insertLast(list1, 5);

    display(list1);
    cout << endl;
    struct ListNode *list2 = NULL;

    list2 = insertLast(list2, -2);
    list2 = insertLast(list2, 1);

    list2 = insertLast(list2, 2);

    list2 = insertLast(list2, 3);
    // list2 = insertLast(list2, 3);
    // list2 = insertLast(list2, 3);
    list2 = insertLast(list2, 9);

    display(list2);

    struct ListNode *mergedList = mergeTwoLists(list1, list2);
    cout << "Ans:" << endl;
    display(mergedList);
    return 0;
}
