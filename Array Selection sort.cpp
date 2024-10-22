#include <iostream>
using namespace std;
int main(){
	int size , i , j , chc;
	do{
		system("cls");
		cout<<"\nSize of Array : ";
		cin>>size;
		int ary[size];
		for(i = 0 ; i < size ; i++){		// Array insertion
			cout<<"Element "<<i + 1<<" : ";
			cin>>ary[i];
		}
		system("cls");
		cout<<"\nGiven Array  : ";
		for(i = 0 ; i < size ; i++){ 		// Array display
			cout<<ary[i]<<" ";
		}
		cout<<"\nSorted Array : ";
		for(i = 0 ; i < size - 1 ; i++){		// Sorting logic
			for(j = i + 1 ; j < size ; j++){
				if(ary[j] < ary[i]){
					int t = ary[j];
					ary[j] = ary[i];
					ary[i] = t;
				}
			}
		}
		for(i = 0 ; i < size ; i++){
			cout<<ary[i]<<" ";
		}
		cout<<"\n\nDo you want to continue ?\n1 ] Yes\t\t\t2 ] No\nChoice >>> ";
		cin>>chc;
	}while(chc != 2);
}
