#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
	int rank, size;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (rank == 0) {
		printf("[%d]: Workers, work!\n", rank);
		fflush(stdout);
	}
	MPI_Barrier(MPI_COMM_WORLD);
	if (rank != 0)
		printf("[%d]: Yes boss!\n", rank);

	MPI_Finalize();
	return 0;
}