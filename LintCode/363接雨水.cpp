#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


//363. 接雨水
/*
//超出时间限制，求最大的时候重复遍历，造成时间浪费。
int trapRainWater(vector<int> &heights) 
{
	// write your code here
	if (heights.empty())
	{
		return 0;
	}
	int len = heights.size();
	if (len <= 2)
	{
		return 0;
	}
	int res = 0;
	for (int i = 0; i < len; i++)
	{
		int start = 0;
		int end = len - 1;
		int leftmax = heights[start];
		int rightmax = heights[end];
		while (start<i)
		{
			if (leftmax < heights[start])
			{
				leftmax = heights[start];
			}
			start++;
		}
		while (end > i)
		{
			if (rightmax < heights[end])
			{
				rightmax = heights[end];
			}
			end--;
		}
		int temp = min(leftmax, rightmax);
		if (temp > heights[i])
		{
			res = res + temp - heights[i];
		}
	}
	return res;
}
*/

//您的提交打败了 98.80% 的提交!
int trapRainWater(vector<int> &heights)
{        // write your code here
	if (heights.empty())
	{
		return 0;
	}
	//单独定义两个vector来存储左右的最大值
	vector<int> left(heights.size()); 
	vector<int> right(heights.size());
	int maxH = heights[0];  
	left[0] = heights[0];  
	for(int i=1; i<heights.size(); ++i)
	{            
		if(heights[i] < maxH)
		{                
			left[i] = left[i-1];
		}            
		else
		{                
			left[i] = heights[i]; 
			maxH = heights[i]; 
		}       
	}          
	int len = heights.size();
	maxH = heights[len-1]; 
	right[len-1] = maxH; 
	for(int i=len-2; i>=0; --i)
	{           
		if(heights[i] < maxH)
		{               
			right[i] = right[i+1]; 
		}            
		else
		{  
			right[i] = heights[i];
			maxH = heights[i]; 
		}      
	}           
	int res = 0; 
	for(int i=0; i<heights.size(); ++i)
	{            
		if(heights[i] == left[i] || heights[i] == right[i])
		{     
			continue; 
		}              
		int h = min(left[i], right[i]);
		res += (h - heights[i]);   
	}        
	return res;
}


int main()
{
	vector<int> num = { 0,1,0,2,1,0,1,3,2,1,2,1 };
	int res = trapRainWater(num);
	cout << res << endl;
	system("pause");
	return 0;
}