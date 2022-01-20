#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};
ListNode *tail = NULL;
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
    tail = new_node;
    new_node->next = NULL;
    size++;
    return head;
}

void display_LL(ListNode *head)
{
    struct ListNode *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->val << " >> ";
        ptr = ptr->next;
    }
    cout << "end";
}
ListNode *getPrev(ListNode *head, ListNode *aheadPtr)
{
    ListNode *temp = head;
    ListNode *prev = head;
    while (temp != aheadPtr)
    {
        prev = temp;
        temp = temp->next;
    }
    return prev;
}

ListNode *getPrev(ListNode *head, int pos)
{
    ListNode *temp = head;

    for (int i = 0; i != pos; i++)
    {
        temp = temp->next;
    }
    return temp;
}
void bubbleSortRec(ListNode *head, int row, int col)
{

    if (row == 0)
    {
        return;
    }
    if (col < row)
    {
        struct ListNode *first = head;
        struct ListNode *second = head->next;
        if (first->val > second->val)
        {

            if (first == head)
            {
                first->next = second->next;
                second->next = first;
                head = second;
            }
            else if (second == tail)
            {
                // struct ListNode *prev= getPrev(head, first);
                struct ListNode *prev = getPrev(head, col - 1);
                first->next = NULL;
                second->next = first;
                prev->next = second;
            }
            else
            {
                // struct ListNode *prev = getPrev(head, first);
                struct ListNode *prev = getPrev(head, col - 1);
                first->next = second->next;
                second->next = first;
                prev->next = second;
            }
        }
        bubbleSortRec(head, row, col + 1);
    }

    else
    {
        bubbleSortRec(head, row - 1, 0);
    }
}

int main()
{

    ListNode *head = NULL;

    head = insertLast(head, 1);
    head = insertLast(head, 100);
    head = insertLast(head, 1);
    head = insertLast(head, 3);
    head = insertLast(head, -5);
    display_LL(head);
    bubbleSortRec(head, size, 0);
    cout << endl
         << "Sorted LL: ";
    display_LL(head);
    return 0;
}