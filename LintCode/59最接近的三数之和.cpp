#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//59. ��ӽ�������֮��
//ͨ�����������ǿ����뵽һ��ʱ�临�Ӷ�ΪO(n^2)�Ľⷨ��
//������������len��Ԫ�أ��������ǽ������е�Ԫ�ذ��մ�С�����˳���������
//��Σ�������ȡ�����������еĵ�һ�����������鳤��Ϊn����ô��n��ȡ����
//����ȡ�ĵ�һ������A[i]����ô�ڶ�����������A[i+1]~A[len]��ȡ����
//�ҵ�����һ����ΪA[i]�̶�������������A[i]����Ԫ����ȡ����������֮����target������������
//��ʱ������������ָ��j,k�ֱ�ָ��A[i+1]��A[len]��
//�����ʱ����֮��A[i]+A[j]+A[k]<target��˵������֮��С�ˣ�
//���ǽ�j����һ�񣻷�֮�����ʹ���target����kǰ��һ��
//ֱ��j��k����Ϊֹ�������ڼ䣬������target���������֮�͡�
//һ�������С��͵���target�������,����������ɡ�
//�����ύ����� 84.00% ���ύ!
int threeSumClosest(vector<int> &numbers, int target)
{
	// write your code here
	int res = numbers[0] + numbers[1] + numbers[2];
	int dis = abs(res - target);//��������֮����Ŀ��ֵ�Ĳ�
	sort(numbers.begin(), numbers.end());
	for (int i = 0; i < numbers.size(); i++)
	{
		int j = i + 1, k = numbers.size() - 1;
		while (j < k)
		{
			int sum = numbers[i] + numbers[j] + numbers[k];
			int temp = abs(sum - target);
			if (temp < dis)//�ҵ���Ŀ��ֵ��С��ֵ������֮��
			{
				dis = temp;
				res = sum;
			}
			if (sum < target)
			{
				j++;
			}
			else if (sum > target)
			{
				k--;
			}
			else
			{
				return res;
			}
		}
	}
	return res;
}

//��ӽ�������֮�ͣ��ڶ��ַ���
//�����ύ����� 65.20% ���ύ!
int threeSumClosest(vector<int> &numbers, int target)
{
	if (numbers.empty() || numbers.size() < 3)
	{
		return -1;
	}
	sort(numbers.begin(), numbers.end());
	int res = numbers[0] + numbers[1] + numbers[2];
	for (int i = 0; i < numbers.size(); i++)
	{
		int left = i + 1, right = numbers.size() - 1;
		while (left < right)
		{
			if (abs(res - target) > abs(numbers[i] + numbers[left] + numbers[right] - target))
			{
				res = numbers[i] + numbers[left] + numbers[right];
			}
			if (numbers[i] + numbers[left] + numbers[right] < target)
			{
				left++;
			}
			else
			{
				right--;
			}
		}
	}
	return res;
}

//57. ����֮��
//�����ύ����� 24.20% ���ύ!
//ʹ��python�Ļ����50%���ύ
vector<vector<int>> threeSum(vector<int> &numbers) 
{
	// write your code here
	vector<vector<int>>res;
	if (numbers.size() <= 0)
	{
		return res;
	}
	sort(numbers.begin(), numbers.end());
	int len = numbers.size();
	for (int i = 0; i < len - 2; i++)
	{
		if (i == 0 || numbers[i] > numbers[i - 1])
		{
			int left = i + 1;
			int right = len - 1;
			while (left < right)
			{
				int sum = numbers[left] + numbers[right] + numbers[i];
				if (sum == 0)
				{
					vector<int> temp = { numbers[i], numbers[left], numbers[right] };
					res.push_back(temp);
					left++;
					right--;//���µ�������whileѭ����Ҫ��Ϊ��ȥ���ظ�Ԫ��
					while (left < right&&numbers[left] == numbers[left - 1])
					{
						left++;
					}
					while (left < right&&numbers[right] == numbers[right + 1])
					{
						right--;
					}
				}
				else if (sum < 0)
				{
					left++;
				}
				else
				{
					right--;
				}
			}
		}
	}
	return res;
}

int main()
{
	vector<int>num = { -1, 2, 1, -4 };
	int target = 1;
	int res = threeSumClosest(num, target);
	cout << res << endl;
	system("pause");
	return 1;
}