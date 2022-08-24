#include<stdio.h>
#include<stdlib.h>
struct circularQueue{
int size; int f;
int r;
int *arr;
};
int isFull(struct circularQueue * q)
{
    if((q->r+1) % q->size == q->f )
    {
        return 1;
    }
    return 0;

}
int isEmpty(struct circularQueue * q)
{
    if(q->r == q->f)
    {
        return 1;
    }
    return 0;

}
void enqueue(struct circularQueue * q, int val)
{
    //O(1)
    if(isFull(q))
    {
        printf("This queue is full");
    }
    else
    {
        q -> r = (q -> r+1) % q->size;
        q -> arr[q->r] = val;
    }
}
int dequeue(struct circularQueue * q)
{
    //O(n)
    if(isEmpty(q))
    {
        printf("This queue is Empty");
    }
    else
    {
        q -> f = (q -> f+1) % q->size;
        return q -> arr[q->f];
    }
}

int main()
{
    struct circularQueue q;
    q.size = 100;
    q.f = q.r = 0;
    q.arr = (int *) malloc(q.size * sizeof(int));
    if(isEmpty(&q))
    {
        printf("Queue is Empty.\n");
    }
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 111);
    dequeue(&q);
    if(isEmpty(&q))
    {
        printf("Queue is Empty.\n");
    }
    return 0;
}
