
#include "life_game.hpp"
#include <random>

// LifeGame::LifeGame()
// {

// }

// LifeGame::~LifeGame()
// {

// }

//********************
// Common
//********************

Cell* LifeGame::GetCell(const int x, const int y)
{
  return &cells.at(y).at(x);
}

void LifeGame::SetAliveCellsForRandom(const int max_cells, const int alive_cnt)
{
  random_device rd;
  mt19937 mt(rd());
  uniform_int_distribution<int> range(0,max_cells-1);
  for(int i=0; i<alive_cnt; i++) {
    GetCell(range(mt), range(mt))->set_is_alive(true);
  }
}

void LifeGame::OutputCells()
{
  cout << "/*** CELLS ***" << endl;

  const int row_size = cells.size();
  int col_size = 0;
  for(int row=0; row<row_size; row++)
  {
    col_size = cells.at(row).size();
    for(int col=0; col<col_size; col++)
    {
      cout << "[" << col << ", " << row << "] ";
      if(GetCell(col, row)->is_alive())
      {
        cout << "ALIVE" << endl;
      }
      else
      {
        cout << "DEATH" << endl;
      }
    }
  }

  cout << "*** CELLS ***/" << endl;
}

int LifeGame::GetAliveCellCount()
{
  int cnt = 0;
  const int row_size = cells.size();
  int col_size = 0;
  for(int row=0; row<row_size; row++)
  {
    col_size = cells.at(row).size();
    for(int col=0; col<col_size; col++)
    {
      if(GetCell(col, row)->is_alive()) cnt++; 
    }
  }

  return cnt;
}

//********************
//　Setter
//********************

void LifeGame::SetCells(const int max_cells)
{

  cells.clear();
  for(int row=0; row<max_cells; row++)
  {
    vector<Cell> cols;
    for(int col=0; col<max_cells; col++)
    {
      Cell cell(col, row);
      cols.push_back(cell);
    }
    cells.push_back(cols);
  }

  cout << cells.size() <<  endl;

}

/*
void AddRules(const ICondition)
{
  con
}
*/

//********************
//　状態
//********************

void LifeGame::Condition()
{

  const int size = cells.size();
  for(int i=0; i<size; i++)
  {
    for(int j=0; j<size; j++)
    {
      Cell* p = &cells.at(i).at(j);
      ConditionA(p);
      ConditionB(p);
      ConditionC(p);
      ConditionD(p);
    }
  }
}

// １、死んでいるマス目に隣接する生きたマス目がちょうど3つあれば、次のターンに生きているマス目が誕生する。
void LifeGame::ConditionA(Cell* cell)
{
  const Point2D point = cell->get_point();
  const int x = point.x;
  const int y = point.y;
  int alive_cnt = 0;

  if((y-1) >= 0 && cells.at(y-1).at(x).is_alive()) {
    ++alive_cnt;
  }

  if((y+1) < cells.size() && cells.at(y+1).at(x).is_alive()) {
    ++alive_cnt;
  }

  if((x-1) >= 0 && cells.at(y).at(x-1).is_alive()) {
    ++alive_cnt;
  }

  if((x+1) < cells.size() && cells.at(y).at(x+1).is_alive()) {
    ++alive_cnt;
  }

  if(alive_cnt == 3)
  {
    // 生きているマス目を誕生
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> range(0,cells.size()-1);
    GetCell(range(mt), range(mt))->set_is_alive(true);
  }
}

// ２、生きているマス目に隣接する生きたマス目が2つか3つならば、次のターンでも生存する。
void LifeGame::ConditionB(Cell* cell)
{
}

// ３、生きているマス目に隣接する生きたマス目が1つ以下ならば、次のターンで過疎により死滅する。
void LifeGame::ConditionC(Cell* cell)
{
}

// ４、生きているマス目に隣接する生きたマス目が4つ以上ならば、次のターンで過密により死滅する。
void LifeGame::ConditionD(Cell* cell)
{
}

void LifeGame::Update()
{

  // ルールを適用
  Condition();

  // 描画
  const int size = cells.size();
  for(int i=0; i<size; i++)
  {
    for(int j=0; j<size; j++)
    {
      if(cells.at(i).at(j).is_alive()){
        cout << "■";
      }
      else
      {
        cout << "□";
      }
    }
    cout << endl;
  }
  cout << endl;
  cout << endl;
  cout << endl;

}
