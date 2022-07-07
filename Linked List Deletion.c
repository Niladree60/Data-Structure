#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void linkedListTraversal(struct Node * ptr)
{
    while(ptr != NULL)
    {
        printf("Element : %d \n", ptr -> data);
        ptr = ptr -> next;
    }
}

struct Node * deleteFirst(struct Node * head)
{
    //O(1)
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
struct Node * deleteAtIndex(struct Node * head, int index)
{
    //O(n) delete in between
    struct Node * p = head;
    struct Node * q = head->next;
    for(int i  = 0 ; i < index-1 ; i++)
    {
        p  =p-> next;
        q = q-> next;
    }
    p -> next = q->next;
    free(q);
    return head;
}
struct Node * deleteLastNode(struct Node * head)
{
    //O(n) delete in between
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->next != NULL)
    {

        p  =p-> next;
        q = q-> next;
    }
    p -> next = NULL;
    free(q);
    return head;
}
// Delete a node with a given value (First node with that value)
struct Node * deleteNodeWithGivenValue(struct Node * head, int value)
{
    //O(n) delete in between
    struct Node * p = head;
    struct Node * q = head->next;
    while(q->data != value && q -> next != NULL)
    {
        p  =p-> next;
        q = q-> next;
    }
    if(q -> data == value)
    {
        p -> next = q -> next;
        free(q);
    }
    return head;
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
    head -> data = 4;
    head -> next  = second;

    // link second and third node
    second -> data = 3;
    second -> next  = third;

    // link third and fourth node
    third -> data = 8;
    third -> next  = fourth;

    // terminate the link at the third node
    fourth -> data = 1;
    fourth -> next  = NULL;
    printf("Before Deletion\n");
    linkedListTraversal(head);
    //head = deleteFirst(head);
    //head = deleteAtIndex(head,2);
    //head = deleteLastNode(head);
    head = deleteNodeWithGivenValue(head,3);
    printf("After Deletion\n");
    linkedListTraversal(head);

    return 0;
}
