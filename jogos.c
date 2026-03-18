#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CAIXAS 5
#define NUM_NOMES 4

const char *nomes[NUM_NOMES] = {"P1", "P2", "P3", "P4"};

typedef struct {
    int aberta[NUM_CAIXAS];   
    int caixa_botao;          
    int caixa_cobra;         
    int jogador_atual;        
    char nome[2][32];
} Jogo;

void limpar_tela(void) {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

int sortear(int min, int max) {
    return min + rand() % (max - min + 1);
}

void sortear_posicoes(Jogo *j) {
    j->caixa_botao = sortear(0, NUM_CAIXAS - 1);
    do {
        j->caixa_cobra = sortear(0, NUM_CAIXAS - 1);
    } while (j->caixa_cobra == j->caixa_botao);
}

void exibir_caixas(const Jogo *j) {
    printf("\n  Caixas:  ");
    for (int i = 0; i < NUM_CAIXAS; i++) {
        if (j->aberta[i])
            printf("[  X  ] ");
        else
            printf("[  %d  ] ", i + 1);
    }
    printf("\n\n");
}

void escolher_nome(Jogo *j, int idx) {
    printf("Jogador %d, escolha seu nome:\n", idx + 1);
    for (int i = 0; i < NUM_NOMES; i++)
        printf("  %d. %s\n", i + 1, nomes[i]);

    int op = 0;
    while (op < 1 || op > NUM_NOMES) {
        scanf("%d", &op);
        getchar();
    }
    strncpy(j->nome[idx], nomes[op - 1], 31);
    j->nome[idx][31] = '\0';
}

void quiz() {
    int RespostaQuiz; 

    printf("\n--- Jogo 1: Quiz ---\n");
    printf("Qual a capital do Brasil? \n");
    printf("1. Londres \n2. Xique Xique \n3. Brasilia \n4. Llanfairpwll... \n");

    while{

        do{
        printf("Digite o numero da opcao correta: ");
        scanf("%d", &RespostaQuiz);
        getchar();
        if (RespostaQuiz == 3) {
            printf("Resposta correta! \n");
        } else {
            printf("Resposta incorreta. Tente novamente.\n");
        }
    
    
    
        printf("Digite o numero da opcao correta: ");
        scanf("%d", &RespostaQuiz);
        if (RespostaQuiz == 3) {
            printf("Resposta correta! \n");
        } else {
            printf("Resposta incorreta. Tente novamente.\n");
        }
    
              

    
        printf("--- Jogo 2: Quiz ---\n");
        printf("Qual e o  melhor filme da barbie em animacao? \n");
        printf("1. Barbie: A Vida de uma Princesa \n2. Barbie: A Princesa e a Plebéia \n3. Barbie: A Princesa e a Popstar \n4. Barbie: A Princesa e a Sereia \n");
    
    
        printf("Digite o numero da opcao correta: ");
        scanf("%d", &RespostaQuiz);
        getchar();
        if (RespostaQuiz == 3) {
            printf("Resposta correta! \n");
        } else {
            printf("Resposta incorreta. Tente novamente.\n");
        }
        }
    }

     printf("--- Jogo 2: Quiz ---\n");
    printf("Qual e o melhor desenho na cartton network? \n");
    printf("1. apenas um show ○\n2 Hora de Aventura \n3. Samurai jack \n 4. As Meninas Superpoderosas \n");
    
    
        printf("Digite o numero da opcao correta: ");
        scanf("%d", &RespostaQuiz);
        getchar();
        if (RespostaQuiz == 3) {
            printf("Resposta correta! \n");
        } else {
            printf("Resposta incorreta. Tente novamente.\n");
        }
    } 



  printf("--- Jogo 2: Quiz ---\n");
    printf("Qual e o melhor youtuber de minecraft? \n");
    printf("1. tazercraft \n2. AuthenticGames \n3. vincius 13 \n4. VenomExtreme \n");
    
    
        printf("Digite o numero da opcao correta: ");
        scanf("%d", &RespostaQuiz);
        getchar();
        if (RespostaQuiz == 4) {
            printf("Resposta correta! \n");
        } else {
            printf("Resposta incorreta. Tente novamente.\n");
        }


        }
    }

 
    
    
  getchar();
} 

int jogar_cobra(void) {
    Jogo j;
    memset(&j, 0, sizeof(j));
    printf("||| Cobra na Caixa! |||\n\n");
    escolher_nome(&j, 0);
    escolher_nome(&j, 1);
    j.jogador_atual = sortear(0, 1);
    printf("\n%s comeca!\n", j.nome[j.jogador_atual]);
    sortear_posicoes(&j);

    while (1) {
        limpar_tela();
        printf("||| Cobra na Caixa! |||\n");
        printf("Turno de: %s\n", j.nome[j.jogador_atual]);
        exibir_caixas(&j);
        int escolha = 0;
        while (1) {
            printf("Escolha uma caixa (1-%d): ", NUM_CAIXAS);
            scanf("%d", &escolha);
            getchar();
            escolha--;   
            if (escolha < 0 || escolha >= NUM_CAIXAS || j.aberta[escolha]) {
                printf("Invalido ou ja aberta. Tente novamente.\n");
                continue;
            }
            break;
        }
        j.aberta[escolha] = 1;
        if (escolha == j.caixa_botao) {
            printf("\n*** Voce encontrou o BOTAO! %s VENCEU! ***\n\n", j.nome[j.jogador_atual]);
            getchar(); return j.jogador_atual;
        } else if (escolha == j.caixa_cobra) {
            printf("\n*** COBRA! %s perdeu. ***\n\n", j.nome[j.jogador_atual]);
            getchar(); return 1 - j.jogador_atual;
        } else {
            printf("\nCaixa vazia. Passando a vez...\n");
            memset(j.aberta, 0, sizeof(j.aberta));
            sortear_posicoes(&j);
            j.jogador_atual = 1 - j.jogador_atual;
            getchar();
        }
    }
}

int main() {
    srand((unsigned)time(NULL));
    int Jogos;

    do { 
        printf("\n--- JOGOS DISPONIVEIS ---\n");
        printf("1. Quiz\n2. Cobra na Caixa\n3. Gousmas War\n4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &Jogos);
        getchar();

        switch(Jogos) {
            case 1: quiz(); break;
            case 2: jogar_cobra(); break;
            case 3: printf("Gousmas War em breve!\n"); break;
            case 4: printf("Saindo...\n"); break;
            default: printf("Opcao invalida\n"); break;
        }
    } while (Jogos != 4);

    return 0;
}