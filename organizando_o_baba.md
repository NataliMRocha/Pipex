Assim, precisaremos de duas coisas para definir um pipe: algo que caracterize a entrada, que onde iremos escrever (usando a chamada write()) e algo que caracterize a saída, onde iremos ler (chamada read()).

Essas duas coisas que iremos precisar parar criar o pipe são os file descriptors, que nada mais são que dois inteiros que vão definir a entrada-padrão e a saída-padrão do pipe. Na verdade precisaremos apenas de uma coisa, um vetor de inteiros de duas posições.

O primeiro elemento (elemento 0) do vetor define a leitura (saída) de dados, e o segundo elemento (de índice 1) 
define a escrita de dados no pipe (entrada).
Escreve no fd[1] --(pipe)--> lê no fd[0]

O terceiro parâmetro deve ser fornecido caso na abertura se tenha especificado o flag O_CREAT. Este terceiro parâmetro indica a máscara de proteção a ser usada na criação do arquivo. Pode-se especificar mais de um flag neste campo, bastando fazer-se or binário entre os seguintes valores:

S_IRUSR - Leitura para usuário
S_IWUSR - Gravação para usuário
S_IXUSR - Execução para usuário
S_IRRGRP - Leitura para grupo
S_IWGRP - Gravação para grupo
S_IXGRP - Execução para grupo
S_IROTH - Leitura para outros
S_IWOTH - Gravação para outros
S_IXOTH - Execução para outros