#include <iostream>
int main()
{
int times;
char ch;
std::cout << "enter the charcter: ";
std::cin >> ch;
while (ch != 'q')
{
	std::cout << "enter the integer: ";
	std::cin >> times;
	n_chars(ch, times);

}
