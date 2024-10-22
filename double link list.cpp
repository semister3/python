#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
int i , j , size = 0 , select , pos , val;
struct node{
	int data;
	struct node *next , *previous;
};
struct node *head = NULL , *temp , *lastnode = NULL;
void print_list();
void user_continue();
void menu();
void isEmptyList(){
	system("cls");
	if(size == 0){
		cout<<"\nDouble Link List is empty\n\n--------------------------------------\nPress any key ";
		getch();
		menu();
	}
}
void create_node(int val){
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = val; 
	new_node -> next = NULL;
	new_node -> previous = NULL;
	if(head == NULL){
		head = new_node;
		temp = head;
	}else{
		new_node -> previous = temp;
		temp -> next = new_node;
		temp = temp -> next;
	}
	lastnode = temp;
	size++;
}
void reset_list(){
	isEmptyList();
	system("cls");
	for(i = 1 ; i <= size ; i++){
		temp = head;
		head = head -> next;
		free(temp);
	}
	temp = NULL;
	cout<<"\nReset Successfull\n";
	size = 0;
	user_continue();
}
void update_list(){
	isEmptyList();
	print_list();
	cout<<"\nPosition of value to update : ";
	cin>>pos;
	if(pos <= size){
		temp = head;
		for(i = 1 ; i < pos ; i++){
			temp = temp -> next;
		}
		cout<<"\nOld Value : "<<temp -> data<<"\n\nNew Value : ";
		cin>>temp -> data;
		cout<<"Update successfull...\n";
	}else{
		cout<<"\n\nInvalid Position\n";
	}
	user_continue();
}
void search_list(){
	isEmptyList();
	int flag = 0;
	system("cls");
	cout<<"\nValue to Search : ";
	cin>>val;
	temp = head;
	while(temp != NULL){
		if(val == temp -> data){
			flag = 1;
			break;
		}
		temp = temp -> next;
	}
	if(flag){
		cout<<"Value found and stored in "<<temp<<endl;
	}else{
		cout<<"Value not found in the Link List\n";
	}
	user_continue();
}
void insert_node(int pos , int val){
	isEmptyList();
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = val; 
	new_node -> next = NULL;
	new_node -> previous = NULL;
	temp = head;
	if(pos == 1){
		head -> previous = new_node;
		new_node -> next = head;
		head = new_node;
		size++;
		cout<<"Insertion Successfull\n";
	}else if(pos > size){
		cout<<"Invalid Postion\n";
	}else{
		for(i = 1 ; i < pos ; i++){
			temp = temp -> next;
		}
		temp -> previous -> next = new_node;
		new_node -> previous = temp -> previous;
		new_node -> next = temp;
		temp -> previous = new_node;
		size++;
		cout<<"Insertion Successfull\n";
	}
	user_continue();
}
void delete_list(){
	isEmptyList();
	int pos;
	cout<<"\nPosition : ";
	cin>>pos;
	temp = head;
	if(pos == 1){
		head = head -> next;
		head -> previous = NULL;
		free(temp);
		cout<<"Deletion Successfull\n";
		size--;
	}else if(pos > size){
		cout<<"Invalid Position\n";
	}else{
		for(i = 1 ; i < pos ; i++){
			temp = temp -> next;
		}
		temp -> previous -> next = temp -> next;
		temp -> next -> previous = temp -> previous;
		free(temp);
		cout<<"Deletion Successfull\n";
		size--;
	}
	user_continue();
}
void menu(){
	int loop , i = 0;
	system("cls");
	cout<<"\n---------- Double Link List ----------\n\n[ 1 ] Create Link List\n[ 2 ] Display\n[ 3 ] Insert\n[ 4 ] Update\n[ 5 ] Search\n[ 6 ] Delete\n[ 7 ] Reset Link List\n[ 8 ] Exit\n\n--------------------------------------\nChoice >>> ";
	cin>>select;	
	switch(select){
		case 1 :
			do{
				i++;
				system("cls");
				cout<<"Element "<<i<<" : ";
				cin>>val;
				create_node(val);
				cout<<"Creation Successfull\n\n--------------------------------------\nDo you want to continue ?\n[ 1 ] Yes        No [ 2 ]\n\nChoice >>> ";
				cin>>loop;
			}while(loop != 2);
			menu();
			break;
		case 2 :
			print_list();
			user_continue();
			break;
		case 3 :
			isEmptyList();
			cout<<"\nPostion : ";
			cin>>pos;
			cout<<"Value : ";
			cin>>val;
			insert_node(pos , val);
			break;
		case 4 :
			update_list();
			break;
		case 5 :
			search_list();
			break;
		case 6 :
			delete_list();
			break;
		case 7 :
			reset_list();
			break;
		case 8 :
			exit(0);
			break;
	}
}
void print_list(){
	isEmptyList();
	cout<<"\nDouble Link List :\n";
	temp = head;
	for(i = 1 ; i <= size ; i++){
		cout<<"\nData "<<i<<" : "<<temp -> data<<"\nAddress : "<<temp<<endl;
		temp = temp -> next;
	}
//	user_continue();
}
void user_continue(){
	cout<<"\n--------------------------------------\nNavigate to ?\n[ 1 ] Menu        Exit [ 2 ]\n\nChoice >>> ";
	cin>>select;
	if(select == 1){
		menu();	
	}else{
		exit(0);
	}
}
int main(){
	menu();
}
