#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

int len(char str[]);
void randStr(char str[], char perm[]);
void anagram(int nmbr);
void caesar_encrypt(int nmbr);
void caesar_decrypt(int nmbr);
void word_game(int nmbr);
int substr(char x[], char y[]);
int strcomp(char a[], char b[]);
void strcopy(char p[], char q[]);




//Anagram
int score=0;
int success=0;
char arr0[]="listen";
char arr1[]="earth";
char arr2[]="binary";
int c0=1, c1=1, c2=1;

//Caesar Cipher
char phr0[]="there is a secret code";
char phr1[]="attack at dawn";
char phr2[]="meet me at the park";
int d=1;

//Word guessing game
char wrd0[]="program";
char wrd1[]="network";
char wrd2[]="science";

int len(char str[]) {
	int n=0;
	for (int i = 0; str[i]!='\0'; i++)
		n++;
	return n;
}

void strcopy(char p[], char q[]){
    for(int i=0; i<len(q); i++)
        p[i]=q[i];
    
    p[len(q)]='\0';
}

void randStr(char str[], char perm[]) {
	//srand(time(NULL));
	for(int i=0; i<len(str); i++) {
		perm[i]=str[i];
	}
	perm[len(str)] = '\0';
	for(int i=0; i<len(perm); i++) {

		int t = rand() % len(perm);
		char tmp = perm[i];
		perm[i]=perm[t];
		perm[t]=tmp;
	}
}

void anagram(int nmbr) {
	char t[10];
	char perm[10];
	printf("\nStarting Anagram Challenge...\n");
	switch(nmbr) {
	case 0:
		randStr(arr0, perm);

		printf("Scrambled word: %s\n",perm);
		for(int j=0; j<3; j++) {
			printf("Your guess: ");
			scanf(" %[^\n]s", t);
			if(len(arr0)!=len(t)) {
				printf("Incorrect! ");
				if(c0<3) printf("Try again.\n");
				c0++;
			}
			else {
				int i;
				for (i = 0; i < len(arr0); i++)
				{
					if(t[i]!=arr0[i]) {

						printf("Incorrect! ");
						if(c0<3) printf("Try again.\n");
						c0++;
						break;
					}
				}
				if(i==len(arr0) && c0<4) {
					printf("Correct! You solved it in %d attempt(s).\n", c0);
					success++;
					score=score+ (3-c0)*10 + 10;
					break;
				}
			}
		}
		if(c0==4) printf("Correct answer: %s\n", arr0);
		break;
	case 1:
		randStr(arr1, perm);

		printf("Scrambled word: %s\n",perm);
		for(int j=0; j<3; j++) {
			printf("Your guess: ");
			scanf(" %[^\n]s", t);
			if(len(arr1)!=len(t)) {
				printf("Incorrect! ");
				if(c1<3) printf("Try again.\n");
				c1++;
			}
			else {
				int i;
				for (i = 0; i < len(arr1); i++)
				{
					if(t[i]!=arr1[i]) {

						printf("Incorrect! ");
						if(c1<3) printf("Try again.\n");
						c1++;
						break;
					}
				}
				if(i==len(arr1) && c1<4) {
					printf("Correct! You solved it in %d attempt(s).\n", c1);
					success++;
					score=score+ (3-c1)*10 + 10;
					break;
				}
			}
		}
		if(c1==4) printf("Correct answer: %s\n", arr1);
		break;
	case 2:
		randStr(arr2, perm);

		printf("Scrambled word: %s\n",perm);
		for(int j=0; j<3; j++) {
			printf("Your guess: ");
			scanf(" %[^\n]s", t);
			if(len(arr2)!=len(t)) {
				printf("Incorrect! ");
				if(c2<3) printf("Try again.\n");
				c2++;
			}
			else {
				int i;
				for (i = 0; i < len(arr2); i++)
				{
					if(t[i]!=arr2[i] && c2<4) {

						printf("Incorrect! ");
						if(c2<3) printf("Try again.\n");
						c2++;
						break;
					}
				}
				if(i==len(arr2) && c2<4) {
					printf("Correct! You solved it in %d attempt(s).\n", c2);
					success++;
					score=score+ (3-c2)*10 + 10;
					break;
				}
			}
		}
		if(c2==4) printf("Correct answer: %s\n", arr2);
		break;
	}
}

void caesar_encrypt(int nmbr) {
	printf("\nStarting Caesar Cipher Challenge... \n");
	int shift=3;
	char cc[50];
	char tt[50];

	switch (nmbr)
	{
	case 0:
		for(int i=0; phr0[i]!='\0'; i++) {
			if (isupper(phr0[i])) {
				cc[i] = (phr0[i] - 'A' + shift) % 26 + 'A';
			}

			else if (islower(phr0[i])) {
				cc[i] = (phr0[i] - 'a' + shift) % 26 + 'a';
			}
			else
				cc[i] = phr0[i];

		}
		cc[len(phr0)]='\0';

		printf("Encrypted phrase: %s\n",cc);
		for(int j=0; j<3; j++) {
			printf("Your Guess: ");
			scanf(" %[^\n]s",tt);
			if(len(phr0)!=len(tt)) {
				printf("Incorrect! ");
				if(d<3) printf("Try again.\n");
				d++;
			}
			else {
				int i;
				for(i=0; i<len(phr0); i++) {
					if(phr0[i]!=tt[i]) {
						printf("Incorrect! ");
						if(d<3) printf("Try again.\n");
						d++;
					}

				}
				if(i==len(phr0) && d<4) {
					printf("Correct! You decrypted it in %d attempt(s).\n",d);
					success++;
					score=score+ (3-d)*10 + 10;
					break;
				}
			}
		}
		if(d==4) {
			printf("Correct phrase: %s", phr0);
		}
		break;

	case 1:
		for(int i=0; phr1[i]!='\0'; i++) {
			if (isupper(phr1[i])) {
				cc[i] = (phr1[i] - 'A' + shift) % 26 + 'A';
			}

			else if (islower(phr1[i])) {
				cc[i] = (phr1[i] - 'a' + shift) % 26 + 'a';
			}
			else
				cc[i] = phr1[i];

		}
		cc[len(phr1)]='\0';

		printf("Encrypted phrase: %s\n",cc);
		for(int j=0; j<3; j++) {
			printf("Your Guess: ");
			scanf(" %[^\n]s",tt);
			if(len(phr1)!=len(tt)) {
				printf("Incorrect! ");
				if(d<3) printf("Try again.\n");
				d++;
			}
			else {
				int i;
				for(i=0; i<len(phr1); i++) {
					if(phr1[i]!=tt[i]) {
						printf("Incorrect! ");
						if(d<3) printf("Try again.\n");
						d++;
					}

				}
				if(i==len(phr1) && d<4) {
					printf("Correct! You decrypted it in %d attempt(s).\n",d);
					success++;
					score=score+ (3-d)*10 + 10;
					break;
				}
			}
		}
		if(d==4) {
			printf("Correct phrase: %s", phr1);
		}
		break;

	case 2:
		for(int i=0; phr2[i]!='\0'; i++) {
			if (isupper(phr2[i])) {
				cc[i] = (phr2[i] - 'A' + shift) % 26 + 'A';
			}

			else if (islower(phr2[i])) {
				cc[i] = (phr2[i] - 'a' + shift) % 26 + 'a';
			}
			else
				cc[i] = phr2[i];

		}
		cc[len(phr2)]='\0';

		printf("Encrypted phrase: %s\n",cc);
		for(int j=0; j<3; j++) {
			printf("Your Guess: ");
			scanf(" %[^\n]s",tt);
			if(len(phr2)!=len(tt)) {
				printf("Incorrect! ");
				if(d<3) printf("Try again.\n");
				d++;
			}
			else {
				int i;
				for(i=0; i<len(phr2); i++) {
					if(phr2[i]!=tt[i]) {
						printf("Incorrect! ");
						if(d<3) printf("Try again.\n");
						d++;
					}

				}
				if(i==len(phr2) && d<4) {
					printf("Correct! You decrypted it in %d attempt(s).\n",d);
					success++;
					score=score+ (3-d)*10 + 10;
					break;
				}
			}
		}
		if(d==4) {
			printf("Correct phrase: %s", phr2);
		}
		break;

	}

}

void caesar_decrypt(int nmbr) {
	char phr[100];
	int shift;
	
	printf("enter encrypted phrase: ");
	scanf("%[^\n]s",phr);
	printf("enter shift: ");
	scanf("%d", &shift);

	for (int i = 0; phr[i] != '\0'; i++) {
		if (isupper(phr[i])) {
			phr[i] = (phr[i] - 'A' - shift + 26) % 26 + 'A';
		}

		else if (islower(phr[i])) {
			phr[i] = (phr[i] - 'a' - shift + 26) % 26 + 'a';
		}
	}

	printf("Decrypted Phrase: %s", phr);

}

void word_game(int nmbr) {
	printf("\nStarting word guessing challenge...\n");
	char word[20];
	int opt;
	int atmp=1;
	int ut_fnc1=0;
	int ut_fnc2=0;
	switch (nmbr)
	{
	case 0:
		for (int i = 0; i < len(wrd0); i++)
		{
			word[i]=wrd0[i];
		}
		word[len(wrd0)]='\0';
		break;

	case 1:
		for (int i = 0; i < len(wrd1); i++)
		{
			word[i]=wrd1[i];
		}
		word[len(wrd1)]='\0';
		break;
	case 2:
		for (int i = 0; i < len(wrd2); i++)
		{
			word[i]=wrd2[i];
		}
		word[len(wrd2)]='\0';
		break;
	}
	printf("Hint: ");
	for (int i = 0; i < 3; i++)
		printf("%c",word[i]);

	printf("___\n");
	for(int k=0; (k<5 && atmp<4); k++) {
		printf("Select an option: 1. Write answer  2. Check substring  3. Check length\n");
		scanf("%d", &opt);
		char guess[20];
		switch (opt)
		{
		case 1:
			
			printf("Enter your guess: ");
			scanf(" %[^\n]s", guess);
			int is_eq = strcomp(word, guess);
			if(is_eq && atmp<4) {
				printf("Correct! You guessed it in %d attempt(s) using %d utility functions.\n", atmp, ut_fnc1+ut_fnc2);
				success++;
				score=score + (3-atmp)*10 + 10 - 2*ut_fnc1 - 2*ut_fnc2;
				atmp=4;
				break;
			}
			else {
				printf("wrong guess\n");
				atmp++;
				if(atmp==4) printf("Correct word: %s\n", word);
			}
			break;

		case 2:
			if(ut_fnc1<1) {
				ut_fnc1++;
				char subs[20];
				printf("Enter substring: ");
				scanf(" %[^\n]s", subs);
				int is_substr=substr(word, subs);
				if(is_substr) printf("Yes\n");
				else printf("No\n");
			}
			else {
				printf("Utility function already used.\n");
			}
			break;

		case 3:
			if(ut_fnc2<1) {
				ut_fnc2++;
				int length;
				printf("enter length: ");
				scanf("%d", &length);
				if(length==len(word)) printf("Yes\n");
				else printf("No\n");
			}
			else {
				printf("Utility function already used.\n");
			}
			break;
		default:
			printf("You have entered invalid option\n");
			break;
		}
	}


}

int strcomp(char a[], char b[]) {
	if(len(a)!=len(b))
		return 0;
	else {
		int i;
		for(i=0; i<len(a); i++) {
			if(a[i]!=b[i]) return 0;
		}
		return 1;
	}
}

int substr(char x[], char y[]) {
	int i, n=len(x), m=len(y), j;
	for(i=0; i<(n-m); i++) {
		for(j=0; j<m; j++) {
			if(x[i+j]!=y[j])
				break;
		}
		if(j==m)
			return 1;
	}
	return 0;
}
int main() {
	int choice;
	printf("Welcome to the Game World!\n1. Start Game\n2. Exit\nEnter your choice: ");
	scanf("%d", &choice);
	if(choice==1) {
		srand(time(NULL));
		int nmbr=rand()%3;

		anagram(nmbr);
		caesar_encrypt(nmbr);
		word_game(nmbr);

		printf("Game Over!\n");
		if(success==3) score+=5;
		printf("\nScore: %d\n", score);
	}

	else

		return 0;
}