#include <stdio.h>
#include "task.h"

void menu(){
    printf("1) Aggiungi Task\n");
    printf("2) Cancella Task\n");
	printf("3) Completa Task\n");
    printf("4) Lista Task\n");
    printf("5) Salva su File\n");
    printf("6) Carica da File\n");
    printf("0) Esci\n");
}

int main() {
	Task tasks[MAX_TASKS];
	int nrTask =0;
	int scelta = -1;
	
	do{
		menu();
		printf("Scegli Operazione: ");
		scanf("%d", &scelta);
		
		switch(scelta) {
			case 1:
				aggiungiTask(tasks, &nrTask);
				break;
			case 2:
				cancellaTask(tasks, &nrTask);
				break;
			case 3:
				completaTask(tasks, nrTask);
				break;
			case 4:
				listaTask(tasks, nrTask);
				break;
			case 5:
				salvaSuFile(tasks, nrTask);
				break;
			case 6:
				caricaDaFile(tasks, &nrTask);
				break;
			case 0:
				printf("Chiudo Programma!");
				break;
			default:
				printf("Scelta non Valida!");
			
		}
		
	}while(scelta != 0);
	
	return 0;
}
