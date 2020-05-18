
/*
   TPD2 - Programação Paralela e Distribuida

   Alunos: Derick Garcez e Vinicius Azevedo

   Programa Baseado no Exemplo dispobilizado pelo Professor

*/

#include <mpi.h>
#include <stdio.h>

int main(int argc, char* argv[]) {

        int size;
        int id;
        int coord;
	char[100] msg;
	int recebido;
	int pos;
	int i;
	int achei;

        MPI_Init(&argc, &argv);
        MPI_Comm_size( MPI_COMM_WORLD, &size );
        MPI_Comm_rank( MPI_COMM_WORLD, &id );
	coord = size -1;
	int[size] nodos;
	pos = id;
	for(i = 0; i < size; i++) {
		nodos[i] = 1; // Lista com todos os nodos
	}
	// POS: 0 1 2
	//      1 1 0 
	// Nodos 0 e 1 ativos , 2  desativado
        if( id != coord ) {
		for(i = pos-1; i >= 0; i--;){
			if(nodos[i] == 1){
				recebido = nodos[í]; break;
			}else if(i == 0){
				 recebido = coord;
			}
                MPI_Recv( &token, 1, MPI_INT, recebido, 0, MPI_COMM_WORLD, MPI_STATUS_IGN$);

                printf("Sou o Processo %d Recebi a Mensagem do processo %d => %d\n", id$
        } else {
                // Initialize the token value
                token = 100;
                }
	achei = 0;
	for(i = pos; i < size; i++;){
		if(nodos[i] == 1){
			enviando = nodos[i]; 
			achei = 1; 
			break;
		}
	}		
	if(achei == 0){
		for(i = 0; i < pos; i++;){
			if(nodos[i] == 1) enviando = nodos[i]; 
				achei = 1; 
				break;
			}
		}
	}
        MPI_Send( &token, 1, MPI_INT, enviando, 0, MPI_COMM_WORLD );

        if( id == coord ) {
		for(i = pos-1; i >= 0; i--;){
			if(nodos[i] == 1){
				{recebido = nodos[í]; 
				break;
			} else if(i == 0){
				recebido = coord;
			}
		}
                MPI_Recv( &token, 1, MPI_INT, recebido, 0, MPI_COMM_WORLD, MPI_STATUS_I$);

                printf("Sou o Coordenador e recebi a mensagem %d do nodo %d", token,nodos[id-1]);
        }

        MPI_Finalize();
        return 0;
}


