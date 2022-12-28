#include <iostream>
#include <queue>
#include<stack>
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


void reversee(Node*root){
		stack<Node*> s;
		queue<Node*> q;
		q.push(root);
		

		  while(!q.empty()){
       		root = q.front();
       		 q.pop();
       		 s.push(root);
            
            if(root->right){
                q.push(root->right);
            }
            
            if(root->left){
                q.push(root->left);
            }
        }
        //to check if level left or not.
       while(!s.empty()){
       		root=s.top();
       		cout<<root->data<<" ";
       		s.pop();
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
	reversee(root);
	return 0;
}
