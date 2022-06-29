#include <stdio.h>  
#include <string.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <conio.h>
#include <time.h>
#define qtdPiloto 2

	typedef struct {
		int codigo,minutos,segundos,milisegundos;
		char nomeCircuito[120],paisCircuito[120];
		float tamanhoQuilometros;
	}Circuito;
	
	
	typedef struct {
		int dia,mes,ano;
		char nomeEquipe[120];
		int soma;
	}Melhorvolta;
	
	
	typedef struct {
		Circuito circuito;
		Melhorvolta melhorVolta;
		int id,idade;
		char nomePiloto[120],sexo,paisOrigem[120];
		
	}Piloto;
	
	void sortpilotos( Piloto list[qtdPiloto], int s) {
    int i, j;
    Piloto temp;
    for (i = 0; i < s - 1; i++){
        for (j = 0; j < (s - 1-i); j++){

			int sum1 = list[j].circuito.milisegundos + (list[j].circuito.segundos * 1000) +  (list[j].circuito.minutos * 60 * 1000);
			int sum2 = list[j+1].circuito.milisegundos + (list[j+1].circuito.segundos * 1000) +  (list[j+1].circuito.minutos * 60 * 1000);
            if (sum1 < sum2){
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            } 
        }
    }
}
	
	void imprimirPiloto(Piloto p){
		printf("-------------------------------------------------------------------------------------------------\n");
		printf("id: %d\nNome: %s\nIdade: %d\nSexo: %c\nPais de origem: %s\nCodigo: %d\n",p.id,p.nomePiloto,p.idade,p.sexo,p.paisOrigem,p.circuito.codigo);
		printf("Nome da pista: %s\nPais do circuito: %s\nMenor tempo do circuito em min seg mil: %d %d %d\n",p.circuito.nomeCircuito,p.circuito.paisCircuito,p.circuito.minutos,p.circuito.segundos,p.circuito.milisegundos);
		printf("Data da volta DD MM AA: %d/%d/%d\n",p.melhorVolta.dia,p.melhorVolta.mes,p.melhorVolta.ano);
		printf("-------------------------------------------------------------------------------------------------\n");
	}
	
	void imprimirVoltas(Piloto p){
	printf("-------------------------------------------------------------------------------------------------\n");
	printf("Nome do piloto: %s \nMelhor tempo no circuito: %d\n", p.nomePiloto, p.melhorVolta.soma);
	printf("-------------------------------------------------------------------------------------------------\n");
}

void imprimirTempo(Piloto p){
	printf("-------------------------------------------------------------------------------------------------\n");
	printf("Nome do piloto: %s \nMelhor tempo no circuito: %d\nNome da equipe: %s\n", p.nomePiloto, p.melhorVolta.soma, p.melhorVolta.nomeEquipe);
	printf("-------------------------------------------------------------------------------------------------\n");
}
	
	Piloto lerPiloto(){
		Piloto p;
		Piloto piloto;
		printf("ID do piloto:");
		scanf("%d",&p.id);
		fflush(stdin);
	  while(p.id<100 || p.id>500){	
			printf("Digite um numero entre 100 e 500!\n");
			scanf("%d",&p.id);
		    fflush(stdin);	    
    	}
    	printf("Nome:");
    	scanf("%[^\n]s",&p.nomePiloto);
    	fflush(stdin);
    	
    	printf("Idade:");
    	scanf("%d",&p.idade);
    	fflush(stdin);
    	
    	printf("Sexo --> f|m:");
    	scanf("%c",&p.sexo);
    	fflush(stdin);
    	
    	printf("Pais de origem:");
    	scanf("%[^\n]s",&p.paisOrigem);
    	fflush(stdin);
    	
    	printf("Codigo sequencial:");
    	scanf("%d",&p.circuito.codigo);
    	fflush(stdin);
    	
    	printf("Nome da pista:");
    	scanf("%[^\n]s",&p.circuito.nomeCircuito);
    	fflush(stdin);
    	
    	printf("Pais do circuito:");
    	scanf("%[^\n]s",&p.circuito.paisCircuito);
    	fflush(stdin);
    	
    	printf("Menor tempo do circuito em min seg mil:");
    	scanf("%d %d %d",&p.circuito.minutos,&p.circuito.segundos,&p.circuito.milisegundos);
    	fflush(stdin);
    	p.melhorVolta.soma = p.circuito.minutos + p.circuito.segundos + p.circuito.milisegundos;
    	
    	printf("Nome da equipe:");
    	scanf("%[^\n]s",&p.melhorVolta.nomeEquipe);
    	fflush(stdin);
    	
		printf("Data da volta DD MM AA?");
		scanf("%d %d %d", &p.melhorVolta.dia,&p.melhorVolta.mes,&p.melhorVolta.ano);
		fflush(stdin);
		printf("--------------------------\n");
		
		return p;
    	
	}
	
	int main() {
		char opcao,nomeComp[120],circuitoComp[120];
		int i,k,tempoComp,somapilotos=0;
		Piloto pilotos[qtdPiloto];
		
		for(i=0;i<qtdPiloto;i++){
				pilotos[i] = lerPiloto();
				for(k=0;k<=i-1;k++){
						if(pilotos[i].id==pilotos[k].id){
							printf("ID %d ja exite! Cadastre o piloto novamente...\n", pilotos[i].id);
							i-=1;
						}		
					}
				for(k=0;k<=i-1;k++){
					if(pilotos[i].melhorVolta.dia==pilotos[k].melhorVolta.dia){
						printf("Ja ocorreu uma volta no dia %d! Cadastre o piloto novamente com dia diferente...\n", pilotos[i].melhorVolta.dia);
						i-=1;
					}
				}
				
		}
		
		do {
			
			 
			printf("------------------------MENU---------------------------\n");
			printf("A - Ver os cadastros\n");
			printf("B - Pesquisar os pilotos registrados por nome\n");
			printf("C- Ver dados atraves de um  circuito especifico\n");
			printf("D - Pesquisar por tempo de volta no circuito\n");
			printf("E - Encerrar programa\n");
			printf("--------------------------------------------------------\n");
			
			printf("Escolha uma opcao:\n");
			scanf("%c", &opcao);
			fflush(stdin);
			opcao = toupper(opcao);
			system("cls");
					
			
			switch(opcao){
				case 'A':
					for(i=0;i<qtdPiloto;i++){
						imprimirPiloto(pilotos[i]);
						
					}
				break;
				case 'B':
					printf("Ver informacoes de qual piloto?\n");
					scanf("%[^\n]s", nomeComp);
					fflush(stdin);
					for (i = 0; i < qtdPiloto; i++) 
					{
						if (strcmp(nomeComp, pilotos[i].nomePiloto) == 0)
						{
							imprimirPiloto(pilotos[i]);
						}
					}
				break;
				case 'C':
					 	printf("Ver informacoes de qual circuito?\n");
						scanf("%[^\n]s", circuitoComp);
						fflush(stdin);
						for (i = 0; i < qtdPiloto; i++) {
							if (strcmp(circuitoComp, pilotos[i].circuito.nomeCircuito) == 0){
								imprimirVoltas(pilotos[i]);
															
						}
					}
				break;
				case 'D':
					sortpilotos(pilotos, somapilotos);
					printf("Insira o tempo de volta de um circuito: ");
					scanf("%d", &tempoComp);
					fflush(stdin);
					for(i = 0; i <= qtdPiloto; i++)
							if (tempoComp <= pilotos[i].melhorVolta.soma)
						{
							imprimirTempo(pilotos[i]);
						}
				break;
				default:
					printf("opcao invalida!");
			}
		}while(opcao != 'E');
		return 0;
	} 
