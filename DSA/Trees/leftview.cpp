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

void leftView(Node*root){
	if(root==NULL){
		return;
	}
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	
 cout << root->data << " ";

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        if(curr != NULL){

            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
        // Traverse next level
        else if(!q.empty()){
            cout << q.front()->data << " ";
            q.push(NULL);
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
	
	cout<<endl;
	
	leftView(root);
	return 0;
}
