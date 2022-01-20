#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *head = NULL;
int size = 0;

ListNode *insertLast(ListNode *head, int val)
{
    ListNode *new_node = new ListNode;
    new_node->val = val;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        ListNode *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    new_node->next = NULL;
    size++;
    return head;
}

void display_LL(ListNode * head)
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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{

      if (list1 == NULL)
        return (list2);
    else if (list2 == NULL)
        return (list1);

    ListNode *res = new ListNode();
    ListNode *mergedList = res;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val <= list2->val)
        {
            ListNode *Node = new ListNode(list1->val);
            list1 = list1->next;
            mergedList->next = Node;
        }

        else if (list1->val > list2->val)
        {
            ListNode *Node = new ListNode(list2->val);
            list2 = list2->next;
            mergedList->next = Node;
        }
        mergedList = mergedList->next;
    }

    if (list1 != NULL)
    {
        mergedList->next = list1;
    }

    else
        mergedList->next = list2;

    return res->next;
}

ListNode *mergeSort(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    
    ListNode *left = mergeSort(head);
    ListNode *mid = middleNode(head);
    ListNode *right = mergeSort(mid->next);
    
    return mergeTwoLists(left, right);
}

int main()
{

    head = insertLast(head, 5);
    insertLast(head, 2);
    insertLast(head, 1);
    insertLast(head, 3);
    insertLast(head, 4);
    display_LL(head);

    cout << "\nsize of LL: " << size << "\n";

    cout << "Process of merge sort starts from here:";
   ListNode *mergedList = mergeSort(head);
    display_LL(mergedList);
    return 0;
}