
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void inputArr(int*, int);
void printArray(int*, int);
void split(int*, int, int**, int*, int** , int* );

void main()
{
	int* arr=NULL, size = 0;
	printf("enter the length of the array ");
	scanf("%d", &size);
	arr = malloc(NULL, size * sizeof(int));
	if (arr == NULL) {
		printf("allocation fail");
		exit(1);
	}
	inputArr(arr, size);
	printArray(arr, size);
	int* neg = NULL, negSize = 0, * pos = NULL, posSize = 0;
	split(arr,size, &neg, &negSize, &pos, &posSize);
	printf("negative array: ");
	printArray(neg, negSize);
	printf("positive array: ");
	printArray(pos, posSize);
	free(arr);
	free(neg);
	free(pos);
}

void inputArr(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		printf("enter number ");
		scanf("%d",arr+i);
	}
}
void printArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d, ", *(arr + i));
	}
	printf("\n");
}
void split(int* arr, int n, int** pNeg, int* pNegSize, int** pPos, int* pPosSize){
	int* neg = NULL, * pos = NULL;
	for (int i = 0;i < n; i++) {
		int num = *(arr + i);
		printf("%d, ", num);
		if (num < 0) {
			(*pNegSize)++;
			*neg = (int*)realloc(*neg, *pNegSize  * sizeof(int));
			if (*pNeg == NULL) {
				printf("Allocation fail");
				exit(1);
			}
			*(neg + *pNegSize) = num;
		}
		else {
			(*pPosSize)++;
			*pos = (int*)realloc(*pos, *pPosSize  * sizeof(int));
			if (*pos == NULL) {
				printf("Allocation fail");
				exit(1);
			}
			*(pPos + *pPosSize) = num;
		}
	}
	//for (int i = 0;i < n; i++) {
	//	int num = *(arr + i);
	//	printf("%d, ", num);
	//	if (num < 0) {
	//		(*pNegSize)++;
	//		*pNeg = (int*)realloc(*pNeg, *pNegSize * sizeof(int));
	//		if (*pNeg == NULL) {
	//			printf("Allocation fail");
	//			exit(1);
	//		}
	//		//*(pNeg + *pNegSize) = num;
	//		(*pNeg)[*pNegSize - 1] = num;
	//	}
	//	else {
	//		(*pPosSize)++;
	//		*pPos = (int*)realloc(*pPos, *pPosSize * sizeof(int));
	//		if (*pPos == NULL) {
	//			printf("Allocation fail");
	//			exit(1);
	//		}
	//		//*(pPos + *pPosSize) = num;
	//		(*pNeg)[*pNegSize - 1] = num;
	//	}
	//}
}

