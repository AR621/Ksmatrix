#include <cstdio>
#include <iostream>

using namespace std;

//Defining functions
float simple_det(int arr_size, float arr[][50])
{
	float det;
	if (arr_size == 3)
		det = arr[0][0] * arr[1][1] * arr[2][2]
			+ arr[1][0] * arr[2][1] * arr[0][2]
		       	+ arr[2][0] * arr[0][1] * arr[1][2]
			- arr[2][0] * arr[1][1] * arr[0][2]
			- arr[1][0] * arr[0][1] * arr[2][2]
			- arr[0][0] * arr[2][1] * arr[1][2];
	if (arr_size == 2)
		det = arr[0][0] * arr[1][1] - arr[1][0] * arr[0][1];
	if ( arr_size == 1)
		det = arr[0][0];
	return det;
}

float complex_det(int arr_size, float arr[][50])
{
	float determinant = 0, tmp[49][50];
	if (arr_size <= 3)
	{
		determinant = simple_det(arr_size, arr);
	}
	else
	{
		for (int i = 0; i < arr_size; i++)
			{
				//temporary array
				for (int j = 1; j < arr_size; j++)
					for (int k = 1; k < arr_size; k++)
						if (j < i)
							tmp[j][k] = arr[j][k];
						else
							tmp[j][k] = arr[j + 1][k];
				//Determinant
				for (int i = 0; i < arr_size; i++)
					if (!(i%2))
						determinant = determinant + complex_det(arr_size - 1, tmp);
					else
						determinant = determinant - complex_det(arr_size - 1, tmp);
			}
	}
	return determinant;
}

void array_input(int arr_size, float array[][50])
{
	for (int i = 0; i < arr_size; i++)
	{
		for (int j = 0; j < arr_size; j++)
		{
			float tmp;
			cout << "\nPlease input matrix element [" << j + 1 << "][" << i + 1 << "] > "; 
			cin >> tmp;
			array[j][i] = tmp; 
		}
	}
}

void print_arr(int arr_size, float arr[][50])
{
	for (int i = 0; i < arr_size; i++)
	{
		cout << "{ ";
		for (int j = 0; j < arr_size; j++)
		{
			cout << arr[j][i];
			if (j < arr_size - 1)
				cout << " ; "; 
		}
		cout << " }\n";
	}
}

int main()
{
	//Variables
	float determinant, array[50][50];
	int arr_size = 1;
	//User input
	cout << "Matrix determinawnt.\nPlease input the size of an array of which the determinant will be calculated: ";
	cin >> arr_size;
	array_input(arr_size, array);
	//Calculating determinant
	determinant = complex_det(arr_size, array);
	//Printing output
	cout << "\nInput matrix:\n";
	print_arr(arr_size, array);
	cout << "Determinant of the following matrix is: " << determinant << endl;
	return 0;
}
