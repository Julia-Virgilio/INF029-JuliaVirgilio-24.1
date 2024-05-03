#include <stdio.h>
#include <stdlib.h>
#define cls system("clear")

void imprimir(char tab[3][3]){   
  system("clear");
  printf("    1   2   3\n");
  printf("A   %c | %c | %c\n", tab[0][0],tab[0][1],tab[0][2]);
  printf("    ----------\n");
  printf("B   %c | %c | %c\n", tab[1][0],tab[1][1],tab[1][2]);
  printf("    ----------\n");
  printf("C   %c | %c | %c\n\n", tab[2][0],tab[2][1],tab[2][2]);
}

int checar(char tab[3][3], int linha, int coluna){    
  if(tab[linha][coluna-1] == 'X' || tab[linha][coluna-1] == 'O') 
  return 1; 

  return 0;
}

int ganhou(char tab[3][3], char jogador_1, char jogador_2){ 

  for (int linha = 0; linha < 3; linha++) {
  if (tab[linha][0] == jogador_1 && tab[linha][1] == jogador_1 && tab[linha][2] == jogador_1) return 1;
  }

  for (int linha = 0; linha < 3; linha++) {
    if (tab[linha][0] == jogador_2 && tab[linha][1] == jogador_2 && tab[linha][2] == jogador_2) return 2;
  }

  for (int coluna = 0; coluna < 3; coluna++) {
    if (tab[0][coluna] == jogador_1 && tab[1][coluna] == jogador_1 && tab[2][coluna] == jogador_1) return 1;
  }

  for (int coluna = 0; coluna < 3; coluna++) {
    if (tab[0][coluna] == jogador_2 && tab[1][coluna] == jogador_2 && tab[2][coluna] == jogador_2) return 2;
  }

  if(tab[0][0] == jogador_1 && tab[1][1] == jogador_1 && tab[2][2] == jogador_1) return 1;
  if(tab[0][2] == jogador_1 && tab[1][1] == jogador_1 && tab[2][0] == jogador_1) return 1;

  if(tab[0][0] == jogador_2 && tab[1][1] == jogador_2 && tab[2][2] == jogador_2) return 2;
  if(tab[0][2] == jogador_2 && tab[1][1] == jogador_2 && tab[2][0] == jogador_2) return 2;

  return 0;
}

int main(){

char tab[3][3], jogada, jogador_1, jogador_2, sair;
int coluna, linha, rodada;

while(sair != 'n'){
  jogador_1 = 'c';
  jogador_2 = 'c';
  system("clear");

  while(jogador_1 != 'X' && jogador_1 != 'O'){
    printf("Jogador 1 será que símbolo? (X ou O): ");
    scanf(" %c", &jogador_1);
    if(jogador_1 > 'Z') jogador_1 -= 32;
    if(jogador_1 != 'X' && jogador_1 != 'O'){
      system("clear");
      printf("Jogador 1, você não escolheu um símbolo válido!\n\n");
    }
  }

  if(jogador_1 == 'X') jogador_2 = 'O';
  else jogador_2 = 'X';


  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      tab[i][j] = ' ';
    }
  }

  imprimir(tab);

  for(rodada = 1; rodada < 9; rodada++){

    if(rodada % 2 != 0) printf("Jogador 1, informe sua jogada: ");
    else printf("Jogador 2, informe sua jogada: ");
    scanf(" %c %i", &jogada, &coluna);

    if(jogada > 'Z') jogada -= 32;    
    switch(jogada){
      case 'A': linha = 0; break;
      case 'B': linha = 1; break;
      case 'C': linha = 2; break;
      default: linha = -1;
    }

    if(linha == -1 || coluna < 1 || coluna > 3){ 
      printf("\nJogada inválida!\n\n");
      rodada--;
    } else{

    if(checar(tab,linha,coluna) == 1){
      printf("\nPosição já preenchida!\n\n");
      rodada--;
    } else {
    if(rodada % 2 != 0) tab[linha][coluna - 1] = jogador_1;  
    else tab[linha][coluna-1] = jogador_2;
    imprimir(tab);

    if(ganhou(tab, jogador_1, jogador_2) != 0){
      if(ganhou(tab, jogador_1, jogador_2) == 1){
        printf("Jogador 1 venceu!\n\n");
        break;
      } else{
        printf("Jogador 2 venceu!\n\n");
        break;
      }
    }
    }
    }  
  }

    if(ganhou(tab, jogador_1, jogador_2) == 0){
      printf("Deu velha!\n\n");
    }

    printf("Deseja jogar novamente? (s/n): ");
    scanf(" %c", &sair);
    if(sair == 'S') sair = 's';      
    if(sair == 'N') sair = 'n';
  }  
}