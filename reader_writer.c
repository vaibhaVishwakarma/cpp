#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
sem_t r ,w;
int nr = 0 , nw= 0;



void* reader(void* iid){
    int id = *(int*)iid;
    while(1){
sem_wait(&r);
nr++;
if(nr == 1) sem_wait(&w);
sem_post(&r);
printf("Reader %d is reading\n",nr);

sem_wait(&r);
nr--;
if(nr == 0) {
    sem_post(&w);
    printf("all reader done\n");
}
sem_post(&r);
sleep(1);
    }
}

void* writer(void* iid){
    int id = *(int*)iid;
    while(1){
sem_wait(&w);
printf("Writer %d is writing\n",id);
sem_post(&w);
printf("Writer %d is DONE\n",id);
sleep(2);

    }
}

int main(){
    
    int n =2;
    int r1 = 1 , r2 = 2 , w1 = 1 , w2 = 2;
    sem_init(&r,0,1);
    sem_init(&w,0,1);
    
    pthread_t t1[n];
    pthread_t t2[n];

        pthread_create(&t1[1] , NULL , reader ,(void*)&r1);
        pthread_create(&t1[2] , NULL , reader ,(void*)&r2);
   
        pthread_create(&t2[1] , NULL , writer ,(void*)&w1);
        pthread_create(&t2[2] , NULL , writer ,(void*)&w2);
    
        pthread_join(t1[1] , NULL);
        pthread_join(t1[2] , NULL);
        pthread_join(t2[1] , NULL);
        pthread_join(t2[2] , NULL);
    

      
    
    return 0;
}
