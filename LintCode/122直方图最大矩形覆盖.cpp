#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;


//122. ֱ��ͼ�����θ���
//Time Limit Exceeded
//��ԭʼ�ķ�������
//68% ����ͨ������
/*
int largestRectangleArea(vector<int> &height)
{
	// write your code here
	if (height.empty())
	{
		return 0;
	}
	if (height.size() == 1) 
	{
		return height[0];
	}

	int len = height.size();
	
	int maxArea = INT_MIN;

	for (int i = 0; i < len; i++)
	{
		int left = i;
		int right = i;
		while (left - 1 >= 0 && height[left - 1] >= height[i])
		{
			left--;
		}
		while (right + 1 <= len - 1 && height[right + 1] >= height[i])
		{
			right++;
		}
		maxArea = max(maxArea, (right - left + 1) * height[i]);
	}
	return maxArea;
}
*/

//�����ύ����� 98.80% ���ύ!
int largestRectangleArea(vector<int> &height)
{
	// write your code here
	if (height.size() == 0) 
		return 0;
	int res = 0;
	vector<int> tmp = height;
	tmp.push_back(0);  // Important

	stack<int> s;    		//ά����������
	for (int i = 0; i < tmp.size(); i++)
	{
		if (s.empty() || (!s.empty() && tmp[i] >= tmp[s.top()])) 
			s.push(i);		//�����ǰ�߶ȴ���ջ����ֱ��ѹ��
		else 
		{
			while (!s.empty() && tmp[s.top()] > tmp[i]) 			//���ջ���߶ȴ��ڵ�ǰ�߶�
			{
				int idx = s.top();
				s.pop();						//����ջ��Ԫ����Ϣ
				int width = s.empty() ? i : (i - s.top() - 1);		//���ջ�Ѿ�Ϊ�գ����Ϊi������i-s.top()-1
				res = max(res, tmp[idx] * width);
			}
			s.push(i);  // Important							//ѹ��ջ��
		}
	}
	return res;
}

int main()
{
	vector<int> nums = {2,1,5,6,2,3 };
	int res = largestRectangleArea(nums);
	cout << res << endl;
	system("pause");
	return 0;
}