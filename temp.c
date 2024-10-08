#include<stdio.h>
#include<stdlib.h>
#define scan(n) scanf("%d",&(n))
#define newn allocate()
#define MAX_SIZE 100

typedef struct Node{
    int val;
    struct Node* l, *r;
}node;
node* allocate(){return (node*)malloc(sizeof(node)); }
typedef struct Queue{
    node* arr[MAX_SIZE];
    int f,r;
}q;
void init(q* queue){
    queue->r = -1;
    queue->f = -1;}

int isEmpty(q* queue){
    return queue->r == -1  && queue->f == -1;}

int isFull(q* queue){return (queue->r+1)%MAX_SIZE == queue->f;}

void enqueue(q* queue , node* val){
    if(isFull(queue)){printf("FULL %d not queued\n",val->val); return ;}
    if(isEmpty(queue)) queue->f = 0;
    queue->r = (queue->r+1) % MAX_SIZE;
    queue->arr[queue->r] = val;
}

node* dequeue(q* queue){
    if(isEmpty(queue)){printf("Queue Empty\n"); return NULL;}
    node* ret = queue->arr[queue->f];
    queue->arr[queue->f] = NULL;
    if(queue->f != MAX_SIZE-1) queue->f++;
    else queue->f = 0;
    return ret;
}

int main(void){
    q que ; q* queue = &que; init(queue);
    int n , i; scan(n);
    node* t , *tmp ;
    i = 1;
    node* root = newn;
    scan(root->val);
    enqueue(queue,root);
    while(i<n){
        tmp = dequeue(queue);
        if(i<n){
            t = newn;
            scan(t->val);
            enqueue(queue,t);
            tmp->l = t;
            i++;
        }
        if(i<n){
            t= newn;
            scan(t->val);
            enqueue(queue,t);
            tmp->r = t;
            i++;
        }
    } // input
    
    printf("%d",root->val);
    
}
