#include <fstream>
#include <iostream>
#include <stdio.h>
using namespace std;

void true_codeword_output(int iteration_counter, int counter, int *c_bit_nodes, int col );

void wr_in_file(int iteration_counter, int counter, int *c_bit_nodes, int col );

void read_y_received_codeword(int *y_received_codeword, int col);

void read_h_check_matrix(int *h_check_matrix, int row, int col );

void codeword_cout(char *name, int *codeword, int col );

void matrix_cout(char *name, const int row, int *num_elem_in_row, int **matrix);