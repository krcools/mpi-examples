add_executable(ex1-hello ex1-hello.cpp)
target_link_libraries(ex1-hello ${MPI_CXX_LIBRARIES})
set_target_properties(ex1-hello PROPERTIES
    COMPILE_FLAGS "${MPI_CXX_COMPILE_FLAGS}"
    LINK_FLAGS    "${MPI_CXX_LINK_FLAGS}")

add_executable(ex2-rank ex2-rank.cpp)
target_link_libraries(ex2-rank ${MPI_CXX_LIBRARIES})
set_target_properties(ex2-rank PROPERTIES
    COMPILE_FLAGS "${MPI_CXX_COMPILE_FLAGS}"
    LINK_FLAGS    "${MPI_CXX_LINK_FLAGS}")

add_executable(ex3-branching ex3-branching.cpp)
target_link_libraries(ex3-branching ${MPI_CXX_LIBRARIES})
set_target_properties(ex3-branching PROPERTIES
    COMPILE_FLAGS "${MPI_CXX_COMPILE_FLAGS}"
    LINK_FLAGS    "${MPI_CXX_LINK_FLAGS}")
	
add_executable(ex4-barrier ex4-barrier.cpp)
target_link_libraries(ex4-barrier ${MPI_CXX_LIBRARIES})
set_target_properties(ex4-barrier PROPERTIES
    COMPILE_FLAGS "${MPI_CXX_COMPILE_FLAGS}"
    LINK_FLAGS    "${MPI_CXX_LINK_FLAGS}")

add_executable(ex5-send ex5-send.cpp)
target_link_libraries(ex5-send ${MPI_CXX_LIBRARIES})
set_target_properties(ex5-send PROPERTIES
    COMPILE_FLAGS "${MPI_CXX_COMPILE_FLAGS}"
    LINK_FLAGS    "${MPI_CXX_LINK_FLAGS}")
	
add_executable(ex6-cyclic ex6-cyclic.cpp)
target_link_libraries(ex6-cyclic ${MPI_CXX_LIBRARIES})
set_target_properties(ex6-cyclic PROPERTIES
    COMPILE_FLAGS "${MPI_CXX_COMPILE_FLAGS}"
    LINK_FLAGS    "${MPI_CXX_LINK_FLAGS}")

add_executable(ex7-sendrecv ex7-sendrecv.cpp)
target_link_libraries(ex7-sendrecv ${MPI_CXX_LIBRARIES})
set_target_properties(ex7-sendrecv PROPERTIES
    COMPILE_FLAGS "${MPI_CXX_COMPILE_FLAGS}"
    LINK_FLAGS    "${MPI_CXX_LINK_FLAGS}")

add_executable(ex8-bcast ex8-bcast.cpp)
target_link_libraries(ex8-bcast ${MPI_CXX_LIBRARIES})
set_target_properties(ex8-bcast PROPERTIES
    COMPILE_FLAGS "${MPI_CXX_COMPILE_FLAGS}"
    LINK_FLAGS    "${MPI_CXX_LINK_FLAGS}")	

add_executable(ex9-reduce ex9-reduce)
target_link_libraries(ex9-reduce ${MPI_CXX_LIBRARIES})
set_target_properties(ex9-reduce PROPERTIES
    COMPILE_FLAGS "${MPI_CXX_COMPILE_FLAGS}"
    LINK_FLAGS    "${MPI_CXX_LINK_FLAGS}")

add_executable(ex10-scatter ex10-scatter)
target_link_libraries(ex10-scatter ${MPI_CXX_LIBRARIES})
set_target_properties(ex10-scatter PROPERTIES
    COMPILE_FLAGS "${MPI_CXX_COMPILE_FLAGS}"
    LINK_FLAGS    "${MPI_CXX_LINK_FLAGS}")
	
add_executable(ex11-alltoall ex11-alltoall)
target_link_libraries(ex11-alltoall ${MPI_CXX_LIBRARIES})
set_target_properties(ex11-alltoall PROPERTIES
    COMPILE_FLAGS "${MPI_CXX_COMPILE_FLAGS}"
    LINK_FLAGS    "${MPI_CXX_LINK_FLAGS}")
	
add_executable(ex12-async ex12-async)
target_link_libraries(ex12-async ${MPI_CXX_LIBRARIES})
set_target_properties(ex12-async PROPERTIES
    COMPILE_FLAGS "${MPI_CXX_COMPILE_FLAGS}"
    LINK_FLAGS    "${MPI_CXX_LINK_FLAGS}")
	
add_executable(ex13-pi ex13-pi.cpp)
target_link_libraries(ex13-pi ${MPI_CXX_LIBRARIES})
set_target_properties(ex13-pi PROPERTIES
    COMPILE_FLAGS "${MPI_CXX_COMPILE_FLAGS}"
    LINK_FLAGS    "${MPI_CXX_LINK_FLAGS}")
    
add_executable(ex14-matvec ex14-matvec.cpp)
target_link_libraries(ex14-matvec ${MPI_CXX_LIBRARIES})
set_target_properties(ex14-matvec PROPERTIES
    COMPILE_FLAGS "${MPI_CXX_COMPILE_FLAGS}"
    LINK_FLAGS    "${MPI_CXX_LINK_FLAGS}")
    
    