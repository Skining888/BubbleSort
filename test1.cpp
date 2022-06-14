#include<stdio.h>

void Diy_printf(int arr[], int size_arr)
{
	for (int i = 0; i < size_arr; i++)
	{
		cout << arr[i];
	}
	cout << endl;
	return;
}

int main()
{
	//int arr[] = { 9,8,7,6,5,4,3,2,1 };
	//int arr[] = { 9,5,6,3,2,1,4,7,8 };
	//int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int arr[] = { 1,1,3,4,5,6,6,7,7,1 };
	int a = 600;
	int b = 180;
	printf("test3 a + b = %d\n",a+b);
	return 0;
}

