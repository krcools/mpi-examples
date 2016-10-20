#ifndef MPI_EXAMPLES_ECHO_H
#define MPI_EXAMPLES_ECHO_H

#include <algorithm>
#include <iostream>
#include <iterator>

template<typename R>
void print_range(const R &r) {
    std::copy(r.begin(), r.end(), std::ostream_iterator<typename R::value_type>(std::cout,"\n"));
}

#define echoa(x) {std::cout << rank << ": " << x << std::endl;}
#define echoa_var(x) {std::cout << rank << ": " <<<< #x ": " << x << std::endl;}
#define echoa_range(x) { \
    std::cout << rank << ": " <<<< #x ": " << std::endl; \
    print_range(x); \
} \

#define echo0(x) if(rank == 0) std::cout << rank << ": " << x << std::endl;
#define echo0_var(x) if(rank == 0) std::cout << rank << ": " << #x ": " << x << std::endl;
#define echo0_range(x) if(rank == 0) { \
    std::cout << rank << ": " << #x ": " << std::endl; \
    print_range(x); \
} \

#define echoi(x,i) if(rank == i) { std::cout << i << ": " << x << std::endl; }
#define echoi_var(x,index) if(rank == index) { std::cout << index << ": " << #x ": " << x << std::endl; }
#define echoi_range(x,i) if(rank == i) { \
    std::cout << i << ": " << #x ": " << std::endl; \
    print_range(x); \
} \

#endif
