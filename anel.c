/*
   TPD2 - Programação Paralela e Distribuida

   Alunos: Derick Garcez e Vinicius Azevedo

   Programa Baseado no Exemplo dispobilizado pelo Professor

*/
#include <stdio.h>
#include "mpi.h"
 
main(int argc, char** argv)
{


// Variaveis do MPI
char message[100]; 	/* Buffer para as mensagens */
int my_rank;  		/* Identificador do processo */
int proc_n;   		/* Número de processos */
int source;   		/* Identificador do proc.origem */
int dest;    		/* Identificador do proc. destino */
int tag = 50; 	        /* Tag para as mensagens */

// Variaveis "globais"
int nodos = 4;

// Variaveis para Token Ring
int coord 			= 1; // Começa em 4 pois no exemplo do desenho o coordenador = A
int token 			= 0; // TOKEN = 1 => Posso mandar ; TOKEN = 0 => Só escuto!
char Matriz[nodos-1][2];             // Lista de informacoes sobre os nodos
char nome; 			     // Variavel que identifica quem é o novo, mesma ideia do MYRANK mas em CHAR!


MPI_Status status; /* Status de retorno */
 
MPI_Init (&argc , & argv);
 
MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
MPI_Comm_size(MPI_COMM_WORLD, &proc_n);
 
if (my_rank != coord) // Se eu for o coord
   {
   sprintf(message, "Greetings from process %d!", my_rank);
   dest = 0;
   MPI_Send (message, strlen(message)+1, MPI_CHAR,dest, tag, MPI_COMM_WORLD);
   }
else  
   {
   for (source = 1; source < proc_n; source++)
      {
      MPI_Recv (message, 100, MPI_CHAR , source, tag, MPI_COMM_WORLD, &status);
      printf("%s\n", message);
      }
   }
MPI_Finalize();
}

