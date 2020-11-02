#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//definindo tamanho do mapa
#define LARGURA_M 14
#define ALTURA_M 7

struct player{
	char nome[50];
	char user;
	int vida;
	int x;
	int y;
	int pontos;
};

//Menu principal
void menuGame(void){
	printf("--------------------------------\n");
	printf("|Precione w,a,s,d para se mover|\n");
	printf("|Precione 'q' para sair do jogo|\n");
	printf("--------------------------------\n");
	return ;
	}



int main(){
	setlocale(LC_ALL, "Portuguese");//Transformando texto em nosso idioma Brasileiro
	
	//----------Campo das Variaveis-----------
	typedef struct player Player;
	int linha,coluna;
	Player jogador;
	jogador.x =0;
	jogador.y =0;
	jogador.user = '@';
	//----------Fim Campo Variaveis------------
	
	
	//criadno mapa
	char mapa[LARGURA_M][ALTURA_M];
	for(linha =0; linha <= ALTURA_M; linha++){
		for(coluna =0; coluna <= LARGURA_M; coluna++){
			mapa[linha][coluna] ='-';
		}
	}
	
	for(linha =0; linha <= ALTURA_M; linha++){
		for(coluna =0; coluna <= LARGURA_M; coluna++){
			printf("%c", mapa[linha][coluna]);
		}
		printf("\n");
	}
	
	
	
	
	
	return 0;
}
