#include <stdio.h>
#include <string.h>

int main(){

    // --- CARTA 1: Declaracao de Variaveis ---
    char estado1[20];
    char codigo_da_carta1[6];
    char nome_da_cidade1[50];
    unsigned int populacao1;
    float area_em_km1;
    float pib1;


    // --- CARTA 2: Declaracao de Variaveis ---
    char estado2[20];
    char codigo_da_carta2[6];
    char nome_da_cidade2[50];
    unsigned int populacao2;
    float area_em_km2;
    float pib2;
    
    // --- CARTA 1: Coleta de Dados ---
    printf("--- Cadastro da Primeira Carta ---\n");

    printf("Informe a sigla do estado (ex: ES): ");
    fgets(estado1, sizeof(estado1), stdin);
    estado1[strcspn(estado1, "\n")] = 0;

    printf("Informe o codigo da carta (ex: DDD da cidade): ");
    scanf("%s", codigo_da_carta1);
    getchar();

    printf("Informe o nome da cidade: ");
    fgets(nome_da_cidade1, sizeof(nome_da_cidade1), stdin);
    nome_da_cidade1[strcspn(nome_da_cidade1, "\n")] = 0;

    printf("Informe a populacao (somente numeros): ");
    scanf("%u", &populacao1);

    printf("Informe a area em km² dessa cidade: ");
    scanf("%f", &area_em_km1);

    printf("Informe o PIB (em bilhoes, ex: 123.45): ");
    scanf("%f", &pib1);

    // --- Operacoes da CARTA 1 apos Coleta ---
    float densidade_populacional1 = (float) populacao1 / area_em_km1;
    float pib_per_capita1 = (float) (pib1 / populacao1) * 1000000000;
    float inverso_densidade1 = area_em_km1 / populacao1;
    float super_poder1 = (float) populacao1 + area_em_km1 + pib1 + pib_per_capita1 + inverso_densidade1;
    
    // --- CARTA 2: Coleta de Dados ---
    printf("\n--- Cadastro da Segunda Carta ---\n");

    printf("Informe a sigla do estado (ex: RJ): ");
    fgets(estado2, sizeof(estado2), stdin);
    estado2[strcspn(estado2, "\n")] = 0;

    printf("Informe o codigo da carta (ex: DDD da cidade): ");
    scanf("%s", codigo_da_carta2);
    getchar();

    printf("Informe o nome da cidade: ");
    fgets(nome_da_cidade2, sizeof(nome_da_cidade2), stdin);
    nome_da_cidade2[strcspn(nome_da_cidade2, "\n")] = 0;

    printf("Informe a populacao (somente numeros): ");
    scanf("%u", &populacao2);

    printf("Informe a area em km²: ");
    scanf("%f", &area_em_km2);

    printf("Informe o PIB (em bilhoes, ex: 67.89): ");
    scanf("%f", &pib2);

    // --- Operacoes da CARTA 2 apos Coleta ---
    float densidade_populacional2 = (float) populacao2 / area_em_km2;
    float pib_per_capita2 = (float) (pib2 / populacao2) * 1000000000;
    float inverso_densidade2 = area_em_km2 / populacao2;
    double super_poder2 = (float) populacao2 + area_em_km2 + pib2 + pib_per_capita2 + inverso_densidade2;

    // --- RESULTADO FINAL: Exibicao das Cartas Cadastradas ---
    printf("\n--- Informacoes das Cartas Cadastradas ---\n");

    printf("\n--- Carta 1 ---\n");
    printf("Estado: %s\n", estado1);
    printf("Codigo: %s\n", codigo_da_carta1);
    printf("Nome da Cidade: %s\n", nome_da_cidade1);
    printf("Populacao: %u habitantes\n", populacao1);
    printf("Area: %.2f km²\n", area_em_km1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional1);
    printf("PIB per Capita: R$ %.2f\n", pib_per_capita1);
    printf("Super Poder: %.2f\n", super_poder1);

    printf("\n--- Carta 2 ---\n");
    printf("Estado: %s\n", estado2);
    printf("Codigo: %s\n", codigo_da_carta2);
    printf("Nome da Cidade: %s\n", nome_da_cidade2);
    printf("Populacao: %u habitantes\n", populacao2);
    printf("Area: %.2f km²\n", area_em_km2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional2);
    printf("PIB per Capita: R$ %.2f\n", pib_per_capita2);
    printf("Super Poder: %.2f\n", super_poder2);

    // --- COMPARACAO DAS CARTAS ---
    printf("\n--- Comparacao dos Atributos ---\n");

    // Logica: 1 se Carta 1 venceu, 0 caso contrario (Carta 2 venceu ou empatou)
    int populacao1Maior = populacao1 > populacao2;
    int area1Maior = area_em_km1 > area_em_km2;
    int pib1Maior = pib1 > pib2;
    int densidade1Maior = densidade_populacional1 < densidade_populacional2; // Menor pode ser melhor
    int pibpercapita1Maior = pib_per_capita1 > pib_per_capita2;
    int superpoder1Maior = super_poder1 > super_poder2;

    int vencedorCarta = 2; // Variavel auxiliar para mostrar qual carta venceu

    printf("Populacao: Carta %d venceu (1: C1 > C2, 2: C2 <= C1)\n", vencedorCarta - populacao1Maior);
    printf("Area: Carta %d venceu (1: C1 > C2, 2: C2 <= C1)\n", vencedorCarta - area1Maior);
    printf("PIB: Carta %d venceu (1: C1 > C2, 2: C2 <= C1)\n", vencedorCarta - pib1Maior);
    printf("Densidade Populacional: Carta %d venceu (1: C1 < C2, 2: C2 >= C1)\n", vencedorCarta - densidade1Maior);
    printf("PIB per Capita: Carta %d venceu (1: C1 > C2, 2: C2 <= C1)\n", vencedorCarta - pibpercapita1Maior);
    printf("Super Poder: Carta %d venceu (1: C1 > C2, 2: C2 <= C1)\n", vencedorCarta - superpoder1Maior);
    
    return 0;
}