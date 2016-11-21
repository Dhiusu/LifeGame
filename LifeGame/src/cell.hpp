#ifndef _CELL_H
#define _CELL_H

#include <iostream>
using namespace std;

// 座標構造体
struct Point2D
{
  int x,y;
};

// セル（生命体）
class Cell
{

public:

  Cell(const int x, const int y);
  ~Cell();

  void set_is_alive(bool is_alive);
  bool is_alive();

  Point2D get_point(); 

private:

  // 生死フラグ
  bool m_is_alive;

  // 座標
  Point2D point;

};

#endif // _CELL_H
