#include"KMP.h"
#include<stdio.h>
#include<stdlib.h>

void test01(StrType* str, StrType* substr) {
	int res = index_simple(str, substr);
	printf("simple find index: %d", res);
}

void test02(StrType* str, StrType* pattern) {
	int* next = malloc(sizeof(int) * (pattern->len + 1));
	getNext(pattern, next);
	printf("%d\n", indexKMP(str, pattern, next));
	free(next);
}

int main() {
	StrType str;
	StrType substr;
	str.str = NULL;
	substr.str = NULL;
	strAssign(&str, "ABCDABCABCABABCABCDA");
	strAssign(&substr, "ABCABCD");

	test02(&str, &substr);
	return 0;
}