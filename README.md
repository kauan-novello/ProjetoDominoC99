# Projeto Jogo Domino em C
Projeto em C - Cadeira de Programação Imperativa - Cesar School

Use um compilador C, como o GCC (GNU Compiler Collection), 
para compilar o arquivo C o comando é:

<code> $ gcc -o domino main.c embaralha.c </code>

e em seguida

<code> ./domino </code>

<h2>Regras do Jogo</h2>
O jogo inicia com o embaralhamento das peças, seguido pela distribuição para cada jogador. O jogador que tiver a peça de maior valor inicia a primeira rodada. As jogadas seguem uma ordem de turno, respeitando o sentido horário ou anti-horário, dependendo de quem começou.

Cada jogador escolhe uma peça para jogar na mesa. A peça escolhida deve coincidir com uma das extremidades da peça na mesa. O jogador que jogar todas as suas peças primeiro vence.

<h2>Destaques</h2>

- Embaralhamento das peças
- Distribuição das peças entre o jogadores
- Verificação de quem começa a jogada
- Ordem dos Turnos
- Lista encadeada para representar as peças na mesa
- Verificações de validade nas jogadas
- Contagem de pontos

<h2>Autores</h2>

Kauan Novello      -  kvns@cesar.school

Bernardo Coutinho  -  bcc2@cesar.school

Antônio Cabral     -  apbc@cesar.school
