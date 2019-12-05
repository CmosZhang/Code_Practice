#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

#define MAX_Value -999999

int main()
{
	vector<int> A;
	vector<int> B;


	int input1;
	char c;
	while ((c = getchar()) != '\n')
	{
		if (c != ' ')
		{
			ungetc(c, stdin);
			cin >> input1;
			A.push_back(input1);
		}
	}
	int input2;
	char c1;
	while ((c1 = getchar()) != '\n')
	{
		if (c1 != ' ')
		{
			ungetc(c1, stdin);
			cin >> input2;
			B.push_back(input2);
		}
	}
	//ºËÐÄË¼Â·£º
	int index = 0;
	for (int i = 0; i < A.size() - 1; i++)
	{
		if (A[i] < A[i + 1])
		{
			continue;
		}
		else if (A[i] > A[i + 1])
		{
			index = i + 1;
			break;
		}
	}

	int temp1 = 0;
	int temp2 = 0;
	if (index == A.size() - 1)
	{
		temp1 = A[index - 1];
	}
	else
	{
		temp1 = A[index - 1];
		temp2 = A[index + 1];
	}

	int maxValue = MAX_Value;
	if (temp2 != 0)
	{
		for (int i = 0; i < B.size(); i++)
		{
			if (B[i] > temp1&&B[i] < temp2)
			{
				maxValue = max(maxValue, B[i]);
			}
		}
	}
	else
	{
		for (int i = 0; i < B.size(); i++)
		{
			if (B[i] > temp1)
			{
				maxValue = max(maxValue, B[i]);
			}
		}
	}
	
	if (maxValue == MAX_Value)
	{
		cout << "NO" << endl;
	}
	else
	{
		for (int i = 0; i < A.size(); i++)
		{
			if (i != index)
			{
				cout << A[i] << " ";
			}
			else
			{
				cout << maxValue << " ";
			}
		}
	}
	system("pause");
	return 0;
}