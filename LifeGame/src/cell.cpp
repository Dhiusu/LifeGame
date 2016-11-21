#include "cell.hpp"

Cell::Cell()
{
    m_is_alive = false;
}

Cell::~Cell()
{

}

void Cell::set_is_alive(bool is_alive)
{
    m_is_alive = is_alive;
}

bool Cell::is_alive()
{
    return m_is_alive;
}