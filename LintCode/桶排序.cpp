#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

void bksort(int A[],int l,int h)
{    
	int size = h - l + 1;
	vector<vector<int>> b(size);
	//有size个数据，就分配size个桶   
	for(int i=l;i<=h;i++)
	{   
		int bi = size*A[i];//元素A[i]的桶编号  
		b[bi].push_back(A[i]);//将元素A[i]压入桶中 
	}   
	for(int i=0;i<size;i++)   
		sort(b[i].begin(),b[i].end());//桶内排序 
	int idx = l;//指向数组A的下标    
	for(int i=0;i<size;i++)
	{//遍历桶      
		for(int j=0;j<b[i].size();j++)
		{//遍历桶内元素           
			A[idx++] = b[i][j];   
		}  
	}
} 


int main()
{  
	int A[] = {120,3,9,5,67,82,9,7};   
	bksort(A,2,9);  
	for(int i=0;i<10;i++) 
		cout<<A[i]<<" ";
}
