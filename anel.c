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
int nodos;   		/* Número de processos */
int source;   		/* Identificador do proc.origem */
int dest;    		/* Identificador do proc. destino */
int tag = 50; 	        /* Tag para as mensagens */



// Variaveis para Token Ring
int coord 			= 1; // Começa em 1 pois no exemplo do desenho o coordenador = A
int token 			= 0; // TOKEN = 1 => Posso mandar ; TOKEN = 0 => Só escuto!
char Matriz[nodos-1][2];             // Lista de informacoes sobre os nodos
char nome; 			     // Variavel que identifica quem é o novo, mesma ideia do MYRANK mas em CHAR!

MPI_Status status; /* Status de retorno */
 
MPI_Init (&argc , & argv);
 
MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
MPI_Comm_size(MPI_COMM_WORLD, &nodos);

 
if(my_rank == 0) token = 1; //Inicia o anel

if (my_rank != coord) // Se não for eu for o coord
   {
	if(token == 1){
	   	sprintf(message, "Sou o Processo %d!", my_rank);
	   	dest = my_rank + 1;
	   	if(dest >= nodos) dest = coord;
	   	MPI_Send (message, strlen(message)+1, MPI_CHAR,dest, tag, MPI_COMM_WORLD);
	}else{
		MPI_Recv (message, 100, MPI_CHAR , my_rank - 1, tag, MPI_COMM_WORLD, &status);
      		printf("Sou o %d e recebi -> %s\n", my_rank, message);		
		token = message;
	}
   }
else  
   { //Se for o coord
	if( token != 1){
		MPI_Recv (message, 100, MPI_CHAR , source, tag, MPI_COMM_WORLD, &status);
      		printf("%s\n", message);
	}else{
		sprintf(message, "Sou o Processo %d!", my_rank);
	   	dest = my_rank + 1;
	   	if(dest >= nodos) dest = coord;
	   	MPI_Send (message, strlen(message)+1, MPI_CHAR,dest, tag, MPI_COMM_WORLD);
		
	}
   }
MPI_Finalize();
}

