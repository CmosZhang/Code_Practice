#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

//83�䵥����II��
int singleNumberII(vector<int> &A) 
{
	// write your code here
	//sort(A.begin(), A.end());
	int length = A.size();
	int ones = 0;       
	int twos = 0;
	for (int i = 0; i < length; i++)
	{
	    ones = (ones ^ A[i]) & (~twos);           
		twos = (twos ^ A[i]) & (~ones); 
	}         
	return ones;
}

//84. �䵥���� III
//���ַ���ʱ�临�ӶȱȽϸߣ������72%���ύ������ʱ��3220ms��
//���������Ż���
vector<int> singleNumberIII(vector<int> &A)
{
	// write your code here
	vector<int> res;
	if (A.size() <= 0)
	{
		return res;
	}
	sort(A.begin(), A.end());
	if (A[0] != A[1])
	{
		res.push_back(A[0]);
	}
	int len = A.size();
	for (int i = 1; i <= len - 2; i++)
	{
		if (A[i] != A[i - 1] && A[i] != A[i + 1])
		{
			res.push_back(A[i]);
		}
	}
	if (A[len - 2] != A[len - 1])
	{
		res.push_back(A[len-1]);
	}
	return res;
}
/* ������������set����������
vector<int> singleNumberIII(vector<int> &A)
{
	// write your code here
	vector<int> res;
	if (A.size() <= 0)
	{
		return res;
	}
	int len = A.size();
	set<int> data;
	set<int>::iterator it;
	for (int i = 0; i<len; i++)
	{
		if (data.find(A[i]) == data.end())
		{
			data.insert(A[i]);
		}
		else
		{
			it = data.find(A[i]);
			data.erase(it);
		}
	}
	it = data.begin();
	res.push_back(*it);
	res.push_back(*(++it));
	return res;
}*/

//������
//�ϸ�����㷨��ʱ�临�ӶȺͿռ临�Ӷ�
//ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1)
//�����ύ����� 59.80% ���ύ!
vector<int> singleNumberIII(vector<int> &A) {
	// write your code here
	vector<int> res(2);
	if (A.empty())
	{
		return res;
	}
	int len = A.size();
	int x = 0;
	//x��������ֻ����һ�ε����������
	for (int i = 0; i < len; i++)
	{
		x ^= A[i];
	}
	//�ҵ�x�Ķ����Ʊ�ʾʽ�У���һ��Ϊ1��λ�ã��ӵ�λ����λ��
	int pos;
	for (int i = 0; i < 32; ++i)
	{
		if (x & (1 << i)) 
		{
			pos = i;
			break;
		}
	}
	//��1��λ��Ϊ���ޣ�����Ϊ���������飬������ͬ�����ͷֱ������������鵱��
	//�������������������
	for (int i = 0; i < len; ++i)
	{
		if (A[i] & (1 << pos))
			res[0] ^= A[i];
		else
			res[1] ^= A[i];
	}
	return res;
}


//824. �䵥���� IV
//�������飬����һ��������һ���⣬���������������Σ�
//�������г������ε��������š����ҳ��ҳ��Ǹ�����һ�ε�����
//������⣬�����ύ����� 99.66% ���ύ!
//�ö��ַ����
int getSingleNumber(vector<int> &nums) 
{
	// Write your code here
	//sort(nums.begin(), nums.end());
	if (nums[0] != nums[1])
	{
		return nums[0];
	}
	int len = nums.size();
	for (int i = 2; i < len - 1; i++)
	{
		if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
		{
			return nums[i];
		}
	}
	if (nums[len - 2] != nums[len - 1])
	{
		return nums[len-1];
	}
}


int main()
{
	//vector<int>nums = { 1,2,3,3,2,4,1,5 };
	//vector<int>res;
	//res = singleNumberIII(nums);
	//for (int i = 0; i < res.size(); i++)
	//{
	//	cout << res[i] << ' ';
	//}
	//cout << endl;

	vector<int>nums = { 3,3,2,2,4,5,5 };
	int res2;
	res2 = getSingleNumber(nums);
	cout << res2 << endl;


	system("pause");
	return 1;
}