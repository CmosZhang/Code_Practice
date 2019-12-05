#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class ListNode
{
public:
	int val;
	ListNode *next;
	ListNode(int val)
	{
		this->val = val;
		this->next = NULL;
	}
};

int hashcode(int key, int capacity)
{
	return key % capacity;
}

void addlistnode(ListNode *node, int num)
{
	if (node->next != NULL)
	{
		addlistnode(node->next, num);
	}
	else
	{
		node->next = new ListNode(num);
	}
}


void addnode(vector<ListNode*>&res, int num)
{
	int index = (num + res.size()) % res.size();
	if (res[index] == NULL)
	{
		res[index] = new ListNode(num);
	}
	else
	{
		addlistnode(res[index], num);
	}
}


//您的提交打败了 57.20% 的提交!
vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
	// write your code here
	if (hashTable.empty())
	{
		return hashTable;
	}
	//重哈希后的结果
	vector<ListNode*> res(2 * hashTable.size(), NULL);
	int hash_size = 2 * hashTable.size();
	for (int i = 0; i < hashTable.size(); i++)
	{
		ListNode *p = hashTable[i];
		while (p != NULL)
		{
			addnode(res, p->val);
			p = p->next;
		}
	}
	return res;
}

