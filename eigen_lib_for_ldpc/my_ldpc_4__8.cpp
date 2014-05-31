//

#include <iostream>
//#include <vector>
using namespace std;

int matr_vec_mult(int h_check_matrix [4][8], int y_received_codeword[8]);
///int funk1_for_f_check_nodes(int h_check_matrix [4][8], int c_bit_nodes[8]);


int main()
{
	int m=4;
	int n=8;
	int y_received_codeword[8] = {1, 1, 0, 1, 0, 1, 0, 1};// {1, 0, 0, 1, 0, 1, 0, 1}
	int h_check_matrix [4][8] =
	{
		{0, 1, 0, 1, 1, 0, 0, 1},   
		{1, 1, 1, 0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0, 1, 1, 1},
		{1, 0, 0, 1, 1, 0, 1, 0}
	};

	int iteration_counter = 0;
	
	int sindrom = matr_vec_mult(h_check_matrix, y_received_codeword);
	
	int c_bit_nodes[8];
	int f_check_nodes[4][4];

	for (int i = 0; i < 8; i++)
	{
		c_bit_nodes[i] = y_received_codeword[i];  
	}


	while (sindrom != 0 && iteration_counter < 3)
	{
		iteration_counter = iteration_counter + 1;
	
	for  (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (h_check_matrix[i][j] == 1)
				f_check_nodes[i][j]= c_bit_nodes[j];			
		}
			}

	}

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

//int funk1_for_f_check_nodes(int h_check_matrix [4][8], int c_bit_nodes[8])
//{
//	int m = 4;
//	int n = 8;
//	int index = 0;
//	int f_check_nodes[4][4];
//
//	for  (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (h_check_matrix[i][j] != 0)
//			index = h_check_matrix[i][j];
//			f_check_nodes[i][j]= c_bit_nodes[index];
//		
//		}
//
//
//	}
//
//	
//	//cout << "\n  f_check_nodes=  \n";// вывод f матрицы
//	//for (int i = 0; i < 4; i++)
//	//	{
//	//		for (int j = 0; j < 4; j++)
//	//		{
//	//		cout << f_check_nodes[i][j];
//	//		}
//	//	cout <<endl;
//	//	}///////////////////////////////////////////////////////
//
//}







//	cout << "y_received_codeword =  " ;//вывод кодового слова
	//	for (int i = 0; i < 8; i++)
	//	{
	//		cout << y_received_codeword[i];
	//	}
	//	cout << endl;
	//}
	//cout << "sindrom=  " << sindrom << endl;//////////////////////


	//
	//cout << "h_check_matrix=  \n";// вывод проверочной матрицы
	//for (int i = 0; i < 4; i++)
	//	{
	//		for (int j = 0; j < 8; j++)
	//		{
	//		cout << h_check_matrix[i][j];
	//		}
	//	cout <<endl;