#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
	int rank, size;
	float data, avg;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	avg = 0.0;
	data = (float)rank;
	MPI_Reduce(&data, &avg, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);
	if( rank == 0 )
		printf("[%d]: average value is %f\n", rank, avg/size);

	MPI_Finalize();
	return 0;
}