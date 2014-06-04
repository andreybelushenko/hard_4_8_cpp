#include "tools.h"

void true_codeword_output(int iteration_counter, int counter, int c_bit_nodes[8] )
{
	if (iteration_counter==counter)
		cout << "codeword was reciewed with error, can't correct  \n";
	else
	{
		cout << "iteration_counter:   " <<iteration_counter <<endl;
		cout << "true received_codeword:  ";
		for  (int i = 0; i < 8; i++)
		{
			cout <<c_bit_nodes[i];
		}
	}
}


void wr_in_file(int iteration_counter, int counter, int c_bit_nodes[8] )
{
	ofstream fout("true_codeword_output_file.txt"); // создаём объект класса ofstream для записи и связываем его с файлом .txt
	if (iteration_counter==counter)
		fout << "codeword was reciewed with error, can't correct  \n";
	else
	{
		fout << "iteration_counter:   " <<iteration_counter <<endl;
		fout << "true received_codeword:  ";
		for  (int i = 0; i < 8; i++)
		{
			fout <<c_bit_nodes[i];
		}
		fout << endl;
	}
	fout.close(); // закрываем файл
}

 //	  ofstream fout("cppstudio.txt"); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
 //   fout << "Работа с файлами в С++"; // запись строки в файл
 //   fout.close(); // закрываем файл
 //   system("pause");


void read_y_received_codeword(int y_received_codeword[8])
{
	ifstream fin("read_y_received_codeword.txt"); // открыли файл для чтения
	for  (int i = 0; i < 8; i++)
	{
		fin >> y_received_codeword[i];
	}
	fin.close(); // закрываем файл
}


void read_h_check_matrix(int h_check_matrix [4][8])
{
	ifstream fin("read_h_check_matrix.txt"); // открыли файл для чтения
	for  (int i = 0; i < 4; i++)
	{
		for  (int j = 0; j < 8; j++)
		{
			fin >> h_check_matrix [i][j];
		}
	}
	fin.close(); // закрываем файл
}

void codeword_cout(char nama[21], int codeword[8])
{
	cout <<  nama << "  ";
	for  (int i = 0; i < 8; i++)
		{
			cout << codeword[i];
		}
	cout <<endl;
}


//void matrix_cout(char nama[21], int matrix[4][8])
//{
//	cout << endl;
//	cout <<  nama << "  " <<endl;
//	for  (int i = 0; i < 4; i++)
//	{
//		for  (int j = 0; j < 8; j++)
//		{
//			cout << matrix [i][j];
//			cout <<"  ";
//		}
//		cout << endl;
//	}
//	cout << endl;cout << endl;
//}

void matrix_cout(char nama[21], const int row, const int col, int *matrix)
{
	cout << endl;
	cout <<  nama << "  " <<endl;
	int k=0;
	for  (int i = 0; i < row; i++)
	{
		for  (int j = 0; j < col; j++)
		{
			//cout << matrix [i][j];
			cout << *(matrix+(k++));
			cout <<"  ";
		}
		cout << endl;
	}
	cout << endl;cout << endl;
}