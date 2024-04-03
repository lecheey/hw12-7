#include <iostream>
#include <string>
#include "BMH_Algorithm.h"

bool IsKPeriodic(std::string& str, int k){
	int len = str.length(); // длина строки	
	
	if(len == 0){ // строка не может быть нулевой
		std::cout << "Пустая строка" << std::endl;
		return false;
	}
	if(len == k || k == 1){ // строка кратна величине своей длины или 1
		return true;
	}
	if(len % k != 0){ // проверка кратности длины строки k
		std::cout << "Неверный размер строки" << std::endl;
		return false;
	}

	// проверка образа с помощью алгоритма Бойера-Мура-Хорспула

	std::string pat = str.substr(0, k);	
	for(int i = k; i < (len - k); i += k){ // проверка совпадения начала подстрок
		if(str[i] == pat[0]){
			std::string temp = str.substr(i, k);
			if(!search(temp, pat)){
				return false;
			}
		}
		else{ return false; }
	}
	return true;

	// или наивный поиск
/*
	int a = k; // переменная начала следующей подстроки (отступ на k)
	for(int i = 0; i < (len - k); i += k){ // проверка совпадения начала подстрок
		if(str[i] == str[a]){
			for(int j = i + 1; j < k; j++){ // проверка оставшихся элементов подстрок
				if(str[j] != str[j + k]){
					break;
				}
			}
			a += k; // переход к следующей подстроке
		}uuuuuu

		else{ return false; }
	}
	return true;
*/

}

int main(){
	std::string a;
	int K;
	
//	a = "abcabcabcabcabcabcabcabc"; // для проверки
//	K = 3;
	
	std::cout << "Введите символы строки: ";
	std::cin >> a;
	std::cout << "Введите число для проверки на кратность: ";
	std::cin >>K;

	std::string b = IsKPeriodic(a, K) ? "Строка кратна " : "Строка не кратна ";
	std::cout << b << K << std::endl;
	return 0;
}
