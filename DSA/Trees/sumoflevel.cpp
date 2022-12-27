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


int sum(Node*root,int k){
	if(root==NULL){
		return -1;
	}
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	int level=0;
	int sum=0;
	
	while(!q.empty()){
		Node*temp=q.front();
		q.pop();
		if(temp!=NULL){
			if(level==k){
				sum=sum+temp->data;
			}
			 if(temp->left){
                q.push(temp->left);
            }
            
            if(temp->right){
                q.push(temp->right);
            }
		}
		// Will check if level is remaining or not.
		else if(!q.empty()){
			q.push(NULL);
			level++;
		}
	}
	return sum;
}

 int main(){
 
	Node*root=new Node(1);
	root->left=new Node(2); 
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	
	cout<<sum(root,2);
	
	return 0;
}
