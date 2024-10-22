#include <iostream>
using namespace std;
int arr[20] = {} , i , j , chc , size , t;
int arr_print()
{
	cout<<"Array : ";
	for(i = 0 ; i < size ; i++)
	{
		cout<<arr[i]<<" ";
	}
}
int arr_insert()
{
	cout<<"Enter the size of array : ";
	cin>>size;
	arr[size];
	cout<<endl;
	for(i = 0 ; i < size ; i++)
	{
		cout<<"Enter element "<<i + 1<<" : ";
		cin>>arr[i];
	}
	system("cls");
}
int arr_search()
{
	int f = 0;
	cout<<"Enter the Element to Search : ";
	cin>>chc;
	for(i = 0 ; i < size ; i++)
	{
		if(arr[i] == chc)
		{
			f = 1;
			break;
		}
	}
	if(f == 1)
	{
		cout<<"Element Found...\n";
	}
	else
	{
		cout<<"Element not Found...\n";
	}
}
int arr_sort()
{
	cout<<"1 ] Ascending Sort\n2 ] Descending Sort\nChoice >>>>> ";
	cin>>chc;
	for(i = 0 ; i < size ; i++)
	{
		for(j = i + 1 ; j < size ; j++)
		{
			if(chc == 1)
			{
				if(arr[i] > arr[j])
				{
					t = arr[i];
					arr[i] = arr[j];
					arr[j] = t;
				}
			}
			else if(chc == 2)
			{
				if(arr[i] < arr[j])
				{
					t = arr[i];
					arr[i] = arr[j];
					arr[j] = t;
				}
			}
		}	
	}
	arr_print();
}
int arr_reverse()
{
	i = 0;
	chc = size;
	chc -= 1;
	while(i < chc)
	{
		t = arr[i];
		arr[i] = arr[chc];
		arr[chc] = t;
		i++;
		chc--;
	}
	arr_print();
}
int menu()
{
	int yn;
	do
	{
		system("cls");
		cout<<"Array Operations :\n1 ] Search\n2 ] Sort\n3 ] Reverse\n4 ] Exit\nChoice >>>> ";
		cin>>chc;
		switch(chc)
		{
			case 1 :
				system("cls");
				arr_search();
				break;
			case 2 :
				system("cls");
				arr_sort();
				break;
			case 3 :
				system("cls");
				arr_reverse();
				break;
			case 4 :
				exit(0);
				break;
			default :
				cout<<"Chooce a correct option...";
		}
		cout<<"\nDo you want to continue ?\n1 | YES		2 | NO\nChoice >>>>> ";
		cin>>yn;
	}while(yn != 2);
}
int main()
{
	arr_insert();
	menu();
}
