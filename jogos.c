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

// ============================================================
//  Gousmas War
// ============================================================

#define MAX_FURIA 5
#define NUM_GOUSMAS 2

typedef struct {
    int furia;
    int destruida;
} Gousma;

typedef struct {
    char nome[20];
    Gousma gousmas[NUM_GOUSMAS];
} Jogador;

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

    
    for (int i = 1; i <= 5; i++) {
        
        
        if (i == 1) {
            printf("\n--- Pergunta 1: Qual a capital do Brasil? ---\n1. Londres | 2. Xique Xique | 3. Brasilia | 4. Llanfairpwll\n");
        } else if (i == 2) {
            printf("\n--- Pergunta 2: Personagem mais lindo de RE? ---\n1. Leon | 2. Claire | 3. Chris | 4. Alcina Dimitrescu\n");
        } else if (i == 3) {
            printf("\n--- Pergunta 3: Melhor Barbie? ---\n1. Princesa | 2. Plebeia | 3. Popstar | 4. Sereia\n");
        } else if (i == 4) {
            printf("\n--- Pergunta 4: Melhor do CN? ---\n1. Apenas um Show | 2. Hora de Aventura | 3. Samurai Jack | 4. Meninas Superpoderosas\n");
        } else if (i == 5) {
            printf("\n--- Pergunta 5: Melhor YouTuber de Minecraft? ---\n1. Tazercraft | 2. Authentic | 3. Vinicius 13 | 4. VenomExtreme\n");
        }

       
        while (1) {
            printf("Digite sua resposta: ");
            
           
            if (scanf(" %d", &RespostaQuiz) != 1) {
                while(getchar() != '\n'); 
                printf("Erro: Digite apenas o NUMERO da opcao.\n");
                continue;
            }

           
            int acertou = 0;
            if (i == 1 && RespostaQuiz == 3) acertou = 1;
            else if (i == 2 && RespostaQuiz == 4) acertou = 1;
            else if (i == 3 && RespostaQuiz == 3) acertou = 1;
            else if (i == 4 && RespostaQuiz == 3) acertou = 1;
            else if (i == 5 && RespostaQuiz == 4) acertou = 1;

            if (acertou) {
                printf("Boa! Resposta correta.\n");
                break; 
            } else {
                printf("Incorreto. Tente novamente!\n");
            }
        }
    }
    printf("\n--- FIM DO QUIZ! VOCE VENCEU! ---\n");
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
            j.jogador_atual = 1 - j.jogador_atual;
            getchar();
        }
    }
}

// ========== GOUSMAS WAR FUNCTIONS ==========

void limpar_buffer_gw() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int ler_inteiro_gw(int min, int max) {
    int val;
    while (1) {
        if (scanf("%d", &val) == 1 && val >= min && val <= max) {
            limpar_buffer_gw();
            return val;
        }
        limpar_buffer_gw();
        printf("  Entrada inválida. Digite um número entre %d e %d: ", min, max);
    }
}

int gousmas_ativas(Jogador *j) {
    int count = 0;
    for (int i = 0; i < NUM_GOUSMAS; i++)
        if (!j->gousmas[i].destruida) count++;
    return count;
}

void exibir_estado(Jogador jogadores[2]) {
    printf("\n========================================\n");
    for (int p = 0; p < 2; p++) {
        printf("  %s:\n", jogadores[p].nome);
        for (int g = 0; g < NUM_GOUSMAS; g++) {
            if (jogadores[p].gousmas[g].destruida)
                printf("    Gousma %d: [DESTRUÍDA]\n", g + 1);
            else
                printf("    Gousma %d: fúria = %d\n", g + 1, jogadores[p].gousmas[g].furia);
        }
    }
    printf("========================================\n");
}

void verificar_destruicao(Jogador *j) {
    for (int g = 0; g < NUM_GOUSMAS; g++) {
        if (!j->gousmas[g].destruida && j->gousmas[g].furia > MAX_FURIA) {
            j->gousmas[g].destruida = 1;
            printf("  *** Gousma %d de %s foi DESTRUÍDA! (fúria > %d) ***\n",
                   g + 1, j->nome, MAX_FURIA);
        }
    }
}

void acao_atacar(Jogador *atacante, Jogador *defensor) {
    printf("\n  Escolha sua Gousma para atacar:\n");
    int opcoes_atk[NUM_GOUSMAS], n_atk = 0;
    for (int g = 0; g < NUM_GOUSMAS; g++) {
        if (!atacante->gousmas[g].destruida) {
            printf("    %d - Gousma %d (fúria = %d)\n", g + 1, g + 1, atacante->gousmas[g].furia);
            opcoes_atk[n_atk++] = g;
        }
    }
    int escolha_atk = -1;
    while (escolha_atk == -1) {
        printf("  Opção: ");
        int v = ler_inteiro_gw(1, NUM_GOUSMAS) - 1;
        for (int i = 0; i < n_atk; i++) {
            if (opcoes_atk[i] == v) { escolha_atk = v; break; }
        }
        if (escolha_atk == -1) printf("  Escolha inválida (Gousma destruída).\n");
    }

    printf("\n  Escolha a Gousma alvo de %s:\n", defensor->nome);
    int opcoes_def[NUM_GOUSMAS], n_def = 0;
    for (int g = 0; g < NUM_GOUSMAS; g++) {
        if (!defensor->gousmas[g].destruida) {
            printf("    %d - Gousma %d (fúria = %d)\n", g + 1, g + 1, defensor->gousmas[g].furia);
            opcoes_def[n_def++] = g;
        }
    }
    int escolha_def = -1;
    while (escolha_def == -1) {
        printf("  Opção: ");
        int v = ler_inteiro_gw(1, NUM_GOUSMAS) - 1;
        for (int i = 0; i < n_def; i++) {
            if (opcoes_def[i] == v) { escolha_def = v; break; }
        }
        if (escolha_def == -1) printf("  Escolha inválida (Gousma destruída).\n");
    }

    int furia_atk = atacante->gousmas[escolha_atk].furia;
    defensor->gousmas[escolha_def].furia += furia_atk;

    printf("\n  Gousma %d de %s atacou Gousma %d de %s! (+%d fúria)\n",
           escolha_atk + 1, atacante->nome,
           escolha_def + 1, defensor->nome,
           furia_atk);

    verificar_destruicao(defensor);
}

void acao_dividir(Jogador *j) {
    printf("\n  Escolha a Gousma DOADORA (para transferir fúria):\n");
    int opcoes[NUM_GOUSMAS], n = 0;
    for (int g = 0; g < NUM_GOUSMAS; g++) {
        if (!j->gousmas[g].destruida) {
            printf("    %d - Gousma %d (fúria = %d)\n", g + 1, g + 1, j->gousmas[g].furia);
            opcoes[n++] = g;
        }
    }
    if (n == 0) { printf("  Nenhuma Gousma ativa.\n"); return; }

    int doadora = -1;
    while (doadora == -1) {
        printf("  Opção: ");
        int v = ler_inteiro_gw(1, NUM_GOUSMAS) - 1;
        for (int i = 0; i < n; i++) {
            if (opcoes[i] == v) { doadora = v; break; }
        }
        if (doadora == -1) printf("  Escolha inválida.\n");
    }

    int receptora = 1 - doadora;

    if (j->gousmas[receptora].destruida)
        printf("\n  Gousma %d está destruída — ela será revivida ao receber fúria.\n", receptora + 1);
    else
        printf("\n  Receptora: Gousma %d (fúria = %d)\n", receptora + 1, j->gousmas[receptora].furia);

    int furia_max = j->gousmas[doadora].furia - 1;
    if (furia_max <= 0) {
        printf("  A Gousma doadora só tem 1 de fúria; não pode transferir.\n");
        return;
    }

    printf("  Quantos pontos de fúria transferir? (1 a %d): ", furia_max);
    int qtd = ler_inteiro_gw(1, furia_max);

    j->gousmas[doadora].furia  -= qtd;
    j->gousmas[receptora].furia += qtd;

    if (j->gousmas[receptora].destruida) {
        j->gousmas[receptora].destruida = 0;
        printf("  Gousma %d de %s foi REVIVIDA com fúria = %d!\n",
               receptora + 1, j->nome, j->gousmas[receptora].furia);
    } else {
        printf("  Transferência concluída. Gousma %d: fúria = %d | Gousma %d: fúria = %d\n",
               doadora + 1, j->gousmas[doadora].furia,
               receptora + 1, j->gousmas[receptora].furia);
    }

    verificar_destruicao(j);
}

void inicializar_gousmas(Jogador jogadores[2]) {
    char nomes_gw[2][20] = {"Jogador 1", "Jogador 2"};
    for (int p = 0; p < 2; p++) {
        strncpy(jogadores[p].nome, nomes_gw[p], 19);
        for (int g = 0; g < NUM_GOUSMAS; g++) {
            jogadores[p].gousmas[g].furia    = 1;
            jogadores[p].gousmas[g].destruida = 0;
        }
    }
}

void jogar_gousmas_war() {
    Jogador jogadores[2];
    inicializar_gousmas(jogadores);

    int turno = 0;

    printf("\n*** BEM-VINDO AO GOUSMAS WAR! ***\n");
    printf("Regra: fúria > %d => Gousma destruída. Perde quem ficar sem Gousmas ativas.\n", MAX_FURIA);

    while (1) {
        exibir_estado(jogadores);

        Jogador *atual    = &jogadores[turno];
        Jogador *adversario = &jogadores[1 - turno];

        printf("\n>>> Turno de %s <<<\n", atual->nome);
        printf("  1 - Atacar\n");
        printf("  2 - Dividir\n");
        printf("  Ação: ");
        int acao = ler_inteiro_gw(1, 2);

        if (acao == 1) {
            acao_atacar(atual, adversario);
        } else {
            acao_dividir(atual);
        }

        if (gousmas_ativas(adversario) == 0) {
            exibir_estado(jogadores);
            printf("\n🏆  %s VENCEU! %s ficou sem Gousmas ativas.\n\n",
                   atual->nome, adversario->nome);
            break;
        }
        if (gousmas_ativas(atual) == 0) {
            exibir_estado(jogadores);
            printf("\n🏆  %s VENCEU! %s ficou sem Gousmas ativas.\n\n",
                   adversario->nome, atual->nome);
            break;
        }

        turno = 1 - turno;
    }

    printf("  1 - Reiniciar partida\n");
    printf("  2 - Voltar ao menu\n");
    printf("  Opção: ");
    int opcao = ler_inteiro_gw(1, 2);
    if (opcao == 1) jogar_gousmas_war();
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
            case 3: jogar_gousmas_war(); break;
            case 4: printf("Saindo...\n"); break;
            default: printf("Opcao invalida\n"); break;
        }
    } while (Jogos != 4);

    return 0;
}
