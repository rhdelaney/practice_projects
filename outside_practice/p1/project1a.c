#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "integer.h"
#include "queue.h"
#include "stack.h"
#include "comparator.h"
#include "readin.h"
#include "real.h"
#include "string.h"
#include "scanner.h"
#include "people.h"
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <time.h>
#include <ctype.h>

//shouldn't sleep with the lock
//cond_sig only on if's not whiles
//
//

/*
Raychel Delaney 426-Fall 2017
Used the data structures library created in CS201-Spring 2017
Basically used a queue to store mechLot, oilLot,carsLot
3 different threads running through
each has a condition signal
I had a status inside the person class(class I created for the cars/customers) called "sig"
Honestly I had this all done before the last day and talked to one person realizing I was completely off
so I redid the whole thing
rip me
*/
int size_val;
int run = 1;
pthread_mutex_t mechLock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t oilLock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t cusLock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t mechSig = PTHREAD_COND_INITIALIZER;
pthread_cond_t oilSig =PTHREAD_COND_INITIALIZER;
pthread_cond_t cusSig =PTHREAD_COND_INITIALIZER;
int mechSleep=0;
int oilSleep=0;


typedef void (*Printer)(FILE*,void*);

Printer print;
FILE *fp; 
queue *mechLot;
queue *oilLot;
queue *carsLot;

void *oilRunner() {
    while(1){
        pthread_mutex_lock(&oilLock);
        if(sizeQueue(oilLot)>0){
            people* p = dequeue(oilLot);
            printf("Customer %s - (MCL) is being serviced by the oil tech for %d seconds\n", p->name, p->oilchange_dur);
            sleep(p->oilchange_dur);
            pthread_mutex_unlock(&oilLock);
            pthread_mutex_lock(&cusLock);
            p->sig=1;
            pthread_mutex_unlock(&cusLock);
            pthread_cond_signal(&cusSig);
        }
        else{
            oilSleep=0;
            pthread_mutex_unlock(&oilLock);

        }
        pthread_mutex_lock(&oilLock);
        while(oilSleep){
            pthread_cond_wait(&oilSig,&oilLock);
        }

        pthread_mutex_unlock(&oilLock);
    }
}

void *mechRunner() {
    while(1){
        pthread_mutex_lock(&mechLock);
        if(sizeQueue(mechLot)>0){
            people* a = dequeue(mechLot);
            printf("Customer %s - (MC) is being serviced by the mechanic for %d seconds\n", getPeopleName(a), getPeopleMechanic(a));
            sleep(getPeopleMechanic(a));
            pthread_mutex_unlock(&mechLock);
            pthread_mutex_lock(&cusLock);
            a->sig=1;
            pthread_mutex_unlock(&cusLock);
            pthread_cond_signal(&cusSig);
        }
        else{
            mechSleep=0;
            pthread_mutex_unlock(&mechLock);

        }
        pthread_mutex_lock(&mechLock);
        while(mechSleep){
            pthread_cond_wait(&mechSig,&mechLock);
        }

        pthread_mutex_unlock(&mechLock);
    }
}
void *customerRunner(void *arg){
    pthread_mutex_lock(&mechLock);
    people* b = (people *) arg;
    printf("Customer %s - (MA) arrival\n", b->name);
    if(sizeQueue(mechLot)>=size_val){
        printf("Customer %s - (MZ) leaves busy car maintenance shop\n", b->name);
        pthread_mutex_unlock(&mechLock);
        pthread_exit(0);
    }
    else{
        if(sizeQueue(mechLot)>0){
            printf("Customer %s - (MB1) is waiting for mechanic\n", b->name);
        }
        enqueue(mechLot,b);
        if(mechSleep==0){
            mechSleep=1;
            pthread_mutex_unlock(&mechLock);
            pthread_cond_signal(&mechSig);
        }
        else{
            pthread_mutex_unlock(&mechLock);
        }
        pthread_mutex_lock(&cusLock);
        while(!b->sig){
            pthread_cond_wait(&cusSig,&cusLock);
        }
        pthread_mutex_unlock(&cusLock);
        pthread_mutex_lock(&mechLock);
        if(sizeQueue(mechLot)>0){
            people *q=peekQueue(mechLot);
            if(strcmp(q->name,b->name)!=0){
                printf("Customer %s - (MC1) notifying customer %s that they are next for mechanic\n", b->name,q->name);
                printf("Customer %s - (MB2) is no longer waiting for mechanic; signaled by %s\n", q->name, b->name);
            }
        }
        pthread_mutex_unlock(&mechLock);
        printf("Customer %s - (MD) is done with mechanic\n", b->name);
        if(b->oilchange_dur!=0){
            if(sizeQueue(oilLot)>0){
                printf("Customer %s - (MBL1) is waiting for oil change tech \n", b->name);
            }
        enqueue(oilLot,b);
        if(oilSleep==0){
            oilSleep=1;
            pthread_mutex_unlock(&oilLock);
            pthread_cond_signal(&oilSig);
        }
        else{
            pthread_mutex_unlock(&oilLock);
        }
        pthread_mutex_lock(&cusLock);
        while(!b->sig){
            pthread_cond_wait(&cusSig,&cusLock);
        }
        pthread_mutex_unlock(&cusLock);
        pthread_mutex_lock(&oilLock);
        if(sizeQueue(oilLot)>0){
            people *k=peekQueue(oilLot);
            printf("Customer %s - (MCL1) notifying customer %s that they are next for oil change tech\n", b->name, k->name);
            printf("Customer %s - (MBL2) is no longer waiting for oil change tech; signaled by %s\n",k->name,b->name);
        }
        pthread_mutex_unlock(&oilLock);
        printf("Customer %s - (ML) is done with oil change tech\n", b->name);
        }
        printf("Customer %s - (ME) is leaving shop\n", b->name);
    }
    pthread_exit(0);
}

int main() { 
        fp = fopen("jobcard", "r");
        print=displayPeople;
        mechLot=newQueue(print);
        oilLot=newQueue(print);
        carsLot=newQueue(print);
        char *name=(char *)malloc(sizeof(50));
        fscanf(fp,"%d",&size_val);
        while(fgetc(fp)!='\n');
        pthread_t oilThread;
        pthread_t mechThread;
        pthread_t carThread;
        pthread_create(&oilThread, NULL, oilRunner, NULL);
        pthread_create(&mechThread, NULL, mechRunner, NULL);
       
        int prev=0;
        int i=0;
        int arr,mech,oil;
        while(fscanf(fp,"%[^,],%d,%d,%d\n",name,&arr,&mech,&oil)==4){
            pthread_create(&carThread, NULL, customerRunner, newPeople(name, arr, mech, oil));
            enqueue(carsLot,&carThread);
            sleep(arr-prev);
            prev=arr;
            name=malloc(sizeof(char)*50);
            i++;
        }
        //int j;
        //for (j=0; j<i; j++) {
        //    pthread_join(&carThread, NULL);
        //}
    return 0;
}


