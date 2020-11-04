#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
struct frutas{
	
	int x;
	int y;
	char fruta;
	
};

//Jogador e seus atributos
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
	inicio:
	setlocale(LC_ALL, "Portuguese");//Transformando texto em nosso idioma Brasileiro
	//caompo dos "apelidos" 
	typedef struct frutas Frutas;
	typedef struct player Player;
	srand(time(NULL));
	//----------Campo das Variaveis-----------
	int i,j ;
	char tecla;
	char jogarNovamente;

	//fruta e posição incial fruta
	Frutas fruta;
	fruta.x = rand()%7;
	fruta.y = rand()%14;
	fruta.fruta = 'ó';
	
	//inimigo
	Player inimigo;
	inimigo.x = rand()%7;
	inimigo.y = rand ()%14;
	inimigo.user = 'I';
	inimigo.vida = 3;
	
	// player
	Player jogador;
	jogador.x =0;
	jogador.y =0;
	jogador.user = '@';
	jogador.pontos = 0;
	jogador.vida = 3;
	
	
	//----------Fim Campo Variaveis------------
	char mapa[7][14];
	
	//loop do game
	while(tecla != 'q'){
		
		menuGame();
		
		//GERA O MAPA, INIMIGO E FRUTAS
		for(i = 0; i<7; i++){
			for(j = 0; j<14; j++){
				if(jogador.x == i && jogador.y==j){
					mapa[i][j] = jogador.user;
				}else if(fruta.x == i && fruta.y ==j){//verificação para para colocar a fruta no mapa
					mapa[i][j] = fruta.fruta;
				}else if(inimigo.x == i && inimigo.y ==j){
					mapa[i][j] = inimigo.user;
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
		
		printf("--------------------------------\n");
		printf("|Pontuação:%2d                  |\n", jogador.pontos);
		printf("|Vida Restante:%2d              |\n", jogador.vida);
		printf("|Vida do inimigo Restante:%2d   |\n", inimigo.vida);
		printf("--------------------------------\n");

		
		tecla = getch(); //capturando tecla do usuario para mover o personagem
		
		//fazendo ferificação da tecla para mover o personagem
	
		if(tecla == 'd' || tecla == 'D'){
			jogador.y++;
			if(jogador.y >13){
				jogador.y = 0;
			}
		}else if(tecla == 'a' || tecla == 'A'){
			jogador.y--;
				if(jogador.y <0){
				jogador.y = 13;
			}
		}else if(tecla == 's' || tecla == 'S'){
			jogador.x++;
				if(jogador.x >6){
				jogador.x = 0;
			}
		}else if(tecla == 'w' || tecla == 'W'){
			jogador.x--;
				if(jogador.x <0){
				jogador.x = 6;
			}
			
		}
		
		//verifica se a posição do jogador = fruta e re calcula a posição da fruta
			if(jogador.x == fruta.x && jogador.y == fruta.y){
				inimigo.vida--;
				//verificação se ganhou o game
				if(inimigo.vida ==0){
					system("cls");
					printf("PARABÉNS, VOCÊ GANHOU!\n");
					printf("Quer jogar novamente?\n");
					printf("Digite S ou N:");
					jogarNovamente = getch();
					if(jogarNovamente == 's' || jogarNovamente == 'S'){
						system("cls");
						goto inicio;
					}else{
						return 0;
					}
				}
				
				jogador.pontos++;
				fruta.x = rand()%7;
				fruta.y = rand()%14;
				
				//recalcula a posição do inimigo
				inimigo.x = rand()%7;
				inimigo.y = rand()%14;
				printf("\a"); // o barra invertida a "\a" faz com que o sistema de um bipe, som padrão do sistema
		}
		
		//movimentação inimigo
		if(inimigo.x < jogador.x){
			inimigo.x++;
		}else if(inimigo.x > jogador.x){
			inimigo.x--;
		}
		if(inimigo.y < jogador.y){
			inimigo.y++;
		}else if(inimigo.y > jogador.y){
			inimigo.y--;
		}
		
		//verificação da posição do inimigo com o jogador
		if(inimigo.x == jogador.x && inimigo.y == jogador.y){
			jogador.vida--; //remove 1 de vida do jogador
			
			//recalcula o valor a posição da fruta
			fruta.x = rand()%7;
			fruta.y = rand()%14;
			
			//recalcula a posição do jogador 
			jogador.x = rand()%7;
			jogador.y = rand()%14;
		}
		
		//verifica se fim de game
		if(jogador.vida == 0){
			system("cls");
			printf("Fim de jogo, você perdeu! \n");
			printf("Quer jogar novamente?\n");
			printf("Digite S ou N: ");
			jogarNovamente = getch();
			if(jogarNovamente == 's' || jogarNovamente == 'S'){
				system("cls");
				goto inicio;
			}else{
				return 0;
			}
			
		}
		
		system("cls");// limpa a tela para fazer animação do personagem se movendo
	}
	
	
	
	

	return 0;
}
