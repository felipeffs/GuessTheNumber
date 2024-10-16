#include <iostream>
#include <Windows.h>
#include <chrono>
#include <thread>
#include "GuessTheNumber.h"

int main()
{
	InitialConfiguration();

	while (true) {
		ShowStartScreen();

		PlayGameLoop();

		ShowEndScreen();
	}
}

void InitialConfiguration()
{
	SetConsoleOutputCP(CP_UTF8);
}

void PlayGameLoop()
{
	int guesses = 1;
	int guess;

	int sortedNumber = GetRandomNumber();

	while (true) {

		guesses++;

		PlayBeep();
		std::cout << "Tentativa: ";
		std::cin >> guess;

		system("cls");
		PlayBeep();

		if (guess == sortedNumber) {
			break;
		}
		else if (guess < sortedNumber)
			std::cout << "O numero é maior que " << guess << "!" << std::endl;
		else
			std::cout << "O numero é menor que " << guess << "!" << std::endl;
	}

	system("cls");

	std::cout << "Você adivinhou!!! O numero era " << sortedNumber << "!!" << std::endl;
	std::cout << "Foram " << guesses << " tentativas." << std::endl;
}

void ShowStartScreen()
{
	std::cout << "====== GUESS THE NUMBER ==========" << std::endl;
	std::cout << "Tente advinhar o numero sorteado de 1 a 100 em menos tentativas conseguir." << std::endl;
	std::cout << "Calma, a cada tentativa mostrara se o numero é maior ou menor que o numero tentado." << std::endl;
	std::cout << "Quando tiver pronto pressione ENTER!" << std::endl;
	std::cin.get();
	PlayBeep();

	system("cls");

	std::cout << "Boa sorte!" << std::endl;
	PlayBeep();

	WaitASecond();

	system("cls");

	WaitASecond();
}

void ShowEndScreen()
{
	std::cout << "=====Pressione ENTER para voltar a tela inicial=======" << std::endl;
	std::cin.ignore(1, '\n');
	std::cin.get();
	PlayBeep();
	system("cls");
}

void WaitASecond()
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

int GetRandomNumber()
{
	unsigned int seed = time(0);
	srand(seed);
	return rand() % 100;
}

void PlayBeep()
{
	Beep(750, 200);
}

