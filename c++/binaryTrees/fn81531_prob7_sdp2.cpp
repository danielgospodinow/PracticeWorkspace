/////////////////////////////////////////////////////////////
//
// Author: ������ ����������
// FN: 81531
// Date: 21.01.2018
//

///
/// ���������, �������� ����� � ������� �����
///

#include <string>
#include <iostream>
#include <algorithm>
#include <set>

struct Node
{
	Node(char d, Node* l = nullptr, Node* r = nullptr):
		data(d), left(l), right(r)
	{

	}

	char data;
	Node *left, *right;
};

void sortStr(std::string& str)
{
	if (str == "")
		return;

	std::sort(str.begin(), str.end());
}

std::string getSmallerChars(std::string const& str, char m)
{
	std::string ret = "";
	std::set<char> strSet;

	for (int i = 0; i < str.length(); ++i)
	{
		if (strSet.count(str[i]) == 0 && str[i] < m)
		{
			ret += str[i];
			strSet.insert(str[i]);
		}
	}

	sortStr(ret);
	return ret;
}

std::string getBiggerChars(std::string const& str, char m)
{
	std::string ret = "";
	std::set<char> strSet;

	for (int i = 0; i < str.length(); ++i)
	{
		if (strSet.count(str[i]) == 0 && str[i] > m)
		{
			ret += str[i];
			strSet.insert(str[i]);
		}
	}

	sortStr(ret);
	return ret;
}


Node* buildTree(std::string s)
{
	if (s == "" || s.length() <= 0)
		return nullptr;

	char middleChar = s[s.length() / 2];
	std::string leftStr = getSmallerChars(s, middleChar);
	std::string rightStr = getBiggerChars(s, middleChar);

	return new Node(middleChar, buildTree(leftStr), buildTree(rightStr));
}

void printTree(Node* const& root)
{
	if(!root)
	{
		std::cout << "null";
		return;
	}

	std::cout << root->data;
	std::cout << "(";
	printTree(root->left);
	std::cout << "|";
	printTree(root->right);
	std::cout << ")";
}

int main() 
{
	Node* testTree = buildTree("zazxxxcyc");
	printTree(testTree);
	std::cout << std::endl;

	return 0;
}