/*
Program of two matrices of user defined size dynamically.
We Perform following functions separately.

• Addition
• Subtraction
• Multiplication
• Transpose

*/
#include<iostream>
// All Functions Prototype.
void calculate_addition(int rows1, int columns1,int rows2, int columns2,int **ptr1, int **ptr2);
void calculate_subtraction(int rows1, int columns1,int rows2, int columns2,int **ptr1, int **ptr2);
void calculate_multiplication(int rows1, int columns1,int rows2, int columns2,int **ptr1, int **ptr2);
void calculate_transpose(int rows1, int columns1,int rows2, int columns2,int **ptr1, int **ptr2);
using namespace std;

int main()
{
	int rows1,columns1;
	cout<<"Enter number of rows of matrix 1: ";// Prompt user to enter size of Matrix that is rows & columns of Matrix1.
	cin>>rows1;
	cout<<"Enter number of columns 1: ";
	cin>>columns1;
	
	// Declare 2D array for Matrix 1.

	   // Pointer to Pointer Declaration of 2D array.
	int **ptr1 =new int*[rows1]; //Dynamically allocating rows of matix 1.
	
	for(int i=0 ;i<rows1; i++)
	{
		ptr1[i]= new int[columns1];//Dynamically allocating columns of matix 1.
	}

	
	
	cout<<"Enter array elements 1: ";
	for(int i=0; i<rows1;i++)    
	{
		for(int j=0; j<columns1; j++)
		{
			cin>> ptr1[i][j];         //Prompt user to enter elements of Matrix 1.
		}
	}
	

    int rows2,columns2;        // Prompt user to enter size of Matrix that is rows & columns of Matrix2.
	cout<<"Enter number of rows of matrix 2: ";
	cin>>rows2;
	cout<<"Enter number of columns 2: ";
	cin>>columns2;
	
	int **ptr2 =new int*[rows2];  //Dynamically allocating rows of matix 2.
	
	for(int i=0;i<rows2;i++)
	{
		ptr2[i] = new int[columns2]; //Dynamically allocating columns of matix 2.
	}
	
	cout<<"Enter array elements 2: ";
	for(int i=0; i<rows2;i++)
	{
		for(int j=0; j<columns2; j++)
		{
			cin>> ptr2[i][j];       //Prompt user to enter elements of Matrix 2.
		}
	}
	
    
	// Function Calling.
	calculate_addition(rows1,columns1,rows2,columns2, ptr1, ptr2);
	calculate_subtraction(rows1,columns1,rows2,columns2,  ptr1, ptr2);
	calculate_multiplication(rows1,columns1,rows2,columns2, ptr1, ptr2);
	calculate_transpose(rows1,columns1,rows2,columns2, ptr1, ptr2);
	
	for(int i=0; i <rows1; i++) //Deallocating memory of rows of matrix 1
	{
	 delete[]ptr1[i];
   }
     delete[] ptr1;  //Deallocating Pointer to matrix 1.
     
	
	for(int i=0; i <rows2; i++) //Deallocating memory of rows of matrix 2
	{
	delete[]ptr2[i];
   }
	delete[]ptr2; //Deallocating Pointer to matrix 2.
	
	return 0;
}
// Function calculate addition of both matrices.
void calculate_addition(int rows1, int columns1,int rows2, int columns2,int **ptr1, int **ptr2) 
{
	int **addition_of_matrices = new int*[rows1];//Dynamically allocate resultant matrix (rows) of addition.
	
    for (int i = 0; i < rows1; ++i) {
        addition_of_matrices[i] = new int[columns1];//Dynamically allocate resultant matrix (columns) of addition.
    }
	
	if (rows1 != rows2 || columns1 != columns2)// For addition of matrices the order of both matrices must be equal.
	{
        cout << "Matrices can't be added!" << endl;
        return;
    }

    
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns1; j++) {
        	
            addition_of_matrices[i][j] = ptr1[i][j] + ptr2[i][j];//Addition of rows and columns of both matrices.
        }
        cout << endl;
    }
    cout<<"Addition of Matrices 1 & 2 is: \n";
     for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns1; j++) {
            cout<< addition_of_matrices[i][j]<<" ";//Printing the resultant addition matrix.
        }
        cout << endl;
    }
    // Deallocate memory for result addition matrix.
    for (int i = 0; i < rows1; ++i) {
        delete[] addition_of_matrices[i];//Deallocating first rows of matrix.
    }
    delete[] addition_of_matrices;//Deallocating whole matrix.

}

// Function calculate subtraction of both matrices.
void calculate_subtraction(int rows1, int columns1,int rows2, int columns2,int **ptr1, int **ptr2)
{
	int **subtraction_of_matrices = new int*[rows1];//Dynamically allocate resultant matrix (rows) of addition.
	for (int i = 0; i < rows1; ++i) {
        subtraction_of_matrices[i] = new int[columns1];
    }

	if (rows1 != rows2 || columns1 != columns2) // For subtraction of matrices the order of both matrices must be equal.
	{
        cout << "Matrices should have the same dimensions for subtraction." << endl;
        return;
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns1; j++) {
            subtraction_of_matrices[i][j] = ptr1[i][j] - ptr2[i][j];//Subtraction of rows and columns of both matrices.
        }
        cout << endl;
    }
    cout<<"Subtraction of Matrices 1 & 2 is: \n";
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns1; j++) {
            cout<<subtraction_of_matrices[i][j]<< " ";//Printing the resultant subtraction matrix.
        }
        cout << endl;
    }
    // Deallocate memory for result matrix
    for (int i = 0; i < rows1; ++i) {
        delete[] subtraction_of_matrices[i];//Deallocating first rows of matrix.
    }
    delete[] subtraction_of_matrices;//Deallocating whole matrix.
}
// Function calculate multiplication of both matrices.
void calculate_multiplication(int rows1, int columns1,int rows2, int columns2,int **ptr1, int **ptr2)
{
	
    if (columns1 != rows2)//In order to multiply 2 matrices columns of 1 matrix should be equal to rows of 2 matrix.
	{
        cout << "Matrices can't be multiplied." << endl;//If condition fail.
        return;
    }

    int **multiplication_of_matrices = new int *[rows1];//Dynamically allocate resultant matrix (rows) of multiplication.
    for (int i = 0; i < rows1; ++i) {
        multiplication_of_matrices[i] = new int[columns2];//Dynamically allocate resultant matrix (columns) of addition.
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            multiplication_of_matrices[i][j] = 0;//On each iteration of rows and columns empty the value multiplication matrix.
            for (int k = 0; k < columns1; k++) {
            	//elements are multiplied and same rows elements should be added to each other.
                multiplication_of_matrices[i][j] += ptr1[i][k] * ptr2[k][j];
            }
        }
    }

    cout << "Multiplication of Matrices 1 & 2 is: \n";
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            cout << multiplication_of_matrices[i][j] << " ";//Print the resultant multiplication matrix. 
        }
        cout << endl;
    }

    // Deallocate memory for result matrix
    for (int i = 0; i < rows1; ++i) {
        delete[] multiplication_of_matrices[i];//Deallocating the rows of multiplication matrix.
    }
    delete[] multiplication_of_matrices;//Deallocating whole pointer.

}
// Transpose of matrix means converting rows to columns and vice versa.
void calculate_transpose(int rows1, int columns1, int rows2, int columns2, int **ptr1, int **ptr2)
{
    int **transpose_matrix1 = new int *[columns1];//Dynamically allocate Transpose matrix1 (columns).
    for (int i = 0; i < columns1; ++i) {
        transpose_matrix1[i] = new int[rows1];//Dynamically allocate Transpose matrix1 (rows).
    }
    for (int i = 0; i < columns1; i++) {
        for (int j = 0; j < rows1; j++) {
            transpose_matrix1[i][j] = ptr1[j][i];//change rows and columns of matrix1.
        }
    }

    cout << "Transpose matrix 1 is:" << endl;
    for (int i = 0; i < columns1; i++) {  // Iterate up to columns1
        for (int j = 0; j < rows1; j++) {
            cout << transpose_matrix1[i][j] << " ";//Print the resultant transpose matrix.
        }
        cout << endl;
    }

    int **transpose_matrix2 = new int *[columns2];//Dynamically allocate Transpose matrix2 (columns).
    for (int i = 0; i < columns2; ++i) {
        transpose_matrix2[i] = new int[rows2];//Dynamically allocate Transpose matrix2 (rows).
    }

    for (int i = 0; i < columns2; i++) {
        for (int j = 0; j < rows2; j++) {
            transpose_matrix2[i][j] = ptr2[j][i];//change rows and columns of matrix1.
        }
    }

    cout << "Transpose matrix 2 is:" << endl;
    for (int i = 0; i < columns2; i++) {  // Iterate up to columns2
        for (int j = 0; j < rows2; j++) {
            cout << transpose_matrix2[i][j] << " ";//Print the resultant transpose matrix.
        }
        cout << endl;
    }

    // Deallocate memory for transpose matrix 1.
    for (int i = 0; i < columns1; ++i) {
        delete[] transpose_matrix1[i];
    }
    delete[] transpose_matrix1;
 
	// Deallocate memory for transpose matrix 1.
    for (int i = 0; i < columns2; ++i) {
        delete[] transpose_matrix2[i];
    }
    delete[] transpose_matrix2;
}
