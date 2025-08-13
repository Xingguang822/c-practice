#include<iostream>
#include<vector>
using namespace std;


// 二分查找
int binarySearch(vector<int>& nums, int target)
{
	//第一种写法
	if (nums.size() == 0)return -1;
	int left = 0, right = nums.size() - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)return mid;
		if (nums[mid] < target)left = mid + 1;
		else right = mid - 1;
	}
	return -1;

	//第二种写法
	/*if (nums.size() == 0)return -1;
	int left = 0, right = nums.size() ;
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)right=mid;
		if (nums[mid] < target)left = mid + 1;
		else right = mid;
	}
	if (left == nums.size())return -1;
	return nums[left] == target ? left : -1;*/

	//第三种写法
	/*if (nums.size() == 0)return -1;
	int left = 0, right = nums.size();
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)left=mid+1;
		if (nums[mid] < target)left = mid ;
		else right = mid;
	}
	if (left == 0)return -1;
	return nums[left-1] == target ? left - 1 : -1;*/
}


int main()
{
	vector<int> a{ 1,2,3,4,5,5,5,5,5,6,7,8,9,10 };
	cout<<binarySearch(a, 5);
	return 0;
}