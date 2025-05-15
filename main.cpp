#include <iostream>
#include <vector>

extern "C" {
    int calcularMCD(int a, int b);
    int sumarArreglo(int* arr, int size);
}

asm(R"(
.global calcularMCD
calcularMCD:
    push %rbx
    mov %edi, %eax
    mov %esi, %ebx
.loop_mcd:
    xor %edx, %edx
    div %ebx
    mov %ebx, %eax
    mov %edx, %ebx
    test %ebx, %ebx
    jnz .loop_mcd
    pop %rbx
    ret

.global sumarArreglo
sumarArreglo:
    xor %eax, %eax
    test %esi, %esi
    jz .end_sum
    lea (%rdi,%rsi,4), %rcx
.loop_sum:
    add (%rdi), %eax
    add $4, %rdi
    cmp %rdi, %rcx
    jne .loop_sum
.end_sum:
    ret
)");

int main() {
    // Entrada para MCD
    int num1, num2;
    std::cout << "=== Calculadora MCD y Suma de Arreglo ===" << std::endl;
    std::cout << "Ingrese dos numeros para calcular el MCD:\n";
    std::cout << "Numero 1: ";
    std::cin >> num1;
    std::cout << "Numero 2: ";
    std::cin >> num2;
    std::cout << "MCD(" << num1 << ", " << num2 << ") = " << calcularMCD(num1, num2) << "\n\n";

    // Entrada para el arreglo
    int n;
    std::cout << "Ingrese el tamaño del arreglo: ";
    std::cin >> n;
    
    int* arr = new int[n];
    std::cout << "Ingrese " << n << " elementos:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Elemento " << i + 1 << ": ";
        std::cin >> arr[i];
    }
    
    std::cout << "Suma del arreglo = " << sumarArreglo(arr, n) << std::endl;
    
    delete[] arr;
    return 0;
}