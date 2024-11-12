//QUEUE
#include<stdio.h>
#include<stdlib.h>
#define MAX 4
#define scan(n) scanf("%d",&(n))
#define print(n) printf("%d ",(n))
#define NIL 0
typedef int qnode;
typedef struct qq{
    qnode arr[MAX];
    int f , r;
}q;
void swap(qnode *a , qnode*b){
    qnode t = *a;
    *a = *b ;
    *b = t;
}
void init(q* queue){ queue->f = -1; queue->r = -1;}
int isFull(q* queue){return queue->f == ((queue->r+1)%MAX);}
int isSingular(q* queue){return queue->f == queue->r;} 
int isEmpty(q* queue){return queue->f == -1 || -1 == queue->r;} 
void sortq(q*queue){
    // int base = queue->f , end = queue->r;
    for(int i = queue->f ; i!=queue->r ; i = (i+1)%MAX){
        int mni = i;
        for(int j = (i+1)%MAX ; j!= (queue->r+1)%MAX ; j = (j+1)%MAX){
            if(queue->arr[mni] > queue->arr[j]) mni = j;
        }
        swap(&queue->arr[mni] , &queue->arr[i]);
    }
}
void push(q* queue , qnode newnode){
    if(isFull(queue)){ printf("queue full\n"); return;}
    if(isEmpty(queue)) queue->f=0;
    queue->r = (queue->r+1)%MAX;
    queue->arr[queue->r] = newnode;
}
qnode pop(q* queue){
    if(isEmpty(queue)) {printf("Empty queue\n") ; return NIL;}
    qnode ret  = queue->arr[queue->f];
    queue->arr[queue->f] = NIL;
    if(isSingular(queue)){
        init(queue);
        return ret;
    }
    queue->f = (queue->f+1)%MAX;
    return ret;
}

void printq(q* queue){
    for(int i = queue->f ; i!=queue->r ; i= (i+1)%MAX)
        print(queue->arr[i]);
    print(queue->arr[queue->r]);
    printf("\n");
}
int main(void){

    q qq; q* que=&qq; init(que);
    push(que,4);
    push(que,4);
    push(que,4);
    push(que,4);
    pop(que);
    pop(que);
    push(que,1);
    push(que,-1);
    print(que->f);
    print(que->r);
    printf("\n");
    printq(que);
    sortq(que);
    print(que->f);
    print(que->r);
    printf("\n");
    printq(que);
}
