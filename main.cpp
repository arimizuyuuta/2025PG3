#include <iostream>
using namespace std;

class Enemy {
public:
    void Update();

    void Approach(); // 接近
    void Attack();   // 攻撃
    void Retreat();  // 離脱

    // 関数ポインタテーブル
    static void (Enemy::* stateTable[])();

private:
    int index = 0;
};

// 各状態の関数定義
void Enemy::Approach() {
    cout << "敵が接近！" << endl;
}

void Enemy::Attack() {
    cout << "敵が攻撃！" << endl;
}

void Enemy::Retreat() {
    cout << "敵が離脱！" << endl;
}

void Enemy::Update() {
    // 現在の状態を実行
    (this->*stateTable[index])();

    cout << "次の状態に移行しますか？ (0: はい、 他: いいえ): ";
    int input;
    cin >> input;

    if (input == 0) {
        index = (index + 1) % 3;
    }
}

// メンバ関数ポインタテーブル
void (Enemy::* Enemy::stateTable[])() = {
    &Enemy::Approach,
    &Enemy::Attack,
    &Enemy::Retreat
};

int main() {
    Enemy enemy;
    while (1) enemy.Update();
    return 0;
}
