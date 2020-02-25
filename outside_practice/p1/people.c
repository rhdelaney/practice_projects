#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <time.h>
#include <ctype.h>
#include "people.h"

people *newPeople(char *x, int arr, int mech, int oil){
    people *p = malloc(sizeof(people));
    if (p == 0){ 
        fprintf(stderr,"out of memory\n");
        exit(-1);}
    p->name=malloc(sizeof(strlen(x)));
    strcpy(p->name,x);
    p->arrival=arr;
    p->mechanic_wait=mech;
    p->oilchange_dur=oil;
    p->sig=1;
    return p;
	}
int getPeopleArrival(people *v){
    return v->arrival;
    }
int getPeopleMechanic(people *v){
    return v->mechanic_wait;
	}
int getPeopleOil(people *v){
    return v->oilchange_dur;
	}
int setPeopleArrival(people *v,int x){
    int old = v->arrival;
    v->arrival = x;
    return old;
	}
int setPeopleMechanic(people *v,int x){
    int old = v->mechanic_wait;
    v->mechanic_wait = x;
    return old;
	}
int setPeopleOil(people *v,int x){
    int old = v->oilchange_dur;
    v->oilchange_dur = x;
    return old;
	}

void displayPeopleArrival(FILE *fp,void *v){
    fprintf(fp,"%d",getPeopleArrival((people *) v));
	}
void displayPeopleMechanic(FILE *fp,void *v){
    fprintf(fp,"%d",getPeopleMechanic((people *) v));
	}
void displayPeopleOil(FILE *fp,void *v){
    fprintf(fp,"%d",getPeopleOil((people *) v));
	}

int comparePeopleArrival(void *v,void *w){
    return ((people *) v)->arrival - ((people *) w)->arrival;
    }
int comparePeopleMechanic(void *v,void *w){
    return ((people *) v)->mechanic_wait - ((people *) w)->mechanic_wait;
    }
int comparePeopleOil(void *v,void *w){
    return ((people *) v)->mechanic_wait - ((people *) w)->mechanic_wait;
    }

char *getPeopleName(people *v){
    return v->name;
    }

char *setPeopleName(people *v,char *x){
    people *old = malloc(sizeof(people));
    old->name=malloc(sizeof(v->name));
    strcpy(old->name,v->name);
    v->name = malloc(sizeof(strlen(x)));
    strcpy(v->name,x);
    return old->name;
	}

void displayPeopleName(FILE *fp,void *v){
    fprintf(fp,"%s",getPeopleName((people *) v));
	}
void displayPeople(FILE *fp,void *v){
    fprintf(fp,"%s, %d, %d, %d",getPeopleName((people *) v),getPeopleArrival((people *) v),getPeopleMechanic((people *) v),getPeopleOil((people *) v) );
    }

void freePeople(people *v){
    free(v);
	}