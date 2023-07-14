/*GRUPO:
Luiz Felipe Diniz Costa - 13782032
Hélio Márcio Cabral Santos - 14577862
João Vitor Alves de Medeiros - 13726762

github: https://github.com/lfelipediniz/MarketSystem
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   unsigned int id;
   char name[80];
   unsigned int qtd;
   float price;
} Product;

typedef struct {
   unsigned int qtd;
   unsigned int capacity;
   Product *products;
} Stock;

void insertProduct(Stock *storage);
void increaseStock(Stock *storage);
void modifyPrice(Stock *storage);
float sale(Stock *storage);
void inventoryConsultation(Stock *storage);
void checkBalance(float cash);
void finalizeDay(Stock *storage, float cash);

// inserir um produto no estoque
void insertProduct(Stock *storage) {
   char name[80];
   unsigned int qtd;
   float price;

   scanf("%s", name);
   scanf("%u", &qtd);
   scanf("%f", &price);

   // vê se o estoque está cheio e realoca espaço quando necessário
   if (storage->qtd == storage->capacity) {
      storage->products = (Product *)realloc(storage->products, (storage->capacity + 10) * sizeof(Product));
      storage->capacity += 10;
   }

   // Insere o produto no estoque
   strcpy(storage->products[storage->qtd].name, name);
   storage->products[storage->qtd].qtd = qtd;
   storage->products[storage->qtd].price = price;
   storage->products[storage->qtd].id = storage->qtd;

   storage->qtd++;
}

// aumenta o estoque de um produto
void increaseStock(Stock *storage) {
   unsigned int id, qtd;
   scanf("%u %u", &id, &qtd);
   storage->products[id].qtd += qtd;
}

// modificar o preço de um produto
void modifyPrice(Stock *storage) {
   unsigned int id;
   float prc;
   scanf("%u %f", &id, &prc);
   storage->products[id].price = prc;
}

// fazer a venda
float sale(Stock *storage) {
   int id = 0;
   float total = 0;

   // Loop para ler os códigos dos produtos vendidos
   while (1) {
      scanf("%d", &id);

      if (id == -1)
         break;
      else if (id >= 0 && id < (int)storage->qtd && storage->products[id].qtd > 0) {
         printf("%s %.2f\n", storage->products[id].name, storage->products[id].price);
         total += storage->products[id].price;
         storage->products[id].qtd--;
      }
   }

   printf("Total: %.2f\n", total);
   for (int j = 0; j < 50; j++) printf("-");

   printf("\n");

   return total;
}

// consulta o estoque
void inventoryConsultation(Stock *storage) {
   for (int i = 0; i < (int)storage->qtd; i++) {
      printf("%u %s %u\n", storage->products[i].id, storage->products[i].name, storage->products[i].qtd);
   }

   for (int j = 0; j < 50; j++) printf("-");

   printf("\n");
}

// consulta o saldo do caixa
void checkBalance(float cash) {
   printf("Saldo: %.2f\n", cash);
}

// finaliza o dia e grava as informações no arquivo binário
void finalizeDay(Stock *storage, float cash) {
   FILE *file = fopen("dados.bin", "wb");
   
   if (file == NULL) {
      printf("Erro ao abrir o arquivo.\n");
      return;
   }

   // grava o saldo e a quantidade de produtos no arquivo
   fwrite(&cash, sizeof(float), 1, file);
   fwrite(&(storage->qtd), sizeof(unsigned int), 1, file);

   // grava os produtos no arquivo
   fwrite(storage->products, sizeof(Product), storage->qtd, file);

   fclose(file);
}

int main() {
   unsigned int stockSize;
   char command[3];
   Stock stockStorage;
   float cash = 0;

   FILE *file = fopen("dados.bin", "rb");

   if (file != NULL) {
      // lê o saldo e a quantidade de produtos do arquivo
      
      fread(&cash, sizeof(float), 1, file);
      fread(&stockSize, sizeof(unsigned int), 1, file);

      
      // aloca a memória pro estoque
      stockStorage.products = (Product *)malloc(stockSize * sizeof(Product));
      if (stockStorage.products == NULL) {
         printf("Erro na alocacao de memoria.\n");
         return 1;
      }

      stockStorage.capacity = stockSize;
      stockStorage.qtd = fread(stockStorage.products, sizeof(Product), stockSize, file);

      fclose(file);
   } else {
      // se o arquivo não existe, lê o espaço atual do estoque do console
      scanf("%u", &stockSize);
      scanf("%f", &cash);

      // aloca memória pro estoque
      stockStorage.products = (Product *)malloc(stockSize * sizeof(Product));
      if (stockStorage.products == NULL) {
         printf("Erro na alocacao de memoria.\n");
         return 1;
      }

      stockStorage.capacity = stockSize;
      stockStorage.qtd = 0;
   }

   while (1) {
      scanf("%s", command);

      if (strcmp(command, "IP") == 0) {
         insertProduct(&stockStorage);
      } else if (strcmp(command, "AE") == 0) {
         increaseStock(&stockStorage);
      } else if (strcmp(command, "MP") == 0) {
         modifyPrice(&stockStorage);
      } else if (strcmp(command, "VE") == 0) {
         cash += sale(&stockStorage);
      } else if (strcmp(command, "CE") == 0) {
         inventoryConsultation(&stockStorage);
      } else if (strcmp(command, "CS") == 0) {
         checkBalance(cash);
         for (int j = 0; j < 50; j++) printf("-");
         printf("\n");
      } else if (strcmp(command, "FE") == 0) {
         finalizeDay(&stockStorage, cash);
         break;
      }
      
   }

   free(stockStorage.products);

   return 0;
}
