#include "Tree.h"

#include <fstream>


// private functions

void Tree::AddNode(char c)
{
	bool hasNode = false;
	for (Node* n : v_nodes)
	{
		if (n->value == c)
		{
			n->weight++;
			hasNode = true;
			break;
		}
	}
	if (!hasNode)
	{
		v_nodes.push_back(new Node(c, 1));
		NumberOfNodes++;
	}
}

void Tree::SearchNode(Node* current, std::string path)
{
	if (current->value != 'æ')
	{
		m_translation.insert(std::make_pair(current->value, path));
	}
	else
	{
		SearchNode(current->child0, path + "0");
		SearchNode(current->child1, path + "1");
	}
}
std::string Tree::CreateTransferrableTree()
{
	std::string strTree = "struct Node\n{\n    char value;\n	u8_t child0;\n	u8_t child1;\n    Node(char c):value(c);\n    Node(n0,n1):child0(n0), child1(n1);\n};";
	std::string strTreeVector = "inline std::vector<Node> v_tree {";

	for (int i = 0; i < v_transfer_nodes.size(); i++)
	{
		std::string strNode = "Node(";
		if (v_transfer_nodes.at(i)->value == 'æ')
		{
			auto it = std::find(v_transfer_nodes.begin(), v_transfer_nodes.end(), v_transfer_nodes.at(i)->child0);
			int index = it - v_transfer_nodes.begin();
			strNode += std::to_string(index) + ",";
			it = std::find(v_transfer_nodes.begin(), v_transfer_nodes.end(), v_transfer_nodes.at(i)->child1);
			index = it - v_transfer_nodes.begin();
			strNode += std::to_string(index) + "),";
		}
		else
		{
			strNode += "'";
			strNode += v_transfer_nodes.at(i)->value;
			strNode += "'),";
		}
		strTreeVector += strNode;
	}
	strTreeVector += "};";
	auto it = std::find(v_transfer_nodes.begin(), v_transfer_nodes.end(), p_root);
	int root_index = it - v_transfer_nodes.begin();

	strTree += strTreeVector;
	strTree += "\n\ninline u8_t root_index " + std::to_string(root_index) + ";";
	return strTree;
}

std::string CreateTransferTranslateFunction()
{
	std::string strFunc = "std::string CreateString()\n{\n";

	return strFunc;
}




// Public functions

void Tree::AddFileData(std::string file_data)
{
	v_file_data.push_back(file_data);
}

void Tree::CreateLeafNodes()
{
	for (std::string file : v_file_data)
	{
		for (char c : file)
		{
			AddNode(c);
		}
	}
}

void Tree::CreateQueue()
{
	for (Node* n : v_nodes)
	{
		v_queue.push(n);
	}
}

void Tree::CreateTree()
{
	while (v_queue.size() > 1)
	{
		Node* n0 = v_queue.top();
		v_transfer_nodes.push_back(n0);
		v_queue.pop();
		Node* n1 = v_queue.top();
		v_transfer_nodes.push_back(n1);
		v_queue.pop();
		v_queue.push(new Node(n0->weight + n1->weight, n0, n1));
		NumberOfNodes++;
	}
	p_root = v_queue.top();
	v_transfer_nodes.push_back(p_root);
	v_queue.pop();
	std::cout << "Number of Nodes: " << NumberOfNodes << "\n";
}

void Tree::CreateTranslationMap()
{
	SearchNode(p_root, "");
}

void Tree::CreateBits()
{
	for (std::string file : v_file_data)
	{
		for (char c : file)
		{
			auto it = m_translation.find(c);

			if (it != m_translation.end())
			{
				for (char ch : it->second)
				{
					v_bits.push_back(ch == '1' ? true : false);
				}
			}
		}
	}
}
std::string Tree::CreateTextFromBits() // Not nessecary in this project
{
	Node* node = p_root;
	std::string strRetVal;
	for (bool b : v_bits)
	{
		if (node->value != 'æ')
		{
			strRetVal += node->value;
			node = p_root;
		}

		if (b) { node = node->child1; }
		else { node = node->child0; }
	}
	if (node->value != 'æ')
	{
		strRetVal += node->value;
	}
	return strRetVal;
}

void Tree::AddToResultFile(std::string result_path)
{
	std::ofstream result_file(result_path);
	result_file << "#include <bitset>\n\n\n";
	result_file << CreateTransferrableTree() << "\n\n";
	result_file << "inline std::bitset<" << v_bits.size() << "> my_bitset {";
	for (bool b : v_bits)
	{
		result_file << b << ",";
	}
	result_file << "};";

}