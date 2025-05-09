#include<stdio.h>
#include<Windows.h>
#include <time.h>
#include <functional>


//コールバック関数
void DispResult(int* s, int* kye) {
	int dice = rand() % 2;

	if (dice == *kye) {
		if (dice == 0)
			printf("%dで丁(偶数)でした。当たり", dice);
		else
			printf("%dで半(奇数)でした。当たり", dice);
	}
	else {
		if (dice == 1)
			printf("%dで半(奇数)でした。はずれ", dice);
		else
			printf("%dで丁(偶数)でした。はずれ", dice);
	}

}

void setTimeout(std::function<void(int*, int*)>p, int second, int kye) {
	//コールバック関数を呼び出す
	for (int i = 0; i < second; i++) {
		Sleep(1000);
		printf("%d...\n", second - i);
	}


	p(&second, &kye);
}

int main() {

	int kye;

	srand(static_cast<unsigned int>(time(NULL)));
	printf("丁(偶数)なら0、半(奇数)なら1を打つ\n");
	scanf_s("%d", &kye);

	if (kye == 0) {
		puts("あなたは丁(偶数)を選びました");
	}
	else {
		puts("あなたは半(奇数)を選びました");
	}

	std::function</*int型のポインタ2つを引数にもらい返り値なしの関数の型*/>p =
		[](int* s, int* kye) {DispResult(s, kye); };
	setTimeout(p, 3, kye);

	return 0;
};
