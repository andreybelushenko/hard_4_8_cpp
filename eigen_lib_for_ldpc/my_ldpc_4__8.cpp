//
#include <iostream>
using namespace std;

int matr_vec_mult(int h_check_matrix [4][8], int y_received_codeword[8]);

int main()
{
	int y_received_codeword[8] = {1, 1, 0, 1, 0, 1, 0, 1};// {1, 0, 0, 1, 0, 1, 0, 1}
	int h_check_matrix [4][8] =
	{
		{0, 1, 0, 1, 1, 0, 0, 1},   
		{1, 1, 1, 0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0, 1, 1, 1},
		{1, 0, 0, 1, 1, 0, 1, 0}
	};

	int sindrom = matr_vec_mult(h_check_matrix, y_received_codeword);

	int c_bit_nodes[8];
	int f_check_nodes[4][4];

	for (int i = 0; i < 8; i++)
	{
		c_bit_nodes[i] = y_received_codeword[i];  
	}


	for (int iteration_counter = 0; (sindrom != 0 && iteration_counter < 2); iteration_counter++)
	{
		for  (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (h_check_matrix[i][j] == 1)
					cout<< (f_check_nodes[i][j] = c_bit_nodes[j]);	
				
			}
			cout << endl;
		}
		cout << endl;  cout << endl;
	}




		
	cout << "f_check_matrix=  \n";// вывод f матрицы
	for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
			cout << f_check_nodes[i][j];
			}
		cout << endl;
		}
	cout << "!!!!!!!!!!!!!!!!!!=!!!  \n";




	cin.get();
	return 0;
}


int matr_vec_mult(int h_check_matrix [4][8], int y_received_codeword[8])
{
	// a[m][n]						h_check_matrix
	// b[] - vect n  elem			y_received_codeword
	// c[] - vect m  elem



	int c[4] = {1, 1, 1, 1};
	int m = 4;
	int n = 8;
	int sum_sindrom = 0;

	for (int i = 0; i < m; i++)  {
		c[i] = 0;
		for (int j =0; j < n; j++){
			c[i] += h_check_matrix[i][j]  *  y_received_codeword[j];
		}
	}

	for (int i = 0; i < m; i++)
		sum_sindrom = sum_sindrom + (c[i] % 2);

	return sum_sindrom;
}

