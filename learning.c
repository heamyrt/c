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

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<float.h>
//分配数据机构，列表头，链表大小，当前容量（判断是否扩容）			列表不能为空
#define listsize 100
#define listincrease 10
typedef struct{
	int* elem;
	int length;		//当前长度
	int listsizee;	//总大小，用于与length比较
}sqlist;	//能减少代码的书写速度
void initlist (sqlist *l)		//怎么返回初始化的列表
{	
	l->elem= (int*)malloc(listsize * sizeof(int));
	if (!l->elem) {
		exit(0);
	}
	l->length = 0;
	l->listsizee = listsize;
	return 0;
}
void getelement(sqlist l,int i,int *e) {//提取i代表的e
	*e = l.elem[i];
	printf("%d\n", *e);
}
//遍历所有元素
void bianli(sqlist la,int j) {
	for (int i = 0; i < j;i++) {
		int e;
		getelement(la, i, &e);
	}
}
//对指针额应用还不够明确，分不清指针（地址）与数据
//将数组填满，用random，for循环
void airele(sqlist* l,int j) {
	for (int i = 0; i < j; i++) {
		int e = rand();
		l->elem[i] = e;
		l->length = l->length + 1;
	}
}
//重新分配空间
void relist(sqlist* l) {
	int* newbase;
	newbase = (int*)realloc(l->elem,(l->listsizee + listincrease) * sizeof(int));
	if (!newbase) {
		l->elem = newbase;
		l->listsizee = l->listsizee + listincrease;
	}
}

//算法2.4，填进元素,尾插入元素；头插入元素，把后几位元素向后复制，在将原值赋予
void addelemt(sqlist* l, int i,int e) {
	if (l->length + 1 > l->listsizee) {
		relist(&l);
	}
	for (int j = l->length-1; j > i - 1; j--) {
		l->elem[j + 1] = l->elem[j];
	}
	l->elem[i] = e;
	l->length = l->length + 1;
}
//删除第i个元素，同插入元素，维持列表完整性；删除最后一个元素时，不变
void del(sqlist *l,int j){
	for (int i = j - 1; i < l->length; i++) {
		l->elem[i] = l->elem[i + 1];
	}
	l->length = l->length - 1;
}
//返回列表e的列序号
int mergetlist(sqlist l, int e) {
	//int* p = l.elem[l.length - 1]; 循环脱离的条件是i与l.length的判断
	int* q = l.elem;
	int i = 1;
	while (i<l.length&&!compare(e,*q++))
	{
		i++;
	}
	if (i < l.length) {
		return i;
	}
}
int compare(int e,int m) {
	if (e == m) {
		return 1;
	}
	return 0;
}
//顺序表合并，L1,L2从大到小排序，lc为新的列表，将1，2元素进行比较，将较小元素插入
void merlsit(sqlist l, sqlist m, sqlist* lc) {
	lc->listsizee = l.length + m.length;
	lc->elem = (int*)malloc(m.listsizee * sizeof(int));
	int* p = l.elem, * q = m.elem, * l_last = p + l.length - 1, * m_last = q + m.length - 1;//四个指针，判断条件，数据调用
	int* qc = lc->elem;
	while (p < l_last && q < m_last) {
		if (*p < *q) {
			*qc = *p;
			p++;
			qc++;
		}
		else {
			*qc = *q;
			p++;
			q++;
		}
	}
}
int main() {
	sqlist l;
	initlist(&l);
	airele(&l,10);
}
 
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<float.h>
//数组实现链表
#define maxsize 100
typedef struct {
	int data;
	int cur;
}compare, slinklist[maxsize];			//结构体名字,两个数组元素构成元素，重新分配地址指针（数组中的位序）
void initit(slinklist s) {
	for (int i = 0; i < maxsize; i++) {
		s[i].cur = i + 1;
	}
	s[maxsize - 1].cur = 0;				//slinklist是建立100个元素（compare）的数组，对数组进行排序
}
int malloc_sl(slinklist s) {			//如malloc一般，提供下一个数据结构的地址
	int k = s[0].cur;
	s[0].cur = s[k].cur;				//取得头个元素的标记，将头元素弹出
	return k;
}
void free(slinklist l,int k) {
	l[k].cur = l[0].cur;
	l[0].cur = k;
}
void bianli(slinklist l,int k) {
	while (l[k].cur) {
		k = l[k].cur;
		printf("%d\n", l[k].data);
	}
}
int main() {
	slinklist l;
	initit(l);
	int k;
	//compare m;					//直接从备用列表中弹出
	//  m.cur = 0;
	k = malloc_sl(l);				//链表头
	l[k].cur = 0;
	int r = k;
	for (int i = 0; i < 10; i++) {
		i = malloc_sl(l);
		l[i].data = rand();
		l[i].cur = l[r].cur;
		l[r].cur = i;
	}
	bianli(l, k);
}
//栈
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<float.h>
#define maxsize 100
#define onesize 10
//顺序站的定义
typedef struct {
	int* base;
	int* top;
	int  sqstacksize;
}sqstack;
void initsqstack(sqstack* l) {
	int* k = (int*)malloc(maxsize * sizeof(int));
	l->base = k;
	l->top = k;
	l->sqstacksize = maxsize;
}
int push(sqstack* l,int e) {
	if (l->top==l->base+l->sqstacksize)
	{
		int *k = (int*)malloc((maxsize + onesize) * sizeof(int));
		if(!k){
			return 0;
		}
		l->base = k;
		l->sqstacksize = l->base + onesize;
	}
//  (l->top) = e;				//不知道调用的是指针的地址，还是指针所指的元素
	* l->top = e;
	l->top = l->top + 1;
}
int pop(sqstack* l, int *e) {
	if (l->base == l->top) {
		return 0;
	}
	*e = *(l->top - 1);
	l->top = l->top - 1;
	printf("%d", *e);
}
void main() {
	sqstack l;
	int s;
	initsqstack(&l);
	push(&l, 6);
	pop(&l, &s);
}
