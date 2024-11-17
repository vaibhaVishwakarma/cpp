// You are using GCC
#include<stdio.h>
#include<limits.h>
#define MAX 100000
#define INF INT_MAX
#define scan(n) scanf("%d",&(n))
#define NIL {0,0,0}
#define prints(s) printf("%s",s);
void print(int d){printf("%d ",d);}
int V , E ;
typedef struct{
    int first ,second , third;
}tri;
typedef tri qnode;
void swap(qnode *a , qnode* b){
    qnode t = *a;
    *a = *b;
    *b = t;
}
typedef struct{
    qnode arr[MAX];
    int f , r;
}queue;
void init(queue* q){q->f = -1 ; q->r = -1;}
int isEmpty(queue* q){return q->f == -1 || q->r == -1;}
int isFull(queue* q){ return q->r == MAX-1;}
void sortq(queue* q){
    int base = q->f , end = q->r +1 ;
    for(int i = base ; i< end-1 ; i++){
        int mn = i;
        for(int j = i+1 ; j<end ; j++)
        if(q->arr[mn].second > q->arr[j].second) mn = j;
        swap(&q->arr[mn], &q->arr[i]);
    }
}
void push(queue* q , qnode newnode){
    if(isFull(q)){prints("full\n") ; return;}
    if(isEmpty(q)) q->f = 0;
    q->arr[++q->r]=newnode;
}
qnode pop(queue* q){
    if(isEmpty(q)){prints("Empty\n"); return NIL;}
    qnode ret = q->arr[q->f];
    if(q->f == q->r) {
        init(q); return ret;
    }
    q->f = q->f +1;
    return ret;
}
void printq(queue * q){
    int base = q->f , end = q->r+1;
    for(int i = base ; i<end ; i++) print(q->arr[i].second);
    prints("\n");
}

int main(){
    scan(V); scan(E);
    int adj[V][V];
    for(int i = 0 ; i<E ; i++){
        int r , c;
        scan(r); scan(c);
        scan(adj[r][c]);
        adj[c][r] = adj[r][c];
    }
    for(int i = 0 ; i<V ; i++)
    for(int j = 0 ; j<V ; j++) if(adj[i][j] == 0) adj[i][j] = INF;
    int src; scan(src);
    //input
    
    
    int visited[V]; for(int i = 0 ; i<V ; i++) visited[i] = 0;
    int parent[V]; for(int i = 0 ; i<V ; i++) parent[i] = -1;
    int dist[V]; for(int i = 0 ; i<V ; i++) dist[i] = INF;
    queue q; queue* que = &q; init(que);
    //initialising
    
    
    push(que,{src,0,-1});
    dist[src] = 0;
    
    while(!isEmpty(que)){
        sortq(que);
        qnode it = pop(que);
        int curr = it.first , w = it.second , prt = it.third;
        if(visited[curr]) continue;
        visited[curr] = 1;
        parent[curr] = prt;
        
        for(int i = 0 ; i<V ; i++){
            if(i == curr || adj[curr][i] == INF || visited[i] ) continue;
            int d = adj[curr][i] + dist[curr];
            if(dist[i] <= d) continue;
            push(que,{i,adj[curr][i],curr});
            dist[i] = d;

        }
        
    }
    prints("Shortest distances from vertex "); print(src); prints("to all other vertices: ");
    for(int i = 0 ; i<V ; i++) print(dist[i]);
    
    return 0;
}












