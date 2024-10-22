#include <iostream>
using namespace std;
int main()
{
	int size = 11;
	int arry[size] = {1 , 1 , 1 , 3 ,  1 , 5 , 7 , 0 , 9 , 0 , 7};
	for(int i = 0 ; i < size ; i++)
	{
		for(int j = i + 1 ; j < size ; j++)
		{
			if(arry[i] == arry[j])
			{
				for(int k = j ; k <= size ;  k++)
				{
					arry[k] = arry[k + 1];
				}
				size--;
				arry[size];
				j = i;
			}
		}
	}
	for(int i = 0 ; i < size ; i++)
	{
		cout<<arry[i]<<" ";
	}
}
