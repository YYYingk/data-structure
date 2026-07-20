#include "KMP.h"
#include<stdio.h>
#include<stdlib.h>

int strAssign(StrType* str, const char* ch)
{
	if (str->str) {		// str已经指向了数据，释放后重新再通过ch赋值
		free(str->str);
	}
	// 求ch的长度
	int len = 0;
	while (ch[len]) {
		len++;
	}
	if (len == 0) {
		str->str = NULL;
		str->len = 0;
	}
	else {
		str->str = malloc(sizeof(char) * (len + 2));	// 把0号位置空出来，把\0也放入空间内
		for (int i = 0; i <= len; i++) {	// 包含了ch指向空间的\0位置
			str->str[i + 1] = ch[i];
		}
		str->len = len;
	}
	return 1;
}

// 暴力匹配
int index_simple(const StrType* str, const StrType* substr) {
	int i = 1;
	int j = 1;
	int k = i;		// 记录假设值
	while (i <= str->len && j <= substr->len) {
		if (str->str[i] == substr->str[j]) {
			++i;
			++j;
		}
		else {
			++k;
			j = 1;
			i = k;
		}
	}
	if (j > substr->len) {
		return k;
	}
	else {
		return 0;
	}
}

void getNext(const StrType* substr, int next[]) {
	int i = 1, j = 0;
	next[1] = 0;
	while (i < substr->len) {
		if (j == 0 || substr->str[i] == substr->str[j]) {
			++i;
			++j;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
}

int indexKMP(const StrType* str, const StrType* substr, const int* next)
{
	int i = 1;
	int j = 1;
	while (i <= str->len && j <= substr->len) {
		if (j == 0 || str->str[i] == substr->str[j]) {
			++i;
			++j;
		}
		else {
			j = next[j];
		}
	}
	if (j > substr->len) {
		return i - substr->len;	// 减去最后到开头
	}
	else {
		return 0;
	}
}
