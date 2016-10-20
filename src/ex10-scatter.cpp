#include <stdio.h>
#include <string.h>
#include <mpi.h>

int some_complicated_computation(int w) { return 2 * w;  }

int main(int argc, char *argv[])
{
	int rank, size, i;
	int inputs[3]  = { 1,2,3 };
	int outputs[3] = { 0,0,0 };
	int my_input, my_output;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (size != 3) {
		if( rank == 0)
			fprintf(stderr, "This program is designed to run with 3 processes");
		MPI_Finalize();
		return 1;
	}

	MPI_Scatter(inputs, 1, MPI_INT, &my_input, 1, MPI_INT, 0, MPI_COMM_WORLD);
	my_output = some_complicated_computation(my_input);
	MPI_Gather(&my_output, 1, MPI_INT, outputs, 1, MPI_INT, 0, MPI_COMM_WORLD);

	if (rank == 0)
		for (i = 0; i < size; ++i)
			printf("[%d]: output received from %d: %d\n", rank, i, outputs[i]);

	MPI_Finalize();
	return 0;
}