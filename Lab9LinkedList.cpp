
#include <iostream>
#include "Main.h"
#include "Node.h"
#include "LinkedList.h"

void displayInt(void* i) {
	int* p = (int*)(i);
	int n = *p;
	cout << n << "->";
}
void displayStr(void* i) {
	char* p = (char*)(i);
	cout << p << "->";
}
////from Learn by Doing Chapter 12, slide 105
int compare_ints(void* arg1, void* arg2)
{
	int return_value = 0;

	if (*(int*)arg1 < *(int*)arg2)
		return_value = -1;
	else if (*(int*)arg1 > *(int*)arg2)
		return_value = 1;

	return return_value;
}

int compare_strs(void* arg1, void* arg2)
{
	return (_stricmp(((char*)arg1), ((char*)arg2)));
}

int main()
{
	int num2 = 2;
	int* pnum2 = &num2;
	int num1 = 1;
	int* pnum1 = &num1;
	int num3 = 3;
	int* pnum3 = &num3;
	LinkedList* nums = new LinkedList();
	nums->insert(pnum3, compare_ints);
	nums->insert(pnum1, compare_ints);
	nums->insert(pnum2, compare_ints);
	nums->setDisplay(displayInt);
	nums->display();
	char cat[4] = "cat";
	char dog[4] = "dog";
	char bird[5] = "bird";
	LinkedList* animals = new LinkedList();
	animals->insert(&dog[0], compare_strs);
	animals->insert(&bird[0], compare_strs);
	animals->insert(&cat[0], compare_strs);
	animals->setDisplay(displayStr);
	animals->display();
	cout << "Hello" << endl;
}
