#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<float.h>
int getrandvalue(void) {
	return rand();
}
int populate(int* array, int arrsize, int (*getvalue)(void)) {
	for (int i = 0; i < arrsize;i++){
		array[i] = getvalue();
	}
}
int main() {
	int arr[10];
	populate(arr, 10, getrandvalue);
	for (int i = 0; i < 5; i++) {
		printf("%d \n",arr[i]);
	}
}
//返回函数的调用
