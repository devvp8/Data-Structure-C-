#include <iostream>

using namespace std;

class Node{
	public:
	int data;
	Node*left,*right;
	
	Node(int val){
		data=val;
		left=NULL;
		right=NULL;
	}
};


int calHeight(Node*root){
	if(root==NULL){
		return 0;
	}
	return max(calHeight(root->left),calHeight(root->right))+1;
}

int calDiameter(Node*root){
	if(root==NULL){
		return 0;
	}
	int lheight=calHeight(root->left);
	int rheight=calHeight(root->right);
	int currdiameter=lheight+rheight+1;
	
	int ldia=calDiameter(root->left);
	int rdia=calDiameter(root->right);
	
	return max(currdiameter,max(ldia,rdia));
	
}



 int main(){
 
	Node*root=new Node(1);
	root->left=new Node(2); 
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	
	cout<<calDiameter(root)<<endl;
	cout<<calHeight(root);
	
	return 0;
}
