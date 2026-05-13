#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* newNode(int val)
{
    struct Node *node;
    node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node *root, int val)
{
    if (root == NULL)
    {
        return newNode(val);
    }
    if (val <= root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
}

void inord(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inord(root->left);
    printf("%d", root->data);
    inord(root->right);
}

void preorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d", root->data);
    preorder(root->left);
    preorder(root->right);
}

int getHeight(struct Node *root)
{
    int lh;
    int rh;
    if (root == NULL)
    {
        return -1;
    }
    lh = getHeight(root->left);
    rh = getHeight(root->right);
    if (lh > rh)
    {
        return lh + 1;
    }
    return rh + 1;
}

void levelOrder(struct Node *root, int digits[], int n)
{
    struct Node *queue[10];
    int level[10];
    int front;
    int rear;
    int i;
    int nodeLevel;
    int resultLevel[10];
    struct Node *cur;

    front = 0;
    rear = 0;

    queue[rear] = root;
    level[rear] = 1;
    rear++;

    while (front < rear)
    {
        cur = queue[front];
        nodeLevel = level[front];
        front++;

        for (i = 0; i < n; i++)
        {
            if (cur->data == digits[i])
            {
                resultLevel[i] = nodeLevel;
                break;
            }
        }

        if (cur->left != NULL)
        {
            queue[rear] = cur->left;
            level[rear] = nodeLevel + 1;
            rear++;
        }
        if (cur->right != NULL)
        {
            queue[rear] = cur->right;
            level[rear] = nodeLevel + 1;
            rear++;
        }
    }

    for (i = 0; i < n; i++)
    {
        printf("L%d\n", resultLevel[i]);
    }
}

void postOrderHeightDepth(struct Node *root, int digits[], int n, int depth)
{
    int i;
    int h;
    if (root == NULL)
    {
        return;
    }
    postOrderHeightDepth(root->left, digits, n, depth + 1);
    postOrderHeightDepth(root->right, digits, n, depth + 1);

    h = getHeight(root);
    for (i = 0; i < n; i++)
    {
        if (digits[i] == root->data)
        {
            printf("Height of Node %d = H%d, Depth of Node %d = Y%d\n", i + 1, h, i + 1, depth);
            break;
        }
    }
}

int main()
{
    int digits[5];
    int original[5];
    int i;
    struct Node *root;

    root = NULL;

    printf("Enter last 5 digits of roll number:\n");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &digits[i]);
        original[i] = digits[i];
    }

    for (i = 0; i < 5; i++)
    {
        root = insert(root, digits[i]);
    }

    inord(root);
    printf("\n");

    preorder(root);
    printf("\n");

    levelOrder(root, original, 5);

    postOrderHeightDepth(root, original, 5, 0);

    return 0;
}