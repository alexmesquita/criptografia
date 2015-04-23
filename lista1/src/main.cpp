#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "calculator_gf_256.h"
#include "des.h"
#include "extended_euclidean.h"

using namespace std;

void load_des()
{
    int option = 0;
    Des des;
    string text = "", key = "";

    system("clear");
    
    cout << "1 - Cifrar" << endl;
    cout << "2 - Decifrar" << endl;
    cout << "Escolha uma opcao: ";

    cin >> option;

    switch(option)
    {
        case 1:
            cout << "Insira o texto em claro:" << endl;
            cin >> text;
            cout << "Insira a chave:" << endl;
            cin >> key;

            cout << "O texto cifrado e: " << endl;
            cout << des.cipher(text, key) << endl;
            break;
        case 2:
            cout << "Insira o texto cifrado:" << endl;
            cin >> text;
            cout << "Insira a chave:" << endl;
            cin >> key;

            cout << "O texto em claro e: " << endl;
            cout << des.decipher(text, key);
            break;
        default:
            cout << "opcao invalida" << endl;
    }
    cin.get();
    cin.get();
}

void load_multiplicative_inverse()
{
    long long a, b;
    ExtendedEuclidean ee;
    system("clear");
    cout << "Insira o valor de A: ";
    cin >> a;
    cout << "Insira o valor de B: ";
    cin >> b;

    cout << "O inverso multiplicativo de " << a << " mod " << b << " e: " << ee.multiplicative_inverse(a, b) << endl;

    cin.get();
    cin.get();
}

void load_calculator()
{
    int option = 0;
    string a = "", b = "";

    system("clear");
    
    cout << "1 - Soma" << endl;
    cout << "2 - Subtracao" << endl;
    cout << "3 - Multiplicacao" << endl;
    cout << "4 - Divisao" << endl;
    cout << "Escolha uma opcao: ";

    cin >> option;

    system("clear");

    cout << "Insira o polinomio A: " << endl;
    cin >> a;
    cout << "Insira o polinomio B: " << endl;
    cin >> b; 

    CalculatorGF256 calc;

    switch(option)
    {
        case 1:
            cout << a << " + " << b << " = " << calc.sum(a, b) << endl;
            break;
        case 2:
            cout << a << " - " << b << " = " << calc.subtraction(a, b) << endl;
            break;
        case 3:
            cout << a << " * " << b << " = " << calc.multiplication_mod(a, b) << endl;
            break;
        case 4:
            cout << a << " / " << b << " = " << calc.division(a, b) << endl;
            break;
        default:
            cout << "opcao invalida" << endl;
    }
    cin.get();
    cin.get();
}

bool load_menu()
{
    bool quit = false;
    int option = 0;
    system("clear");
    
    cout << "1 - DES" << endl;
    cout << "2 - Inverso multiplicativo" << endl;
    cout << "3 - Calculadora GF(2" << char(94) << "8)" << endl;
    cout << "4 - Sair" << endl;
    cout << "Escolha uma opcao: ";

    cin >> option;

    switch(option)
    {
        case 1:
            load_des();
            break;
        case 2:
            load_multiplicative_inverse();
            break;
        case 3:
            load_calculator();
            break;
        case 4:
            quit = true;
            break;
        default:
            cout << "opcao invalida" << endl;
            cin.get();
            cin.get();
            break;
    }

    return quit;
}


int main()
{

    bool quit = false;

    while(!quit)
    {
        quit = load_menu();
    }
    
    return 0;
}
