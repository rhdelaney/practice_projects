#include <stdio.h>
#include <string.h>

int palin(char *);
int count(char *, char);

int main(int argc, char *argv[]) {
    int i;

    if (argc<3) {
        fprintf(stderr, "Usage: %s char word_1 ... word_n\n", argv[0]);
        return 1;
    }

    printf("Checking palindrome:\n");
    for (i=2; i<argc; i++) { 
        printf("\t\"%s\" - %d\n", argv[i], palin(argv[i]));
    }

    printf("\nCounting occurences:\n");
    for (i=2; i<argc; i++) { 
        printf("\t\"%s\" contains '%c' %d times\n", argv[i], argv[1][0],
                    count(argv[i], argv[1][0]));
    }

    return 0;
}

int palin(char *str){
	int len=0;
	len=strlen(str);
	int a, b;
	for(a=0;a<len;a++){
	for(b=len-1;b>=0;b--){
		if(strcmp(&str[a],&str[b])==1){
		return 0;}
		}
}
	return 1;
}
int count(char *string, char letter){
	int len=0;
	len=strlen(string);
	int i;
	int count=0;
	for(i=0;i<len;i++){
	if(letter==string[i]){
	count++;}
}
	return count;
}
