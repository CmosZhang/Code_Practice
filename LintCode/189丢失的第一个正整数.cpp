#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>

using namespace std;

//189. ��ʧ�ĵ�һ��������
//��ս
//ֻ����ʱ�临�Ӷ�O(n)���㷨������ֻ��ʹ�ó�������Ŀռ䡣
//�����ύ����� 6.80% ���ύ!

//ѡ������
void SelectSort(vector<int>&a, int n) //ѡ������
{
	int mix, temp;
	for (int i = 0; i<n - 1; i++) //ÿ��ѭ�����飬�ҳ���С��Ԫ�أ�����ǰ�棬ǰ��ļ�Ϊ����õ�
	{
		mix = i; //������СԪ�ص��±�
		for (int j = i + 1; j<n; j++) //������������СԪ��������Ƚϣ���������С��Ԫ�ص��±�
			if (a[j]<a[mix])
				mix = j;
		//������������бȼ����Ԫ�ػ�С���ͽ���
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

	//ѡ������
	SelectSort(A, m);
	if (A[0] > 1)
	{
		return 1;
	}
	//��ȱʧ��������
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


//����һ�ַ���
//��������ռ��Ҫ�󣬿������ù�ϣ��˼�룬Ԫ��i�����±�Ϊi��λ�á�
//Ȼ����������ռ䣬��һ��û�и�ֵ�ľ��Ǵ𰸡�
//�����ύ����� 92.20% ���ύ!
int firstMissingPositive2(vector<int> &A)
{        // write your code 
	for(int i=0; i<A.size();)
	{
		if(A[i] == i+1)  //���iλ�þ��Ƕ�Ӧ��Ԫ�أ�����
			++i;            
		else
		{
			if(A[i] >=1 && A[i]<=A.size() && A[A[i]-1] != A[i]) //�жϸ�Ԫ���Ƿ�����������
				//���������鳤�ȷ�Χ�ڣ�������Ψһ��
				swap(A[i], A[A[i]-1]);   //��������Ժ�i������һ����Ϊ��������Ԫ�ػ�Ҫ�����ж� 
			else     //���ָ�������������Ԫ�ط�Χ������ �ظ�������ֱ������ 
				++i;            
		}
	}                
	for(int i=0; i<A.size(); ++i)
	{   //Ѱ�ҵ�һ���±��Ԫ�ز���Ӧ����            
		if(A[i] != i+1)                
			return i+1;      
	}        
	return A.size()+1;    //������Ƕ�Ӧ�ģ��򷵻����鳤�ȵ���һ��Ԫ��  
}

//196. Missing Number
//��������ԭ����ɣ�ʹ��O(1)�Ķ���ռ��O(N)��ʱ�䡣
//�����ύ����� 79.80% ���ύ!
//����hash��ϣӳ���˼·��
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

//681. ȱʧ�ĵ�һ������
//�����ύ����� 100.00% ���ύ!
//ע�͵��Ĳ��ִ��98.03%���ύ
int firstMissingPrime(vector<int> &nums) 
{
	// write your code here
	//int minPrime = 2;//2�ǵ�һ��������Ҳ��������Ψһ��ż����
	//if (nums.empty() || nums.size() == 0 || nums[0] > 2)
	//{
	//	return minPrime;
	//}
	//minPrime++;
	//int count = 1;//�ӵڶ���������ʼ����������ֻ��2��ż��������ȫ��������
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
	int minPrime = 2;//2�ǵ�һ��������Ҳ��������Ψһ��ż����
	if (nums.empty() || nums.size() == 0)
	{
		return minPrime;
	}
	int count = 0;//�ӵڶ���������ʼ����������ֻ��2��ż��������ȫ��������
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


//�����Լ���˼·���Ȱ����е��������������ǰ�벿�֣�Ȼ������
//�����ύ����� 83.40% ���ύ!
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