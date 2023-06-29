#include <stdio.h>
#include <stdlib.h> // Incluí a biblioteca para alocação dinâmica
#include <string.h>

typedef struct {
   // Struct do Produto
   unsigned int key;
   char name[80];
   unsigned int qtd;
   float price;
} Product;

void insertProduct() {
    printf("Inserting product...\n");
    // inserir um produto
}

void increaseStock() {
    printf("Increasing stock...\n");
    // aumentar o estoque
}

int main() {
   unsigned int stockSize;
   char command[3];

   printf("Espaco atual do estoque: ");
   scanf("%u", &stockSize);

   // alocação dinâmica do estoque
   Product* stock = (Product*)malloc(stockSize * sizeof(Product));
   if (stock == NULL) {
       printf("Erro na alocacao de memoria.\n");
       return 1;
   }

   // loop infinito dos comandos, para só quando o usuário digitar "FE" (Finalizar Execução)
   while (1) {
       scanf("%s", command);

       if (strcmp(command, "IP") == 0) {
           insertProduct();
       } else if (strcmp(command, "AE") == 0) {
           increaseStock();
       } else if (strcmp(command, "FE") == 0) {
           break; // sai do loop
       }
   }

   // libera a memória alocada para o estoque
   free(stock);

   return 0;
}
