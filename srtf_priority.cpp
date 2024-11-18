#include <bits/stdc++.h>
#define scan(n) scanf("%d",&(n))
using namespace std;
typedef struct {
    int id , at , bt , wt, tat , ct,rbt , priority , present;
}process;
struct compare{
    bool operator()(const process* p1, const process* p2) {
        // Higher priority first
        if (p1->priority != p2->priority)
            return p1->priority > p2->priority; // Smaller priority value comes later
        // Shorter burst time next
        if (p1->bt != p2->bt)
            return p1->bt > p2->bt; // Larger burst time comes later
        // Earlier arrival time next
        return p1->at > p2->at; // Larger arrival time comes later
    }
};

int n = 4;
int main()
{
    std::priority_queue<process*,vector<process*>,compare> q;
    
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
        scan(p[i]->priority);
        p[i]->present = 0;
    }
    
    int tq = 1;
    int at = 0;
    
    for(int i = 0 ; i<n ; i++)if(p[i]->at <= at) {q.push(p[i]); p[i]->present = 1;}
    
    while(!q.empty()){
        process* it = q.top(); q.pop();
        it->present = 0;
       
        int t = it->rbt;
        if(t<=tq) {it->rbt = 0; at  += t;  it->ct = at; it->tat = it->ct - it->at ; it->wt =it->tat - it->bt ;}
        else{it->rbt -= tq; at+= tq; }
        printf("|P%d ",it->id+1);
        
        for(int i = 0 ; i<n ; i++)if( p[i]->present==0 && p[i]->rbt>0 && p[i]->at <= at) { q.push(p[i]); p[i]->present = 1;}
    }
    printf("\n");
    for(int i = 0 ; i <n ; i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i]->id+1,p[i]->at,p[i]->bt,p[i]->priority , p[i]->ct ,p[i]->tat,p[i]->wt   );
    }

    return 0;
}
