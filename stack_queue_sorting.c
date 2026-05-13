#include <stdio.h>

int stack[5];
int top = -1;
int queue[5];
int front = 0;
int rear = 0;
void push(int val)
{
    top++;
    stack[top] = val;
}
int pop()
{
    int val;
    val = stack[top];
    top--;
    return val;
}
void enqueue(int val)
{
    queue[rear] = val;
    rear++;
}
int dequeue()
{
    int val;
    val = queue[front];
    front++;
    return val;
}
void bubbleSort(int arr[], int n)
{
    int i;
    int j;
    int temp;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main()
{
    int digits[5] = {1, 8, 0, 4, 7};
    int sorted[5];
    int i;
    int popped;
    for (i = 0; i < 5; i++)
    {
        sorted[i] = digits[i];
    }
    bubbleSort(sorted, 5);
    for (i = 0; i < 5; i++)
    {
        printf("%d", sorted[i]);
    }
    printf("\n");
    for (i = 0; i < 5; i++)
    {
        push(digits[i]);
    }
    for (i = 0; i < 5; i++)
    {
        popped = pop();
        printf("%d", popped);
        enqueue(popped);
    }
    printf("\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d", dequeue());
    }
    printf("\n");
    return 0;
}