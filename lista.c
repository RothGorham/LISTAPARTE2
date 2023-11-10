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


int filtrarPorPrioridade(ListaDeTarefas lt) {
    int prioridade;

    // Opção para filtrar tarefas por prioridade
    printf("Digite a prioridade desejada (de 1 a 10): ");
    scanf("%d", &prioridade);

    printf("\nLista de tarefas com prioridade %d\n", prioridade);

    int encontrouPrioridade = 0; // Variável para verificar se encontrou alguma tarefa com a prioridade escolhida

    // Loop para percorrer todas as tarefas
    for (int i = 0; i < lt.qtd; i++) {
        // Verifica se a tarefa tem a prioridade escolhida
        if (lt.tarefas[i].prioridade == prioridade) {
            encontrouPrioridade = 1; // Marca que encontrou uma tarefa com a prioridade escolhida
            // Imprime os detalhes da tarefa
            printf("Tarefa %d\n", i + 1);
            printf("Nome: %s\n", lt.tarefas[i].nome);
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
            printf("Descrição: %s\n", lt.tarefas[i].descricao);
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
            printf("Status: %d\n", lt.tarefas[i].status);
            printf("\n");
        }
    }

    // Verifica se não encontrou nenhuma tarefa com a prioridade escolhida
    if (!encontrouPrioridade) {
        printf("Nenhuma tarefa encontrada com a prioridade %d.\n", prioridade);
    }

    return 0; // Retorna 0 indicando que a função executou corretamente
}

int filtrarPorStatus(ListaDeTarefas lt) {
    int Status;

    // Opção para filtrar tarefas por Status
    printf("Digite o Status desejado (1 para completo, 2 para em andamento, 3 para não iniciado): ");
    scanf("%d", &Status);

    printf("\nLista de tarefas com Status %d\n", Status);

    int encontrouStatus = 0; // Variável para verificar se encontrou alguma tarefa com o estado escolhido

    // Loop para percorrer todas as tarefas
    for (int i = 0; i < lt.qtd; i++) {
        // Verifica se a tarefa tem o estado escolhido
        if (lt.tarefas[i].status == Status) {
            encontrouStatus = 1; // Marca que encontrou uma tarefa com o estado escolhido
            // Imprime os detalhes da tarefa
            printf("Tarefa %d\n", i + 1);
            printf("Nome: %s\n", lt.tarefas[i].nome);
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
            printf("Descrição: %s\n", lt.tarefas[i].descricao);
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
            printf("Status: %d\n", lt.tarefas[i].status);
            printf("\n");
        }
    }

    // Verifica se não encontrou nenhuma tarefa com o estado escolhido
    if (!encontrouStatus) {
        printf("Nenhuma tarefa encontrada com o Status %d.\n", Status);
    }

    return 0; // Retorna 0 indicando que a função executou corretamente
}

// Função para imprimir todas as categorias com números e retornar a escolha do usuário
int imprimirCategoriasNumeradas(ListaDeTarefas lt) {
    printf("Categorias disponíveis:\n");
    for (int i = 0; i < lt.qtd; i++) {
        printf("%d - %s\n", i + 1, lt.tarefas[i].categoria);
    }

    int escolha;
    printf("Escolha o número correspondente à Categoria desejada: ");
    scanf("%d", &escolha);

    // Verifica se a escolha do usuário é válida
    if (escolha < 1 || escolha > lt.qtd) {
        printf("Escolha inválida.\n");
        return -1; // Retorna -1 indicando que houve um erro
    }

    return escolha;
}


// Função para filtrar tarefas por categoria
int filtrarPorCategoria(ListaDeTarefas lt) {
    // Imprime as categorias e recebe a escolha do usuário
    int escolha = imprimirCategoriasNumeradas(lt);

    // Verifica se houve um erro na escolha da categoria
    if (escolha == -1) {
        return 1; // Retorna 1 indicando que houve um erro
    }

    // Cria uma variável para armazenar a categoria escolhida
    char categoriaEscolhida[50];
    // Copia a categoria escolhida para a variável
    strcpy(categoriaEscolhida, lt.tarefas[escolha - 1].categoria);

    // Cria um array para armazenar as tarefas filtradas
    Tarefa tarefasFiltradas[100];
    // Cria uma variável para contar a quantidade de tarefas filtradas
    int qtdTarefasFiltradas = 0;

    // Loop para percorrer todas as tarefas
    for (int i = 0; i < lt.qtd; i++) {
        // Verifica se a tarefa tem a categoria escolhida
        if (strcmp(lt.tarefas[i].categoria, categoriaEscolhida) == 0) {
            // Adiciona a tarefa ao array de tarefas filtradas
            tarefasFiltradas[qtdTarefasFiltradas++] = lt.tarefas[i];
        }
    }

    // Loop para ordenar as tarefas filtradas por prioridade (maior para menor)
    for (int i = 0; i < qtdTarefasFiltradas - 1; i++) {
        for (int j = 0; j < qtdTarefasFiltradas - i - 1; j++) {
            // Verifica se a prioridade da tarefa atual é menor que a da próxima
            if (tarefasFiltradas[j].prioridade < tarefasFiltradas[j + 1].prioridade) {
                // Troca as tarefas se estiverem fora de ordem
                Tarefa temp = tarefasFiltradas[j];
                tarefasFiltradas[j] = tarefasFiltradas[j + 1];
                tarefasFiltradas[j + 1] = temp;
            }
        }
    }

    printf("\nLista de tarefas na Categoria %s\n", categoriaEscolhida);

    // Loop para imprimir as tarefas ordenadas
    for (int i = 0; i < qtdTarefasFiltradas; i++) {
        printf("Tarefa %d\n", i + 1);
        printf("Nome: %s\n", tarefasFiltradas[i].nome);
        printf("Categoria: %s\n", tarefasFiltradas[i].categoria);
        printf("Descrição: %s\n", tarefasFiltradas[i].descricao);
        printf("Prioridade: %d\n", tarefasFiltradas[i].prioridade);
        printf("Status: %d\n", tarefasFiltradas[i].status);
        printf("\n");
    }

    // Verifica se não encontrou nenhuma tarefa na categoria escolhida
    if (qtdTarefasFiltradas == 0) {
        printf("Nenhuma tarefa encontrada na Categoria %s.\n", categoriaEscolhida);
    }

    return 0; // Retorna 0 indicando que a função executou corretamente
}

// Função para filtrar tarefas por categoria e prioridade
int catepri(ListaDeTarefas lt) {
    // Imprime as categorias e recebe a escolha do usuário
    int escolhaCategoria = imprimirCategoriasNumeradas(lt);

    // Verifica se houve um erro na escolha da categoria
    if (escolhaCategoria == -1) {
        return 1; // Retorna 1 indicando que houve um erro
    }

    // Cria uma variável para armazenar a categoria escolhida
    char categoriaEscolhida[50];
    // Copia a categoria escolhida para a variável
    strcpy(categoriaEscolhida, lt.tarefas[escolhaCategoria - 1].categoria);

    // Opção para filtrar tarefas por prioridade
    int prioridade;
    printf("Digite a prioridade desejada (de 1 a 10): ");
    scanf("%d", &prioridade); // Recebe a prioridade desejada do usuário

    printf("\nLista de tarefas na Categoria %s com prioridade %d\n", categoriaEscolhida, prioridade);

    int encontrouTarefa = 0; // Variável para verificar se encontrou alguma tarefa que atenda aos critérios

    // Loop para percorrer todas as tarefas
    for (int i = 0; i < lt.qtd; i++) {
        // Verifica se a tarefa tem a categoria e prioridade escolhidas
        if (strcmp(lt.tarefas[i].categoria, categoriaEscolhida) == 0 && lt.tarefas[i].prioridade == prioridade) {
            encontrouTarefa = 1; // Marca que encontrou uma tarefa que atende aos critérios
            // Imprime os detalhes da tarefa
            printf("Tarefa %d\n", i + 1);
            printf("Nome: %s\n", lt.tarefas[i].nome);
            printf("Categoria: %s\n", lt.tarefas[i].categoria);
            printf("Descrição: %s\n", lt.tarefas[i].descricao);
            printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
            printf("Status: %d\n", lt.tarefas[i].status);
            printf("\n");
        }
    }

    // Verifica se não encontrou nenhuma tarefa que atenda aos critérios
    if (!encontrouTarefa) {
        printf("Nenhuma tarefa encontrada na Categoria %s com prioridade %d.\n", categoriaEscolhida, prioridade);
    }

    return 0; // Retorna 0 indicando que a função executou corretamente
}


// Função principal para listar tarefas
int listarTarefa(ListaDeTarefas lt) {
    int opcao;

    // Imprime as opções
    printf("Menu Listar Tarefas\n");
    printf("1 - Mostrar todas as tarefas\n");
    printf("2 - Filtrar tarefas por prioridade\n");
    printf("3 - Filtrar tarefas por Status\n");
    printf("4 - Filtrar tarefas por categoria\n");
    printf("5 - Filtrar tarefas por categoria e prioridade\n");
    printf("Digite a opção desejada: ");

    // Lê a opção escolhida pelo usuário
    scanf("%d", &opcao);
    printf("\n");

    // Verifica a opção escolhida pelo usuário
    switch (opcao) {
        case 1:
            // Opção para mostrar todas as tarefas
            printf("Lista de todas as tarefas\n");
            for (int i = 0; i < lt.qtd; i++) {
                // Imprime os detalhes da tarefa
                printf("Tarefa %d\n", i + 1);
                printf("Nome: %s\n", lt.tarefas[i].nome);
                printf("Categoria: %s\n", lt.tarefas[i].categoria);
                printf("Descrição: %s\n", lt.tarefas[i].descricao);
                printf("Prioridade: %d\n", lt.tarefas[i].prioridade);
                printf("Status: %d\n", lt.tarefas[i].status);
                printf("\n");
            }
            break;

        case 2:
            // Chama a função para filtrar por prioridade
            filtrarPorPrioridade(lt);
            break;

        case 3:
            // Chama a função para filtrar por status
            filtrarPorStatus(lt);
            break;

        case 4:
            // Chama a função para filtrar por categoria
            filtrarPorCategoria(lt);
            break;
      
        case 5:
            catepri(lt);
      
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
