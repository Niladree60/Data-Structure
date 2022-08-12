#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};
struct Node * top;
struct Node * push(struct Node * top, int x)
{
    if(isFull(top))
    {
        printf("Stack Overflow");
    }
    else
    {
        struct Node * n = (struct Node *) malloc(sizeof(struct Node ));
        n -> data = x;
        n -> next = top;
        top = n;
        return top;
    }

}
int pop(struct Node ** top)
{
    if(isEmpty(*top))
    {
        printf("Stack Underflow");
    }
    else
    {
        struct Node * n = *top;
        *top = (*top)->next;
        int x = n -> data;
        free(n);
        return x;
    }

}
int isEmpty(struct Node * top)
{
    if(top == NULL)
    {
        return 1;
    }
    else return 0;

}
int stack_bottom(struct Node * t){
    while(t->next != NULL){
        t = t->next;
    }
    if(t->next == NULL){
        return t->data;
    }
    return -1;
}
int isFull(struct Node * top)
{
    struct Node * p = (struct Node*)malloc(sizeof(struct Node));
    if(p == NULL)
    {

        return 1;
    }
    else return 0;

}
void linkedListTraversal(struct Node * ptr)
{
    while(ptr != NULL)
    {
        printf("Element : %d \n", ptr -> data);
        ptr = ptr -> next;

    }
}
int peek(int pos)
{

    struct Node * ptr  = top;
    for(int i = 0 ; (i < pos-1 && ptr != NULL) ; i++)
    {
        ptr = ptr->next;
    }
    if(ptr != NULL)
    {
        return ptr->data;
    }
    else{
        return -1;
    }
}
int main()
{

    top = push(top,28);
    top = push(top,18);
    top = push(top,15);
    top = push(top,7);
    linkedListTraversal(top);

    for(int i =1  ;  i <= 4 ; i++)
    {
        printf("Value at position %d is : %d\n",i,peek(i));
    }
    /*int element = pop(&top);
    printf("Popped element is %d\n", element);
    linkedListTraversal(top);*/
    return 0;
}
