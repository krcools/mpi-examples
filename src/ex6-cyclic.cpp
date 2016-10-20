#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
	int rank, size, recv;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	MPI_Send(&rank, 1, MPI_INT, (rank + 1) % size, 0, MPI_COMM_WORLD);
	MPI_Recv(&recv, 1, MPI_INT, (rank - 1 + size) % size, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

	printf("[%d]: recv = %d\n", rank, recv);
	fflush(stdout);

	MPI_Finalize();
	return 0;
}