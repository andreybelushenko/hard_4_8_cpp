//04.06---23-00
#include "algorithm.h"
#include "tools.h"

int main()
{
	int counter = 2;
	int y_received_codeword[8]; // {1, 1, 0, 1, 0, 1, 0, 1};//true  codeword {1, 0, 0, 1, 0, 1, 0, 1}

	read_y_received_codeword(y_received_codeword);
	char nama1[21] = "y_received_codeword";
	codeword_cout(nama1, y_received_codeword);

	const int row1 = 4;
	const int col1 = 8;
	int h_check_matrix [4][8];
	read_h_check_matrix(h_check_matrix);
	char nama2[21] = "h_check_matrix";
	matrix_cout(nama2, row1, col1, &h_check_matrix[0][0]);
	/*{
		{0, 1, 0, 1, 1, 0, 0, 1},   
		{1, 1, 1, 0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0, 1, 1, 1},
		{1, 0, 0, 1, 1, 0, 1, 0}
	};*/
	

	int c_bit_nodes[8];
	int f_check_nodes[4][4];
	int parity_check [4][4];
	int c_node_index_matrx [4][4];
	int f_node_index_matrx [8][2];
	int bit_nodes_matrix [8][2];

	c_bit_nodes_from_y(y_received_codeword, c_bit_nodes);
	char nama3[21] = "c_bit_nodes";
	codeword_cout(nama3, y_received_codeword);

	int sindrom = matr_vec_mult(h_check_matrix, y_received_codeword);
	cout <<"sindrom =   " << sindrom <<endl;

	ind_c(h_check_matrix, c_node_index_matrx);
	const int row2 = 4;
	const int col2 = 4;
	char nama4[21] = "c_node_index_matrx";
	matrix_cout(nama4, row2, col2, &c_node_index_matrx[0][0]);

	ind_f(h_check_matrix , f_node_index_matrx);
	const int row3 = 8;
	const int col3 = 2;
	char nama5[21] = "f_node_index_matrx";
	matrix_cout(nama5, row3, col3, &f_node_index_matrx[0][0]);

	int iteration_counter = 0;
	for ( iteration_counter; (sindrom != 0 && iteration_counter < counter); iteration_counter++)
	{
		f_check (h_check_matrix , c_bit_nodes, f_check_nodes);
		const int row4 = 4;
		const int col4 = 4;
		char nama6[21] = "f_check_nodes";
		matrix_cout(nama6, row4, col4, &f_check_nodes[0][0]);

		parity (f_check_nodes, parity_check);
		const int row5 = 4;
		const int col5 = 4;
		char nama7[21] = "parity_check";
		matrix_cout(nama7, row5, col5, &parity_check[0][0]);

		bit_nodes (f_node_index_matrx, c_node_index_matrx, parity_check, bit_nodes_matrix );
		const int row6 = 8;
		const int col6 = 2;
		char nama8[21] = "bit_nodes_matrix";
		matrix_cout(nama8, row6, col6, &bit_nodes_matrix[0][0]);

		vote (y_received_codeword, bit_nodes_matrix, c_bit_nodes);
		char nama9[21] = "c_bit_nod after vote";
		codeword_cout(nama9, c_bit_nodes);

		sindrom = matr_vec_mult(h_check_matrix, c_bit_nodes);
	}

	true_codeword_output( iteration_counter,  counter,  c_bit_nodes );
	wr_in_file (iteration_counter,  counter,  c_bit_nodes);
	/////////////////////////////



	






	////////////////////////
	cin.get();
	//system("pause");
	return 0;
}
///100))