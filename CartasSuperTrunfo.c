#include <stdio.h>

// Desenvolvido por Edison Antonio - 30/07/2025

#define NUM_CARTAS 2

typedef struct {
    char codigo[10];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
    float superPoder;
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta) {
    printf("\nDigite o código da cidade (ex: A01): ");
    scanf(" %s", carta->codigo);
    printf("População: ");
    scanf("%lu", &carta->populacao);
    printf("Área (km²): ");
    scanf("%f", &carta->area);
    printf("PIB (em bilhões): ");
    scanf("%f", &carta->pib);
    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Cálculo dos atributos derivados
    carta->densidade = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
    carta->superPoder = carta->pontosTuristicos + carta->pib + carta->pibPerCapita + (1 / carta->densidade);
}

// Exibir dados de uma carta
void exibirCarta(Carta c) {
    printf("\n---- Carta %s ----\n", c.codigo);
    printf("População: %lu\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: R$ %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidade);
    printf("PIB per Capita: R$ %.2f\n", c.pibPerCapita);
    printf("Super Poder: %.2f\n", c.superPoder);
}

// Comparar dois valores float (ou long)
int compararFloat(float a, float b, int menorVence) {
    return menorVence ? (a < b ? 1 : 0) : (a > b ? 1 : 0);
}

// Comparar dois valores int/long
int compararLong(unsigned long a, unsigned long b) {
    return a > b ? 1 : 0;
}

// Comparar e mostrar resultados
void compararCartas(Carta c1, Carta c2) {
    printf("\n==== Comparação ====\n");

    printf("\nPopulação: Carta %d vence", compararLong(c1.populacao, c2.populacao) + 1);
    printf("\nÁrea: Carta %d vence", compararFloat(c1.area, c2.area, 0) + 1);
    printf("\nPIB: Carta %d vence", compararFloat(c1.pib, c2.pib, 0) + 1);
    printf("\nPontos Turísticos: Carta %d vence", compararLong(c1.pontosTuristicos, c2.pontosTuristicos) + 1);
    printf("\nDensidade Populacional: Carta %d vence", compararFloat(c1.densidade, c2.densidade, 1) + 1);
    printf("\nPIB per Capita: Carta %d vence", compararFloat(c1.pibPerCapita, c2.pibPerCapita, 0) + 1);
    printf("\nSuper Poder: Carta %d vence", compararFloat(c1.superPoder, c2.superPoder, 0) + 1);

    printf("\n");
}

int main() {
    Carta cartas[NUM_CARTAS];

    printf("=== SUPER TRUNFO - PAÍSES ===\n");

    // Cadastro
    for (int i = 0; i < NUM_CARTAS; i++) {
        printf("\nCadastro da Carta %d:\n", i + 1);
        cadastrarCarta(&cartas[i]);
    }

    // Exibição
    for (int i = 0; i < NUM_CARTAS; i++) {
        exibirCarta(cartas[i]);
    }

    // Comparação
    compararCartas(cartas[0], cartas[1]);

    return 0;
}
