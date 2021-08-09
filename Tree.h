#pragma once
#pragma region Tree
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <stack>

using namespace std;
const long long int mod = 10000000007;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//deserialize binary tree-scaler
TreeNode* createTree(vector<int> A)
{
	vector<TreeNode*> res;
	res.push_back(NULL);
	queue < TreeNode * > q;
	if (A.size() > 0)
	{
		TreeNode *curr = NULL;
		for (auto x : A)
		{
			TreeNode *temp = new TreeNode(x);
			if (curr == NULL)
				curr = temp;
			else if (curr->left == NULL && (x != -1))
				curr->left = new TreeNode(x);
			else if (curr->right == NULL && (x != -1))
				curr->right = new TreeNode(x);


			if (x != -1)
				q.push(temp);

			if (curr->left != NULL && curr->right != NULL)
			{
				res.push_back(curr);
				q.pop();
				if (!q.empty())
					curr = q.front();
			}
		}


		for (int i = 1; i < res.size() / 2; i++)
		{
			if (res[i]->left->val == res[2 * i]->val)
				res[i]->left = res[2 * i];
			if (res[i]->right->val == res[2 * i + 1]->val)
				res[i]->right = res[2 * i + 1];
		}
	}
	return res[1];
}

TreeNode* deSerializeBinaryTree(vector<int> A)
{
	queue < TreeNode * > q;
	TreeNode *node = new TreeNode(A[0]);
	q.push(node);

	for (int i = 1; i < A.size() - 2; i += 2)
	{
		TreeNode* curr = q.front();
		if (i % 2 == 1)
		{
			if (A[i] != -1)
			{
				curr->left = new TreeNode(A[i]);
				q.push(curr->left);
			}
			if (A[i + 1] != -1)
			{
				curr->right = new TreeNode(A[i + 1]);
				q.push(curr->right);
			}
		}

		q.pop();
		curr = q.front();
	}
	return node;
}

vector<vector<int>> verticalOrderTraversal(TreeNode* root)
{
	vector<vector<int>> res;
	unordered_map<int, vector<int>> hash;
	queue<pair<TreeNode*, int>> q;
	q.push(pair<TreeNode*, int>(root, 0));
	hash[0].push_back(root->val);

	int min = 0, max = 0;
	while (!q.empty())
	{
		pair<TreeNode*, int> curr = q.front();
		if (curr.first->left != NULL)
		{
			min = (min > curr.second - 1) ? curr.second - 1 : min;
			q.push(pair<TreeNode*, int>(curr.first->left, curr.second - 1));
			hash[curr.second - 1].push_back(curr.first->left->val);
		}
		if (curr.first->right != NULL)
		{
			max = (max < curr.second + 1) ? curr.second + 1 : max;
			q.push(pair<TreeNode*, int>(curr.first->right, curr.second + 1));
			hash[curr.second + 1].push_back(curr.first->right->val);
		}
		q.pop();
	}

	for (int i = min; i <= max; i++)
		res.push_back(hash[i]);

	return res;
}


TreeNode* find_lca(TreeNode* root, int a, int b)
{
	if (!root)
		return NULL;
	if (root->val == a || root->val == b)
		return root;

	TreeNode *left = NULL, *right = NULL;

	left = find_lca(root->left, a, b);
	if(left)
	cout << "left : " << left->val << endl;
	right = find_lca(root->right, a, b);
	if(right)
	cout << "right : " << right->val << endl;

	if (left && right)
		return root;
	else
		return (left) ? left : right;
}

void findlcaRnr()
{
	int arr[] = { 16,23,9,-1,1,22,2,25,19,6,13,-1,24,14,-1,30,4,26,29,-1,-1,-1,-1,-1,3,-1,8,-1,-1,12,18,28,-1,10,-1,5,-1,17,11,21,7,-1,-1,-1,20,-1,-1,-1,-1,-1,15,-1,-1,-1,-1,-1,-1,-1,27,-1,-1};
	vector<int> A(begin(arr), end(arr));

	TreeNode* root = createTree(A);

	TreeNode* lca = find_lca(root, 32, 24);
	cout << lca->val;

}

void dfs(TreeNode *root, string path)
{
	if (!root)
		return;
	path += std::to_string(root->val);
	cout << path << endl;
	dfs(root->left, path);
	dfs(root->right, path);
	path.resize(path.size() - 1);
}


void printLeftView(TreeNode* root)
{
	cout << "Left View : ";
	queue<TreeNode*> store;
	store.push(root);
	while (!store.empty())
	{
		int len = store.size();
		for (int i = 1; i <= len;i++)
		{
			auto x = store.front();
			if (1 == i)
				cout << x->val;
			if(x->left)
				store.push(x->left);
			if(x->right)
				store.push(x->right);
			store.pop();
		}	
	}
}


void printRightView(TreeNode* root)
{
	cout << "\nRight View: ";
	queue<TreeNode*> store;
	store.push(root);
	while (!store.empty())
	{
		int len = store.size();
		for (int i = 1; i <= len; i++)
		{
			auto x = store.front();
			if (i == len)
				cout << x->val;
			if (x->left)
				store.push(x->left);
			if (x->right)
				store.push(x->right);
			store.pop();
		}
	}
}

void TreeViewRnr()
{
	int arr[] = { 1, 2, 3, 4, 5,6,7 };
	vector<int> vec(begin(arr), end(arr));
	
	printLeftView(createTree(vec));
	printRightView(createTree(vec));
	verticalOrderTraversal(createTree(vec));
	cout << "";
}





#pragma endregion