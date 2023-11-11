#include <stdio.h>
#include <wchar.h>  
typedef struct {
    int prioridade;
    wchar_t categoria[10];
    wchar_t descricao[10];
    wchar_t nome[10];

// colocar para 300 depois
    int status; // mostrar completo, em andamento ou nao iniciado
} Tarefa; 
typedef struct {
    Tarefa tarefas[10];
// colocar 100
    int pos;
    int qtd;
} ListaDeTarefas;



int criarTarefa(ListaDeTarefas *lt);
int deletarTarefa(ListaDeTarefas *lt);
int listarTarefa(ListaDeTarefas lt);
int mudarTarefa(ListaDeTarefas *lt);
int filtrarPorPrioridade(ListaDeTarefas lt);
int filtrarPorStatus(ListaDeTarefas lt);
int filtrarPorCategoria(ListaDeTarefas lt);
int filtrarPorCategoriaEPrioridade(ListaDeTarefas lt);
int downloadPorPrioridade(Tarefa tarefasFiltradas[], int qtdTarefasFiltradas);
int downloadPorCategoria(ListaDeTarefas lt);
int downloadPorCategoria(ListaDeTarefas lt);
int downloadPorCatPri(ListaDeTarefas lt);


void printMenu();
int salvarLista(ListaDeTarefas lt, char nome[]);
int carregarLista(ListaDeTarefas *lt, char nome[]);
