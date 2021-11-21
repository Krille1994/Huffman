#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <bitset>


struct Node
{
	char value = 'æ';
	int weight;
	Node* child0 = nullptr;
	Node* child1 = nullptr;
	Node(char c, int w) : value(c), weight(w) {};
	Node(int w, Node* n0, Node* n1) : weight(w), child0(n0), child1(n1) {};
};

class Compare
{
public:
	bool operator() (Node* l, Node* r)
	{
		return l->weight > r->weight;
	}
};

class Tree
{
private:
	std::vector<std::string> v_file_data;
	Node* p_root = nullptr;
	std::priority_queue<Node*, std::vector<Node*>, Compare> v_queue;
	std::vector<Node*> v_nodes;
	std::vector<Node*> v_transfer_nodes;
	std::map<char, std::string> m_translation;
	std::vector<bool> v_bits;


	int NumberOfNodes = 0;
	void AddNode(char c);
	void SearchNode(Node* current, std::string path);
	std::string CreateTransferrableTree();
	std::string CreateTransferTranslateFunction();

public:
	void AddFileData(std::string);
	void CreateLeafNodes();
	void CreateQueue();
	void CreateTree();
	void CreateTranslationMap();
	void CreateBits();
	std::string CreateTextFromBits();
	void AddToResultFile(std::string result_path);
	


	void PrintResults()
	{
		std::cout << "Results\n\n";
		size_t file_size = 0;
		size_t bit_size = v_bits.size();
		for (std::string& file : v_file_data)
		{
			file_size += file.size()*8;
		}
		std::cout << file_size << "/" << bit_size << " = " << file_size - bit_size << "\n\n";
		

	}
};

