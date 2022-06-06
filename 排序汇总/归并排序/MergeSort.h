#pragma once

//打印函数
//入参：int arr[]，要打印的数组地址
//		size_arr，数组的元素个数
//出参：无
void Diy_printf(int arr[], int size_arr);

//合并函数，进行左右序列的排序合并
//入参：int arr[]，要排序的数组地址
//		int temp_arr[]，排序时临时存放排好序的数组
//		int mid，要合并的左右序列的中间值，用做区分左右序列的左右边界
//		int left，要合并的序列的左边界
//		int right，要合并的序列的右边界
//出参：无
void Merge(int arr[], int temp_arr[], int mid, int left, int right);

//拆分函数，将一个数组拆分为只有一个元素的序列，默认一个元素的序列是有序的
//入参：int arr[]，要拆分的数组的地址
//		int temp_arr[]，存放排完序的临时数组的地址
//		int left，要排序的序列的左边界
//		int right，要排序的序列的右边界
//出参：无
void Split(int arr[], int temp_arr[], int left, int right);

//归并排序的主函数入口
//入参：int arr[]，要排序的数组的地址
//		int left，要排序的数组的左边界
//		int right ，要排序的数组的右边界
//出参：无
void MergeSort(int arr[], int left, int right);



//归并排序总结：
// 中心思想：拆分和合并。
//将无序的数组拆分成只有一个元素的有序数组，然后左右序列进行合并，左右序列比较时，都用左右的第一个数字去比较，将两者中小的数字放在临时变量中，直到遍历完左右序列
// 如此遍历完后，临时数组就是有序的。后将临时数组的值复制到原数组中即可。
//归并排序的时间复杂度：O（NlogN）;	
//归并排序是稳定的排序