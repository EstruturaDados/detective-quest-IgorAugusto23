#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura que representa uma sala da mansão (nó da árvore binária)
typedef struct Sala {
    char nome[50];             // Nome da sala
    struct Sala *esquerda;     // Caminho à esquerda
    struct Sala *direita;      // Caminho à direita
} Sala;

/*
 * -----------------
 * Cria dinamicamente uma sala com o nome informado.
 */
Sala* criarSala(const char *nome) {
    Sala *novaSala = (Sala*) malloc(sizeof(Sala));
    if (novaSala == NULL) {
        printf("Erro ao alocar memória para a sala.\n");
        exit(1);
    }
    strcpy(novaSala->nome, nome);
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;
    return novaSala;
}

/*
 * Função: explorarSalas
 * ---------------------
 * Permite a navegação do jogador pela árvore binária.
 * O jogador escolhe entre ir para a esquerda (e), direita (d) ou sair (s).
 */
void explorarSalas(Sala *atual) {
    char escolha;

    if (atual == NULL) {
        printf("Mapa inválido.\n");
        return;
    }

    printf("\n=== Exploração da Mansão ===\n");
    while (1) {
        printf("\nVocê está em: %s\n", atual->nome);

        // Caso o jogador chegue a um cômodo sem caminhos (nó-folha)
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Não há mais caminhos a seguir. Você chegou ao fim da exploração.\n");
            break;
        }

        printf("Escolha um caminho:\n");
        if (atual->esquerda != NULL) printf(" [e] Ir para %s (esquerda)\n", atual->esquerda->nome);
        if (atual->direita != NULL) printf(" [d] Ir para %s (direita)\n", atual->direita->nome);
        printf(" [s] Sair da exploração\n");
        printf(">> ");
        scanf(" %c", &escolha);

        if (escolha == 'e' && atual->esquerda != NULL) {
            atual = atual->esquerda;
        } else if (escolha == 'd' && atual->direita != NULL) {
            atual = atual->direita;
        } else if (escolha == 's') {
            printf("Você decidiu encerrar a exploração.\n");
            break;
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    }
}

/*
 * Função: main
 * ------------
 * Monta o mapa da mansão (árvore binária) e inicia a exploração.
 */
int main() {
    // Criação das salas (nós da árvore)
    Sala *hall = criarSala("Hall de Entrada");
    Sala *salaEstar = criarSala("Sala de Estar");
    Sala *cozinha = criarSala("Cozinha");
    Sala *biblioteca = criarSala("Biblioteca");
    Sala *jardim = criarSala("Jardim");
    Sala *porao = criarSala("Porão");

    // Montagem manual da árvore binária (mapa fixo)
    hall->esquerda = salaEstar;
    hall->direita = cozinha;

    salaEstar->esquerda = biblioteca;
    salaEstar->direita = jardim;

    cozinha->esquerda = porao;

    // Início da exploração
    explorarSalas(hall);

    // Liberação de memória (opcional, mas boa prática)
    free(porao);
    free(jardim);
    free(biblioteca);
    free(cozinha);
    free(salaEstar);
    free(hall);

    return 0;
}
