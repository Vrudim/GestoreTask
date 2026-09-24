#include <stdio.h>
#include "task.h"

void aggiungiTask(Task tasks[], int *nrTask){
	if(*nrTask >= MAX_TASKS){
		printf("Nr massimo di task raggiunto.\n");
		return;
	}

	tasks[*nrTask].id = *nrTask +1;

	printf("Task: ");
	scanf(" %[^\n]", tasks[*nrTask].nome);

	tasks[*nrTask].completata = 0;

	(*nrTask)++;
}


void cancellaTask(Task tasks[], int *nrTask){

}

void completaTask(Task tasks[], int nrTask){

}

void listaTask(Task tasks[], int nrTask){
    if (nrTask == 0) {
        printf("Nessun task presente.\n\n");
        return;
    }

    printf("-------------------\n");
    for (int i = 0; i < nrTask; i++) {
        printf("[%d] %s - %s\n", tasks[i].id, tasks[i].nome, tasks[i].completata ? "Completato" : "Da Fare");
    printf("-------------------\n\n");
    }
}

void salvaSuFile(Task tasks[], int nrTask){

}

void caricaDaFile(Task tasks[], int *nrTask){

}
