#include <iostream>
#include <stdlib.h>
using namespace std;
int chc , val , size , i;
struct node{
	int value;
	struct node *leftChild , *rightChild;
};
void menu();
struct node *createNode(int value){
	if(value == -1){
		return 0;
	}
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode -> leftChild = NULL;
	newNode -> rightChild = NULL;
	newNode -> value = value;
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
		cout<<"\t\tTree Data Structure\n1 ] Create Tree\n2 ] Display(inorder)\n3 ] Exit\n\nChoice >>> ";
		cin>>chc;
		system("cls");
		struct node *root;
		switch(chc){
			case 1 :
				cout<<"Data (-1 for no node) : ";
				cin>>val;
				root = createNode(val);
				cout<<"Data for "<<root -> value<<"'s left child (-1 for no node) : ";
				cin>>val;
				root -> leftChild = createNode(val);
				cout<<"Data for "<<root -> value<<"'s right child (-1 for no node) : ";
				cin>>val;
				root -> rightChild = createNode(val);	
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
