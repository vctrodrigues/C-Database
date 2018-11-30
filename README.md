# C-Database - CoffeeBD
A clean database created in C for College Project
Funcionalidades:
   > create_table
       Comandos:
           -Digite o nome da tabela;
           -Digite o nome da chave primária (predeterminada como tipo int);
           -Digite o nome da coluna;
           -Digite o tipo da coluna;
           -Para finalizar digite valor 0;
       Detalhes:
           -Essa função cria uma pasta com nome da tabela (dentro da pasta dbs) e nela cria dois arquivos: nome_da_tabela.txt e nome_da_tabela.data. Sendo armazenado a formatação das colunas e tipos no arquivo nome_da_tabela.txt e as tuplas da tabela no nome_da_tabela.data. No final adiciona o nome da tabela no arquivo index.txt;
   > list_table
       Comandos:
           -Digite o nome da tabela;
       Detalhes:
           -Lista os nomes das tabelas existentes a partir da leitura do arquivo index.txt;
   > insert_data
       Comandos:
           -Digite nome da tabela;
           -Preenche os dados da tupla de acordo com cada tipo de cada coluna;
       Detalhes:
           - Leitura das colunas no arquivo ".txt" e registro no final do arquivo ".data";
   > list_data
       Comandos:
           -Digite nome da tabela;
       Detalhes:
           -Lista todas a tuplas da tabela a partir da leitura dos arquivos formatação(.txt) e os arquivos dos dados(.data);
   > remove_data
       Comandos:
           -Digite nomes da tabela;
           -Digite chave primária da tupla que deseja deletar;
       Detalhes:
           - Ele cria um arquivo (.alterado) e copia toda os dados do arquivo original(.data) exceto a tupla que contenha a chave selecionada, posteriormente deleta o arquivo original e renomeia o novo arquivo para Nome_da_tabela.data;
   > delete_table
       Comandos:
           -Digite nome da tabela;
       Detalhes:
           -Apaga a pasta com nome da tabela contida na pasta dbs e retira o nome do arquivo index.txt utilizando o mesmo processo da função remove_data;
   > search_data
       Comandos:
           -Digite nome da tabela;
           -Digite coluna que deseja procurar;
           -Selecione forma de pesquisa;
           -Digite o dado parâmetro da pesquisa;
       Detalhes:
           -Realiza pesquisa no arquivo .data de acordo com forma selecionada e retorna os valores achados. No caso 6 (valores próximos) utiliza o mecanismo de busca por substrings;
   > change_data (extra)
       Comandos:
           -Digite a tabela;
           -Selecione a coluna que deseja alterar;
           -Digite o novo valor;
           -Digite a chave primária da tupla que deseja alterar;
       Detalhes:
           -Os dados são armazenados na mesma ordem que é dada seleção da colunas, assim sabendo o valor da coluna e chave primária(sabendo que chave primária sempre é o primeiro dado) localizamos a tupla e o dado que deseja alterar. Realizando o mesmo procedimento discutido nos detalhes da funcionalidade "remove_data" criamos um arquivo com o dado alterado;
Compilar :
   -Abra o terminal na pasta inicial do arquivo e execute a seguinte linha de comando :
       $gcc main.c view.c BD.c -o main
Executar:
   -Após compilar abra o terminal na pasta inicial do arquivo e execute a seguinte linha de comando :
       $./main
Autores:
   -Pedro Cardoso Carvalho
   -Victor Raphaell Vieira Rodrigues
Contribuição:
   -Todas as funcionalidade foram feitas por ambos os autores;
Extras:
   -Além da parte visual, temos a funcionalidade "change_data" feita pela necessidade de alterar um dado específico da tabela;
