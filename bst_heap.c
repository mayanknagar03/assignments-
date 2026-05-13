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
    if (val < root->data)
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

void postorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d", root->data);
}

void heapifyDown(int arr[], int n, int i)
{
    int largest;
    int left;
    int right;
    int temp;
    largest = i;
    left = 2*i + 1;
    right = 2*i + 2;
    if (left < n && arr[left] >= arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] >= arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapifyDown(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n)
{
    int i;
    for (i = n/2 - 1; i >= 0; i--)
    {
        heapifyDown(arr, n, i);
    }
}

void heapifyDownMin(int arr[], int n, int i)
{
    int smallest;
    int left;
    int right;
    int temp;
    smallest = i;
    left = 2*i + 1;
    right = 2*i + 2;
    if (left < n && arr[left] <= arr[smallest])
    {
        smallest = left;
    }
    if (right < n && arr[right] <= arr[smallest])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapifyDownMin(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n)
{
    int i;
    for (i = n/2 - 1; i >= 0; i--)
    {
        heapifyDownMin(arr, n, i);
    }
}

int main()
{
    int digits[5];
    int original[5];
    int heap[5];
    int i;
    int rollnum;
    int deleted;
    struct Node *root;

    root = NULL;

    printf("Enter last 5 digits of roll number:\n");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &digits[i]);
        original[i] = digits[i];
        heap[i] = digits[i];
    }

    for (i = 0; i < 5; i++)
    {
        root = insert(root, digits[i]);
    }

    inord(root);
    printf("\n");

    postorder(root);
    printf("\n");

    rollnum = 18047;

    if (rollnum % 2 == 0)
    {
        buildMinHeap(heap, 5);
    }
    else
    {
        buildMaxHeap(heap, 5);
    }

    for (i = 0; i < 5; i++)
    {
        printf("%d", heap[i]);
    }
    printf("\n");

    deleted = heap[0];
    heap[0] = heap[4];

    if (rollnum % 2 == 0)
    {
        heapifyDownMin(heap, 4, 0);
    }
    else
    {
        heapifyDown(heap, 4, 0);
    }

    printf("%d\n", deleted);

    for (i = 0; i < 4; i++)
    {
        printf("%d", heap[i]);
    }
    printf("\n");

    return 0;
}