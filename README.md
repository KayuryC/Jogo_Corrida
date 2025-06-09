# 🏁 Corrida de Processos no Terminal
Este projeto é uma simulação visual e divertida de escalonamento de processos, utilizando as políticas FIFO e Round Robin. Cada processo é representado por um animal que "corre" no terminal, mostrando sua barra de progresso até a conclusão.

🎮 Como funciona
O usuário escolhe uma das duas políticas de escalonamento:

FIFO (First In, First Out): os processos são executados na ordem em que chegam, um de cada vez até a conclusão.

Round Robin: os processos são executados em rodadas com um quantum de 1 segundo. Cada processo recebe tempo de CPU por turnos até todos serem concluídos.

# 🐢🐇🐍 Participantes
Cada processo tem um nome de animal e um tempo aleatório de execução entre 5 e 14 unidades de tempo:

Tartaruga

Coelho

Raposa

Cobra

Elefante

# 🖥️ Visual
Durante a execução, uma barra de progresso no terminal mostra o andamento de cada processo. Ao final, é exibido o processo que terminou mais rápido.

#📦 Compilação
Compile o programa com gcc:


🚀 Execução

1 - FIFO (Primeiro a entrar, primeiro a sair)
2 - Round Robin (Quantum de 1 segundo)
💡 Requisitos
Compilador C (GCC)

Terminal compatível com códigos ANSI (como bash)

# 📚 Conceitos abordados
Simulação de escalonamento de processos

FIFO vs Round Robin

Uso de structs, ponteiros e arrays em C

Manipulação do terminal com escape codes ANSI

Funções sleep, rand, e controle de fluxo

