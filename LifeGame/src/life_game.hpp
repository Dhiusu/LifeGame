#ifndef _LIFE_GAME_H
#define _LIFE_GAME_H

#include <iostream>
#include <vector>

#include "cell.hpp"

using namespace std;

// ライフゲームクラス
class LifeGame
{

private:

  // Cell配列
  vector<vector<Cell>> cells;

  // ルール
  //vector<ICondition>conditions;

  // コマンド
  //vector<Command>commands;

public:

  // LifeGame();
  // ~LifeGame();

  //********************
  // Common
  //********************
  Cell* GetCell(const int x, const int y);
  void SetAliveCellsForRandom(const int max_cells, const int alive_cnt);
  void OutputCells();
  int GetAliveCellCount();

  //********************
  //　Getter
  //********************

  //********************
  //　Setter
  //********************

  void SetCells(const int max_cells); // セルの設定
  void SetCell(const int x, const int y, const bool is_alive); // セル状態を設定

  //********************
  //　状態
  //********************

  //void Reset();
  void Update();

  //void AddRules(const ICondition);  // ルールの設定
  //void AddCommnad(const Command); // コマンド

private:



};

#endif // _LIFE_GAME_H
