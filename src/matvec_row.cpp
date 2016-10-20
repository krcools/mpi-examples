#include <iostream>
#include <vector>
#include <mpi.h>

#define M 20 // number of rows
#define N 10 // number of columns

template<typename ContainerType> typename ContainerType::pointer
dataPtr(ContainerType &c) { return c.empty() ? 0 : &c.front(); }

int main(int argc, char *argv[])
{
  using namespace std;

  MPI_Init(&argc,&argv); 
  int size; MPI_Comm_size(MPI_COMM_WORLD,&size); 
  int rank; MPI_Comm_rank(MPI_COMM_WORLD,&rank);

  vector<double> A(rank == 0 ? M*N : 0);
  vector<double> X(M);

  if(rank == 0) {
    for(size_t i = 0; i < M*N; ++i) A[i] = rand() / double(RAND_MAX);
    for(size_t i = 0; i < N; ++i)   X[i] = rand() / double(RAND_MAX);
  }

  MPI_Bcast(dataPtr(X), N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

  vector<int> displsa(size), sendcntsa(size, 0), displsy(size), sendcntsy(size);
  for(size_t i = 0; i < size; ++i) {
      int p = floor((i+0)*M/double(size)), q = floor((i+1)*M/double(size))-1;
      displsa[i] = p*N; sendcntsa[i] = (q-p+1)*N;
      displsy[i] = p; sendcntsy[i] = q-p+1;
  }

  vector<double> a(sendcntsa[rank], 0);
  double *sendbuf = dataPtr(A), *recvbuf = dataPtr(a);
  MPI_Scatterv(dataPtr(A), dataPtr(sendcntsa), dataPtr(displsa), 
      MPI_DOUBLE, dataPtr(a), sendcntsa[rank], MPI_DOUBLE, 0, MPI_COMM_WORLD);

  vector<double> y(sendcntsy[rank]);
    for(size_t i = 0; i < sendcntsy[rank]; ++i)
      for(size_t j = 0; j < N; ++j)
        y[i] += a[i * N + j] * X[j];

  vector<double> Y(rank == 0 ? M : 0);
  MPI_Gatherv(dataPtr(y), sendcntsy[rank], MPI_DOUBLE, dataPtr(Y),
    dataPtr(sendcntsy), dataPtr(displsy), MPI_DOUBLE, 0, MPI_COMM_WORLD);

  MPI_Finalize();
  return EXIT_SUCCESS;
}

