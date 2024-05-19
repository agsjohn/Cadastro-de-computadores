#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct
{
  char modelo[30];
  char marca[30];
  char processador[30];
  int memoria;
  int hd;
  char tipohd;  // Só serão aceitas as letras s para ssd e c para convencional
}Computador;

void escrever(Computador *labin, int tamanho);
void preencher(Computador *labin, int tamanho);
void alterar(Computador *labin, int posicao);
void insere(Computador *labin, int tamanho, int novotamanho);
void exclui(Computador *labin, Computador *aux, int posicao, int tamanho);

main(){
  // setlocale(LC_ALL, "Portuguese");
  int i, opcao, posicao, nregs;
  Computador *laboratorio, *aux;
  printf("Digite quantas Computadors você deseja cadastrar: ");
  scanf("%i",&nregs);
  laboratorio = (Computador*) malloc(nregs*sizeof(Computador));
  do{
    printf("Digite a opção ou zero para sair: 1 preencher, 2 escreve, 3 altera, 4 insere, 5 exclui: ");
    scanf("%i",&opcao);
    getchar();
    switch(opcao){
      case 1:{
        preencher(laboratorio, nregs);
      }
      break;
      case 2:{
        escrever(laboratorio, nregs);
      }
      break;
      case 3:{
        printf("Digite a posição para alteração dos dados, não podendo ser maior que %i: ", (nregs -1));
        scanf("%i", &posicao);
        getchar();
        alterar(laboratorio, posicao);
      }
      break;
      case 4:{
        insere(laboratorio, nregs, nregs + 1);
        nregs++;
      }
      break;
      case 5:{
        printf("Digite a posição para exclusão dos dados, não podendo ser maior que %i: ", (nregs -1));
        scanf("%i", &posicao);
        getchar();
        aux = (Computador*) malloc((nregs - 1)*sizeof(Computador));
        exclui(laboratorio, aux, posicao, nregs);
        laboratorio=aux;
        nregs--;
      }
      break;
      default:{
        printf("opção inválida! ");
      }
    }
  }
  while (opcao !=0);
  free(laboratorio);
}

void escrever(Computador *labin, int tamanho){
  system("clear");
  printf("Listando os Computadores registrados: \n");
  for(int i=0; i<tamanho; i++){
    printf("\n---------------------------------------------------");
    printf("\nModelo: %s",labin[i].modelo);
    printf("\nMarca: %s",labin[i].marca);
    printf("\nProcessador: %s",labin[i].processador);
    printf("\nMemoria: %i",labin[i].memoria);
    printf("\nHd: %i",labin[i].hd);
    printf("\nTipohd: %c",labin[i].tipohd);
  }
  printf("\n---------------------------------------------------\n");
}
void preencher(Computador *labin, int tamanho){
  for(int i=0; i < tamanho; i++){
    printf("\nInforme o modelo: ");
    gets(labin[i].modelo);
    printf("Informe a marca: ");
    gets(labin[i].marca);
    printf("Informe processador: ");
    gets(labin[i].processador);
    printf("Informe a memória: ");
    scanf("%i", &labin[i].memoria);
    getchar();
    printf("Informe o HD: ");
    scanf("%i", &labin[i].hd);
    getchar();
    printf("Informe o tipo de HD: ");
    scanf("%c", &labin[i].tipohd);
    getchar();
    while(labin[i].tipohd != 's' && labin[i].tipohd != 'S' && labin[i].tipohd != 'c' && labin[i].tipohd != 'C'){
      printf("Tipo inválido, digite novamente: ");
      scanf("%c", &labin[i].tipohd);
      getchar();
    }
  }
  system("clear");
}
void alterar(Computador *labin, int posicao){
  int x;
  printf("\nEscolha que informação deseja alterar: \n[0] - Modelo\n[1] - Marca\n[2] - Processador\n[3] - Memoria\n[4] - HD\n[5] - Tipo de HD\n");
  scanf("%i", &x);
  getchar();
  printf("\n");
  switch(x){
    case 0:
      printf("Modelo atual: %s\nNovo modelo: ", labin[posicao].modelo);
      gets(labin[posicao].modelo);
      printf("\nAtualizado com sucesso");
      getchar();
      system("clear");
    break;
    case 1:
      printf("Marca atual: %s\nNova marca: ", labin[posicao].marca);
      gets(labin[posicao].marca);
      printf("\nAtualizado com sucesso");
      getchar();
      system("clear");
    break;
    case 2:
      printf("Processador atual: %s\nNovo processador: ", labin[posicao].processador);
      gets(labin[posicao].processador);
      printf("\nAtualizado com sucesso");
      getchar();
      system("clear");
    break;
    case 3:
      printf("Memoria atual: %i\nNova memoria: ", labin[posicao].memoria);
      scanf("%d", &labin[posicao].memoria);
      getchar();
      printf("\nAtualizado com sucesso");
      getchar();
      system("clear");
    break;
    case 4:
      printf("HD atual: %i\nNovo HD: ", labin[posicao].hd);
      scanf("%d", &labin[posicao].hd);
      getchar();
      printf("\nAtualizado com sucesso");
      getchar();
      system("clear");
    break;
    case 5:
      printf("Tipo de HD atual: %c\nNovo tipo: ", labin[posicao].tipohd);
      scanf("%c", &labin[posicao].tipohd);
      getchar();
      while(labin[posicao].tipohd != 's' && labin[posicao].tipohd != 'S' && labin[posicao].tipohd != 'c' && labin[posicao].tipohd != 'C'){
        printf("Tipo inválido, digite novamente: ");
        scanf("%c", &labin[posicao].tipohd);
        getchar();
      }
      printf("\nAtualizado com sucesso");
      getchar();
      system("clear");
    break;
    default:
      printf("Código inválido");
      getchar();
      system("clear");
  }
}
void insere(Computador *labin, int tamanho, int novotamanho){
  int i;
  labin = realloc(labin, novotamanho * sizeof(Computador));
  i = tamanho;
  printf("\nInforme o modelo: ");
  gets(labin[i].modelo);
  printf("Informe a marca: ");
  gets(labin[i].marca);
  printf("Informe o processador: ");
  gets(labin[i].processador);
  printf("Informe a memória: ");
  scanf("%d", &labin[i].memoria);
  getchar();
  printf("Informe o HD: ");
  scanf("%d", &labin[i].hd);
  getchar();
  printf("Informe o tipo de HD: ");
  scanf("%c", &labin[i].tipohd);
  getchar();
  while(labin[i].tipohd != 's' && labin[i].tipohd != 'S' && labin[i].tipohd != 'c' && labin[i].tipohd != 'C'){
    printf("Tipo inválido, digite novamente: ");
    scanf("%c", &labin[i].tipohd);
    getchar();
  }
  system("clear");
}
void exclui(Computador *labin, Computador *aux, int posicao, int tamanho){
  int j = 0;
  if(posicao >= tamanho){
    printf("\nPosição inválida");
    getchar();
    system("clear");
  } else{
    for(int i=0; i< tamanho; i++){
      if(i != posicao){
        strcpy(aux[j].modelo, labin[i].modelo);
        strcpy(aux[j].marca, labin[i].marca);
        strcpy(aux[j].processador, labin[i].processador);
        aux[j].hd = labin[i].hd;
        aux[j].memoria = labin[i].memoria;
        aux[j].tipohd = labin[i].tipohd;
        j++;
      }
    }
    free(labin);
    labin = aux;
    tamanho--;
    system("clear");
  }
}