#include <iostream>
using namespace std;
int searchElement(int ary[] , int size , int item){
	for(int i = 0 ; i < size ; i++){
		if(item == ary[i]){				// Checking if item is in array or not
			return i;
		}
	}
	return -1;
}
int main(){
	int size , res , item , chc;
	do{
		system("cls");
		cout<<"\nArray Size : ";
		cin>>size;
		int ary[size];
		for(int i = 0 ; i < size ; i++){		// Array insertion
			cout<<"Element  "<<i + 1<<" : ";
			cin>>ary[i];
		}
		system("cls");
		cout<<"\nItem to search : ";			// Taking user input 
		cin>>item;
		system("cls");
		cout<<"\nArray : ";
		for(int i = 0 ; i < size ; i++){		// Array printing
			cout<<ary[i]<<" ";
		}
		res = searchElement(ary , size , item); 		// Storing the index number of item searched
		if(res == -1){
			cout<<"\nMatch not found !";
		}else{
			cout<<"\nMatch found and it is stored in "<<" position "<<res + 1;
		}
		cout<<"\n\nDo you want to continue ?\n1 ] Yes\t\t\t2 ] No\nChoice >>> ";
		cin>>chc;
	}while(chc != 2);
}
