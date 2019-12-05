#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//227. 用栈模拟汉诺塔问题
class Tower {
private:
	stack<int> disks;
public:
	/*
	* @param i: An integer from 0 to 2
	*/
	Tower(int i)
	{
		// create three towers
	}

	/*
	* @param d: An integer
	* @return: nothing
	*/
	void add(int d) 
	{
		// Add a disk into this tower
		if (!disks.empty() && disks.top() <= d) 
		{
			printf("Error placing disk %d", d);
		}
		else 
		{
			disks.push(d);
		}
	}

	/*
	* @param t: a tower
	* @return: nothing
	*/
	void moveTopTo(Tower &t) 
	{
		// Move the top disk of this tower to the top of t.
	}

	/*
	* @param n: An integer
	* @param destination: a tower
	* @param buffer: a tower
	* @return: nothing
	*/
	void moveDisks(int n, Tower &destination, Tower &buffer)
	{
		// Move n Disks from this tower to destination by buffer tower
	}

	/*
	* @return: Disks
	*/
	stack<int> getDisks()
	{
		// write your code here
		return disks;
	}
};
