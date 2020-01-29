#include<stdio.h> 
#include<stdlib.h>

#include "bstHeader.h"
	//Node creator
	Node* createNode(int value){
		Node* newNode = malloc(sizeof(Node));
		newNode->left =  NULL;
		newNode->right = NULL;
		newNode->data = value;
	
	return newNode;	
	}

	//The method that prints the tree inorder
	void inorder(Node* root){
		if(root != NULL){
			inorder(root->left);
			printf("%d -> ", root->data);
			inorder(root->right);
		}	
	}

	//The method which inserts a node for given data
	Node* insert(Node* root,int data){
	
		if(root == NULL){
			Node* newNode = createNode(data);
			root = newNode;	
		}
		else{
			if(data > root->data)
				root->right = insert(root->right,data);
			else	
				root->left = insert(root->left,data);
			
		}	
		return root;
	}
	//The method which searches and returns how many step taken to find the node stores given data
	int counter = 1;
	int search(Node* root, int data){ 
		if(root == NULL)
			return -1;
		if(root != NULL){
			if(data == root->data){
			int temp = counter;
			counter =1;
			return temp;
			}	
			else if(data > root->data){
				counter++;	
				return search(root->right,data);
			}
				
			else if(data < root->data){
				counter++;
				return search(root->left,data);
			}				
		}
		return counter;
	}		
	//The method which finds the node stores minimum element of tree
	Node* minValueNode(Node* node){
		Node* currentNode = node;
		if(node != NULL){
			while(currentNode->left != NULL){
				currentNode = currentNode->left;
			}
			if(currentNode->right != NULL)
				minValueNode(currentNode->right);
			return currentNode;
		}
		return node;
	}
	//The method which deletes the node stores given data
	Node* deleteNode(Node* root, int data){
		if(root==NULL)
			return root;		
		if(root != NULL){
			if(data > root->data){
				root->right = deleteNode(root->right,data);
				}
				
			else if(data < root->data)
				root->left = deleteNode(root->left,data);				
	/*means found*/	else{ 
				if(root->right == NULL)
					return root->left;
				else if( root->left == NULL )
					return root->right;					
				Node* temp = minValueNode(root->right);
				root->data=temp->data;
				root->right = deleteNode(root->right,temp->data);
			}	
		}					
	return root;	
}



