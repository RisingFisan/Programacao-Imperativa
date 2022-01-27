Existem várias formas de definir funções recursivas. A que vou usar nesta explicação consiste em encontrar o "padrão" da recursividade, isto é, o que é que muda entre diferentes chamadas recursivas da função.

Qual deverá ser o resultado de `enumFromTo 5 5`? Exato, apenas `[5]`.

E de `enumFromTo 4 5`? `[4,5]`.

Ou seja, quando chamamos a função `enumFromTo start end`, a lista resultante começa sempre com `start`.

Temos assim uma definição preliminar da função: `enumFromTo start end = start : ???` (`:` é uma função que coloca um elemento no início de uma lista).

Vamos aplicar esta nossa solução a um exemplo concreto: `enumFromTo 1 5` irá resultar em `1 : ???`.

Pode parecer que chegámos a um entrave, mas nós sabemos o valor de `???`. Neste caso, `??? = [2,3,4,5]`, isto é, o resto da lista.

Agora vamos pensar ao contrário... o que é que deve resultar em `[2,3,4,5]`? Exatamente, `enumFromTo 2 5`! Por outras palavras, sabemos que `enumFromTo 1 5 = 1 : enumFromTo 2 5 = 1 : enumFromTo (1 + 1) 5`.

Já podemos então definir a nossa função como: `enumFromTo start end = start : enumFromTo (start + 1) end`.

Visto que esta função é recursiva, precisamos ainda de um caso de paragem. Para lá chegar, podemos pensar da seguinte forma: quando é que paramos de adicionar 1 a `start`? Aqui a resposta é "quando for igual a `end`", pois se os dois valores forem iguais iremos ter uma lista de apenas um elemento.

Chegamos assim à definição (quase) final da função:

```haskell
enumFromTo start end 
    | start == end = [start]
    | otherwise = start : enumFromTo (start + 1) end
```

Os caracteres `|` chamam-se "guardas", podes aprender o que são e como as usar [aqui](http://learnyouahaskell.com/syntax-in-functions#guards-guards).

Apesar desta definição funcionar para a maioria dos casos, não funciona para todos. E se `start` for maior que `end`? Se experimentássemos correr `enumFromTo 5 1` com a nossa solução atual, o nosso computador nunca mais iria sair do sítio. Porquê? Porque iria estar constantemente a adicionar uma unidade a `start`, mas como este já é superior a `end`, nunca iriam ser iguais. Desta forma, uma solução mais completa para esta questão seria:

```haskell
enumFromTo start end 
    | start > end = []
    | start == end = [start]
    | otherwise = start : enumFromTo (start + 1) end
```

Por outras palavras, se o limite inferior for maior do que o limite superior, o resultado é uma lista vazia (um comportamento alternativo seria ordenar de forma decrescente neste cenário, mas nesta questão apenas pretendemos ordenar de forma crescente).

Por intuição, vemos que a segunda condição é redundante, por isso podemos removê-la de forma segura.

```haskell
enumFromTo start end 
    | start > end = []
    | otherwise = start : enumFromTo (start + 1) end
```
