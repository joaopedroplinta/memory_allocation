# Alocação de Memória em C++ — Análise de Desempenho

## Descrição

Este programa em C++ aloca registros na memória e mede o tempo de execução, o uso de recursos e os endereços de memória utilizados. O objetivo é investigar o comportamento da alocação de registros e seus impactos em termos de tempo de execução, uso de memória e desempenho de CPU.

## Funcionalidades

- Alocação de registros na memória.
- Medição do tempo de execução.
- Monitoramento do uso de recursos do sistema.
- Rastreamento de endereços de memória.

## Requisitos

- Compilador C++ com suporte ao padrão **C++11 ou superior**.
- Sistema operacional compatível com C++ (Linux, macOS ou Windows).

## Como compilar e executar

```bash
# Clonar o repositório
git clone https://github.com/joaopedroplinta/memory_allocation.git
cd memory_allocation

# Compilar
g++ -std=c++11 -O2 -o memory_allocation memory_allocation/main.cpp

# Executar
./memory_allocation
```

## Estrutura do projeto

```
memory_allocation/
├── memory_allocation/   # Código-fonte do programa
└── README.md
```

## Tecnologias utilizadas

- **Linguagem:** C++
- **Padrão:** C++11 ou superior
- **Ferramentas de análise:** Medição de tempo e monitoramento de recursos via bibliotecas padrão

## Autor

Desenvolvido por [João Pedro Plinta](https://github.com/joaopedroplinta).
