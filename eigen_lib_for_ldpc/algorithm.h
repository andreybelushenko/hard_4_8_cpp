#include <iostream>
using namespace std;

void c_bit_nodes_from_y( int *y_received_codeword, int *c_bit_nodes, int col );

int matr_vec_mult( int **h_check_matrix_compact, int *c_bit_nodes, int row, int *num_elem_in_row);

void f_check ( int **h_check_matrix_compact, int *c_bit_nodes, int **f_check_nodes, int row, int  *num_elem_in_row );

void parity (int **f_check_nodes, int row, int  *num_elem_in_row );

void vote (int *num_elem_in_row, int **h_check_matrix_compact, int row, int col, int *y_received_codeword, int *c_bit_nodes, int **f_check_nodes );

//void cells_in_col(int *num_elem_in_col, const int row, const int col, int *h_check_matrix);

void cells_in_row(int *num_elem_in_row, const int row, const int col, int *h_check_matrix);

void h_compact(int *num_elem_in_row, const int row, const int col, int *h_check_matrix, int **h_check_matrix_compact );

void hard_decision(int row, const int col, int *num_elem_in_row, int sindrom, int iteration_counter, int counter, int *y_received_codeword,
	int **h_check_matrix_compact, int *c_bit_nodes, int **f_check_nodes);