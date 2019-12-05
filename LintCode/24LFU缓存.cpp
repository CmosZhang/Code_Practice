#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>

using namespace std;

//24. LFU缓存
//您的提交打败了 73.60% 的提交!
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
			  //假如存在这个key
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
			  // 不存在此 key
			  if (cache.count(key) == 0)
			  {
				  return -1;
			  }
			  // 更新 cache
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