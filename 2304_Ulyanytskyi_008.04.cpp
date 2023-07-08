#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

template <typename type>
type get_user_input() {
	type   input;
	cin >> input;
	return input;
}

class Special_Symbols {
protected:
	char symbol;
	int static counter;
	vector<char> symbols_eng;
	vector<char> symbols_ua;	

public:
	Special_Symbols() 
	{
		symbols_eng = { 'O', 'A', 'I', 'E', 'H', 'C', 'B', 'K', 'P', 'X', 'T', 'M' };
		symbols_ua  = { 'Î', 'À', '²', 'Å', 'Í', 'Ñ', 'Â', 'Ê', 'Ð', 'Õ', 'Ò', 'Ì' };
	}

	bool check_input_sumbol() 
	{
		for (int i = 0; i < symbols_eng.size(); ++i) 
		{
			if (symbol == symbols_ua[i] || symbol == symbols_eng[i])
				return true;
		}
		return false;
	}

	void set_symbol(char symbol) { this->symbol = symbol; }
	char get_symbol()			 { return symbol; }
	int  get_counter()			 { return counter; }

	bool operator==(const Special_Symbols& operand) 
	{
		int index_eng = 0;
		int index_ua  = 0;
		int array_size = symbols_eng.size();
		++counter;

		for (int i = 0; i < array_size; ++i) 
		{
			if (symbols_eng[i] == symbol || symbols_eng[i] == operand.symbol)
				index_eng = i;
			if (symbols_ua[i] == symbol || symbols_ua[i] == operand.symbol)
				index_ua = i;
		}

		if (symbol == operand.symbol)
			return true;

		return (index_eng == index_ua && index_eng != 0 && index_ua != 0);
	}

	bool operator != (const Special_Symbols& operand) 
	{
		return !(*this == operand);
	}
};

int Special_Symbols::counter = 0;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool exit_status = false;

	Special_Symbols symbol_1;
	Special_Symbols symbol_2;

	while (!exit_status) 
	{
		cout << "counter of chek: " << symbol_1.get_counter() / 2;
		cout << "\nType first char: ";
		symbol_1.set_symbol(get_user_input<char>());
		cout << "Type second char: ";
		symbol_2.set_symbol(get_user_input<char>());
		
		if (symbol_1.check_input_sumbol() && symbol_2.check_input_sumbol()) 
		{
			if (symbol_1 == symbol_2) 
			{
				cout << "\noperator ==\n";
				cout << symbol_1.get_symbol() << " and " << symbol_2.get_symbol();
				cout << " are equal\n";
			}
			if (symbol_1 != symbol_2) 
			{
				cout << "\noperator !=\n";
				cout << symbol_1.get_symbol() << " and " << symbol_2.get_symbol();
				cout << " are not equal\n";
			}
		}
		else if (symbol_1.get_symbol() == '0' || symbol_2.get_symbol() == '0') 
		{
			cout << "Exit";
			exit_status = true;
		}
		else 
		{
			cout << "Invalid input!\n";
		}
		cout << endl;
	}

	return 0;
}