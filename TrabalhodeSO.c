#include <stdio.h>
#include <stdlib.h>

#define NUM_PROCESSOS 10

typedef enum eStatus{
    EXECUCAO,     // 0
    PRONTO,     // 1  // 5
    CONCLUIDO      // 6
}STATUS;

// Estrutura para representar um processo
typedef struct {
    int id;          // Identificador do processo
    int arrivalTime; // Tempo de chegada
    int burstTime;   // Tempo de execução
    int remainingTime; // Tempo restante para a conclusão
    STATUS statusProcesso;     // Status do processo (R = em execução, P = pronto, C = concluído)
} PROCESSO;

// Função para encontrar o próximo processo a ser executado com base no tempo restante
//int findShortestRemainingTime(Process processes[], int n, int currentTime) {
//    int shortestTime = INT_MAX;
//    int shortestIndex = -1;
//
//    for (int i = 0; i < n; i++) {
//        if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime < shortestTime && processes[i].remainingTime > 0 && processes[i].statusProcesso != 'C') {
//            shortestTime = processes[i].remainingTime;
//            shortestIndex = i;
//        }
//    }
//
//    return shortestIndex;
//}

int main() {
    PROCESSO processos[NUM_PROCESSOS];
    int currentTime = 0;

    // Inicialização dos processos
    for (int i = 0; i < NUM_PROCESSOS; i++) {
        processos[i].id = i + 1;
        printf("Informe o tempo de chegada e o tempo de execução para o processo %d: ", i + 1);
        scanf("%d %d", &processos[i].arrivalTime, &processos[i].burstTime);
        processos[i].remainingTime = processos[i].burstTime;
        processos[i].statusProcesso = 'P';
    }

    printf("Tempo de Execução:\n");
//    while (1) {
//        int shortestIndex = findShortestRemainingTime(processos, NUM_PROCESSOS, currentTime);
//
//        if (shortestIndex == -1) {
//            break;
//        }
//
//        processos[shortestIndex].statusProcesso = 'R';
//        processos[shortestIndex].remainingTime--;
//
//        printf("Tempo %d: Processo %d\n", currentTime, processos[shortestIndex].id);
//
//        if (processos[shortestIndex].remainingTime == 0) {
//            processos[shortestIndex].statusProcesso = 'C';
//            int completionTime = currentTime + 1;
//            printf("Processo %d concluído no tempo %d\n", processos[shortestIndex].id, completionTime);
//        }
//
//        currentTime++;
//    }

    return 0;
}
