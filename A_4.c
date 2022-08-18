#include <stdio.h>
#include <stdlib.h>

// Define stack node
struct StackNode
{
    int element;
    struct StackNode *next;
};
// Define a custom stack
struct MyStack
{
    struct StackNode *top;
    int size;
};

struct MyStack *newStack()
{
    // Make a stack
    struct MyStack *stack = (struct MyStack *)malloc(sizeof(struct MyStack));
    if (stack != NULL)
    {
        // Set node values
        stack->top = NULL;
        stack->size = 0;
    }
    else
    {
        printf("\nMemory overflow when create new stack\n");
    }
}
// Returns the status of empty or non empty stacks
int isEmpty(struct MyStack *stack)
{
    if (stack->size > 0 && stack->top != NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
// Add node at the top of stack
void push(struct MyStack *stack, int element)
{

    // Make a new node
    struct StackNode *node = (struct StackNode *)malloc(sizeof(struct StackNode));

    if (node == NULL)
    {
        printf("\nMemory overflow when create new stack Node \n");
    }
    else
    {
        node->element = element;
        node->next = stack->top;
    }

    // Add stack element
    stack->top = node;
    stack->size++;
}
// return top element of stack
int peek(struct MyStack *stack)
{
    return stack->top->element;
}
// Remove top element of stack
void pop(struct MyStack *stack)
{
    if (isEmpty(stack) == 0)
    {
        struct StackNode *temp = stack->top;
        // Change top element of stack
        stack->top = temp->next;
        // remove previous top
        free(temp);
        temp = NULL;
        stack->size--;
    }
}
// Determine that given stacks are equal or not
int compareStack(struct MyStack *s1, struct MyStack *s2)
{

    if (s1->size != s2->size)
    {
        // When number of elements are not same
        return 0;
    }

    // This is backup stack
    struct MyStack *b1 = newStack();
    struct MyStack *b2 = newStack();

    int status = 1;
    // When both stack contains elements
    // And status are active
    while (isEmpty(s1) == 0 && isEmpty(s2) == 0 && status == 1)
    {
        if (peek(s1) != peek(s2))
        {
            // When data elements are not same
            status = 0;
        }
        else
        {
            // Backup the actual elements
            push(b1, peek(s1));
            push(b2, peek(s2));
            // Remove top element of stack
            pop(s1);
            pop(s2);
        }
    }
    // Puts the all pop element into actual stack
    while (isEmpty(b1) == 0)
    {
        push(s1, peek(b1));
        push(s2, peek(b2));
        pop(b1);
        pop(b2);
    }

    return status;
}
// Print stack element
void printData(struct MyStack *s)
{
    if (isEmpty(s) == 1)
    {
        return;
    }
    int data = peek(s);
    printf("  %d", data);
    pop(s);
    printData(s);
    push(s, data);
}
// Handle request to print stack elements
void printStack(struct MyStack *s1, struct MyStack *s2)
{
    printf("\n Stack 1 \n");
    printData(s1);
    printf("\n Stack 2 \n");
    printData(s2);
}
int main()
{
    // Create two empty stack
    struct MyStack *s1 = newStack();
    struct MyStack *s2 = newStack();

    // First stack
    push(s1, 1);
    push(s1, 2);
    push(s1, 3);

    // Second stack
    push(s2, 1);
    push(s2, 2);
    push(s2, 3);

    printStack(s1, s2);

    if (compareStack(s1, s2) == 1)
    {

        printf("\n Stack are equal\n");
    }
    else
    {
        printf("\n Stack are not equal\n");
    }

    push(s1, 4);
    push(s2, 5);

    printStack(s1, s2);
    if (compareStack(s1, s2) == 1)
    {
        printf("\n Stack are equal\n");
    }
    else
    {
        printf("\n Stack are not equal\n");
    }

    return 0;
}