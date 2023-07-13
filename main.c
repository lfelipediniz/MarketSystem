#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    // struct do Produto
    unsigned int id;
    char name[80];
    unsigned int qtd;
    float price;
} Product;

typedef struct {
    // struct do Estoque

    unsigned int qtd;
    unsigned int capacity;
    Product *products;
} Stock;

void insertProduct(Stock *storage);
void increaseStock(Stock *storage);
void modifyPrice(Stock *storage);
float sale(Stock *storage);
void inventoryConsultation(Stock *storage);

void insertProduct(Stock *storage) {
    char name[80];
    unsigned int qtd;
    float price;

    scanf("%s", name);
    scanf("%u", &qtd);
    scanf("%f", &price);

    if (storage->qtd == storage->capacity) {
        storage->products = (Product *)realloc(storage->products, storage->capacity * 2);
        storage->capacity *= 2;
    }

    strcpy(storage->products[storage->qtd].name, name);
    storage->products[storage->qtd].qtd = qtd;
    storage->products[storage->qtd].price = price;
    storage->products[storage->qtd].id = storage->qtd;

    storage->qtd++;
}

void increaseStock(Stock *storage) {
    unsigned int id, qtd;
    scanf("%u %u", &id, &qtd);
    storage->products[id].qtd += qtd;
}

void modifyPrice(Stock *storage) {
    unsigned int id;
    float prc;
    scanf("%u %f", &id, &prc);
    storage->products[id].price = prc;
}

//Não coloquei para printar codigo de erro pq as saidas tem que ser exatamente igual o esperado
//A função retorna o saldo depois das vendas, para facilitar na hora de fazer o comando CS
float sale(Stock *storage) {
    int id = 0;
    float saldo = 0;
    float dinheiroVenda = 0;

    while (1) {
        scanf("%d", &id);

        if (id == -1)
            break;
        else if (id >= 0 && storage->products[(unsigned) id].qtd > 0 && id < (int)storage->qtd) {
            storage->products[(unsigned) id].qtd -= 1;
            dinheiroVenda += storage->products[(unsigned) id].price;
            printf("%s %.2f \n", storage->products[id].name, storage->products[id].price);
            saldo += storage->products[id].price * (float) storage->products[id].qtd;
        }
    }

    printf("Total: %.2f\n", dinheiroVenda);

    for (int j = 0; j < 50; j++)
        printf("-");

    printf("\n");

    return saldo;
}

void inventoryConsultation(Stock *storage) {
    int i;

    for (i = 0; i < (int)storage->qtd; i++) {
        printf("%u %s %u \n", storage->products[i].id, storage->products[i].name, storage->products[i].qtd);
    }

    for (int j = 0; j < 50; j++)
        printf("-");

    printf("\n");
}

int main() {
    FILE *fp;
    unsigned int stockSize; //primeiro número do arquivo
    int balance; //segundo número do arquivo
    char command[3];
    Stock stockStorage;

    fp = fopen("MarketFile", "r+");

    // checar se existe o arquivo do dia anterior
    if(fp == NULL){
        fp = fopen("MarketFile","w");
        scanf("%u", &stockSize);
        scanf("%d", &balance);

        // só para ser possível alocar a memoria nos testes, deve ser atualizado com os dados do fim do dia
        fprintf(fp, "%u %d", stockSize, balance);
    }else{
        fscanf(fp, "%u %d", &stockSize, &balance);
    }

    // alocação dinâmica do estoque que contém os produtos
    stockStorage.products = (Product *) malloc(stockSize * sizeof(Product));
    if (stockStorage.products == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return 1;
    }

    stockStorage.capacity = stockSize;
    stockStorage.qtd = 0;

    // loop infinito dos comandos, para só quando o usuário digitar "FE"
    // (Finalizar Execução)
    while (1) {
        //colocar o comando
        scanf("%s", command);

        if (strcmp(command, "IP") == 0) {
            insertProduct(&stockStorage);
        } else if (strcmp(command, "AE") == 0) {
            increaseStock(&stockStorage);
        } else if (strcmp(command, "MP") == 0) {
            modifyPrice(&stockStorage);
        } else if (strcmp(command, "VE") == 0) {
            sale(&stockStorage);
        } else if (strcmp(command, "CE") == 0) {
            inventoryConsultation(&stockStorage);
        } else if (strcmp(command, "FE") == 0) {
            break;  // sai do loop
        }
    }

    // libera a memória alocada para o estoque
    free(stockStorage.products);

    fclose(fp);
    return 0;
}
