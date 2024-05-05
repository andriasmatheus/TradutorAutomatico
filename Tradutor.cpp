#include <cstdlib>
#include <iostream>
#include <windows.h>

using namespace std;


string vetorLinguas[] = {"en", "es"};

DWORD WINAPI minha_funcao(LPVOID lpParam) {
    string linguagem = *reinterpret_cast<string*>(lpParam); // Convertendo LPVOID para string

    // Concatenando a string corretamente
    string script = "python FazATraducao.py " + linguagem;
    system(script.c_str()); // Executando o comando usando system()

    return 0;
}

int main(int argc, char* argv[]) {

    DWORD ThreadId;
    HANDLE ThreadHandle;
    int Param;

    for(int i = 0 ; i < 2; ++i)
    {
        string argumentos = argv[1] + vetorLinguas[i];
        /* cria o thread*/
        ThreadHandle = CreateThread(
        NULL, /* atributos default de segurança */
        0, /* tamanho default de pilha */
        minha_funcao, /* função do thread */
        &argumentos, /* parâmetro para a função do thread */
        0, /* flags default de criação */
        &ThreadId); /* retorna o identificador do thread */

        if (ThreadHandle != NULL) {
        /* agora espera que o thread seja encerrado */
        WaitForSingleObject(ThreadHandle,INFINITE);
        /* fecha o manipulador do thread */
        CloseHandle(ThreadHandle);
        }
    }

    return 0;
}
