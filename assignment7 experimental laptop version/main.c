
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "assignment7.h"

int main() {
	int test;
	char test2[100] = "abba"; //"herrehisaweirdstring";
	scanf("%d", &test);
	generateAllMatchedParens(test);
	//stringReverse(test2);
	//printf("%s", test2);
	generateAllPalindromicDecompositions(test2);
}
