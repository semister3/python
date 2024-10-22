#include<iostream>
#include<conio.h>
#define N 3
using namespace std;

int cnt=0,front=-1,rear=-1,queue[N];

void enqueue(int val){
	if(cnt==N) cout<<"Queue is in overflow state";
	else {
		if(front==-1 && rear==-1){
		front=rear=0;queue[rear]=val;cnt++;
		} else { rear=(rear+1)%N;queue[rear]=val;cnt++;}
		cout<<val<<" enqueued successfully !!";	
	}
}

void dequeue(){
	if(cnt==0){ cout<<"Queue is in underflow state"; }
	else if(cnt==1){
		cout<<queue[front]<<" dequeued successfully !!";	
		cnt--;front=-1;rear=-1; } 
	else{ cout<<queue[front]<<" dequeued successfully !!";
		front++; cnt--; }
}

void display(){
	if(front!=-1 && rear!=-1){
		if(front>rear){
			for(int i=front;i<N;i++)cout<<queue[i]<<" ";
			for(int i=0;i<=rear;i++)cout<<queue[i]<<" ";
		} else for(int i=front;i<=rear;i++)cout<<queue[i]<<" ";	
	} else cout<<"\nQueue is an empty state";
}

void wait(){ cout<<"\nplease enter any key! "; getch();}

int main(){
	int ch,ele;
	do{
		system("cls");
		cout<<"1 | Enqueue"<<endl<<"2 | Dequeue"<<endl;
		cout<<"3 | Display"<<endl<<"4 | Front Item"<<endl;
		cout<<"5 | Rear Item"<<endl<<"6 | Exit"<<endl;
		cout<<">>> ";
		cin>>ch;
		switch(ch){
			case 1 : cout<<"Enter element to insert : ";
					 cin>>ele;enqueue(ele); wait(); break;
			case 2 : dequeue(); wait(); break;
			case 3 : display(); wait(); break; 
			case 4 : cout<<"Front item : "<<queue[front]; wait(); break;
			case 5 : cout<<"Rear item  : "<<queue[rear]; wait(); break;
		}
	} while(ch!=6);
}
