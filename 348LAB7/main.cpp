
#include <iostream>

using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
	int data[SIZE][SIZE];  // 2D array for matrix data (using int for simplicity)

public:
	// 1. Read values from stdin into a matrix
	void readFromStdin() {
		// Go through all positions in the matrix and take user input
		for (int row = 0; row < SIZE; row++) {
			for (int col = 0; col < SIZE; col++) {
				int inputVal;
				// Assign input to a value which is saved to data
				cin >> inputVal;
				data[row][col] = inputVal;
			}
		}
		return;
	}

	// 2. Display a matrix
	void display() const {
		// Prints each value in the data in a user-readable format
		for (int row = 0; row < SIZE; row++) {
			cout << "|\t";
			for (int col = 0; col < SIZE; col++) {
				cout << data[row][col] << "\t";
			}
			cout << "|\n";
		}
	}

	// 3. Add two matrices (operator overloading for +)
	Matrix operator+(const Matrix& other) const {
		// overload by completing matrix addition with the other variable referencing the data from the matrix being added
		Matrix outputMatrix;
		for (int row = 0; row < SIZE; row++) {
			for (int col = 0; col < SIZE; col++) {
				outputMatrix.data[row][col] = data[row][col] + other.data[row][col];
			}
		}
		return outputMatrix;
	}

	// 4. Multiply two matrices (operator overloading for *)
	Matrix operator*(const Matrix& other) const {
		// Similar to the addition overload, just with the extra math needed to complete matrix multiplication
		Matrix outputMatrix;
		for (int row = 0; row < SIZE; row++) {
			for (int col = 0; col < SIZE; col++) {
				double sum = 0;
				for (int product = 0; product < SIZE; product++) {
					sum += data[row][product] * other.data[product][col];
				}
				outputMatrix.data[row][col] = sum;
			}
		}
		return outputMatrix;
	}

	// 5. Compute the sum of matrix diagonal elements
	int sumOfDiagonals() const {
		int diagonalSum = 0;
		// sum up each value by adding the values along both diagonals
		for (int i = 0; i < SIZE; ++i) {


			// add the top-left to bottom-right value and add it to the sum
			diagonalSum += data[i][i];

			// add the top-right to bottom-left value and add it 
			diagonalSum += data[i][SIZE - (i + 1)];
		}

		return diagonalSum;
	}

	// 6. Swap matrix rows
	void swapRows(int row1, int row2) {
		// iterate through the data array and swap the values in the specified rows
		for (int col = 0; col < SIZE; col++) {
			// set a temp val and swap the data accordingly
			int tempRowVal = data[row1][col];
			data[row1][col] = data[row2][col];
			data[row2][col] = tempRowVal;
		}
	}
};

int main() {
	// Example usage:
	Matrix mat1;
	cout << "Enter values for Matrix 1:" << endl;
	mat1.readFromStdin();
	cout << "Matrix 1:" << endl;
	mat1.display();

	Matrix mat2;
	cout << "Enter values for Matrix 2:" << endl;
	mat2.readFromStdin();
	cout << "Matrix 2:" << endl;
	mat2.display();

	Matrix sum = mat1 + mat2;
	cout << "Sum of matrices:" << endl;
	sum.display();

	Matrix product = mat1 * mat2;
	cout << "Product of matrices:" << endl;
	product.display();

	cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

	mat1.swapRows(0, 2);
	cout << "Matrix 1 after swapping rows:" << endl;
	mat1.display();

	return 0;
}
