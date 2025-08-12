#include<iostream>
#include<vector>
#include<chrono>
#include<algorithm>

using namespace std;

//冒泡排序
void bubble_sort(vector<int> &nums)
{
	//第一种写法
	/*for (int i = 0; i < nums.size() - 1; ++i)
	{
		for (int j = 1; j < nums.size() - i - 1; ++j)
		{
			if (nums[j] > nums[j + 1])
			{
				swap(nums[j], nums[j + 1]);
			}
		}
	}*/


	//第二种写法
	/*bool swapped;
	for (int i = 0; i < nums.size() - 1; ++i)
	{
		swapped = false;
		for (int j = 0; j < nums.size() - 1 - i; ++j)
		{
			if (nums[j] > nums[j + 1])
			{
				swap(nums[j], nums[j + 1]);
				swapped = true;
			}
		}
		if (!swapped)break;
	}*/


	//第三种写法
	bool swapped = true;
	int last_unsorted_index = nums.size() - 1;
	int swapped_index = -1;
	while (swapped)
	{
		swapped = false;
		for (int i = 0; i < last_unsorted_index; i++) {
			if (nums[i] > nums[i + 1])
			{
				swap(nums[i], nums[i + 1]);
				swapped = true;
				swapped_index = i;
			}
		}
		last_unsorted_index = swapped_index;
	}
}


//选择排序
void selectionSort(vector<int>& nums)
{
	int minindex;
	for (int i = 0; i < nums.size() - 1; ++i) {
		minindex = i;
		for (int j = i + 1; j < nums.size(); ++j) {
			if (nums[minindex] > nums[j]) {
				minindex = j;
			}
		}
		swap(nums[i], nums[minindex]);
	}
}


//二元选择排序
void selectionSort2(vector<int>& nums)
{
	int minindex,maxindex,n=nums.size();
	for (int i = 0; i < n/2; ++i) {
		maxindex=minindex = i;
		for (int j = i + 1; j < n-i; ++j) {
			if (nums[minindex] > nums[j]) {
				minindex = j;
			}
			if (nums[maxindex] < nums[j]) {
				maxindex = j;
			}
		}
		if (minindex == maxindex)break;
		swap(nums[minindex], nums[i]);
		if (maxindex == i)maxindex = minindex;
		swap(nums[maxindex], nums[n-i - 1]);
	}
}


//交换排序
void insertSort(vector<int>& nums)
{
	//第一种交换法
	int n = nums.size();
	/*for (int i = 1; i < n; ++i) {
		int j = i;
		while (j >= 1 && nums[j] < nums[j - 1]) {
			swap(nums[j], nums[j - 1]);
			--j;
		}
	}*/
	//第二种交换法
	for (int i = 1; i < n; ++i) {
		int j = i-1, temp = nums[i];
		while (j >= 0 && temp < nums[j]) {
			nums[j+1] = nums[j];
			--j;
		}
		nums[j + 1] = temp;
	}
}


//希尔排序
void shellSort(vector<int>& nums) {
	//第一种写法
	/*for (int gap = nums.size() / 2; gap > 0; gap /= 2) {
		for (int groupindex = 0; groupindex < gap; ++groupindex) {
			for (int current = groupindex + gap; current < nums.size(); current += gap) {
				int temp = nums[current], preindex = current - gap;
				while (preindex >= groupindex && temp < nums[preindex]) {
					nums[preindex + gap] = nums[preindex];
					preindex -= gap;
				}
				nums[preindex + gap] = temp;
			}
		}
	}*/
	//第二种写法（优化后）
	/*for (int gap = nums.size() / 2; gap > 0; gap /= 2) {
		for (int i = gap; i <nums.size(); ++i) {
			int temp = nums[i], preindex = i - gap;
			while (preindex >= 0 && temp < nums[preindex]) {
				nums[preindex + gap] = nums[preindex];
				preindex -= gap;
			}
			nums[preindex + gap] = temp;
		}
	}*/
}


//堆排序
void buildmaxheap(vector<int>&);
void maxHeapify(vector<int>&, int, int);
void heapsort(vector<int>& nums)
{
	buildmaxheap(nums);
	for (int i = nums.size()-1; i > 0; --i)
	{
		swap(nums[0], nums[i]);
		maxHeapify(nums, 0, i);
	}
}
void buildmaxheap(vector<int>& nums)
{
	for (int i = (nums.size()>>1) - 1; i > 0; --i) {
		maxHeapify(nums, i, nums.size());
	}
}
void maxHeapify(vector<int>& nums, int i, int heapSize)
{
	int l = (i<<1) + 1, r = l + 1, largest = i;
	if (l<heapSize && nums[l]>nums[largest])
	{
		largest = l;
	}
	if (r<heapSize && nums[r]>nums[largest])
	{
		largest = r;
	}
	if (largest != i)
	{
		swap(nums[i], nums[largest]);
		maxHeapify(nums, largest, nums.size());
	}
}


//快速排序
void quicksort(vector<int>& nums, int start, int end);
int partition(vector<int>& nums, int start, int end);
void quickSort(vector<int>& nums)
{
	quicksort(nums, 0, nums.size() - 1);
}
void quicksort(vector<int>& nums,int start,int end)
{
	if (start >= end)return;
	int middle = partition(nums, start, end);
	quicksort(nums, start, middle - 1);
	quicksort(nums, middle+1, end);
}
int partition(vector<int>& nums, int start, int end)
{
	int pivot = nums[start];
	int left = start + 1, right = end;
	//第一种写法
	/*while (left < right) {
		while (left < right && nums[left] <= pivot)++left;
		if (left != right) {
			swap(nums[left], nums[right]);
			--right;
		}
	}
	if (left == right && nums[right]>pivot)--right;
	if (right != start) swap(nums[right], nums[start]);
	return right;*/
	//第二种写法
	while (left < right) {
		while (left < right && nums[left] <= pivot)++left;
		while (left < right && nums[right] >= pivot)--right;
		if (left != right) {
			swap(nums[left], nums[right]);
		}
	}
	if (left == right && nums[right] > pivot)--right;
	swap(nums[right], nums[start]);
	return right;
}


//归并排序
void mergesort(vector<int>& nums, int start, int end, vector<int>& result);
void merge(vector<int>& nums, int start, int middle, int end, vector<int>& result);
void mergeSort(vector<int>& nums)
{
	if (nums.size() == 0)return;
	vector<int> result(nums.size());
	mergesort(nums, 0, nums.size() - 1, result);
}
void mergesort(vector<int>& nums,int start,int end, vector<int>& result)
{
	if (start == end)return;
	int middle = (start + end) / 2;
	mergesort(nums, start, middle, result);
	mergesort(nums, middle+1, end, result);
	merge(nums, start,middle, end, result);
}
void merge(vector<int>& nums, int start, int middle, int end, vector<int>& result)
{
	int end1 = middle, index1 = start, start2 = middle + 1,index2=start2;
	while (index1 <= end1 && index2 <= end) {
		if (nums[index1] <= nums[index2]) {
			result[index1 + index2 - start2] = nums[index1];
			++index1;
		}
		else {
			result[index1 + index2 - start2] = nums[index2];
			++index2;
		}
	}
	while (index1 <= end1) {
		result[index1 + index2 - start2] = nums[index1];
		++index1;
	}
	while (index2 <= end) {
		result[index1 + index2 - start2] = nums[index2];
		++index2;
	}
	while (start <= end)
	{
		nums[start] = result[start];
		++start;
	}
}

//计数排序
void countingSort(vector<int>& nums)
{
	if (nums.empty() || nums.size() <= 1)return;
	int min = nums[0], max = nums[0];
	for (int i : nums)
	{
		if (i > max)max = i;
		if (i < min)min = i;
	}
	int range = max - min + 1;
	vector<int> counting(range);
	for (int i : nums)
	{
		++counting[i - min];
	}
	//第一种写法
	/*int precounts = 0;
	for (int i = 0; i < range; ++i) {
		precounts += counting[i];
		counting[i] = precounts - counting[i];
	}
	vector<int> result(range);
	for (int i : nums) {
		result[counting[i-min]] = i;
		++counting[i - min];
	}*/
	//第二种写法
	--counting[0];
	for (int i = 0; i < nums.size()-1; i++)
	{
		counting[i + 1] += counting[i];
	}
	vector<int> result(range);
	for (int i = nums.size() - 1; i >= 0;--i) {
		result[counting[nums[i] - min]--] = nums[i];
	}
	for (int i = 0; i < nums.size(); ++i)
	{
		nums[i] = result[i];
	}

}


//基数排序
void radixSort(vector<int>& nums)
{
	//仅包含正数
	/*if (nums.empty() )return;
	int max = 0,maxdigitlength=0,n=nums.size();
	for (int i : nums)
	{
		if (i > max)max = i;
	}
	while (max != 0)
	{
		++maxdigitlength;
		max /= 10;
	}
	vector<int> counting(10), result(n);
	int dev = 1;
	for (int i = 0; i < maxdigitlength; ++i)
	{
		for (int j : nums)
		{
			int redix = j / dev % 10;
			++counting[redix];
		}
		for (int j = 1; j < counting.size(); ++j)
		{
			counting[j ] += counting[j-1];
		}
		for (int j = n - 1; j >= 0; --j)
		{
			int redix = nums[j] / dev % 10;
			result[--counting[redix]] = nums[j];
		}
		copy(result.begin(),result.end(),nums.begin());
		fill(counting.begin(), counting.end(), 0);
		dev *= 10;
	}*/
	//正负数都有
	if (nums.empty())return;
	int max = 0, maxdigitlength = 0, n = nums.size();
	for (int i : nums)
	{
		if (abs(i) > max)max = i;
	}
	while (max != 0)
	{
		++maxdigitlength;
		max /= 10;
	}
	vector<int> counting(19), result(n);
	int dev = 1;
	for (int i = 0; i < maxdigitlength; ++i)
	{
		for (int j : nums)
		{
			int redix = j / dev % 10+9;
			++counting[redix];
		}
		for (int j = 1; j < counting.size(); ++j)
		{
			counting[j] += counting[j - 1];
		}
		for (int j = n - 1; j >= 0; --j)
		{
			int redix = nums[j] / dev % 10+9;
			result[--counting[redix]] = nums[j];
		}
		copy(result.begin(), result.end(), nums.begin());
		fill(counting.begin(), counting.end(), 0);
		dev *= 10;
	}
}


//桶排序
void  bucketSort(vector<int>& nums)
{
	if (nums.empty() || nums.size() <= 1)return;
	int min = nums[0], max = nums[0];
	for (int i : nums)
	{
		if (i > max)max = i;
		if (i < min)min = i;
	}
	int range = max - min;
	int bucketamount = range / 10 + 1;
	double gap = range * 1.0 / (bucketamount - 1);
	vector<vector<int>> buckets(bucketamount);
	for (int value : nums)
	{
		int index = int((value - min) / gap);
		buckets[index].push_back(value);
	}
	vector<int> result;
	for (int i = 0; i < bucketamount; ++i)
	{
		if (buckets[i].size() <= 1)continue;
		insertSort(buckets[i]);
		copy(buckets[i].begin(), buckets[i].end(), back_inserter(result));
	}
	copy(result.begin(), result.end(), nums.begin());
}


template<typename T>  
void print_(const T &v) {  
    for (const auto &elem : v) {  
        cout << elem << " ";  
    }  
    cout << endl;  
}


int main() {
	int sum[11] = {0};
	for (int i = 0; i < 1; i++) {
		vector<int> a = { 35, 67, 12, 88, 42, 3, 97, 51, 19, 74, 28, 90, 5, 63, 33, 81, 16, 57, 94, 7, 45, 79, 22, 66, 10, 53, 86, 31, 72, 14, 48, 99, 25, 61, 38, 84, 1, 69, 18, 55, 92, 8, 41, 77, 29, 64, 95, 13, 50, 82, 21, 59, 36, 75, 4, 46, 98, 24, 71, 9, 54, 87, 32, 78, 15, 62, 37, 83, 2, 68, 20, 58, 93, 6, 44, 80, 27, 65, 96, 11, 49, 85, 30, 73, 17, 60, 39, 100, 26, 70, 43, 91, 23, 56, 34, 89, 40, 76, 52, 47 };
		auto start = chrono::high_resolution_clock::now();
		print_(a);
		cout << endl;
		bubble_sort(a);
		print_(a);
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
		cout << duration.count() << endl;
		sum[0] += duration.count();
	}
	for (int i = 0; i < 1; i++) {
		vector<int> a = { 35, 67, 12, 88, 42, 3, 97, 51, 19, 74, 28, 90, 5, 63, 33, 81, 16, 57, 94, 7, 45, 79, 22, 66, 10, 53, 86, 31, 72, 14, 48, 99, 25, 61, 38, 84, 1, 69, 18, 55, 92, 8, 41, 77, 29, 64, 95, 13, 50, 82, 21, 59, 36, 75, 4, 46, 98, 24, 71, 9, 54, 87, 32, 78, 15, 62, 37, 83, 2, 68, 20, 58, 93, 6, 44, 80, 27, 65, 96, 11, 49, 85, 30, 73, 17, 60, 39, 100, 26, 70, 43, 91, 23, 56, 34, 89, 40, 76, 52, 47 };
		auto start = chrono::high_resolution_clock::now();
		print_(a);
		cout << endl;
		selectionSort(a);
		print_(a);
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
		cout << duration.count() << endl;
		sum[1] += duration.count();
	}
	for (int i = 0; i < 1; i++) {
		vector<int> a = { 35, 67, 12, 88, 42, 3, 97, 51, 19, 74, 28, 90, 5, 63, 33, 81, 16, 57, 94, 7, 45, 79, 22, 66, 10, 53, 86, 31, 72, 14, 48, 99, 25, 61, 38, 84, 1, 69, 18, 55, 92, 8, 41, 77, 29, 64, 95, 13, 50, 82, 21, 59, 36, 75, 4, 46, 98, 24, 71, 9, 54, 87, 32, 78, 15, 62, 37, 83, 2, 68, 20, 58, 93, 6, 44, 80, 27, 65, 96, 11, 49, 85, 30, 73, 17, 60, 39, 100, 26, 70, 43, 91, 23, 56, 34, 89, 40, 76, 52, 47 };
		auto start = chrono::high_resolution_clock::now();
		print_(a);
		cout << endl;
		selectionSort2(a);
		print_(a);
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
		cout << duration.count() << endl;
		sum[2] += duration.count();
	}
	for (int i = 0; i < 1; i++) {
		vector<int> a = { 35, 67, 12, 88, 42, 3, 97, 51, 19, 74, 28, 90, 5, 63, 33, 81, 16, 57, 94, 7, 45, 79, 22, 66, 10, 53, 86, 31, 72, 14, 48, 99, 25, 61, 38, 84, 1, 69, 18, 55, 92, 8, 41, 77, 29, 64, 95, 13, 50, 82, 21, 59, 36, 75, 4, 46, 98, 24, 71, 9, 54, 87, 32, 78, 15, 62, 37, 83, 2, 68, 20, 58, 93, 6, 44, 80, 27, 65, 96, 11, 49, 85, 30, 73, 17, 60, 39, 100, 26, 70, 43, 91, 23, 56, 34, 89, 40, 76, 52, 47 };
		auto start = chrono::high_resolution_clock::now();
		print_(a);
		cout << endl;
		insertSort(a);
		print_(a);
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
		cout << duration.count() << endl;
		sum[3] += duration.count();
	}
	for (int i = 0; i < 1; i++) {
		vector<int> a = { 35, 67, 12, 88, 42, 3, 97, 51, 19, 74, 28, 90, 5, 63, 33, 81, 16, 57, 94, 7, 45, 79, 22, 66, 10, 53, 86, 31, 72, 14, 48, 99, 25, 61, 38, 84, 1, 69, 18, 55, 92, 8, 41, 77, 29, 64, 95, 13, 50, 82, 21, 59, 36, 75, 4, 46, 98, 24, 71, 9, 54, 87, 32, 78, 15, 62, 37, 83, 2, 68, 20, 58, 93, 6, 44, 80, 27, 65, 96, 11, 49, 85, 30, 73, 17, 60, 39, 100, 26, 70, 43, 91, 23, 56, 34, 89, 40, 76, 52, 47 };
		auto start = chrono::high_resolution_clock::now();
		print_(a);
		cout << endl;
		shellSort(a);
		print_(a);
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
		cout << duration.count() << endl;
		sum[4] += duration.count();
	}
	for (int i = 0; i < 1; i++) {
		vector<int> a = { 35, 67, 12, 88, 42, 3, 97, 51, 19, 74, 28, 90, 5, 63, 33, 81, 16, 57, 94, 7, 45, 79, 22, 66, 10, 53, 86, 31, 72, 14, 48, 99, 25, 61, 38, 84, 1, 69, 18, 55, 92, 8, 41, 77, 29, 64, 95, 13, 50, 82, 21, 59, 36, 75, 4, 46, 98, 24, 71, 9, 54, 87, 32, 78, 15, 62, 37, 83, 2, 68, 20, 58, 93, 6, 44, 80, 27, 65, 96, 11, 49, 85, 30, 73, 17, 60, 39, 100, 26, 70, 43, 91, 23, 56, 34, 89, 40, 76, 52, 47 };
		auto start = chrono::high_resolution_clock::now();
		print_(a);
		cout << endl;
		heapsort(a);
		print_(a);
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
		cout << duration.count() << endl;
		sum[5] += duration.count();
	}
	for (int i = 0; i < 1; i++) {
		vector<int> a = { 35, 67, 12, 88, 42, 3, 97, 51, 19, 74, 28, 90, 5, 63, 33, 81, 16, 57, 94, 7, 45, 79, 22, 66, 10, 53, 86, 31, 72, 14, 48, 99, 25, 61, 38, 84, 1, 69, 18, 55, 92, 8, 41, 77, 29, 64, 95, 13, 50, 82, 21, 59, 36, 75, 4, 46, 98, 24, 71, 9, 54, 87, 32, 78, 15, 62, 37, 83, 2, 68, 20, 58, 93, 6, 44, 80, 27, 65, 96, 11, 49, 85, 30, 73, 17, 60, 39, 100, 26, 70, 43, 91, 23, 56, 34, 89, 40, 76, 52, 47 };
		auto start = chrono::high_resolution_clock::now();
		print_(a);
		cout << endl;
		quickSort(a);
		print_(a);
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
		cout << duration.count() << endl;
		sum[6] += duration.count();
	}
	for (int i = 0; i < 1; i++) {
		vector<int> a = { 35, 67, 12, 88, 42, 3, 97, 51, 19, 74, 28, 90, 5, 63, 33, 81, 16, 57, 94, 7, 45, 79, 22, 66, 10, 53, 86, 31, 72, 14, 48, 99, 25, 61, 38, 84, 1, 69, 18, 55, 92, 8, 41, 77, 29, 64, 95, 13, 50, 82, 21, 59, 36, 75, 4, 46, 98, 24, 71, 9, 54, 87, 32, 78, 15, 62, 37, 83, 2, 68, 20, 58, 93, 6, 44, 80, 27, 65, 96, 11, 49, 85, 30, 73, 17, 60, 39, 100, 26, 70, 43, 91, 23, 56, 34, 89, 40, 76, 52, 47 };
		auto start = chrono::high_resolution_clock::now();
		print_(a);
		cout << endl;
		mergeSort(a);
		print_(a);
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
		cout << duration.count() << endl;
		sum[7] += duration.count();
	}
	for (int i = 0; i < 1; i++) {
		vector<int> a = { 35, 67, 12, 88, 42, 3, 97, 51, 19, 74, 28, 90, 5, 63, 33, 81, 16, 57, 94, 7, 45, 79, 22, 66, 10, 53, 86, 31, 72, 14, 48, 99, 25, 61, 38, 84, 1, 69, 18, 55, 92, 8, 41, 77, 29, 64, 95, 13, 50, 82, 21, 59, 36, 75, 4, 46, 98, 24, 71, 9, 54, 87, 32, 78, 15, 62, 37, 83, 2, 68, 20, 58, 93, 6, 44, 80, 27, 65, 96, 11, 49, 85, 30, 73, 17, 60, 39, 100, 26, 70, 43, 91, 23, 56, 34, 89, 40, 76, 52, 47 };
		auto start = chrono::high_resolution_clock::now();
		print_(a);
		cout << endl;
		countingSort(a);
		print_(a);
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
		cout << duration.count() << endl;
		sum[8] += duration.count();
	}
	for (int i = 0; i < 1; i++) {
		vector<int> a = { 35, 67, 12, 88, 42, 3, 97, 51, 19, 74, 28, 90, 5, 63, 33, 81, 16, 57, 94, 7, 45, 79, 22, 66, 10, 53, 86, 31, 72, 14, 48, 99, 25, 61, 38, 84, 1, 69, 18, 55, 92, 8, 41, 77, 29, 64, 95, 13, 50, 82, 21, 59, 36, 75, 4, 46, 98, 24, 71, 9, 54, 87, 32, 78, 15, 62, 37, 83, 2, 68, 20, 58, 93, 6, 44, 80, 27, 65, 96, 11, 49, 85, 30, 73, 17, 60, 39, 100, 26, 70, 43, 91, 23, 56, 34, 89, 40, 76, 52, 47 };
		auto start = chrono::high_resolution_clock::now();
		print_(a);
		cout << endl;
		radixSort(a);
		print_(a);
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
		cout << duration.count() << endl;
		sum[9] += duration.count();
	}
	for (int i = 0; i < 1; i++) {
		vector<int> a = { 35, 67, 12, 88, 42, 3, 97, 51, 19, 74, 28, 90, 5, 63, 33, 81, 16, 57, 94, 7, 45, 79, 22, 66, 10, 53, 86, 31, 72, 14, 48, 99, 25, 61, 38, 84, 1, 69, 18, 55, 92, 8, 41, 77, 29, 64, 95, 13, 50, 82, 21, 59, 36, 75, 4, 46, 98, 24, 71, 9, 54, 87, 32, 78, 15, 62, 37, 83, 2, 68, 20, 58, 93, 6, 44, 80, 27, 65, 96, 11, 49, 85, 30, 73, 17, 60, 39, 100, 26, 70, 43, 91, 23, 56, 34, 89, 40, 76, 52, 47 };
		auto start = chrono::high_resolution_clock::now();
		print_(a);
		cout << endl;
		bucketSort(a);
		print_(a);
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
		cout << duration.count() << endl;
		sum[10] += duration.count();
	}
	cout << "冒泡排序的平均时间:" << sum[0]  << endl;
	cout << "选择排序的平均时间:" << sum[1]  << endl;
	cout << "二分选择排序的平均时间:" << sum[2]<< endl;
	cout << "交换排序的平均时间:" << sum[3]<< endl;
	cout << "希尔排序的平均时间:" << sum[4] << endl;
	cout << "堆排序的平均时间:" << sum[5] << endl;
	cout << "快速排序的平均时间:" << sum[6]  << endl;
	cout << "归并排序的平均时间:" << sum[7]  << endl;
	cout << "计数排序的平均时间:" << sum[8]  << endl;
	cout << "基数排序的平均时间:" << sum[9] << endl;
	cout << "桶排序的平均时间:" << sum[10] << endl;
	return 0;
}