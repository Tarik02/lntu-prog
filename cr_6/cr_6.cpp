/**********************************************************/
/*                                                        */
/*  cr_6                                                  */
/*  Мова: C++                                             */
/*                                                        */
/*  Задано текст, слова якого розділені пробілами.        */
/* Переставити слова тексту так, щоб останнє слово стало  */
/* першим, передостаннє - другим і т. д.                  */
/*                                                        */
/**********************************************************/

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> words;
vector<string> suffs;

bool is_word_ch(char c); // Функція для перевірки чи символ є частиною слова

void read_data(); // Функція для зчитування вхідних даних

void swap_words(); // Функція переставляння слів

void write_results(); // Функція для виводу результатів

int main() {
	read_data();

	swap_words();

	write_results();

	return 0;
}

// Функція для перевірки чи символ є частиною слова
bool is_word_ch(char c) {
	return (
		(c >= 'a' && c <= 'z') ||
		(c >= 'A' && c <= 'Z') ||
		(c >= '0' && c <= '9')
	);
}

// Функція для зчитування вхідних даних
void read_data() {
	cout << "Введіть вхідний текст. Для того, щоб закінчити введення тексту, введіть дві порожні стрічки." << endl;

	string line, suff, word;
	bool last_empty = false;

	while (true) {
		getline(cin, line);

		if (line.empty()) {
			if (last_empty) {
				break;
			}

			last_empty = true;
			continue;
		}

		line += "\n";

		if (last_empty) {
			line = "\n" + line;
			last_empty = false;
		}

		for (int i = 0, c = line.size(); i <= c; ++i) {
			if (is_word_ch(line[i])) {
				word += line[i];
			} else {
				if (!word.empty()) {
					suffs.push_back(suff);
					words.push_back(word);
					suff.clear();
					word.clear();
				}
				suff += line[i];
			}
		}

		if (!word.empty()) {
			suffs.push_back(suff);
			words.push_back(word);
			suff.clear();
			word.clear();
		}
	}

	suffs.push_back(suff);
}

// Функція переставляння слів
void swap_words() {
	reverse(words.begin(), words.end());
}

// Функція для виводу результатів
void write_results() {
	cout << "Вихідний текст:" << endl;

	int c = words.size();

	for (int i = 0; i < c; ++i) {
		cout << suffs[i] << words[i];
	}

	cout << suffs[c];
}
