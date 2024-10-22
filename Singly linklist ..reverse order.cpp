 #include <iostream>
#include <stdlib.h>
using namespace std;
int val , loop = 1 , size = 0;
struct node{
	int data;
	struct node *next;
};
struct node *head = NULL;
struct node *temp , *temp2;
void create_node(int val){
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = val;
	new_node -> next = NULL;
	if(head == NULL){
		head = new_node;
		temp = head;
	}else{
		temp -> next = new_node;
		temp = temp -> next;
		temp -> next = NULL;
	}
	size++;
}
void print_list(){
	temp = head;
	while(temp != NULL){
		cout<<"\nData : "<<temp -> data<<"\nAddress : "<<temp<<endl;
		temp = temp -> next;
	}
}
void reverse_list(){
	temp = NULL;
	temp2 = NULL;
	while(head != NULL){
		temp2 = head -> next;
		head -> next = temp;
		temp = head;
		head = temp2;
	}
	head = temp;
}
int main(){
	int i = 0;
	do{
		i++;
		system("cls");
		cout<<"Element "<<i<<" : ";
		cin>>val;
		create_node(val);
		cout<<"Creation Successfull\n\nDo you want to continue ?\n[ 1 ] Yes        No [ 2 ]\n\nChoice >>> ";
		cin>>loop;
	}while(loop != 2);
	system("cls");
	cout<<"\nLinkList : \n";
	print_list();
	cout<<"\nAfter Reversing : \n";
	reverse_list();
	print_list();
}
