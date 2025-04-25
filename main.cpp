#include<stdio.h>
template<typename T>

T Min(T a, T b) {
	if (a > b) {
		return b;
	}
	else
	{
		return a;
	}
}
template <>
char Min<char>(char a, char b) {

	printf( "数字以外は代入できません");
	return 0;
}
int main() {
	

	printf("%d\n",Min<int>(100,200));
	printf("%f\n", Min<float>(3.3f, 2.2));
	printf("%lf\n", Min<double>(100.2, 123.4));
	printf("%c\n", Min<char>('A','B'));
		return 0;
}