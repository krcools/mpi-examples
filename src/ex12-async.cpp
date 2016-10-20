#include <stdio.h>
#include <mpi.h>
#include <chrono>
#include <thread>

void my_work(int r) { std::this_thread::sleep_for(std::chrono::seconds(r)); }

int main(int argc, char *argv[])
{
	const int N = 10000;

	int rank, size, in[N], out[N];
	MPI_Request send_req, recv_req;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	MPI_Isend(&out, N, MPI_INT, (rank + 1) % size, 0, MPI_COMM_WORLD, &send_req);

	my_work(rank + 3);
	printf("[%d]: work finished!\n", rank);

	MPI_Irecv(&in, N, MPI_INT, (rank + size - 1) % size, 0, MPI_COMM_WORLD, &recv_req);

	MPI_Wait(&recv_req, MPI_STATUS_IGNORE);
	printf("[%d]: data received!\n", rank);

	MPI_Finalize();
	return 0;
}