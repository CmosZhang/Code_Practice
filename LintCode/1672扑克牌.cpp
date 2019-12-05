#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;


//1672. ÆË¿ËÅÆ
//
int minValue;

void dfs(vector<int>&cards, int sum)
{
	bool flag = cards[4] == 0 ? true : false;
	int index1 = 0, index2 = 0;
	for (int i = 3; i >= 0; i--)
	{
		if (cards[i] == 0)
		{
			index1 = i;
			break;
		}
	}
	for (int i = 5; i < 9; i++)
	{
		if (cards[i] == 0)
		{
			index2 = i;
			break;
		}
	}
	if (flag || !flag && (index2 - index1) <= 5)
	{
		int res = 0;
		for (int i = 0; i < cards.size(); i++)
		{
			if (cards[i] != 0)
				res++;
		}
		minValue = min(minValue, res + sum);
		return;
	}

	for (int i = 0; i < 5; i++)
	{
		int j = i, count = 0;
		for (; j < cards.size(); j++)
		{
			if (cards[j] == 0 && j - i < 5)
			{
				continue;
			}
			if (cards[j] == 0)
			{
				count = j - i;
			}
			else if (j == cards.size() - 1)
			{
				count = j - i + 1;
			}
		}
		while (count != 4)
		{
			for (int k = i; k < i + count; k++)
			{
				cards[k]--;
			}
			dfs(cards, 1 + sum);
			for (int k = i; k < i + count; k++)
			{
				cards[k]++;
			}
			count--;
		}
	}
}


int getAns(vector<int> &cards) {
	// Write your code here
}