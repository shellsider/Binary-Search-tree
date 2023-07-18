#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *LEFT;
    struct node *RIGHT;
};
typedef struct node NODE;

NODE *ROOT = '\0', *PARENT, *X;

NODE *bstInsert(NODE *TREE, int num)
{
    if(TREE == '\0')
    {
        TREE = (NODE*)malloc(sizeof(NODE));
        TREE->info = num;
        TREE->LEFT = '\0';
        TREE->RIGHT = '\0';
    }
    else if(TREE->info < num)
    {
        TREE->RIGHT = bstInsert(TREE->RIGHT, num);
    }
    else if(TREE->info > num)
    {
        TREE->LEFT = bstInsert(TREE->LEFT, num);
    }
    else
    {
        printf("Number invalid or repeated\n");
    }
    return TREE;
}

void preOrder(NODE *TREE)
{
    if(TREE != '\0')
    {
        printf("%d ", TREE->info);
        preOrder(TREE->LEFT);
        preOrder(TREE->RIGHT);
    }
}

void inOrder(NODE *TREE)
{
    if(TREE != '\0')
    {
        inOrder(TREE->LEFT);
        printf("%d ", TREE->info);
        inOrder(TREE->RIGHT);
    }
}

void postOrder(NODE *TREE)
{
    if(TREE != '\0')
    {
        postOrder(TREE->LEFT);
        postOrder(TREE->RIGHT);
        printf("%d ", TREE->info);
    }
}

void search(NODE *TEMP, int num)
{
    PARENT = '\0';
    while(TEMP != '\0')
    {
        if(num == TEMP->info)
        {
            X = TEMP;
            printf("Number found!\n");
            if(PARENT == '\0'){
                printf("NO PARENT PRESENT, IT IS ROOT!\n");
            }
            else{
                printf("Parent is: %d\n\n", PARENT->info);
            }
            return;
        }
        else if(num < TEMP->info)
        {
            PARENT = TEMP;
            TEMP = TEMP->LEFT;
        }
        else
        {
            PARENT = TEMP;
            TEMP = TEMP->RIGHT;
        }
    }
    X = TEMP;
    printf("Number not found:\n");
}

void bstDelete(NODE *TREE, int num)
{
    search(TREE, num);
    if(X->LEFT != '\0' && X->RIGHT != '\0')
    {
        NODE *TEMP;
        TEMP = X->RIGHT;
        PARENT = X;
        while(TEMP->LEFT != '\0')
        {
            PARENT = TEMP;
            TEMP = TEMP->LEFT;
        }
        X->info = TEMP->info;
        X = TEMP;
    }
    if(X->LEFT == '\0' && X->RIGHT == '\0')
    {
        if(PARENT->LEFT == X)
        {
            PARENT->LEFT = '\0';
        }
        else
        {
            PARENT->RIGHT = '\0';
        }
    }
    if(X->LEFT != '\0' && X->RIGHT == '\0')
    {
        if(PARENT->LEFT == X)
        {
            PARENT->LEFT = X->LEFT;
        }
        else
        {
            PARENT->RIGHT = X->LEFT;
        }
    }
    if(X->LEFT == '\0' && X->RIGHT != '\0')
    {
        if(PARENT->LEFT == X)
        {
            PARENT->LEFT = X->RIGHT;
        }
        else
        {
            PARENT->RIGHT = X->RIGHT;
        }
    }
    free (X);
}

void display(NODE *TREE)
{
    if(TREE == '\0')
    {
        printf("TREE is ABsent\n");
        return;
    }
    printf("Displaying PreOrder: ");
    preOrder(TREE);
    printf("\n");
    printf("Displaying InOrder: ");
    inOrder(TREE);
    printf("\n");
    printf("Displaying PostOrder: ");
    postOrder(TREE);
    printf("\n");
}

int main()
{
    int choice, num, find;
    printf("PROGRAM DSCRIPTION\n");
    printf("-------------------------------------------------\n");
    printf("1 = insertion\n2 = display\n3 = search\n4 = deletion\n0=exit\n");
    printf("-------------------------------------------------\n\n");
    while(1)
    {
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter Number: ");
            scanf("%d", &num);
            ROOT = bstInsert(ROOT, num);
            printf("\n");
            break;

        case 2:
            printf("Displaying Elements\n");
            display(ROOT);
            printf("\n");
            break;

        case 3:
            printf("Enter Number: ");
            scanf("%d", &find);
            search(ROOT, find);
            printf("\n");
            break;

        case 4:
            printf("Enter Number to Delete: ");
            scanf("%d", &find);
            bstDelete(ROOT, find);
            break;

        case 0:
            printf("Exiting Program");
            exit (0);

        default:
            printf("Wrong value entered\n");
        }
    }
}
