#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <functional>


void DispResult(int* _, int* kye) {
    int dice = rand() % 6 + 1; 

    if (dice % 2 == *kye) {
        if (*kye == 0)
            printf("%dで丁(偶数)でした。当たり\n", dice);
        else
            printf("%dで半(奇数)でした。当たり\n", dice);
    }
    else {
        if (*kye == 1)
            printf("%dで丁(偶数)でした。はずれ\n", dice);
        else
            printf("%dで半(奇数)でした。はずれ\n", dice);
    }
}


void setTimeout(std::function<void(int*, int*)> p, int second, int kye) {
    for (int i = 0; i < second; i++) {
        Sleep(1000);
        printf("%d...\n", second - i);
    }
    p(&second, &kye);
}

int main() {
    int kye;

    srand(static_cast<unsigned int>(time(NULL)));
    printf("丁(偶数)なら0、半(奇数)なら1を打つ: ");
    scanf_s("%d", &kye);

    if (kye == 0) {
        puts("あなたは丁(偶数)を選びました");
    }
    else {
        puts("あなたは半(奇数)を選びました");
    }

    
    auto p = [&kye](int* s, int* dummy) {
        DispResult(s,&kye);
        };

    setTimeout(p, 3, kye);

    return 0;
}

