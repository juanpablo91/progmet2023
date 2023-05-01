#include <iostream>
#include <vector>
#include "matrix.h"


/*
Carlos Adrian Nieto
Juan Pablo Gonzalez Rodriguez
Pablo Jose Montoya Barraza
Juan Angel Ruiz Sanchez
*/

int main(int argc, char **argv){
    if (argc != 2) {
      std::cerr << "Error. Usage:\n"
                << argv[0] << " M N\n"
                << "M : Rows = Columns\n";

      return 1;
    }
    const int M = std::stoi(argv[1]);
    const int N = M;

    // allocate memory for the matrix
    std::vector<double> A(M*N);

    //fill the matrix with funcion Hilbert 
    fill_hilbert(A, M, N);

    // calculate the trace 
    double trace = 0.0;
    trace = compute_trace(A,M,N);

    //Print
    print_matrix(A,M,N);
    std::cout << "\n" << "trace: " << trace << "\n";

}