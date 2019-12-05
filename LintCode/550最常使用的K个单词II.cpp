#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;

//550. 最常使用的K个单词II
//
class TopK 
{
	private:
		int count;
		priority_queue<pair<string,int>> q;
		public:
		/*
		* @param k: An integer
		*/

		TopK(int k) 
		{
			// do intialization if necessary
			count = k;
		}

		/*
		* @param word: A string
		* @return: nothing
		*/
		void add(string &word) 
		{
			// write your code here



		}

		/*
		* @return: the current top k frequent words.
		*/
		vector<string> topk() 
		{
			// write your code here





		}
};