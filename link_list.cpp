#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;
int chc , i , size , val , loop , pos;
struct node
{
	int data;
	struct node *next;
};
struct node *head = NULL;
struct node *temp;
void menu();
int check_size(){
	if(size == 0){
		cout<<"\nLink-List is empty\n\nDo you want to continue ?\n1 | Yes         No | 2\nChoice >>> ";
		cin>>chc;
		if(chc == 1){
			menu();
		}else{
			exit(0);
		}
	}
}
void insert_at_pos(){
	check_size();
	cout<<"Position : ";
	cin>>pos;
	if(pos > size + 1){
		cout<<"\nPosition out of range\n";
	}else{
		struct node *new_node = (struct node *)malloc(sizeof(struct node));
		cout<<"\nNew Value : ";
		cin>>val;
		new_node -> data = val;
		new_node -> next = NULL;
		temp = head;
		if(pos == 1){
			head = new_node;
			head -> next = temp;
		}else if(pos == size + 1){
			for(i = 1 ; i < size ; i++){
				temp = temp -> next;
			}
			temp -> next = new_node;
		}else if(pos <= size){
			for(i = 1 ; i < pos - 1 ; i++){
			temp = temp -> next;
			}
			new_node -> next = temp -> next;
			temp -> next = new_node;
		}
		size++;
		cout<<"\nValue Inserted Successfully\n";
	}
}
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
}
void display_node(){
	check_size();
	temp = head;
	while(temp != NULL){
		cout<<"\nData : "<<temp -> data<<"\nAddress : "<<temp<<endl;
		temp = temp -> next;
	}
}
void remove_value(int j = 0){
	check_size();
	if(j == 0){
		cout<<"Position : ";
		cin>>pos;
	}else{
		pos = j;
		goto label;
	}
	if(pos > size){
		cout<<"\nPosition out of range\n";
	}else{
		label:
		struct node *temp2;
		temp = head;
		i = 1;
		if(pos == 1){
			head = head -> next;
			free(temp);
			struct node *temp;
		}else{
			while(i < pos - 1){
				temp = temp -> next;
				i++;
			}
			temp2 = temp -> next;
			temp -> next = temp -> next -> next;
			free(temp2);
		}
		if(j == 0){
			size--;
			cout<<"\nReset Successfull\n";
		}else{
			size = 0;
			cout<<"\nValue Removed Successfully\n";
		}
	}	
}
void search_list(){
	check_size();
	cout<<"Value : ";
	cin>>val;
	temp = head;
	int f = 0;
	while(temp != NULL){
		if(temp -> data == val){
			f = 1;
			break;
		}
		temp = temp -> next;
	}
	if(f){
		cout<<endl<<val<<" is stored in memory "<<temp<<endl;
	}else{
		cout<<"\nValue not Found\n";
	}
}
void update_list(){
	check_size();
	cout<<"Position : ";
	cin>>pos;
	temp = head;
	i = 1;
	while(temp != NULL){
		if(i == pos){
			break;
		}
		temp = temp -> next;
		i++;
	}
	cout<<"\nOld Value : "<<temp -> data<<"\n\nNew Value : ";
	cin>>temp -> data;
	cout<<"\nUpdate Successfull\n";
}
void menu(){
	do{
		system("cls");
		cout<<":: Operations on Link-List ::\n\n1 | Create Link List\n2 | Display Link-List\n3 | Insert Value\n4 | Remove Value\n5 | Search Value\n6 | Update Value\n7 | Reset Link-List\n8 | Exit\nChoice >>> ";
		cin>>chc;
		system("cls");
		switch(chc){
			case 1 :
				cout<<"Size of link-list : ";
				cin>>size;
				for(i = 1 ; i <= size ; i++){
					cout<<"Data "<<i<<" : ";
					cin>>val;
					create_node(val);
				}
				system("cls");
				display_node();
				break;
			case 2 :
				display_node();
				break;
			case 3 :
				insert_at_pos();
				break;
			case 4 :
				remove_value();
				break;
			case 5 :
				search_list();
				break;
			case 6 :
				update_list();
				break;
			case 7 :
				for(i = 1 ; i < size + 1 ; i++){
					remove_value(i);
				}
				break;
			case 8:
				exit(0);
				break;
		}
		cout<<"\nDo you want to continue ?\n1 | Yes         No | 2\nChoice >>> ";
		cin>>loop;
	}while(loop != 2);
}
int main(){
	menu();
}
