#include <stdio.h>

void cadastrarEquipamento() {
    FILE *ficheiro = fopen("equipamentos.txt", "a");
    if (ficheiro == NULL) {
        printf("Erro ao abrir o ficheiro!\n");
        return;
    }

    int codigo;
    char nome[50];
    char localizacao[50];

    printf("\n--- Cadastrar Equipamento ---\n");
    printf("Introduza o codigo de identificacao: ");
    scanf("%d", &codigo);
    getchar();

    printf("Introduza o nome do equipamento: ");
    fgets(nome, sizeof(nome), stdin);
    int i = 0;
    while (nome[i] != '\0') {
        if (nome[i] == '\n') {
            nome[i] = '\0';
            break;
        }
        i++;
    }

    printf("Introduza a localizacao: ");
    fgets(localizacao, sizeof(localizacao), stdin);
    i = 0;
    while (localizacao[i] != '\0') {
        if (localizacao[i] == '\n') {
            localizacao[i] = '\0';
            break;
        }
        i++;
    }

    fprintf(ficheiro, "Codigo: %d | Nome: %s | Localizacao: %s\n", codigo, nome, localizacao);
    
    fclose(ficheiro);
    printf("Equipamento cadastrado com sucesso!\n");
}

void listarEquipamentos() {
    FILE *ficheiro = fopen("equipamentos.txt", "r");
    if (ficheiro == NULL) {
        printf("\nNenhum equipamento cadastrado ainda.\n");
        return;
    }

    printf("\n--- Lista de Equipamentos Cadastrados ---\n");
    char linha[200];
    
    while (fgets(linha, sizeof(linha), ficheiro) != NULL) {
        printf("%s", linha);
    }
    
    fclose(ficheiro);
}

int main() {
    int opcao;

    do {
        printf("\n=== SISTEMA DE CADASTRO DE EQUIPAMENTOS ===\n");
        printf("1. Cadastrar equipamento\n");
        printf("2. Listar equipamentos\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarEquipamento();
                break;
            case 2:
                listarEquipamentos();
                break;
            case 3:
                printf("A encerrar o programa. Ate logo!\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
