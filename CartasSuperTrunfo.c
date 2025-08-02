#include <stdio.h>

#define TAM 50
#define NUM_CARTAS 2

typedef struct {
    char estado[TAM];
    char nomeCidade[TAM];
    char codigo[4];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
    float superPoder;
} Carta;

void cadastrarCarta(Carta *carta) {
    printf("\n--- Cadastro da Carta ---\n");

    printf("Estado: ");
    scanf(" %[^\n]", carta->estado);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);

    printf("Código da carta (ex: A01): ");
    scanf(" %s", carta->codigo);

    printf("População (em habitantes): ");
    scanf("%lu", &carta->populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta->area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Cálculos automáticos
    carta->densidade = carta->area != 0 ? carta->populacao / carta->area : 0;
    carta->pibPerCapita = carta->populacao != 0 ? (carta->pib * 1000000000.0) / carta->populacao : 0;
    carta->superPoder = (float)carta->populacao + carta->area + carta->pib +
                        carta->pontosTuristicos + carta->pibPerCapita +
                        (carta->densidade != 0 ? (1.0 / carta->densidade) : 0);
}

void exibirCarta(Carta carta) {
    printf("\n--- Exibindo Carta %s ---\n", carta.codigo);
    printf("Estado: %s\n", carta.estado);
    printf("Cidade: %s\n", carta.nomeCidade);
    printf("População: %lu\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidade);
    printf("PIB per Capita: R$ %.2f\n", carta.pibPerCapita);
    printf("Super Poder: %.2f\n", carta.superPoder);
}

int compararFloat(float a, float b, int menorVence) {
    return menorVence ? (a < b) : (a > b);
}

int compararLong(unsigned long int a, unsigned long int b) {
    return a > b;
}

void compararCartas(Carta c1, Carta c2) {
    printf("\n--- Comparação Entre Cartas ---\n");
    printf("População: %d\n", compararLong(c1.populacao, c2.populacao));
    printf("Área: %d\n", compararFloat(c1.area, c2.area, 0));
    printf("PIB: %d\n", compararFloat(c1.pib, c2.pib, 0));
    printf("Pontos Turísticos: %d\n", compararLong(c1.pontosTuristicos, c2.pontosTuristicos));
    printf("Densidade Populacional: %d\n", compararFloat(c1.densidade, c2.densidade, 1));
    printf("PIB per Capita: %d\n", compararFloat(c1.pibPerCapita, c2.pibPerCapita, 0));
    printf("Super Poder: %d\n", compararFloat(c1.superPoder, c2.superPoder, 0));
}

int main() {
    Carta cartas[NUM_CARTAS];

    cadastrarCarta(&cartas[0]);
    cadastrarCarta(&cartas[1]);

    exibirCarta(cartas[0]);
    exibirCarta(cartas[1]);

    compararCartas(cartas[0], cartas[1]);

    return 0;
}
