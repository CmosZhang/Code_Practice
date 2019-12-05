#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

void bksort(int A[],int l,int h)
{    
	int size = h - l + 1;
	vector<vector<int>> b(size);
	//��size�����ݣ��ͷ���size��Ͱ   
	for(int i=l;i<=h;i++)
	{   
		int bi = size*A[i];//Ԫ��A[i]��Ͱ���  
		b[bi].push_back(A[i]);//��Ԫ��A[i]ѹ��Ͱ�� 
	}   
	for(int i=0;i<size;i++)   
		sort(b[i].begin(),b[i].end());//Ͱ������ 
	int idx = l;//ָ������A���±�    
	for(int i=0;i<size;i++)
	{//����Ͱ      
		for(int j=0;j<b[i].size();j++)
		{//����Ͱ��Ԫ��           
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
