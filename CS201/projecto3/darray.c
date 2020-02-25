#include "darray.h"
#include "integer.h"

struct DArray{
	void **array; //an array of void pointers
	int capacity; //total number of slots
	int size; //number of filled slots
	void (*display)(FILE *,void *);
};

DArray *newDArray(void (*display)(FILE *,void *)){
	DArray *a=malloc(sizeof(DArray));
	//a->array=NULL;
	a->array=malloc(sizeof(void *)* 1);
	a->capacity=1;
	a->size=0;
	a->display=display;
	a->array[0]=NULL;
	return a;
}
void insertDArray(DArray *a,void *v){
	if(a->size==a->capacity){
		a->capacity*=2;
		a->array=realloc(a->array,sizeof(void *) * a->capacity);
		//a->size++;
	}
	
	a->array[a->size++]= v;
}
//STRICTLY LESS THAN 25% not == :D
void *removeDArray(DArray *a){
	if(a->size==0){
		exit(-1);
	}
	void *v=a->array[a->size-1];
	a->array[a->size-1]=NULL;
	a->size--;
	if(a->size < ((double)a->capacity/4.0) && a->capacity!=1){
		a->capacity/=2;
		a->array=realloc(a->array,sizeof(void *) * a->capacity);
	}
	return v;
}
void *getDArray(DArray *a,int index){
	return a->array[index];
}
void setDArray(DArray *a,int index,void *value){
	if(index==a->size){
		insertDArray(a,value);
	}
	else if(index<a->size){
		a->array[index]=value;
	}
}//The setDArray method should call insertDArray if the index to be set is the size.
//If it is less than the size, the method should just replace the current value. 
int sizeDArray(DArray *a){
	return a->size;
}
void displayDArray(FILE *fp,DArray *a){
	if(sizeDArray(a)==0){
		fprintf(fp,"[");
		fprintf(fp, "][%d]",((a->capacity) - (a->size) ));
		return;
	}
	else{
		int num=sizeDArray(a);
		fprintf(fp,"[");
		for(int i=0;i<num;i++){
			a->display(fp,a->array[i]);
			if(i+1<num){
				fprintf(fp, ",");
			}
		}
		fprintf(fp, "][%d]",((a->capacity) - (a->size) ));
	}
}