  //Parte da Nicole

//Atualizar placar 
#include <stdio.h> 
int main()
{   
    while(1){
    printf("Digite um número para ser a coletável: ");
    int coletável = 0;
    int coletável1; 
    
    scanf("%d", &coletável);
    
    coletável1 += coletável;
    printf("Pontos: %d\n", coletável1);
}
    return 0;
}
//modificar para o STM32

//Atualizar recorde (atual)
#include <stdio.h> 

int main()
{  
    int PlacarAtual = 0;
    int Recorde = 0;
    while(1){
    printf("Digite um valor para ser o placar atual: ");
    scanf("%d", &PlacarAtual);
   
	 if (PlacarAtual > Recorde){
	    Recorde = PlacarAtual;
		printf("Recorde: %d\n", Recorde); 
	 } else { 
	     printf("Recorde: %d\n", Recorde);  }
    } 
    return 0;
}

//caso precise (atualização de recorde aintiga)
/*int PlacarAtual = 0;
int PlacarAnterior = 0;
//int Record;
if (PlacarAtual > PlacarAnterior)
	 {
//placar aumenta se a cobrinha pegar um coletável
//mostrar o maior placar aqui
ST7789_WriteString(10, 199, "Pontos: ", PlacarAtual ,Font_16x26, WHITE, BLACK);
//record = record;
	 }
else if (PlacarAtual == PlacarAnterior)
	 {
//placar continua o mesmo se a cobrinha pegar uma mesma quantidade de coletáveis
//mostrar o placar anterior aqui
ST7789_WriteString(10, 199, "Pontos: ", PlacarAtual ,Font_16x26, WHITE, BLACK);
	 }
else
	 {
 //se o placar for menor que o enterior ele mostra o placar anterior assim como no outro caso
//só pra indicar mesmo
ST7789_WriteString(10, 199, "Pontos: ", PlacarAtual ,Font_16x26, WHITE, BLACK);
	 }
	  	  }*/

//direção da cobrinha (so if ur ready...)
//int para os coiso de baixo ali, pra indicar 
int x,y;
int direcao;
//defines para definir o tamanho do coiso da tela do coiso do coiso da coisa da cobrinha pra ela bater a cara e game ove e pá
#define WIDTH 115
#define HEIGHT 100
    //void blablabla{
    switch (direcao) {
    case 1: //cobrinha vai pra cima
    if (y > 0)
        y--;
    else
        gameOver = true;
    break;
    case 2://cobrinha vai para baixo
    if (y < HEIGHT - 1)
        y++;
    else
        gameOver = true;
    break;
    case 3://cobrinha vai para esquerda
    if (x > 0)
        x--;
    else
        gameOver = true; 
    break;
    case 4: //cobrinha vai para direita
    if (x < WIDTH - 1)
        x++;
    else
        gameOver = true; 
    break;
}
//}
