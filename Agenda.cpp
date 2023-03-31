#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// Fun��o para converter uma string em formato de agenda telef�nica
string to_agenda_telefonica(string nome) {
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
    
    // Cria a string de agenda telef�nica
    string agenda = "";
    agenda += partes.back(); // Adiciona o sobrenome
    agenda += ", "; // Adiciona a v�rgula ap�s o sobrenome
    for (int i = 0; i < (int)partes.size() - 1; i++) {
        agenda += partes[i]; // Adiciona o nome ou nome do meio
        agenda += " "; // Adiciona um espa�o ap�s o nome ou nome do meio
    }
    agenda.pop_back(); // Remove o �ltimo espa�o ap�s o �ltimo nome do meio
    
    return agenda;
}

int main() {
    // Abre o arquivo de texto com os nomes
    ifstream arquivo("nomes.txt");
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo de nomes!" << endl;
        return 1;
    }
    
    // L� os nomes do arquivo e converte cada um em formato de agenda telef�nica
    string nome;
    while (getline(arquivo, nome)) {
        string agenda = to_agenda_telefonica(nome);
        cout << agenda << endl;
    }
    
    // Fecha o arquivo
    arquivo.close();
    
    return 0;
}
