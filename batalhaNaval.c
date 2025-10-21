#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

int main() {
    // Declaração e inicialização do tabuleiro com zeros (água)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};
    
    // Vetores para representar os navios
    int navio_horizontal[TAM_NAVIO];
    int navio_vertical[TAM_NAVIO];
    
    // Inicializar os vetores dos navios com valor 3
    for(int i = 0; i < TAM_NAVIO; i++) {
        navio_horizontal[i] = 3;
        navio_vertical[i] = 3;
    }
    
    // Coordenadas iniciais dos navios (definidas no código)
    int linha_horizontal = 2, coluna_horizontal = 3;  // Navio horizontal
    int linha_vertical = 5, coluna_vertical = 7;      // Navio vertical
    
    // VALIDAÇÃO: Verificar se os navios estão dentro dos limites do tabuleiro
    
    // Navio horizontal: verificar se cabe na linha e coluna especificadas
    if(coluna_horizontal + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio horizontal não cabe nas coordenadas especificadas!\n");
        return 1;
    }
    
    // Navio vertical: verificar se cabe na linha e coluna especificadas
    if(linha_vertical + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio vertical não cabe nas coordenadas especificadas!\n");
        return 1;
    }
    
    // VALIDAÇÃO: Verificar sobreposição dos navios
    int sobreposicao = 0;
    for(int i = 0; i < TAM_NAVIO; i++) {
        // Verificar se alguma posição do navio horizontal coincide com o vertical
        if(linha_horizontal == linha_vertical + i && 
           (coluna_horizontal <= coluna_vertical && coluna_vertical < coluna_horizontal + TAM_NAVIO)) {
            sobreposicao = 1;
            break;
        }
        // Verificar se alguma posição do navio vertical coincide com o horizontal
        if(coluna_vertical == coluna_horizontal + i && 
           (linha_vertical <= linha_horizontal && linha_horizontal < linha_vertical + TAM_NAVIO)) {
            sobreposicao = 1;
            break;
        }
    }
    
    if(sobreposicao) {
        printf("Erro: Os navios estão se sobrepondo!\n");
        return 1;
    }
    
    // POSICIONAMENTO: Colocar navio horizontal no tabuleiro
    for(int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
    }
    
    // POSICIONAMENTO: Colocar navio vertical no tabuleiro
    for(int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
    }
    
    // EXIBIÇÃO: Mostrar o tabuleiro no console
    printf("=== TABULEIRO DE BATALHA NAVAL ===\n");
    printf("Legenda: 0 = Água, 3 = Navio\n\n");
    
    // Cabeçalho com números das colunas
    printf("   ");
    for(int col = 0; col < TAM_TABULEIRO; col++) {
        printf("%2d ", col);
    }
    printf("\n");
    
    // Linha separadora
    printf("   ");
    for(int col = 0; col < TAM_TABULEIRO; col++) {
        printf("---");
    }
    printf("\n");
    
    // Tabuleiro com números das linhas
    for(int linha = 0; linha < TAM_TABULEIRO; linha++) {
        printf("%2d|", linha);  // Número da linha
        for(int coluna = 0; coluna < TAM_TABULEIRO; coluna++) {
            printf("%2d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }
    
    // Informações adicionais
    printf("\n=== INFORMAÇÕES DOS NAVIOS ===\n");
    printf("Navio Horizontal: Linha %d, Coluna %d (tamanho: %d)\n", 
           linha_horizontal, coluna_horizontal, TAM_NAVIO);
    printf("Navio Vertical: Linha %d, Coluna %d (tamanho: %d)\n", 
           linha_vertical, coluna_vertical, TAM_NAVIO);
    
    return 0;
}