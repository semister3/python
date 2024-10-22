#include <iostream>
#include <stdlib.h>
using namespace std;
int matrix[10][10] , i , j , row , col , size = 0 , count = 0;
struct node{
	int data , row , col;
	struct node *previous , *next ;
};
struct node *head = NULL , *temp;
void get_matrix(){
	cout<<"Row & Column of Matrix : ";
	cin>>row>>col;
	for(i = 0 ; i < row ; i++){
		for(j = 0 ; j < col ; j++){
			cout<<"Element ["<<i + 1<<"]["<<j + 1<<"] : ";
			cin>>matrix[i][j];
			if(matrix[i][j] == 0){
				count++;
			}
		}
	}
}
void print_matrix(){
	cout<<"\nMatrix : \n";
	for(i = 0 ; i < row ; i++){
		for(j = 0 ; j < col ; j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}
void print_node(){
	temp = head;
	for(i = 1 ; i <= size ; i++){
		//cout<<temp -> previous<<" | "<<temp -> row<<" | "<<temp -> col<<" | "<<temp -> data<<" ("<<&temp -> data<<") | "<<temp -> next<<" --> \n\n";
		cout<<temp -> previous<<" | "<<temp -> row<<" | "<<temp -> col<<" | "<<temp -> data<<" | "<<temp -> next<<"\n\n";
		temp = temp -> next;
	}
}
void create_node(int val , int row , int col){
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node -> data = val;
	new_node -> previous = 	NULL;
	new_node -> next = 	NULL;
	new_node -> row = row;
	new_node -> col = col;
	if(head == NULL){
		head = new_node;
		temp = head;
	}else{
		temp -> next = new_node;
		new_node -> previous = temp;
		temp = new_node;
	}
	size++;
}
void isSparce(){
	if(count > (row * col) / 2){
		cout<<"\nEntered Matrix is a Sparce Matrix\n";
		for(i = 0 ; i < row ; i++){
			for(j = 0 ; j < col ; j++){
				if(matrix[i][j] != 0){
					create_node(matrix[i][j] , i , j);
				}
			}
		}
	}else{
		cout<<"\nEnterd Matrix is not a Sparce Matrix\n";
	}
}
int main(){
	get_matrix();
	print_matrix();
	isSparce();
	print_node();
}
