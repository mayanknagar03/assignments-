#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;};
void heapify(int arr[], int n, int i)
 {
    int large = i, l = 2*i+1, r = 2*i+2, tmp;
    if (l < n && arr[l] > arr[large]) 
    large = l;
    if (r < n && arr[r] > arr[large]) 
    large = r;
    if (large != i) 
    {
        tmp = arr[i]; arr[i] = arr[large]; arr[large] = tmp;
        heapify(arr, n, large);
    }
}
void heapSort(int arr[], int n) {
    int i, tmp;
    for (i = n/2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (i = n-1; i > 0; i--) {
        tmp = arr[0]; arr[0] = arr[i]; arr[i] = tmp;
        heapify(arr, i, 0);
    }
}
struct Node* newNode(int data)
 {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->prev = node->next = NULL;
    return node;
}
int main()
 {
    int digi[5] = {1, 8, 0, 4, 7};
    int sorted[5], i;
    for (i = 0; i < 5; i++)
    {
     sorted[i] = digi[i];
    }
    heapSort(sorted, 5);
    printf("Sorted: ");
    for (i = 0; i < 5; i++) printf("%d", sorted[i]);
    printf("\n");
    int l = 0, r = 4, tmp;
    while (l < r)
    {
        tmp = digi[l]; 
        digi[l] = digi[r]; 
        digi[r] = tmp;
        l++; r--;
    }
    printf("Reversed: ");
    for (i = 0; i < 5; i++)
    {
     printf("%d", digi[i]);
    }
    printf("\n");
    struct Node *head = NULL, *tail = NULL;
    for (i = 0; i < 5; i++)
     {
        struct Node* node = newNode(digi[i]);
        if (!head)
         { 
            head = tail = node;
         }
        else 
        { 
            tail->next = node; 
            node->prev = tail; 
            tail = node;
         }
    }
    printf("Forward: ");
    struct Node* cur = head;
    while (cur)
     {
         printf("%d", cur->data); cur = cur->next; 
     }
           printf("\n");
    printf("Backward: ");
    cur = tail;
    while (cur) 
    { 
        printf("%d", cur->data); cur = cur->prev;
     }
    printf("\n");
    return 0;
}