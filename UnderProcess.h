#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <bitset>

using namespace std;
//const long long int mod = 10000000007;

#pragma region UnderProcess
vector<int> sortArrinGivenOrder(vector<int> &A, vector<int> &B) {
	vector<int> result;
	unordered_map<int, int> hash;
	for (auto x : B)
	{
		if (std::find(A.begin(), A.end(), x) != A.end())
		{
			hash[x]++;
		}
	}

	vector<int> sorted;
	vector<int> mapped;
	for (int i = 0; i < A.size(); i++)
	{
		if (hash.find(A[i]) == hash.end())
			sorted.push_back(A[i]);
		else
			mapped.push_back(A[i]);
	}

	sort(sorted.begin(), sorted.end());

	result = mapped;
	for (int i = 0; i < sorted.size(); i++)
		result.push_back(sorted[i]);

	return result;

}

int sumofmaxandmin(vector<int> A, int B)
{
	int sum = 0;
	int min = A[0], max = A[0];
	for (int i = 0; i < B; i++)
	{
		min = (min > A[i]) ? A[i] : min;
		max = (max < A[i]) ? A[i] : max;
	}

	int curr = 1;
	while (curr < A.size() - B)
	{
		if (A[curr - 1] != min && A[curr - 1] != max)
		{
			cout << "";
		}
	}
	return sum;
}



//a is x and B is y
int Points_on_same_line(vector<int> &A, vector<int> &B)
{
	unordered_map<int, int> hash;
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < A.size() && j != i; j++)
		{
			if (B[i] == B[j])
				continue;
			int m = abs((A[i] - A[j]) / (B[i] - B[j]));
			hash[m]++;
		}
	}

	int max = 0;
	for (auto x : hash)
		max = (max < x.second) ? x.second : max;

	if (max <= 1)
		return 2;
	return max;
}



int candy(vector<int> &A) {
	int n = A.size();
	if (n < 2)
		return n;
	vector<int> dp(n, 1);
	for (int i = 1; i < n; i++)
	{
		if (A[i] > A[i - 1])
			dp[i] = 1 + dp[i - 1];
	}

	int ans = dp[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		if (A[i] > A[i + 1])
		{
			dp[i] = max(dp[i], 1 + dp[i + 1]);
		}
		ans += dp[i];
	}
	return ans;
}



void subarray(vector<int> A, int index, vector<vector<int>> *res)
{
	for (int i = 1; i < A.size(); i++)
	{
		//vector<int> temp;
		for (int j = 0; j < i; j++) {
			cout << A[j] << " ";
		}
		cout << endl;
		//res->push_back(temp);
	}
}

vector<vector<int>> getAllSubarrays(vector<int> A)
{
	vector<vector<int>> result;
	subarray(A, 0, &result);
	return result;
}

vector<vector<int>> getAllSubSequences(vector<int> A)
{
	vector<vector<int>> result;

	return result;
}

void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs)
{
	subs.push_back(sub);
	for (int j = i; j < nums.size(); j++)
	{
		sub.push_back(nums[j]);
		subsets(nums, j + 1, sub, subs);
		sub.pop_back();
	}
}

/* Recursive way to get susbsets*/
vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> subs;
	vector<int> sub;
	subsets(nums, 0, sub, subs);
	return subs;
}



//Iterative way to create subset
vector<vector<int>> getAllSubsets(vector<int> A)
{
	vector<vector<int>> subs = { {} };
	for (int num : A) {
		int n = subs.size();
		for (int i = 0; i < n; i++) {
			subs.push_back(subs[i]);
			subs.back().push_back(num);
		}
	}
	return subs;
}

vector<int> beggars(int A, vector<vector<int>>B)
{
	vector<int> res;
	res.resize(A);

	for (int i = 0; i < B.size(); i++)
	{
		for (int j = B[i][0]; j <= B[i][1]; j++)
		{
			res[j] += B[i][2];
		}
	}
	return res;

	vector<int> coins(A, 0);
	for (int i = 0; i < B.size(); i++)
	{
		int leftIndex = B[i][0] - 1, rightIndex = B[i][1] - 1;
		int donationByDevotee = B[i][2];
		coins[leftIndex] += donationByDevotee;
		if ((rightIndex + 1) < A) coins[rightIndex + 1] -= donationByDevotee;
	}
	for (int i = 1; i < A; i++) coins[i] = coins[i] + coins[i - 1];
	return coins;
}


//subset of an arr
vector<vector<int>> subsetOfAnArr(vector<int> ar)
{
	vector<vector<int>> res;
	int N = pow(2, ar.size());
	for (int i = 0; i < N; i++)
	{
		vector<int> temp;
		for (int j = 0; j < ar.size(); j++)
		{
			if (i & (1 << j))
			{
				temp.push_back(ar[j]);
			}
		}
		res.push_back(temp);
	}

	return res;
}

void printSubsequences(vector<int> arr, int index, vector<int> *subarr)
{
	if (index == arr.size())
	{
		int l = subarr->size();
		if (l != 0)
		{
			for (int i = 0; i < l; i++)
				cout << arr[i] << " ";
			cout << endl;
		}
	}
	else
	{
		printSubsequences(arr, index + 1, subarr);
		subarr->push_back(arr[index]);
		printSubsequences(arr, index + 1, subarr);
	}
	return;
}



//Done
int minDiffPuzzle()
{
	int arr[] = { 66, 23, 687, 252, 187, 114, 789, 527, 129, 474, 679, 119, 687, 92, 578, 332, 781, 499, 597, 370, 848, 248, 496, 641, 714, 572, 399, 187, 910, 638, 100, 975, 660, 786, 227, 198, 252, 367, 725 };
	vector<int> A(begin(arr), end(arr));
	int B = 29;

	sort(A.begin(), A.end());

	int diff = INT_MAX;
	for (int i = 0; B + i - 1 < A.size() - B; i++)
	{
		int temp = A[B + i - 1] - A[i];
		if (temp < diff)
			diff = temp;
	}
	return diff;
}

//done
int sInterleave(string A, string B, string C) {
	const int n = A.length(); int m = B.length(); int k = C.length();
	if (n + m != k)
		return false;
	
	vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 && j == 0)
				dp[i][j] = true;
			else if (i == 0 && B[j] == C[i + j])
				dp[i][j] = dp[i][j];
			else if (j == 0 && A[i] == C[i + j])
				dp[i][j] = dp[i][j];
			else if (A[i] == C[i + j] && B[j] != C[i + j])
				dp[i][j] = dp[i][j];
			else if (A[i] != C[i + j] && B[j] == C[i + j])
				dp[i][j] = dp[i][j - 1];
			else if (A[i] == C[i + j] && B[j] == C[i + j])
				dp[i][j] = (dp[i][j] || dp[i][j]);
		}
	}
	return 	dp[n - 1][m - 1];
}

vector<int> constructArray(const int A, const int B, const int C) {
	vector<int> res(A);
	res[A-1] = C;
	int diff = floor(C / A);
	while ((C-B) % diff != 0)
	{
		diff--;
	}	

	if (A > 2)
	{	
		for (int i = A-1; i >=0; i--)
		{
			if (i == A - 1)
				res[i] = C;
			else
				res[i] = C - diff * i;
		}
	}
	else
	{
		res[0] = B;		
	}
	return res;
}



vector<vector<int>> xorQueries(vector<int> A, vector<vector<int>> queries);
void XORQueries(vector<int> &arr, vector<vector<int> > &queries);
void xorQueryRnr()
{
	int arr[] = { 1,0,0,0,1 };
	vector<int> A(begin(arr), end(arr));

	vector<vector<int>> queries;
	vector<int> temp;
	temp.push_back(2);
	temp.push_back(4);
	queries.push_back(temp);

	temp.clear();
	temp.push_back(1);
	temp.push_back(5);
	queries.push_back(temp);

	temp.clear();
	temp.push_back(3);
	temp.push_back(5);
	queries.push_back(temp);

	XORQueries(A, queries);
}

//BRUTE force - TLE
vector<vector<int>> xorQueries(vector<int> A, vector<vector<int>> queries)
{
	vector<vector<int>> ans;
	for (int i = 0; i < queries.size(); i++)
	{
		vector<int> temp;
		int start = queries[i][0];
		int end = queries[i][1];
		int ones = 0, zeroes = 0;
		for (int j = start-1; j < end; j++)
		{
			ones ^= A[j];
			if (0 == A[j])
				zeroes++;
		}

		temp.push_back(ones);
		temp.push_back(zeroes);
		ans.push_back(temp);
	}
	return ans;
}

//Optimized - Done
void XORQueries(vector<int> &arr, vector<vector<int> > &queries)
{
	vector<vector<int>> ans;
	vector<int> prefix_xor(arr.size()+1);
	prefix_xor[0] = arr[0];
	for (int i = 1; i <= arr.size(); i++)
	{
		prefix_xor[i] = prefix_xor[i - 1] + arr[i - 1];
	}
	
	for (int i = 0; i < queries.size(); i++)
	{
		vector<int> temp;
		int left = queries[i][0];
		int right = queries[i][1];

		int cntOnes = prefix_xor[right];
		if (left - 1 >= 0)
			cntOnes -= prefix_xor[left - 1];

		int zero = (right - left + 1) - cntOnes;
		if (cntOnes % 2 == 0)
			temp.push_back(0);
		else
			temp.push_back(1);
		temp.push_back(zero);
		ans.push_back(temp);
	}
}

//TLE
vector<int> N_integers_containing_only_123(int A)
{
	vector<int> res;
	int count = 1;
	while (res.size() < A)
	{
		int len = floor(log10(count) + 1);
		if (count < 3)
			res.push_back(count);
		else
		{
			/*int val = count;
			int temp = val % 10;
			bool bAdd = false;
			while (temp != 0)
			{
				if (temp > 0 && temp <= 3)
				{
					val = val / 10;
					temp = val % 10;
					bAdd = true;
					len--;
				}
				else
				{
					bAdd = false;
					break;
				}
			}
			if (true == bAdd && len == 0)*/
				res.push_back(count);
		}
		if (res.size() % (27 * 3*3) == 0)
			count += 77777;
		else if (res.size() % (27 * 3) == 0)
			count += 7777;
		else if (res.size() % 27 ==0)
			count += 777;
		else if (res.size() % 12 == 0)
			count += 77;
		else if (count % 10 == 3)
			count += 7;
		count++;
	}
	return res;
}


vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
	int freq[101] = { 0 };

	for (int i = 0; i < nums.size(); i++)
		freq[nums[i]]++;

	for (int i = 1; i < 101; i++)
		freq[i] += freq[i - 1];

	for (int i = 0; i < nums.size(); i++)
		nums[i] = nums[i] != 0 ? freq[nums[i] - 1] : 0;

	return nums;
}

//brute force - TLE
int subArrOr(vector<int> A)
{
	for (int k = 1; k <= 5; k++)
	{
		for (int i = 1; i <= 5; i++)
		{
			int sum = 0;
			for (int j = k; j <= i; j++)
			{
				cout << j << " ";
				sum = sum | j;
			}
			cout << " - sum: " << sum << endl;
		}
	}
	return 0;
}

///Optimized- gettung TLE
int SubArrOR(vector<int> A)
{
	/*vector<int> pre;
	pre.push_back(A[0]);
	for (int i = 1; i < A.size(); i++)
	{
		int val = pre[i-1] | A[i];
		pre.push_back(val);
	}*/

	const unsigned int M = 1000000007;
	unsigned long long int sum = 0, sum1 = 0;

	int n = A.size();
	for (int i = 0; i < n; i++)
	{
		sum1 = 0;
		for (int j = i; j < n; j++)
		{
			cout << A[j];
			sum1 = (sum1 | A[j]);
			sum = sum + sum1;
		}
		cout << " :: sum : " << sum << endl;
	}
	return sum % M;
}

//aaaabbbbccccaaaabbbbcc

//aaabacaaabac


void stringperiod(string A) {
	//int pos = 0, max = 0;
	//unordered_map<char, int> hash;
	int k = 1;
	int pos = 1;
	for (int i = 1; i < A.size(); i++)
	{
		if (A[i] != A[i%k])
		{
			if (k == pos)
				k++;
			else
				k = pos+1;
		}			
		pos++;
	}
	//if (A[A.size()] != A[(A.size())%k])
	//	k = A.size();
	cout << k;
}

std::string r = "";
std::string toBinary(int n)
{
	r = (n % 2 == 0 ? "0" : "1") + r;
	if (n / 2 != 0) {
		toBinary(n / 2);
	}
	return r;
}

int bobQuery()
{
	vector<int> res;
	vector<int> A(28, 0);
	int x = 0, y = 0, z = 0;
	for (int i = 0; i < 12; i++)
	{
		if (i == 0)
		{
			x = 1, y = 22, z = -1;
		}
		else
		{
			x = 3, y = 1, z = 27;
		}
		switch (x)
		{
		case 1:
			A[y] = 2 * A[y] + 1;
			break;
		case 2:
			A[y] = floor(A[y] / 2);
			break;
		case 3:
			string str = "";
			r = "";
			for (int j = y; j <= z; j++)
			{
				if (A[j] != 0)
					str += toBinary(A[j]);
			}
			int count = 0;
			for (int j = 0; j < str.length(); j++)
			{
				if (str[j] == '1')
					count++;
			}
			res.push_back(count);
			break;
		}
	}
	return 0;
}

int maxAndmin()
{
	int arr[] = { 4, 7, 3, 8 };
	vector<int> A(begin(arr), end(arr));
	
	int sum = 0;
	int n = A.size();
	for (int j = 2; j < A.size(); j++)
	{
		
	}
	return sum;
}

void getallsubseq(vector<int> arr, vector<vector<int>>* subseq)
{
	for (int i = 1; i <= arr.size(); i++) //size
	{
		vector<int> temp;
		for (int j = 0; j < i; j++)
		{
			temp.push_back(arr[j]);
		}
		subseq->push_back(temp);
	}
}

void getAllSubArrIteratively(vector<int> A, vector<vector<int>>* subseq)
{
	for (int i = 1; i < A.size(); i++)
	{
		for (int j = 0; j < A.size(); j++)
		{
			vector<int> temp;
			for (int k = 0; k <= i; k++)
			{
				temp.push_back(A[k]);
			}
			subseq->push_back(temp);
		}
	}
}

//recursive way to get all subarrays
void getAllSubArraysRecursively(vector<int> arr, int start, int end, vector<vector<int>>* subarr)
{
	if (end == arr.size())
		return;
	else if (start > end)
		getAllSubArraysRecursively(arr, 0, end + 1, subarr);
	else
	{
		vector<int> temp;
		for (int i = start; i <= end; i++)
			temp.push_back(arr[i]);
		subarr->push_back(temp);
		getAllSubArraysRecursively(arr, start + 1, end, subarr);
	}
	return;
}

int kadane(vector<int> A) // maxSubArraySum
{
	int n = A.size();
	int max_so_far = INT_MIN, max_ending_here = 0;
	for (int i = 0; i < n; i++)
	{
		max_ending_here = max_ending_here + A[i];
		if (max_so_far < max_ending_here)
			max_so_far = max_ending_here;

		if (max_ending_here < 0)
			max_ending_here = 0;
	}
	return max_so_far;
}
void largestSubarray()
{
	int arr[] = { 0,1,0,0,0,1,0,0,1,0,0,0,0,1,1 };
	vector<int> A(begin(arr), end(arr));

	int start = 0, end = 0, len = 0, maxlen = 0;
	if (A[0] == 0)
	{
		maxlen = 1;
	}

	for (int i = 1; i < A.size(); i++)
	{
		if (A[i] != A[i - 1])
		{
			if (0 == A[i])
			{
				start = i;
				end = i;
			}
			else if (A[i] == 1)
			{
				end = i;
			}
			len = end - start;
			if (len > maxlen)
				maxlen = len;
		}
	}
	if (end == start)
		len = A.size() - start;
	if (maxlen < len)
		maxlen = len;
	cout << maxlen;
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, b%a);
}
int largestSubArrWithGcdK()
{
	int arr[] = { 8, 16, 4, 12,6,9 };
	vector<int> A(begin(arr), end(arr));

	vector<int> processed;
	int curr = A[0];
	for (int i = 1; i < A.size(); i++)
	{
		curr = gcd(A[i], curr);
		processed.push_back(curr);
	}
	cout << "hello";
	return 0;
}

vector<int> KMP_prefix_function(string Z) {

	int n = (int)Z.length();
	vector<int> prefix(n);
	prefix[0] = 0;
	for (int i = 1; i < n; ++i)
	{
		int j = prefix[i - 1];
		while (j > 0 && Z[i] != Z[j])
			j = prefix[j - 1];

		if (Z[i] == Z[j])
			++j;
		prefix[i] = j;
	}
	return prefix;
}

/*
This fucntion uses kmp search algo to find patterns in given string
*/

void KMPSearch(string pattern, string text)
{
	vector<int> pref = KMP_prefix_function(text);
	int len = text.length();
	int j = 0, i = 0;
	while (i < len)
	{
		if (text[i] == pattern[j + 1])
		{
			i++;
			j++;
		}
		if (j == pattern.length())
		{
			cout << "pattern found at " << i - j - 1 << endl;
			break;
		}
		else if (text[i] != pattern[j + 1] && i < len)
		{
			if (j != 0)
				j = pref[j];
			else
				i++;
		}
	}
}

//Done TC: NK , SC: NK
int PermutationsOfAinB(string A, string B)
{
	int m = A.size();
	int n = B.length();
	unordered_map<char, int> ahash;
	unordered_map<char, int> bhash;

	for (auto x : A)
		ahash[x]++;
	
	for (int i = 0; i < m; i++)
		bhash[B[i]]++;
	
	int count = 0;
	int endpoint = n - ahash.size();
	int i = 0;
	while (i < endpoint)
	{
		int flag = true;
		for (auto x : ahash)
		{
			if (x.second != bhash[x.first])
			{
				flag = false;
				break;
			}
		}
		if (flag == true)
			count++;
		if (bhash[B[i]] > 1)
			bhash[B[i]]--;
		else
			bhash.erase(B[i]);
		bhash[B[m + i]]++;
		i++;
	}
	return count;
}

bool ColorfulNumber(int number)
{
	vector<int> subsequence;
	unordered_map<int, int> hash;
	bool bfirst = true;
	while (number != 0)
	{
		int res = number % 10;
		number = number / 10;
		subsequence.push_back(res);
		if (hash.find(res) == hash.end())
			hash[res]++;
		else
			return false;
	}

	for (int i = 0; i < subsequence.size(); i++)
	{
		int temp = subsequence[i];
		for (int j = i + 1; j < subsequence.size(); j++)
		{
			int val = temp * subsequence[j];
			if (hash.find(val) == hash.end())
			{
				hash[val]++;
				temp = val;
			}
			else
				return false;
		}
	}

	return true;
}

//not working in scaler
int maxAndMin(vector<int> A)
{
	const int mod = 1e9 + 7;
	int sum = 0;
	int min = INT_MAX, max = INT_MIN;
	for (int i = 0; i < A.size(); i++)
	{
		min = A[i];
		max = A[i];
		for (int j = i + 1; j < A.size(); j++)
		{
			min = (min > A[j]) ? A[j] : min;
			max = (max < A[j]) ? A[j] : max;
			cout <<"max : "<< max <<" min : "<< min << endl;
			sum += max - min;
		}
	}
	cout << sum % mod;
	return sum % mod;
}

#pragma endregion