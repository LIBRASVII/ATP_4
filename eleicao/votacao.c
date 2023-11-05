#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cadidatos {
  char *nome;
  int votos;
} Cadidatos[5] = {{"[33] - Juan Gonsalveis", 0},
                  {"[04] - Joaquina de Marques", 0},
                  {"[11] - Pinheiro da Tilapia", 0},
                  {"[77] - Silvio Cazaquistão", 0},
                  {"[20] - Liane Gabriele", 0}};

struct cadidatos Cadidatos[5];

int main() {
  int branco, nulo;
  int i, count;
  int op;

  while (op) {
    printf("\n :: Eleicoes do Condominio 2024 ::\n"
           "\n[1] - Votar"
           "\n[0] - Sair"
           "\n=>> ");
    fflush(stdin);
    scanf(" %d", &op);

    if (!Cadidatos[i].votos) {
      printf("\n:: Votos por candidatos ::\n");
      for (i = 0; i < 5; i++) {
        printf("\n%s %d votos", Cadidatos[i].nome, Cadidatos[i].votos);
      }
    }
    if (op == 1) {

      printf("\n :: Candidatos :: \n");
      printf("\n[33] - Juan Gonsalveis"
             "\n[04] - Joaquina de Marques"
             "\n[11] - Pinheiro da Tilapia"
             "\n[77] - Silvio Cazaquistão"
             "\n[20] - Liane Gabriele"
             "\n[1] - Nulo"
             "\n[2] - Branco\n"
             "\nDigite o numero do cadidato que deseja votar ==> ");
      fflush(stdin);
      scanf(" %d", &count);
      switch (count) {
      case 33:
      case 04:
      case 11:
      case 77:
      case 20: {
        Cadidatos[count - 1].votos++;
        printf("\nVoto realizado com sucesso\n");
        break;
      }
      case 1: {
        nulo++;
        break;
      }
      case 2: {
        branco++;
        break;
      }
      default: {
        printf("\n|>          Aviso!!         <|"
               "\n|> Esse cadidato não existe <|\n");
      }
      }
    } else
      break;
  }

  return 0;
}
