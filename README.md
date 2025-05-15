# 🔥 Programa Híbrido C++/ASM en Docker

[![GitHub License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![ASM](https://img.shields.io/badge/Assembly-NASM-red.svg)](https://nasm.us)
[![C++](https://img.shields.io/badge/C++-17-informational.svg)](https://isocpp.org/)
[![Docker](https://img.shields.io/badge/Docker-Enabled-2496ED.svg)](https://www.docker.com)
[![Platform](https://img.shields.io/badge/OS-Linux%20|%20WSL2-lightgrey.svg)](https://learn.microsoft.com/es-es/windows/wsl/)

Programa que calcula el **MCD** y **suma de arreglos** combinando C++ con ensamblador (ASM) en Docker.

## 🚀 Características
- Cálculo del MCD con el algoritmo de Euclides en ASM
- Suma optimizada de arreglos en ensamblador
- Interfaz interactiva en C++
- Soporte para arquitecturas x86_64

## 📦 Requisitos
- [Docker](https://www.docker.com/get-started)
- Git (opcional)

## 🛠️ Compilación y Ejecución

### 1. Método rápido (todo en un archivo)
```bash
docker run -it --rm -v $(pwd):/code gcc:12.2.0 sh -c "cd /code && g++ main.cpp -o programa && ./programa"

### 2. Método profesional (archivos separados)
# Compilar ASM
docker run -it --rm -v $(pwd):/code codeneomatrix/nasm sh -c "cd /code && nasm -f elf64 funciones.asm -o funciones.o"

# Compilar C++ y enlazar
docker run -it --rm -v $(pwd):/code gcc:12.2.0 sh -c "cd /code && g++ main.cpp funciones.o -o programa && ./programa"
