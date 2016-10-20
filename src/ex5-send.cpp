#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
	int rank, size, payment, i;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (rank == 0) {
		payment = 1;
		for (i = 1; i < size; ++i) {
			printf("[%d]: paying %d pound to %d.\n", rank, payment, i);
			fflush(stdout);
			MPI_Send(&payment, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
			
		}
	}
	else {
		MPI_Recv(&payment, 1, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("[%d]: %d pound earned!\n", rank, payment);
		fflush(stdout);
	}

	MPI_Finalize();
	return 0;
}