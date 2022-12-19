//
// Created by sacha on 10-11-22.
//

#include "Board.h"

Board::Board(const std::string &level)
{
    if(!level.empty())
        loadBoard(level);
}

Board::~Board() {}

int Board::getHeight()
{
    return h;
}

int Board::getWidth()
{
    return w;
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
    //TODO faire
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
    input_file >> h >> w;
    int tmp;
    for (int i = 0; i < h; i++)
    {
        cells.push_back(std::vector<Cell>());
        for (int j = 0; j < w; j++)
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
                    targets.push_back(Point{i,j}); //TODO VOIR POUR LES POINTS
                    cells[i].push_back(Cell({cell_width*i+cell_width/2, cell_width*j+cell_width/2}, cell_width, cell_width, Corridor));
                    break;
                case Wall: //3
                    cells[i].push_back(Cell({cell_width*i+cell_width/2, cell_width*j+cell_width/2}, cell_width, cell_width, Wall));
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
            //cells[i].push_back(tmp);
        }
    }
    input_file.close();
}

void Board::printBoard(void)
    //TODO faire que le print marche du moins !!!
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            std::cout << cells[i][j].getCellType() << " ";
        }
        std::cout << std::endl;
    }
}
