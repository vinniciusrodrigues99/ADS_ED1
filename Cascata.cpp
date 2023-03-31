#include <iostream>
#include <string>
#include <unistd.h> // Biblioteca para usar a função usleep()

using namespace std;

int main() {
    // Lê a mensagem digitada pelo usuário
    string mensagem;
    cout << "Digite uma mensagem: ";
    getline(cin, mensagem);
    
    // Centraliza a mensagem na linha 5
    int largura_tela = 80; // Largura padrão da tela
    int tamanho_mensagem = mensagem.size();
    int espacos_lado_esquerdo = (largura_tela - tamanho_mensagem) / 2;
    for (int i = 0; i < espacos_lado_esquerdo; i++) {
        cout << " ";
    }
    cout << mensagem << endl;
    
    // "Cai" cada letra da mensagem até a linha 20
    for (int i = 0; i < tamanho_mensagem; i++) {
        for (int j = 0; j < espacos_lado_esquerdo; j++) {
            cout << " ";
        }
        for (int j = 0; j <= i; j++) {
            cout << mensagem[j];
        }
        cout << endl;
        usleep(100000); // Espera 0.1 segundo antes de imprimir a próxima linha
    }
    
    return 0;
}

