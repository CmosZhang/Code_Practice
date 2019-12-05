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
			return a.first < b.first;//��Ƶ�ν���Ϊ����
		}
		else
			return a.second > b.second;//����ĸ����Ϊ�ֵ���
	}
};

//471. ���Ƶ��K������
//�����ύ����� 31.60% ���ύ!
//Խ��Ƶ�Ĵ�����Խǰ�档����������ʳ��ֵĴ�����ͬ����ʵ���С������ǰ�档
vector<string> topKFrequentWords(vector<string> &words, int k) 
{
	// write your code here
	if (words.empty())
		return words;
	vector<string> res;
	if (k <= 0)
		return res;
	//�淶k��ֵ
	if (k > words.size())
		k = words.size();

	map<string, int> m;//����ַ���������ִ���
	priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> que;//������������Ķ�
	for (auto c : words)
		m[c]++;
	//�����е��ַ���,���ִ����������
	//���ѣ��Ѿ���һ������Ĺ�������
	for (auto t : m)
	{
		pair<int, string> temp = make_pair(t.second, t.first);
		que.push(temp);
	}
	//��Ѷ���ǰk��ֵ
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