#include "tools.h"

void true_codeword_output(int iteration_counter, int counter, int c_bit_nodes[8] )
{
	if (iteration_counter==counter)
		cout << "codeword was reciewed with error, can't correct  \n";
	else
	{
		cout <<"iteration_counter:   " <<iteration_counter <<endl;
		cout << "true received_codeword:  ";
		for  (int i = 0; i < 8; i++)
		{
			cout <<c_bit_nodes[i];
		}
	}
}