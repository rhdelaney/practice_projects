#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <time.h>
#include <ctype.h>

#ifndef __PEOPLE_INCLUDED__
#define __PEOPLE_INCLUDED__

typedef struct people{
    char *name;
    int arrival;
    int mechanic_wait;
    int oilchange_dur;
    int sig;
} people;

extern people *newPeople(char *, int, int, int);
extern int getPeopleArrival(people *);
extern int setPeopleArrival(people *,int);
extern int getPeopleMechanic(people *);
extern int setPeopleMechanic(people *,int);
extern int getPeopleOil(people *);
extern int setPeopleOil(people *,int);
extern char *getPeopleName(people *);
extern char *setPeopleName(people *,char *);
extern void displayPeopleName(FILE *,void *);
extern void displayPeopleArrival(FILE *,void *);
extern void displayPeopleMechanic(FILE *,void *);
extern void displayPeopleOil(FILE *,void *);
extern void displayPeople(FILE *,void *);
extern int comparePeopleArrival(void *,void *);
extern int comparePeopleMechanic(void *,void *);
extern int comparePeopleWait(void *,void *);
extern void freePeople(people *);

#define PINFINITY IN_MAX
#define NINFINITY IN_MIN

#endif