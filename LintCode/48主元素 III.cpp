#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>


using namespace std;

//������ֻ��Ψһ����Ԫ��
//hash�ķ������������뵽���㷨
//48. ��Ԫ�� III
//�����ύ����� 48.40% ���ύ!
//ʹ�ù�ϣ��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n);
//int majorityNumber(vector<int> &nums, int k) {
//	// write your code here
//	int n = nums.size();
//	unordered_map<int, int>result;
//	for (int i = 0; i<n; i++)
//	{
//		if (++result[nums[i]]>n / k)
//			return nums[i];
//	}
//	return -1;
//}


//�����㷨��
//��Ŀ��Ҫ��Ϊ�ռ临�Ӷ�ΪO(k),ʱ�临�Ӷ�ΪO(n);
//����������Ļ����Ϸ�չ����
//����㷨��ʱ�临�Ӷ�ΪO(nk+k-1+n*(k-1)+k-1)=O(2nk+2(k-1)),��n>>kʱ���㷨��ʱ�临�Ӷ�ΪO(nk),Ҳ�ͽ���O(n);
//����㷨��n>>k������£����ƱȽ�����
//�����ύ����� 83.80% ���ύ!
int majorityNumber(vector<int> &nums, int k) {
	// write your code here
	if (nums.empty())
	{
		return -1;
	}
	int len = nums.size();
	vector<int> MajorNum(k - 1, 0);//�������飬�ռ临�Ӷ�ΪO(2*(k-1))
	vector<int> count(k - 1, 0);
	bool hasused = false;

	//����ѭ�����㷨��ʱ�临�Ӷ�ΪO(n*((k-1)+(k-1)+(k-1))=O(3n(k-1))=O(nk)
	for (int i = 0; i < len; i++)
	{
		hasused = false;
		for (int j = 0; j < k - 1; j++) //������տ�ʼ��ΪmajorԪ��ȫΪ0����Ҫ��������һ��ġ�
		{
			if (MajorNum[j] == nums[i])
			{
				count[j]++;
				hasused = true;
				break; //��������forѭ��
			}
		}

		if (hasused)
		{
			continue;
		}

		//ʱ�临�Ӷȣ��տ�ʼ��ΪcountԪ��ȫΪ0��ֻ����һ�Σ�
		//�������ݵ����࣬���Ӷȱ�ΪO(k-1)
		for (int j = 0; j < k - 1; j++) 
		{
			if (count[j] == 0)
			{
				MajorNum[j] = nums[i];
				count[j]++;
				hasused = true;
				break;
			}
		}

		if (hasused)
		{
			continue;
		}

		for (int j = 0; j < k - 1; j++)//ʱ�临�Ӷ�O(k-1)
		{
			if (count[j] != 0)
			{
				count[j]--;
			}
		}
	}

	//���ģ���ʱ�临�Ӷ�ΪO(k-1)
	for (int j = 0; j < k - 1; j++)
	{
		count[j] = 0;
	}

	//��һ��ģ���ʱ�临�Ӷ�ΪO(n*(k-1))
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < k - 1; j++)
		{
			if (MajorNum[j] == nums[i])
			{
				count[j]++;
			}
		}
	}

	//���ģ���ʱ�临�Ӷ�ΪO(k-1)
	int index = 0;
	int temp = 0;
	for (int i = 0; i < k - 1; i++)
	{
		if (temp < count[i])
		{
			temp = count[i];
			index = i;
		}
	}
	return MajorNum[index];
}