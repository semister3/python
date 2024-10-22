#include <iostream>
#include <stdlib.h>
using namespace std;
int chc , val , nodes[20] , i;
struct node{
	int value;
	struct node *leftChild , *rightChild;
};
struct node *root = NULL;
void menu();
struct node *createNode(struct node *root , int value){
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode -> leftChild = NULL;
	newNode -> rightChild = NULL;
	newNode -> value = value;
	if(root == NULL){
		root = newNode;
	}else if(value > root -> value){
		root -> rightChild = newNode;
	}
	else if(value < root -> value){
		root -> leftChild = newNode;
	}
	return newNode;
}
void inorderTraversal(struct node *root){
	if(root == NULL){
		return;
	}
	inorderTraversal(root -> leftChild);
	cout<<root -> value<<" ";
	inorderTraversal(root -> rightChild);
}
void menu(){
	do{
		system("cls");
		cout<<"\t\tBinary Tree\n1 ] Create Tree\n2 ] Display(inorder)\n3 ] Exit\n\nChoice >>> ";
		cin>>chc;
		system("cls");
		switch(chc){
			case 1 :
				cout<<"\nTotal Node : ";
				cin>>val;
				for(i = 0 ; i < val ; i++){
					cout<<"Node "<<i + 1<<" : ";
					cin>>nodes[i];
				}
				root = createNode(root , nodes[0]);
				for(i = 1 ; i < val ; i++){
					createNode(root , nodes[i]);
				}
				cout<<"\nTree Successfully created";
				break;
			case 2 :
				inorderTraversal(root);
				break;
			case 3 :
				exit(0);
		}
		cout<<"\nDo you want to continue ?\n[ 1 ] Yes\t\t[ 2 ] No\nChoice >>> ";
		cin>>chc;
	}while(chc != 2);
}
int main(){
	menu();
}
