#include<iostream>
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

void Merge(int arr[], int temp_arr[], int mid, int left, int right)
{
	int l = left;
	int r = mid + 1;
	int pos = left;
	while (l <= mid && r <= right)
	{
		if (arr[l] < arr[r])
		{
			temp_arr[pos++] = arr[l++];
		}
		else
		{
			temp_arr[pos++] = arr[r++];
		}
	}
	//右序列遍历完毕，左序列还有剩余，直接将剩余元素放在临时数组后面
	while (l <= mid)
	{
		temp_arr[pos++] = arr[l++];
	}
	//左序列遍历完毕，右序列还有剩余，直接将剩余元素放在临时数组后面
	while (r <= right)
	{
		temp_arr[pos++] = arr[r++];
	}

	//将排好序的临时存放数组的值复制到原数组中
	while (left <= right)
	{
		arr[left] = temp_arr[left];
		left++;
	}
	return;
}

void Split(int arr[], int temp_arr[], int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) / 2;
	Split(arr, temp_arr, left, mid);
	Split(arr, temp_arr, mid + 1, right);
	Merge(arr, temp_arr, mid, left, right);
	return;
}

void MergeSort(int arr[], int left, int right)
{
	int* temp_arr = new int[right + 1];
	if (temp_arr)
	{
		Split(arr, temp_arr, left, right);
	}
	else
	{
		cout << "temp_arr == NULL,application memory faild" << endl;
	}
	delete[]temp_arr;
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
	MergeSort(arr, 0, size_arr - 1);
	Diy_printf(arr, size_arr);
	system("pause");
	return 0;
}