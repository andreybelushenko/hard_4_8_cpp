#include "algorithm.h"

void c_bit_nodes_from_y( int *y_received_codeword, int *c_bit_nodes, int col )
{
	for (int i = 0; i < col; i++)
	{
		c_bit_nodes[i] = y_received_codeword[i];  
	}
}

int matr_vec_mult( int **h_check_matrix_compact, int *c_bit_nodes, int row, int *num_elem_in_row)
{
	int sindrom  = 1;
	for  (int i = 0, b = 0, d = 0; i < row; i++)
	{ 
		d = num_elem_in_row[i];
		b = 0;
		for  (int j = 0, a = 0; j < d; j++)
		{
			a = h_check_matrix_compact[i][j];
			b = b + c_bit_nodes[a];

		}
		sindrom = (b % 2);
		if (sindrom  != 0)
			break;
	}
	return sindrom;
}

void f_check ( int **h_check_matrix_compact, int *c_bit_nodes, int **f_check_nodes, int row, int  *num_elem_in_row )
{
	for  (int i = 0; i < row; i++)
	{
		for  (int j = 0, a = 0; j < num_elem_in_row[i]; j++)
		{
			a = h_check_matrix_compact[i][j];
			f_check_nodes[i][j] = c_bit_nodes[a];
		}
	}
}

void parity (int **f_check_nodes, int row, int  *num_elem_in_row )
{	
	for  (int i = 0, a = 0; i < row; i++)
	{	
		a = 0;
		for  (int j = 0; j < num_elem_in_row[i]; j++)
		{  
			if ( f_check_nodes[i][j] != 0)
			{
				a = a + f_check_nodes[i][j];
			}
		}
		if ((a % 2 ) != 0)
		{
			for  (int k = 0; k < num_elem_in_row[i]; k++)
			{
				f_check_nodes[i][k] = ~ f_check_nodes[i][k];
			}
		}
	}

}

void vote (int *num_elem_in_row, int **h_check_matrix_compact, int row, int col, int *y_received_codeword, int *c_bit_nodes, int **f_check_nodes )
{
	c_bit_nodes_from_y(y_received_codeword, c_bit_nodes, col );
	for (int i=0; i<row; i++)
	{
		for (int j=0, k = 0; j < num_elem_in_row[i]; j++)
		{
			k = h_check_matrix_compact[i][j];
			c_bit_nodes[k] = c_bit_nodes[k] + f_check_nodes[i][j];
		}
	}
}

void cells_in_row(int *num_elem_in_row, const int row, const int col, int *h_check_matrix)
{
	for (int i=0, a=0; i<row; i++)
	{
		a = 0;
		for (int j=0; j<col; j++)
		{	 
			if (  (  h_check_matrix[i * col + j]  )  != 0) 
			{
				a++;
			}
		}
		num_elem_in_row[i] = a ; 
	}
}

void h_compact(int *num_elem_in_row, const int row, const int col, int *h_check_matrix, int **h_check_matrix_compact )
{
	for (int i = 0; i < row; i++)
	{	
		for (int j = 0, k = 0; j < col; j++)
		{
			if (   (  h_check_matrix[i * col + j]  ) == 1)
			{	
				h_check_matrix_compact[i][k] = j;
				k++;
			}
		}
	}
}

void hard_decision(int row, const int col, int *num_elem_in_row, int sindrom, int iteration_counter, int counter, int *y_received_codeword,
	int **h_check_matrix_compact, int *c_bit_nodes, int **f_check_nodes)

{
	c_bit_nodes_from_y(y_received_codeword, c_bit_nodes, col );
	//codeword_cout((char *)"c_bit_nodes", c_bit_nodes, col );

	for ( iteration_counter; (sindrom != 0 && iteration_counter < counter); iteration_counter++)
	{
		f_check (h_check_matrix_compact, c_bit_nodes, f_check_nodes, row, num_elem_in_row );

		parity (f_check_nodes, row, num_elem_in_row );

		vote (num_elem_in_row, h_check_matrix_compact, row, col, y_received_codeword, c_bit_nodes, f_check_nodes );

		sindrom = matr_vec_mult( h_check_matrix_compact, c_bit_nodes, row, num_elem_in_row );
	}
}

// *(*(matrix+i)+j); если		int **h_check_matrix_compact
// arr[ i * col + j] = 123;		int* arr 



//void cells_in_col(int *num_elem_in_col, const int row, const int col, int *h_check_matrix)
//{
//	for (int i=0, a=0; i<col; i++)
//	{
//		a = 0;
//		for (int j=0; j<row; j++)
//		{	 
//			if (  (  h_check_matrix[i + row * j]  )  != 0) 
//			{
//				a++;
//			}
//		}
//		num_elem_in_col[i] = a ; 
//	}
//}
