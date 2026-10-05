#include <stdio.h>

// calcula se o ano é bissexto (1) ou não (0)
int bissexto(int a) {
  int b = a % 4;
  if (b == 0) {
    return 1;
  } else {
    return 0;
  }
}

// calcula quantos anos bissextos existem entre 2000 e o ano fornecido usando a função bissexto(int a)
int quantos_bissextos(int a) {
  int b = 0;

  for (int i = 2000; i < a; i++) {
    if (bissexto(i)) {
      b++;
    }
  }

  return b;
}

// calcula qual dia da semana eh a partir do 01/01/2000 (sabado)
int dia_da_semana(int dia1, int mes1, int ano1) {
  int dia0 = 1, mes0 = 1, ano0 = 2000;
  int meses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int a = 0;

  // calcula quantos dias tiveram no ano até o mes fornecido
  for (int i = 0; i < mes1 - 1; i++) {
    a += meses[i];
  }

  // calcula quandos dias tiveram até o ano fornecido
  a += (ano1 - ano0) * 365 + quantos_bissextos(ano1);

  // calcula quantos dias tiveram entre 01/01/2000 e o dia fornecido
  a += dia1 - 1;

  // calcula o dia da semana
  // 0 = sabado, 1 = domingo, 2 = segunda-feira, 3 = terca-feira, 4 = quarta-feira, 5 = quinta-feira, 6 = sexta-feira
  a = a % 7;

  return a;
}

int main() {
  int dia = 5, mes = 10, ano = 2026;

  int resultado = dia_da_semana(dia, mes, ano);
  printf("%d\n", resultado);
  return 0;
}