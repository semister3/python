#include <iostream>
#include <stdlib.h>
using namespace std;
struct node{
	int data;
	struct node *next;
};
struct node *rear = NULL , *front = NULL , *temp = NULL;
int boundedCapacity = 5 , counter = 0 , val , chc , i;
void menu();
void continueUser(){
	cout<<"\n1 ] Menu\t\t\t2 ] Exit\n------------------------------------------------------------\nChoice >>> ";
	cin>>chc;
	if(chc == 1){
		menu();
	}else if(chc == 2){
		exit(0);
	}
}
void enque(){
	system("cls");
	if(counter + 1 > boundedCapacity){
		cout<<"\nQueue is in Overflow State !\n";
	}else{
		struct node *element = (struct node *)malloc(sizeof(struct node));
		cout<<"\nNew Value : ";
		cin>>val;
		element -> data = val;
		element -> next = NULL;
		cout<<"\n1 ] Enqueue at Rear \n2 ] Enqueue at Front \n\nChoice >>> ";
		cin>>chc;
		if(front == NULL && rear == NULL){
			front = rear = element;
		}else{
			if(chc == 1){
				element -> next = front;
				front = element;	
			}else if(chc == 2){
				rear -> next = element;
				rear = element;
			}
		}
		counter++;
	}
}
void display(){
	if(counter == 0){
		cout<<"\nQueue is in Underflow State !\n";
		continueUser();
	}
	cout<<"\nAvailable Queue\n";
	temp = front;
	while(temp != rear){
		cout<<temp -> data<<"\n";
		temp = temp -> next;
	}
	cout<<temp -> data<<"\n";
	continueUser();
}
void createQueue(){
	system("cls");
	cout<<"\nBounded Capacity : ";
	cin>>boundedCapacity;
	menu();
}
void deque(){
	if(counter == 0){
		cout<<"\nQueue is in Underflow State !\n";
		continueUser();
	}else{
		cout<<"\n1 ] Dequeue from Rear\n2 ] Dequeue from Front\n\nChoice >>> ";
		cin>>chc;
		if(chc == 1){
			temp = front;
			for(i = 1 ; i < counter - 2 ; i++){
				temp = temp -> next;
			}
			free(temp -> next -> next);
			temp -> next = NULL;
		}else if(chc == 2){
			temp = front;
			front = front -> next;
			free(temp);
		}
		counter--;
		cout<<"\nValue Deleted Successfully !\n";
	}
	continueUser();
}
void menu(){
	system("cls");                                  
	cout<<"\n       Double Ended Queue\n------------------------------\n1 ] Create         2 ] Display\n\n3 ] EnQueue        4 ] DeQueue\n\n           5 ] Exit\n------------------------------\nChoice >>> ";
	cin>>chc;
	system("cls");
	switch(chc){
		case 1 :
			createQueue();
			break;
		case 2 :
			display();
			break;
		case 3 :
			enque();
			continueUser();
			break;
		case 4 :
			deque();
			break;
		case 5 :
			exit(0);
			break;
	}
}
int main(){
	menu();
}
