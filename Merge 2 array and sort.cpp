#include <iostream>
using namespace std;
int i , j , size1 , size2 , arr_1[20] = {} , arr_2[20] = {};
int arr_print(int arr[] , int size)
{
	for(i = 0 ; i < size ; i++)
	{
		cout<<arr[i]<<" ";
	}
}
int arr_insert()
{
	cout<<"Enter the size of array 1 : ";
	cin>>size1;
	arr_1[size1];
	cout<<"Enter the size of array 2 : ";
	cin>>size2;
	arr_2[size2];
	cout<<endl;
	cout<<"Array 1 elements :\n";
	for(i = 0 ; i < size1 ; i++)
	{
		cout<<"Enter element "<<i + 1<<" : ";
		cin>>arr_1[i];
	}
	cout<<endl;
	cout<<"Array 2 elements :\n";
	for(i = 0 ; i < size2 ; i++)
	{
		cout<<"Enter element "<<i + 1<<" : ";
		cin>>arr_2[i];
	}
	system("cls");
	cout<<"You have entered :\n\nArray 1 : ";
	arr_print(arr_1 , size1);
	cout<<"\nArray 2 : ";
	arr_print(arr_2 , size2);
}
int arr_sort(int arr[] , int size)
{
	for(i = 0 ; i < size ; i++)
	{
		for(j = i + 1 ; j < size ; j++)
		{
			if(arr[i] > arr[j])
			{
				int t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}	
	}
	cout<<"\nMerged & Sorted Array : \n";
	arr_print(arr , size);
}
int arr_merge()
{
	int size = size1 + size2;
	int merged[size];
	j = 0;
	for(i = 0 ; i < size ; i++)
	{
		if(i < size1)
		{
			merged[i] = arr_1[i];
		}
		else
		{
			merged[i] = arr_2[j];
			j++;
		}
	}
	arr_sort(merged , size);
}
int main()
{
	int chc;
	do
	{
		system("cls");
		arr_insert();
		arr_merge();
		cout<<"\n\nDo you want to continue ?\n1 | YES		2 | NO\nChoice >>> ";
		cin>>chc;
	}while(chc != 2);
}
