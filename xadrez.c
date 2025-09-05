#include <stdio.h>

// Constantes para facilitar a manutenção e evitar repetição de valores
#define MOVIMENTOS_BISPO 5
#define MOVIMENTOS_TORRE 5
#define MOVIMENTOS_RAINHA 8
#define CAVALO_VERTICAL 2
#define CAVALO_HORIZONTAL 1

// Protótipos das funções recursivas (Nível Mestre)
void mover_bispo_recursivo(int casas_restantes);
void mover_torre_recursivo(int casas_restantes);
void mover_rainha_recursivo(int casas_restantes);

// Função para exibir separadores visuais
void exibir_separador(const char* titulo) {
    printf("\n==========================================\n");
    printf("           %s\n", titulo);
    printf("==========================================\n");
}

// ===========================================
//            NÍVEL NOVATO
// ===========================================

/**
 * Move o bispo 5 casas na diagonal superior direita
 * Utiliza loop for com printf combinando direções
 */
void nivel_novato_bispo() {
    printf("\n--- Movimentação do Bispo ---\n");
    printf("Movendo %d casas na diagonal superior direita:\n\n", MOVIMENTOS_BISPO);
    
    // Loop for para mover o bispo
    for (int movimento = 1; movimento <= MOVIMENTOS_BISPO; movimento++) {
        printf("Movimento %d: ", movimento);
        // Bispo se move na diagonal - combinação de direções
        printf("Cima");
        printf("Direita\n");
    }
    printf("\nBispo chegou ao destino!\n");
}

/**
 * Move a torre 5 casas para a direita
 * Utiliza loop while
 */
void nivel_novato_torre() {
    printf("\n--- Movimentação da Torre ---\n");
    printf("Movendo %d casas para a direita:\n\n", MOVIMENTOS_TORRE);
    
    int movimento = 1;
    // Loop while para mover a torre
    while (movimento <= MOVIMENTOS_TORRE) {
        printf("Movimento %d: ", movimento);
        printf("Direita\n");
        movimento++;
    }
    printf("\nTorre chegou ao destino!\n");
}

/**
 * Move a rainha 8 casas para a esquerda
 * Utiliza loop do-while
 */
void nivel_novato_rainha() {
    printf("\n--- Movimentação da Rainha ---\n");
    printf("Movendo %d casas para a esquerda:\n\n", MOVIMENTOS_RAINHA);
    
    int movimento = 1;
    // Loop do-while para mover a rainha
    do {
        printf("Movimento %d: ", movimento);
        printf("Esquerda\n");
        movimento++;
    } while (movimento <= MOVIMENTOS_RAINHA);
    printf("\nRainha chegou ao destino!\n");
}

// ===========================================
//           NÍVEL AVENTUREIRO
// ===========================================

/**
 * Move o cavalo em L (para baixo e esquerda)
 * Utiliza loops aninhados: for externo e while interno
 */
void nivel_aventureiro_cavalo() {
    printf("\n--- Movimentação do Cavalo (Nível Aventureiro) ---\n");
    printf("Movendo o cavalo em L (baixo e esquerda):\n\n");
    
    // Loop externo (for) para controlar as fases do movimento em L
    for (int fase = 1; fase <= 2; fase++) {
        printf("Fase %d do movimento em L:\n", fase);
        
        int movimento = 1;
        int movimentos_fase;
        
        // Determinar quantos movimentos para cada fase
        if (fase == 1) {
            movimentos_fase = CAVALO_VERTICAL; // 2 casas para baixo
            printf("Movendo %d casas para baixo:\n", movimentos_fase);
        } else {
            movimentos_fase = CAVALO_HORIZONTAL; // 1 casa para esquerda
            printf("Movendo %d casa para esquerda:\n", movimentos_fase);
        }
        
        // Loop interno (while) para executar os movimentos da fase
        while (movimento <= movimentos_fase) {
            printf("  Movimento %d: ", movimento);
            if (fase == 1) {
                printf("Baixo\n");
            } else {
                printf("Esquerda\n");
            }
            movimento++;
        }
        printf("\n");
    }
    printf("Cavalo completou o movimento em L!\n");
}

// ===========================================
//            NÍVEL MESTRE
// ===========================================

/**
 * Função recursiva para mover o bispo
 * Substitui o loop simples por recursão
 */
void mover_bispo_recursivo(int casas_restantes) {
    // Caso base da recursão
    if (casas_restantes <= 0) {
        printf("\nBispo (recursivo) chegou ao destino!\n");
        return;
    }
    
    // Movimento atual
    int movimento_atual = MOVIMENTOS_BISPO - casas_restantes + 1;
    printf("Movimento %d: ", movimento_atual);
    printf("Cima");
    printf("Direita\n");
    
    // Chamada recursiva para o próximo movimento
    mover_bispo_recursivo(casas_restantes - 1);
}

/**
 * Função recursiva para mover a torre
 */
void mover_torre_recursivo(int casas_restantes) {
    // Caso base da recursão
    if (casas_restantes <= 0) {
        printf("\nTorre (recursiva) chegou ao destino!\n");
        return;
    }
    
    // Movimento atual
    int movimento_atual = MOVIMENTOS_TORRE - casas_restantes + 1;
    printf("Movimento %d: ", movimento_atual);
    printf("Direita\n");
    
    // Chamada recursiva para o próximo movimento
    mover_torre_recursivo(casas_restantes - 1);
}

/**
 * Função recursiva para mover a rainha
 */
void mover_rainha_recursivo(int casas_restantes) {
    // Caso base da recursão
    if (casas_restantes <= 0) {
        printf("\nRainha (recursiva) chegou ao destino!\n");
        return;
    }
    
    // Movimento atual
    int movimento_atual = MOVIMENTOS_RAINHA - casas_restantes + 1;
    printf("Movimento %d: ", movimento_atual);
    printf("Esquerda\n");
    
    // Chamada recursiva para o próximo movimento
    mover_rainha_recursivo(casas_restantes - 1);
}

/**
 * Move o cavalo em L (para cima e direita) usando loops com condições múltiplas
 * Utiliza continue e break conforme solicitado
 */
void nivel_mestre_cavalo() {
    printf("\n--- Movimentação do Cavalo (Nível Mestre) ---\n");
    printf("Movendo o cavalo em L (cima e direita) com loops avançados:\n\n");
    
    // Variáveis múltiplas para controle do loop
    int fase = 1, movimento_total = 0, max_movimentos = 3;
    
    // Loop externo com condições múltiplas
    while (fase <= 2 && movimento_total < max_movimentos) {
        
        // Loop interno para cada fase do movimento
        for (int mov_fase = 1; mov_fase <= 2; mov_fase++) {
            
            // Condição para pular movimentos desnecessários
            if (fase == 2 && mov_fase > 1) {
                continue; // Pula o segundo movimento na segunda fase
            }
            
            // Verifica se já atingiu o limite máximo
            if (movimento_total >= max_movimentos) {
                break; // Sai do loop se atingir o limite
            }
            
            movimento_total++;
            printf("Movimento %d (Fase %d): ", movimento_total, fase);
            
            if (fase == 1) {
                printf("Cima\n");
            } else {
                printf("Direita\n");
            }
        }
        
        printf("Completada fase %d\n\n", fase);
        fase++;
    }
    
    printf("Cavalo (nível mestre) completou o movimento em L!\n");
}

/**
 * Move o bispo usando loops aninhados (obrigatório no nível mestre)
 */
void nivel_mestre_bispo_loops_aninhados() {
    printf("\n--- Movimentação do Bispo com Loops Aninhados ---\n");
    printf("Movendo %d casas na diagonal direita para cima:\n\n", MOVIMENTOS_BISPO);
    
    // Loop externo para controlar o número de movimentos
    for (int movimento = 1; movimento <= MOVIMENTOS_BISPO; movimento++) {
        printf("Movimento %d:\n", movimento);
        
        // Loop interno para simular as duas componentes do movimento diagonal
        for (int componente = 1; componente <= 2; componente++) {
            printf("  Componente %d: ", componente);
            if (componente == 1) {
                printf("Direita");
            } else {
                printf("Cima");
            }
            printf("\n");
        }
        printf("  -> Movimento diagonal completo\n\n");
    }
    printf("Bispo (loops aninhados) chegou ao destino!\n");
}

// ===========================================
//            FUNÇÃO PRINCIPAL
// ===========================================

int main() {
    printf("===========================================\n");
    printf("    DESAFIO DE XADREZ - MATECHECK\n");
    printf("===========================================\n");
    printf("Sistema de Movimentação de Peças\n");
    printf("Testando limites e estruturas de repetição\n");
    
    // NÍVEL NOVATO
    exibir_separador("NÍVEL NOVATO");
    printf("Utilizando estruturas de repetição básicas:\n");
    
    nivel_novato_bispo();
    nivel_novato_torre();
    nivel_novato_rainha();
    
    // NÍVEL AVENTUREIRO
    exibir_separador("NÍVEL AVENTUREIRO");
    printf("Utilizando loops aninhados para movimentação do cavalo:\n");
    
    nivel_aventureiro_cavalo();
    
    // NÍVEL MESTRE
    exibir_separador("NÍVEL MESTRE");
    printf("Utilizando funções recursivas e loops avançados:\n");
    
    printf("\n--- Peças com Funções Recursivas ---\n");
    
    printf("\n--- Movimentação do Bispo (Recursiva) ---\n");
    printf("Movendo %d casas na diagonal superior direita:\n\n", MOVIMENTOS_BISPO);
    mover_bispo_recursivo(MOVIMENTOS_BISPO);
    
    printf("\n--- Movimentação da Torre (Recursiva) ---\n");
    printf("Movendo %d casas para a direita:\n\n", MOVIMENTOS_TORRE);
    mover_torre_recursivo(MOVIMENTOS_TORRE);
    
    printf("\n--- Movimentação da Rainha (Recursiva) ---\n");
    printf("Movendo %d casas para a esquerda:\n\n", MOVIMENTOS_RAINHA);
    mover_rainha_recursivo(MOVIMENTOS_RAINHA);
    
    // Bispo com loops aninhados (obrigatório)
    nivel_mestre_bispo_loops_aninhados();
    
    // Cavalo com loops avançados
    nivel_mestre_cavalo();
    
    exibir_separador("DESAFIO CONCLUÍDO");
    
    return 0;
}
