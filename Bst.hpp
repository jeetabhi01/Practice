#include<iostream> 
#include"BinaryTreeNode.h"
 
class Bst{
    private:
        BinaryTreeNode<int> * root ;
    
        bool hasdata(int data, BinaryTreeNode<int> * node){
            if(node==NULL)
            return false;
            else if(node->data == data)
            return true;
            else if(node->data > data)
            return hasdata(data, node->left);
            else
            return hasdata(data,node->right);
        }
        BinaryTreeNode<int> * Insertinbst(int data, BinaryTreeNode<int> * node){
            if(node == NULL){
            BinaryTreeNode<int> * new_node = new BinaryTreeNode<int> (data);
            return new_node;    
            }
            else if(node->data > data){
             node->left = Insertinbst(data,node->left);
                // return node;
            }
            else{
            node->right = Insertinbst(data, node->right);
            // return node;
            }
            return node;
        }

        BinaryTreeNode<int> * Deleteinbst(int data, BinaryTreeNode<int> * node){
            if(node == NULL)
            return NULL;
            else if(node->data >  data){
            node->left = Deleteinbst(data, node->left);
            return node;
            }
            else if(node->data < data){
                node->right = Deleteinbst(data, node->right);
            }
            else{
                if(node->right == NULL && node->left == NULL){
                    delete node;
                    return NULL;
                }
                else if(node->left == NULL){
                    BinaryTreeNode<int> * temp = node->right;
                    delete node;
                    return temp;
                }
                else if(node->right == NULL){
                    BinaryTreeNode<int> * temp = node->left ;
                    delete node;
                    return temp;
                }     
                else{
                    BinaryTreeNode<int> * minimumright = node->right;
                    while(minimumright->left != NULL)
                        minimumright = minimumright->left;
                    int mindata = minimumright->data;
                    node->data = mindata;
                    node->right = Deleteinbst(mindata, node->right);
                    return node; 
                }     
            }
            return node;
        }
    public:
        Bst(){
            this->root = NULL;
        }
        ~Bst(){
            delete root;
        }
        bool hasdata(int data){
            return hasdata(data, root);
        }
        void Insertinbst(int data){
            root = Insertinbst(data,root);
        }
        void Deleteinbst(int data){
            root = Deleteinbst(data, root);
        }
        BinaryTreeNode<int> * getroot(){
            return this->root;
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

};