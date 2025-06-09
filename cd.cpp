#include <stdio.h>

typedef struct {
    char banda[50];
    int ano;
    char genero[50];
    int quant;
    float preco;
} CD;

CD cd[5];

void cadastrarCD() {
    for (int i = 0; i < 5; i++) {
        if (cd[i].quant == 0) { 
            printf("Cadastro do CD %d:\n", i + 1);
            printf("Nome da banda: ");
            scanf(" %[^\n]", cd[i].banda);
            printf("Ano de lançamento: ");
            scanf("%d", &cd[i].ano);
            printf("Gênero musical: ");
            scanf(" %[^\n]", cd[i].genero);
            printf("Quantidade em estoque: ");
            scanf("%d", &cd[i].quant);
            printf("Preço unitário: ");
            scanf("%f", &cd[i].preco);
            printf("CD cadastrado com sucesso!\n");
            return;
        }
    }
    printf("Estoque cheio!\n");
}

void venderCD() {
    int cdEscolhido, quant;

    printf("Digite o número do CD que deseja comprar (1 a 5): ");
    scanf("%d", &cdEscolhido);

    if (cdEscolhido < 1 || cdEscolhido > 5 || cd[cdEscolhido - 1].quant == 0) {
        printf("CD não disponível ou número inválido!\n");
        return;
    }

    printf("CD encontrado! Quantidade disponível: %d\n", cd[cdEscolhido - 1].quant);
    printf("Preço unitário: R$ %.2f\n", cd[cdEscolhido - 1].preco);

    printf("Digite a quantidade desejada para compra: ");
    scanf("%d", &quant);

    if (quant <= 0) {
        printf("Quantidade inválida!\n");
    } else if (quant > cd[cdEscolhido - 1].quant) {
        printf("Estoque insuficiente! Apenas %d unidades disponíveis.\n", cd[cdEscolhido - 1].quant);
    } else {
        cd[cdEscolhido - 1].quant -= quant;
        float total = quant * cd[cdEscolhido - 1].preco;
        printf("\nVenda realizada com sucesso! Valor total: R$ %.2f\n", total);
        printf("Estoque restante: %d unidades\n", cd[cdEscolhido - 1].quant);
        if (cd[cdEscolhido - 1].quant == 0) {
            printf("Este CD está fora de estoque!\n");
        }
    }
}

void pesquisarPorGenero() {
    char genero[50];
    int encontrado = 0;

    printf("Digite o gênero que deseja pesquisar: ");
    scanf(" %[^\n]", genero);

    for (int i = 0; i < 5; i++) {
        if (cd[i].quant > 0 && (cd[i].genero, genero) == 0) {
            printf("\nCD encontrado - %d:\n", i + 1);
            printf("Banda: %s\n", cd[i].banda);
            printf("Ano de lançamento: %d\n", cd[i].ano);
            printf("Quantidade disponível: %d\n", cd[i].quant);
            printf("Preço unitário: R$ %.2f\n", cd[i].preco);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhum CD encontrado para o gênero '%s'.\n", genero);
    }
}

void consultarCD() {
    int cdEscolhido;

    printf("Digite o número do CD que deseja consultar (1 a 5): ");
    scanf("%d", &cdEscolhido);

    if (cdEscolhido < 1 || cdEscolhido > 5 || cd[cdEscolhido - 1].quant == 0) {
        printf("CD não disponível ou número inválido!\n");
        return;
    }

    printf("\nCD encontrado! Quantidade disponível: %d\n", cd[cdEscolhido - 1].quant);
    printf("Preço unitário: R$ %.2f\n", cd[cdEscolhido - 1].preco);
}

int main() {
    int op;

    printf("--- Bem-vindo ao Sistema de Controle de Estoque de CDs ---\n");

    do {
        printf("= Menu de Opções =\n");
        printf("1 - Cadastrar CD\n");
        printf("2 - Vender CD\n");
        printf("3 - Pesquisar CD por gênero\n");
        printf("4 - Consultar CD\n");
        printf("0 - Sair\n");
        printf("Selecione uma opção: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                cadastrarCD();
                break;
            case 2:
                venderCD();
                break;
            case 3:
                pesquisarPorGenero();
                break;
            case 4:
                consultarCD();
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (op != 0);

    return 0;
}