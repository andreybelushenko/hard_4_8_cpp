//
#include <iostream>
using namespace std;

int matr_vec_mult(int h_check_matrix [4][8], int y_received_codeword[8]);

int f_check (int h_check_matrix [4][8], int c_bit_nodes[8]);

int parity (int f_check_nodes[4][4]);

int bit_nodes (int f_node_index_matrx[8][2], int c_node_index_matrx[4][4], int parity_check [4][4]  );

int vote (int y_received_codeword[8], int bit_nodes_matrix[8][2]);

int ind_c ( int h_check_matrix [4][8] );

int ind_f ( int h_check_matrix [4][8] );

int main()
{
	int counter = 2;
	int y_received_codeword[8] = {1, 1, 0, 1, 0, 1, 0, 1};//true  codeword {1, 0, 0, 1, 0, 1, 0, 1}
	int h_check_matrix [4][8] =
	{
		{0, 1, 0, 1, 1, 0, 0, 1},   
		{1, 1, 1, 0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0, 1, 1, 1},
		{1, 0, 0, 1, 1, 0, 1, 0}
	};

	int c_bit_nodes[8];
	int f_check_nodes[4][4];
	int parity_check [4][4];
	int c_node_index_matrx [4][4];
	int f_node_index_matrx [8][2];
	int bit_nodes_matrix [8][2];

	for (int q = 0; q < 8; q++)
	{
		c_bit_nodes[q] = y_received_codeword[q];  
	}

	int sindrom = matr_vec_mult(h_check_matrix, y_received_codeword);

	c_node_index_matrx = ind_c( h_check_matrix );

	f_node_index_matrx = ind_f( h_check_matrix );

	int iteration_counter = 0;
	for ( iteration_counter; (sindrom != 0 && iteration_counter < counter); iteration_counter++)
	{
		f_check_nodes = f_check ( h_check_matrix,  c_bit_nodes);
		
		parity_check = parity (f_check_nodes);

		bit_nodes_matrix = bit_nodes ( f_node_index_matrx, c_node_index_matrx,  parity_check );
		
		c_bit_nodes = vote (y_received_codeword, bit_nodes_matrix);

		sindrom = matr_vec_mult(h_check_matrix, c_bit_nodes);
	}

	if (iteration_counter==counter)
		cout << "codeword was reciewed with error, can't correct  \n";
	else
	{
		cout <<"iteration_counter:   " <<iteration_counter <<endl;
		cout << "true received_codeword:  ";
		for  (int i = 0; i < 8; i++)
		{
			cout <<c_bit_nodes[i];
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

int f_check (int h_check_matrix [4][8], int c_bit_nodes[8])
{
	int f_check_nodes[4][4];
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
		
return f_check_nodes;
}

int parity (int f_check_nodes[4][4])
{
		int parity_check [4][4];
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
return parity_check;
}

int bit_nodes (int f_node_index_matrx[8][2], int c_node_index_matrx[4][4], int parity_check [4][4]  )
{
int bit_nodes_matrix[8][2];
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
return bit_nodes_matrix;
}

int vote (int y_received_codeword[8], int bit_nodes_matrix[8][2])
{
	int c_bit_nodes[8];
	for  (int i = 0; i < 8; i++)
		{
			c_bit_nodes[i] =y_received_codeword[i] + bit_nodes_matrix[i][0] + bit_nodes_matrix[i][1];
			if (c_bit_nodes[i] > 1)
				c_bit_nodes[i] = 1;
			else
				c_bit_nodes[i] = 0;
		}
	return c_bit_nodes;
}

int ind_c( int h_check_matrix [4][8] )
{
	int c_node_index_matrx[4][4];
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
	
	return c_node_index_matrx;
}

int ind_f(int h_check_matrix [4][8])
{
	int f_node_index_matrx[8][2];
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
	
	return f_node_index_matrx;
}