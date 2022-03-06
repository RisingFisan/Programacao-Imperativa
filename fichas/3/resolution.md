# 1) Assumindo que uma hora é representada por um par de inteiros, uma viagem pode ser representada por uma sequência de etapas, onde cada etapa é representada por um par de horas (partida, chegada):

```
data Hora = H Int Int
            deriving Show

type Etapa = (Hora,Hora)
type Viagem = [Etapa]
```

# Por exemplo, se uma viagem for

```
[(H 9 30, H 10 25), (H 11 20, H 12 45), (H 13 30, H 14 45)]
```

# significa que teve três etapas:

- a primeira começou às 9 e um quarto e terminou às 10 e 25;
- a segunda começou às 11 e 20 e terminou à uma menos um quarto;
- a terceira começou às 1 e meia e terminou às 3 menos um quarto;

# Para este problema, vamos trabalhar apenas com viagens que começam e acabam no mesmo dia. Utilizando as funções sobre horas que definiu na Ficha 1, defina as seguintes funções:

## a) Testar se uma etapa está bem construída (i.e., o tempo de chegada é superior ao de partida e as horas são válidas).

```haskell
etapaBemConstruida :: Etapa -> Bool
etapaBemConstruida (h1,h2) = horaValida h1 && horaValida h2 && h2 `horaDepois` h1
```

## b) Testa se uma viagem está bem construída (i.e., se para cada etapa, o tempo de chegada é superior ao de partida, e se a etapa seguinte começa depois da etapa anterior ter terminado).

```haskell
viagemBemConstruida :: Viagem -> Bool
viagemBemConstruida [] = True
viagemBemConstruida [e] = etapaBemConstruida e
viagemBemConstruida ((h1,h2):(h3,h4):et) = etapaBemConstruida (h1,h2) && etapaBemConstruida (h2,h3) && viagemBemConstruida ((h3,h4):et)

-- Precisamos de pelo menos duas etapas na definição recursiva pois precisamos de comparar o tempo de fim da primeira etapa com o tempo de início da segunda etapa.
```

## c) Calcular a hora de partida e de chegada de uma dada viagem.

```haskell
partidaEChegada :: Viagem -> (F1.Hora,F1.Hora)
partidaEChegada [(h1,h2)] = (h1,h2)
partidaEChegada ((h1,_):(_,h4):et) = partidaEChegada ((h1,h4):et) 
```

## d) Dada uma viagem válida, calcular o tempo total de viagem efectiva.

```haskell
tempoDeViagem :: Viagem -> Hora
tempoDeViagem [(h1,h2)] = hourDiff h1 h2
tempoDeViagem ((h1,h2):et) = addMins (hourDiff h1 h2) (hour2min(tempoDeViagem et))
```

## e) Calcular o tempo total de espera.

```haskell
tempoDeEspera :: Viagem -> Hora
tempoDeEspera [(h1,h2)] = H 0 0
tempoDeEspera ((h1,h2):(h3,h4):et) = addMins (hourDiff h2 h3) (hour2min (tempoDeEspera ((h3,h4):et)))
```

## f) Calcular o tempo total da viagem (a soma dos tempos de espera e de viagem efectiva).

```haskell
tempoTotalViagem :: Viagem -> Hora
tempoTotalViagem v = addMins (tempoDeViagem v) (hour2min (tempoDeEspera v))
```

# 2) Considere as seguinte definição de um tipo para representar linhas poligonais.

```
type Poligonal = [Ponto]
```

# O tipo `Ponto` é idêntico ao definido na Ficha 1. Nas resolução das alíneas seguintes pode utilizar funções definidas nessa ficha.

## a) Defina a função para calcular o comprimento de uma linha poligonal

```haskell
comprimento :: Poligonal -> Double
comprimento p = case p of [] -> 0
                          [_] -> 0
                          (a:b:t) -> dist a b + comprimento (b:t)
```

## b) Defina uma função para testar se uma dada linha poligonal é ou não fechada.

```haskell
linhaFechada :: Poligonal -> Bool
linhaFechada p = length p >= 3 && head p == last p

-- Escrever `head p == last p` e `dist (head p) (last p) == 0` deverá ser equivalente. Neste caso só podemos escrever da primeira forma porque o tipo `Ponto` deriva a classe `Eq`, permitindo-nos assim verificar a equivalência de valores deste tipo com a função `(==)`.
```

## c) Defina a função `triangula :: Poligonal -> [Figura]` que, dada uma linha poligonal fechada e convexa, calcule uma lista de triângulos cuja soma das áreas seja igual à àrea delimitada pela linha poligonal. O tipo `Figura` é idêntico ao definido na Ficha 1.

```haskell
triangula :: Poligonal -> [Figura]
triangula [p1,p2,p3] = [Triangulo p1 p2 p3]
triangula (p1:p2:p3:ps) = Triangulo p1 p2 p3 : triangula (p1:p3:ps)
triangula _ = []

-- Com esta função, criamos um leque de triângulos (https://pt.wikipedia.org/wiki/Leque_de_tri%C3%A2ngulos).
```

## d) Defina uma função para calcular a área delimitada por uma linha poligonal fechada e convexa.

```haskell
areaPol :: Poligonal -> Double
areaPol p = sum [area t | t <- triangula p]

-- Aqui, dividimos o polígono em triângulos, calculamos a área de cada um e fazemos a soma destas áreas.
```

## e) Defina a função `mover :: Poligonal -> Ponto -> Poligonal` que, dada uma linha poligonal e um ponto, dá como resultado uma linha poligonal idêntica à primeira mas tendo como ponto inicial o ponto dado.

```haskell
mover :: Poligonal -> Ponto -> Poligonal
mover pol p = p : pol
```

## a) Defina a função `zoom :: Double -> Poligonal -> Poligonal` que, dada um factor de escala e uma linha poligonal, dê como resultado uma linha poligonal semelhante e com o mesmo ponto inicial mas em que o comprimento de cada segmento de recta é multiplicado pelo factor dado.

```haskell
zoom :: Double -> Poligonal -> Poligonal
zoom z [p1,p2] = [p1,multP z p2]
zoom z (p1:p2:pol) = p1 : zoom z (p2' : pol)
    where p2' = multP z p2
zoom _ p = p

multP :: Double -> Ponto -> Ponto
multP z p = Cartesiano (z * posx p) (z * posy p)
```

# 3) Para armazenar uma agenda de contactos telefónicos e de correio electrónico definiram-se os seguintes tipos de dados. Não existem nomes repetidos na agenda e para cada nome existe uma lista de contactos.

```
data Contacto = Casa Integer
              | Trab Integer
              | Tlm Integer
              | Email String
              deriving Show

type Nome = String
type Agenda = [(Nome, [Contacto])]
```

## a) Defina a função `acrescEmail :: Nome -> String -> Agenda -> Agenda` que, dado um nome, um email e uma agenda, acrescenta essa informação à agenda.

```haskell
acrescEmail :: Nome -> String -> Agenda -> Agenda
acrescEmail nome email agenda = agenda ++ [(nome, [Email email])]
```

## b) Defina a função `verEmails :: Nome -> Agenda -> Maybe [String]` que, dado um nome e uma agenda, retorna a lista dos emails associados a esse nome. Se esse nome não existir na agenda a função deve retornar `Nothing`.

```haskell
verEmails :: Nome -> Agenda -> Maybe [String]
verEmails _ [] = Nothing
verEmails nome [(n,c)] = if nome == n then Just [e | x@(Email e) <- c] else Nothing
verEmails nome ((n,c):agenda) = if nome == n then verEmails nome [(n,c)] else verEmails nome agenda
```

## c) Defina a função `consTelefs :: [Contacto] -> [Integer]` que, dada uma lista de contactos, retorna a lista de todos os números de telefone dessa lista (tanto telefones fixos como telemóveis).

```haskell
consTelefs :: [Contacto] -> [Integer]
consTelefs [] = []
consTelefs (c:cs) = case c of Casa x -> x:consTelefs cs
                              Trab x -> x:consTelefs cs
                              Tlm x -> x:consTelefs cs 
                              _ -> consTelefs cs
``` 

## d) Defina a função `casa :: Nome -> Agenda -> Maybe Integer` que, dado um nome e uma agenda, retorna o número de telefone de casa (caso exista).

```haskell
casa :: Nome -> Agenda -> Maybe Integer
casa _ [] = Nothing
casa nome [(n,c:cs)] = if nome == n 
                       then case c of Casa x -> Just x
                                      _ -> casa nome [(n,cs)] 
                       else Nothing
casa nome ((n,c):agenda) = if nome == n 
                           then casa nome [(n,c)]
                           else casa nome agenda
``` 

# 4) Pretende-se guardar informação sobre os aniversários das pessoas numa tabela que associa o nome de cada pessoa à sua data de nascimento. Para isso, declarou-se a seguinte estrutura de dados:

```
type Dia = Int
type Mes = Int
type Ano = Int
type Nome = String

data Data = D Dia Mes Ano
    deriving Show

type TabDN = [(Nome,Data)]
```

## a) Defina a função `procura :: Nome -> TabDN -> Maybe Data` que indica a data de nascimento de uma dada pessoa, caso o seu nome exista na tabela.

```haskell
procura :: Nome -> TabDN -> Maybe Data
procura _ [] = Nothing
procura nome ((n,d):ts) = if nome == n then Just d else procura nome ts
```

## b) Defina a função `idade :: Data -> Nome -> TabDN -> Maybe Int` que calcula a idade de uma pessoa numa dada data.

```haskell
idade :: Data -> Nome -> TabDN -> Maybe Int
idade _ _ [] = Nothing
idade data@(D dx mx ax) nome ((n,D d m a):ts) = if nome == n then if mx > m || mx == m && dx > d then Just (ax - a) else Just ((ax - a) - 1) else idade data nome ts
```

## c) Defina a função `anterior :: Data -> Data -> Bool` que testa se uma data é anterior a outra data.

```haskell
anterior :: Data -> Data -> Bool
anterior (D d m a) (D d2 m2 a2) = a < a2 || (a == a2 && (m < m2 || (m == m2 && d < d2)))
``` 

## d) Defina a função `ordena :: TabDN -> TabDN` que ordena uma tabela de datas de nascimento por ordem crescente das datas de nascimento.

```haskell
ordena :: TabDN -> TabDN
ordena [] = []
ordena ((n,d):ts) = insere (n,d) (ordena ts)
    where insere (n,d) [] = [(n,d)]
          insere (n,d) ((nh,dh):t) | anterior dh d = (nh,dh):insere (n,d) t
                                   | otherwise = (n,d):(nh,dh):t
``` 

## e) Defina a função `porIdade:: Data -> TabDN -> [(Nome,Int)]` que apresenta o nome e a idade das pessoas, numa dada data, por ordem crescente da idade das pessoas.

```haskell
porIdade:: Data -> TabDN -> [(Nome,Int)]
porIdade _ [] = []
porIdade (D d m a) tabela = (n,idade) : porIdade (D d m a) ts
    where ((n,D dx mx ax):ts) = ordena tabela
          idade = if m > mx || mx == m && d > dx then a - ax else (a - ax) - 1
``` 

# 5) Considere o seguinte tipo de dados que descreve a informação de um extracto bancário. Cada valor deste tipo indica o saldo inicial e uma lista de movimentos. Cada movimento é representado por um triplo que indica a data da operação, a sua descrição e a quantia movimentada (em que os valores são sempre números positivos).

``` 
data Movimento = Credito Float | Debito Float
    deriving Show

data Data = D Int Int Int
    deriving Show

data Extracto = Ext Float [(Data, String, Movimento)]
    deriving Show
```

## a) Construa a função `extValor :: Extracto -> Float -> [Movimento]` que produz uma lista de todos os movimentos (créditos ou débitos) superiores a um determinado valor.

```haskell
extValor :: Extracto -> Float -> [Movimento]
extValor (Ext _ []) _ = []
extValor (Ext x ((_,_,mov):ls)) valor = if n >= valor then mov : extValor (Ext x ls) valor else extValor (Ext x ls) valor
    where n = case mov of Credito x -> x
                          Debito x -> x
```

## b) Defina a função `filtro :: Extracto -> [String] -> [(Data,Movimento)]` que retorna informação relativa apenas aos movimentos cuja descrição esteja incluída na lista fornecida no segundo parâmetro.

```haskell
filtro :: Extracto -> [String] -> [(Data,Movimento)]
filtro (Ext _ []) _ = []
filtro (Ext x ((dat,desc,mov):ls)) listaStr = if desc `elem` listaStr then (dat,mov) : filtro (Ext x ls) listaStr else filtro (Ext x ls) listaStr
```

## c) Defina a função `creDeb :: Extracto -> (Float,Float)` que retorna o total de créditos e de débitos de um extracto no primeiro e segundo elementos de um par, respectivamente.

```haskell
creDeb :: Extracto -> (Float,Float)
creDeb (Ext _ lm) = foldl (\(c,d) (_,_,mov) -> case mov of Credito x -> (c + x, d)
                                                           Debito x -> (c, d + x)) (0,0) lm
```

## a) Defina a função `saldo :: Extracto -> Float` que devolve o saldo final que resulta da execução de todos os movimentos no extracto sobre o saldo inicial.

```haskell
saldo :: Extracto -> Float
saldo (Ext x lm) = foldl (\acc (_,_,mov) -> case mov of Credito n -> acc + n
                                                        Debito n -> acc - n) x lm
```