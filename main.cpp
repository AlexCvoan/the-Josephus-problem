#include <stdio.h>
#include <conio.h>
#include <malloc.h>

typedef struct tnod{
	int player_id;
	struct tnod *next;
}TNOD;

TNOD *first, *last;

int josephus(int n);
int clean_stdin();

int main() {
	int n, exit = 1;

	printf("\n \tHello! This program will solve the Josephus Problem. The statement of the problem is:");
	printf("\n \tThere are n people standing in a circle waiting to be executed. The counting out begins"
        "at some point in the circle and proceeds around the circle in a fixed direction. In each step, "
        "the next person alive is executed. The elimination proceeds around the circle (which is becoming "
        "3smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom.)");

	while (exit) {
        n = -1;
		printf("\n\n Introduce the number of persons: ");
		while (n<=0 || n>9999999) {
            scanf(" %d", &n);
			if (n<=0 || n>9999999)	printf("Invalid number. Introduce a number greater than 0 and smaller than 9999999: ");
            clean_stdin();
		}

		printf("\n The man alive is the man number: %d", josephus(n));
		printf("\n\n Do you want to test the problem again? If yes, press Enter. Else, press any other key.\n");
		if (getch() != 13)	exit = 0;
	}
	printf("\n Thanks for trying this application!\n");
}

int josephus(int n) {
	TNOD *p, *q, *current, *previous;
	int i, deleted=0;
	current = p = q = (TNOD*)malloc(sizeof(TNOD));

	p->player_id = 1;
	for (i = 2; i <= n; i++) {
		p->next = (TNOD*)malloc(sizeof(TNOD));
		p = p->next;
		p->player_id = i;
	}
	p->next = q;

    current = q->next;
    previous = q;

    while(n != 1) {
            if (deleted == 1) {
                previous = current;
                current = current->next;
                deleted = 0;
            }
            else {
                previous->next = current->next;
                free(current);
                current = previous->next;
                deleted = 1;
                n--;
            }
        }
	return current->player_id;
	}

int clean_stdin(){
    while (getchar()!='\n');
    return 1;
}
