#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

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
	int i,j ;
	Player jogador;
	jogador.x =0;
	jogador.y =0;
	jogador.user = '@';
	char tecla;
	//----------Fim Campo Variaveis------------
	char mapa[7][14];
	
	//loop do game
	while(tecla != 'q'){
		
		menuGame();
		
		//criando mapa
		for(i = 0; i<7; i++){
			for(j = 0; j<14; j++){
				if(jogador.x == i && jogador.y==j){
					mapa[i][j] = jogador.user;
				}else{
					mapa[i][j] = '-';
				}
				
			}
		}
		//mostrando mapa
		for(i = 0; i<7; i++){
			for(j = 0; j<14; j++){
				printf("%c", mapa[i][j]);
			}
			printf("\n");
		}
		
		//capturando tecla do usuario para mover o personagem
		tecla = getch();
		
		if(tecla == 'd' || tecla == 'D'){
			jogador.y++;
		}else if(tecla == 'a' || tecla == 'A'){
			jogador.y--;
		}else if(tecla == 's' || tecla == 'S'){
			jogador.x++;
		}else if(tecla == 'w' || tecla == 'W'){
			jogador.x--;
		}
		
		system("cls");// limpa a tela para fazer animação do personagem se movendo
	}
	
	
	
	

	return 0;
}
