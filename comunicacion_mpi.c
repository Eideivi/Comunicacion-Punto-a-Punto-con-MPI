#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int rank, size;
    int value;

    
    MPI_Init(&argc, &argv);                   
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);     
    MPI_Comm_size(MPI_COMM_WORLD, &size);     

    if (size < 2) {
        if (rank == 0)
            printf("Este programa necesita al menos 2 procesos.\n");
        MPI_Finalize();
        return 0;
    }

    
    if (rank == 0) {
        value = 100;  
        MPI_Send(&value, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        printf("Proceso %d envió el valor %d al proceso 1.\n", rank, value);
    } else if (rank == 1) {
        MPI_Recv(&value, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Proceso %d recibió el valor %d del proceso 0.\n", rank, value);
    }

    
    MPI_Finalize();

    return 0;
}
