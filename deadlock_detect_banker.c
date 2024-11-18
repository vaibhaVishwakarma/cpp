#include<stdio.h>
#define scan(n) scanf("%d",&(n))
typedef struct{
    int a,b,c;
    int done;
}resource;


int aa=10 ,
ab=5, 
ac=7 ;
int n = 5;
void print(resource p[]){
    for(int i = 0 ; i<n ; i++)
    printf("sno %d\t%d %d %d\n",i+1,p[i].a,p[i].b,p[i].c);
    printf("\n");
}

int satisfied(resource a , resource b){
    if(a.a - b.a > 0) return 0;
    if(a.b - b.b > 0) return 0;
    if(a.c - b.c > 0) return 0;
    return 1;
}

int main(){
 
    resource allot[n];
    resource max[n];
    resource need[n];
    for(int i = 0 ; i<n ; i++){
        scan(max[i].a);
        scan(max[i].b);
        scan(max[i].c);
    }
    for(int i = 0 ; i<n ; i++){
        scan(allot[i].a); aa -= allot[i].a;
        scan(allot[i].b); ab -= allot[i].b;
        scan(allot[i].c); ac -= allot[i].c;
    }
    
    for(int i = 0 ; i<n ; i++){
        need[i].a = max[i].a - allot[i].a;
        need[i].b = max[i].b - allot[i].b;
        need[i].c = max[i].c - allot[i].c;
        need[i].done = 0;
    }
    
    int done = 0;
    while(done!=n){
    int found = 0;
        // print(need);
        for(int i = 0 ; i<n ; i++){
            resource avail={aa,ab,ac,0};
            // printf("done%d\t%d %d %d\n",done,aa,ab,ac);
            if(need[i].done==0 && satisfied(need[i] , avail) == 1){
                found = 1;
                need[i].done =1;
                done++;
                aa+=allot[i].a;
                ab+=allot[i].b;
                ac+=allot[i].c;
                printf("|%d ",i+1);
                break;
            }
        }
    if(!found) {printf("Deadlock detected\n"); return 0;}
    }
    
    
    
    
    
    
    
    return 0;
}
