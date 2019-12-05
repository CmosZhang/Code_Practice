#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<iterator>

using namespace std;

//交集
void Intersect(const vector<int>& A, const vector<int>& B, vector<int>& ans)
{
	map<int, int> Counter;
	const int ASize = A.size(), BSize = B.size();
	for (int i = 0; i < ASize; ++i)
		Counter[A[i]] = 1;
	for (int i = 0; i < BSize; ++i)
	{
		if (Counter.count(B[i]))
			Counter[B[i]] = 2;
	}
	map<int, int>::iterator it;
	for (it = Counter.begin(); it != Counter.end(); ++it)
	{
		if (it->second == 2)
			ans.push_back(it->first);
	}
}

//并集：
void Union(const vector<int>& A, const vector<int>& B, vector<int>& ans)
{
	set<int> Exist;
	Exist.insert(A.begin(), A.end());
	Exist.insert(B.begin(), B.end());
	set<int>::iterator it;
	for (it = Exist.begin(); it != Exist.end(); ++it)
		ans.push_back(*it);
}

//差集：
void Difference(const vector<int>& A, const vector<int>& B, vector<int>& ans)
{
	set<int> Unique;
	Unique.insert(A.begin(), A.end());
	const int BSize = B.size();
	for (int i = 0; i < BSize; ++i)
		Unique.erase(B[i]);//删除在B中也存在的元素
	set<int>::iterator it;
	for (it = Unique.begin(); it != Unique.end(); ++it)
		ans.push_back(*it);
}


//简单测试代码：
int main() {
	int a[] = { 1,2,3,4,5,5,4,3,2,1,6,8,10,9,7 };
	int b[] = { 2,2,4,4,8,8,6,6,2,4,6,8 };
	vector<int> AVec(a, a + sizeof(a) / sizeof(int));
	vector<int> BVec(b, b + sizeof(b) / sizeof(int));
	vector<int> ans;
	cout << "A:\t";
	copy(AVec.begin(), AVec.end(), ostream_iterator<int>(cout, " "));
	cout << "\nB:\t";
	copy(BVec.begin(), BVec.end(), ostream_iterator<int>(cout, " "));
	Intersect(AVec, BVec, ans);
	cout << "\nA Intersect B:\n";
	copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
	ans.clear();
	Union(AVec, BVec, ans);
	cout << "\nA Union B:\n";
	copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
	ans.clear();
	Difference(AVec, BVec, ans);
	cout << "\nA - B:\n";
	copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " "));
	system("pause");
	return 0;
}