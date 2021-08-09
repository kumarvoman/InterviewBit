#pragma once

#pragma region CompletedCode
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;
const long long int mod = 10000000007;


//class A
//{
//private:
//
//protected:
//
//public:
//	int x;
//	int y;
//	void fun()
//	{
//		cout << "varsha";
//
//	}
//	void fun(string p)
//	{
//		cout << p;
//
//	}
//	void fun(int p)
//	{
//		x = p;
//
//
//	}
//
//};

int getDistintCount(vector<int> A, int B)
{
	int count = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (B < A[i])
			return count;
		B -= A[i];
		count++;
	}

	return count;
}

int taskScheduling(vector<int> A, vector<int> B)
{
	int count = 0;
	queue<int> store;
	for (auto x : A)
		store.push(x);

	for (auto x : B)
	{
		while (x != store.front())
		{
			int temp = store.front();
			store.pop();
			store.push(temp);
			count++;
		}
		count++;
		store.pop();
	}
	cout << count;
	return count;
}

vector<int> slidingMaximum(const vector<int> &A, int B) {
	vector<int> result;
	for (int i = 0; i <= A.size() - B; i++)
	{
		int max = A[i];
		for (int j = i; j < A.size(); j++)
		{
			if (max < A[j])
				max = A[j];
		}
		result.push_back(max);
	}
	return result;
}

int pair_with_given_Sum_II(vector<int> A, int B)
{
	int val = 0;

	//make a separate vector of elements with no duplicates
	// and a hash where store the frequencies of duplicates
	//where a+b=sum.. just add the x*y frequencies to ans and increment i= i+x and j=j+y
	vector<int> ar;
	ar.push_back(A[0]);
	for (int i = 1; i < A.size(); i++)
	{
		if (A[i - 1] != A[i])
			ar.push_back(A[i]);
	}

	unordered_map<int, int> hash;
	for (auto x : A)
		hash[x]++;
	//1, 1, 1, 2, 2, 3, 4, 5, 6, 7, 8, 9 --------- 2
	int i = 0;
	auto  j = A.size() - 1;
	while (i < j)
	{
		if (A[i] + A[j] == B)
		{
			/*int x = hash[A[i]];
			int y = hash[A[j]];

			val += x * y;*/
			int y = hash[A[j]];
			if (y > 1 && A[i] != A[j])
				val += y;
			else
				val++;
		}

		if (A[i] + A[j] > B)
			j--;
		else
			i++;
	}
	return val;
}


int pairwithgivensumII(vector<int> A, int B)
{
	int i = 0, j = i + 1;
	int count = 0;
	auto n = A.size();

	unordered_map<int, int> hash;
	for (auto k : A)
		hash[k]++;


	for (int i = 0; i < n; i++)
	{
		auto itr = hash.find(B - A[i]);
		if (itr != hash.end())
		{
			int x = itr->second;
			int y = hash[A[i]];
			if (A[i] == A[j])
				count += (x*(y - 1) / 2);
			else
				count += x * y;
			i += y - 1;
		}
	}

	while (i < n - 1)
	{

		int sum = A[i] + A[j];
		if (sum == B)
		{
			int x = hash[A[i]];
			int y = hash[A[j]];
			if (A[i] == A[j])
			{
				/*if (x == 2)
					x = 1;
				y = 1;*/
				int sc = x * (y - 1) / 2;
				count += sc;
			}
			else
				count += x * y;
			i += x;
			j = i + 1;
		}
		if (i >= n)
			break;
		if (sum < B)
			j++;
		if (sum > B || j >= n)
		{
			i++;
			j = i + 1;
		}

	}
	return count;
	/*
	 1, 2, 6, 6, 7, 9, 9 B=13 - op -2 correct

	1,1,1,2,3,3,4,5,6,6,7,8   B=9 - 9 correct

	1, 1, 3, 3, 5, 5, 6, 6, 6, 9, 10  B=9 - op -6 correct

	2, 2, 3, 4, 4, 5, 6, 7, 10    B =8 op:4

1+8 => 1*3 + 8*1 => 3*1 = 3
2+7 => 2*1 + 7*1 => 1*1 = 1
3+6 => 3*2 + 6*2 => 2*2 = 4
4+5 => 4*1 + 5*1 => 1*1 = 1
---------------------------
9
	*/
}

vector<int> littleponnyandmobilephone(vector<int> A, vector<int> B)
{
	vector<int> distintPhoneperQuery;

	//use binary search
	vector<int> prefixSum;
	vector<int> result;
	int sum = 0;
	for (auto x : A)
	{
		sum += x;
		prefixSum.push_back(sum);
	}

	int i = 0;
	auto j = A.size() - 1;
	int mid = (i + j) / 2;
	for (auto x : B)
	{
		if (x < A[mid])
		{
			mid--;
		}
		else if (x > A[mid])
		{
			mid++;

		}
		else
			result.push_back(mid);
		if (mid == 0)
			result.push_back(0);

	}
	return result;

	//this logic works- but partial correct - TLE
	for (int i = 0; i < B.size(); i++)
	{
		int count = 0;
		for (int j = 0; j < A.size(); j++)
		{
			if (B[i] < A[j])
				break;
			B[i] -= A[j];
			count++;
		}
		distintPhoneperQuery.push_back(count);
	}
	return distintPhoneperQuery;
}

int searchinmnMatrix(vector<vector<int>> A, int B)
{
	int rowid = 0;
	auto n = A[0].size();
	for (int i = 0; i < n; i++)
	{
		if (A[i][n - 1] > B)
		{
			rowid = i;
			break;
		}
	}


	int val = rowid * 1009;
	for (int j = 1; j < A[rowid].size(); j++)
		if (A[rowid][j] == B)
			cout << val + j;

	return -1;
}

#pragma endregion


