#include <iostream>
using namespace std;
int arraySize = 5;
void merge(int ary[] , int startIndex , int midPointIndex , int lastIndex){
	int leftArrayPointer = lastIndex , rightArrayPointer = midPointIndex + 1 , tempArrayPointer = lastIndex;
	int tempArray[arraySize];
	while(leftArrayPointer <= midPointIndex && rightArrayPointer <= lastIndex){
		if(ary[leftArrayPointer]  <= ary[rightArrayPointer]){
			tempArray[tempArrayPointer] = ary[leftArrayPointer];
			tempArrayPointer++;
			leftArrayPointer++;
		}else if(ary[leftArrayPointer]  <= ary[rightArrayPointer]){
			tempArray[tempArrayPointer] = ary[rightArrayPointer];
			tempArrayPointer++;
			rightArrayPointer++;
		}
	}
	while(leftArrayPointer <= midPointIndex){
		tempArray[tempArrayPointer] = ary[leftArrayPointer];
		tempArrayPointer++;
		leftArrayPointer++;
	}
	while(rightArrayPointer <= lastIndex){
		tempArray[tempArrayPointer] = ary[rightArrayPointer];
		tempArrayPointer++;
		rightArrayPointer++;
	}
	for(int i = 0 ; i < arraySize ; i++){
		ary[i] = tempArray[i];
	}
}
void mergeSort(int ary[] , int startIndex , int lastIndex){
	if(startIndex <= lastIndex){
		int midPointIndex = (startIndex + lastIndex) / 2;
		mergeSort(ary , startIndex , midPointIndex);
		mergeSort(ary , midPointIndex + 1 , lastIndex);
		merge(ary , startIndex , midPointIndex , lastIndex);
	}
}
int main(){
	int chc;
//	cout<<"\nArray Size : ";
//	cin>>arraySize;
//	int ary[arraySize];
//	for(int i = 0 ; i < arraySize ; i++){
//		cout<<"Element "<<i + 1<<" : ";
//		cin>>ary[i];
//	}	
	int ary[arraySize] = {4 , 3 , 10 , 5 , 1};
	cout<<"\nArray        : ";
	for(int i = 0 ; i < arraySize ; i++){
		cout<<ary[i]<<" ";
	}	
	mergeSort(ary , 0 , arraySize - 1);
	cout<<"\nSorted Array :";
	for(int i = 0 ; i < arraySize ; i++){
		cout<<ary[i]<<" ";
	}	
}
