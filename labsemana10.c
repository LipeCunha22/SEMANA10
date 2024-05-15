#include <stdio.h>

#define MAX_SIZE 100

// Fun��es do Lab da semana anterior

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
    return -1; // Se n�o encontrado
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

// Novas fun��es

void append(int arr[], int *size, int num) {
    if (*size < MAX_SIZE) {
        arr[*size] = num;
        (*size)++;
    } else {
        printf("Erro: N�o � poss�vel anexar, lista cheia.\n");
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
        printf("Erro: N�o � poss�vel inserir nesse �ndice.\n");
    }
}

int pop(int arr[], int *size) {
    if (*size > 0) {
        int popped = arr[*size - 1];
        (*size)--;
        return popped;
    } else {
        printf("Erro: Lista vazia, n�o � poss�vel fazer pop.\n");
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
            i--; // Para verificar novamente na posi��o atual, pois os elementos foram deslocados
        }
    }
    if (!found) {
        printf("Erro: Elemento n�o encontrado, n�o � poss�vel remover.\n");
    }
}

// Fun��o Calculadora

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
                printf("Erro: Divis�o por zero.\n");
            break;
        default:
            printf("Erro: Opera��o inv�lida.\n");
    }
}

int main() {
    int lista[MAX_SIZE] = {5, 3, 7};
    int tamanho = 3;

    printf("Count of 3: %d\n", count(lista, tamanho, 3));
    printf("Index of 7: %d\n", index(lista, tamanho, 7));

    append(lista, &tamanho, 2);
    printf("Lista com inser��o: ");
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
    printf("Lista com remo��o: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");

    reverse(lista, tamanho);
    printf("Lista com revers�o: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");

    sort(lista, tamanho);
    printf("Lista com ordena��o: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");

    return 0;
}

