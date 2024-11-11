// You are using GCC
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define scan(n) scanf("%d",&(n))
#define print(n) printf("%d ",n)
#define NIL {0,0,0}
#define INF INT_MAX
#include<limits.h>
int V =0   , E = 0;

typedef struct{
    int first , second;
}pair;
typedef struct{
    int first , second,third;
}tri;

typedef tri qnode;
typedef struct QQ{
    qnode arr[MAX];
    int f , r;
}q;
void swap(tri* q1 , tri* q2){
    tri t = *q1;
    *q1 = *q2;
    *q2 = t;
}
void swap(pair* q1 , pair* q2){
    pair t = *q1;
    *q1 = *q2;
    *q2 = t;
}
void swap(int* q1 , int* q2){
    int t = *q1;
    *q1 = *q2;
    *q2 = t;
}
void swap(q** q1 , q** q2){
    q* t = *q1;
    *q1 = *q2;
    *q2 = t;
}
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
int increase(int i ){return (i+1)%MAX;}
void sortq(q*queue){
    for(int i = queue->f ; i != queue->r ; i = increase(i)){
        int mni = i;
        for(int j = (i+1)%MAX ;  j != (queue->r+1)%MAX ; j = increase(j)){
            if(queue->arr[mni].second > queue->arr[j].second)  
            // && queue->arr[mni].third > queue->arr[j].third)
                mni = j;
            
            
        }
        if(i!=mni) swap(&queue->arr[i] , &queue->arr[mni]);
    }
}
    
void push(q* queue , qnode newnode){
    if(isFull(queue)){printf("full\n"); return;}
    if(isEmpty(queue)) queue->f = 0;
    queue->r = (queue->r+1)%MAX;
    queue->arr[queue->r] = newnode;
    // sortq(queue);
} //priority queue
qnode pop(q* queue ){
    if(isEmpty(queue)){printf("empty\n"); return NIL;}
    qnode ret = queue->arr[queue->f];
    queue->arr[queue->f] = NIL;
    if(isSingular(queue))init(queue);
    else queue->f = (queue->f+1)%MAX;
    return ret;}

void printqf(q* queue ){
    if(isEmpty(queue)) return;
    for(int i = queue->f ; i!=queue->r ; i = increase(i))
        print(queue->arr[i].first);
    print(queue->arr[queue->r].first);
    printf("\n");
}
void printq(q* queue ){
    if(isEmpty(queue)) return;
    for(int i = queue->f ; i!=queue->r ; i = increase(i))
        print(queue->arr[i].second);
    print(queue->arr[queue->r].second);
    printf("\n");
}
int getsum(int* arr){
    int sm = 0;
    for(int i = 0 ; i <V ; i++) sm+= arr[i];
    return sm;
}

int main(void){
    
    scan(V);
    int adj[V][V];
    for(int i = 0 ; i<V ; i++) 
    for(int j = 0 ; j<V ; j++) adj[i][j] = 0; 
    
    for(int i = 0 ; i<V ; i++) 
    for(int j = 0 ; j<V ; j++) scan(adj[i][j]); 
    
    // for(int i = 0 ; i<V ; i++) {
        // for(int j = 0 ; j<V ; j++) print(adj[i][j]); printf("\n");}
    for(int i = 0 ; i<V ; i++) {
        for(int j = 0 ; j<V ; j++) if(adj[i][j] == 0 ) adj[i][j] = INF;}
    //input ends here
    
    
    int src , dest ; scan(src) ; scan(dest);
    
    
    
    
    int parent[V]; for(int i = 0 ; i<V ; i++) parent[i] = -1;
    int visited[V]; for(int i = 0 ; i<V ; i++) visited[i] = 0;
    int dist[V]; for(int i = 0 ; i<V ; i++) dist[i] = INF;
    dist[src] = 0;
    
    q qq , qq2 ; q* que = &qq , *que2 = &qq2; init(que);init(que2);
    push(que,{src,0,src});
    
    while(!isEmpty(que)){
        sortq(que);
        tri it = pop(que);
        int src = it.first , weight = it.second ,  prt = it.third;
        visited[src] = 1;
        parent[src] = prt;
        
        for(int v = 0 ; v<V ; v++){
            if(src == v || adj[src][v] == INF || visited[v] ) continue;
            int d = dist[src] + adj[src][v];
            if(dist[v] <= d) continue;
            dist[v] = d;
            // printf("pushed %d  parent %d dist %d",v , src , d);
            push(que2,{v,d,src});
        }
        
        if(isEmpty(que)) 
            swap(&que,&que2);
    }
    parent[src] = -1;
    int arr[V] = {0};
    
    int t = dest;
    int idx = 0;
    while(parent[t] != -1){
        arr[idx++] = t;
        t = parent[t];
    }
    arr[idx] = src;
    printf("Shortest path: %d\n",dist[dest]);
    printf("Path: ");
    for(int i = idx ; i>0 ; i-- ){
        print(arr[i]);
        printf("-> ");
    }
    print(arr[0]);
    
    
    

    return 0;
    
}
    


 

 
