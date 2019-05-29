#include <Windows.h>
#include <iostream>
#include <vector>
#include "Menu.h"
#include "Keyboard.h"
#include "Items.h"

using namespace std;

string repeat_text(string s, int n)
{
	string s1 = s;

	for (int i = 1; i < n; i++)
		s += s1;

	return s;
}


void DrawMenu()
{
	ItemsMenu();
	while (true)
	{
		system("cls");
		Hotkey();

		cout << " "; // Começar Fora do canto da tela
		for (int i = 0; i < 30; i++)
		{
			cout << "_"; // Escrever 30 x '_'
		}
		cout << "\n"; // Pular linha para Terminar de desenhar a caixa


		for (int i = 1; i < MenuFunctions.Items + 1; i ++) // Inicia o Desenho do Menu de acordo com o total de items
		{
			int Letter_counter = 0; // Conta quantas linhas obtem-se
			string str = MenuFunctions.Name[i]; // String atual do Menu
			for (int i = 0; str[i]; i++) 
				Letter_counter++; // Somatória que resultará no Total de Letras abordado pela string
			if (MenuFunctions.Index == i) // Caso A Opção do Menu  esteja marcada Desenha-se uma Setinha
			{
				cout << "| -> " << MenuFunctions.Name[i] << repeat_text(" ", (25 - Letter_counter)) << MenuFunctions.Variable[i] << "|\n"; // Desenho da Seta
				cout << "\n";
			}
			else
			{
				cout << "|    " << MenuFunctions.Name[i] << repeat_text(" ", (25 - Letter_counter)) << MenuFunctions.Variable[i] << "|\n"; // Caso não Esteja marcado, não desenha a seta
				cout << "\n";
			}
		}

		cout << " "; //  Quebra linhas para desenhar o fundo do Menu
		for (int i = 0; i < 30; i++)
		{
			cout << "_"; // Escrever 30 x '_'
		}
		Sleep(30); // Dar uma pausa para o programa não ficar piscando -:-
	}
}


int main()
{
	DrawMenu();
}
