#include <stdio.h>
#include <string.h>
#include <locale.h>
//Menu principal
void menuGame(void){
	printf("--------------------------------\n");
	printf("|Precione w,a,s,d para se mover|\n");
	printf("|Precione 'q' para sair do jogo|\n");
	printf("--------------------------------\n");
	return ;
	}

//Fun��o que faz pular linha para formar o mapa
void pularLinha(int i){
	if(i == (14*1)-1){
		printf("\n");
	}else if( i == (14*2)-1){
		printf("\n");
	}else if( i == (14*3)-1){
		printf("\n");
	}else if( i == (14*4)-1){
		printf("\n");
	}else if( i == (14*5)-1){
		printf("\n");
	}else if( i == (14*6)-1){
		printf("\n");
	}else if( i == (14*7)-1){
		printf("\n");
	}
 	return;
}

//Rodape
int rodape(void){
	printf("--------------------------------\n");
	printf("|Pontua��o:                    |\n");
	printf("|Vida Restante:                |\n");
	printf("--------------------------------\n");
	return ;
	}

//INICIO DO PROGRAMA
int main(){
	setlocale(LC_ALL, "Portuguese");//Transformando texto em nosso idioma Brasileiro
	
	//----CAMPO DAS VARIAVEIS----//
	int tamanhoMapa = 14*7; //tamanho do mapa
	char mapa[tamanhoMapa]; // "o mapa"
	int i,j; // variaveis auxiliares
	char user ='@'; //caractere do usuario
	int posicao =0; //posi��o do usuario no mapa
	char tecla; // tecla que o usuario aperta para se mover
	int posicaoInimigo; // posi��o do inimigo no mapa
	char inimigo = 'o'; // caractere do inimigo no mapa
	//----FIM CAMPO DAS VARIAVEIS----//
	
	
	//Gerador de n�mero aleatorio para a posi��o do inimigo
	srand(time(NULL));
	posicaoInimigo =rand()%97; //gera numeros de 0 a 97 que � o tamanho do mapa
	
	//INICIO DO LOOP DO GAME
	while(tecla != 'q'){
	
	//MOSTRANDO MENU DO GAME
	menuGame();
		
	//ESTE LA�O � RESPONSAVEL POR CRIAR O MAPA E A POSI��O DO INIMIGO COM A DO USUARIO TODA VEZ QUE � CHAMADO
		for(i =0; i<tamanhoMapa; i++){
			if( i == posicao){
				mapa[i] = user;
			}else if(i == posicaoInimigo){
				mapa[i] = inimigo;
			}else{
				mapa[i] = '-';
			}
		}
	
		
	
	//ESTE LA�O � RESPONSAVEL POR MOSTRAR NA TELA O MAPA COM A POSI��O DO INIMIGO E DO USUARIO		
		for(i=0; i <tamanhoMapa; i++){
			printf("%c", mapa[i]);
			pularLinha(i);
		}
		
		rodape();
			
		// CAPTURA A TECLA DO USUARIO SEM QUE ELE APERTE "ENTER"	
		tecla = getch();
		
		//SEQUENCIA DE IF E ELSES 
		/*
		Nesta parte do programa ele verifica a tecla precionada pelo usuario para fazer os devidos calculos de movimenta��o
		ao apertar "D" ele incrementa mais 1 na posi��o do personagem
		ao apertar "A" ele decrementa mais 1 na posi��o do personagem
		ao apertar "W" ele decrementa 14 na posi��o do personagem que da a impress�o que ele foi para linha de cima
		ao apertar "S" ele incrementa 14 na posi��o do personagem que da a impress�o que para linha de baixo
		
		podemos ver que quando um usuario aperta um bot�o o jogo incrementa primeiro
		e depois verifica se a posi��o � maior que 97 ou menor que 0 se for ele decrementa o mesmo valor dando a impress�o
		de que o usuario n�o se moveu ou que n�o pode.  isso acontece para que o caractere do usuario n�o consiga sair do mapa
		
		e como o mapa � um array de 1 dimes�o dividido de forma que pare�a que o usuario se mova em 2 por�m
		semanticamente ele s� se move em 1 dime��o. 1 eixo ou ele vai para direita ou para a esquerda o resto � "maquiagem"
		*/
		if(tecla == 'd' || tecla == 'D'){
			posicao++;
			if(posicao > 97){
				posicao--;
			}
		}else if(tecla == 'a' || tecla == 'A'){
			posicao--;
			if(posicao < 0){
				posicao++;	
			}
			
		}else if(tecla == 's' || tecla == 'S'){
			posicao += 14;
			if(posicao > 97){
				posicao -= 14;
			}
		}else if(tecla == 'w' || tecla == 'W'){
			posicao -=14;
			if(posicao < 0){
				posicao += 14;	
			}
		}
		
		//verifica de o o usuario esta na mesma posi��o que o inimigo se tiver 
		//o inimigo troca de lugar, e da impress�o que o usuario matou ele
		if(posicao == posicaoInimigo){
			posicaoInimigo =rand()%97;
			printf("\a"); // o barra invertida a "\a" faz com que o sistema de um bipe, som padr�o do sistema
		}
		system("cls");// limpa a tela para fazer anima��o do personagem se movendo
		
		
		
	}
	//FIM DO LOOP DO GAME
	
	
	// tecla = getch();
	// system("cls");
	
	return 0;	
}
