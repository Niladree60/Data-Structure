#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr; // Array in Heap

};
void display(struct stack *  ptr){
    for (int i = 0; i < ptr->size; i++)
    {
        printf("%d\n",ptr->arr[i]);
    }

}
int isEmpty(struct stack * ptr)
{
    // O(1)
    if(ptr -> top == -1)
    {
        return 1;
    }
    else return 0;

}
int isFull(struct stack * ptr)
{
    // O(1)
    if(ptr -> top == ptr -> size -1)
    {
        return 1;
    }
    else return 0;

}
void push ( struct stack * ptr, char val)
{
    // O(1)
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
char pop ( struct stack * ptr)
{
    // O(1)
    if(isEmpty(ptr))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int peek(struct stack * sp, int i)
{
    // O(1)
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
char stackTop(struct stack * sp)
{
    return sp->arr[sp->top];
}
int stackBottom(struct stack * sp)
{
    return sp->arr[0];
}
int match(char a, char b)
{
    if(a == '{' && b == '}')
    {
        return 1;
    }
    if(a == '(' && b == ')')
    {
        return 1;
    }
    if(a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}
int parenthesisMatch(char * exp)
{
    // create and initialize the stack
    struct stack * sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp -> size * sizeof(char));
    char popped_ch;
    for(int i =0  ; exp[i] != '\0' ; i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp,exp[i]);

        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(isEmpty(sp))
            {
                return 0;
            }
            popped_ch = pop(sp);
            if(!match(popped_ch,exp[i]))
            {
                return 0;
            }
        }
    }
    if(isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char * exp = "[(8)*(9)]";
    if(parenthesisMatch(exp))
    {
        printf("Parenthesis Matching");
    }
    else printf("Parenthesis Not Matching");


    return 0;
}
