/***********************************************************/
/*                                                         */
/*  lab_work_22_05                                         */
/*  Мова: C++                                              */
/*                                                         */
/*  Дано стрiчку s1[80]. Видiлити з неї пiдстрiчку s2, яка */
/* починається з позицiї n та мiстить n символiв. Для      */
/* вводу рiзних варiантiв стрiчки s1 скласти нескiнченний  */
/* цикл, вихiд з якого вiдбувається тодi, коли стрiчка s1  */
/* матиме вигляд "*****".                                  */
/*  Розробити пiдпрограму-функцiю для видiлення пiдстрiчки */
/* заданої довжини, починаючи iз заданої позицiї.          */
/*                                                         */
/***********************************************************/

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;


int substr(char *src, char *dest, int pos, int len);

int main() {
	char s1[80]; // s1 - стрiчка-джерело
	char s2[80]; // s2 - cтрiчка-результат
	int n, l, r; //n-позиція, l-довжина, r-параметр виведення

	while (true) {
		// Ввiд стрiчки s1:
		cout << "Введiть стрiчку-джерело s1:" << endl << "  ";
		cin.getline(s1, sizeof(s1));

		// Умова виходу з нескінченного циклу:
		if (strcmp(s1, "*****") == 0) {
			break;
		}

		// Введення позицiї pos i довжини len:
		cout << "  Введiть параметри pos та len:" << endl << "    ";
		cin >> n >> l;

		// Формування пiдстрiчки за допомогою пiдпрограми:
		r = substr(s1, s2, n, l);

		// Друк результатiв:
		cout << "  Стрiчка-джерело: s1 = " << s1 << endl;
		cout << "  Номер позицiї pos = " << n << " та довжина len = " << l << endl;
		cout << "  Стрiчка-результат: s2 = " << s2 << endl;
		cout << "  Параметр виведення r = " << r << endl;

		cout << endl;

		cin.get();
	}

	return 0;
}

/**
 * Видiлення пiдстрiчки заданої довжини, починаючи iз заданої позицiї.
 * 
 * Можливі результати роботи функції:
 *   0 - у випадку коректної роботи;
 *  -1 - стрічка dest має довжину, меншу за len;
 *  -2 - недопустимі значення параметрів pos або len;
 *
 * \param char *src  стрiчка-джерело.
 * \param char *dest стрiчка-результат.
 * \param int pos    позицiя, з якої видiляється пiдстрiчка-результат.
 * \param int len    задана довжина пiдстрiчки-результату.
 * \return код завершення
 */
int substr(char *src, char *dest, int pos, int len) {
	// Встановлення вказiвника src на позицiю pos:
	while (pos > 0 && *src != '\0') {
		++src;
		--pos;
	}

	// Перевiрка параметрiв pos та len на коректнiсть
	// та формування стрічки-результату у разі їх коректності:

	if (pos > 0 || len < 0) {
		return -2;
	}

	// Копiювання len символiв зi стрiчки src у стрiчку dest:
	while (len > 0 && *src != '\0') {
		--len;
		*dest = *src;
		++dest;
		++src;
	}

	*dest = '\0';

	if (len != 0) {
		return -1;
	}

	return 0;
}