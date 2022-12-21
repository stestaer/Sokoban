//
// Created by sacha on 10-11-22.
//

#include "Board.h"

Board::Board(const std::string &level): level{level}
{
    loadBoard(level);
    updateBlockedStatus();
}

Board::~Board() {}

int Board::getHeight()
{
    return rows;
}

int Board::getWidth()
{
    return cols;
}

Point Board::getPlayer()
{
    return player;
}

void Board::saveSteps()
{
    stepsRecord = std::min(stepsRecord, currentSteps);
    std::ofstream record_file(LEVELS_DICT[level]);
    record_file << stepsRecord;
    record_file.close();
}

Cell& Board::getCell(Point cell)
{
    return cells[cell.y][cell.x];
}

void Board::changeTypes(Cell &c1, Cell &c2){
    CellType tmp = c1.getCellType();
    c1.setCellType(c2.getCellType());
    c2.setCellType(tmp);
}


bool Board::solved()
{
    for (Point &t: targets)
    {
        if (cells[t.y][t.x].getCellType() != Crate)
            return false;
    }
    changeState(Won);
    saveSteps();
    return true;
}

bool Board::isBlocked(Point& position)
{
    if ((getCell(position+UP).isBlocked() && getCell(position+LEFT).isBlocked() ) ||
        (getCell(position+LEFT).isBlocked() && getCell(position+DOWN).isBlocked())||
        (getCell(position+DOWN).isBlocked() && getCell(position+RIGHT).isBlocked())||
        (getCell(position+RIGHT).isBlocked() && getCell(position+UP).isBlocked()))
    {
        getCell(position).setBlocked();
        return true;
    }
    else
    {
        getCell(position).setUnblocked();
        return false;
    }
}

bool Board::allBlocked()
{
    for (Point &c: crates)
    {
        if(!isBlocked(c))
            return false; //TODO, peut etre possible d'utiliser le c.isBlocked() pour faire moins de checking sur le blocked
    }
    return true;
}

bool Board::updateBlockedStatus()
{
    crates.clear();
    for (int y =0; y<rows; y++)
    {
        for (int x =0; x<rows; x++)
        {
            if (cells[y][x].getCellType() == Crate)
                crates.push_back({y, x});
        }
    }
    if (allBlocked())
        changeState(Lost);
    return gameState == Lost;
}

bool Board::checkPlayerMove(Point &direction)
{
    if( 0 < player.x+direction.x < cols &&
        0 < player.y+direction.y < rows &&
        !getCell(player+direction).isBlocked())
        return true;
    return false;
}

std::vector<std::vector<Cell>>& Board::getCells()
{
    return cells;
}

std::vector<Point>& Board::getTargets()
{
    return targets;
}


void Board::loadBoard(const std::string &text_file)
{
    cells.clear();
    crates.clear();
    level = text_file;
    std::ifstream level_file(level);
    level_file >> rows >> cols;
    int tmp;
    for (int i = 0; i < rows; i++)
    {
        cells.push_back(std::vector<Cell>());
        for (int j = 0; j < cols; j++)
        {
            level_file >> tmp;
            switch (tmp) {
                case Corridor: //0
                    cells[i].push_back(Cell({cell_width*i+cell_width/2, cell_width*j+cell_width/2}, cell_width, cell_width, Corridor));
                    break;
                case Crate: //1
                    cells[i].push_back(Cell({cell_width*i+cell_width/2, cell_width*j+cell_width/2}, cell_width, cell_width, Crate));
                    break;
                case Target: //2
                    targets.push_back(Point{i,j});
                    cells[i].push_back(Cell({cell_width*i+cell_width/2, cell_width*j+cell_width/2}, cell_width, cell_width, Corridor));
                    break;
                case Wall: //3
                    cells[i].push_back(Cell({cell_width*i+cell_width/2, cell_width*j+cell_width/2}, cell_width, cell_width, Wall));
                    cells[i][j].setBlocked();
                    break;
                case Player: //4
                    cells[i].push_back(Cell({cell_width*i+cell_width/2, cell_width*j+cell_width/2}, cell_width, cell_width, Player));
                    player = {i,j};
                    break;
                case CrateOnTarget: //5
                    targets.push_back(Point{i,j});
                    cells[i].push_back(Cell({cell_width*i+cell_width/2, cell_width*j+cell_width/2}, cell_width, cell_width, Crate));
                    break;
                case PlayerOnTarget: //6
                    targets.push_back(Point{i,j});
                    cells[i].push_back(Cell({cell_width*i+cell_width/2, cell_width*j+cell_width/2}, cell_width, cell_width, Player));
                    break;
                default:
                    break;

            }
        }
    }
    level_file.close();

    std::ifstream record_file(LEVELS_DICT[level]);
    record_file >> stepsRecord;
    std::cout << stepsRecord<< std::endl;
    record_file.close();
}

void Board::loadBoard()
{
    loadBoard(level);
}

void Board::printBoard(void)

{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << cells[i][j].getCellType() << " ";
        }
        std::cout << std::endl;
    }
}
