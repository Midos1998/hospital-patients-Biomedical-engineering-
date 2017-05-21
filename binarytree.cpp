#include"binarytree.h"
#include<iostream>
using namespace std;

BinaryTree::BinaryTree()
{
root=NULL;
}
BinaryTree::~BinaryTree()
{
remove(getmin());
}

void BinaryTree::print(int decider){
    ofstream file;
    file.open("data.csv");
    file<<"ID,Age,Name,Medicine\n";
print(root,decider,file);
file.close();

}
void BinaryTree::print(TreeNode* subtree,int decider,ofstream& file){
    if(decider==0){
    if(subtree!=NULL){
    print(subtree->left,decider,file);
    cout<<subtree->data<<","<<subtree->age<<","<<subtree->name<<","<<"drugs :";
    for(int i=0;i<subtree->num_of_drugs;i++){
        cout<<" "<<subtree->drugs[i];
    }
    cout<<endl;
    print(subtree->right,decider,file);
   }
}
    else{
        if(subtree!=NULL&&root!=NULL){
        print(subtree->left,decider,file);
        file<<subtree->data<<","<<subtree->age<<","<<subtree->name;
        for(int i=0;i<subtree->num_of_drugs;i++){
            if(i==0)file<<","<<subtree->drugs[i];
            else file<<"-"<<subtree->drugs[i];
        }
        file<<"\n";
        print(subtree->right,decider,file);

    }
}
}

void BinaryTree::add(int code,int age,string name,string* drugs,int nodrugs){
    add(root,code,age,name,drugs,nodrugs);

}
void BinaryTree::add(TreeNode*& node,int code,int age,string name,string* drugs,int n){
    if(node==NULL){
       node=new TreeNode();
       node->data=code;
       node->age=age;
       node->name=name;
       for(int i=0;i<n;i++){
           node->drugs[i]=drugs[i];
           node->num_of_drugs++;
       }
       node->num_of_drugs--;
    }else if(code<node->data){
        add(node->left,code,age,name,drugs,n);
    }else if(code>node->data){
        add(node->right,code,age,name,drugs,n);
    }

}
int BinaryTree::getmin(){
    if(root==NULL){
    }else{
        getmin(root);
    }
}
int BinaryTree::getmin(TreeNode* node){

     if(node->left==NULL){
        return node->data;
    }else{
        getmin(node->left);
    }

}

void BinaryTree::remove(int code){
remove(root,code);

}
void BinaryTree::remove(TreeNode*& node ,int code){
if(node==NULL){
//nothing happens :: not found
}else if(code<node->data){
    remove(node->left,code);
}else if(code>node->data){
    remove(node->right,code);
}else{
    TreeNode* trash=NULL;
    if(node->left==NULL && node->right==NULL){
        //case 1: leaf
        trash=node;
        node=NULL;
    }else if(node->right==NULL){
        //case 2: left child only
        trash=node;
        node=node->left;
    }else if(node->left==NULL){
        //case 3: right child only
        trash=node;
        node=node->right;
    }else{
        //case 4 : L&R subtrees
        int newData=getmin(node->right);
        node->data=newData;
        remove(node->right,newData);
    }
    if(trash!=NULL){
        delete trash;
    }
}

}

TreeNode* BinaryTree::search(int code){
return search(root,code);
}

TreeNode* BinaryTree::search(TreeNode* node, int code){
    if(node==NULL){//nothing found exhausted all the tree
        return NULL;
    }else if(node->data==code){//am the not itself
        return node;
    }
    else{//i have to go either left or right
       if(code<node->data){//go left
           search(node->left,code);
       }else{
           search(node->right,code);//go right
       }

    }

}
