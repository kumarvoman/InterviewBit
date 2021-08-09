#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

void heafn()
{
	//priority_queue<int> pq; //create a max-heap
	priority_queue <int, vector<int>, greater<int> > pq; // Creates a min heap
	pq.push(5);
	pq.push(2);
	pq.push(3);
	pq.push(4);
	pq.push(9);
	pq.push(6);
	pq.push(7);

	//make max heap frome a vector
	vector<int> A;
	make_heap(A.begin(), A.end());

	
	push_heap(A.begin(), A.end()); //to heapify the given heap
	
}


//struct TreeNode
//{
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}; 
//};


void insertInHeap(int x)
{
	
}

void upHeapify(TreeNode* curr)
{

}

void downHeapify(TreeNode* curr)
{

}

int connectRopes(vector<int> A)
{
	priority_queue <int, vector<int>, greater<int> > pq;
	for (auto x : A)
		pq.push(x);

	vector<int> res;

	int m1 = pq.top();
	int sum = 0;
	while (!pq.empty())
	{
		pq.pop();
		m1+= pq.top();
		res.push_back(m1);
		pq.pop();
		if (!pq.empty())
		{
			pq.push(m1);
			m1 = pq.top();
		}
		else
			break;
		
	}

	for (auto x : res)
		sum += x;
	return sum;
}

int Maximum_array_sum_after_B_negations(vector<int> A, int B)
{
	priority_queue <int, vector<int>, greater<int> > pq;
	for (auto x : A)
		pq.push(x);

	while (B)
	{
		int min = pq.top();
		pq.pop();
		pq.push(-1 * min);
		if ((min > 0) && (B%2 !=0))
		{
			break;
		}
		B--;
	}

	int sum = 0;
	while (pq.empty() == false)
	{
		sum += pq.top();
		pq.pop();
	}

	return sum;
}

vector<int> ProductOF3(vector<int> &A) {
	priority_queue<int> pq;
	vector<int> res;
	for (int i = 0; i < A.size();i++)
	{
		pq.push(A[i]);
		if (i < 2)
			res.push_back(-1);
		else
		{
			int m1 = pq.top();
			pq.pop();
			int m2 = pq.top();
			pq.pop();
			int m3 = pq.top();
			res.push_back(m1*m2*m3);
			pq.push(m1);
			pq.push(m2);
		}
	}
	return res;
}


int Magician_and_chocolate(int A, vector<int> &B)
{
	priority_queue<int> pq; //max heap
	for (auto x : B)
		pq.push(x);

	pq.push(4);
	push_heap(B.begin(), B.end());
	long long int sum = 0;
	while (A)
	{
		int temp = pq.top();
		sum += temp;
		pq.pop();
		temp = floor(temp / 2);
		pq.push(temp);
		A--;
	}
	const long long int mod = 1000000007;
	return sum % mod;
	//284628164
}

vector<int> AthLargestElement(int A, vector<int> &B)
{
	priority_queue<long long int, vector<long long int>, greater<long long int>> p; //min heap
	for (int i = 0; i < A; i++)
		p.push(B[i]);

	vector<int> res;
	for (int i = 1; i <= B.size(); i++)
	{
		if (i < A)
			res.push_back(-1);
		else
		{
			long long int val = p.top();
			res.push_back(val);
			if (val < B[i])
			{
				p.pop();
				p.push(B[i]);
			}
		}
	}
	return res;
}



struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeKLists(vector<ListNode*> &A) {
	priority_queue<int, vector<int>, greater<int>> pq;
	for (auto x : A)
	{
		ListNode* head = x;
		while (head != NULL)
		{
			pq.push(head->val);
			head = head->next;
		}
	}

	ListNode* head = new ListNode(pq.top());
	ListNode* root = head;
	pq.pop();
	while (!pq.empty())
	{
		head->next = new ListNode(pq.top());
		pq.pop();
		head = head->next;
	}
	return root;
}