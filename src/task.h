#ifndef TASK_H
#define TASK_H
#define MAX_TASKS 25

typedef struct {
	int id;
	char nome[100];
	int completata;
} Task;

void aggiungiTask(Task tasks[], int *nrTask);
void cancellaTask(Task tasks[], int *nrTask);
void completaTask(Task tasks[], int nrTask);
void listaTask(Task tasks[], int nrTask);
void salvaSuFile(Task tasks[], int nrTask);
void caricaDaFile(Task tasks[], int *nrTask);
#endif