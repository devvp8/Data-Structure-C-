#include <iostream>
#include <queue>
using namespace std;

struct Node{
	int data;
	Node*left,*right;
	
	Node(int val){
		data=val;
		left=NULL;
		right=NULL;
	}
};

void levelOrder(Node*root){
	if(root==NULL){
		return;
	}
		queue<Node*> q;
		q.push(root);
		q.push(NULL);
		
		  while(!q.empty()){
       		 Node* curr = q.front();
       		 q.pop();
       		 
        	 if(curr != NULL){
			cout<<curr->data<<" ";
			
            if(curr->left){
                q.push(curr->left);
            }
            
            if(curr->right){
                q.push(curr->right);
            }
        }
        else if(!q.empty()){
        	q.push(NULL);
		}
        
	}


 int main()
 
 	
	Node*root=new Node(1);
	root->left=new Node(2); 
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	levelOrder(root);
	return 0;

