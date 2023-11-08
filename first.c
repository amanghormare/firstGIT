#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data1;
    int data2;
    struct node *link;
};

struct node *head;

void insert(int a, int b);
void addition(int x, int y);
void bubbleSortList();

int main()
{
    head = NULL;
    int a, b;
    printf("POLYNOMIAL 1 -enter coefficient and exponent (x, y):\n");
    int k = 0;
    while (k != 100)
    {
        printf("Enter the coefficient: ");
        scanf("%d", &a);
        printf("Enter the exponent: ");
        scanf("%d", &b);
        insert(a, b);
        printf("Enter 1 to exit and to not exit press any number: ");
        scanf("%d", &k);
        if (k == 1)
            break; 
    }

    int a1, b1;
    printf("Polynomial 2- enter coefficient and exponent (x, y):\n");
    int k1 = 0;
    while (k1 != 1)
    {
        printf("Enter the coefficient: ");
        scanf("%d", &a1);
        printf("Enter the exponent: ");
        scanf("%d", &b1);
        addition(a1, b1);
        printf("Enter 1 to exit and to not exit press any number: ");
        scanf("%d", &k1);
        if (k1 == 1)
            break; 
    }

    bubbleSortList();
    printf("Final addition of polynomial =>\n");
    struct node *poly = head;
    while (poly != NULL)
    {
        printf("%d x^%d", poly->data1, poly->data2);
        if (poly->link != NULL)
            printf(" + ");
        poly = poly->link;
    }

    poly = head;
    while (poly != NULL)
    {
        struct node *temp = poly;
        poly = poly->link;
        free(temp);
    }

    return 0;
}

void addition(int x, int y)
{
    int c = 0;

    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->data2 == y)
        {
            c = 1;
            break;
        }
        temp = temp->link;
    }
    if (c == 1)
    {
        temp->data1 += x;
    }
    else
    {
        insert(x, y);
    }
}

void insert(int a, int b)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory overflow!\n");
        exit(EXIT_FAILURE);
    }

    temp->data1 = a;
    temp->data2 = b;
    temp->link = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *temp2 = head;
        while (temp2->link != NULL)
            temp2 = temp2->link;

        temp2->link = temp;
    }
}

void bubbleSortList()
{
    int swap, template1, template2;
    struct node *temp;
    struct node *ptr = NULL;

    if (head == NULL)
        return;

    do
    {
        swap = 0;
        temp = head;

        while (temp->link != ptr)
        {
            if (temp->data2 < temp->link->data2)
            {
                template1 = temp->data1;
                template2 = temp->data2;
                temp->data1 = temp->link->data1;
                temp->data2 = temp->link->data2;
                temp->link->data1 = template1;
                temp->link->data2 = template2;
                swap = 1;
            }
            temp = temp->link;
        }
        ptr = temp;
    } while (swap);
}