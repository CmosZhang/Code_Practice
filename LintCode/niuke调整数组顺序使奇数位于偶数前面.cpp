#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//调整数组顺序
void reOrderArray(vector<int> &array)
{
	if (array.size() <= 0)
	{
		return;
	}
	int len = array.size();
	int start = 0;
	int end = len - 1;
	while (start < end)
	{
		if (array[start] % 2 != 0)
		{
			start++;
			continue;
		}
		if (array[end] % 2 == 0)
		{
			end--;
			continue;
		}
		int temp = array[end];
		array[end] = array[start];
		array[start] = temp;
		start++;
		end--;
	}
}

int main()
{
	vector<int>num = { 1,2,3,4,5,6,7 };
	reOrderArray(num);
	for (int i = 0; i < num.size(); i++)
	{
		cout << num[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}