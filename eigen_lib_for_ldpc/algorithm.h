#include <iostream>
using namespace std;

void c_bit_nodes_from_y(int y_received_codeword[8], int c_bit_nodes[8]);

int matr_vec_mult(int h_check_matrix [4][8], int y_received_codeword[8]);

void f_check (int h_check_matrix[4][8] , int c_bit_nodes[8], int f_check_nodes[4][4]);

void parity (int f_check_nodes[4][4], int parity_check[4][4]);

void bit_nodes (int f_node_index_matrx[8][2], int c_node_index_matrx[4][4], int parity_check[4][4], int bit_nodes_matrix[8][2] );

void vote (int y_received_codeword[8], int bit_nodes_matrix[8][2], int c_bit_nodes[8]);

void ind_c( int h_check_matrix[4][8] , int c_node_index_matrx[4][4]);

void ind_f(int h_check_matrix[4][8] , int f_node_index_matrx[8][2]);