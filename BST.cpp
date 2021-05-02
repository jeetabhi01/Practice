#include<bits/stdc++.h>
#include"Bst.h"

bool Search(BinaryTreeNode<int> * ,int);
BinaryTreeNode<int> * takeinputlevelwise();
void PrintBtreelevelwise(BinaryTreeNode<int> *);
bool isBST(BinaryTreeNode<int> * );
int maximum(BinaryTreeNode<int> *);
int minimum(BinaryTreeNode<int> *);
BinaryTreeNode<int> * Insertbst(BinaryTreeNode<int> * , int);



class Isbstreturn{
	public:
	bool bst;
	int max;
	int min;
};

signed main(){
	class Bst a ;
	a.Insertinbst(0);
	a.Insertinbst(93);
	a.Insertinbst(-12);
	a.Insertinbst(38);
	PrintBtreelevelwise(a.getroot());
	std::cout<<"Why waiting for an input\n";
	a.Deleteinbst(0);
	PrintBtreelevelwise(a.getroot());

    return 0 ;
}
// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1


void PrintBtreelevelwise(BinaryTreeNode<int> * root ){
    if(root == NULL)
    return;
    std::queue<BinaryTreeNode<int> *> pendingnodes;
    
    pendingnodes.push(root);
    while(!pendingnodes.empty()){
        auto front = pendingnodes.front();
        pendingnodes.pop();
        std::cout<<front->data<<": ";
        if(front->left!= NULL){
        std::cout<<front->left->data<<"L, ";
        pendingnodes.push(front->left);
        if(front->right!=NULL){
            std::cout<<front->right->data<<"R ";
            pendingnodes.push(front->right);
            }
        std::cout<<std::endl;
        }
    }
    return;
}

bool Search(BinaryTreeNode<int> * root, int n){
    if(root==NULL){
        return  false;
    }
	bool ans;
	if(n == root->data)
	return true;

	else if(n < root->data){
	ans = Search(root->left,n);
	}

	else
	ans = Search(root->right, n);
	return ans ;
	
}

bool isBST(BinaryTreeNode<int> * root){
	if(root==NULL)
	return true;
	
	int maximumleft = maximum(root->left);
	int minimumright = minimum(root->right);

	bool output = (root->data > maximumleft) && (root->data <= minimumright) && (isBST(root->left)) &&(isBST(root->right));
	return output;
}

int maximum(BinaryTreeNode<int> * root ){
	if(root == NULL)
	return INT_MIN;
	return std::max(root->data, std::max(maximum(root->left),maximum(root->right)));
}

int minimum(BinaryTreeNode<int> * root){
	if(root==NULL)
	return INT_MAX;
	return std::min(root->data,std::min(minimum(root->left),minimum(root->right)));
}

Isbstreturn isbst2(BinaryTreeNode<int> * root){
	if(root==NULL){
	Isbstreturn output;
	output.bst = true;
	output.max = INT_MIN;
	output.min = INT_MAX;
	return output;
	}

	Isbstreturn leftoutput,rightoutput;
	leftoutput = isbst2(root->left);
	rightoutput = isbst2(root->right);
	int minimum = std::min(root->data,std::min(rightoutput.min,leftoutput.min));
	int maximum = std::max(root->data,std::max(leftoutput.max, rightoutput.max));

	bool isbstfinal = (root->data >	leftoutput.max) && (root->data <= rightoutput.min) && (leftoutput.bst) && (rightoutput.bst);
	Isbstreturn output ; 
	output.min = minimum;
	output.min = maximum; 
	output.bst = isbstfinal;
	return output;
}

