#include <stdio.h>
#include <stdlib.h>      // Bliblioteca para usar "abs" (modulo de um numero)
#include <time.h>

// #define NUMERO_DE_TENTATIVAS 5 // DECLARANDO UMA CONSTANTE


int main(){
    printf("\n");
    printf("------------------------------------------\n");
    printf("||Bem vindo ao nosso jogo de adivinhacao||\n");
    printf("------------------------------------------\n");
    printf("\n");

    int segundos = time(0); // Função time(0) importa a quantidade de segundos passos desde 1970
    srand(segundos); // Função srand passo essa quantidade de segundos para função rand() 
    // Assim, sempre será um número aleatório

    int numerogrande = rand();  // Funçãoo rand() gera um numero grande aleatorio  // Ele nÃ£o muda ao iniciar o programa// Para deixar aleatorio e necessario usar as funções time(0) e srand();


    int numeroSecreto = numerogrande%100; // Canculo para gerar um numero entre 0 e 99 
    int chute = 0;
    int tentativas = 1;
    double pontos = 1000;
    int acertou = 0;

    int nivel;
    printf("Qual e o nivel de dificulade?\n");
    printf("(1) Facil  (2) Medio  (3) Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numerodeTentativas = 0;

    switch (nivel)
    {
    case 1:
        numerodeTentativas = 20;
        break;
    case 2: 
        numerodeTentativas = 15;
        break;
    case 3:
        numerodeTentativas = 7;
        break;    
    }
    
    
    for ( int i = 1; i <= numerodeTentativas; i++){
        printf("\n");
        printf("Tentativa %d\n", tentativas);
        printf("Qual e o seu chute? ");
        scanf("%d", &chute);


        if (chute < 0){
            printf("Numero ivalido ** Numero menor que 0\n");
            continue;
        }
        
        acertou = (chute == numeroSecreto);
        
        if (acertou){
            break;

        }else if(chute > numeroSecreto){
            printf("\n");
            printf("O numero secreto e menor\n");
            
        }else if(chute < numeroSecreto){
            printf("\n");
            printf ("O numero secreto e maior\n");
        }

        tentativas++;
        double pontosPerdidos = abs(chute - (double)numeroSecreto)/2;
        pontos = pontos - pontosPerdidos;

    } 
    printf("\n");
    printf("-----------------------\n");
    printf("|     FIM DE JOGO     |\n");
    printf("-----------------------\n");

    if (acertou)
    {
        printf("\n");
        printf("-------------------------------\n");
        printf("|    Parabens! Voce acertou   | \n");
        printf("-------------------------------\n");
        printf("|  O numero secreto era: %d   |\n ", numeroSecreto);
        printf("-------------------------------\n");
        printf("| Voce acertou na tentativa: %d|\n", tentativas);
        printf("-------------------------------\n");
        printf("|    Total de pontos: %.1f    |\n", pontos);
        printf("-------------------------------\n");
    }else{
        printf("--------------------------------\n");
        printf("| Voce perdeu! Tente novamente | \n");
        printf("--------------------------------\n");

    }
    


    
    

    return 0;
}