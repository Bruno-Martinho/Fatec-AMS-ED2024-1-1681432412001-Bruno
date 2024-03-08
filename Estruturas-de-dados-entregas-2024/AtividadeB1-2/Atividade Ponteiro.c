#include <stdio.h>

void applyDiscount(int *price, float discount) {

      *price -= *price * (discount / 100);

}

int main(void) {

  int precocomDesconto;
  int precosemDesconto;
  float desconto;

  printf("Coloque o preço do produto: \n");
  scanf("%d", &precocomDesconto);
  
  printf("Coloque o desconto: \n");
  scanf("%f", &desconto);

  //salva o preço sem desconto
  precosemDesconto = precocomDesconto;
  
  applyDiscount(&precocomDesconto, desconto);

  printf("O preço do produto sem desconto: %d R$\n", precosemDesconto);
  printf("O preço do produto com desconto: %d R$\n", precocomDesconto);
  printf("Valor do desconto aplicado: %.f%%\n", desconto);
  
  return 0;
}
