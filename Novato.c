#include <stdio.h>
#include <string.h>

// Estrutura que representa os dados de uma carta
typedef struct {
    char estado[50];
    char codigo[20];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int num_pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função para calcular a densidade populacional e PIB per capita
void calcular_dados(Carta *c) {
    c->densidade_populacional = c->populacao / c->area;
    c->pib_per_capita = c->pib / c->populacao;
}

// Função para comparar duas cartas com base no atributo escolhido (população neste caso)
void comparar_cartas(Carta carta1, Carta carta2) {
    // Atributo escolhido para comparação (população)
    printf("Comparação de cartas (Atributo: População):\n");

    printf("Carta 1 - %s (%s): %d\n", carta1.cidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n", carta2.cidade, carta2.estado, carta2.populacao);

    // Comparação de População
    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta1.populacao < carta2.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}

int main() {
    // Inicialização das duas cartas
    Carta carta1, carta2;

    // Entrada dos dados para a Carta 1
    printf("Digite os dados para a Carta 1:\n");
    printf("Estado: ");
    fgets(carta1.estado, 50, stdin);
    carta1.estado[strcspn(carta1.estado, "\n")] = 0;  // Remover a quebra de linha
    printf("Código da carta: ");
    fgets(carta1.codigo, 20, stdin);
    carta1.codigo[strcspn(carta1.codigo, "\n")] = 0;
    printf("Nome da cidade: ");
    fgets(carta1.cidade, 50, stdin);
    carta1.cidade[strcspn(carta1.cidade, "\n")] = 0;
    printf("População: ");
    scanf("%d", &carta1.populacao);
    printf("Área: ");
    scanf("%f", &carta1.area);
    printf("PIB: ");
    scanf("%f", &carta1.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.num_pontos_turisticos);
    getchar();  // Para consumir a quebra de linha remanescente após a leitura de números

    // Calcular densidade populacional e PIB per capita para a Carta 1
    calcular_dados(&carta1);

    // Entrada dos dados para a Carta 2
    printf("\nDigite os dados para a Carta 2:\n");
    printf("Estado: ");
    fgets(carta2.estado, 50, stdin);
    carta2.estado[strcspn(carta2.estado, "\n")] = 0;
    printf("Código da carta: ");
    fgets(carta2.codigo, 20, stdin);
    carta2.codigo[strcspn(carta2.codigo, "\n")] = 0;
    printf("Nome da cidade: ");
    fgets(carta2.cidade, 50, stdin);
    carta2.cidade[strcspn(carta2.cidade, "\n")] = 0;
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área: ");
    scanf("%f", &carta2.area);
    printf("PIB: ");
    scanf("%f", &carta2.pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.num_pontos_turisticos);
    getchar();  // Para consumir a quebra de linha remanescente

    // Calcular densidade populacional e PIB per capita para a Carta 2
    calcular_dados(&carta2);

    // Comparar as duas cartas com base na população
    comparar_cartas(carta1, carta2);

    return 0;
}

