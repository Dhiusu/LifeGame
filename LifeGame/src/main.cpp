#ifndef _MAIN_H
#define _MAIN_H

#include <iostream>
#include <unistd.h>
#include <string.h>

#include "./other_library/singleton/singleton.hpp"
#include "life_game.hpp"

using namespace std;

unsigned int microseconds = 10000; // wait ms.
unsigned short kMaxCell = 64;

/**
* 初期化
*/
void Init(LifeGame& game)
{

  // マス数を設定（64*64）
  game.SetCells(kMaxCell);

  // 生きているセル座標を設定（[0, 0], [1, 2]）
  // TODO: とりあえず、ランダムで生きているセルを設定
  game.SetAliveCellsForRandom(kMaxCell, 150);
  game.OutputCells();
  cout << "ALIVE CELL COUNT :" << game.GetAliveCellCount() << endl;
  // エンジンにルールを設定

}

/**
* 終了処理
*/
void finalize() {

  // シングルトオブジェクトの解放
  SingletonFinalizer::finalize();

}

int main(void) {

  // ライフゲームエンジンの生成
  LifeGame& game = singleton<LifeGame>::get_instance();

  // 初期化処理
  Init(game);

  // 入力値（文字列）
  //string input;

  // 無限ループ（"quit"で処理を終了）
  while(/*!strncmp(cin, "quit", 4)*/true) {

    // ゲーム更新
    game.Update();

    // スリープ
    usleep(microseconds);

  }

  // 終了メッセージ出力
  cout << "ゲームを終了します" << endl;

  // 終了処理
  finalize();

  // return
  return 0;

}

#endif // _MAIN_H
