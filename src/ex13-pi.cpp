#include <stdio.h> 
#include <math.h> 
#include <mpi.h>

#define N 100000000

int main( int argc, char *argv[] ) 
{ 
    int rank, size, i; 
    double PI25DT = 3.141592653589793238462643, mypi, pi, h, x;

    MPI_Init(&argc,&argv); 
    MPI_Comm_size(MPI_COMM_WORLD,&size); 
    MPI_Comm_rank(MPI_COMM_WORLD,&rank); 

    mypi = 0.0; h = 1.0 / (double) N; 
    for (i = rank + 1; i <= N; i += size) { 
        x = h * ((double)i - 0.5);  mypi += h * (4.0 / (1.0 + x*x)); 
    }

    MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD); 
    if (rank == 0)  
        printf("pi is approximately %.16f, Error is %.16f\n", pi, pi - PI25DT); 

    MPI_Finalize(); 
    return 0; 
} 