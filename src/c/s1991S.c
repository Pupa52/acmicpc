#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    char data;
    char left;
    char right;
}Node;

void preorder(Node *tree, int n, int index)
{
    int next_left = -1;
    int next_right = -1;

    for(int i = 0; i < n; i++)
    {
        if(tree[index].left == tree[i].data)
            next_left = i;
        else if(tree[index].right == tree[i].data)
            next_right = i;
    }
    printf("%c", tree[index].data);
    if(next_left != -1)
        preorder(tree, n, next_left);
    if(next_right != -1)
        preorder(tree, n, next_right);
}

void inorder(Node *tree, int n, int index)
{
    int next_left = -1;
    int next_right = -1;

    for(int i = 0; i < n; i++)
    {
        if(tree[index].left == tree[i].data)
            next_left = i;
        else if(tree[index].right == tree[i].data)
            next_right = i;
    }
    if(next_left != -1)
        inorder(tree, n, next_left);
    printf("%c", tree[index].data);
    if(next_right != -1)
        inorder(tree, n, next_right);
}

void postorder(Node *tree, int n, int index)
{
    int next_left = -1;
    int next_right = -1;

    for(int i = 0; i < n; i++)
    {
        if(tree[index].left == tree[i].data)
            next_left = i;
        else if(tree[index].right == tree[i].data)
            next_right = i;
    }
    if(next_left != -1)
        postorder(tree, n, next_left);
    if(next_right != -1)
        postorder(tree, n, next_right);
    printf("%c", tree[index].data);
}

int main(void)
{
    int n;
    Node *tree;

    scanf("%d", &n);
    tree = (Node *)malloc(sizeof(Node) * n);
    for(int i = 0; i < n; i++)
    {
        scanf(" %c %c %c", &tree[i].data, &tree[i].left, &tree[i].right);
    }
    preorder(tree, n, 0);
    printf("\n");
    inorder(tree, n, 0);
    printf("\n");
    postorder(tree, n, 0);
    free(tree);
    return 0;
}