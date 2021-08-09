#pragma once
#include <unordered_map>

using namespace std;

class TrieNode
{
	char ch;
	unordered_map<char, TrieNode> *node;

public:
	void insert(string s);
};

void TrieNode::insert(string s)
{
	/*for each(char x in s)
	{
		ch = x;
		node[x, NULL];
	}*/
}
