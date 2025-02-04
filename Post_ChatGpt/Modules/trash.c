#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodee
{
    int value;
    struct nodee *left;
    struct nodee *right;
}node;



void fill(node *n, int x)
{
    if(n->value == x)
    {
        return;
    }
    if(x >= n->value)
    {
        if (n->right != NULL)
        {
            fill(n->right,x);
        }else
        {
            n->right = malloc(sizeof(node));
            n->right->value = x;
            n->right->left = NULL;
            n->right->right = NULL;
        }
        
    }else
    {
        if (n->left != NULL)
        {
            fill(n->left,x);
        }else
        {
            n->left = malloc(sizeof(node));
            n->left->value = x;
            n->left->left = NULL;
            n->left->right = NULL;
        }
    }
}

int main()
{
    int t[] = {56,34,52,87,45,235,76,989,678,645,4653,3,1,8,45,33};
    int i;
    node *n;
    n = malloc(sizeof(node));
    n->value = t[0];
    n->left = NULL;
    n->right = NULL;
    for(i = 0; i < 16; i++ )
    {
        fill(n, t[i]);
    }
    printf("the first number in node is %d\n",n->value);
    printf("the second number in node is %d\n",n->right->value);
    printf("the second number in node is %d\n",n->right->right->value);
    printf("the second number in node is %d\n",n->left->value);
    printf("the second number in node is %d\n",n->left->left->value);
    printf("the second number in node is %d\n",n->left->left->right->value);


    return 0;
}