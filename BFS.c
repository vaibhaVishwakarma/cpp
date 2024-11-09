#include<stdio.h>
#define scan(n) scanf("%d",&(n))
#define MAX  15
typedef struct {
    int first , second ; 
}pair;
typedef struct {
    int first , second , third; 
}tri;

typedef struct QQ{
    int arr[MAX];
    int f , r;
}q;


void swap(q** q1 , q** q2){
    q* t = *q1;
    *q1 = *q2;
    *q2 = t;
}

int V  , E ;

void init(q* queue){
    queue->f = -1;
    queue->r = -1;
}
int isFull(q* queue){
    return queue->f == (queue->r+1)%MAX;}
int isEmpty(q* queue){
    return queue->f == -1 || queue->r == -1;}
int isSingular(q* queue){
    return queue->f == queue->r ;}
void push(q* queue , int newnode){
    if(isFull(queue)){printf("full\n"); return;}
    if(isEmpty(queue)) queue->f = 0;
    queue->r = (queue->r+1)%MAX;
    queue->arr[queue->r] = newnode;
}
int pop(q* queue ){
    if(isEmpty(queue)){printf("empty\n"); return 0;}
    int ret = queue->arr[queue->f];
    queue->arr[queue->f] = 0;
    if(isSingular(queue))init(queue);
    else queue->f = (queue->f+1)%MAX;
    return ret;
}

int main(void){
    
    scan(V);    scan(E);
    
    int adj[V][V]; for(int i = 0 ; i<V ; i++) for(int j = 0 ; j<V ; j++) adj[i][j] =0;
    
    for(int i= 0 ; i<E ; i++){
        int r , c ; 
        scan(r);
        scan(c);
        adj[r][c]=1;
    }
    int src; scan(src);
    
    q qq , qq2 ;
    q* que = &qq; init(que);
    q* que2 = &qq2; init(que2);
    int visited[V]; for(int i = 0; i<V ; i++) visited[i] = 0;
    // for(int i = 0 ; i <V ; i++){
    // for(int j = 0 ; j<V ; j++){printf("%d ",adj[i][j]);} printf("\n");}
    // return 0;
    
    int lvl= 0;
    int found = 0;
    
    
    visited[src]=1; init(que); init(que2);
    push(que,src);

    while(!isEmpty(que)){
        int curr = pop(que);
        printf("%d ",curr);
        for(int edge = 0 ; edge<V ; edge++){
            if( !adj[curr][edge] ) continue;
            if(!visited[edge]){
                visited[edge] = 1;
                // printf("pushed %d in que\n",edge);
                push(que2,edge);
            }
        }
        
        
        if(isEmpty(que)) {
            // printf("swaped\n");
            lvl++;
            swap(&que,&que2);
            }  
}
    return 0;
}



