#include <stdio.h>
#include <stdstring.h>

int main(int argc, char *argv){
	if (argc==1){
		printf("Usage: %s word\n", argv[0]);
		return 1;
	}
	else if (isLegalword(argv[1]==1)){
		printf("%s is a legal word.\n", argv[1] );
}
	else{
		printf("%s is not a legal word.\n", argv[1]);
	}
	return 0;
}	



int isLegalword(char word[])
{
	if(strchr(word, 'a')!=NULL) return 1;
	if(strchr(word, 'e')!=NULL) return 1;
	if(strchr(word, 'i')!=NULL) return 1;
	if(strchr(word, 'o')!=NULL) return 1;
	if(strchr(word, 'u')!=NULL) return 1;
	return 0;
}
