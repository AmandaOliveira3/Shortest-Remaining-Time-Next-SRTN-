# Shortest-Remaining-Time-Next-SRTN-

O programa deverá seguir as seguintes regras:
- Criar 10 processos com as características de cada algoritmo de escalonamento (ex: o grupo de
Round Robin é obrigatório ter a variável quantum, o grupo de Lotery não é obrigatório ter o
quantum e sim o ticket e assim por diante).
- Os processos devem ter uma variável “status” para demonstrar em que status ele está (em
execução, bloqueado ou na fila de pronto).
- O programa deve ter uma fila de “Pronto”, que o escalonador vai retirar dessa fila e colocar na
CPU.
- Uma situação em que o programa estará em execução na CPU para escalonar com a fila de
“Pronto”. Atenção: é na CPU que é contabilizado/descontado o “quantum”.
- O trabalho do escalonador termina quando não há mais nenhum elemento na fila de “Pronto”.

- DICAS: cada processo ser uma struct com as devidas características/variáveis , considere os
recursos memória RAM como sendo variáveis globais (como se fosse SO), fila de “Pronto” ser
fila de structs, CPU ser fila de processos com um único elemento.
---
Desenvolvido por Amanda Oliveira e Bianca Santos Pastos
