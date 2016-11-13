#include <stdio.h>

int global1 = 0;
int global2 = 0;
char str1[1000] = { 0 };
char* start = str1;
char* thing[1000][1000];
char* plz[100] = { 0 };
int thing_index = 0;
char* original;
char palindrome[1000] = { 0 };
char* pal = palindrome;

void state(int left, int right) {
	char str[1000] = { 0 };
	if (left == right && left>0 && right>0) {
		strcpy(start - left - right, "(");
		state(left - 1, right);
	}
	if (left > 0 && right != left) {
		strcpy(start - left - right, "(");
		state(left - 1, right);
	}
	if (right > 0 && right != left) {
		strcpy(start - left - right, ")");
		state(left, right - 1);
	}
	if (left == 0 && right == 0) {
		strcpy(start - left - right, "\n");
		strcpy(start + 1, "\0");
		printf("%s", str1);
	}
}

void generateAllMatchedParens(int n) {
	global1 = n;
	start = str1 + global1 * 2;
	state(n, n);
	//Function needs to generate all matched parens as described in the assignment
}

void stringReverse(char str[]) {
	char* tempstr = calloc(strlen(str) + 1, sizeof(char));
	int stringlength = strlen(str);
	for (int i = 0; i < strlen(str); i++) {
		//strcpy(tempstr+stringlength-i-1, (char) str[i]);
		tempstr[stringlength - i - 1] = str[i];
	}
	strcpy(str, tempstr);
	free(tempstr);
}

void stringSplit(char str[]) {
	int printcheck = 0;
	if (strlen(str) <= 2) {
		return;
	}
	int len = strlen(str);
	int mid = (len / 2);
	char* front = calloc(len + 1, sizeof(char));
	char* back = calloc(len + 1, sizeof(char));
	if (len % 2 == 0) {
		for (int i = 0; i < mid; i++) {
			front[i] = str[i];
		}
		for (int i = mid; i < len; i++) {
			back[i - mid] = str[i];
		}
	}
	else {
		for (int i = 0; i < mid; i++) {
			front[i] = str[i];
		}
		for (int i = mid + 1; i < len; i++) {
			back[i - mid - 1] = str[i];
		}
	}
	stringReverse(front);
	if (strcmp(front, back) == 0) {
		//for (int i = 0; i < 1000; i++) {
		if (strcmp(plz, str) == 0) printcheck = 1;
		//}
		if (printcheck == 0) {
			strcpy(plz, str);
			printf("%s\n", str);
		}
	}
	stringSplit(front);
	stringSplit(back);
	free(front);
	free(back);
}

int isPalindrome(char str[]) {
	if (strlen(str) <= 1) 
		return 1;
	int len = strlen(str);
	int mid = (len / 2);
	char* front = calloc(len + 1, sizeof(char));
	char* back = calloc(len + 1, sizeof(char));
	if (len % 2 == 0) {
		for (int i = 0; i < mid; i++) {
			front[i] = str[i];
		}
		for (int i = mid; i < len; i++) {
			back[i - mid] = str[i];
		}
	}
	else {
		for (int i = 0; i < mid; i++) {
			front[i] = str[i];
		}
		for (int i = mid + 1; i < len; i++) {
			back[i - mid - 1] = str[i];
		}
	}
	stringReverse(front);
	if (strcmp(front, back) == 0) return 1;
	else return 0;

}


void mengshi(char str[], int position) {
	static int start = 0;
	static int spaces = 0;
	char* temp1 = calloc(strlen(str)+1, sizeof(char));
	char* temp2 = calloc(strlen(str)+1, sizeof(char));
	int index = 1;
	for (int divider = 1; divider <= strlen(str); divider++) {
		for (int i = 0; i < divider; i++) {
			temp1[i] = str[i];
		}
		for (int i = divider; i < strlen(str); i++) {
			temp2[i - divider] = str[i];
		}
		if (isPalindrome(temp1)) {
			strcpy(pal+position, temp1);
			position+=strlen(temp1);
			strcpy(pal + position, "\n");
			position++;
			if (strlen(temp2) == 0) {
				printf("%s", pal);
			}
			free(temp1);
			free(temp2);
			//printf("%s\n", temp1);
			mengshi(temp2, position);
		}
	}
}
void experiment(char str[], int divider) {
	char* copy = calloc(strlen(str) + 1, sizeof(char));
	char* temp = calloc(strlen(str)+1 , sizeof(char));
	char* token = calloc(strlen(str) + 1, sizeof(char));
	strcpy(copy, str);
	if (divider > 0) {
		for (int i = 0; (i+divider)<=strlen(str); i++) {
			for (int j = 0; j < divider; j++) {
				temp[j] = str[i + j];
			}
			if (isPalindrome(temp)) {
				token = strtok(copy, temp);
				while (token != NULL) {
					if (isPalindrome(token)) printf("%s\n", token);
					token = strtok(NULL, temp);
				}
				printf("%s\n", temp);
			}
		}
		experiment(str, divider - 1);
	}
	free(temp);
	free(token);
}


void adjacentPal(char str[]) {
	int len = strlen(str);
	char tempstr[4] = { 0 };
	for (int i = 1; i < len; i++) {
		if (str[i - 1] == str[i + 1]) {
			tempstr[0] = str[i - 1];
			tempstr[1] = str[i];
			tempstr[2] = str[i + 1];
			printf("%s", tempstr);
			i += 2;
		}
	}
}

void generateAllPalindromicDecompositions(char str[]) {
	/*original = calloc(strlen(str) + 1, sizeof(char));
	for (int i = 0; i <= strlen(str); i++) {
		for (int j = 0; j < i; j++) {
			original[j] = str[j];
		}
		stringSplit(original);
	}
	adjacentPal(original);*/
	//experiment(str, strlen(str));
	mengshi(str, 0);
}

