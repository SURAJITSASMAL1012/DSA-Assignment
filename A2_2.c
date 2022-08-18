/*
2. Write a menu-driven program representing a polynomial as a data structure using a single linked list
and write functions to add, subtract and multiply two polynomials.
*/
#include <stdio.h>
#include <stdlib.h>
// node of storing each term of a polynomial
typedef struct record
{
    int coeff, exp;
    struct record *next;
} node;
// method to create a node
node *getNode(int co, int exp)
{
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL)
    {
        printf("\nMemory Allocation Failed...");
        exit(0);
    }
    temp->coeff = co;
    temp->exp = exp;
    temp->next = NULL;
    return temp;
}
// method to create a polynomial
node *createPoly()
{
    node *temp, *head = NULL, *prev = NULL;
    int ch, co, exp;
    // do-while loop to create a singly linked list
    do
    {
        printf("\nEnter coefficient and exponent:");
        scanf("%d%d", &co, &exp);
        temp = getNode(co, exp);
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
        scanf("%d", &ch);
    } while (ch == 1);
    return head;
}
// method to display a polynomial
void display(node *head)
{
    node *c = head;
    // if list is empty
    if (head == NULL)
    {
        printf("\nPolynomial has not built...");
    }
    else
    {
        printf("\nThe Polynomial is:");
        // loop to print list elements
        while (c)
        {
            printf("(%d)x^(%d)", c->coeff, c->exp);
            if (c->next)
                printf("+");
            c = c->next;
        }
    }
}
// method to add two polynomials
node *addPoly(node *p1, node *p2)
{
    node *c1 = p1, *c2 = p2, *p3 = NULL, *temp, *prev = NULL;
    // if no polynomial is there
    if (p1 == NULL && p2 == NULL)
        return NULL;
    // if only one polynomial is there then return it
    if (p1 == NULL)
        return p2;
    if (p2 == NULL)
        return p1;
    // loop to add two polynomials
    while (c1 != NULL || c2 != NULL)
    {
        // both polynomials there
        if (c1 != NULL && c2 != NULL)
        {
            // same exponent,add coefficients
            if (c1->exp == c2->exp)
            {
                temp = getNode(c1->coeff + c2->coeff, c1->exp);
                c1 = c1->next;
                c2 = c2->next;
            }
            // different exponents,append the node with higher exponent first
            // and move respective pointer
            else if (c1->exp > c2->exp)
            {
                temp = getNode(c1->coeff, c1->exp);
                c1 = c1->next;
            }
            else
            {
                temp = getNode(c2->coeff, c2->exp);
                c2 = c2->next;
            }
        }
        // only one polynomila is there
        else if (c1 == NULL)
        {
            temp = getNode(c2->coeff, c2->exp);
            c2 = c2->next;
        }
        else
        {
            temp = getNode(c1->coeff, c1->exp);
            c1 = c1->next;
        }
        // insert a new node in resultant list
        if (p3 == NULL)
        {
            p3 = temp;
            prev = p3;
        }
        else
        {
            prev->next = temp;
            prev = temp;
        }
    }
    return p3;
}
// method to subtract two polynomials
node *subPoly(node *p1, node *p2)
{
    node *c1 = p1, *c2 = p2, *p3 = NULL, *temp, *prev = NULL;
    // if no polynomial is there
    if (p1 == NULL && p2 == NULL)
        return NULL;
    // if only one polynomial is there then return it
    if (p1 == NULL)
        return p2;
    if (p2 == NULL)
        return p1;
    // loop to subtract two polynomials
    while (c1 != NULL || c2 != NULL)
    {
        // both polynomials there
        if (c1 != NULL && c2 != NULL)
        {
            // same exponent,add coefficients
            if (c1->exp == c2->exp)
            {
                temp = getNode(c1->coeff - c2->coeff, c1->exp);
                c1 = c1->next;
                c2 = c2->next;
            }
            // different exponents,append the node with higher exponent first
            // and move respective pointer
            else if (c1->exp > c2->exp)
            {
                temp = getNode(c1->coeff, c1->exp);
                c1 = c1->next;
            }
            else
            {
                temp = getNode(-c2->coeff, c2->exp);
                c2 = c2->next;
            }
        }
        // only one polynomila is there
        else if (c1 == NULL)
        {
            temp = getNode(-c2->coeff, c2->exp);
            c2 = c2->next;
        }
        else
        {
            temp = getNode(c1->coeff, c1->exp);
            c1 = c1->next;
        }
        // insert a new node in resultant list
        if (p3 == NULL)
        {
            p3 = temp;
            prev = p3;
        }
        else
        {
            prev->next = temp;
            prev = temp;
        }
    }
    return p3;
}
// method to multiply two polynomials
node *mulPoly(node *p1, node *p2)
{
    node *c1, *c2, *temp, *p3 = NULL, *prev = NULL, *c3;
    // if no polynomial is there
    if (p1 == NULL && p2 == NULL)
        return NULL;
    // if only one polynomial is there then return it
    if (p1 == NULL)
        return p2;
    if (p2 == NULL)
        return p1;
    c1 = p1;
    // loop to traverse first polynomial
    while (c1 != NULL)
    {
        c2 = p2;
        // loop to traverse second polynomial
        while (c2 != NULL)
        {
            temp = getNode(c1->coeff * c2->coeff, c1->exp + c2->exp);
            // if 3rd polynomial is not at all created
            if (p3 == NULL)
            {
                p3 = temp;
            }
            // otherwise
            else
            {
                c3 = p3;
                // loop to append new node to proper position in resultant list
                while (c3 != NULL)
                {
                    // same exponent,add coefficient
                    if (c3->exp == temp->exp)
                    {
                        c3->coeff += temp->coeff;
                        break;
                    }
                    // lesser exponent,add node to prev of current node
                    else if (temp->exp > c3->exp)
                    {
                        temp->next = prev->next;
                        prev->next = temp;
                        break;
                    }
                    // otherwise keeping a track of prev node,move on
                    else
                        prev = c3;
                    c3 = c3->next;
                }
                if (c3 == NULL)
                    prev->next = temp;
            }
            c2 = c2->next;
        }
        c1 = c1->next;
    }
    return p3;
}
int main()
{
    int ch;
    node *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;
    printf("\n1.Create 1st Polynomial\n2.Create 2nd Polynomial\n3.Add\n4.Subtract\n5.Multiply");
    do
    {
        printf("\nEnter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            poly1 = createPoly();
            display(poly1);
            break;
        case 2:
            poly2 = createPoly();
            display(poly2);
            break;
        case 3:
            poly3 = addPoly(poly1, poly2);
            display(poly3);
            break;
        case 4:
            poly3 = subPoly(poly1, poly2);
            display(poly3);
            break;
        case 5:
            poly3 = mulPoly(poly1, poly2);
            display(poly3);
            break;
        }
    } while (ch > 0 && ch < 6);
    return 0;
}