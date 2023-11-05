#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *genero_1[5];
  char *genero_2[5];
  int op = 1;
  int i;

  /* DANCE */
  genero_1[0] = "What Is Love? — Haddaway";
  genero_1[1] = "Run To Me — Double You";
  genero_1[2] = "Saturday Night — Whigfield";
  genero_1[3] = "The Rhythm Of The Night — Corona";
  genero_1[4] = "Mr. Vain — Culture Beat";

  /* ROCK */
  genero_2[0] = "Smells Like Teen Spirit — Nirvana";
  genero_2[1] = "Losing My Religion — R.E.M.";
  genero_2[2] = "Creep — Radiohead";
  genero_2[3] = "Creep — Radiohead";
  genero_2[4] = "Wonderwall — Oasis";

  while (op) {
    printf("\nEscolha um genero musical\n"
           "\n[1] - Dance"
           "\n[2] - Rock"
           "\n[0] - Sair"
           "\n==> ");
    scanf("%d", &op);

    switch (op) {
    case 1:
      printf("\t[ Dance !]\n");
      printf("[1] => %s \n[2] => %s \n[3] => %s \n[4] => %s \n[5] => %s",
             genero_1[0], genero_1[1], genero_1[2], genero_1[3], genero_1[4]);
      printf("\nEscolha uma musica ==> ");
      scanf("%d", &op);
      for (i = 0; i < 5; i++) {
        printf("\nTocando => %s", genero_1[i]);
      }
      break;
    case 2:
      printf("\t[ Rock ]\n");
      printf("[1] => %s \n[2] => %s \n[3] => %s \n[4] => %s \n[5] => %s",
             genero_2[0], genero_2[1], genero_2[2], genero_2[3], genero_2[4]);
      printf("\nEscolha uma musica ==> ");
      scanf("%d", &op);
      for (i = 0; i < 5; i++) {
        printf("\nTocando => %s", genero_2[i]);
        break;
      }
    default:
      printf("\nErro! Operacao Invalida\n");
    }
  }
  return 0;
}
