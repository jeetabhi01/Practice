#include<iostream>
#include<queue>
#include"BinaryTreeNode.h"

void PrintBtree(BinaryTreeNode<int> * );
BinaryTreeNode<int> * takeinput();
void PrintBtreelevelwise(BinaryTreeNode<int> * );
BinaryTreeNode<int> * takeinputlevelwise();
std::vector<int>* roottonode(BinaryTreeNode<int> * , int ); 
int main(){
	// auto root = takeinput();
	auto root = takeinputlevelwise();
	PrintBtree(root);
}

BinaryTreeNode<int> * takeinput(){
	std::cout<<"Enter the data "<<std::endl;
	int rootdata;
	std::cin>>rootdata;
	if (rootdata == -1)
	return NULL;
	BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootdata);
	root->left = takeinput();
	root->right = takeinput();

	return root;

}

void PrintBtree(BinaryTreeNode<int> * root){
	if(root==NULL)
	return;
	std::cout<<root->data<<": ";
	if(root->left!= NULL)
	std::cout<<root->left->data<<"L, ";
	if(root->right != NULL)
	std::cout<<root->right->data<<"R ";
	std::cout<<std::endl;
	PrintBtree(root->left);
	PrintBtree(root->right);
}

BinaryTreeNode<int> * takeinputlevelwise(){
	int rootdata; 
	std::cout<<"Enter the data \n";
	std::cin>>rootdata;
	if(rootdata == -1)
	return NULL;
	std::queue<BinaryTreeNode<int> * > pendingnodes;
	auto root = new BinaryTreeNode<int> (rootdata);
	pendingnodes.push(root);
	while(!pendingnodes.empty()){
		auto front = pendingnodes.front();
		pendingnodes.pop();
		std::cout<<"Enter the left child of the node "<<front->data<<std::endl;
		int leftchild;
		std::cin>>leftchild;
		if(leftchild!=-1){
			auto left = new BinaryTreeNode<int> (leftchild);
			pendingnodes.push(left);
			front->left = left;
		}
		int rightchild;
		std::cout<<"Enter the right child of the node "<<front->data<<std::endl;
		std::cin>>rightchild;
		if(rightchild != -1){
			auto right = new BinaryTreeNode<int>(rightchild);
			pendingnodes.push(right);
			front->right = right;
		}

	}
	return root;
}

std::vector<int>* roottonode(BinaryTreeNode<int> * root, int data){
	if(root== NULL)
	return NULL;

	else if(root->data== data){
	std::vector<int> * path = new std::vector<int> ();
	path->push_back(root->data);
	return path;
	}

	std::vector<int> * leftoutput = roottonode(root->left,data);
	if(leftoutput!=NULL){
	leftoutput->push_back(root->data);
	return leftoutput;
	}

	std::vector<int> * rightoutput = roottonode(root->right, data);	
	if(rightoutput!=NULL){
		rightoutput->push_back(root->data);
		return rightoutput;
	}
	else
	return NULL;

}
