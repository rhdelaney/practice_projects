#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

if (strcmp(argv[1],argv[2]) == 0) {
	printf("It's a tie!\n");
	return 0;
}

//player1 rock
if (strcmp(argv[1],"rock") == 0) {
	if (strcmp(argv[2],"paper") == 0) {
		printf("Player 2 wins!\n");
		return 0;
	}
	if (strcmp(argv[2],"spock") == 0) {
		printf("Player 2 wins!\n");
		return 0;
	}
	if (strcmp(argv[2],"scissors") == 0) {
		printf("Player 1 wins!\n");
		return 0;
	}
	if (strcmp(argv[2],"lizard") == 0) {
		printf("Player 1 wins!\n");
		return 0;
	}
}
//player1 paper
if (strcmp(argv[1],"paper") == 0) {
	if (strcmp(argv[2],"rock") == 0) {
		printf("Player 1 wins!\n");
		return 0;
	}
	if (strcmp(argv[2],"scissors") == 0) {
		printf("Player 2 wins!\n");
		return 0;
	}
	if (strcmp(argv[2], "lizard") == 0) {
		printf("Player 2 wins!\n");
		return 0;
	}
	if (strcmp(argv[2], "spock") == 0) {
		printf("Player 1 wins!\n");
		return 0;
	}
}
//player1 scissors
if (strcmp(argv[1],"scissors") == 0) {
	if (strcmp(argv[2],"rock") == 0) {
		printf("Player 2 wins!\n");
		return 0;
	}
	if (strcmp(argv[2],"paper") == 0){
		printf("Player 1 wins!\n");
		return 0;
	}
	if (strcmp(argv[2],"lizard") == 0){
		printf("Player 1 wins!\n");
		return 0;
	}
	if (strcmp(argv[2],"spock") == 0) {
		printf("Player 2 wins!\n");
		return 0;
	}
}
//player1 lizard
if (strcmp(argv[1],"lizard") == 0) {
	if (strcmp(argv[2], "rock") == 0) {
		printf("Player 2 wins!\n");
		return 0;
	}
	if (strcmp(argv[2], "paper") == 0) {
		printf("Player 1 wins!\n");
		return 0;
	}
	if (strcmp(argv[2], "scissors") == 0) {
		printf("Player 2 wins!\n");
		return 0;
	}
	if (strcmp(argv[2], "spock") == 0) {
		printf("Player 1 wins!\n");
		return 0;
	}
}
//player1 spock
if (strcmp(argv[1],"spock") == 0) {
	if (strcmp(argv[2],"rock") == 0) {
		printf("Player 1 wins!\n");
		return 0;
	}
	if (strcmp(argv[2], "paper") == 0) {
		printf("Player 2 wins!\n");
		return 0;
	}
	if (strcmp(argv[2], "scissors") == 0) {
		printf("Player 1 wins!\n");
		return 0;
	}
	if (strcmp(argv[2], "lizard") == 0) {
		printf("Player 2 wins!\n");
		return 0;
	}
}
	return 0;
}
