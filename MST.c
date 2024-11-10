#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define scan(n) scanf("%d",&(n))
#define print(n) printf("%d ",n)
#define NIL {0,0,0}
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
            if(queue->arr[mni].second > queue->arr[j].second ) mni = j;
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
    scan(E);
    int adj[V][V];
    for(int i = 0 ; i<V ; i++) {
    for(int j = 0 ; j<V ; j++) adj[i][j] = 0; }
    for(int i = 0 ; i<E ; i++) {
            int r, c;
            scan(r);
            scan(c);
            scan(adj[r][c]);
            // adj[c][r] = adj[r][c];
        
        }
    // for(int i = 0 ; i<V ; i++) {
        // for(int j = 0 ; j<V ; j++) print(adj[i][j]); printf("\n");}
    for(int i = 0 ; i<V ; i++) {
        for(int j = 0 ; j<V ; j++) if(adj[i][j] == 0 ) adj[i][j] = INT_MAX;}
    //input ends here
    
    
    int parent[V]; for(int i = 0 ; i<V ; i++) parent[i] = -1;
    int visited[V]; for(int i = 0 ; i<V ; i++) visited[i] = 0;
    
    q qq , qq2 ; q* que = &qq , *que2 = &qq2; init(que);init(que2);
    
    push(que , {0,0,0}); // orgin -> o , distance = 0;
    parent[0] = 0;
    int vis = 0;
    int found = 1;
 
    // visited[0] = 1;
    
    int wt = 0;
    while(!isEmpty(que)){
        sortq(que);
        tri it = pop(que);
        int curr = it.first;
        int prt = it.third;
        if(visited[curr] || it.second == INT_MAX) continue;
        parent[curr] = prt;
        visited[curr] = 1;
        if(it.second != INT_MAX)wt += it.second;
        vis++;
        // if(curr != prt)printf("Edge %d:(%d %d) cost:%d\n",vis-1 , parent[curr] , curr , adj[parent[curr]][curr]);
        // printq(que);
        // printqf(que);
        for(int i = 0 ; i<V ; i++){
            if( visited[i]) continue;
            // printf("%d - %d %d\n",curr , i , adj[curr][i]);
            push(que,{i,adj[curr][i],curr});
            // sortq(que);
            // printq(que);
        }
    }
    // printf("Minimum cost = ");
    if(getsum(visited) == V)print(wt);
    else printf("It is not possible to connect all cities.");    
    return 0;
    
}
    

