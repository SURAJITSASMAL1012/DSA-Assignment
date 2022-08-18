/*
1. program to create singly linked list and perform various operations in it
*/
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
typedef struct record
{
    int data;
    struct record *next;
} node;
// method to create linked list
node *create()
{
    node *temp, *head = NULL, *prev = NULL;
    int ch;
    // do-while loop to create a singly linked list
    do
    {
        // memory allocation
        temp = (node *)malloc(sizeof(node));
        if (temp == NULL)
        {
            printf("\nMemory Allocation Failed...");
            exit(0);
        }
        printf("\nEnter data:");
        scanf("%d", &temp->data);
        temp->next = NULL;
        // node insertion
        if (head == NULL)
        {
            head = temp;
            prev = head;
        }
        else
        {
            prev->next = temp;
            prev = temp;
        }
        // wanna repeat
        printf("\nChoose 1 to continue,else 0:");
        // fflush(stdin);
        scanf("%d", &ch);
    } while (ch == 1);
    return head;
}
// method to display the list
void display(node *head)
{
    node *c = head;
    // if list is empty
    if (head == NULL)
    {
        printf("\nThe List is Empty...");
    }
    else
    {
        printf("\nThe list is:");
        // loop to print list elements
        while (c)
        {
            printf("%d->\t", c->data);
            c = c->next;
        }printf(" NULL");
    }
}
// method to insert node at front
node *add_beg(node *head)
{
    node *temp;
    // memory allocation
    temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("\nMemory Allocation Failed...");
        exit(0);
    }
    printf("\nEnter data:");
    scanf("%d", &temp->data);
    // node insertion at beginning
    temp->next = head;
    head = temp;
    return head;
}
// method to insert at last
node *add_end(node *head)
{
    node *temp, *c;
    // memory allocation
    temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("\nMemory Allocation Failed...");
        exit(0);
    }
    printf("\nEnter data:");
    scanf("%d", &temp->data);
    temp->next = NULL;
    // node insertion at end
    c = head;
    while (c->next)
    {
        c = c->next;
    }
    c->next = temp;
    return head;
}
// method to add after kth node
void *add_after_k(node *head, int k)
{
    node *c = head, *temp;
    // loop to go to the position
    while (--k && c->next != NULL)
        c = c->next;
    // if the position do exist
    if (c->next != NULL)
    {
        temp = (node *)malloc(sizeof(node));
        if (temp == NULL)
            printf("\nMemory allocation is not possible!!!");
        else
        {
            printf("\nEnter the data:");
            scanf("%d", &temp->data);
            temp->next = c->next;
            c->next = temp;
        }
    }
    else
        printf("\nWrong Position...");
}
// method to delete front node
node *del_beg(node *head)
{
    node *temp;
    if (head == NULL)
        return NULL;
    temp = head;
    head = head->next;
    free(temp);
    return head;
}
// method to delete last node
node *del_end(node *head)
{
    node *temp, *prev = NULL;
    if (head == NULL)
        return NULL;
    node *c = head;
    while (c->next)
    {
        prev = c;
        c = c->next;
    }
    prev->next = NULL;
    free(c);
    return head;
}
// method to add after a value
void *add_after_val(node *head, int k)
{
    node *c = head, *temp;
    while (c)
    {
        if (c->data == k)
        {
            break;
        }
        c = c->next;
    }
    if (c == NULL)
    {
        printf("\nValue not found...");
    }
    else
    {
        temp = (node *)malloc(sizeof(node));
        if (temp == NULL)
            printf("\nMemmory allocation failed...");
        else
        {
            printf("\nEnter data:");
            scanf("%d", &temp->data);
            temp->next = c->next;
            c->next = temp;
        }
    }
}
// method to add before kth node
void add_before_k(node *head, int k)
{
    node *c = head, *temp;
    --k;
    // loop to go to the position
    while (--k && c->next != NULL)
        c = c->next;
    // if the position do exist
    if (c->next != NULL)
    {
        temp = (node *)malloc(sizeof(node));
        if (temp == NULL)
            printf("\nMemory allocation is not possible!!!");
        else
        {
            printf("\nEnter the data:");
            scanf("%d", &temp->data);
            temp->next = c->next;
            c->next = temp;
        }
    }
    else
        printf("\nWrong Position...");
}
// method to add before a value
void add_before_val(node *head, int k)
{
    node *c = head, *temp, *prev = NULL;
    while (c)
    {
        if (c->data == k)
        {
            break;
        }
        prev = c;
        c = c->next;
    }
    if (c == NULL)
    {
        printf("\nValue not found...");
    }
    else
    {
        temp = (node *)malloc(sizeof(node));
        if (temp == NULL)
            printf("\nMemmory allocation failed...");
        else
        {
            printf("\nEnter data:");
            scanf("%d", &temp->data);
            temp->next = prev->next;
            prev->next = temp;
        }
    }
}
// method to delete after kth node
void del_after_k(node *head, int k)
{
    node *c = head, *temp;
    // loop to go to the position
    while (--k && c->next != NULL)
        c = c->next;
    // if the position do exist
    if (c->next != NULL)
    {
        temp = c->next;
        c->next = temp->next;
        free(temp);
    }
    else
        printf("\nWrong Position...");
}
// method to delete before kth node
void del_before_k(node *head, int k)
{
    node *c = head, *temp;
    if (k == 1)
    {
        printf("\nWrong Position...");
        return;
    }
    if (k == 2)
    {
        printf("\nCan be handled by another case...");
        return;
    }
    k -= 2;
    // loop to go to the position
    while (--k && c->next != NULL)
        c = c->next;
    // if the position do exist
    if (c->next != NULL)
    {
        temp = c->next;
        c->next = temp->next;
        free(temp);
    }
    else
        printf("\nWrong Position...");
}
// method to delete kth node
void del_k(node *head, int k)
{
    node *c = head, *temp;
    if (k == 1)
    {
        printf("\nCan be handled by another case...");
        return;
    }
    --k;
    // loop to go to the position
    while (--k && c->next != NULL)
        c = c->next;
    // if the position do exist
    if (c->next != NULL)
    {
        temp = c->next;
        c->next = temp->next;
        free(temp);
    }
    else
        printf("\nWrong Position...");
}
// reverse the linked list
node *reverse(node *head)
{
    node *temp, *prev = NULL, *c = head;
    // loop to reverse a linked list
    while (c)
    {
        temp = c;
        c = c->next;
        temp->next = prev;
        prev = temp;
    }
    printf("\nLinked list reversed...");
    return prev;
}
// method to delete a specified value
void del_val(node *head, int val)
{
    node *c, *temp, *prev = NULL;
    // if the value is present at head node
    if (head->data == val)
    {
        printf("\nUse head node delete case...");
        return;
    }
    c = head;
    // loop to search the value
    while (c->next)
    {
        prev = c;
        c = c->next;
        if (c->data == val)
        {
            break;
        }
    }
    // if value found,delete the node
    if (c->next != NULL)
    {
        temp = c;
        prev->next = c->next;
        free(temp);
    }
    // otherwise value not found
    else
    {
        printf("\nValue not found...");
    }
}
// method to search a value
void search(node *head, int val)
{
    node *c = head;
    int index = 0;
    while (c)
    {
        if (c->data == val)
        {
            printf("Item found at index %d", index);
            return;
        }
        index++;
        c = c->next;
    }
    printf("\nItem not found...");
}
// merge two list by comaprison
node *merge(node *l1, node *l2)
{
    node *dummy, *curr;
    // memory allocation
    dummy = (node *)malloc(sizeof(node));
    if (dummy == NULL)
    {
        printf("\nMemory Allocation Failed...");
        exit(0);
    }
    dummy->data = 0;
    dummy->next = NULL;
    curr = dummy;
    // traverse the lists to merge
    while (l1 && l2)
    {
        if (l1->data < l2->data)
        {
            curr->next = l1;
            l1 = l1->next;
        }
        else
        {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }
    // if list2 ended
    if (l1)
    {
        curr->next = l1;
    }
    // if list1 ended
    if (l2)
    {
        curr->next = l2;
    }
    return dummy->next;
}
// method to sort a linked list in O(nlogn) time
// split lists by mid node
node *sortList(node *head)
{
    node *slow, *fast, *mid, *l1 = NULL, *l2 = NULL;
    if (head == NULL || head->next == NULL)
        return head;
    slow = head;
    fast = head->next;
    while (slow->next != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    mid = slow->next;
    slow->next = NULL;
    l1 = sortList(head);
    l2 = sortList(mid);
    return merge(l1, l2);
}
// method to concatenate two singly linked lists
node *concat(node *h1, node *h2)
{
    node *c = h1;
    while (c->next)
    {
        c = c->next;
    }
    c->next = h2;
    return h1;
}
// method to check whether two BSTs are equal or not
bool chk_equal(node *h1, node *h2)
{
    node *c1 = h1, *c2 = h2;
    int flag = 1;
    while (c1 && c2)
    {
        if (c1->data != c2->data)
        {
            flag = 0;
            break;
        }
        c1 = c1->next;
        c2 = c2->next;
    }
    if ((!c1 && c2) || (c1 && !c2))
    {
        flag = 0;
        return 0;
    }
    return 1;
    /*if (flag == 1)
    {
        printf("\nThe two lists are equal...");
    }
    else
    {
        printf("\nThe two lists are different...");
    }*/
}
int main()
{
    int ch, k;
    node *temp, *head = NULL, *head1 = NULL, *head2 = NULL;
    printf("\n1.Create singly linked list\n2.Display\n3.Insert at front\n4.Insert at end");
    printf("\n5.Insert a node after kth node\n6.Insert a node after a value\n7.Insert a node before kth node");
    printf("\n8.Insert a node before a value\n9.Delete First Node\n10.Delete Last Node\n11.Delete a node after kth node");
    printf("\n12.Delete a node before kth node\n13.Delete kth node\n14.Delete a node containing a specified value");
    printf("\n15.Find Reverse\n16.Search a value\n17.Sort\n18.Merge two lists which are in ascending order\n19.Concatenate two lists\n20.Find if two lists are equal");
    do
    {
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        // create singly linked list
        case 1:
            head = create();
            break;
        case 2:
            display(head);
            break;
        case 3:
            head = add_beg(head);
            break;
        case 4:
            head = add_end(head);
            break;
        case 5:
            printf("\nEnter k:");
            scanf("%d", &k);
            add_after_k(head, k);
            break;
        case 6:
            printf("\nEnter value:");
            scanf("%d", &k);
            add_after_val(head, k);
            break;
        case 7:
            printf("\nEnter k:");
            scanf("%d", &k);
            add_before_k(head, k);
            break;
        case 8:
            printf("\nEnter value:");
            scanf("%d", &k);
            add_before_val(head, k);
            break;
        case 9:
            head = del_beg(head);
            break;
        case 10:
            head = del_end(head);
            break;
        case 11:
            printf("\nEnter k:");
            scanf("%d", &k);
            del_after_k(head, k);
            break;
        case 12:
            printf("\nEnter k:");
            scanf("%d", &k);
            del_before_k(head, k);
            break;
        case 13:
            printf("\nEnter k:");
            scanf("%d", &k);
            del_k(head, k);
            break;
        case 14:
            printf("\nEnter value:");
            scanf("%d", &k);
            del_val(head, k);
            break;
        case 15:
            head = reverse(head);
            break;
        case 16:
            printf("\nEnter value:");
            scanf("%d", &k);
            search(head, k);
            break;
        case 17:
            head = sortList(head);
            break;
        case 18:
            printf("\nCreate 1st linked list in ascending order\n");
            head1 = create();
            printf("\nCreate 2nd linked list in ascending order\n");
            head2 = create();
            printf("\nThe lists are:\n");
            display(head1);
            display(head2);
            head1 = merge(head1, head2);
            printf("\nThe merged list is:\n");
            display(head1);
            break;
        case 19:
            printf("\nCreate 2nd list\n");
            head1 = create();
            head = concat(head, head1);
            break;
        case 20:
            printf("\nCreate 2nd list\n");
            head1 = create();
            if(chk_equal(head, head1))
            printf("List are equal");
            else
            printf("List are not equal");
            break;
        }
    } while (ch >= 1 && ch <= 20);
    return 0;
}
