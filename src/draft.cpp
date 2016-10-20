#include <stdio.h>
#include <mpi.h>

int main (int argc, char *argv[])
{
  MPI_Init (&argc, &argv);	/* starts MPI */

  int rank, size;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  printf("My rank is %d", rank);
  printf("The world's size is %d", size);

  MPI_Finalize();
  return 0;
}
