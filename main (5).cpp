#include <stdio.h>
#include <locale.h>
#include <string.h>

typedef struct {
    char banda[50];
    int ano;
    char genero[50];
    int quant;
    float preco;
} CD;

typedef struct {
    char nome[50];
} Cliente;

CD cd;
Cliente cliente;

int cdCadastrado = 0;
int clienteCadastrado = 0;

void cadastrarCD();
void cadastrarCliente();
void listarCD();
void listarCliente();
void realizarVenda();

int main() {
    setlocale(LC_ALL, "");
    int op;

    do {
        printf("\n--- Sistema de Controle de CDs ---\n");
        printf("1 - Cadastrar CD\n");
        printf("2 - Cadastrar cliente\n");
        printf("3 - Listar CD\n");
        printf("4 - Listar cliente\n");
        printf("5 - Realizar venda\n");
        printf("0 - Sair\n");
        printf("Selecione uma opção: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                cadastrarCD();
                break;
            case 2:
                cadastrarCliente();
                break;
            case 3:
                listarCD();
                break;
            case 4:
                listarCliente();
                break;
            case 5:
                realizarVenda();
                break;
            case 0:
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (op != 0);

    return 0;
}

void cadastrarCD() {
    if (cdCadastrado >= 1) {
        printf("Já existe um CD cadastrado!\n");
        return;
    }

    printf("Nome da banda: ");
    scanf(" %[^\n]", cd.banda);
    printf("Ano de lançamento: ");
    scanf("%d", &cd.ano);
    printf("Gênero musical: ");
    scanf(" %[^\n]", cd.genero);
    printf("Quantidade em estoque: ");
    scanf("%d", &cd.quant);
    printf("Preço do CD: ");
    scanf("%f", &cd.preco);

    cdCadastrado++;
    printf("CD cadastrado!\n");
}

void cadastrarCliente() {
    if (clienteCadastrado >= 1) {
        printf("Já existe um cliente cadastrado!\n");
        return;
    }

    printf("Nome do cliente: ");
    scanf(" %[^\n]", cliente.nome);

    clienteCadastrado++;
    printf("Cliente cadastrado!\n");
}

void listarCD() {
    if (cdCadastrado == 0) {
        printf("Nenhum CD cadastrado.\n");
        return;
    }

    printf("Banda: %s\n", cd.banda);
    printf("Ano: %d\n", cd.ano);
    printf("Gênero: %s\n", cd.genero);
    printf("Quantidade em estoque: %d\n", cd.quant);
    printf("Preço: R$ %.2f\n", cd.preco);
}

void listarCliente() {
    if (clienteCadastrado == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    printf("Cliente: %s\n", cliente.nome);
}

void realizarVenda() {
    if (cdCadastrado == 0) {
        printf("Nenhum CD cadastrado.\n");
        return;
    }

    if (clienteCadastrado == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    printf("CD disponível: %s\n", cd.banda);
    printf("Gênero: %s\n", cd.genero);
    printf("Ano: %d\n", cd.ano);
    printf("Preço: R$ %.2f\n", cd.preco);
    printf("Quantidade em estoque: %d\n", cd.quant);

    int quantidade;
    printf("Quantidade desejada: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0) {
        printf("Quantidade inválida!\n");
        return;
    }

    if (quantidade > cd.quant) {
        printf("Estoque insuficiente!\n", cd.quant);
        return;
    }

    cd.quant -= quantidade;
    float total = quantidade * cd.preco;

    printf("Venda realizada para %s!\n", cliente.nome);
    printf("CD comprado: %s\n", cd.banda);
    printf("Quantidade: %d\n", quantidade);
    printf("Valor total: R$ %.2f\n", total);
    printf("Estoque atualizado: %d unidades\n", cd.quant);

    if (cd.quant == 0) {
        printf("Estoque esgotado!\n");
    }
}
