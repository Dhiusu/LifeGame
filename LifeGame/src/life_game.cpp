
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
      Cell cell;
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

void LifeGame::Update()
{
  cout << "..." << endl;
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

}
