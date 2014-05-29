//

#include <iostream>
//#include <vector>
using namespace std;

int matr_vec_mult(int h_check_matrix [4][8], int y_received_codeword[8]);

int main()
{
	int y_received_codeword[8] = {1, 0, 0, 1, 0, 1, 0, 1};
	int h_check_matrix [4][8]=
	{
		{0, 1, 0, 1, 1, 0, 0, 1},   
		{1, 1, 1, 0, 0, 1, 0, 0},
		{0, 0, 1, 0, 0, 1, 1, 1},
		{1, 0, 0, 1, 1, 0, 1, 0}
	};

	int iteration_counter=0;
	int sindrom =567;

	sindrom = matr_vec_mult(h_check_matrix, y_received_codeword);

	while (sindrom !=0 && iteration_counter<5)
	{
		iteration_counter=iteration_counter+1;

	cout<<"y_received_codeword=  "<< y_received_codeword[8]<<endl;
	}
	cout<<"sindrom=  "<< sindrom<<endl;
	cout<<"h_check_matrix=  "<< h_check_matrix<<endl;
	cin.get();
	return 0;
}


int matr_vec_mult(int h_check_matrix [4][8], int y_received_codeword[8])

	// a[m][n]						h_check_matrix
	// b[] - vect n  elem			y_received_codeword
	// c[] - vect m  elem

{
	int i,m,j,n,sum_sindrom;
	int c[4]={1, 1, 1, 1};
		m=4;
		n=8;
		sum_sindrom=0;

	for (i=0; i<m; i++)  {
	c[i]=0;
	for (j=0; j<n; j++){
		c[i]+=h_check_matrix[i][j]*y_received_codeword[j];
	}
}

for (i=0; i<m; i++)
	sum_sindrom=sum_sindrom+c[i];



return sum_sindrom;
}
