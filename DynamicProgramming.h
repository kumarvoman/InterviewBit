#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;
int val(int A)
{
	if (A == 1)
		return 1;
	if (A == 2)
		return 2;
	return val(A - 1) + val(A - 2)*(A - 1);
}

int letsparty(int A)
{
	cout << val(A);
	vector<int> res;
	res.push_back(0);
	res.push_back(1);
	res.push_back(2);
	for (int i = 3; i <= A; i++)
	{
		int val = res[i - 1] + res[i - 2] * (i - 1);
		res.push_back(val);
	}

	int val = res[A] % 10003;
	return val;
}

int minNoOfSquares(int A)
{
	int count = 0;
	int root = 0;
	while (A > 3)
	{
		root = sqrt(A);
		int diff = A - root*root;
		count++;
		if (diff <= 3)
		{
			root = diff;
			break;
		}			
		else
			A = diff;
	}
	return count + root;
}