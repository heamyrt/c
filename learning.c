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
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<float.h>
//算法1		对a进行操作，对a插入b的元素，	提取a的元素，提取b的元素，判断a==b,是就删除，在所有循环判断a！=b，将给a加1（需要构建一个新的列表）	
int unin(int *a,int*b) {
	int e;//提取元素
	for (int i = 0; i < 5; i++) {
		e = b[i];
		for (int j = 0; j < 10; j++) {
			int m = a[j];
			if (m == e) {
				a[j] = 9;
				break;
			}
			if (j == 9) {
				static int k = 1;
				a[5+k] = e;
				k++;
			}
		}
	}
	return 0;
}
int main() {
	int a[10] = { 1,5,6,2,4, };
	int b[5] = { 1,6,5,4,11 };
	int e;
	unin(a, b);
	for (int j = 0; j < 10; j++) {
		e = a[j];
		printf("%d\n", e);
		}

}
//break跳出全部循环
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<float.h>
int main() {
	int a[10] = { 1,5,6,2,4, };
	int e;
	for (int j = 0; j < 10; j++) {
		e = a[j];
		if (e == 6) {
			break;
		}
		printf("%d\n", e);
		}

}
//运行结果1，5
