#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>

#define NUM_PROCESSOS 10


typedef struct {
    int id;
    int Tempo_Chegada;
    int Tempo_Execucao;
    int Tempo_Inicio;
    float Tempo_Execucao_Restante;
    int Tempo_Espera;
    int concluido,tat,rt;
    int status;  // 0 - Pronto, 1 - Em execução, 2 - Concluído
} Processo;


int findmax(int a, int b)
{
    return a>b?a:b;
}

int findmin(int a, int b)
{
    return a<b?a:b;
}

int main(){
	
	srand(time(NULL));
	
	Processo processos[NUM_PROCESSOS];
	int tempo_atual = 0;
    int processos_concluidos = 0;
    
    for (int i = 0; i < NUM_PROCESSOS; i++) {
	    processos[i].Tempo_Chegada = rand() % 10;
	    processos[i].id = i;
	    processos[i].Tempo_Execucao = rand() % 10 + 1;
	    processos[i].Tempo_Execucao_Restante = processos[i].Tempo_Execucao;
	    processos[i].status = 0;
	    printf("Processo P%d - Tempo de Chegada: %d- Tempo Execucao/Restante: %d - Status: %d\n", i,processos[i].Tempo_Chegada, processos[i].Tempo_Execucao,processos[i].status);
	}
//
//	    for(int i=0;i<NUM_PROCESSOS;i++)
//    {
//        printf("\nProcesso %d Arrival Time: ",i);
//        scanf("%d",&processos[i].Tempo_Chegada);
//        processos[i].id = i ;
//        processos[i].status =0;
//    }
//     for(int i=0;i<NUM_PROCESSOS;i++)
//    {
//        printf("\nEnter Process %d Burst Time: ",i);
//       scanf("%d",&processos[i].Tempo_Execucao);
//         processos[i].Tempo_Execucao_Restante= processos[i].Tempo_Execucao;
//    }

	printf("\n");
	
	while(processos_concluidos!=NUM_PROCESSOS){
		int min_index = -1;
		int menor_tempo_execucao = INT_MAX;
		
		  for(int i = 0; i < NUM_PROCESSOS; i++) {
            if(processos[i].Tempo_Chegada <= tempo_atual && processos[i].status != 2) {// verificar se aquele processo foi o primerio a chegar
            // e se não está concluido 
                if(processos[i].Tempo_Execucao_Restante < menor_tempo_execucao) {// verificar se o tempo faltando é o menor daqueles processos que chegaram ao mesmo tempo
                    menor_tempo_execucao = processos[i].Tempo_Execucao_Restante;
                    min_index = i;
               if(processos[i].Tempo_Execucao_Restante== menor_tempo_execucao) {
                 }
                    if(processos[i].Tempo_Chegada < processos[min_index].Tempo_Chegada) {
                        menor_tempo_execucao= processos[i].Tempo_Execucao_Restante;
                        min_index = i;
                    }
                }
            }
        }
        
        if(min_index==-1)// não chegou nenhum processo ou todos os processos que chegaram foram completados
        {
            tempo_atual++;
        }
        else{
        		if(processos[min_index].Tempo_Execucao_Restante == processos[min_index].Tempo_Execucao)
            {
                processos[min_index].Tempo_Inicio = tempo_atual;
                processos[min_index].status = 1;
        	}
            processos[min_index].Tempo_Execucao_Restante -= 1;
            tempo_atual++; 
            if(processos[min_index].Tempo_Execucao_Restante == 0)
            {
                processos[min_index].concluido = tempo_atual;
                processos[min_index].tat = processos[min_index].concluido - processos[min_index].Tempo_Chegada;
                processos[min_index].Tempo_Espera= processos[min_index].tat - processos[min_index].Tempo_Execucao;
                processos[min_index].rt = processos[min_index].Tempo_Inicio - processos[min_index].Tempo_Chegada;
            
                processos_concluidos++;
                processos[min_index].status=2;
            }
        }
		
	}
	
	    //Output
    printf("\nProcesso \t Tempo Chegada\t Tempo de Execucao CPU \tConcluido\tTAT\tEspera\tRT\n");
    for(int i=0;i<NUM_PROCESSOS;i++)
    printf("%d\t\t\t%d\t\t%d\t\t%d\t\t%d\t%d\t%d\n",
	processos[i].id,processos[i].Tempo_Chegada,processos[i].Tempo_Execucao,processos[i].concluido,processos[i].tat,processos[i].Tempo_Espera,processos[i].rt);


	return 0;
}