#include <iostream>
#include <stdio.h>
#include "bits/stdc++.h"

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

		 //inorder==LVR
		 //preorder==VLR
		 //postorder==LRV
void preorder(struct Node*root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
	
}


void inorder(struct Node*root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	
}


void postorder(struct Node*root){
	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
	

}


Node* search(Node* root,int find){

	if(root==NULL){
	   return NULL;	
	}
	
	if(root->data==find){
	   return root;	
	}
	
	if(root->data<find){
		return search(root->right,find);
	}
	return search(root->left,find);
}

Node*inorderSuc(Node*root){
	Node*curr=root;
	while(curr && curr->left !=NULL){
		curr=curr->left;
	}
	return curr;
}


Node* deletebst(Node*root,int key){
	
	if(key<root->data){
		root->left=deletebst(root->left,key);
	}
	
	else if(key>root->data){
		root->right=deletebst(root->right,key);
	}
	
	else{
		if(root->left==NULL){
		 	Node*temp=root->right;
		 	free(root);
		 	return temp;
		}
		else if(root->left==NULL){
		 	Node*temp=root->right;
		 	free(root);
		 	return temp;
		}
		
		Node*temp=inorderSuc(root->right);
		root->data=temp->data;
		root->right=deletebst(root->right,temp->data);
	}
	return root;
}


 int main(){
 
	Node*root=new Node(1);
	root->left=new Node(2); 
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	
//	preorder(root);
//	cout<<endl
//	postorder(root);
//	cout<<endl
	inorder(root);
	cout<<endl;
	root=deletebst(root,5);
	inorder(root);
	cout<<endl;
	return 0;
}
