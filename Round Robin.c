//https://www.javatpoint.com/os-round-robin-scheduling-algorithm
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define scan(n) scanf("%d",&(n))
#define print(n) printf("%d ",(n))
#define MAX 100000
#define NIL NULL
typedef struct {
    int id , at , bt , wt, tat , ct,rbt , done , present;
}process;

typedef process* qnode;
typedef struct{
    qnode arr[MAX];
    int f, r;
}queue;
void swap(qnode*a , qnode*b){
    qnode t = *a; *a=*b; *b = t;}
void init(queue * q){q->f = -1; q->r = -1;}
int isEmpty(queue*q){ return q->f==-1 || q->r == -1;}
int isFull(queue*q){ return q->r == MAX-1;}
void sortq(queue*q){
    for(int i = q->f ; i<q->r ; i++){
        int mn = i;
        for(int j = i+1 ; j<=q->r ; j++) 
        if(q->arr[mn]->rbt > q->arr[j]->rbt)
        mn = j;
        else if(q->arr[mn]->rbt == q->arr[j]->rbt)
                if(q->arr[mn]->at > q->arr[j]->at) mn = j;
        swap(&q->arr[mn] , &q->arr[i]);
    }
}
void push(queue*q , qnode newnode){
    if(isFull(q)) printf("Full\n");
    if(isFull(q)) return;
    if(isEmpty(q)) q->f = 0;
    q->arr[++q->r] = newnode;
}
qnode pop(queue*q){
    if(isEmpty(q)) printf("empty\n");
    if(isEmpty(q)) return NIL;
    qnode ret = q->arr[q->f];
    q->arr[q->f] = NIL;
    if(q->f == q->r) {
        init(q);
        return ret;
    }
    q->f++;
    return ret;
}

int n = 6;

void printq(queue* q){
    for(int i = q->f ; i<=q->r ; i++) printf("%d ",q->arr[i]->id+1);
    printf("\n");
}

int main(){
    queue que; queue* q= &que; init(q);
    process* p[n];
    for(int i = 0 ; i< n ; i++){
        p[i] = (process*) malloc(sizeof(process));
        p[i]->id = i;
        scan(p[i]->at);
        scan(p[i]->bt);
        p[i]->rbt = p[i]->bt;
        p[i]->wt= 0;
        p[i]->tat= 0;
        p[i]->ct= 0;
        p[i]->done= 0;
        p[i]->present = 0;
    }
    
    int tq = 5;
    int at = 0;
    
    for(int i = 0 ; i<n ; i++)if(p[i]->at <= at) { push(q,p[i]); p[i]->present = 1;}
    
    while(!isEmpty(q)){
        // sortq(q);
        // printq(q);
        qnode it = pop(q);
        it->present = 0;
       
        int t = it->rbt;
        if(t<=tq) {
          it->rbt = 0; at  += t;
          it->ct = at; 
          it->tat = it->ct - it->at ; //CT - AT
          it->wt =it->tat - it->bt ;  //TAT - BT
        }
        else{
          it->rbt -= tq; at+= tq; 
        }
        printf("|P%d ",(it->id +1),at);
        for(int i = 0 ; i<n ; i++)
          if(p[i]->id!=it->id && p[i]->present==0 && p[i]->rbt>0 && p[i]->at <= at) 
          { 
            push(q,p[i]);
            p[i]->present = 1;
          }
        if(it->rbt == 0 )continue;
        push(q,it); it->present = 1;
    }
    printf("\n");
    for(int i = 0 ; i <n ; i++){
        // ID    AT     BT     CT     TAT     WT
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i]->id+1,p[i]->at,p[i]->bt , p[i]->ct ,p[i]->tat,p[i]->wt);
    }
}







