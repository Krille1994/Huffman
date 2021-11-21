
#include <iostream>

#include "FileHandler.h"
#include "Tree.h"



int main()
{
	FileHandler file_handler;
	Tree tree;
	std::string chart;
	chart = file_handler.GetFileText("C:\\Users\\Krille\\Desktop\\Huffman\\Huffman_v2\\testJs\\chart.js");
	//chart = "elefantene";

	//std::cout << "\n\nOriginal "<< chart.size() <<"\n\n" << chart << "\n\n\n";

	tree.AddFileData(chart);
	tree.CreateLeafNodes();
	tree.CreateQueue();
	tree.CreateTree();
	tree.CreateTranslationMap();

	tree.CreateBits();
	tree.PrintResults();

	tree.AddToResultFile("C:\\Users\\Krille\\Desktop\\Huffman\\Huffman_endPoint\\ResultFile.h");

	//std::string chart2 = tree.CreateTextFromBits();

	//std::cout << "\n\n\n\nNew " << chart2.size() << "\n\n" << chart2;

	

}
