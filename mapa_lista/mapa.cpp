#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Materias {
  string codigo;
  string disciplina;
};

int main() {
  int chave;
  char disciplina[20], codigo[5];

  map<int, Materias> Mapa_Lista;

  Materias mat;
  mat.codigo = "93";
  mat.disciplina = "Estrutura de Dados I";
  Mapa_Lista[1] = mat;
  mat.codigo = "143";
  mat.disciplina = "Estrutura de Dados II";
  Mapa_Lista[2] = mat;
  mat.codigo = "183";
  mat.disciplina = "Estrutura de Dados III";
  Mapa_Lista[3] = mat;

  if (Mapa_Lista.find(chave) == Mapa_Lista.end()) {
    printf("\nAdicionar nova disciplina");
    printf("\nInforme a chave para armazenar: ");
    scanf("%d", &chave);

    mat.codigo = codigo;
    mat.disciplina = disciplina;
    Mapa_Lista[chave] = mat;

    cout << "\nDisciplina Inserida com sucesso" << endl;
    cout << "\nCodigo: " + Mapa_Lista[chave].codigo +
                "\nDisciplina: " + Mapa_Lista[chave].disciplina + "\n"
         << endl;
  } else {
    cout << "\nChave ja existente!" << endl;
  }

  printf("\nInforme a chave para a remação: ");
  scanf("%d", &chave);

  if (Mapa_Lista.find(chave) == Mapa_Lista.end()) {
    cout << "\nChave não existente!" << endl;
  } else {
    Mapa_Lista.erase(Mapa_Lista.find(chave));
  }

  printf("\nInforme a chave para pesquise: ");
  scanf("%d", &chave);

  if (Mapa_Lista.find(chave) == Mapa_Lista.end()) {
    cout << "\nDisciplina não encontrada!" << endl;
  } else {
    cout << "\nDisciplina Encontrada!\nCodigo: " + Mapa_Lista[chave].codigo +
                "\nDisciplina: " + Mapa_Lista[chave].disciplina + "\n"
         << endl;
  }

  char coddisc[5];
  printf("\nInforme o codigo da disciplina: ");
  scanf("%s", &coddisc);

  for (int i = 1; i <= Mapa_Lista.size(); i++) {
    printf("\nPosição %d");

    if (Mapa_Lista[i].codigo == coddisc) {
      cout << "\nDisciplina Encontrada!\nCodigo: " + Mapa_Lista[i].codigo +
                  "\nDisciplina: " + Mapa_Lista[i].disciplina + "\n"
           << endl;
    } else {
      cout << "\nDisciplina não encontrada!" << endl;
    }
  }

  return 0;
}
