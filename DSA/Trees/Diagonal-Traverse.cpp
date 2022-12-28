#include <iostream>
#include <queue>
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

void diagonal(Node*root){
	if(root==NULL){
		return;
	}
	Node*temp=root;
	queue<Node*> q;
	
	while(!q.empty() || temp!=NULL){
		
		if(temp!=NULL){
			cout<<temp->data<<" ";
		
		//Store Left and continue with right.
		  if(temp->left!=NULL)
			q.push(temp->left);
			temp=temp->right;
		
	}
		//If null=temp,then store it and pop resp.
		else{
			temp=q.front();
			q.pop();
		}
	}
}


 int main(){
 
	Node*root=new Node(1);
	root->left=new Node(2); 
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	diagonal(root);
	return 0;
}
