#include <iostream>
using namespace std;
int main(){
	int size , i , j , chc , key;
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
		for(i = 1 ; i < size ; i++){		// Sorting logic
			key = ary[i];
			for(j = i - 1 ; (j >= 0 && ary[j] > key) ; j--){
				ary[j + 1] = ary[j];
			}
			ary[j + 1] = key;
		}
		for(i = 0 ; i < size ; i++){
			cout<<ary[i]<<" ";
		}
		cout<<"\n\nDo you want to continue ?\n1 ] Yes\t\t\t2 ] No\nChoice >>> ";
		cin>>chc;
	}while(chc != 2);
}
