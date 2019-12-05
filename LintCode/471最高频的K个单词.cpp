#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <functional>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct cmp
{
	bool operator()(pair<int, string> a, pair<int, string> b)
	{
		if (a.first != b.first)
		{
			return a.first < b.first;//按频次降序，为最大堆
		}
		else
			return a.second > b.second;//按字母升序，为字典序
	}
};

//471. 最高频的K个单词
//您的提交打败了 31.60% 的提交!
//越高频的词排在越前面。如果两个单词出现的次数相同，则词典序小的排在前面。
vector<string> topKFrequentWords(vector<string> &words, int k) 
{
	// write your code here
	if (words.empty())
		return words;
	vector<string> res;
	if (k <= 0)
		return res;
	//规范k的值
	if (k > words.size())
		k = words.size();

	map<string, int> m;//存放字符串及其出现次数
	priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> que;//构建符合题意的堆
	for (auto c : words)
		m[c]++;
	//将所有的字符串,出现次数放入堆中
	//最大堆，已经有一个排序的过程啦。
	for (auto t : m)
	{
		pair<int, string> temp = make_pair(t.second, t.first);
		que.push(temp);
	}
	//求堆顶的前k个值
	for (int i = 0; i < k; ++i)
	{
		res.push_back(que.top().second);
		que.pop();
	}
	return res;
}

int main()
{
	vector<string> str = { "yes","lint","code","yes","code","baby","you","baby","chrome","safari","lint","code","body","lint","code" };
	int k = 3;
	vector<string> res = topKFrequentWords(str, k);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}