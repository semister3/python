#include <iostream>
using namespace std;
int matrix_1[20][20] = {} , matrix_2[20][20] = {} , res[20][20] ,  i , j , chc , row1 , col1 , row2 , col2;
int matrix_print(int matrix[20][20] , int row , int col)
{
	for(i = 0 ; i < row ; i++)
	{
		for(j = 0 ; j < col ; j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}
int matrix_insert(int cnt)
{
	if(cnt == 2)
	{
		cout<<"Enter the row & column of Matrix 1 : ";
		cin>>row1>>col1;
		matrix_1[row1][col1];
		cout<<"Enter the row & column of Matrix 2 : ";
		cin>>row2>>col2;
		matrix_2[row2][col2];
		cout<<endl;
		cout<<"Matrix 1 : \n";
		for(i = 0 ; i < row1 ; i++)
		{
			for(j = 0 ; j < col1 ; j++)
			{
				cout<<"Element ["<<i + 1<<"]["<<j + 1<<"] : ";
				cin>>matrix_1[i][j];
			}
		}
		cout<<endl;
		cout<<"Matrix 2 : \n";
		for(i = 0 ; i < row2 ; i++)
		{
			for(j = 0 ; j < col2 ; j++)
			{
				cout<<"Element ["<<i + 1<<"]["<<j + 1<<"] : ";
				cin>>matrix_2[i][j];
			}
		}
	}
	else
	{
		cout<<"Enter the row & column of Matrix : ";
		cin>>row1>>col1;
		matrix_1[row1][col1];
		cout<<endl;
		cout<<"Matrix : \n";
		for(i = 0 ; i < row1 ; i++)
		{
			for(j = 0 ; j < col1 ; j++)
			{
				cout<<"Element ["<<i + 1<<"]["<<j + 1<<"] : ";
				cin>>matrix_1[i][j];
			}
		}
	}
}
int matrix_add()
{
	if(row1 != row2 || col1 != col2)
	{
		cout<<"\nMatrix addition is not possible...\n";
	}
	else
	{
		for(i = 0 ; i < row1 ; i++)
		{
			for(j = 0 ; j < col1 ; j++)
			{
				res[i][j] = 0;
				res[i][j] = matrix_1[i][j] + matrix_2[i][j];
			}
		}
		cout<<"\nAddition of matrix is : \n";
		matrix_print(res , row1 , col1);
	}
}
int matrix_mul()
{
	for(i = 0 ; i < row1 ; i++)
	{
		for(j = 0 ; j < col2 ; j++)
		{
			res[i][j] = 0;
			for(int k = 0 ; k < col1 ; k++)
			{
				res[i][j] += matrix_1[i][k] * matrix_2[k][j];
			}
		}
	}
	matrix_print(res , row1 , col2);
}
int matrix_trans()
{
	res[col1][row1];
	for(i = 0 ; i < row1 ; i++)
	{
		for(j = 0 ; j < col1 ; j++)
		{
			res[j][i] = matrix_1[i][j];
		}
	}
	matrix_print(res , col1 , row1);
}
int menu()
{
	int yn;
	do
	{
		system("cls");
		cout<<"Matrix Operations :\n1 ] Addition\n2 ] Multiplication\n3 ] Transpose\n4 ] Exit\nChoice >>>> ";
		cin>>chc;
		switch(chc)
		{
			case 1 :
				system("cls");
				matrix_insert(2);
				matrix_add();
				break;
			case 2 :
				system("cls");
				matrix_insert(2);
				matrix_mul();
				break;
			case 3 :
				system("cls");
				matrix_insert(1);
				matrix_trans();
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
	menu();
}
