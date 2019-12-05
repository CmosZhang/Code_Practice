#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


void maxHeapDown(vector<int>&a, int start, int end)
{
	int c = start;            // ��ǰ(current)�ڵ��λ��
	int l = 2 * c + 1;        // ��(left)���ӵ�λ��
	int tmp = a[c];           // ��ǰ(current)�ڵ�Ĵ�С
	for (; l <= end; c = l, l = 2 * l + 1)
	{
		// "l"�����ӣ�"l+1"���Һ���
		if (l < end && a[l] < a[l + 1])
			l++;        // ������������ѡ��ϴ��ߣ���m_heap[l+1]
		if (tmp >= a[l])
			break;        // ��������
		else            // ����ֵ
		{
			a[c] = a[l];
			a[l] = tmp;
		}
	}
}

/*
* ������(��С����)
*
* ����˵����
*     a -- �����������
*     n -- ����ĳ���
*/
void heapSortAsc(vector<int>&a, int n)
{
	int i, tmp;
	// ��(n/2-1) --> 0��α���������֮�󣬵õ�������ʵ������һ��(���)����ѡ�
	for (i = n / 2 - 1; i >= 0; i--)
		maxHeapDown(a, i, n - 1);
	// �����һ��Ԫ�ؿ�ʼ�����н��е��������ϵ���С�����ķ�Χֱ����һ��Ԫ��
	for (i = n - 1; i > 0; i--)
	{
		// ����a[0]��a[i]��������a[i]��a[0...i]�����ġ�
		tmp = a[0];
		a[0] = a[i];
		a[i] = tmp;
		// ����a[0...i-1]��ʹ��a[0...i-1]��Ȼ��һ�����ѡ�
		// ������֤a[i-1]��a[0...i-1]�е����ֵ��
		maxHeapDown(a, 0, i - 1);
	}
}
//486. �ϲ�k����������
//��ʱ�临�Ӷ�Ҫ��
//�����ύ����� 87.20% ���ύ!
vector<int> mergekSortedArrays(vector<vector<int>> &arrays)
{
    // write your code here
	vector<int> res;
	if (arrays.empty())
	{
		return res;
	}
	int row = arrays.size();
	//int col = arrays[0].size();
	int len = 0;
	for (int i = 0; i < row; i++)
	{
		int len_temp = arrays[i].size();
		if (len_temp > 0)
		{
			len += len_temp;
		}
		for (int j = 0; j < len_temp; j++)
		{
			res.push_back(arrays[i][j]);
		}
	}
	heapSortAsc(res, len);            // ��������
	return res;
}

int main()
{
	vector<vector<int>> num = { {1, 3, 5, 7},{2, 4, 6},{0, 8, 9, 10, 11} };
	vector<int> ans = mergekSortedArrays(num);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i]<<" ";
	}
	cout << endl;
	system("pause");
	return 0;
}