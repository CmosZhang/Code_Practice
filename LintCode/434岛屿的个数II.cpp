#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

//434.����ĸ���II
//˼·�����ÿ��λ�÷����仯�����ʺ��������ķ����������ʺ��ò��鼯�ķ���������
//�����ύ����� 43.00% ���ύ!

//Ѱ��root����߲㵺��
int unionSearch(int root, vector<int>&nums)
{
	while (root != nums[root])
	{
		nums[root] = nums[nums[root]];
		root = nums[root];
	}
	return root;
}


vector<int> numIslands2(int n, int m, vector<Point> &operators)
{
	vector<int> res;
	if (n <= 0 || m <= 0 || operators.empty())
	{
		return res;
	}

	vector<int> nums(n*m + 1, 0);//�±��ʾ�����λ��
	vector<vector<int>> dic = { {1,0},{-1,0},{0,1},{0,-1} };//���������������4��λ��
	int count = 0;
	for (auto c : operators)
	{
		int pos = c.x*m + c.y + 1;
		//��nums[pos]��Ϊ0�������Ѿ����ֹ���ֱ�ӷ������еĵ�����Ŀ
		if (nums[pos] > 0)
		{
			res.push_back(count);
			continue;
		}
		//��ʼ��nums[pos]Ϊpos,��ʾpos��߲�ĵ����Ǳ�����ʱ������+1
		nums[pos] = pos;
		count++;
		for (auto t : dic)
		{
			int a = c.x + t[0];
			int b = c.y + t[1];
			int tmp = a * m + b + 1;
			if (a < 0 || a >= n || b < 0 || b >= m || nums[tmp] == 0)
			{
				continue;
			}
			//tmp��ʾpos������λ��,rootΪtmp����߲㵺��
			//root!=pos��ʾpos��root��������ͬһ������,��pos����root���ڵĴ�,
			//nums[pos]=root,����pos��Ϊroot�����ظ�����,��ʱ������Ŀ-1
			int root = unionSearch(tmp, nums);
			if (root != pos)
			{
				nums[pos] = root;
				pos = root;
				--count;
			}
		}
		res.push_back(count);
	}
	return res;
}

int main()
{
	int n = 4, m = 5;
	vector<Point> temp = { {1,1 },{0, 1},{3, 3},{3, 4} };
	vector<int> num = numIslands2(n, m, temp);
	for (int i = 0; i < num.size(); i++)
	{
		cout << num[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}