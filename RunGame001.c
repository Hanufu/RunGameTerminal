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

//Função que faz pular linha para formar o mapa
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
	printf("|Pontuação:                    |\n");
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
	int posicao =0; //posição do usuario no mapa
	char tecla; // tecla que o usuario aperta para se mover
	int posicaoInimigo; // posição do inimigo no mapa
	char inimigo = 'o'; // caractere do inimigo no mapa
	//----FIM CAMPO DAS VARIAVEIS----//
	
	
	//Gerador de número aleatorio para a posição do inimigo
	srand(time(NULL));
	posicaoInimigo =rand()%97; //gera numeros de 0 a 97 que é o tamanho do mapa
	
	//INICIO DO LOOP DO GAME
	while(tecla != 'q'){
	
	//MOSTRANDO MENU DO GAME
	menuGame();
		
	//ESTE LAÇO É RESPONSAVEL POR CRIAR O MAPA E A POSIÇÃO DO INIMIGO COM A DO USUARIO TODA VEZ QUE É CHAMADO
		for(i =0; i<tamanhoMapa; i++){
			if( i == posicao){
				mapa[i] = user;
			}else if(i == posicaoInimigo){
				mapa[i] = inimigo;
			}else{
				mapa[i] = '-';
			}
		}
	
		
	
	//ESTE LAÇO É RESPONSAVEL POR MOSTRAR NA TELA O MAPA COM A POSIÇÃO DO INIMIGO E DO USUARIO		
		for(i=0; i <tamanhoMapa; i++){
			printf("%c", mapa[i]);
			pularLinha(i);
		}
		
		rodape();
			
		// CAPTURA A TECLA DO USUARIO SEM QUE ELE APERTE "ENTER"	
		tecla = getch();
		
		//SEQUENCIA DE IF E ELSES 
		/*
		Nesta parte do programa ele verifica a tecla precionada pelo usuario para fazer os devidos calculos de movimentação
		ao apertar "D" ele incrementa mais 1 na posição do personagem
		ao apertar "A" ele decrementa mais 1 na posição do personagem
		ao apertar "W" ele decrementa 14 na posição do personagem que da a impressão que ele foi para linha de cima
		ao apertar "S" ele incrementa 14 na posição do personagem que da a impressão que para linha de baixo
		
		podemos ver que quando um usuario aperta um botão o jogo incrementa primeiro
		e depois verifica se a posição é maior que 97 ou menor que 0 se for ele decrementa o mesmo valor dando a impressão
		de que o usuario não se moveu ou que não pode.  isso acontece para que o caractere do usuario não consiga sair do mapa
		
		e como o mapa é um array de 1 dimesão dividido de forma que pareça que o usuario se mova em 2 porém
		semanticamente ele só se move em 1 dimeção. 1 eixo ou ele vai para direita ou para a esquerda o resto é "maquiagem"
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
		
		//verifica de o o usuario esta na mesma posição que o inimigo se tiver 
		//o inimigo troca de lugar, e da impressão que o usuario matou ele
		if(posicao == posicaoInimigo){
			posicaoInimigo =rand()%97;
			printf("\a"); // o barra invertida a "\a" faz com que o sistema de um bipe, som padrão do sistema
		}
		system("cls");// limpa a tela para fazer animação do personagem se movendo
		
		
		
	}
	//FIM DO LOOP DO GAME
	
	
	// tecla = getch();
	// system("cls");
	
	return 0;	
}
