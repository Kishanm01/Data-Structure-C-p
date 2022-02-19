// Name:        Kishan Mistry
// Class:       CS 3305/Section 03
// Term:        Fall 2021
// Instructor:  Dr. Haddad
// Assignment:  9

#include <iostream>  // Provides input/output stream
#include <limits>    // Provides limit for removing unnecessary characters after string input for menu command.
#include <cassert>   // Provides assert command for restricting matrix size less than 5.

using namespace std;

// Maximum nodes computed.
const size_t MAX_NODE = 5;

// Matrix size for a given graph.
static int matrixSize;
// Input matrix, maximum of 5 adjancey matrices and reachability matrix with the size of MAX_NODE
static int matrixA1[MAX_NODE][MAX_NODE];
static int matrixA2[MAX_NODE][MAX_NODE];
static int matrixA3[MAX_NODE][MAX_NODE];
static int matrixA4[MAX_NODE][MAX_NODE];
static int matrixA5[MAX_NODE][MAX_NODE];
static int matrixR[MAX_NODE][MAX_NODE];

// POSTCONDITION: The user has been prompted for a integer value.
int get_command();
// Display the menu option
void display_menu();
// Clears the matrices with prior values.
void clearMatrices();
// Intialize all matrices by asking the user of number of nodes, clearing matrices of previous values, reading graph values, and computing adjancey and reachability matrices.
void initMatrix();

// PRE CONDITION: All matrices are appropriate data filled
// POST CONDITION: Print out the input matrix.
template <size_t rows, size_t cols>
void printMatrix (int (&matrix)[rows][cols]);

// PRE CONDITION: All matrices are appropriate data filled
// POST CONDITION: Print out the graph reachability matrix.
void reachabilityMatrix();

// PRE CONDITION: matrixA and matrixB is declared and initialized.
// POST CONDITION: matrixB is filled by using Warshall’s Algorithm.
template <size_t rows, size_t cols>
void adjacencyMatrix(int (&MatrixA)[rows][cols], int (&MatrixB)[rows][cols]);

// PRE CONDITION: All matrices are appropriate data filled
// POST CONDITION: Compute and print out the In-degree of each node of the graph.
void inDegree();

// PRE CONDITION: All matrices are appropriate data filled
// POST CONDITION: Compute and print out the Out-degree for each node of the graph. 
void outDegree();

// PRE CONDITION: All matrices are appropriate data filled
// POST CONDITION: Returns the total number of loops (also known as self-loops) in given matrix.
template <size_t rows, size_t cols>
int selfLoops(int (&matrix)[rows][cols]);

// PRE CONDITION: All matrices are appropriate data filled
// POST CONDITION: Returns he total number of cycles of length N (N is the number of nodes in the inputted graph).
int numCycleLengthN(size_t N);

// PRE CONDITION: All matrices are appropriate data filled
// POST CONDITION: Returns the total number of paths of length N edges (N is the number of nodes in the inputted graph).
int numPathsLengthN(size_t N);

// PRE CONDITION: All matrices are appropriate data filled
// POST CONDITION: Returns the total number of paths of length 1 to N edges (N is the number of nodes in the inputted graph).
int numPathsLength1ToN();

// PRE CONDITION: All matrices are appropriate data filled
// POST CONDITION: Returns the total number of cycles length 1 to N edges (N is the number of nodes in the inputted graph).
int numCycleLength1ToN();

// PRE CONDITION: Matrices are initialized with data.
// Post Condition: prints the graph data with appropriate headings.
void printGraphData();

// POSTCONDITION: The user has been prompted for a integer value.
int get_command() {
	int command;
	cout << endl << "Enter Option Number: ";
	cin >> command;
	if (cin.fail()) {                                          // Check if user entered value other than int
		cin.clear();										   // Clear cin errors
		cin.ignore(numeric_limits<streamsize>::max(), '\n');   // Move the cin cursor to the next line by ignoring the rest of input on the line
	}
	return command;
}

// Display the menu option
void display_menu() {
	cout << endl << "---MAIN MENU---" << endl;
	cout << "1 - Enter Graph Data" << endl;
	cout << "2 - Print Outputs" << endl;
	cout << "3 - Exit Program" << endl;
	cout << "---------------" << endl;
}

// Intialize all matrices by asking the user of number of nodes, clearing matrices of previous values, reading graph values, and computing adjancey and reachability matrices.
void initMatrix() {
	// Ask user of number of nodes in the graph with maximum nodes being 5.
	cout << "Enter the number of nodes in the graph (Maximum size - 5): ";
	cin >> matrixSize;
	assert(matrixSize < 6);
	
	// Clear all matrices before filling matrices with user's value and adjancey matrices
	clearMatrices();
	
	// Read the user's values row by row and column by column.
	cout << endl << "Reading value for adjency matrix row-by-row:" << endl;
	for(int i = 0; i < matrixSize; i++) {
		for(int j = 0; j < matrixSize; j++) {
			cout << "Enter A1[" << i << "," << j << "]: ";
			int value;
			cin >> value;
			matrixA1[i][j] = value;
		}
	}
	
	// Switch-case method used to fill in adjancey matrices unitl it matches the number of nodes equals.
	switch(2) {
		case 2:
			adjacencyMatrix(matrixA1, matrixA2);
			if(matrixSize == 2)
				break;
		case 3:
			adjacencyMatrix(matrixA2, matrixA3);
			if(matrixSize == 3)
				break;
		case 4:
			adjacencyMatrix(matrixA3, matrixA4);
			if(matrixSize == 4)
				break;
		case 5:
			adjacencyMatrix(matrixA4, matrixA5);
			if(matrixSize == 5)
				break;
	}
	
	// Fill in the reachability matrix with all adjacency matrix filled.
	reachabilityMatrix();
}

// Clears the matrices with prior values.
void clearMatrices() {
	for(int i = 0; i < MAX_NODE; i++) {
		for(int j = 0; j < MAX_NODE; j++) {
			matrixA1[i][j] = 0;
			matrixA2[i][j] = 0;
			matrixA3[i][j] = 0;
			matrixA4[i][j] = 0;
			matrixA5[i][j] = 0;
			matrixR[i][j] = 0;
		}
	}
}

// PRE CONDITION: matrixA and matrixB is declared and initialized.
// POST CONDITION: matrixB is filled by using Warshall’s Algorithm.
template <size_t rows, size_t cols>
void adjacencyMatrix(int (&MatrixA)[rows][cols], int (&MatrixB)[rows][cols]) {
	// Using Warshall’s Algorithm to multiply two matrices and return values to matrixB
	for(int i = 0; i < matrixSize; i++) {
		for(int j = 0; j < matrixSize; j++) {
			for(int k = 0; k < matrixSize; k++) {
				MatrixB[j][k] = MatrixB[j][k] + (matrixA1[j][i] * MatrixA[i][k]);
			}
		}
	}
}

// PRE CONDITION: All matrices are appropriate data filled
// POST CONDITION: Print out the input matrix.
template <size_t rows, size_t cols>
void printMatrix(int (&matrix)[rows][cols]) {
	// Print matrix values
	for(int i = 0; i < matrixSize; i++) {
		for(int j = 0; j < matrixSize; j++) {
			cout << matrix[i][j] << "  ";
		}
		cout << endl;
	}
}

// PRE CONDITION: All matrices are appropriate data filled
// POST CONDITION: Print out the graph reachability matrix.
void reachabilityMatrix() {
	// Adding matrices to  matrixR by using the Warshall’s Algorithm.
	for(int i = 0; i < matrixSize; i++) {
		for(int j = 0; j < matrixSize; j++) {
			// Add values of all adjancey matrices to reachability matrix.
			matrixR[i][j] = matrixA1[i][j] + matrixA2[i][j] + matrixA3[i][j] + matrixA4[i][j] + matrixA5[i][j];
		}
	}
}

// PRE CONDITION: All matrices are appropriate data filled
// POST CONDITION: Compute and print out the In-degree of each node of the graph.
void inDegree() {
	// double for loop for adding values for column by column.
	// Difference from out-degree is j loop is parent and i loop is inside.
	for(int j = 0; j < matrixSize; j++) {
		int sum = 0;
		for(int i = 0; i < matrixSize; i++) {
			sum += matrixA1[i][j];
		}
		cout << "Node " << (j + 1) << " in-degree is " << sum << endl;
	}
}

// PRE CONDITION: All matrices are appropriate data filled
// POST CONDITION: Compute and print out the Out-degree for each node of the graph. 
void outDegree() {
	
	// double for loop for adding values for rows by rows.
	for(int i = 0; i < matrixSize; i++) {
		int sum = 0;
		for(int j = 0; j < matrixSize; j++) {
			sum += matrixA1[i][j];
		}
		cout << "Node " << (i + 1) << " out-degree is " << sum << endl;
	}
}

// PRE CONDITION: All matrices are appropriate data filled
// POST CONDITION: Returns the total number of loops (also known as self-loops) in the graph.
template <size_t rows, size_t cols>
int selfLoops(int (&matrix)[rows][cols]) {
	int selfLoops = 0;
	for(int i = 0; i < matrixSize; i++) {
		// matricx[i][i] in-degree and out-degree of (0,0), (1.1) ... => self loop
		selfLoops += matrix[i][i];
	}
	return selfLoops;
}

// PRE CONDITION: All matrices are appropriate data filled
// POST CONDITION: Returns he total number of cycles of length N (N is the number of nodes in the inputted graph).
int numCycleLengthN(size_t N) {
	int cycles = 0;
	// With the switch-case statement, returns total number of cycles of n length based on adjancey matrices
	switch(N) {
		case 1:
			cycles = selfLoops(matrixA1);
			break;
		case 2:
			cycles = selfLoops(matrixA2);
			break;
		case 3:
			cycles = selfLoops(matrixA3);
			break;
		case 4:
			cycles = selfLoops(matrixA4);
			break;
		case 5:
			cycles = selfLoops(matrixA5);
			break;
		default:
			cout << "Invalid matrix length!" << endl;
			break;
	}
	return cycles;
}

// PRE CONDITION: All matrices are appropriate data filled
// POST CONDITION: Returns the total number of paths of length N edges (N is the number of nodes in the inputted graph).
int numPathsLengthN(size_t N) {
	
	// With the switch-case statement, returns total number of paths of n length based on adjancey matrices
	int paths = 0;
	switch(N) {
		case 1:
			for(int i = 0; i < matrixSize; i++) {
				for(int j = 0; j < matrixSize; j++) {
					paths += matrixA1[i][j];
				}
			}
			break;
		case 2:
			for(int i = 0; i < matrixSize; i++) {
				for(int j = 0; j < matrixSize; j++) {
					paths += matrixA2[i][j];
				}
			}
			break;
		case 3:
			for(int i = 0; i < matrixSize; i++) {
				for(int j = 0; j < matrixSize; j++) {
					paths += matrixA3[i][j];
				}
			}
			break;
		case 4:
			for(int i = 0; i < matrixSize; i++) {
				for(int j = 0; j < matrixSize; j++) {
					paths += matrixA4[i][j];
				}
			}
			break;
		case 5:
			for(int i = 0; i < matrixSize; i++) {
				for(int j = 0; j < matrixSize; j++) {
					paths += matrixA5[i][j];
				}
			}
			break;
		default:
			cout << "Invalid matrix length!" << endl;
			break;
	}
	return paths;
}

// PRE CONDITION: All matrices are appropriate data filled
// POST CONDITION: Returns the total number of paths of length 1 to N edges (N is the number of nodes in the inputted graph).
int numPathsLength1ToN() {
	int paths = 0;
	for(int i = 0; i < matrixSize; i++) {
		for(int j = 0; j < matrixSize; j++) {
			paths += matrixR[i][j];
		}
	}
	return paths;
}

// PRE CONDITION: All matrices are appropriate data filled
// POST CONDITION: Returns the total number of cycles length 1 to N edges (N is the number of nodes in the inputted graph).
int numCycleLength1ToN() {
	int cycles = selfLoops(matrixR);
	return cycles;
}

// PRE CONDITION: Matrices are initialized with data.
// Post Condition: prints the graph data with appropriate headings.
void printGraphData() {
	
	// Print out the input matrix.
	cout << endl << "Input Matrix:" << endl;
	printMatrix(matrixA1);
	
	// Compute and print out the graph reachability matrix.
	cout << endl << "Reachability Matrix:" << endl;
	printMatrix(matrixR);
	
	// Compute and print out the In-degree of each node of the graph.
	cout << endl << "In-degree:" << endl;
	inDegree();
	
	// Compute and print out the Out-degree for each node of the graph.
	cout << endl << "Out-degree:" << endl;
	outDegree();
	
	// Compute and print out the total number of loops (also known as self-loops) in the graph.
	cout << endl << "Total number of self-loops: " << selfLoops(matrixA1) << endl;
	
	// Compute and print out the total number of cycles of length N (N is the number of nodes in the inputted graph).
	cout << "Total number of cycles of length " << matrixSize << " edges: " << numCycleLengthN(matrixSize) << endl;
	
	// Compute and print out the total number of paths of length 1-edge.
	cout << "Total number of paths of length 1 edge: " << numPathsLengthN(1) << endl;
	
	// Compute and print out the total number of paths of length N edges (N is the number of nodes in the inputted graph).
	cout << "Total number of paths of length " << matrixSize << " edges: " << numPathsLengthN(matrixSize) << endl;
	
	// Compute and print out the total number of paths of length 1 to N edges (N is the number of nodes in the inputted graph).
	cout << "Total number of paths of length 1 to " << matrixSize << " edges: " << numPathsLength1ToN() << endl;
	
	// Compute and print out the total number of cycles length 1 to N edges (N is the number of nodes in the inputted graph).
	cout << "Total number of cycles of length 1 to " << matrixSize << " edges: " << numCycleLength1ToN() << endl;
}

int main() {
	int command;
	bool flag = true;
	
	do {
		display_menu();
		command = get_command();
		
		// Force user to choose option 1 to initialize matrices unless option 3 is chosen to quit.
		if (command == 3)
			break;
		else if (flag && command != 1)
			cout << "Please select option 1 to unlock other options." << endl;
		else {
			switch(command) {
				case 1:	{
					initMatrix();
					flag = false;
					break;
				}
				case 2:
					printGraphData();
					break;
				case 3:
					break;
				default:
					cout << "Command invalid! Please try again." << endl;
					break;
			}
		}
	} while (command != 3);
	
	return EXIT_SUCCESS;
}