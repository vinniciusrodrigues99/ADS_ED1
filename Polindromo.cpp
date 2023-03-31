#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Função para remover espaços de uma string
string remove_espacos(string str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

// Função para verificar se uma string é um palíndromo
bool is_palindromo(string str) {
    str = remove_espacos(str);
    string str_reversa = str;
    reverse(str_reversa.begin(), str_reversa.end());
    return str == str_reversa;
}

int main() {
    // Lê a mensagem digitada pelo usuário
    string mensagem;
    cout << "Digite uma mensagem: ";
    getline(cin, mensagem);
    
    // Verifica se a mensagem é um palíndromo e imprime o resultado
    if (is_palindromo(mensagem)) {
        cout << "A mensagem e um palindromo!" << endl;
    } else {
        cout << "A mensagem nao e um palindromo." << endl;
    }
    
    return 0;
}
