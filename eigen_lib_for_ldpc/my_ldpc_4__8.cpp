//
#include <iostream>
using namespace std;

int matr_vec_mult(int h_check_matrix [4][8], int y_received_codeword[8]);
//void print_matrix (const int row, const int column, const int matrix[4][4] );
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
	int parity_check [4][4];

	for (int i = 0; i < 8; i++)
	{
		c_bit_nodes[i] = y_received_codeword[i];  
	}


	for (int iteration_counter = 0; (sindrom != 0 && iteration_counter < 2); iteration_counter++)
	{
		for  (int i = 0; i < 4; i++)
		{
			int k = 0;
			for (int j = 0; j < 8; j++)
			{
				if (h_check_matrix[i][j] == 1)
				{	
					k++;
					f_check_nodes[i][k] = c_bit_nodes[j];	
					cout<<f_check_nodes[i][k];
				}
			}
			cout << endl;
		}
		cout << endl;  cout << endl;



		// matrix parity_check [4][4];
		for  (int i = 0; i < 4; i++)
		{
			int p = 0;
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < 4; j++)
				{
					
					p = p + f_check_nodes[i][k];
				}
				p = p - f_check_nodes[i][j];
				p = (p % 2);
				parity_check[i][j] = p;
				cout << parity_check[i][j];
			}
			cout << endl;
		}
		cout << endl;  cout << endl;
		

		
					  

					









	}




		
	/*print_matrix(4,4,f_check_nodes);*/




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

	for (int i = 0; i < m; i++) 
	{
		c[i] = 0;
		for (int j =0; j < n; j++)
		{
			c[i] += h_check_matrix[i][j]  *  y_received_codeword[j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		sum_sindrom = sum_sindrom + (c[i] % 2);
	}
	return sum_sindrom;
}

//void print_matrix (const int row, const int column, const int matrix[4][4] )
//{
//		cout << "matrix=  \n";
//	for (int i = 0; i < row; i++)
//		{
//			for (int j = 0; j < column; j++)
//			{
//			cout << matrix[i][j];
//			}
//		cout <<endl;
//
//}
//}
//
