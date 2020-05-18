/*
   TPD2 - Programação Paralela e Distribuida

   Alunos: Derick Garcez e Vinicius Azevedo

   Programa Baseado no Exemplo dispobilizado pelo Professor

*/


#include <mpi.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
   int size;
   int rank;
   int msg;


   MPI_Init(&argc, &argv);
   MPI_Comm_size( MPI_COMM_WORLD, &size );
   MPI_Comm_rank( MPI_COMM_WORLD, &rank );

   if( rank != 0 ) {
      MPI_Recv( &msg, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE );
      printf("Sou o %d e Recebi a Mensagem do processo %d, com o seguinte conteúdo: %d \n", rank, rank-1, msg);
   } else {

      msg = 1;
   }
   MPI_Send( &msg, 1, MPI_INT, (rank + 1) % size, 0, MPI_COMM_WORLD );

   if( rank == 0 ) {
      MPI_Recv( &msg, 1, MPI_INT, size - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE );
      printf("Sou o processo %d e recebi a seguinte mensagem do processo %d : %d , e estou encerrando! \n", rank, size-1, msg );
   }

   MPI_Finalize();

   return 0;
}





