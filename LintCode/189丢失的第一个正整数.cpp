#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;

//189. 丢失的第一个正整数
//挑战
//只允许时间复杂度O(n)的算法，并且只能使用常数级别的空间。
//您的提交打败了 6.80% 的提交!

//选择排序
void SelectSort(vector<int>&a, int n) //选择排序
{
	int mix, temp;
	for (int i = 0; i<n - 1; i++) //每次循环数组，找出最小的元素，放在前面，前面的即为排序好的
	{
		mix = i; //假设最小元素的下标
		for (int j = i + 1; j<n; j++) //将上面假设的最小元素与数组比较，交换出最小的元素的下标
			if (a[j]<a[mix])
				mix = j;
		//若数组中真的有比假设的元素还小，就交换
		if (i != mix)
		{
			temp = a[i];
			a[i] = a[mix];
			a[mix] = temp;
		}
	}
}

int firstMissingPositive1(vector<int> &A) 
{
	// write your code here
	if (A.size() <= 0)
	{
		return 1;
	}
	if (A.size() == 1 && A[0] == -1)
	{
		return 1;
	}
	int m = A.size();
	int left = 0, right = m;

	//选择排序
	SelectSort(A, m);
	if (A[0] > 1)
	{
		return 1;
	}
	//找缺失的正整数
	for (int i = 0; i < m - 1; i++)
	{
		if (A[i] == A[i + 1])
		{
			continue;
		}
		if (A[i] + 1 != A[i + 1] && A[i] > 0)
		{
			return A[i] + 1;
		}
	}
	return A[m - 1] + 1;
}


//另外一种方法
//如果不做空间的要求，可以利用哈希的思想，元素i放在下标为i的位置。
//然后遍历辅助空间，第一个没有赋值的就是答案。
//您的提交打败了 92.20% 的提交!
int firstMissingPositive2(vector<int> &A)
{        // write your code 
	for(int i=0; i<A.size();)
	{
		if(A[i] == i+1)  //如果i位置就是对应的元素，跳过
			++i;            
		else
		{
			if(A[i] >=1 && A[i]<=A.size() && A[A[i]-1] != A[i]) //判断该元素是否是正整数，
				//并且在数组长度范围内，并且是唯一的
				swap(A[i], A[A[i]-1]);   //交换完成以后，i并不加一，因为换回来的元素还要进行判断 
			else     //出现负数，大于数组元素范围的数， 重复的数，直接跳过 
				++i;            
		}
	}                
	for(int i=0; i<A.size(); ++i)
	{   //寻找第一个下标和元素不对应的数            
		if(A[i] != i+1)                
			return i+1;      
	}        
	return A.size()+1;    //如果都是对应的，则返回数组长度的下一个元素  
}

//196. Missing Number
//在数组上原地完成，使用O(1)的额外空间和O(N)的时间。
//您的提交打败了 79.80% 的提交!
//利用hash哈希映射的思路。
int findMissing(vector<int> &nums)
{
	// write your code here
	int len = nums.size();
	vector<bool>numb(len + 1, false);
	for (int i = 0; i<len; i++) 
		numb[nums[i]] = true;
	for (int i = 0; i <=len; i++)
	{
		if (numb[i] == false)
			return i;
	}
}   

//681. 缺失的第一个素数
//您的提交打败了 100.00% 的提交!
//注释掉的部分打败98.03%的提交
int firstMissingPrime(vector<int> &nums) 
{
	// write your code here
	//int minPrime = 2;//2是第一个素数，也是素数中唯一的偶数。
	//if (nums.empty() || nums.size() == 0 || nums[0] > 2)
	//{
	//	return minPrime;
	//}
	//minPrime++;
	//int count = 1;//从第二个素数开始算起，素数中只有2是偶数，其余全是奇数。
	//while (count < nums.size() + 1)
	//{
	//	bool prime = true;
	//	for (int i = 2; i*i <= minPrime; i++)
	//	{
	//		if (minPrime%i == 0)
	//		{
	//			prime = false;
	//			break;
	//		}
	//	}
	//	if (prime)
	//	{
	//		if (count < nums.size() && nums[count] != minPrime)
	//		{
	//			return minPrime;
	//		}
	//		count++;
	//	}
	//	minPrime = minPrime + 2;
	//}
	//return minPrime - 2;
	int minPrime = 2;//2是第一个素数，也是素数中唯一的偶数。
	if (nums.empty() || nums.size() == 0)
	{
		return minPrime;
	}
	int count = 0;//从第二个素数开始算起，素数中只有2是偶数，其余全是奇数。
	while (count < nums.size() + 1)
	{
		bool prime = true;
		for (int i = 2; i*i <= minPrime; i++)
		{
			if (minPrime%i == 0)
			{
				prime = false;
				break;
			}
		}
		if (prime)
		{
			if (count < nums.size() && nums[count] != minPrime)
			{
				return minPrime;
			}
			count++;
		}
		minPrime++;
	}
	return minPrime - 1;
}


//按照自己的思路，先把所有的正数放在数组的前半部分，然后排序
//您的提交打败了 83.40% 的提交!
int firstMissingPositive(vector<int> &A)
{
	if (A.empty())
	{
		return 1;
	}
	int low = 0;
	int high = A.size() - 1;
	while (low < high)
	{
		while (A[low] > 0 && low <= high)
		{
			low++;
		}
		while (A[high] <= 0 && low <= high)
		{
			high--;
		}
		if (low < high)
		{
			swap(A[low], A[high]);
		}
	}
	cout << low << endl;

	sort(A.begin(), A.begin() + low);
	if (A[0] < 1 || A[0] > 1)
	{
		return 1;
	}
	for (int i = 0; i < A.size() - 1; i++)
	{
		if (A[i] == A[i + 1])
		{
			continue;
		}
		if (A[i] + 1 != A[i + 1])
		{
			return A[i] + 1;
		}
	}
	return A.size() + 1;
}

int main()
{
	vector<int> A = { -2 };

	int res = firstMissingPositive(A);
	for (int i = 0; i < A.size(); i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	cout << res << endl;
	system("pause");
	return 0;
}