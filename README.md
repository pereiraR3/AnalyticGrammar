# AnalyticGrammar

Projeto iniciado e concluído em 2024, preparado em menos de 1 semana. Requisitado pela disciplina de TELEFAC (Teoria das Linguagens Formais e Autômatos).

## Visão Geral
O projeto não é nada mais do que a construção de um analisador sintático, dentre o qual deverá ser rapaz de receber entradas para atestar se pertence ou não à linguagem pré-determinada.

## Definição de Gramática Livre de Contexto

Uma gramática livre de contexto \( G \) é definida pela 4-tupla \( G = (N, Σ, P, S) \), onde:

- \( N \) é um conjunto de símbolos não-terminais.
- \( Σ \) é um conjunto de símbolos terminais.
- \( P \) é um conjunto de regras de produção.
- \( S \) é o símbolo inicial.

Para a dada gramática \( G \):

- \( N = \{S, A, B\} \)
- \( Σ = \{a, b\} \)
- As regras de produção \( P \) são:
  - \( S \rightarrow aA \)
  - \( A \rightarrow bB \) | \( ε \)
  - \( B \rightarrow aA \) | \( bS \)

A tabela de análise para esta gramática é a seguinte:

|   | a            | b            | $   |
|---|--------------|--------------|-----|
| S | S -&gt; aA |              |     |
| A |              | A -&gt; bB | A -&gt; ε |
| B | B -&gt; aA | B -&gt; bS |     |

Nota: \$ representa o final da cadeia de entrada.


## Tecnologias Utilizadas

A tecnologia usada para desenvolver o projeto é a seguinte:

<div style="display: inline_block" align= "center"><br>
<img align="center" alt="C++" height="38" width="80" src="https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white">
</div>

## Contato
<strong> Membros Desenvolvedores do Projeto: </strong> Somos ambos estudantes de Ciência da Computação na Universidade Federal de Mato Grosso - Turma de 2022.

| Membro | Foto | Email | LinkedIn |
| --- | --- | --- | --- |
| Anthony Ricardo Rodrigues Rezende | <img src="./Membros/anthony.jpeg" alt="Foto do Anthony" width="100"/> | anthony_rodriguespereira@outlook.com | [LinkedIn do Anthony](https://www.linkedin.com/in/anthony-ricardo-rodrigues-rezende-486917227/) |
| Alan Bruno Moraes Costa | <img src="./Membros/alanB.jpeg" alt="Foto do Alan" width="100"/> | alanbrunomoraescosta18@hotmail.com | [LinkedIn do Alan](https://www.linkedin.com/in/alan-morais-4861322b0) |
| Vinicius Padilha Vieira | <img src="./Membros/vinicius.jpeg" alt="Foto do Vinicius" width="100"/> | vinicius_padilhavieira@outlook.com | [LinkedIn do Vinicius](https://www.linkedin.com/in/vinicius-padilha-vieira-486917227/) |
| Andrey Luiggi da Cruz | <img src="./Membros/andrey.jpeg" alt="Foto do Andrey" width="100"/> | andrey_luiggidacruz@outlook.com | [LinkedIn do Andrey](https://www.linkedin.com/in/andrey-luiggi-da-cruz-4861322b0) |

##
