#include<iostream>
#include"HeapSort.h"
using namespace std;

void Diy_printf(int arr[], int size_arr)
{
	for (int i = 0; i < size_arr; i++)
	{
		cout << arr[i];
	}
	cout << endl;
	return;
}
void Swap(int& left, int& right)
{
	if (left == right)
	{
		return;
	}
	left ^= right;
	right ^= left;
	left ^= right;
	return;
}
void Heappos(int tree[], int n, int i)
{
	if (i >= n)
	{
		return;
	}
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int max = i;
	if (left < n && tree[left] > tree[max])
	{
		max = left;
	}
	if (right < n && tree[right] > tree[max])
	{
		max = right;
	}
	if (max != i)
	{
		Swap(tree[i], tree[max]);
		Heappos(tree, n, max);
	}
}
void CreatHeap(int tree[], int n)
{
	int last_pos = n - 1;
	int pos = (last_pos - 1) / 2;
	for (int i = pos; i >= 0; i--)
	{
		Heappos(tree, n, i);
	}
}
void HeapSort(int tree[], int n)
{
	CreatHeap(tree, n);
	for (int i = n - 1; i >= 0; i--)
	{
		Swap(tree[i], tree[0]);
		Heappos(tree, i, 0);
	}
	return;
}
int main()
{
	//int arr[] = { 9,8,7,6,5,4,3,2,1 };
	//int arr[] = { 9,5,6,3,2,1,4,7,8 };
	//int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int arr[] = { 1,1,3,4,5,6,6,7,7,1 };
	int size_arr = sizeof(arr) / sizeof(arr[0]);
	Diy_printf(arr, size_arr);
	HeapSort(arr, size_arr);
	Diy_printf(arr, size_arr);
	system("pause");
	return 0;
}