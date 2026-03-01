#include <iostream>
#include <string>
#include <random>
#include <cstdio>   
#include <cstdlib>  

void limpiarTerminal()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Borra archivo temporal si existe
void borrarTemp(const std::string& ruta) 
{
    std::remove(ruta.c_str());
}

std::string generarContrasena(int longitud) 
{
    std::string caracteres =
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789"
        "!\"#$%&'()*+,-./"
        ":;<=>?@"
        "[\\]^_`"
        "{|}~";

    static std::random_device rd;
    static std::mt19937 generador(rd());
    std::uniform_int_distribution<> distribucion(0, caracteres.size() - 1);

    std::string contrasena;
    for (int i = 0; i < longitud; i++) 
    {
        contrasena += caracteres[distribucion(generador)];
    }
    return contrasena;
}

int main() 
{
    const int LONGITUD = 25;

    
#ifdef _WIN32
    std::string tempFile = "C:\\Windows\\Temp\\password_tmp.txt";
#else
    std::string tempFile = "/tmp/password_tmp.txt";
#endif

    std::string entrada;

    while (true) {
        borrarTemp(tempFile);   // Borra temp si existe
        limpiarTerminal();      // Limpia pantalla

        std::cout << "=== Generador de Contraseñas ===\n\n";
        std::cout << "Contraseña generada:\n\n";
        std::cout << generarContrasena(LONGITUD) << "\n\n";

        std::cout << "ENTER = otra | q + ENTER = salir\n";
        std::getline(std::cin, entrada);

        if (entrada == "q" || entrada == "Q") 
        {
            borrarTemp(tempFile);
            limpiarTerminal();
            break;
        }
    }

    return 0;
}