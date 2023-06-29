#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   // Struct do Produto
   unsigned int id;
   char name[80];
   unsigned int qtd;
   float price;
} Product;

typedef struct {
   // Struct do Estoque

   unsigned int qtd;
   unsigned int capacity;
   Product* products;
} Stock;

void insertProduct(Stock * storage) {
   char name[80];
   unsigned int qtd;
   float price;

   scanf(" %[^\n]", name);
   scanf("%u", &qtd);
   scanf("%f", &price);

   if(storage->qtd == storage->capacity) {
      storage->products =  realloc(storage->products, storage->capacity * 2);
      storage->capacity *= 2;
   }

   strcpy(storage->products[storage->qtd].name, name);
   storage->products[storage->qtd].qtd = qtd;
   storage->products[storage->qtd].price = price;
   storage->products[storage->qtd].id = storage->qtd;


   storage->qtd++;

   printf("Produto inserido com sucesso!\n");
}

void increaseStock() {}

void displayProducts() {

}

int main() {
   unsigned int stockSize;
   char command[3];
   Stock stockStorage;

   printf("Espaco atual do estoque: ");
   scanf("%u", &stockSize);

   // Alocação dinâmica do estoque
    stockStorage.products = (Product*)malloc(stockSize * sizeof(Product));
   if (stockStorage.products == NULL) {
      printf("Erro na alocacao de memoria.\n");
      return 1;
   }

   stockStorage.capacity = stockSize;
   stockStorage.qtd = 0;

   // Loop infinito dos comandos, para só quando o usuário digitar "FE"
   // (Finalizar Execução)
   while (1) {
      printf("Comando (IP/AE/FE): ");
      scanf("%s", command);

      if (strcmp(command, "IP") == 0) {
         insertProduct(&stockStorage);
      } else if (strcmp(command, "AE") == 0) {
         increaseStock();
      } else if (strcmp(command, "aa") == 0) {
         displayProducts(&stockStorage);
      } else if (strcmp(command, "FE") == 0) {
         break;  // Sai do loop
      }
   }

   // Libera a memória alocada para o estoque
   free(stockStorage.products);

   return 0;
}
