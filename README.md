# Projeto-c-JOGOS-FEITO-EM-PARCERIA
Esse aqui é um projeto de faculdade feito em dupla, Feito por Hugo ribeiro e Higor.
Execute o programa:
# 🎮 Mini-Games Collection em C

Este repositório contém uma coletânea de três jogos interativos desenvolvidos em **Linguagem C**, rodando diretamente no terminal. O projeto aplica conceitos fundamentais de programação como **estruturas de dados (structs)**, **ponteiros**, **gerenciamento de turnos** e **lógica matemática**.

---

## 🕹️ Jogos Disponíveis

### 1. 🧠 Quiz Interativo
Um desafio de perguntas e respostas com temas variados.
* **Mecânica:** O jogador deve acertar a sequência de 5 perguntas.
* **Destaque:** Sistema de validação que exige a resposta correta para avançar.

### 2. 🐍 Cobra na Caixa
Um jogo de sorte e estratégia para 2 jogadores.
* **O Objetivo:** Encontrar o botão escondido em uma das 5 caixas.
* **O Risco:** Uma das caixas contém uma cobra que elimina o jogador instantaneamente.
* **Lógica:** Posições sorteadas aleatoriamente a cada rodada usando `rand()`.

### 3. ⚔️ Gousmas War
Um jogo de combate estratégico por turnos.
* **Sistema de Fúria:** Cada Gousma aguenta até 5 pontos de fúria. Se ultrapassar, ela explode.
* **Ações:**
    * **Atacar:** Transfere sua fúria para a Gousma inimiga para tentar destruí-la.
    * **Dividir:** Transfere fúria entre suas próprias Gousmas (permite reviver unidades destruídas).

---

## 🛠️ Tecnologias e Funções
* **Linguagem:** C (Padrão C99/C11).
* **Bibliotecas:** `stdio.h`, `stdlib.h`, `string.h`, `time.h`.
* **Estruturas:** Uso de `typedef struct` para gerenciar estados de jogo e jogadores.
* **Randomização:** Semente de tempo (`srand(time(NULL))`) para garantir partidas únicas.

---

## 🚀 Como Compilar e Rodar

1. **Certifique-se de ter o GCC instalado.**
2. **Compile o arquivo:**
   ```bash
   gcc main.c -o mini_games

   Execute o programa:
   ./mini_games
   📂 Estrutura do Projeto
main.c: Código fonte contendo toda a lógica dos jogos.

README.md: Documentação do projeto.
