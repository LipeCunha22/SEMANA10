#include <stdio.h>

#define MAX_SIZE 100

// Funções do Lab da semana anterior

int count(int arr[], int size, int num) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == num)
            count++;
    }
    return count;
}

int index(int arr[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num)
            return i;
    }
    return -1; // Se não encontrado
}

void reverse(int arr[], int size) {
    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

void sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Novas funções

void append(int arr[], int *size, int num) {
    if (*size < MAX_SIZE) {
        arr[*size] = num;
        (*size)++;
    } else {
        printf("Erro: Não é possível anexar, lista cheia.\n");
    }
}

void insert(int arr[], int *size, int index, int num) {
    if (*size < MAX_SIZE && index >= 0 && index <= *size) {
        for (int i = *size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = num;
        (*size)++;
    } else {
        printf("Erro: Não é possível inserir nesse índice.\n");
    }
}

int pop(int arr[], int *size) {
    if (*size > 0) {
        int popped = arr[*size - 1];
        (*size)--;
        return popped;
    } else {
        printf("Erro: Lista vazia, não é possível fazer pop.\n");
        return -1;
    }
}

void remove_element(int arr[], int *size, int num) {
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (arr[i] == num) {
            for (int j = i; j < *size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            (*size)--;
            found = 1;
            i--; // Para verificar novamente na posição atual, pois os elementos foram deslocados
        }
    }
    if (!found) {
        printf("Erro: Elemento não encontrado, não é possível remover.\n");
    }
}

// Função Calculadora

void Calculadora(int *a, int *b, char op, int *resultado) {
    switch (op) {
        case '+':
            *resultado = *a + *b;
            break;
        case '-':
            *resultado = *a - *b;
            break;
        case '*':
            *resultado = *a * *b;
            break;
        case '/':
            if (*b != 0)
                *resultado = *a / *b;
            else
                printf("Erro: Divisão por zero.\n");
            break;
        default:
            printf("Erro: Operação inválida.\n");
    }
}

int main() {
    int lista[MAX_SIZE] = {5, 3, 7};
    int tamanho = 3;

    printf("Count of 3: %d\n", count(lista, tamanho, 3));
    printf("Index of 7: %d\n", index(lista, tamanho, 7));

    append(lista, &tamanho, 2);
    printf("Lista com inserção: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");

    int popped = pop(lista, &tamanho);
    printf("Popped element: %d\n", popped);
    printf("Lista com pop: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");

    remove_element(lista, &tamanho, 2);
    printf("Lista com remoção: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");

    reverse(lista, tamanho);
    printf("Lista com reversão: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");

    sort(lista, tamanho);
    printf("Lista com ordenação: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");

    return 0;
}

