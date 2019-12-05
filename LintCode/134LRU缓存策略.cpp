#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//134. LRU�������
//90%����ͨ������,����ʱ������
//ÿ�ζ�Ҫ����ջ��Ȼ������ջ֮��������㣬��ʱ�ϳ���
//leetcode��Ҳ��ͨ��17/18.
class LRUCache 
{
	public:
		struct Data
		{
			int key;
			int value;
		};
		stack<Data> LRUdata;
		stack<Data> helpstack;
		int size;

	public:
		/*
		* @param capacity: An integer
		*/LRUCache(int capacity)
	     {
	 	  // do intialization if necessary
			size = capacity;
	     }

		  /*
		  * @param key: An integer
		  * @return: An integer
		  */
		  int get(int key) 
		  {
			  // write your code here
			  //�ҵ���Ԫ�أ�����Ԫ�طŵ�ջ����
			  Data top;
			  bool flag = false;
			  while (!LRUdata.empty())
			  {
				  top = LRUdata.top();
				  if (top.key == key)
				  {
					  LRUdata.pop();
					  flag = true;
					  break;
				  }
				  helpstack.push(top);
				  LRUdata.pop();
			  }
			  while (!helpstack.empty())
			  {
				  LRUdata.push(helpstack.top());
				  helpstack.pop();
			  }
			  if (flag == false)
			  {
				  return -1;
			  }
			  else
			  {
				  LRUdata.push(top);
				  return top.value;
			  }
			//  cout << LRUdata.top().key << endl;
		  }

		  /*
		  * @param key: An integer
		  * @param value: An integer
		  * @return: nothing
		  */
		  void set(int key, int value)
		  {
			  // write your code here
			  Data temp;
			  temp.key = key;
			  temp.value = value;
			  
			  if (LRUdata.empty())
			  {
				  LRUdata.push(temp);
				  return;
			  }
			  //�ȼ��ջ���Ƿ������һ����ֵ
			  //��������ڣ��Ҽ�������ݣ�����size,��ջ��Ԫ��ɾ����
			  int flag = get(temp.key);
			  if (flag == -1)
			  {
				  if (LRUdata.size() < size)
				  {
					  LRUdata.push(temp);
				  }
				  else
				  {
					  while (!LRUdata.empty())
					  {
						  if (LRUdata.size() == 1)
						  {
							  LRUdata.pop();
							  break;
						  }
						  helpstack.push(LRUdata.top());
						  LRUdata.pop();
					  }
					  while (!helpstack.empty())
					  {
						  LRUdata.push(helpstack.top());
						  helpstack.pop();
					  }
					  LRUdata.push(temp);
					  cout << LRUdata.top().key<< endl;
				  }
			  }
			  else
			  {//������ڣ�Ҫ����valueֵ
					Data top;
					while (!LRUdata.empty())
					{
						top = LRUdata.top();
						if (top.key == key)
						{
							LRUdata.pop();
							top.value = temp.value;
							break;
						}
						helpstack.push(top);
						LRUdata.pop();
					}
					while (!helpstack.empty())
					{
						LRUdata.push(helpstack.top());
						helpstack.pop();
					}
					LRUdata.push(top);
			  }
		  }
};


int main()
{
	LRUCache LRUCache(10);
	LRUCache.set(7, 28);
	LRUCache.set(7, 1);
	LRUCache.set(8, 15);
	cout << LRUCache.get(6) << endl;
	LRUCache.set(10, 27);
	LRUCache.set(8, 10);
	cout << LRUCache.get(8) << endl;
	LRUCache.set(6, 29);
	LRUCache.set(1, 9);
	cout << LRUCache.get(6) << endl;
	LRUCache.set(10, 7);
	cout << LRUCache.get(1) << endl;
	cout << LRUCache.get(2) << endl;
	cout << LRUCache.get(13) << endl;
	LRUCache.set(8, 30);
	LRUCache.set(1, 5);
	cout << LRUCache.get(1) << endl;
	LRUCache.set(13, 2);
	cout << LRUCache.get(12) << endl;
	system("pause");
	return 0;
}