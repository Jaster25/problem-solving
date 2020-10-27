#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{
    int n;
    int size;
    Node *top;
} Stack;

Node *createNode()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    return newNode;
}

Stack *createStack()
{
    Stack *newStack = (Stack *)malloc(sizeof(Stack));
    newStack->n = 0;
    newStack->size = 0;
    newStack->top = createNode();
    return newStack;
}

void push(Stack *stack, int a)
{
    Node *newNode = createNode();
    newNode->data = a;

    stack->n++;
    stack->size++;
    newNode->next = stack->top;
    stack->top = newNode;
}

void freeNode(Node *node)
{
    if (node->next)
        freeNode(node->next);
    free(node);
}

void freeStack(Stack *stack)
{
    freeNode(stack->top);
    free(stack);
}

int main()
{
    Stack *stack = createStack();

    int n;
    scanf("%d", &n);
    while (n--)
    {
        char order[10];
        scanf("%s", order);

        if (strcmp(order, "push") == 0)
        {
            int num;
            scanf("%d", &num);
            push(stack, num);
        }
        else if (strcmp(order, "pop") == 0)
        {
            if (stack->size == 0)
                printf("-1\n");
            else
            {
                stack->n--;
                stack->size--;
                printf("%d\n", stack->top->data);
                stack->top = stack->top->next;
            }
        }
        else if (strcmp(order, "size") == 0)
            printf("%d\n", stack->size);
        else if (strcmp(order, "empty") == 0)
            stack->size == 0 ? printf("1\n") : printf("0\n");
        else if (strcmp(order, "top") == 0)
        {
            if (stack->size == 0)
                printf("-1\n");
            else
                printf("%d\n", stack->top->data);
        }
    }

    freeStack(stack);
}