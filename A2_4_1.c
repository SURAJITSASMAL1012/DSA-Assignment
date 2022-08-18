#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node *next;
};
struct node *head = NULL;

void create();
void display();
int survivor(int);

int main()
{
    int survive, skip;
    create();
    display();
    printf("Enter the number of persons to be skipped\n");
    scanf("%d", &skip);
    survive = survivor(skip);
    printf("The person to survive is : %d \n", survive);
    free(head);
}

void create()
{
    struct node *temp, *rear;
    int a, ch;
    do
    {
        printf("Enter a number : ");
        scanf("%d", &a);
        temp = (struct node *)malloc(sizeof(struct node));
        temp->num = a;
        temp->next = NULL;

        if (head == NULL)
        {
            head = temp;
            temp->next = head;
        }
        else
        {
            rear = head;
            while (rear->next != head)
            {
                rear = rear->next;
            }
            rear->next = temp;
            temp->next = head;
        }

        printf("Do you want to add a number [1/0]?");
        scanf("%d", &ch);
    } while (ch != 0);
}

void display()
{
    struct node *temp;
    temp = head;
    do
    {
        printf("%d ", temp->num);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int survivor(int k)
{
    struct node *p, *q;
    int i;
    p = q = head;
    while (p->next != p)
    {
        for (i = 0; i < k - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        printf("%d has been killed \n", p->num);
        free(p);
        p = q->next;
    }
    head = p;
    return (p->num);
}