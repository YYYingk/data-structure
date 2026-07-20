#pragma once
typedef struct {
	char* str;
	int len;
} StrType;

int strAssign(StrType* str, const char* ch);
void realeaseStr();

void getNext(const StrType* substr, int next[]);
int index_simple(const StrType* str, const StrType* substr);
int indexKMP(const StrType* str, const StrType* substr, const int* next);