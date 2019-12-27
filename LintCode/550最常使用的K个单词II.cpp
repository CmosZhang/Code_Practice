#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<map>

using namespace std;

//550. 最常使用的K个单词II
//
map<string, int> words;
class cmp {
public:
	bool operator () (const string& a, const string& b) {
		int a_count = words[a];
		int b_count = words[b];
		if (a_count != b_count)
			return a_count > b_count;
		return a < b;
	}
};

class TopK {
private:
	set<string, cmp> q;
	int k;
public:
	TopK(int k) {
		// initialize your data structure here
		this->k = k;
	}

	void add(string& word) {
		// Write your code here
		if (words.find(word) == words.end()) {
			words[word] = 1;
		}
		else {
			if (q.find(word) != q.end())
				q.erase(q.find(word));
			words[word] += 1;
		}
		q.insert(word);
		if (q.size() > k)
			q.erase(--q.end());
	}

	vector<string> topk() {
		// Write your code here
		vector<string> topk;
		set<string, cmp>::iterator it = q.begin();
		int i = 0;
		for (int i = 0; i < k && it != q.end(); ++i, ++it) {
			topk.push_back(*it);
		}
		return topk;
	}
};