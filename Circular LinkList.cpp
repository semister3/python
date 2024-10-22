#include <iostream>
#include <stdlib.h>
using namespace std;
int i , j , size = 0 , chc;
struct node{
	int data;
	struct node *next;
};
struct node *head = NULL;
struct node *temp;
void print_list();
void user_continue();
void create_node(int val){
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = val; 
	if(head == NULL){
		head = new_node;
		head -> next = head;
		temp = head;
	}else{
		new_node -> next = head;
		temp -> next = new_node;
		temp = temp -> next;
	}
	size++;
}
void reset_list(){
	system("cls");
	if(size != 0){
		system("cls");
		struct node *temp2;
		temp = head;
		while(temp -> next != head){
			temp2 = temp -> next;
			free(temp);
			temp = temp2;
		}
		free(temp);
		temp = head = NULL;
		cout<<"\nReset Successfull\n";
	}else{
		cout<<"\nLink List is empty\n";
	}
	size = 0;
	user_continue();
}
void insert_beg(int val){
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = val; 
	new_node -> next = head;
	temp = head;
	while(temp -> next != head){
		temp = temp -> next;
	}
	temp -> next = new_node;
	head = new_node;
	size++;
}
void update_list(){
	system("cls");
	if(size != 0){
		int pos;
		print_list();
		cout<<"\nPosition of value : ";
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
			cout<<"\nInvalid Position\n";
		}
	}else{
		cout<<"\nLink List is empty\n";
	}
	user_continue();
}
void search_list(){
	system("cls");
	if(size != 0){
		int val;
		system("cls");
		cout<<"\nValue to Search : ";
		cin>>val;
		temp = head;
		for(i = 1 ; temp -> next != head ; i++){
			if(val == temp -> data){
				cout<<"Value found and stored in "<<temp<<endl;
				break;
			}else{
				cout<<"Value not found in the Link List\n";
				break;
			}
		}
	}else{
		cout<<"\nLink List is empty\n";
	}	
	user_continue();
}
void insert_at_pos(int pos , int val){
	if(size != 0){
		struct node *new_node = (struct node *)malloc(sizeof(struct node));
		new_node -> data = val; 
		if(pos == 1){
			insert_beg(val);
		}else{
			temp = head;
			for(i = 1 ; i < pos - 1 ; i++){
				temp = temp -> next;
			}
			new_node -> next = temp -> next;
			temp -> next = new_node;
			size++;
		}
	}else{
		cout<<"\nLink List is empty\n";
	}
	size++;
	user_continue();
}
void delete_list(){
	system("cls");
	if(size != 0){
		int pos;
		cout<<"\nPosition : ";
		cin>>pos;
		temp = head;
		struct node *temp2 = head;
		if(pos == 1){
			while(temp -> next != head){
				temp = temp -> next;
			}
			head = head -> next;
			free(temp2);
			temp -> next = head;
			cout<<"Deletion Successfull\n";
			size--;
		}else if(pos > size){
			cout<<"Invalid Position\n";
		}else{
			for(i = 1 ; i < pos - 1 ; i++){
				temp = temp -> next;
			}	
			temp2 = temp -> next -> next;
			free(temp -> next);
			temp -> next = temp2;	
			cout<<"Deletion Successfull\n";
			size--;
		}
	}else{
		cout<<"\nLink List is empty\n";
	}
	user_continue();
}
void menu(){
	int val , loop , i = 0;
	system("cls");
	cout<<"\n---------- Cirular Link List ----------\n\n[ 1 ] Create Link List\n[ 2 ] Display\n[ 3 ] Update\n[ 4 ] Search\n[ 5 ] Delete\n[ 6 ] Reset Link List\n[ 7 ] Exit\n\nChoice >>> ";
	cin>>chc;	
	switch(chc){
		case 1 :
			do{
				i++;
				system("cls");
				cout<<"Element "<<i<<" : ";
				cin>>val;
				create_node(val);
				cout<<"Creation Successfull\n\nDo you want to continue ?\n[ 1 ] Yes        No [ 2 ]\n\nChoice >>> ";
				cin>>loop;
			}while(loop != 2);
			menu();
			break;
		case 2 :
			print_list();
			user_continue();
			break;
		case 3 :
			update_list();
			break;
		case 4 :
			search_list();
			break;
		case 5 :
			delete_list();
			break;
		case 6 :
			reset_list();
			break;
		case 7 :
			exit(0);
			break;
	}
}
void print_list(){
	system("cls");
	if(size != 0){
		cout<<"\nCircular Link List :\n";
		temp = head;
		for(i = 1 ; i <= size ; i++){
			cout<<"\nData "<<i<<" : "<<temp -> data<<"\nAddress : "<<temp<<endl;
			temp = temp -> next;
		}
	}else{
		cout<<"\nLink List is empty\n";
		user_continue();
	}
}
void user_continue(){
	cout<<"\nDo you want to continue ?\n[ 1 ] Yes        No [ 2 ]\n\nChoice >>> ";
	cin>>chc;
	if(chc == 1){
		menu();	
	}else{
		exit(0);
	}
}
int main(){
	menu();
}
