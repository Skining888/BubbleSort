#pragma once

//函数说明：左右边界扫描交换一次，将比key小的放在key的左边，比key大的放在右边
//入参：arr[]数组地址，left和right为要扫描的序列的左右边界
//出参：无
void OnceFastSort(int arr[], int& left, int& right);

//函数说明：递归遍历每一个左右序列，将数组元素排序
//入参：arr[]数组地址，left和right为要扫描的序列的左右边界
//出参：无
void FastSort(int arr[], int left, int right);


//快速排序总结
//中心思想：找出一个key值，从左右边界开始比较，将小于key的放在左边，大于key的放在右边，key值将原数组分为左右两个序列，递归遍历下去。直到每一个序列都只剩一个数字，即left == right
//此时，所有数字都是有序，排序完成;
//快速排序的时间复杂度为： 最优情况下为O(N)，最差即数组元素逆序的时候，相当于冒泡排序，时间复杂度为O（N^2）;