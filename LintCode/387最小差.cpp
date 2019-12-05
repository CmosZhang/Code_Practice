#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

//387. 最小差
//您的提交打败了 84.80% 的提交!
int smallestDifference(vector<int> &A, vector<int> &B) {
	// write your code here
	if (A.empty() || B.empty())
	{
		return -1;
	}
	int dif = INT_MAX;
	int Alen = A.size();
	int Blen = B.size();
	//暴力方法
	//暴力求解时间复杂度太高，达不到要求 ,算法复杂度为O(Alen*Blen)
	//for (int i = 0; i < Alen; i++)
	//{
	//	for (int j = 0; j < Blen; j++)
	//	{
	//		int temp = abs(B[j] - A[i]);
	//		dif = min(dif, temp);
	//	}
	//}
	//return dif;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	for (int i = 0, j = 0; i < Alen&&j < Blen;)
	{
		dif = min(dif, abs(A[i] - B[j]));
		if (A[i] < B[j])
		{
			i++;
		}
		else
		{
			j++;
		}
	}
	return dif;
}


//int main()
//{
//	vector<int> A = {1,2,3,4 };
//	vector<int> B = { 7,6,5};
//	cout << smallestDifference(A, B) << endl;
//	system("pause");
//	return 0;
//}

