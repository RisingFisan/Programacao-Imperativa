Para escrever esta função de forma recursiva, iremos ter que dividir uma das listas, visto que a recursividade se baseia na divisão de um problema grande num conjuunto de problemas pequenos. Nesta explicação, escolhi dividir a primeira lista, pois em Haskell é geralmente mais fácil aplicar recursividade da esquerda para a direita. Para além disso, a língua Portuguesa também se escreve da esquerda para a direita, dando-nos assim um maior conforto em resolver o problema desta forma.

Desta forma, para a função `(++) a b`, sendo `a` e `b` duas listas, se dividirmos a primeira lista em `h`, o seu elemento inicial, e `t`, o resto da lista (*h* e *t* vêm de *head* e *tail*, "cabeça" e "cauda" em inglês, respetivamente, sendo o uso destas letras uma convenção), temos `(++) (h:t) b`.

Sabemos que o resultado esperado desta função é `a ++ b`, uma concatenação das duas listas. Se substituirmos `a` no resultado pela nossa divisão, ficamos com `(h:t) ++ b`.

Por intuição, vemos que podemos remover o `h` dos parênteses, visto que a concatenação não irá alterar o início da lista, e obtemos assim o mesmo resultado na mesma, ficando com `h : (t ++ b)`.

Ora, `t ++ b` não é nada mais do que `(++) t b`, a nossa função aplicada às duas listas.

Desta forma, podemos deduzir que `(++) (h:t) b = h : (++) t b`, e chegamos assim à definição recursiva da função.

Agora, apenas precisamos do caso de paragem. Nesta função é fácil encontrá-lo, como estamos a encolher a primeira lista, apenas temos de ver quando é que não a podemos encolher mais. Aqui a resposta é "quando ela for vazia", e neste caso a lista final deverá ser a segunda lista, já que concatenar algo com nada dá o "algo".

Sendo assim, obtemos a nossa solução final.

```haskell
(++) :: [a] -> [a] -> [a]
(++) [] b = b
(++) (h:t) b = h : (++) t b
```

Para casos em que a segunda lista seja vazia a nossa função também funciona, pois nenhuma das operações que realizamos envolvem os elementos da lista, apenas a lista em si, se está vazia ou não é irrelevante.