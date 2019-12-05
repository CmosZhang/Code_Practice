#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//510. ������
//�������ת����122��ֱ��ͼ�����θ���Ȼ��ֱ������122��ķ�����⼴��
//�����ύ����� 82.80% ���ύ!
int largestRectangleArea(vector<int> &height)
{
	// write your code here
	if (height.size() == 0)
		return 0;
	int res = 0;
	vector<int> tmp = height;
	tmp.push_back(0);  // Important

	stack<int> s;  //ά����������
	for (int i = 0; i < tmp.size(); i++)
	{
		if (s.empty() || (!s.empty() && tmp[i] >= tmp[s.top()]))
		{
			s.push(i);//�����ǰ�߶ȴ���ջ����ֱ��ѹ��
		}
		else
		{
			while (!s.empty() && tmp[s.top()] > tmp[i]) //���ջ���߶ȴ��ڵ�ǰ�߶�
			{
				int idx = s.top();
				s.pop();						//����ջ��Ԫ����Ϣ
				int width = s.empty() ? i : (i - s.top() - 1);//���ջ�Ѿ�Ϊ�գ����Ϊi������i-s.top()-1
				res = max(res, tmp[idx] * width);
			}
			s.push(i);  // Important							//ѹ��ջ��
		}
	}
	return res;
}

int maximalRectangle(vector<vector<bool>> &matrix) 
{
	// write your code here
	if (matrix.empty()||matrix[0].empty())
	{
		return 0;
	}
	int row = matrix.size();
	int col = matrix[0].size();
	int maxArea = 0;
	vector<vector<int>> height(row, vector<int>(col, 0));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (!matrix[i][j])
			{
				height[i][j] = 0;
			}
			else 
			{
				height[i][j] = (i == 0) ? 1 : height[i - 1][j] + 1;
			}
		}
	}

	for (int i = 0; i < row; i++) 
	{
		maxArea = max(maxArea, largestRectangleArea(height[i]));
	}
	return maxArea;
}

int main()
{
	vector<vector<bool>> num = { { 1, 1, 0, 0, 1 },{ 0,1,0,0,1 },{ 0,0,1,1,1 },{ 0,0,1,1,1},{ 0,0,0,0,1 } };
	int ans = maximalRectangle(num);
	cout << ans << endl;
	system("pause");
	return 0;
}