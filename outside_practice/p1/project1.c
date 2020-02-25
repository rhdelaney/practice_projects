#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
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

int size_val;
int length;
int run = 1;
int awakened = 0;
int waiting = 0;
int allCarsWaiting = 0;
sem_t carsWaiting, spots;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; 
pthread_mutex_t lockMech = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t OilLock = PTHREAD_MUTEX_INITIALIZER;

typedef void (*Printer)(FILE*,void*);

//Comparator comp;
//Reader readfff;
Printer print;
FILE *fp; 
queue *input;
/* One TA thread will be running */
void *lotRunner() {
    while (run) {
        pthread_mutex_lock(&OilLock);
        sem_wait(&spots)
        pthread_mutex_lock(&mutex);
      //  if (waiting==0) printf("TA is sleeping\n");
        if (waiting >0) {
            if (!awakened) {
               // printf("TA is awakened\n");
                awakened=1;
            }
            sem_wait(&carsWaiting);
            void* p = dequeue(input); 
            printf("Customer %s - (MC) is being serviced by the mechanic for %d second(s)\n", getPeopleName((people *) p), getPeopleMechanic((people *) p));
            allCarsWaiting = allCarsWaiting - 1;
            waiting = waiting - 1;
        }
        sleep(1);//getPeopleMechanic((people *) p));
        pthread_mutex_unlock(&mutex);
        sem_post(&spots);
        pthread_mutex_unlock(&OilLock);
    }
    pthread_exit(0);
}/* End of taRunner */

/* Car threads that will execute */
void *carRunner(void *arg) {
    people* p = (people *) arg;
    printf("Customer %s - (MA) arrival\n", p->name);
    if (waiting < size_val || allCarsWaiting>0) {
        /* studentsWaiting = studentsWaiting+1;*/
        pthread_mutex_lock(&lockMech);
        //printf("Customer %s - (MB) is waiting for mechanic\n", p->name);
        waiting = waiting + 1;
        allCarsWaiting = allCarsWaiting + 1;
        
        enqueue(input, p);
        
        pthread_mutex_unlock(&lockMech);
        /*sem_post(&studentsWaiting);*/
        sem_post(&spots);
        pthread_mutex_unlock(&OilLock);
        
    } else {
        allCarsWaiting = allCarsWaiting + 1;
        printf("Customer %s - (MZ) leaves busy car maintenance shop\n", p->name);
        pthread_mutex_unlock(&mutex);
    }
            
    pthread_exit(0);
}/* End method studentRunner */


int main() {
        //printf("Out here!\n");     
        fp = fopen("jobcard", "r");
        size_val = readInt(fp);
        //printf("Size = %d\n", size_val);
        /*char dummy=readChar(fp);
        dummy='n';*/
        char *lot_size = readString(fp);
        lot_size=readString(fp);
        //int lot[size_val];
        
        print = displayPeople;
        //readfff= readPeople;
        //comp = intComparator;
    //Creates Queue
    input = newQueue(print);
//start here and work down? 
    pthread_t lotThread;
    pthread_t carThreads[size_val];
    sem_init(&carsWaiting, 0, 3);
    sem_init(&spots, 0, 1); //what do the numbers mean raychel lol
    pthread_create(&lotThread, NULL, lotRunner, NULL);
    int i;
    int prev=0;
    for (i=0; i<(size_val*size_val); i++) {
    //**create the people right here I think**
      /*  student* argument = (student*) malloc(sizeof(student));
        argument->status=1;
        argument->id=i;*/
            char *name=readString(fp);
            int arr = readInt(fp);
            void *dummy=readString(fp);
            int mech = readInt(fp);
            dummy=readString(fp);
            int oil = readInt(fp);
            sleep(arr-prev);
        pthread_create(&carThreads[i], NULL, carRunner, newPeople(name, arr, mech, oil));
        prev=arr;
        if(feof(fp)){
            break;
        }
    }
    //length = size_val;
    //sleep(length);
    run=0;
    for (i=0; i<size_val; i++) {
        pthread_join(carThreads[i], NULL);
    }
    abort();
}
/* } End main method */


    //stack *stack = newStack(print);
    //queue *output = newQueue(print);
/*    read(input, fp);
    
    displayQueue(stdout, input);
    printf("\n");
    //sqsort(input, comp, print);
    //displayQueue(stdout,input);
    //printf("\n");
    return 0;
}*/
