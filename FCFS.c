//https://www.javatpoint.com/os-fcfs-scheduling
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

int n = 6;

int get_min(process** p){
   int mn = p[0]->at;
    for(int i = 0 ; i<n ; i++){
        if(p[i]->at < mn) mn= p[i]->at;
    }
    return mn;
}
int isComplete(process** p){
    int mn = 0;
    for(int i = 0 ; i<n ; i++){
        mn+=p[i]->done;
    }
    return mn==n;
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
    
    int tq = 1;
    int at = get_min(p);
 
    while(!isComplete(p)){
        
        for(int i = 0 ; i<n ; i++){
            if(p[i]->done==1 || p[i]->at > at) continue;
            printf("|P%d ",i);
            p[i]->done = 1;
            at += p[i]->bt;
            p[i]->ct = at; 
            p[i]->tat = p[i]->ct - p[i]->at ; //CT - AT
            p[i]->wt =p[i]->tat - p[i]->bt ;
        }
        at += 1;
    }
    printf("\n");
    for(int i = 0 ; i <n ; i++){
        // ID    AT     BT     CT     TAT     WT
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i]->id+1,p[i]->at,p[i]->bt , p[i]->ct ,p[i]->tat,p[i]->wt);
    }  
}







