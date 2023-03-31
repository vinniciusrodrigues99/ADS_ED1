
O programa l� os nomes de um arquivo de texto chamado "nomes.txt" (que deve estar no mesmo diret�rio do programa) e para cada nome lido, chama a fun��o "to_citacao_bibliografica" para convert�-lo em formato de cita��o bibliogr�fica. 

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// Fun��o para converter uma string em formato de cita��o bibliogr�fica
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
    
    // Cria a string de cita��o bibliogr�fica
    string citacao = "";
    citacao += toupper(partes.back()[0]); // Adiciona a primeira letra do sobrenome em mai�scula
    citacao += partes.back().substr(1); // Adiciona o sobrenome sem a primeira letra
    citacao += ", "; // Adiciona a v�rgula ap�s o sobrenome
    for (int i = 0; i < (int)partes.size() - 1; i++) {
        citacao += toupper(partes[i][0]); // Adiciona a primeira letra do nome ou nome do meio em mai�scula
        citacao += ". "; // Adiciona um ponto ap�s a primeira letra e um espa�o ap�s o ponto
    }
    citacao.pop_back(); // Remove o �ltimo espa�o ap�s o �ltimo nome do meio
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
    
    // L� os nomes do arquivo e converte cada um em formato de cita��o bibliogr�fica
    string nome;
    while (getline(arquivo, nome)) {
        string citacao = to_citacao_bibliografica(nome);
        cout << citacao << endl;
    }
    
    // Fecha o arquivo
    arquivo.close();
    
    return 0;
}
