#include <fstream>
#include <iostream>
#include <stdio.h>
using namespace std;


void true_codeword_output(int iteration_counter, int counter, int c_bit_nodes[8] );

void wr_in_file(int iteration_counter, int counter, int c_bit_nodes[8] );

void read_y_received_codeword(int y_received_codeword[8]);

void read_h_check_matrix(int h_check_matrix [4][8]);

void codeword_cout(char nama[21], int codeword[8]);

//void matrix_cout(char nama[21], int matrix[4][8]);
void matrix_cout(char nama[21], const int row, const int col, int *matrix);