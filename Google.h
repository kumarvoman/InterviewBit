#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using std::string;
using std::stack;

void minSequenceOfSizeKwithMaxValue(string str, int k)
{
	int len = str.length();
	stack<int> store;
	int s = str[0]-48;
	store.push(s);
	for (int i = 1; i < len; i++)
	{
		int x = store.top();
		while (x < str[i]-48 && (len - i + store.size() > k))
		{
			store.pop();
			if (!store.empty())
				x = store.top();
			else
				break;
		}
		store.push(str[i]-48);
	}

	cout << "result is : ";
	vector<int> res;
	while (!store.empty())
	{
		res.push_back(store.top());
		store.pop();
	}
	sort(res.rbegin(), res.rend());
	for (int i = 0; i < k; i++)
	{
		cout << res[i];
	}
	cout << endl;
}

void removeAandDoubleB(string str)
{

}
