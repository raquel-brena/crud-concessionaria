
# Identificação

* Nome: Raquel Brena Silva de Lima

* Matrícula: 20210055510
  
# Compilação  

* a descrição de como compilar e rodar o programa, incluindo um roteiro de entradas e comandos que destaquem as funcionalidades 

Para realizar a compilação do programa, deve-se colocar o método que você deseja executar seguindo dos atributos necessários para a compilação do programa, por exemplo: metodo-desejado atributo1 atributo2. Nesse criador de Concessionárias possuímos os métodos create-concessionaria, add-car, add-motorcycle, add-truck, remove-vehicle, search-concessionaria, load-concessionaria, list-concessionaria, raise-concessionaria e quit. A seguir, uma explicação sobre cada método e os atributos necessários para executá-los.

- create concessionaria: Método para realizar criação de concessionárias. Você pode criar concessionárias novas, mas para isso deve-se ter nome e CNPJ diferente de outras já existentes. Além disso, a concessionária inicia com um valor de estoque inicial, dado na entrada pelo usuário. 
Padrão de entrada: create-concessionaria nome cnpj estoque

- add car: Método para realizar adição de carros. Você pode adicionar carros novos, mas para isso deve-se adicionar em um concessionária existente e não pode haver veículos de mesmo chassi numa mesma concessionária. O método se inicia com os atributos concessionária, marca, preco, chassi, ano de fabricação e tipo de motor.
Padrão de entrada: add-car concessionaria marca preco chassi anoFabricacao Motor

- add moto: Método para realizar adição de motos. Você pode adicionar motos novas, mas para isso deve-se adicionar em um concessionária existente e não pode haver motos de mesmo chassi numa mesma concessionária. O método se inicia com os atributos concessionária, marca, preco, chassi, ano de fabricação e modelo.
Padrão de entrada: add-motorcycle concessionaria marca preco chassi anoFabricacao Motor

- add caminhao: Método para realizar adição de caminhões. Você pode adicionar caminhões novos, mas para isso deve-se adicionar em um concessionária existente e não pode haver caminhão de mesmo chassi numa mesma concessionária. O método se inicia com os atributos concessionária, marca, preco, chassi, ano de fabricação e tipo de carga.
Padrão de entrada: add-truck concessionaria marca preco chassi anoFabricacao carga

- remove vehicle: Método para realizar remoção de veículos. Você pode removos veículos, mas para isso o veículo deve existir em alguma concessionária, não sendo possível remover o que já está removido ou não existe. O método se inicia com os atributo chassi.
Padrão de entrada: remove-vehicle chassi

- search vehicle: Método para realizar busca de veículos. Você pode buscar qualquer veículos, mas para isso o veículo deve existir em alguma concessionária. A busca traz a concessionária onde se encontra o veículo, assim como todos os outros atributos dele. O método se inicia com os atributo chassi.
Padrão de entrada: search-vehicle chassi

- save concessionaria: Método para salvar uma concessionária em um arquivo de texto, a fim de guardar os dados dessa concessionaria. O arquivo .txt guardará as motos, carros e caminhões da concessionária, assim como o atributo de cada um. O método se inicia com os atributo nomeConcessionaria.
Padrão de entrada: save-concessionaria nomeConcessionaria

- load concessionaria: Método para recuperar e salvar dados a partir de um arquivo .txt, a fim de guardar os dados dessa concessionaria. Esse método lê todas as motos, carros e caminhões da concessionária, assim como o atributo de cada um. O método se inicia com os atributo nomeConcessionaria.txt.
Padrão de entrada: load-concessionaria nomeConcessionaria.txt

- list concessionaria: Método para listar e mostrar na tela a frota de toda a concessionária, assim como a quantidade e o valor total de cada veículo. O método se inicia com os atributo nomeConcessionaria.txt.
Padrão de entrada: list-concessionaria nomeConcessionaria

- raise price: Método para permitir aumento de preco do valor de todos os veículos. O aumento é dado em x% para carros, 2x% para motos e 3x% para caminhões. O resultado do valor é mostrado na tela. O método se inicia com os atributo nomeConcessionaria porcentagem.
Padrão de entrada: list-concessionaria nomeConcessionaria porcentagem

- quit: método para realizar saída do programa.
Padrão de entrada: quit

# Limitações

* a descrição das limitações (caso existam) do programa e quaisquer dificuldades encontradas
Possui dificuldade no ínicio para assimilar o programa já feito e por onde devia iniciar, qual caminho seguir... Senti dificuldade para perceber por onde devia adicionar os veículos, por qual classe etc. Também foi dificultoso pelo meu tempo pessoal, gostaria de ter implementado mais coisas e otimizado o código com templates e utilizado métodos virtuais.
   
# Autoavaliação

- Modelagem e implementação das classes Concessionária, Veículo, Automóvel, Moto, Caminhão | ***10 / 10**
  - 0: sem modelagem e implementação de classes
  - 5: apenas algumas classes modeladas e implementadas; ausência de herança
  - 10: modelagem e implementação completa com uso de herança
  
- Implementação e uso do comando `create-concessionaria` | **10 / 10**
  - 0: não cria concessionária via linha de comando 
  - 5: permite criar apenas uma concessionária
  - 10: permite criar mais do que uma concessionária
  
- Implementação e uso dos comandos para adicionar veículos `add-car/add-bike/add-truck` | **10 / 10**
  - 0: não permite criar veículos via linha de comando
  - 5: permite criar apenas um ou outro veículo em uma única concessionária
  - 10: permite criar qualquer tipo de veículo em qualquer uma das concessionárias disponíveis

- Não permitir adicionar um veículo que já tenha sido anteriormente adicionado | **10 / 10**
  - 0: não realiza o teste
  - 10: realiza o teste e indica o erro  

- Implementação e uso do comando para remover veículos `remove-vehicle` | **10 / 10**
  - 0: comando não implementado
  - 10: comando implementado e funcional

- Implementação e uso do comando para busca de veículos `search-vehicle` | **15 / 15 - Bônus: ...**
  - 0: não implementado
  - 15: implementado e funcional
  - bonus +10: implementado com estratégia de busca diferente da busca exaustiva
  - bonus +10: uso de métodos virtuais para impressão na tela
  - bonus +10: uso de sobrecarga de operadores para impressão na tela

- Implementação e uso do comando `list-concessionaria` | **10 / 10 - Bônus: ...**
  - 0: não implementado
  - 10: implementado e funcional   
  - bonus +10: uso de sobrecarga de operadores para impressão na tela

- Implementação e uso do comando `raise-price` | **10 / 10 - Bônus: ...**
  - 0: não implementado
  - 10: implementado e funcional 
  - bonus +10: implementado com uso de método virtual

- Implementação e uso do comando `save-concessionaria` e `load-concessionaria` | **15 / 30**
  - 0: não implementado
  - 15: ambos os comandos implementados e funcionais
  
- Implementação eficiente através do uso de referencias e contêineres da STL | **10 / 10**
  - 0: não usou contêiner da STL nem fez uso eficiente dos recursos computacionais
  - 5: usou contêiner da STL mas não otimizou uso dos recursos computacionais
  - 10: usou contêiner da STL junto a algoritmos e práticas de bom uso de recursos computacionais
  
- Organização do código em src, include, data | **5 / 5**
  - 0: não organizou o código
  - 5: organizou o código 
  
- Documentação do código | **5/ 5**
  - 0: não documentou o código
  - 5: documentou o código 
  
- Implementação e documentação de arquivos e procedimentos de compilação e teste | **15 / 15**
  - 0: não implementou arquivos e procedimentos de compilação e teste
  - 5: implementou alguns arquivos e procedimentos de compilação e teste (com alguma documentação) 
  - 15: Ampla implementação e documentação de arquivos e procedimentos de compilação e teste (com exemplos)
 
 # Total
 
 **150 / 150 ** pontos (sem bônus)
 
 **... / 200 ** pontos (com bônus)
