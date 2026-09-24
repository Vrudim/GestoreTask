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
    if (*nrTask == 0) {
        printf("Lsita Task vuota.\n");
        return;
    }

    int idCercato;
    printf("Inserisci l'ID del task da eliminare: ");
    scanf("%d", &idCercato);

    int indiceTrovato = -1;

    for (int i = 0; i < *nrTask; i++) {
        if (tasks[i].id == idCercato) {
            indiceTrovato = i;
            break;
        }
    }

    if (indiceTrovato == -1) {
        printf("Task con ID %d non trovato.\n\n", idCercato);
        return;
    }

    for (int i = indiceTrovato; i < (*nrTask) - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    (*nrTask)--;
}

void completaTask(Task tasks[], int nrTask){
    if (nrTask == 0) {
        printf("Lsita Task vuota.\n");
        return;
    }
    
    int idCercato;
    printf("Inserisci l'ID del task da segnare come completato: ");
    scanf("%d", &idCercato);

    for (int i = 0; i < nrTask; i++) {
        if (tasks[i].id == idCercato) {
            tasks[i].completata = 1;
            printf("Task [%d] segnato come Completato!\n\n", idCercato);
            return;
        }
    }

    printf("Task con Id %d  non trovato.\n", idCercato);
}

void listaTask(Task tasks[], int nrTask){
    if (nrTask == 0) {
        printf("Nessun task presente.\n\n");
        return;
    }
    printf("-------------------\n");
    for (int i = 0; i < nrTask; i++) {
        printf("[%d] %s - %s\n", tasks[i].id, tasks[i].nome, tasks[i].completata ? "Completato" : "Da Fare");
    }
    printf("-------------------\n\n");
}

void salvaSuFile(Task tasks[], int nrTask) {
    if (nrTask == 0) {
        printf("Lista task vuota");
        return;
    }

    FILE *file = fopen("tasks.txt", "w");
    if (file == NULL) {
        printf("Errore nell'apertura del file per il salvataggio.\n");
        return;
    }

    for (int i = 0; i < nrTask; i++) {
        fprintf(file, "%d|%d|%s\n", tasks[i].id, tasks[i].completata, tasks[i].nome);
    }

    fclose(file);
}

void caricaDaFile(Task tasks[], int *nrTask) {
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        printf("Task file non esistente\n");
        return;
    }

    int contatore = 0;
    while (contatore < MAX_TASKS && fscanf(file, "%d|%d|%[^\n]\n", &tasks[contatore].id, &tasks[contatore].completata, tasks[contatore].nome) == 3) {
        contatore++;
    }

    fclose(file);
    *nrTask = contatore;
    printf("Caricamento completato! Recuperati %d task.\n\n", *nrTask);
}