#include <stdio.h>
#include <string.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
	int rank, size;
	char buf[100] = "";

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (rank == 0)
		strcpy(buf, "Spread the word!");

	MPI_Bcast(buf, 100, MPI_CHAR, 0, MPI_COMM_WORLD);
	printf("[%d]: %s\n", rank, buf);

	MPI_Finalize();
	return 0;
}