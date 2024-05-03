// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Júlia Carvalho Virgilio
//  email: 202321600035@ifba.edu.br
//  Matrícula: 20232160035
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "JuliaVirgilio20232160035.h"

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;

  for (i = x; i > 1; i--)
    fat = fat * i;

  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
  char sMes[3];
  char sAno[5];
  int i; 

  for (i = 0; data[i] != '/'; i++){
    sDia[i] = data[i];	
  }
  if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
    sDia[i] = '\0';  // coloca o barra zero no final
  }else {
    dq.valido = 0;
    return dq;
  }  


  int j = i + 1; //anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '/'; j++){
    sMes[i] = data[j];
    i++;
  }

  if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
    sMes[i] = '\0';  // coloca o barra zero no final
  }else {
    dq.valido = 0;
    return dq;
  }


  j = j + 1; //anda 1 cada para pular a barra
  i = 0;

  for(; data[j] != '\0'; j++){
    sAno[i] = data[j];
    i++;
  }

  if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
    sAno[i] = '\0';  // coloca o barra zero no final
  }else {
    dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

  dq.valido = 1;

  return dq;
}

int q1(char data[])
{
  int datavalida = 1, inicio_ano = 0, inicio_mes = 0, i = 0;
  char ano[5] = "", mes[3] = "", dia[3] = "";

  for(i = 0; data[i] != '/'; i++){
    inicio_mes = i+2;
  }

  for(i = inicio_mes; data[i] != '/'; i++){
    inicio_ano = i+2;
  }

  strncpy(dia, data, 2);

  strncpy(mes, &data[inicio_mes], 2);

  strncpy(ano, &data[inicio_ano], 4);

  int ano_i = atoi(ano), mes_i = atoi(mes), dia_i = atoi(dia);

  if(dia_i <= 0 || dia_i > 31) datavalida = 0;
  if(mes_i <= 0 || mes_i > 12) datavalida = 0;
  if(ano_i <= 0) datavalida = 0;

  if(dia_i == 31 && (mes_i == 4 || mes_i == 6 || mes_i == 9 || mes_i == 11)) datavalida = 0;

   if(mes_i == 2 && dia_i == 29){
      if(ano_i % 4 != 0) datavalida = 0;
      if(ano_i % 100 == 0 && ano_i % 400 != 0) datavalida = 0;
   }

  if (datavalida)
      return 1;
  else
      return 0;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma; //qtd de dias, meses e anos + retorno
    dma.qtdAnos = 0;
    dma.qtdMeses = 0;
    dma.qtdDias = 0;

    DataQuebrada data_i = quebraData(datainicial);
    DataQuebrada data_f = quebraData(datafinal);

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{

      if(data_i.iAno == data_f.iAno){
      if((data_i.iMes > data_f.iMes) || (data_i.iMes == data_f.iMes && data_i.iDia > data_f.iDia)){
        dma.retorno = 4;
        return dma;
      } 
      if(data_i.iMes == data_f.iMes){
        if(data_i.iDia != data_f.iDia){
          dma.qtdDias = data_f.iDia - data_i.iDia;
        }
      } else{
          dma.qtdDias = data_f.iDia - data_i.iDia;
          dma.qtdMeses = data_f.iMes - data_i.iMes;
        }
      }

      if(data_i.iAno > data_f.iAno){
         dma.retorno = 4;
         return dma;
       } 

      if(data_i.iAno % 4 == 0 || data_f.iAno % 4 == 0){
        int temp = 0;
        if((data_f.iMes < data_i.iMes && data_i.iMes - data_f.iMes == 1) && data_i.iMes == 2){
          temp = (29 - data_i.iDia) + data_f.iDia;
          if(temp == 29) dma.qtdMeses++;
          else dma.qtdDias = temp;          
        }

        if(data_f.iMes < data_i.iMes && data_i.iMes - data_f.iMes == 1){
          if(data_f.iMes == 4 || data_f.iMes == 6 || data_f.iMes == 9 || data_f.iMes == 11){
            temp = (30 - data_i.iDia) + data_f.iDia;
            if(temp == 30) dma.qtdMeses++;
            else dma.qtdDias = temp;
          } else{
            temp = (31 - data_i.iDia) + data_f.iDia;
            if(temp == 31) dma.qtdMeses++;
            else dma.qtdDias = temp;
          }
        } else{
          if(data_f.iMes < data_i.iMes){
            if(data_i.iDia < data_f.iDia){
              dma.qtdDias = data_f.iDia - data_i.iDia;
            } else{
              dma.qtdDias = data_i.iDia - data_f.iDia;
            }
            dma.qtdMeses = data_i.iMes - data_f.iMes;
          } else{
            dma.qtdMeses = data_f.iMes - data_i.iMes;
          }
        }
      }
      dma.qtdAnos = data_f.iAno - data_i.iAno;
    }

      //se tudo der certo
      dma.retorno = 1;
      return dma;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive){
    int qtdOcorrencias = -1;

    if(isCaseSensitive != 1){
        if(c > 90) c -= 32;

        for(int i = 0; texto[i] != '\0'; i++){
            if(texto[i] > 90){
              char aux = texto[i] - 32;
              if(aux == c) qtdOcorrencias++;
            } else{
            if(texto[i] == c) qtdOcorrencias++;
            }
        }
    } else{
         for(int i = 0; texto[i] != '\0'; i++){
            if(texto[i] == c) qtdOcorrencias++;
        }
    }

    return qtdOcorrencias + 1;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
  int qtdOcorrencias = -1, tam = strlen(strBusca), aux = 0, k = 0;

   for(int i = 0; i < strlen(strTexto); i++){      
      if(strTexto[i] == strBusca[0]){
        int j = 0;        
        aux = i + 1;
        for(; j < strlen(strBusca); j++){
          if(strTexto[i+j] != strBusca[j]){
            break;
          }
        }
        if(j == tam || strBusca[j] == '\0'){
          qtdOcorrencias++;
          posicoes[k] = aux;
          k++;
          posicoes[k] = aux+j-1;
          k++;
        }
      }
    }

  for(int i = 0; i < strlen(strTexto); i++){
    if(i < posicoes[0] && strTexto[i] < 0){
      for(int j = 0; j < 30; j++){
        posicoes[j] -= 2;
        i++;
      }
    }
  }

    return qtdOcorrencias + 1;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
  int inverso = 0;

  while(num > 0){
    inverso = inverso * 10 + num % 10;
    num /= 10;
  }

  return inverso;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca){
  int qtdOcorrencias = 0, aux = 1, salvo = numerobusca, yes = 0;  

  while(salvo > 0){
    salvo /= 10;
    aux *= 10;
  }

  while(numerobase > 0){
    if(numerobase % aux == numerobusca){
       qtdOcorrencias++;
       yes++;
    }
    if(yes> 0){
      numerobase /= aux;
      yes = 0;
    } else
    numerobase /= 10;
  }

  return qtdOcorrencias;
}