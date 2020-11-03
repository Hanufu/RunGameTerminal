#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
struct frutas{
	
	int x;
	int y;
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
	setlocale(LC_ALL, "Portuguese");//Transformando texto em nosso idioma Brasileiro
	//caompo dos "apelidos" 
	typedef struct frutas Frutas;
	typedef struct player Player;
	srand(time(NULL));
	//----------Campo das Variaveis-----------
	int i,j ;
	char tecla;

	//fruta
	Frutas fruta;
	fruta.x = rand()%7;
	fruta.y = rand()%14;
	
	// player
	Player jogador;
	jogador.x =0;
	jogador.y =0;
	jogador.user = '@';
	
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
				}else if(fruta.x == i && fruta.y ==j){
					mapa[i][j] = '�';
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
		
		tecla = getch(); //capturando tecla do usuario para mover o personagem
		
		//fazendo ferifica��o da tecla para mover o personagem
		if(tecla == 'd' || tecla == 'D'){
			jogador.y++;
			if(jogador.y >=14){
				jogador.y--;
			}
		}else if(tecla == 'a' || tecla == 'A'){
			jogador.y--;
				if(jogador.y <=0){
				jogador.y++;
			}
		}else if(tecla == 's' || tecla == 'S'){
			jogador.x++;
				if(jogador.x >=7){
				jogador.x--;
			}
		}else if(tecla == 'w' || tecla == 'W'){
			jogador.x--;
				if(jogador.x <=0){
				jogador.x++;
			}
			
		}
		
		system("cls");// limpa a tela para fazer anima��o do personagem se movendo
	}
	
	
	
	

	return 0;
}
