#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[])
{
	int rank, size, i, j;
	int old_row[3], new_row[3], mtx[3][3];

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (size != 3) {
		if( rank == 0)
			fprintf(stderr, "This program is designed to run with 3 processes");
		MPI_Finalize();
		return 1;
	}

	// Initialise the row owned by this process
	old_row[0] = 3 * rank + 0; old_row[1] = 3 * rank + 1; old_row[2] = 3 * rank + 2;

	// Mixed up the data with the other processes
	MPI_Alltoall(old_row, 1, MPI_INT, new_row, 1, MPI_INT, MPI_COMM_WORLD);

	// Bring all data to the root process for printing on screen
	MPI_Gather(new_row, 3, MPI_INT, mtx, 3, MPI_INT, 0, MPI_COMM_WORLD);

	// Do the actual printing
	if (rank == 0)
		for (i = 0; i < size; ++i) {
			printf("\n[%d]: ", rank);
			for (j = 0; j < size; ++j) {
				printf("%d ", mtx[i][j]);
			}
		}


	MPI_Finalize();
	return 0;
}