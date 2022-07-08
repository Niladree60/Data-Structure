
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
    struct Node * prev;
};

void linkedListTraversal(struct Node * ptr)
{
    while(ptr != NULL)
    {
        printf("Element : %d \n", ptr -> data);
        ptr = ptr -> next;

    }


}

int main()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    // Allocate memory for nodes in the linked list in heap
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));

    // link first and second node
    head -> prev = NULL;
    head -> data = 7;
    head -> next  = second;

    // link second and third node
    second -> data = 777;
    second -> next  = third;
    second -> prev = head;

    // link third and fourth node
    third -> data = 777;
    third -> next  = fourth;
    third -> prev = second;

    // terminate the link at the third node
    fourth -> data = 778;
    fourth -> next  = NULL;
    fourth -> prev = third;
    linkedListTraversal(head);

    return 0;
}
