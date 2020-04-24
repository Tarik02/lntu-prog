/**********************************************************/
/*                                                        */
/*  m3_3                                                  */
/*  Мова: C++                                             */
/*                                                        */
/*  Дано стрічку символів.                                */
/*  Завдання: визначити довжину найкоротшого слова.       */
/*                                                        */
/**********************************************************/

#include <iostream>
#include <cmath>

using namespace std;

char *read_data(int &n); // Функція для зчитування вхідних даних

bool is_word_part(char c); // Функція для перевірки чи символ є частиною слова

pair<int, int> find_shortest_word(const char *s, int n); // Функція для пошуку найкоротшого слова

void write_results(const char *s, int n, pair<int, int> w); // Функція для виводу результатів

int main() {
	int n;
	char *s = read_data(n);

	pair<int, int> shortest_word_pos = find_shortest_word(s, n);

	write_results(s, n, shortest_word_pos);

	return 0;
}

// Функція для зчитування вхідних даних
char *read_data(int &n) {
	cout << "Введіть текст та натисніть Enter:" << endl;

	char *s = new char[1];
	n = 0;

	char chunk[32];
	do {
		cin.clear();
		cin.getline(chunk, sizeof(chunk));

		int l = strlen(chunk);
		char *newS = new char[n + l + 1];
		memcpy(newS, s, n);
		memcpy(newS + n, chunk, l);
		delete[] s;
		s = newS;
		n += l;
	} while (!cin);

	s[n] = '\0';

	return s;
}

// Функція для перевірки чи символ є частиною слова
bool is_word_part(char c) {
	return (
		(c >= 'a' && c <= 'z') ||
		(c >= 'A' && c <= 'Z') ||
		(c >= '0' && c <= '9')
	);
}

// Функція для пошуку найкоротшого слова
pair<int, int> find_shortest_word(const char *s, int n) {
	pair<int, int> best = make_pair(0, -1);

	int start = 0, length = 0;

	for (int i = 0; i < n + 1; ++i) {
		if (is_word_part(*(s + i))) {
			++length;
		} else {
			if (length != 0 && (best.second == -1 || length < best.second)) {
				best = make_pair(start, length);
			}
			start = i + 1;
			length = 0;
		}
	}

	return best;
}

// Функція для виводу результатів
void write_results(const char *s, int n, pair<int, int> w) {
	cout << endl;
	cout << "Найкоротше слово: позиція - " << w.first << ", довжина - " << w.second << endl;
	cout << endl;

	cout << s << endl;

	for (int i = 0; i < w.first; ++i) {
		cout << ' ';
	}
	for (int i = 0; i < w.second; ++i) {
		cout << '^';
	}
	cout << endl;
}
