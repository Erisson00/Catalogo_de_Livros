
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Tam 3
#define TamNome 50

typedef struct livros {
    char nome[TamNome];
    float preco;
} livros;

void cadastrarLivros(livros p0[], int qtdlivros);

void ordenarLivrosCrescente(livros p0[], int tamanho);
void ordenarLivrosDecrescente(livros p0[], int tamanho);

void ordenarNomeCrescente(livros p0[], int tamanho);
void ordenarNomeDecrescente(livros p0[], int tamanho);

int main() {
    livros p1[Tam];
    int cont = 0;
    int criterio, ordem;

    // 1. Cadastro dos livros
    while (cont < Tam) {
        cadastrarLivros(p1, cont);
        cont++;
    }

    // 2. Escolha do criterio
    printf("\nComo deseja ordenar os livros?\n");
    printf("1 - Por nome\n");
    printf("2 - Por preco\n");
    printf("Escolha: ");
    scanf("%d", &criterio);
    getchar();

    // 3. Escolha da ordem
    printf("\nQual ordem deseja utilizar?\n");
    printf("1 - Crescente\n");
    printf("2 - Decrescente\n");
    printf("Escolha: ");
    scanf("%d", &ordem);

    // 4. Executa a ordenacao escolhida
    if (criterio == 1) {
        if (ordem == 1) {
            ordenarNomeCrescente(p1, Tam);
        } else if (ordem == 2) {
            ordenarNomeDecrescente(p1, Tam);
        } else {
            printf("Ordem invalida!\n");
            return 1;
        }
    } else if (criterio == 2) {
        if (ordem == 1) {
            ordenarLivrosCrescente(p1, Tam);
        } else if (ordem == 2) {
            ordenarLivrosDecrescente(p1, Tam);
        } else {
            printf("Ordem invalida!\n");
            return 1;
        }
    } else {
        printf("Criterio invalido!\n");
        return 1;
    }

    // 5. Exibe o resultado
    printf("\n--- CATALOGO DE LIVROS ORDENADO ---\n");

    for (int i = 0; i < Tam; i++) {
        printf("Livro: %s | Preco: R$ %.2f\n",
               p1[i].nome, p1[i].preco);
    }

    return 0;
}

void cadastrarLivros(livros p0[], int qtdlivros) {
    printf("\nDigite o nome do livro %d:\n", qtdlivros + 1);

    fgets(p0[qtdlivros].nome, TamNome, stdin);
    p0[qtdlivros].nome[
        strcspn(p0[qtdlivros].nome, "\n")
    ] = '\0';

    printf("Digite o preco:\n");
    scanf("%f", &p0[qtdlivros].preco);

    getchar();
}

// Ordena pelo preco: menor para maior
void ordenarLivrosCrescente(livros p0[], int tamanho) {
    for (int i = 1; i < tamanho; ++i) {
        livros key = p0[i];
        int j = i - 1;

        while (j >= 0 && p0[j].preco > key.preco) {
            p0[j + 1] = p0[j];
            j = j - 1;
        }

        p0[j + 1] = key;
    }
}

// Ordena pelo preco: maior para menor
void ordenarLivrosDecrescente(livros p0[], int tamanho) {
    for (int i = 1; i < tamanho; ++i) {
        livros key = p0[i];
        int j = i - 1;

        while (j >= 0 && p0[j].preco < key.preco) {
            p0[j + 1] = p0[j];
            j = j - 1;
        }

        p0[j + 1] = key;
    }
}

// Ordena pelo nome: A-Z
void ordenarNomeCrescente(livros p0[], int tamanho) {
    for (int i = 1; i < tamanho; ++i) {
        livros key = p0[i];
        int j = i - 1;

        while (j >= 0 &&
               strcmp(p0[j].nome, key.nome) > 0) {
            p0[j + 1] = p0[j];
            j = j - 1;
        }

        p0[j + 1] = key;
    }
}

// Ordena pelo nome: Z-A
void ordenarNomeDecrescente(livros p0[], int tamanho) {
    for (int i = 1; i < tamanho; ++i) {
        livros key = p0[i];
        int j = i - 1;

        while (j >= 0 &&
               strcmp(p0[j].nome, key.nome) < 0) {
            p0[j + 1] = p0[j];
            j = j - 1;
        }

        p0[j + 1] = key;
    }
}
