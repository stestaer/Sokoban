//
// Created by sacha on 10-11-22.
//

#include "Board.h"

Board::Board(const std::string &level): level{level}
{
    loadBoard(level);
    //setBlockedState(); //TODO implémenter setBlockedState(), méthode qui rend les murs non-bougeables et
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

void Board::changeTypes(Cell &c1, Cell&c2){
    CellType tmp = c1.getCellType();
    c1.setCellType(c2.getCellType());
    c2.setCellType(tmp);
}


bool Board::solved()
{
    for (Point &t: targets) {
        if (cells[t.y][t.x].getCellType() != Crate)
            return false;
    }
    return true;
}

bool Board::allBlocked()
{
    for (std::vector<Cell> &v: cells)
    {
        for(Cell &c: v)
        {
            if(c.getCellType() == Crate && !c.isBlocked())
                return false;
        }
    }
    return true;
}

bool Board::checkMove(Point &direction)
{
    if( 0 < player.x+direction.x < cols &&
        0 < player.y+direction.y < rows &&
        !cells[player.y+direction.y][player.x+direction.x].isBlocked())
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
    std::ifstream input_file(text_file);
    input_file >> rows >> cols;
    int tmp;
    for (int i = 0; i < rows; i++)
    {
        cells.push_back(std::vector<Cell>());
        for (int j = 0; j < cols; j++)
        {
            input_file >> tmp;
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
                    cells[i][j].toggleBlocked();
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
    input_file.close();
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
