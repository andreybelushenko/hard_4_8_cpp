//03.06---23-00
#include "algorithm.h"
#include "tools.h"

#include <fstream>


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

	ind_c(h_check_matrix, c_node_index_matrx);

	ind_f(h_check_matrix , f_node_index_matrx);

	int iteration_counter = 0;
	for ( iteration_counter; (sindrom != 0 && iteration_counter < counter); iteration_counter++)
	{
		f_check (h_check_matrix , c_bit_nodes, f_check_nodes);

		parity (f_check_nodes, parity_check);

		bit_nodes (f_node_index_matrx, c_node_index_matrx, parity_check, bit_nodes_matrix );

		vote (y_received_codeword, bit_nodes_matrix, c_bit_nodes);

		sindrom = matr_vec_mult(h_check_matrix, c_bit_nodes);
	}

	true_codeword_output( iteration_counter,  counter,  c_bit_nodes );
//////////////////////////////////////////
	ofstream out;
	out.("true_codeword_output_file.txt");
	//if (in == NULL) return 1;
		in << "true received_codeword:  ";
		for  (int i = 0; i < 8; i++)
		{
			in <<c_bit_nodes[i];
		}
	//close();
//////////////////////////////////// #include <fstream>
	cin.get();
	return 0;
}
