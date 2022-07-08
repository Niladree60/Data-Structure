
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
void linkedListTraversal(struct Node *n1){
    struct Node *ptr=n1;
    printf("Traversing left to right\n");
    while(ptr->next!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d ",ptr->data);
    printf("\n");

    printf("Traversing right to left\n");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->prev;
    }
    printf("\n");
}

// Insert at beginning
struct node * insertionatbeginning(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->prev = NULL;
    ptr->next = head;
    ptr->data = data;

    return ptr;
}
//INSERTION_AFTER_VALUE in Doubly Linked list
struct node* insertionaftervalue(struct node* head, int data, int value){
    struct node* ptr=(struct node*) malloc(sizeof(struct node));
    struct node* p= head;
    struct node* q= head->next;
    while(p->data!=value){
        p=p->next;
        q=q->next;
    }
    if(p->data==value){
        p->next=ptr;
        ptr->prev=p;
        ptr->next=q;
        q->prev=ptr;
        ptr->data=data;
    }
    return head;

}
//INSERTION_BEFORE_VALUE in Doubly Linked list

struct node* insertionbeforevalue(struct node* head, int data, int value){
    struct node* ptr= (struct node*) malloc(sizeof(struct node));
    struct node* p=head;
    struct node* q=head->next;
    while(q->data!=value){
        p=p->next;
        q=q->next;
    }
    if(q->data==value){
        p->next=ptr;
        ptr->prev=p;
        ptr->next=q;
        q->prev=ptr;
        ptr->data=data;

    }
    return head;
}
// insertion at the last of the doubly linked list
struct node *insertatlast( node *head, int data){
    node*p=head;
    node *ptr=new node();
    ptr->data=data;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->previous=p;
    ptr->next=NULL;
    return head;


}
//INSERTION_AT_LAST_NODE in Doubly Linked list is

struct node* insertionatlast(struct node* head, int data){
    struct node* ptr=(struct node*) malloc (sizeof(struct node));
    struct node* p=head;
    struct node* q= head->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    if(q->next==NULL){
        q->next=ptr;
        ptr->prev=q;
        ptr->next=NULL;
        ptr->data=data;
    }
    return head;
}
// delete at begining
struct node *deletionatfirst(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;

    q->prev = NULL;
    head = head->next;

    free(p);
    return head;
}

//DELETION_OF_LASTNODE in Doubly Linked List is

struct node* deletionoflastnode(struct node* head){
    struct node* p= head;
    struct node* q= head->next;
    while(q->next!= NULL){
        p=p->next;
        q=q->next;
    }
    if(q->next== NULL){
        p->next=NULL;
        free(q);
    }
    return head;
}
// DELETION_AFTER_NODE in Doubly Linked list is

struct node* deletionofnode(struct node* head, struct node* prevnode){
    struct node* p= head;
    struct node* q=head->next;
    while(q!=prevnode){
        p=p->next;
        q=q->next;
    }
    if(q==prevnode){
        p->next=q->next;
        free(q);
    }
    return head;
}
//delete a node at a given index of the doubly linked list
node *deleteatindex(node *head, int index)
{
    node *p = head;
    node *q = head->next;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    p->previous=q->previous;
    free(q);


    return head;
}

//DELETION_AT_ANY_INDEX in Doubly Linked list is

struct node *deletionatindex(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;

    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;

    }
    p->next = q->next;

    free(q);
    return head;
}

//Delete in between function in doubly linked list:
void deleteInBetween(struct Node* head, int index){ // index = 2, here we want to delete 3rd node
// we need three temporary pointers to delete the node in between in doubly linked list
    struct Node* ptr = head;
    struct Node* temp = head->next;
    struct Node* p = temp->next;
    int i = 0;
    while(i != index-1)
    {
        temp = temp->next;
        ptr = ptr->next;
        p = p->next;
        i++;
    }
    ptr->next = temp->next;  // OR ptr->next = p;
    p->prev = temp->prev;
    free(temp);
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
    head = insertionatbeginning(head,5);
    linkedListTraversal(head);

    return 0;
}
