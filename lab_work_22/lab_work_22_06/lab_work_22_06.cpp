/***********************************************************/
/*                                                         */
/*  lab_work_22_06                                         */
/*  Мова: C++                                              */
/*                                                         */
/*  Дано стрічку s1. Слова у цій стрічці розділені одним   */
/* пробілом.                                               */
/*  Для вводу різних варіантів стрічки s1 скласти          */
/* нескінченний цик, вихід з якого відбувається тоді, коли */
/* стрічка s1 буде порожньою.                              */
/*   Визначити кiлькість слiв у заданiй стрiчцi та         */
/* надрукувати їх.                                         */
/*                                                         */
/***********************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Функція для перевірки чи символ є частиною слова
bool is_word_ch(char c) {
	return (
		(c >= 'a' && c <= 'z') ||
		(c >= 'A' && c <= 'Z') ||
		(c >= '0' && c <= '9')
	);
}

int main() {
	while (true) {
		string line;

		cout << "Введіть стрічку. Для того, щоб завершити роботу програми, введіть порожню стрічку." << endl << "  ";

		getline(cin, line);

		if (line.empty()) {
			break;
		}

		string word;
		vector<pair<int, string>> words;
		
		int i = 0, start = 0;
		for (char c : line) {
			++i;

			if (is_word_ch(c)) {
				word += c;
			} else {
				if (!word.empty()) {
					words.push_back(make_pair(start, word));
					word.clear();
				}
				start = i + 1;
			}
		}

		if (!word.empty()) {
			words.push_back(make_pair(start, word));
		}

		cout << "  Кількість слів у стрічці: " << words.size() << endl;
		cout << "  Слова:" << endl;
		for (const pair<int, string> &s : words) {
			cout << "    Слово: \"" << s.second << "\"; початок: " << s.first << "; довжина: " << s.second.size() << "." << endl;
		}
	}

	return 0;
}
