#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>

using namespace std;

//24. LFU����
//�����ύ����� 73.60% ���ύ!
class LFUCache
{
	public:
		int size;
		int minFreq;
		unordered_map<int, pair<int, int>> cache;
		unordered_map<int, list<int>> freq;
		unordered_map<int, list<int>::iterator> iter;
		public:
		/*
		* @param capacity: An integer
		*/ LFUCache(int capacity) 
		   {
		   // do intialization if necessary
				size = capacity;
		   }
		  /*
		  * @param key: An integer
		  * @param value: An integer
		  * @return: nothing
		  */
		  void set(int key, int value) 
		  {
			  // write your code here
			  if (size <= 0)
			  {
				  return;
			  }
			  //����������key
			  if (get(key) != -1)
			  {
				  cache[key].first = value;
				  return;
			  }
			  //
			  if (cache.size() >= size)
			  {
				  cache.erase(freq[minFreq].front());
				  iter.erase(freq[minFreq].front());
				  freq[minFreq].pop_front();
			  }
			  cache[key] = { value, 1 };
			  freq[1].push_back(key);
			  iter[key] = --freq[1].end();
			  minFreq = 1;
		  }

		  /*
		  * @param key: An integer
		  * @return: An integer
		  */
		  int get(int key) 
		  {
			  // write your code here
			  // �����ڴ� key
			  if (cache.count(key) == 0)
			  {
				  return -1;
			  }
			  // ���� cache
			  freq[cache[key].second].erase(iter[key]);
			  cache[key].second++;
			  freq[cache[key].second].push_back(key);
			  iter[key] = --freq[cache[key].second].end();
			  if (freq[minFreq].size() == 0) 
			  {
				  minFreq++;
			  }
			  return cache[key].first;
		  }
};