#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct TreeNode{
    int data;
    int age;
    string drugs[5];
    string name;
    TreeNode* left;
    TreeNode* right;
    int num_of_drugs=0;
};

class BinaryTree
{
public:
    BinaryTree();
    ~BinaryTree();

void add(int,int,string,string*,int);
void print(int decider);
bool contains();
void remove(int value);
int getmin();
TreeNode* search(int code);

private:

TreeNode* root;
void add(TreeNode*& node,int code,int age,string name,string* drugs,int);
void print(TreeNode* subtree,int decider,ofstream& file);
int getmin(TreeNode* node);
void remove(TreeNode*& node,int value);
TreeNode* search(TreeNode*,int code);
};

#endif // BINARYTREE_H
