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
int x,y;
int direcao;

#define WIDTH 115
#define HEIGHT 100
//aqui tem um void {
    switch (direcao) {
        case 1:
            y--;
            break;
        case 2:
            y++;
            break;
        case 3:
            x--;
            break;
        case 4:
            x++;
            break;
    }
    if (x >= WIDTH)
        x = 0;
    else if (x < 0)
        x = WIDTH - 1;
    if (y >= HEIGHT)
        y = 0;
    else if (y < 0)
        y = HEIGHT - 1;

// aqui pode acrescentar algo?

}
