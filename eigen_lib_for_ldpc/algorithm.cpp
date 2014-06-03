#include "algorithm.h"



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

void f_check (int h_check_matrix[4][8] , int c_bit_nodes[8], int f_check_nodes[4][4])
{
	for  (int i = 0; i < 4; i++)
		{
			//int k = 0;
			for (int j = 0, k = 0; j < 8; j++)
			{
				if (h_check_matrix[i][j] == 1)
				{	
					
					f_check_nodes[i][k] = c_bit_nodes[j];
					k++;
				}
			}
		}
}

void parity (int f_check_nodes[4][4], int parity_check[4][4])
{
		for  (int i = 0, p = 0; i < 4; i++)
		{   p = 0;
			for (int k = 0; k < 4; k++)
				{
					p = p + f_check_nodes[i][k];
				}
			for (int j = 0; j < 4; j++)
			{
				parity_check[i][j] = ( ( p - f_check_nodes[i][j] ) % 2 );
			}
		}
}

void bit_nodes (int f_node_index_matrx[8][2], int c_node_index_matrx[4][4], int parity_check[4][4], int bit_nodes_matrix[8][2]  )
{
	for  (int i = 0, p = 0; i < 8; i++)  //в bit_nodes_matrix матрицу запишем результат проверки четности
		{
			for  (int k = 0; k < 2; k++)  
			{
				int jj = 0;
				p=f_node_index_matrx[i][k];
				for  (int j = 0; j < 4; j++)
				{
					jj = j;
					if (c_node_index_matrx[p][jj] == i)
						break;
				}
				bit_nodes_matrix[i][k] = parity_check[p][jj];
			}
		}
}

void vote (int y_received_codeword[8], int bit_nodes_matrix[8][2], int c_bit_nodes[8])
{
	for  (int i = 0; i < 8; i++)
		{
			c_bit_nodes[i] =y_received_codeword[i] + bit_nodes_matrix[i][0] + bit_nodes_matrix[i][1];
			if (c_bit_nodes[i] > 1)
				c_bit_nodes[i] = 1;
			else
				c_bit_nodes[i] = 0;
		}
}

void ind_c(  int h_check_matrix[4][8] , int c_node_index_matrx[4][4])
{
	for  (int c = 0; c < 4; c++)   //строки f0:f3, элементы стр - индексы С
	{
		for  (int e = 0,  d = 0; e < 8; e++)
		{
			if (h_check_matrix [c][e] ==1)
			{
				c_node_index_matrx[c][d]= e;
				d++;
			}
		}
	}
}

void ind_f(int h_check_matrix[4][8] , int f_node_index_matrx[8][2])
{
	for  (int f = 0; f < 8; f++)   //строки c0:c7, элементы стр - индексы f
	{
		for  (int g = 0,  h = 0; g < 4; g++)
		{
			if (h_check_matrix [g][f] ==1)
			{
				f_node_index_matrx[f][h]= g;
				h++;
			}
		}
	}
}