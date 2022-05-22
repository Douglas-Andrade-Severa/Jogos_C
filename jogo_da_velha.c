#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

//@Douglas Andrade Severa
//Aluno do Curso Análise e Desenvolvimento de Sistemas 2022
//Introdução a programação de computadores
//Exercício JOGO DA VELHA COM MATRIZ
/*Faça um programa para jogar o jogo da velha.
Ao final imprima o resultado do jogo e pergunte se deseja jogar novamente
*/
void tabuleiro (char casas2[3][3]){
	system("cls");
	printf("-----# JOGO DA VELHA #-----\n\n");
	printf("\t %c | %c | %c \n", casas2[0][0], casas2[0][1], casas2[0][2] );
	printf("\t-----------\n");
	printf("\t %c | %c | %c \n", casas2[1][0], casas2[1][1], casas2[1][2] );
	printf("\t-----------\n");
	printf("\t %c | %c | %c \n", casas2[2][0], casas2[2][1], casas2[2][2] );
}
int main(){
	setlocale(LC_ALL, "Portuguese");
	char casas[3][3] = { 
		{'1', '2', '3'},
		{'4', '5', '6'},
		{'7', '8', '9'},
	};
	
	char op;
	int cont_jogadas, lin, col, vez = 0, i , j, contX = 0, contO = 0, contE = 0, contT = 0;
	
	do{
		cont_jogadas = 1;
		for(i = 0; i <= 2; i++){
			for(j = 0; j <= 2; j++){
				casas[i][j] = ' ';
			}
		}
		do{
			tabuleiro(casas);
			
			if(vez % 2 == 0){
				printf("\nJogador X");
			}else{
				printf("\nJogador 0");
			}
			
			printf("\nDigite a linha: ");
			scanf("%d", &lin);
			
			printf("\nDigite a coluna: ");
			scanf("%d", &col);
			
			if((lin < 1) || (col < 1) || (lin > 3) || (col > 3)){
				lin = 0;
				col = 0;
			}else if(casas[lin - 1][col - 1] != ' '){
				lin = 0;
				col = 0;
			}else{
				if(vez % 2 == 0){
					casas[lin - 1][col - 1] = 'X';
				}else{
					casas[lin - 1][col - 1] = 'O';
				}
				vez++;
				cont_jogadas++;
			}
			//condição de vitoria para X
			if(casas[0][0] == 'X' && casas[0][1] == 'X' && casas[0][2] =='X'){cont_jogadas = 11;}
			if(casas[1][0] == 'X' && casas[1][1] == 'X' && casas[1][2] == 'X'){cont_jogadas = 11;}
			if(casas[2][0] == 'X' && casas[2][1] == 'X' && casas[2][2] == 'X'){cont_jogadas = 11;}
			if(casas[0][0] == 'X' && casas[1][0] == 'X' && casas[2][0] == 'X'){cont_jogadas = 11;}
			if(casas[0][1] == 'X' && casas[1][1] == 'X' && casas[2][1] == 'X'){cont_jogadas = 11;}
			if(casas[0][2] == 'X' && casas[1][2] == 'X' && casas[2][2] == 'X'){cont_jogadas = 11;}
			if(casas[0][0] == 'X' && casas[1][1] == 'X' && casas[2][2] == 'X'){cont_jogadas = 11;}
			if(casas[0][2] == 'X' && casas[1][1] == 'X' && casas[2][0] == 'X'){cont_jogadas = 11;}
			
			//condição de vitoria para O
			if(casas[0][0] == 'O' && casas[0][1] == 'O' && casas[0][2] == 'O'){cont_jogadas = 12;}
			if(casas[1][0] == 'O' && casas[1][1] == 'O' && casas[1][2] == 'O'){cont_jogadas = 12;}
			if(casas[2][0] == 'O' && casas[2][1] == 'O' && casas[2][2] == 'O'){cont_jogadas = 12;}
			if(casas[0][0] == 'O' && casas[1][0] == 'O' && casas[2][0] == 'O'){cont_jogadas = 12;}
			if(casas[0][1] == 'O' && casas[1][1] == 'O' && casas[2][1] == 'O'){cont_jogadas = 12;}
			if(casas[0][2] == 'O' && casas[1][2] == 'O' && casas[2][2] == 'O'){cont_jogadas = 12;}
			if(casas[0][0] == 'O' && casas[1][1] == 'O' && casas[2][2] == 'O'){cont_jogadas = 12;}
			if(casas[0][2] == 'O' && casas[1][1] == 'O' && casas[2][0] == 'O'){cont_jogadas = 12;}
			
		}while(cont_jogadas <= 9);
		tabuleiro(casas);
		if(cont_jogadas == 10){
			printf("\nJogo empatado ;D");
			contE = contE + 1;
			printf("\nTotal de empates: %d", contE);
		}if(cont_jogadas == 11){
			printf("\nVencedor!! Jogador X");
			contX = contX + 1;
			printf("\nTotal de vitórias jogador X: %d", contX);
		}if(cont_jogadas == 12){
			printf("\nVencedor!! Jogador O");
			contO = contO + 1;
			printf("\nTotal de vitórias jogador O: %d", contO);
		}
		printf("\nDESEJA JOGAR NOVAMENTE? [S - N]\n");
		scanf("%s", &op);
	}while(op == 's');
	
	system("cls");
	printf("\n-----# JOGO DA VELHA #-----");
	printf("\n----# RESULTADO FINAL #----");
	if(contX == contO){
		printf("\n\n!!! NÃO HOUVE VENCENDOR !!!\n");
	}if(contX > contO){
		printf("\n\n!!! VENCEDOR JOGADOR X !!!\n");
	}if(contO > contX){
		printf("\n\n!!! VENCEDOR JOGADOR O !!!\n");
	}
	printf("\nTOTAL DE EMPATES: %d", contE);
	printf("\nTOTAL DE VITÓRIAS JOGADOR X: %d", contX);
	printf("\nTOTAL DE VITÓRIAS JOGADOR O: %d", contO);
}
