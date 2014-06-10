//10.06.2014---21-10-00
#include "algorithm.h"
#include "tools.h"

int main()
{
	const int row = 4; // �����	 � ����������� ������� H
	const int col = 8; // �������� � ����������� ������� H
	int h_check_matrix [row][col]; // ����������� ������� H
	int y_received_codeword[col];  // �������� ������� �����
	int c_bit_nodes[col]; // ���� ���������� Y � ��������� ��������� ������

	int sindrom  = 1;
	int iteration_counter = 0;
	int counter = 2;

	int num_elem_in_col[col] = {0};
	int *num_elem_in_row = new int[row];// ��� ���������������� num_elem_in_row

	int **h_check_matrix_compact = new int* [row]; // ����� �� ��� ������� � �������
	int **f_check_nodes = new int* [row];
	for (int i = 0, q  = 0; i < row; i++)
	{	
		q = num_elem_in_row[i];
		h_check_matrix_compact[i] = new int [q];
		f_check_nodes[i] = new int [q];
	}


	read_h_check_matrix( *h_check_matrix, row, col );// ��������� ������� H �� �����
	//matrix_cout("h_check_matrix", row, col, h_check_matrix);

	cells_in_row( num_elem_in_row, row, col, &h_check_matrix[0][0] );// ����� ����� � ������� h_check_matrix_compact
	codeword_cout("num_elem_in_row", num_elem_in_row, col );


	h_compact( num_elem_in_row, row, col, *h_check_matrix, h_check_matrix_compact ); //������������ ������ ������� �� H
	matrix_cout("h_check_matrix_compact", row, num_elem_in_row, h_check_matrix_compact);


	read_y_received_codeword( y_received_codeword, col);
	codeword_cout("y_received_codeword", y_received_codeword, col);


	sindrom = matr_vec_mult( h_check_matrix_compact, y_received_codeword, row, num_elem_in_row );
	cout <<"sindrom =   " << sindrom <<endl;

	if (sindrom != 0 )
	{
		hard_decision(row, col, num_elem_in_row, sindrom, iteration_counter, counter, y_received_codeword,
			h_check_matrix_compact, c_bit_nodes, f_check_nodes);
	}

	true_codeword_output( iteration_counter,  counter,  c_bit_nodes, col );
	wr_in_file (iteration_counter,  counter,  c_bit_nodes, col);

	// ������������� ������ ��������� ��� ��������� ������������ ������:
	for (int count = 0; count < row; count++)
	{
		delete [] h_check_matrix_compact[count];
		h_check_matrix_compact[count] = NULL;

		delete [] f_check_nodes[count];
		f_check_nodes[count] = NULL;
	}
	delete num_elem_in_row;
	num_elem_in_row = NULL;

	cout << endl;
	system("pause"); // ������� �������� ������  
	return 0;
}