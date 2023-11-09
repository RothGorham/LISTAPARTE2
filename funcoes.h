#include <stdio.h>
#include <wchar.h>  // Add this line

typedef struct {
    int prioridade;
    wchar_t categoria[10];
    wchar_t descricao[10];
    int status; // mostrar completo, em andamento ou nao iniciado
} Tarefa;
// colocar para 300 depois 
typedef struct {
    Tarefa tarefas[100];
    int qtd;
} ListaDeTarefas;

int criarTarefa(ListaDeTarefas *lt);
int deletarTarefa(ListaDeTarefas *lt);
int listarTarefa(ListaDeTarefas lt);

void printMenu();
int salvarLista(ListaDeTarefas lt, char nome[]);
int carregarLista(ListaDeTarefas *lt, char nome[]);
