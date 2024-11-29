#include <iostream>
#include <fstream>
#include "turingmachine.h"
#include "program.h"

int main (int argc, char* argv[])
{
	if (argc != 4)
	{
		return 1;
	}

	// считываем программу машины Тьюринга.
	std::ifstream inFile(argv[1]);
	if (!inFile)
	{
		return 2;
	}

	program prog;
	command X;
	
	inFile >> X;
	prog.set_st(X.get_status ());
	prog.insert (X);

	while (inFile.peek () != EOF)
	{
		inFile >> X;
		prog.insert (X);
	}

	inFile.close();

	// считываем данные для работы.
	inFile.open(argv[2]);

	int length;
	int maxsteps;
	std::string init;

	inFile >> length >> maxsteps >> init;
	inFile.close();

	// записываем в файл результат.
	std::ofstream outFile(argv[3]);
	if (!outFile)
	{
		return 3;
	}

	TuringMachine MT (prog, length);
	outFile << MT.calc (init, maxsteps);

	outFile.close();

	return 0;
}