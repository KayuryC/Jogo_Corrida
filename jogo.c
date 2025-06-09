#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define NUM_PROCESSOS 5
#define TAM_BARRA 20
#define QUANTUM 1

typedef struct {
    char nome[20];
    int tempoTotal;
    int tempoRestante;
    int progresso;
    int concluido;
} Processo;

Processo processos[NUM_PROCESSOS];
char *nomes[] = {"Tartaruga", "Coelho", "Raposa", "Cobra", "Elefante"};

void inicializar_processos() {
    srand(time(NULL));
    for (int i = 0; i < NUM_PROCESSOS; i++) {
        strcpy(processos[i].nome, nomes[i]);
        processos[i].tempoTotal = 5 + rand() % 10;
        processos[i].tempoRestante = processos[i].tempoTotal;
        processos[i].progresso = 0;
        processos[i].concluido = 0;
    }
}

void mostrar_barras() {
    for (int i = 0; i < NUM_PROCESSOS; i++) {
        printf("%s [", processos[i].nome);
        int barrado = (float)(processos[i].progresso) / processos[i].tempoTotal * TAM_BARRA;
        for (int j = 0; j < TAM_BARRA; j++) {
            if (j < barrado) printf("█");
            else printf(" ");
        }
        printf("] %d%%\n", (int)((float)processos[i].progresso / processos[i].tempoTotal * 100));
    }
}

void limpar_terminal() {
    printf("\033[H\033[J"); // Limpa o terminal (codigo ANSI)
}

void fifo() {
    printf("\nEscalonamento FIFO (First In, First Out)\n");
    for (int i = 0; i < NUM_PROCESSOS; i++) {
        printf("\nExecutando processo: %s (Tempo total: %d)\n", processos[i].nome, processos[i].tempoTotal);
        while (processos[i].tempoRestante > 0) {
            processos[i].progresso++;
            processos[i].tempoRestante--;
            limpar_terminal();
            mostrar_barras();
            usleep(300000);
        }
        processos[i].concluido = 1;
        printf("\nProcesso %s concluido!\n", processos[i].nome);
    }
}

void round_robin() {
    printf("\nEscalonamento Round Robin (Quantum: %d segundo(s))\n", QUANTUM);
    int todosConcluidos = 0;
    while (!todosConcluidos) {
        todosConcluidos = 1;
        for (int i = 0; i < NUM_PROCESSOS; i++) {
            if (processos[i].tempoRestante > 0) {
                printf("\nExecutando processo: %s (Tempo restante: %d)\n", processos[i].nome, processos[i].tempoRestante);
                int tempo = (processos[i].tempoRestante >= QUANTUM) ? QUANTUM : processos[i].tempoRestante;
                for (int t = 0; t < tempo; t++) {
                    processos[i].progresso++;
                    processos[i].tempoRestante--;
                    limpar_terminal();
                    mostrar_barras();
                    usleep(300000);
                }
                if (processos[i].tempoRestante > 0) todosConcluidos = 0;
            }
        }
    }
    printf("\nTodos os processos foram concluidos com Round Robin.\n");
}

void mostrar_vencedor() {
    int menorTempo = 9999;
    char vencedor[20];
    for (int i = 0; i < NUM_PROCESSOS; i++) {
        if (processos[i].tempoTotal < menorTempo) {
            menorTempo = processos[i].tempoTotal;
            strcpy(vencedor, processos[i].nome);
        }
    }
    printf("\nProcesso mais rapido: %s, com %d unidades de tempo!\n", vencedor, menorTempo);
}

int main() {
    int escolha;
    printf("Corrida de Processos no Terminal\n");
    printf("Escolha a politica de escalonamento:\n");
    printf("1 - FIFO (Primeiro a entrar, primeiro a sair)\n");
    printf("2 - Round Robin (Quantum de 1 segundo)\n");
    printf("Digite sua escolha (1 ou 2): ");
    scanf("%d", &escolha);

    inicializar_processos();

    if (escolha == 1) {
        fifo();
    } else if (escolha == 2) {
        round_robin();
    } else {
        printf("Escolha invalida! Por favor, digite 1 ou 2.\n");
        return 1;
    }

    mostrar_vencedor();
    return 0;
}
