#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>


#define LINHAS_EASY 3
#define COLUNAS_EASY 2
#define PARES_EASY 3

#define LINHAS_MEDIUM 4
#define COLUNAS_MEDIUM 2
#define PARES_MEDIUM 4

#define LINHAS_HARD 5
#define COLUNAS_HARD 2
#define PARES_HARD 5

#define LINHAS_INSANE 4
#define COLUNAS_INSANE 5
#define PARES_INSANE 10

char GAB_EASY[LINHAS_EASY][COLUNAS_EASY];
char TAB_EASY[LINHAS_EASY][COLUNAS_EASY];
char CAR_EASY[PARES_EASY] = {'A','B','C'};
int COL_EASY[COLUNAS_EASY];

char GAB_MEDIUM[LINHAS_MEDIUM][COLUNAS_MEDIUM];
char TAB_MEDIUM[LINHAS_MEDIUM][COLUNAS_MEDIUM];
char CAR_MEDIUM[PARES_MEDIUM] = {'A','B','C','D'};
int COL_MEDIUM[COLUNAS_MEDIUM];

char GAB_HARD[LINHAS_HARD][COLUNAS_HARD];
char TAB_HARD[LINHAS_HARD][COLUNAS_HARD];
char CAR_HARD[PARES_HARD] = {'A','B','C','D','E'};
int COL_HARD[COLUNAS_HARD];

char GAB_INSANE[LINHAS_INSANE][COLUNAS_INSANE];
char TAB_INSANE[LINHAS_INSANE][COLUNAS_INSANE];
char CAR_INSANE[PARES_INSANE] = {'A','B','C','D','E','F','G','H','I','J'};
int COL_INSANE[COLUNAS_INSANE];

int erros=0;
int score=0;
int acao=0;

void menu() {
		printf("\n\t Pressione 1 para comecar a jogar!       \n");
		printf("\t Pressione qualquer outra tecla para sair \n");
	  scanf("%d", &acao);
	  system("cls");
 }

void esconder_easy() {
	int i, j;
	for (i=0; i<LINHAS_EASY; i++)
		for (j=0; j<COLUNAS_EASY; j++)
			TAB_EASY[i][j]='*';
}
void esconder_medium() {
	int i, j;
	for (i=0; i<LINHAS_MEDIUM; i++)
		for (j=0; j<COLUNAS_MEDIUM; j++)
			TAB_MEDIUM[i][j]='*';
}
void esconder_hard() {
	int i, j;
	for (i=0; i<LINHAS_HARD; i++)
		for (j=0; j<COLUNAS_HARD; j++)
			TAB_HARD[i][j]='*';
}
void esconder_insane() {
	int i, j;
	for (i=0; i<LINHAS_INSANE; i++)
		for (j=0; j<COLUNAS_INSANE; j++)
			TAB_INSANE[i][j]='*';
}


void inicializacao_easy() {
	int i, j, k=0;
	for (i=0; i<LINHAS_EASY; i++)
		for (j=0; j<COLUNAS_EASY; j++){
			GAB_EASY[i][j]=CAR_EASY[k];
			if (k<PARES_EASY-1)
				k++;
				else
					k=0;
		}
	esconder_easy();
}

void inicializacao_medium() {
	int i, j, k=0;
	for (i=0; i<LINHAS_MEDIUM; i++)
		for (j=0; j<COLUNAS_MEDIUM; j++){
			GAB_MEDIUM[i][j]=CAR_MEDIUM[k];
			if (k<PARES_MEDIUM-1)
				k++;
				else
					k=0;
		}
	esconder_medium();
}

void inicializacao_hard() {
	int i, j, k=0;
	for (i=0; i<LINHAS_HARD; i++)
		for (j=0; j<COLUNAS_HARD; j++){
			GAB_HARD[i][j]=CAR_HARD[k];
			if (k<PARES_HARD-1)
				k++;
				else
					k=0;
		}
	esconder_hard();
}

void inicializacao_insane() {
	int i, j, k=0;
	for (i=0; i<LINHAS_INSANE; i++)
		for (j=0; j<COLUNAS_INSANE; j++){
			GAB_INSANE[i][j]=CAR_INSANE[k];
			if (k<PARES_INSANE-1)
				k++;
				else
					k=0;
		}
	esconder_insane();
}


void embaralhar_easy() {
	int i, j, x, y;
	char aux;
	srand(time(NULL));
	for (i=0; i<LINHAS_EASY; i++)
		for (j=0; j<COLUNAS_EASY; j++){
			x=rand()%LINHAS_EASY;
			y=rand()%COLUNAS_EASY;
			aux=GAB_EASY[i][j];
			GAB_EASY[i][j]=GAB_EASY[x][y];
			GAB_EASY[x][y]=aux;
		}
}

void embaralhar_medium() {
	int i, j, x, y;
	char aux;
	srand(time(NULL));
	for (i=0; i<LINHAS_MEDIUM; i++)
		for (j=0; j<COLUNAS_MEDIUM; j++){
			x=rand()%LINHAS_MEDIUM;
			y=rand()%COLUNAS_MEDIUM;
			aux=GAB_MEDIUM[i][j];
			GAB_MEDIUM[i][j]=GAB_MEDIUM[x][y];
			GAB_MEDIUM[x][y]=aux;
		}
}

void embaralhar_hard() {
	int i, j, x, y;
	char aux;
	srand(time(NULL));
	for (i=0; i<LINHAS_HARD; i++)
		for (j=0; j<COLUNAS_HARD; j++){
			x=rand()%LINHAS_HARD;
			y=rand()%COLUNAS_HARD;
			aux=GAB_HARD[i][j];
			GAB_HARD[i][j]=GAB_HARD[x][y];
			GAB_HARD[x][y]=aux;
		}
}

void embaralhar_insane() {
	int i, j, x, y;
	char aux;
	srand(time(NULL));
	for (i=0; i<LINHAS_INSANE; i++)
		for (j=0; j<COLUNAS_INSANE; j++){
			x=rand()%LINHAS_INSANE;
			y=rand()%COLUNAS_INSANE;
			aux=GAB_INSANE[i][j];
			GAB_INSANE[i][j]=GAB_INSANE[x][y];
			GAB_INSANE[x][y]=aux;
		}
}


void tela_jogo_easy (int acao) {
	int i, j;
	if (acao==1){
		printf ("\n Se desejar encerrar, digite: -1, -1 \n\n\t| NIVEL EASY |  \n\n\t**Voce comeca com 300 pontos e perde 30 a cada erro. Boa sorte!**\n\n\tAcertos: %d ", score);
		printf("\n\n\tErros: %d \n\n", erros);
		printf ("\t ");
		for (i=0; i<COLUNAS_EASY; i++){
			COL_EASY[i]=i;
			printf (" %d\t", COL_EASY[i]);
		}
		printf ("\n");
		for (i=0; i<LINHAS_EASY; i++) {
			printf ("\t%d", i);
			for (j=0; j<COLUNAS_EASY; j++)
				printf ("[%c]\t", TAB_EASY[i][j]);
		printf ("\n\n");
		}
	}
}

void tela_jogo_medium (int acao) {
	int i, j;
	if (acao==1){
		printf ("\n Se desejar encerrar, digite: -1, -1 \n\n\t| NIVEL MEDIUM |  \n\n\t**Voce comeca com 400 pontos e perde 40 a cada erro. Boa sorte!**\n\n\tAcertos: %d ", score);
		printf("\n\n\tErros: %d \n\n", erros);
		printf ("\t ");
		for (i=0; i<COLUNAS_MEDIUM; i++){
			COL_MEDIUM[i]=i;
			printf (" %d\t", COL_MEDIUM[i]);
		}
		printf ("\n");
		for (i=0; i<LINHAS_MEDIUM; i++) {
			printf ("\t%d", i);
			for (j=0; j<COLUNAS_MEDIUM; j++)
				printf ("[%c]\t", TAB_MEDIUM[i][j]);
		printf ("\n\n");
		}
	}
}

void tela_jogo_hard (int acao) {
	int i, j;
	if (acao==1){
		printf ("\n Se desejar encerrar, digite: -1, -1 \n\n\t| NIVEL HARD |  \n\n\t**Voce comeca com 500 pontos e perde 50 a cada erro. Boa sorte!**\n\n\tAcertos: %d ", score);
		printf("\n\n\tErros: %d \n\n", erros);
		printf ("\t ");
		for (i=0; i<COLUNAS_HARD; i++){
			COL_HARD[i]=i;
			printf (" %d\t", COL_HARD[i]);
		}
		printf ("\n");
		for (i=0; i<LINHAS_HARD; i++) {
			printf ("\t%d", i);
			for (j=0; j<COLUNAS_HARD; j++)
				printf ("[%c]\t", TAB_HARD[i][j]);
		printf ("\n\n");
		}
	}
}

void tela_jogo_insane (int acao) {
	int i, j;
	if (acao==1){
		printf ("\n Se desejar encerrar, digite: -1, -1 \n\n\t| NIVEL INSANE |  \n\n\t**Voce comeca com 2000 pontos e perde 20 a cada erro. Boa sorte!!**\n\n\tAcertos: %d ", score);
		printf("\n\n\tErros: %d \n\n", erros);
		printf ("\t ");
		for (i=0; i<COLUNAS_INSANE; i++){
			COL_INSANE[i]=i;
			printf (" %d\t", COL_INSANE[i]);
		}
		printf ("\n");
		for (i=0; i<LINHAS_INSANE; i++) {
			printf ("\t%d", i);
			for (j=0; j<COLUNAS_INSANE; j++)
				printf ("[%c]\t", TAB_INSANE[i][j]);
		printf ("\n\n");
		}
	}
}


void atualizartelaeasy(int acao) {
	Sleep (1000);
	system ("cls");
	tela_jogo_easy(acao);
}
void atualizartelamedium(int acao) {
	Sleep (1000);
	system ("cls");
	tela_jogo_medium(acao);
}
void atualizartelahard(int acao) {
	Sleep (1000);
	system ("cls");
	tela_jogo_hard(acao);
}
void atualizar_tela_insane(int acao) {
	Sleep (1000);
	system ("cls");
	tela_jogo_insane(acao);
}


void jogar_easy (int acao) {
	int i, j, x, y, virar=0, checar=1;
	while (score<3 && acao==1){
		do {
			printf ("\n> Informe as coordenadas (Linha e Coluna) da primeira carta: ");
			scanf ("%d %d", &i, &j);
			if (i<0 || j<0){
				acao=-1;
				break;
			}
			if (i>=LINHAS_EASY || j>=COLUNAS_EASY){
				printf ("Coordenada Invalida!");
				checar=0;
				atualizartelaeasy(acao);
			}
				else
					checar=1;
			if (TAB_EASY[i][j]=='*' && checar==1){
				TAB_EASY[i][j]=GAB_EASY[i][j];
				system ("cls");
				tela_jogo_easy(acao);
				virar++;
			}
				else if (checar==1){
						printf ("Esta carta já foi escolhida!");
						atualizartelaeasy(acao);
					}
		} while (virar<1);
		if (acao<0)
			break;
		do {
			printf ("\n> Informe as coordenadas (Linha e Coluna) da segunda carta: ");
			scanf ("%d %d", &x, &y);
			if (x<0 || y<0){
				acao=-1;
				break;
			}
			if (x>=LINHAS_EASY || y>=COLUNAS_EASY){
				printf ("Coordenada Invalida!");
				checar=0;
				atualizartelaeasy(acao);
			}
				else
					checar=1;
			if (TAB_EASY[x][y]=='*' && checar==1){
				TAB_EASY[x][y]=GAB_EASY[x][y];
				system ("cls");
				tela_jogo_easy(acao);
				virar++;
			}
				else
					if (checar==1){
						printf ("Carta ja escolhida!");
						atualizartelaeasy(acao);
	 				}
		} while (virar<2);
		if (acao<0)
			break;
		if (TAB_EASY[i][j]==TAB_EASY[x][y]){
			virar=0;
			score++;
			printf ("\n\t\t\t\t  ACERTOU!");
		}
			else {
				TAB_EASY[i][j]='*';
				TAB_EASY[x][y]='*';
				virar=0;
				erros++;

				printf ("\n\t\t\t\t  ERROU!");


			}
		atualizartelaeasy(acao);
 	}
}


void jogar_medium (int acao) {
	int i, j, x, y, virar=0, checar=1;
	while (score<4 && acao==1){
		do {
			printf ("\n> Informe as coordenadas (Linha e Coluna) da primeira carta: ");
			scanf ("%d %d", &i, &j);
			if (i<0 || j<0){
				acao=-1;
				break;
			}
			if (i>=LINHAS_MEDIUM || j>=COLUNAS_MEDIUM){
				printf ("Coordenada Invalida!");
				checar=0;
				atualizartelamedium(acao);
			}
				else
					checar=1;
			if (TAB_MEDIUM[i][j]=='*' && checar==1){
				TAB_MEDIUM[i][j]=GAB_MEDIUM[i][j];
				system ("cls");
				tela_jogo_medium(acao);
				virar++;
			}
				else if (checar==1){
						printf ("Esta carta ja foi escolhida!");
						atualizartelamedium(acao);
					}
		} while (virar<1);
		if (acao<0)
			break;
		do {
			printf ("\n> Informe as coordenadas (Linha e Coluna) da segunda carta: ");
			scanf ("%d %d", &x, &y);
			if (x<0 || y<0){
				acao=-1;
				break;
			}
			if (x>=LINHAS_MEDIUM || y>=COLUNAS_MEDIUM){
				printf ("Coordenada Invalida!");
				checar=0;
				atualizartelamedium(acao);
			}
				else
					checar=1;
			if (TAB_MEDIUM[x][y]=='*' && checar==1){
				TAB_MEDIUM[x][y]=GAB_MEDIUM[x][y];
				system ("cls");
				tela_jogo_medium(acao);
				virar++;
			}
				else
					if (checar==1){
						printf ("Carta ja escolhida!");
						atualizartelamedium(acao);
	 				}
		} while (virar<2);
		if (acao<0)
			break;
		if (TAB_MEDIUM[i][j]==TAB_MEDIUM[x][y]){
			virar=0;
			score++;
			printf ("\n\t\t\t\t  ACERTOU!");
		}
			else {
				TAB_MEDIUM[i][j]='*';
				TAB_MEDIUM[x][y]='*';
				virar=0;
				erros++;

				printf ("\n\t\t\t\t  ERROU!");


			}
		atualizartelamedium(acao);
 	}
}


void jogar_hard(int acao) {
	int i, j, x, y, virar=0, checar=1;
	while(score<5 && acao==1){
		do {
			printf("\n> Informe as coordenadas (Linha e Coluna) da primeira carta: ");
			scanf("%d %d", &i, &j);
			if (i<0 || j<0){
				acao=-1;
				break;
			}
			if(i>=LINHAS_HARD || j>=COLUNAS_HARD){
				printf("Coordenada Invalida!");
				checar=0;
				atualizartelahard(acao);
			}
				else
					checar=1;
			if(TAB_HARD[i][j]=='*' && checar==1){
				TAB_HARD[i][j]=GAB_HARD[i][j];
				system ("cls");
				tela_jogo_hard(acao);
				virar++;
			}
				else if(checar==1){
						printf ("Esta carta ja foi escolhida!");
						atualizartelahard(acao);
					}
		} while(virar<1);
	    	if(acao<0)
		   	break;
		do {
			printf("\n> Informe as coordenadas (Linha e Coluna) da segunda carta: ");
			scanf("%d %d", &x, &y);
			if(x<0 || y<0){
				acao=-1;
				break;
			}
			if(x>=LINHAS_HARD || y>=COLUNAS_HARD){
				printf("Coordenada Invalida!");
				checar=0;
				atualizartelahard(acao);
			}
				else
					checar=1;
			if(TAB_HARD[x][y]=='*' && checar==1){
				TAB_HARD[x][y]=GAB_HARD[x][y];
				system ("cls");
				tela_jogo_hard(acao);
				virar++;
			}
				else
					if(checar==1){
						printf("Carta ja escolhida!");
						atualizartelahard(acao);
	 				}
		} while(virar<2);
		if(acao<0)
			break;
		if(TAB_HARD[i][j]==TAB_HARD[x][y]){
			virar=0;
			score++;
			printf("\n\t\t\t\t  ACERTOU!");
		}
			else {
				TAB_HARD[i][j]='*';
				TAB_HARD[x][y]='*';
				virar=0;
				erros++;

				printf("\n\t\t\t\t  ERROU!");


			}
		atualizartelahard(acao);
 	}
}

void jogar_insane(int acao) {
	int i, j, x, y, virar=0, checar=1;
	while (score<10 && acao==1){
		do {
			printf("\n> Informe as coordenadas (Linha e Coluna) da primeira carta: ");
			scanf("%d %d", &i, &j);
			if (i<0 || j<0){
				acao=-1;
				break;
			}
			if(i>=LINHAS_INSANE || j>=COLUNAS_INSANE){
				printf("Coordenada Invalida!");
				checar=0;
				atualizar_tela_insane(acao);
			}
				else
					checar=1;
			if(TAB_INSANE[i][j]=='*' && checar==1){
				TAB_INSANE[i][j]=GAB_INSANE[i][j];
				system ("cls");
				tela_jogo_insane(acao);
				virar++;
			}
				else if(checar==1){
						printf("Esta carta ja foi escolhida!");
						atualizar_tela_insane(acao);
					}
		} while(virar<1);
		if (acao<0)
			break;
		do {
			printf("\n> Informe as coordenadas (Linha e Coluna) da segunda carta: ");
			scanf ("%d %d", &x, &y);
			if(x<0 || y<0){
				acao=-1;
				break;
			}
			if(x>=LINHAS_INSANE || y>=COLUNAS_INSANE){
				printf("Coordenada Invalida!");
				checar=0;
				atualizar_tela_insane(acao);
			}
				else
					checar=1;
			if(TAB_INSANE[x][y]=='*' && checar==1){
				TAB_INSANE[x][y]=GAB_INSANE[x][y];
				system ("cls");
				tela_jogo_insane(acao);
				virar++;
			}
				else
					if(checar==1){
						printf ("Carta ja escolhida!");
						atualizar_tela_insane(acao);
	 				}
		} while(virar<2);
		  if(acao<0)
			break;
		if(TAB_INSANE[i][j]==TAB_INSANE[x][y]){
			virar=0;
			score++;
			printf("\n\t\t\t\t  ACERTOU!");
		}
			else {
				TAB_INSANE[i][j]='*';
				TAB_INSANE[x][y]='*';
				virar=0;
				erros++;

				printf("\n\t\t\t\t  ERROU!");
			}
		atualizar_tela_insane(acao);
 	}
}

void saida_easy() {
    int resultado_easy;
		if(score==0)
		printf("\n\n\tJogo encerrado.\n\n");
		else {
			if(score==3)
				printf("\n\tPARABENS, VOCE ACHOU TODOS OS PARES!");
    resultado_easy=300-(erros*30);
		printf("\n\n\tScore Final: %d\n", resultado_easy);

    if(resultado_easy==300){
			 printf("\t ----------------------------------------------------------- \n");
		   printf("\t|    Perfeito! Voce obteve todos os pontos!                | \n");
			 printf("\t ----------------------------------------------------------- \n");
		 }

    if(resultado_easy>=240&&resultado_easy<299){
			 printf("\t ----------------------------------------------------------- \n");
		   printf("\t|    Exelente! Voce obteve mais de 80%% dos pontos!        | \n");
			 printf("\t ----------------------------------------------------------- \n");
		 }

		if(resultado_easy<239&&resultado_easy>=150){
			printf("\t --------------------------------------------------------------- \n");
			printf("\t| Bom! Voce obteve mais de 50%% dos pontos, mas menos que 80%%! |\n");
			printf("\t --------------------------------------------------------------- \n");
		 }

		if(resultado_easy<149&&resultado_easy>0){
			printf("\t --------------------------------------------------------------- \n");
			printf("\t|     Regular! Voce obteve menos de 50%% dos pontos!            |\n");
			printf("\t --------------------------------------------------------------- \n");

		 }
		if(resultado_easy<0) {
			printf("\t --------------------------------------------------------------- \n");
			printf("\t|     Pessimo! Voce nao obteve nenhum ponto!                    |\n");
			printf("\t --------------------------------------------------------------- \n");
		}
		printf("\n\tVezes que nao acertou o par: %d", erros);
	}
}

void saida_medium() {
    int resultado_medium;
		if(score==0)
		printf("\n\n\tJogo encerrado.\n\n");
		else {
			if(score==4)
			printf("\n\tPARABENS, VOCE ACHOU TODOS OS PARES!");
			resultado_medium = 400-(erros*40);
      printf("\n\n\tScore Final: %d\n", resultado_medium);
			if(resultado_medium==400){
				 printf("\t ----------------------------------------------------------- \n");
				 printf("\t|    Perfeito! Voce obteve todos os pontos!                | \n");
				 printf("\t ----------------------------------------------------------- \n");
			 }

			if(resultado_medium>=320&&resultado_medium<399){
				 printf("\t ----------------------------------------------------------- \n");
				 printf("\t|    Exelente! Voce obteve mais de 80%% dos pontos!        | \n");
				 printf("\t ----------------------------------------------------------- \n");
			 }

			if(resultado_medium<319&&resultado_medium>=200){
				printf("\t --------------------------------------------------------------- \n");
				printf("\t| Bom! Voce obteve mais de 50%% dos pontos, mas menos que 80%%! |\n");
				printf("\t --------------------------------------------------------------- \n");
			 }

			if(resultado_medium<199&&resultado_medium>0){
				printf("\t --------------------------------------------------------------- \n");
				printf("\t|     Regular! Voce obteve menos de 50%% dos pontos!            |\n");
				printf("\t --------------------------------------------------------------- \n");

			 }
			if(resultado_medium<0) {
				printf("\t --------------------------------------------------------------- \n");
				printf("\t|     Pessimo! Voce nao obteve nenhum ponto!                    |\n");
				printf("\t --------------------------------------------------------------- \n");
			}
		  printf("\n\tVezes que nao acertou o par: %d", erros);
}
}

void saida_hard() {
    int resultado_hard;
		if(score==0)
		printf("\n\n\tJogo encerrado.\n\n");
		else {
			if(score==5)
				printf("\n\tPARABENS, VOCE ACHOU TODOS OS PARES!");
        resultado_hard = 500-(erros*50);
	    	printf("\n\n\tScore Final: %d\n", resultado_hard);

				if(resultado_hard==500){
					 printf("\t ----------------------------------------------------------- \n");
				   printf("\t|    Perfeito! Voce obteve todos os pontos!                | \n");
					 printf("\t ----------------------------------------------------------- \n");
				 }

		    if(resultado_hard>=400&&resultado_hard<499){
					 printf("\t ----------------------------------------------------------- \n");
				   printf("\t|    Exelente! Voce obteve mais de 80%% dos pontos!        | \n");
					 printf("\t ----------------------------------------------------------- \n");
				 }

				if(resultado_hard<399&&resultado_hard>=250){
					printf("\t --------------------------------------------------------------- \n");
					printf("\t| Bom! Voce obteve mais de 50%% dos pontos, mas menos que 80%%! |\n");
					printf("\t --------------------------------------------------------------- \n");
				 }

				if(resultado_hard<249&&resultado_hard>0){
					printf("\t --------------------------------------------------------------- \n");
					printf("\t|     Regular! Voce obteve menos de 50%% dos pontos!            |\n");
					printf("\t --------------------------------------------------------------- \n");

				 }
				if(resultado_hard<0) {
					printf("\t --------------------------------------------------------------- \n");
					printf("\t|     Pessimo! Voce nao obteve nenhum ponto!                    |\n");
					printf("\t --------------------------------------------------------------- \n");
				}

				printf("\n\tVezes que nao acertou o par: %d", erros);
	}
}

void saida_insane() {
    int resultado_insane;
		if(score==0)
		printf("\n\n\tJogo encerrado.\n\n");
		else{
			if(score==10)
		printf("\n\tPARABENS, VOCE ACHOU TODOS OS PARES!");
    resultado_insane = 2000-(erros*20);
		printf("\n\n\tScore Final: %d\n", resultado_insane);

		if(resultado_insane==2000){
			 printf("\t ----------------------------------------------------------- \n");
			 printf("\t|    Perfeito! Voce obteve todos os pontos!                | \n");
			 printf("\t ----------------------------------------------------------- \n");
		 }

		if(resultado_insane>=1600&&resultado_insane<1999){
			 printf("\t ----------------------------------------------------------- \n");
			 printf("\t|    Exelente! Voce obteve mais de 80%% dos pontos!        | \n");
			 printf("\t ----------------------------------------------------------- \n");
		 }

		if(resultado_insane<1599&&resultado_insane>=1000){
			printf("\t --------------------------------------------------------------- \n");
			printf("\t| Bom! Voce obteve mais de 50%% dos pontos, mas menos que 80%%! |\n");
			printf("\t --------------------------------------------------------------- \n");
		 }

		if(resultado_insane<999&&resultado_insane>0){
			printf("\t --------------------------------------------------------------- \n");
			printf("\t|     Regular! Voce obteve menos de 50%% dos pontos!            |\n");
			printf("\t --------------------------------------------------------------- \n");

		 }
		if(resultado_insane<0) {
			printf("\t --------------------------------------------------------------- \n");
			printf("\t|     Pessimo! Voce nao obteve nenhum ponto!                    |\n");
			printf("\t --------------------------------------------------------------- \n");
		}

		printf("\n\tVezes que nao acertou o par: %d", erros);
	}
}

int main() {

  int nivel;
	printf("\t\n");
	printf("\t                    | JOGO DA MEMORIA |                      \n");
	printf("\t                                                             \n");
	printf("\t ----------------------------------------------------------- \n");
	printf("\t| INSTRUCOES:                                                |\n");
	printf("\t| O objetivo do jogo eh achar os pares de todas as cartas.   |\n");
	printf("\t| Cada nivel tem suas regras de pontuacao.                   |\n");
	printf("\t| O jogo termina quando o jogador achar todos os pares.      |\n");
	printf("\t|                                                            |\n");
	printf("\t ------------------------------------------------------------\n");
	printf("\t               ESCOLHA QUE NIVEL DESEJA JOGAR                 \n");
  printf("\t\n\t Digite 1 e pressione Enter para jogar o nivel EASY (6 cartas)\n\n\t Digite 2 e pressione Enter para jogar o nivel MEDIUM (8 cartas)\n\n\t Digite 3 e pressione Enter para jogar o nivel HARD (10 cartas)\n\n\t Digite 4 e pressione Enter para jogar o nivel INSANE (20 cartas)\t\n\t");

	do{
		 scanf("%d", &nivel);
		 if(nivel<1||nivel>4) {
		 printf("\tNivel invalido! Tente novamente.\n\t");
	   }
	 } while (nivel<1||nivel>4);

	if(nivel==1)
	   printf("\t Voce escolheu o nivel EASY");
	if(nivel==2)
		 printf("\t Voce escolheu o nivel MEDIUM");
	if(nivel==3)
		 printf("\t Voce escolheu o nivel HARD");
	if(nivel==4)
	 	 printf("\t Voce escolheu o nivel INSANE");

	switch(nivel) {
			case 1:
			inicializacao_easy();
			embaralhar_easy();
			menu();
			tela_jogo_easy(acao);
			jogar_easy(acao);
			saida_easy();
					break;
			case 2:
			inicializacao_medium();
			embaralhar_medium();
			menu();
			tela_jogo_medium(acao);
			jogar_medium(acao);
			saida_medium();
					break;
    	case 3:
			inicializacao_hard();
			embaralhar_hard();
			menu();
			tela_jogo_hard(acao);
			jogar_hard(acao);
			saida_hard();
					break;
			case 4:
			inicializacao_insane();
			embaralhar_insane();
			menu();
			tela_jogo_insane(acao);
			jogar_insane(acao);
			saida_insane();
			    break;
	}

return 0;
}
