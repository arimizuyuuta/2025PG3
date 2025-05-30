#include <stdio.h>
#include <list>
#include <iostream>

using namespace std;

int main(void) {
	// 初めは1970年の駅名リスト
	list<const char*> eki_list{
		"Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno", "Uguisudani",
		"Tabata", "Komagome", "Sugamo", "Otsuka", "Ikebukuro", "Mejiro", "Takadanobaba",
		"Sin-Okubo", "Shinjuku", "Yoyogi", "Harajuku", "Shibuya", "Ebisu", "Meguro",
		"Gotanda", "Osaki", "Sinagawa", "Tamachi", "Hamamatsucho", "Shimbashi", "Yurakucho"
	};

	//==== 1970年 ====
	printf("1970年\n");
	for (list<const char*>::iterator it = eki_list.begin(); it != eki_list.end(); ++it) {
		cout << *it << endl;
	}

	//==== 2019年 ====
	// 西日暮里をTabataの前に挿入
	list<const char*> eki_2019 = eki_list;
	for (list<const char*>::iterator it = eki_2019.begin(); it != eki_2019.end(); ++it) {
		if (strcmp(*it, "Tabata") == 0) {
			eki_2019.insert(it, "Nishi-Nippori");
			break;
		}
	}

	printf("\n2019年\n");
	for (list<const char*>::iterator it = eki_2019.begin(); it != eki_2019.end(); ++it) {
		cout << *it << endl;
	}

	//==== 2022年 ====
	// 高輪ゲートウェイをTamachiの前に挿入
	list<const char*> eki_2022 = eki_2019;
	for (list<const char*>::iterator it = eki_2022.begin(); it != eki_2022.end(); ++it) {
		if (strcmp(*it, "Tamachi") == 0) {
			eki_2022.insert(it, "Takanawa Gateway");
			break;
		}
	}

	printf("\n2022年\n");
	for (list<const char*>::iterator it = eki_2022.begin(); it != eki_2022.end(); ++it) {
		cout << *it << endl;
	}

	return 0;
}
