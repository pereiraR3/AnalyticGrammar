#include <iostream>
#include <stack>
#include <map>
#include <vector>

using namespace std;

// Define os tipos de símbolos
enum Simbolo { S, A, B, a, b, epsilon, cifrao };

// Mapeia pares de não-terminal e terminal para produções
map<pair<Simbolo, Simbolo>, vector<Simbolo>> tabelaDeAnalise;

// Inicializa a tabela de análise sintática
void inicializaTabelaDeAnalise() {
    tabelaDeAnalise[{S, a}] = {a, A};
    tabelaDeAnalise[{A, b}] = {b, B};
    tabelaDeAnalise[{A, cifrao}] = {epsilon}; // ϵ representa a produção vazia
    tabelaDeAnalise[{B, a}] = {a, A};
    tabelaDeAnalise[{B, b}] = {b, S};
}

// Função para processar a cadeia de entrada
bool processaEntrada(const string& entrada) {
    stack<Simbolo> pilhaDeAnalise;
    pilhaDeAnalise.push(cifrao); // Símbolo de fim de pilha
    pilhaDeAnalise.push(S); // Símbolo inicial

    int indiceEntrada = 0; // Índice para percorrer a entrada
    while (!pilhaDeAnalise.empty()) {
        Simbolo topoPilha = pilhaDeAnalise.top();
        Simbolo entradaAtual = entrada[indiceEntrada] == 'a' ? a : (entrada[indiceEntrada] == 'b' ? b : cifrao);

        if (topoPilha == a || topoPilha == b || topoPilha == cifrao) { // Se topo é terminal
            if (topoPilha == entradaAtual) {
                pilhaDeAnalise.pop(); // Corresponde: remover da pilha
                indiceEntrada++; // Avançar na entrada
            } else {
                return false; // Erro: entrada não pertence à linguagem
            }
        } else { // Se topo é não-terminal
            auto producao = tabelaDeAnalise.find({topoPilha, entradaAtual});
            if (producao == tabelaDeAnalise.end()) {
                return false; // Erro: entrada não pertence à linguagem
            } else {
                pilhaDeAnalise.pop(); // Remover não-terminal da pilha
                // Empilhar símbolos da produção em ordem inversa
                for (auto it = producao->second.rbegin(); it != producao->second.rend(); ++it) {
                    if (*it != epsilon) pilhaDeAnalise.push(*it);
                }
            }
        }
    }

    return indiceEntrada == entrada.length(); // Sucesso se a entrada foi toda processada
}

int main() {
    string entrada;
    cout << "Digite a cadeia para análise: ";
    cin >> entrada;
    entrada.push_back('$'); // Adicionar símbolo de fim de entrada

    inicializaTabelaDeAnalise();

    if (processaEntrada(entrada)) {
        cout << "A cadeia \"" << entrada << "\" pertence à linguagem.\n";
    } else {
        cout << "A cadeia \"" << entrada << "\" não pertence à linguagem.\n";
    }

    return 0;
}
