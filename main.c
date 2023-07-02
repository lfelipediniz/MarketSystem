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
        storage->products = realloc(storage->products, storage->capacity * 2);
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
//A função retorna o dinheiro ganho com as vendas, para facilitar na hora de fazer o comando CS
float sale(Stock *storage) {
    int id = 0;
    float total = 0;
    float dinheiroVenda = 0;

    while (1) {
        scanf("%d", &id);

        if (id == -1)
            break;
        else if (id >= 0 && storage->products[(unsigned) id].qtd > 0 && id < storage->qtd) {
            storage->products[(unsigned) id].qtd -= 1;
            dinheiroVenda += storage->products[(unsigned) id].price;
        }
    }

    for (int i = 0; i < storage->qtd; i++) {
        printf("%s %.2f \n", storage->products[i].name, storage->products[i].price);
        total += storage->products[i].price * (float) storage->products[i].qtd;
    }
    printf("Total: %.2f\n", total);

    for (int j = 0; j < 50; j++)
        printf("-");

    printf("\n");

    return dinheiroVenda;
}

void inventoryConsultation(Stock *storage) {
    int i;

    for (i = 0; i < storage->qtd; i++) {
        printf("%u %s %u \n", storage->products[i].id, storage->products[i].name, storage->products[i].qtd);
    }

    for (int j = 0; j < 50; j++)
        printf("-");

    printf("\n");
}

int main() {
    unsigned int stockSize;
    char command[3];
    Stock stockStorage;

    //Acho que não é para printar nada nesse começo
    //printf("Espaco atual do estoque: ");
    scanf("%u", &stockSize);

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

    return 0;
}
