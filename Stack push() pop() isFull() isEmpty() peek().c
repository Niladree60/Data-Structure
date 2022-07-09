#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr; // Array in Heap

};
void display(struct stack *  ptr){
    for (int i = 0; i < ptr->size; i++)
    {
        printf("%d\n",ptr->arr[i]);
    }

}
int isEmpty(struct stack * ptr)
{
    if(ptr -> top == -1)
    {
        return 1;
    }
    else return 0;

}
int isFull(struct stack * ptr)
{
    if(ptr -> top == ptr -> size -1)
    {
        return 1;
    }
    else return 0;

}
void push ( struct stack * ptr, int val)
{
    if(isFull(ptr))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        ptr -> top++;
        ptr -> arr[ptr->top] = val;
    }
}
int pop ( struct stack * ptr)
{
    if(isEmpty(ptr))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peek(struct stack * sp, int i)
{
    int indx = sp -> top-i+1;
    if(indx < 0)
    {
        printf("Not a Valid Position\n");
        return -1;
    }
    else
    {
        return sp->arr[indx];

    }
}
int main()
{

    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));// stack pointer
    sp->size = 5; // Arrow operator does dereferencing then add dot
    sp->top = -1;
    sp->arr = (int *)malloc(sp -> size * sizeof(int));

    printf("Stack Created Successfully\n");

    push(sp,56);
    push(sp,57);
    push(sp,58);
    push(sp,59);
    push(sp,60);
    display(sp);
    printf("Popped %d from the stack\n", pop(sp));
    printf("Peeked %d from the stack\n", peek(sp,1));

    return 0;
}
