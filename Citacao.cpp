
O programa lê os nomes de um arquivo de texto chamado "nomes.txt" (que deve estar no mesmo diretório do programa) e para cada nome lido, chama a função "to_citacao_bibliografica" para convertê-lo em formato de citação bibliográfica. 

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// Função para converter uma string em formato de citação bibliográfica
string to_citacao_bibliografica(string nome) {
    // Separa o nome em partes (primeiro nome, nomes do meio e sobrenome)
    vector<string> partes;
    string parte_atual = "";
    for (char c : nome) {
        if (c == ' ') {
            if (!parte_atual.empty()) {
                partes.push_back(parte_atual);
                parte_atual = "";
            }
        } else {
            parte_atual += c;
        }
    }
    if (!parte_atual.empty()) {
        partes.push_back(parte_atual);
    }
    
    // Cria a string de citação bibliográfica
    string citacao = "";
    citacao += toupper(partes.back()[0]); // Adiciona a primeira letra do sobrenome em maiúscula
    citacao += partes.back().substr(1); // Adiciona o sobrenome sem a primeira letra
    citacao += ", "; // Adiciona a vírgula após o sobrenome
    for (int i = 0; i < (int)partes.size() - 1; i++) {
        citacao += toupper(partes[i][0]); // Adiciona a primeira letra do nome ou nome do meio em maiúscula
        citacao += ". "; // Adiciona um ponto após a primeira letra e um espaço após o ponto
    }
    citacao.pop_back(); // Remove o último espaço após o último nome do meio
    citacao += "."; // Adiciona um ponto no final da string
    
    return citacao;
}

int main() {
    // Abre o arquivo de texto com os nomes
    ifstream arquivo("nomes.txt");
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo de nomes!" << endl;
        return 1;
    }
    
    // Lê os nomes do arquivo e converte cada um em formato de citação bibliográfica
    string nome;
    while (getline(arquivo, nome)) {
        string citacao = to_citacao_bibliografica(nome);
        cout << citacao << endl;
    }
    
    // Fecha o arquivo
    arquivo.close();
    
    return 0;
}
