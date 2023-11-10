#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int mudarTarefa(ListaDeTarefas *lt) {
    // Verifica se a lista de tarefas está vazia
    if (lt->qtd <= 0) {
        printf("Lista de tarefas vazia.\n");
        return 1;
    }

    printf("Mudar tarefa\nDigite a posição da tarefa (1 a 100):");
    int pos;
    printf("Digite a posição da tarefa (1 a 100): ");
    scanf("%d", &pos);
    pos--;

    // Verifica se a posição é válida
    if (pos < 0 || pos >= lt->qtd) {
        printf("Posição inválida.\n");
        return 1;
    }

    int opcao;
    printf("Escolha o campo a ser alterado:\n");
    printf("1 - Nome\n");
    printf("2 - Categoria\n");
    printf("3 - Descrição\n");
    printf("4 - Prioridade\n");
    printf("5 - Status\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);

    // buffer
    while (getchar() != '\n');

    // menu para o escolher as opcoes
    switch (opcao) {
        case 1:
            printf("Digite o novo nome da tarefa: ");
            fgets(lt->tarefas[pos].nome, sizeof(lt->tarefas[pos].nome), stdin);
            break;
        case 2:
            printf("Digite a nova categoria da tarefa: ");
            fgets(lt->tarefas[pos].categoria, sizeof(lt->tarefas[pos].categoria), stdin);
            break;
        case 3:
            printf("Digite a nova descrição da tarefa: ");
            fgets(lt->tarefas[pos].descricao, sizeof(lt->tarefas[pos].descricao), stdin);
            break;
      case 4:
          printf("Digite a nova prioridade da tarefa (de 1 a 10): ");
          scanf("%d", &lt->tarefas[pos].prioridade);
          break;
      case 5:
          printf("Digite o novo status da tarefa (1 para completo, 2 para em andamento, 3 para não iniciado): ");
          scanf("%d", &lt->tarefas[pos].status);
          break;
        default:
            printf("Opção inválida.\n");
            return 1;
    }

    return 0;
}




int criarTarefa(ListaDeTarefas *lt) {
    if (lt->qtd < 100) {
        printf("Criar tarefa:\n");

        // Limpando o buffer do teclado antes de ler a categoria
        while (getchar() != '\n');

        printf("Digite o nome da tarefa (até 100 caracteres): ");
        fgets(lt->tarefas[lt->qtd].nome, sizeof(lt->tarefas[lt->qtd].nome), stdin);

        // Remover a quebra de linha do nome da tarefa (se existir)
        size_t nome_len = strlen(lt->tarefas[lt->qtd].nome);
        if (lt->tarefas[lt->qtd].nome[nome_len - 1] == '\n') {
            lt->tarefas[lt->qtd].nome[nome_len - 1] = '\0';
        }

        printf("Digite a categoria (até 100 caracteres): ");
        fgets(lt->tarefas[lt->qtd].categoria, sizeof(lt->tarefas[lt->qtd].categoria), stdin);

        // Remover a quebra de linha da categoria (se existir)
        size_t categoria_len = strlen(lt->tarefas[lt->qtd].categoria);
        if (lt->tarefas[lt->qtd].categoria[categoria_len - 1] == '\n') {
            lt->tarefas[lt->qtd].categoria[categoria_len - 1] = '\0';
        }

        // Limpando o buffer do teclado antes de ler a descrição
        while (getchar() != '\n');

        printf("Digite a descrição (até 300 caracteres): ");
        fgets(lt->tarefas[lt->qtd].descricao, sizeof(lt->tarefas[lt->qtd].descricao), stdin);

        // Remover a quebra de linha da descrição (se existir)
        size_t descricao_len = strlen(lt->tarefas[lt->qtd].descricao);
        if (lt->tarefas[lt->qtd].descricao[descricao_len - 1] == '\n') {
            lt->tarefas[lt->qtd].descricao[descricao_len - 1] = '\0';
        }

        printf("Digite a prioridade (de 1 a 10): ");
        scanf("%d", &lt->tarefas[lt->qtd].prioridade);

        // Limpando o buffer do teclado antes de ler o status
        while (getchar() != '\n');

        printf("Digite o status (1 para completo, 2 para em andamento, 3 para não iniciado): ");
        scanf("%d", &lt->tarefas[lt->qtd].status);

        lt->qtd++;
        return 0;
    } else {
        printf("Lista de tarefas está cheia.\n");
        return 1;
    }
}

// Deleta uma tarefa da lista
int deletarTarefa(ListaDeTarefas *lt) {
    if (lt->qtd > 0) {
        printf("Deletar tarefa:\n");
        int pos;

        wprintf(L"Digite a posição da tarefa (1 a 100): ");
        scanf("%d", &pos);
        pos--;

        if (pos >= 0 && pos < lt->qtd) {
            for (int i = pos; i < lt->qtd - 1; i++) {
                lt->tarefas[i] = lt->tarefas[i + 1];
            }

            lt->qtd--;
            return 0;
        } else {
            wprintf(L"Posição invalida.\n");
            return 1;
        }
    } else {
        printf("Lista de tarefas vazia.\n");
        return 1;
    }
}

// lista as tarefas
int listarTarefa(ListaDeTarefas lt) {
  int opcao; 
  int prioridade;
    // Imprime as opções
    printf("Menu Listar Tarefas\n");
    printf("1 - Mostrar todas as tarefas\n");
    printf("2 - Filtrar tarefas por prioridade\n");
    printf("Digite a opção desejada: ");

    // Lê a opção escolhida pelo usuário
    scanf("%d", &opcao);
    printf("\n");

    // Verifica a opção escolhida pelo usuário
    switch (opcao) {
        case 1:
            // Opção para mostrar todas as tarefas
            printf("Lista de todas as tarefas\n");
            break;
        case 2:
            // Opção para filtrar tarefas por prioridade
            printf("Digite a prioridade desejada (de 1 a 10): ");
            scanf("%d", &prioridade);

            printf("\nLista de tarefas com prioridade %d\n", prioridade);

            int encontrou = 0; // Variável para verificar se encontrou alguma tarefa com a prioridade escolhida

            // Loop para percorrer todas as tarefas
            for (int i = 0; i < lt.qtd; i++) {
                // Verifica se a tarefa tem a prioridade escolhida
                if (lt.tarefas[i].prioridade == prioridade) {
                    encontrou = 1; // Marca que encontrou uma tarefa com a prioridade escolhida
                    // Imprime os detalhes da tarefa
                    printf("Tarefa %d\n", i + 1);
                    printf("Nome: %s\n", lt.tarefas[i].nome);
                    printf("Categoria: %s\n", lt.tarefas[i].categoria);
                    printf("Descrição: %s\n", lt.tarefas[i].descricao);
                    printf("Status: %d\n", lt.tarefas[i].status);
                    printf("\n");
                }
            }

            // Verifica se não encontrou nenhuma tarefa com a prioridade escolhida
            if (!encontrou) {
                printf("Nenhuma tarefa encontrada com a prioridade %d.\n", prioridade);
            }

            return 0; // Retorna 0 indicando que a função executou corretamente
        default:
            // Opção inválida
            printf("Opção inválida.\n");
            return 1; // Retorna 1 indicando que houve um erro
    }

    // Imprime a quantidade de tarefas
    printf("Quantidade de tarefas: %d\n", lt.qtd);
    printf("\n");

    // Verifica se a lista de tarefas está vazia
    if (lt.qtd == 0) {
        printf("A lista de tarefas está vazia.\n");
    } else {
        // Loop para percorrer todas as tarefas
        for (int i = 0; i < lt.qtd; i++) {
            // Imprime os detalhes da tarefa
            printf("Tarefa %d\n", i + 1);
            printf("Nome: %s\n", lt.tarefas[i].nome);
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
            printf("Descrição: %s\n", lt.tarefas[i].descricao);
            printf("Status: %d\n", lt.tarefas[i].status);
            printf("\n");
        }
    }

    return 0; // Retorna 0 indicando que a função executou corretamente
}




// Mostra o menu
void printMenu() {
    printf("Menu\n");
    printf("1 - Criar tarefa\n");
    printf("2 - Deletar tarefa\n");
    printf("3 - Listar tarefas\n");
    printf("4 - Mudar tarefa\n");  
    printf("0 - Sair\n");
    printf("Digite a opção desejada: ");  
}


// Salva a lista de tarefas em um arquivo
// fwrite
int salvarLista(ListaDeTarefas lt, char nome[]) {
    FILE *arquivo;
    arquivo = fopen(nome, "wb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    for (int i = 0; i < lt.qtd; i++) {
        fwrite(&lt.tarefas[i], sizeof(Tarefa), 1, arquivo);
    }

    fclose(arquivo);
    return 0;
}

// Carrega a lista de tarefas de um arquivo
// fread
int carregarLista(ListaDeTarefas *lt, char nome[]) {
    FILE *arquivo;
    arquivo = fopen(nome, "rb");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    lt->qtd = 0; // Inicialize o contador de tarefas carregadas

    while (fread(&lt->tarefas[lt->qtd], sizeof(Tarefa), 1, arquivo) == 1) {
        lt->qtd++;
    }

    fclose(arquivo);
    return 0;
}
