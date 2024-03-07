#include <stdio.h>

void applyDiscount(int* price, double* discount) {
  
    if (*price <= 30 ){
        *discount = 0.2;

      *price = *price - (*price * *discount);

      *discount = *discount * 100;
    }

    else if (*price >= 31 && *price <= 50 ){
          *discount = 0.4;

        *price = *price - (*price * *discount);

        *discount = *discount * 100;
      }
    else if (*price >= 51 ){
        *discount = 0.5;

      *price = *price - (*price * *discount);

      *discount = *discount * 100;
    }
      
    else{
      *discount = 0.0;
    }
}

int main(void) {

  int precocomDesconto;
  int precosemDesconto;
  double desconto;

  printf("Coloque o preço do produto: \n");
  scanf("%d", &precocomDesconto);

  //salva o preço sem desconto
  precosemDesconto = precocomDesconto;
  
  applyDiscount(&precocomDesconto, &desconto);
  
  if ( desconto == 0.0 ){
    printf("O preço do produto: %d\n", precosemDesconto);
    printf("O produto não possui desconto\n");
  }
  else {
    printf("O preço do produto sem desconto: %d\n", precosemDesconto);
    printf("O preço do produto com desconto: %d\n", precocomDesconto);
    printf("Valor do desconto aplicado: %.f%%\n", desconto);
  }
  
  return 0;
}