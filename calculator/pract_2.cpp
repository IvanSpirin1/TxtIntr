#include <iostream>
#include <string>
#include <vector>
#include <getopt.h>
#include <cmath>

using namespace std;

double summa(vector<double> operands) {
	double result = 0;
	for (double operand : operands)
	{
		result+=operand;
	}
	return result;
}

double difference(vector<double> operands) {
	double result = operands[0];
	for(auto i=1U; i<operands.size(); i++)
	{
		result-=operands[i];
	}
	return result;
}

void printHelp() {
   cout << "Использование: ./pract_2 -o [операция] [операнды]" << endl;
   cout << "Опции:" << endl;
   cout << " -o операция задает операцию (summa или difference)" << endl;
   cout << " -h Вывести справку" << endl;
   cout << "Операнды:" << endl;
   cout << "От 2 до 4 операндов" << endl;
   }

int main(int argc, char* argv[]) {
	int option;
	string operation;
	vector<double> operands;
    while ((option = getopt(argc, argv, "o:h")) != -1) {
	 switch (option) {
	 	case 'o':
	 		operation = optarg;
	 		break;
	 	case 'h':
	 		printHelp();
	 		return 0;
	 	default:
	 		cout << "Неизвестная опция" << endl;
	 		return 1;
	 } 
    } 
    
    for(int i=optind; i<argc; ++i)
	{
		double operand=stod(argv[i]);
		operands.push_back(operand);
	}
	
    if (operation.empty() || operands.size()<2) {
		cout << "Недостаточно параметров" << endl;
		return 1;
	}
	if (operands.size()>4) {
		cout << "Много параметров" << endl;
		return 1;
	}
    double result;
    if (operation == "summa") {
		result = summa(operands);
    } else if (operation == "difference") {
		result = difference(operands);
    } else {
		cout <<"Неизвестная операция" <<endl;
		return 1;
    }
    cout << "Результат: " << result << endl;
	return 0;
}
