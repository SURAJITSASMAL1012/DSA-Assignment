#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// function to execute a person
void execute(char **names, int n, int k)
{
    int i;
    printf("\nPerson Executed: %s", names[k]);
    for (i = k; i < n - 1; i++)
    {
        strcpy(names[i], names[i + 1]);
    }
    free(names[n - 1]);
    names = (char **)realloc(names, (n - 1) * sizeof(char *));
}
// function to implement josephus problem using 2D array
void array_handle()
{
    char **names;
    int n, size, i, k;
    char str[100];
    printf("\nEnter number of people:");
    scanf("%d", &n);
    names = (char **)malloc(n * sizeof(char *));
    printf("\nEnter names:\n");
    // loop to input names
    for (i = 0; i < n; i++)
    {
        fflush(stdin);
        scanf("%[^\n]s", str);
        size = strlen(str);
        names[i] = (char *)malloc(size * sizeof(char));
        strcpy(names[i], str);
    }
    printf("\nEnter skip value:");
    scanf("%d", &k);
    i = 0;
    while (n != 1)
    {
        i = (i + k) % n; // increment index value to reach kth index
        // execute after kth index
        execute(names, n, i);
        n--;
    }
    printf("\nWinner is %s", names[0]);
    free(names[0]);
    free(names);
}
// circular linked list node structure
typedef struct record1
{
    char *name;
    struct record1 *next;
} cnode;
// method to create circular linked list
cnode *create_circ(cnode *head)
{
    cnode *temp, *prev = NULL;
    int op;
    char str[100];
    do
    {
        temp = (cnode *)malloc(sizeof(cnode));
        if (temp == NULL)
        {
            printf("\nMemory Allocation is Failed...");
            exit(0);
        }
        printf("\nEnter name:");
        fflush(stdin);
        scanf("%[^\n]s", str);
        temp->name = (char *)malloc(strlen(str) * sizeof(char));
        strcpy(temp->name, str);
        temp->next = NULL;
        // insert new node in circular linked list
        if (head == NULL)
        {
            head = temp;
            head->next = head;
            prev = head;
        }
        else
        {
            prev->next = temp;
            temp->next = head;
            prev = temp;
        }
        printf("\nPress 1 to continue,otherwise 0 to exit:");
        scanf("%d", &op);
    } while (op == 1);
    return head;
}
// method to display circular linked list
void display_circ(cnode *head)
{
    cnode *c = head;
    if (head == NULL)
    {
        printf("\nList is empty..");
        return;
    }
    // loop to display all names
    printf("\nThe names are:\n");
    while (c->next != head)
    {
        printf("%s\n", c->name);
        c = c->next;
    }
    printf("%s\n", c->name);
}
// function to implement josephus problem using circular linked list
void circular_linkedlist_handle()
{
    cnode *head = NULL, *t, *temp;
    int k, i;
    head = create_circ(head);
    display_circ(head);
    printf("\nEnter skip value:");
    scanf("%d", &k);
    t = head;
    // loop to execute all the persons until only one is left
    while (t->next != t)
    {
        // loop to reach (k-1)th node
        for (i = 0; i < k - 1; i++)
        {
            t = t->next;
        }
        // execute kth node
        temp = t->next;
        t->next = temp->next;
        printf("\nPerson Executed: %s", temp->name);
        free(temp);
        t = t->next;
    }
    printf("\nWinner is %s", t->name);
}
// circular doubly linked list node structure
typedef struct record2
{
    char *name;
    struct record2 *next, *prev;
} cdnode;
// function to create circular doubly linked list
cdnode *create_cd(cdnode *head)
{
    cdnode *temp, *p = NULL;
    int op;
    char str[100];
    do
    {
        temp = (cdnode *)malloc(sizeof(cdnode));
        if (temp == NULL)
        {
            printf("\nMemory Allocation is Failed...");
            exit(0);
        }
        printf("\nEnter name:");
        fflush(stdin);
        scanf("%[^\n]s", str);
        temp->name = (char *)malloc(strlen(str) * sizeof(char));
        strcpy(temp->name, str);
        temp->next = NULL;
        temp->prev = NULL;
        // insert new node in circular linked list
        if (head == NULL)
        {
            head = temp;
            head->next = temp;
            head->prev = temp;
            p = head;
        }
        else
        {
            p->next = temp;
            temp->prev = p;
            temp->next = head;
            head->prev = temp;
            p = temp;
        }
        printf("\nPress 1 to continue,otherwise 0 to exit:");
        scanf("%d", &op);
    } while (op == 1);
    return head;
}
// method to display circular linked list
void display_cd(cdnode *head)
{
    cdnode *c = head;
    if (head == NULL)
    {
        printf("\nList is empty..");
        return;
    }
    // loop to display all names
    printf("\nThe names from beginning are:\n");
    while (c->next != head)
    {
        printf("%s\n", c->name);
        c = c->next;
    }
    printf("%s\n", c->name);
}
// handling josephus problem by doubly linked list
void doubly_circular_linkedlist_handle()
{
    cdnode *head = NULL, *t, *temp = NULL;
    int k, i;
    head = create_cd(head);
    display_cd(head);
    printf("\nEnter skip value:");
    scanf("%d", &k);
    t = head;
    // loop to execute all the persons until only one is left
    while (t->next != t)
    {
        // loop to reach (k-1)th node
        for (i = 0; i < k - 1; i++)
        {
            t = t->next;
        }
        // execute kth node
        temp = t->next;
        t->next = temp->next;
        t->next->prev = t;
        printf("\nPerson Executed: %s", temp->name);
        free(temp);
        t = t->next;
    }
    printf("\nWinner is %s", t->name);
}
int main()
{
    int ch;
    printf("\n1.Josephus Problem By 2D array\n2.Josephus Problem By Circular Linked List");
    printf("\n3.Josephus Problem By Circular double linked list");
    do
    {
        printf("\nEnter choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            array_handle();
            break;
        case 2:
            circular_linkedlist_handle();
            break;
        case 3:
            doubly_circular_linkedlist_handle();
            break;
        default:
            printf("\nWrong Choice...Program Exits");
        }
    } while (ch == 1 || ch == 2 || ch == 3);
    return 0;
}
