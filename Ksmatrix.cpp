#include <cstdio>
#include <iostream>

using namespace std;

//Defining functions :)

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

float simple_det(int arr_size, float arr[50][50])
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

float complex_det(int arr_size, float arr[50][50])
{
	float det = 0;
	if (arr_size <= 3)
		det = simple_det(arr_size, arr);
	else
	{
		float tmp[50][50];
		for (int i = 0; i < arr_size; i++)
		{
			//temporary array
			for (int j = 0; j < arr_size - 1; j++)
				for (int k = 0; k < arr_size - 1; k++)
					if (k < i)
						tmp[k][j] = arr[k][j + 1];
					else
						tmp[k][j] = arr[k + 1][j + 1];
			float tmp_det = complex_det(arr_size - 1, tmp);
				//Determinant
			if (!(i%2))
				det = det + arr[i][0] * tmp_det;
			else
				det = det - arr[i][0] * tmp_det; 
		}	
	}
	return det;
}


float det(int arr_size, float arr[50][50])
{
	float determinant = 0;
	if (arr_size <= 3)
		determinant = simple_det(arr_size, arr);
	else
		determinant = complex_det(arr_size, arr);	
	return determinant;
}

void array_input(int arr_size, float array[][50])
{
	for (int i = 0; i < arr_size; i++)
	{
		for (int j = 0; j < arr_size; j++)
		{
			float tmp;
			cout << "Please input matrix element [" << j + 1 << "][" << i + 1 << "] > "; 
			cin >> tmp;
			array[j][i] = tmp; 
		}
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
	determinant = det(arr_size, array);
	//Printing output
	cout << "\nInput matrix:\n";
	print_arr(arr_size, array);
	cout << "Determinant of the following matrix is: " << determinant << endl;
	return 0;
}
