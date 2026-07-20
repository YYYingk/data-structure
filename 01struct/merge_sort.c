#include "merge_sort.h"
#include<stdio.h>
#include<stdlib.h>

// merge合并过程
static void merge(SortTable* table, int left, int mid, int right) {
    int n1 = mid - left + 1;        // 左边区间的个数
    int n2 = right - mid;           // 右边区间的个数
    // 分配aux1和aux2，将已经有序的左区间和已经有序的右区间 初始化临时区域
    Element* aux1 = malloc(sizeof(Element) * n1);
    if (aux1 == NULL) {
        return;
    }
    Element* aux2 = malloc(sizeof(Element) * n2);
    if (aux2 == NULL) {
        free(aux1);
        return;
    }
    for (int i = 0; i < n1; i++) {// 左
        aux1[i] = table->data[left + i];
    }
    for (int i = 0; i < n2; ++i) {// 右
        aux2[i] = table->data[mid + 1 + i];
    }
    // 将临时的有序空间aux1和aux2进行归并
    int i = 0;          // 标记aux1区间待查找的位置
    int j = 0;          // 标记aux2区间待查找的位置
    int k = left;       // 标记原空间存放结果的区域位置
    while (i < n1 && j < n2) {
        if (aux1[i].key <= aux2[j].key) {
            table->data[k] = aux1[i];
            ++i;
        }   
        else if (aux1[i].key > aux2[j].key) {
            table->data[k] = aux2[j];
            ++j;
        }
        k++;
    }
    // 判断究竟是aux1还是aux2区域遍历结束
    while (i < n1) {
        table->data[k++] = aux1[i++];
    }
    while (j < n2) {
        table->data[k++] = aux2[j++];
    }
    free(aux1);
    free(aux2);
}

// 递归的分解table[left, right]区间
static void merge_loop(SortTable* table, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    merge_loop(table, left, mid);
    merge_loop(table, mid + 1, right);
    // 左右区间拆分结束，合并两个子区间
    merge(table, left, mid, right);
}

/* 归并排序：从上往下，从下往上两个过程
 * 从上往下的过程：
 *  a. 分解 -- 将当前区间一分为二
 *  b. 求解 -- 递归对两个子区间a[low...mid] 和 a[mid+1...high]进行归并排序
 */
void mergeSort(SortTable* table) {
    merge_loop(table, 0, table->length - 1);
}