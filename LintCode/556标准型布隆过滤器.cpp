#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<bitset>
#include<unordered_map>

using namespace std;
//
////556. ��׼�Ͳ�¡������
////����Ҫ�ȴ�������hash��������������һ���ַ����ֽ⣬Ȼ������������������
////�����ύ����� 93.29% ���ύ!
//class HashClass
//{
//public:
//	HashClass(int c, int s) :cap(c), seed(s) {}
//	int Hashfunc(string &value)
//	{
//		int ret = 0;
//		for (int i = 0; i < value.size(); i++)
//		{
//			ret += seed * ret + value[i];
//			ret %= cap;
//		}
//		return ret;
//	}
//private:
//	int cap, seed;
//};
//
//
//
//class StandardBloomFilter {
//public:
//	/*
//	* @param k: An integer
//	*/StandardBloomFilter(int k) {
//	// do intialization if necessary
//	this->k = k;
//	for (int i = 0; i < k; ++i) {
//		hashVec.push_back(new HashClass(100000 + i, 2 * i + 3));
//	}
//}
//
//	  /*
//	   * @param word: A string
//	   * @return: nothing
//	   */
//	  void add(string &word) {
//		  // write your code here
//		  for (int i = 0; i < k; ++i) {
//			  bits.set(hashVec[i]->Hashfunc(word));
//		  }
//	  }
//
//	  /*
//	   * @param word: A string
//	   * @return: True if contains word
//	   */
//	  bool contains(string &word) {
//		  // write your code here
//		  for (int i = 0; i < k; ++i) {
//			  if (!bits[hashVec[i]->Hashfunc(word)])
//				  return false;
//		  }
//		  return true;
//	  }
//private:
//	int k;
//	vector<HashClass *> hashVec;
//	bitset<200000> bits;
//
//};


//�������ϵ�java����𰸣�����������Ŀ
//���ǽ�java����ת��ΪC++����
class StandardBloomFilter {
private:
	map<string, int> hashmap;
public:
	/*
	* @param k: An integer
	*/StandardBloomFilter(int k) {
	// do intialization if necessary
}

	  /*
	   * @param word: A string
	   * @return: nothing
	   */
	  void add(string &word) {
		  // write your code here
		  
	  }

	  /*
	   * @param word: A string
	   * @return: True if contains word
	   */
	  bool contains(string &word) {
		  // write your code here
	  }
};