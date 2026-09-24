#include <stdio.h>
#include "task.h"

void aggiungiTask(Task tasks[], int *nrTask){
	if(*nrTask >= MAX_TASKS){
		printf("Nr massimo di task raggiunto.\n");
		return;
	}

	tasks[*nrTask].id = *nrTask +1;

	printf("Task: ");
	scanf("%[^\n]", tasks[*nrTask].nome);

	(*nrTask)++;
}


void cancellaTask(Task tasks[], int *nrTask){

}

void completaTask(Task tasks[], int nrTask){

}

void listaTask(Task tasks[], int nrTask){

}

void salvaSuFile(Task tasks[], int nrTask){

}

void caricaDaFile(Task tasks[], int *nrTask){

}
