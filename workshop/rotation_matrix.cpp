#include <vector>
#include <iostream>
#include <cmath>

void print_matrix(const std::vector<double> & M, int nrows, int ncols);
void fill_matrix(std::vector<double> & M, const int nrows, const int ncols, const int nIndex, const double thetha);

int main(int argc, char **argv){

    if(argc != 7){
        std::cerr << "Usage: error in arguments, expected ( vx vy vz thetha X thetha Y thetha Z )";
    }
    
    //create the vector and vector angles
    std::vector<double> myVector(3), mythetha(3);

    // fill the vectors
    for(int ii = 0; ii < myVector.size(); ii++){
        myVector[ii] = std::stod(argv[ii+1]);
        mythetha[ii] = std::stod(argv[ii+3]);
    }

    //create matrix 
    const int M = 3;
    const int range =M*M;
    std::vector<double> Rx(range), Ry(range),Rz(range);
  
    fill_matrix(Rx,M,M,0,mythetha[0] );
    fill_matrix(Ry,M,M,1, mythetha[1]);
    fill_matrix(Rz,M,M,2,mythetha[2]);

    //print
    print_matrix(Rx,M,M);
    print_matrix(Ry,M,M);
    print_matrix(Rz,M,M);
    

    return 0;
}


void fill_matrix(std::vector<double> & M, const int nrows, const int ncols,const int nIndex,const double thetha){

    //algorithm for fill the matrix of rotation
    std::vector<int> vectorAux{0,1,1,0};
    auto myAux=[](double angle,int nterm){ 
        if( nterm == 0){
            return std::cos(angle);
        }else{
            return std::sin(angle);
        }

    };
    int Nterm=0;
    for (int ii = 0; ii < nrows; ii++){
        for (int jj = 0; jj < ncols; jj++){

            if(ii != nIndex and jj != nIndex){
                M[ii*ncols + jj] = myAux(thetha,vectorAux[Nterm]);
                Nterm ++;
            }else if(ii == jj){
                M[ii*ncols + jj] = 1;
            }else{
                M[ii*ncols + jj] = 0;
            }

        }
    }

}

void print_matrix(const std::vector<double> & M, int nrows, int ncols){
    //std::cout.setf(std::ios::scientific);
    //td::cout.precision(15);

    for (int ii = 0; ii < nrows; ++ii) {
        for (int jj = 0; jj < ncols; ++jj) {
            std::cout << M[ii*ncols + jj] << " "; // (ii, jj) = ii*NCOLS + jj
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}



/*
TODO////////////////////////////////

1.Make a Basic program cpp and dependences (vector, iostream, )
2.get the vector (vx,vy,vz) and the angles (theta x, theta y, theta z) for line command 
3.define the matrix for the vector like as Rz, Rx, Ry following the examples
4.define the multiplications of matrix, like 
*/

/*
    for (int ii = 0; ii < nrows; ii++){
        //
        if(ii == i){
            for (int jj = 0; jj < ncols; jj++){
                if(jj == ii){
                    M[ii*ncols + jj] = 1;
                }
                else{
                    M[ii*ncols + jj] = 0;
                }
            }
        }else{
             for (int jj = 0; jj < ncols; jj++){
                if(jj == j){
                    M[ii*ncols + jj] = 0;
                }else{
                    M[ii*ncols + jj] = 2;
                }
            }
        }

    }


*/


 /*

     for (int ii = 0; ii < nrows; ii++){
        for (int jj = 0; jj < ncols; jj++){
            M[ii*ncols + jj] = 0;
        }
    }
 
 
 */
