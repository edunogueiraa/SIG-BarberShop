# Projeto SIG-Barbearia 💈

## 📌 Descrição

O **SIG-BarberShop** é um sistema de gestão desenvolvido em **C** para auxiliar na organização e administração de uma barbearia. O sistema permite o cadastro e gerenciamento de clientes, serviços, colaboradores, agendamentos e estoque, além da emissão de relatórios, oferecendo uma solução prática para controle interno.

---

## ⚙️ Funcionalidades

- Cadastro de clientes
- Gerenciamento de serviços oferecidos
- Controle de colaboradores
- Agendamento de horários
- Controle de estoque
- Geração de relatórios
- Menu principal intuitivo
- Opção de encerrar e acessar informações do sistema

---

## 🚀 Como Compilar e Executar

### Pré-requisitos

- Compilador C (ex.: `gcc`)
- Sistema operacional Windows, Linux ou compatível

### Compilação

No terminal, dentro da pasta do projeto, execute:

```bash
gcc *.c -o SIG-BarberShop
```

### Execução

Após a compilação:

```bash
./SIG-BarberShop   # Linux ou MacOS
SIG-BarberShop.exe # Windows
```

---

## 📂 Estrutura do Projeto

```
├── agendamento.c       # Módulo de agendamento
├── cliente.c           # Módulo de clientes
├── colaboradores.c     # Módulo de colaboradores
├── estoque.c           # Módulo de estoque
├── main.c              # Arquivo principal do sistema
├── menuPrincipal.c     # Controle do menu principal
├── relatorio.c         # Geração de relatórios
├── servicos.c          # Módulo de serviços
├── sobre.c             # Informações sobre o sistema
├── sair.c              # Encerramento do sistema
├── .gitignore          # Arquivos ignorados pelo Git
└── README.md           # Documentação do projeto
```

---

## 🛠️ Tecnologias Utilizadas

- Linguagem **C**
- Compilador **GCC** (ou compatível)
- Estrutura modular (separação em múltiplos arquivos `.c`)

---
