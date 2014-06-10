#include "tools.h"

void true_codeword_output(int iteration_counter, int counter, int *c_bit_nodes, int col )
{
	if (iteration_counter==counter)
		cout << "codeword was reciewed with error, can't correct  \n";
	else
	{
		cout << "iteration_counter:   " <<iteration_counter <<endl;
		cout << "true received_codeword:  ";
		for  (int i = 0; i < col; i++)
		{
			cout <<c_bit_nodes[i];
		}
	}
}

void wr_in_file(int iteration_counter, int counter, int *c_bit_nodes, int col )
{
	ofstream fout("true_codeword_output_file.txt"); // создаём объект класса ofstream для записи и связываем его с файлом .txt
	if (iteration_counter==counter)
		fout << "codeword was reciewed with error, can't correct  \n";
	else
	{
		fout << "iteration_counter:   " <<iteration_counter <<endl;
		fout << "true received_codeword:  ";
		for  (int i = 0; i < col; i++)
		{
			fout <<c_bit_nodes[i]; // запись   в файл
		}
		fout << endl;
	}
	fout.close(); // закрываем файл
}

void read_y_received_codeword(int *y_received_codeword, int col)
{
	ifstream fin("read_y_received_codeword.txt"); // открыли файл для чтения
	for  (int i = 0; i < col; i++)
	{
		fin >> y_received_codeword[i];
	}
	fin.close(); // закрываем файл
}

void read_h_check_matrix(int *h_check_matrix, int row, int col )
{
	ifstream fin("read_h_check_matrix.txt"); // открыли файл для чтения
	for  (int i = 0; i < row; i++)
	{
		for  (int j = 0; j < col; j++)
		{
			fin >> h_check_matrix [ i * col + j];
		}
	}
	fin.close(); // закрываем файл
}

void codeword_cout(char *name, int *codeword, int col )
{
	cout <<  name << "  ";
	for  (int i = 0; i < col; i++)
	{
		cout << codeword[i];
	}
	cout <<endl;
}

void matrix_cout(char *name, const int row, int *num_elem_in_row, int **matrix)
{
	cout << endl <<  name << "  " <<endl;
	for  (int i = 0; i < row; i++)
	{
		for  (int j = 0; j < num_elem_in_row[i]; j++)
		{
			cout << *(*(matrix+i)+j) <<"  ";
		}
		cout << endl;
	}
	cout << endl << endl;
}
