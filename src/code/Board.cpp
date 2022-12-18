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
                case Corridor: //CORRIDOR //0
                    cells[i].push_back(Cell({cell_width*i+cell_width/2, cell_width*j+cell_width/2}, cell_width, cell_width, Corridor));
                    break;
                case Crate: //CRATE //1
                    cells[i].push_back(Cell({cell_width*i+cell_width/2, cell_width*j+cell_width/2}, cell_width, cell_width, Crate));
                    break;
                case Target: //TARGET //2
                    targets.push_back(Point{i,j}); //TODO VOIR POUR LES POINTS
                    cells[i].push_back(Cell({cell_width*i+cell_width/2, cell_width*j+cell_width/2}, cell_width, cell_width, Corridor)); // 40, 40 = taille des cellules
                case Wall: //WALL //3
                    cells[i].push_back(Cell({cell_width*i+cell_width/2, cell_width*j+cell_width/2}, cell_width, cell_width, Wall));
                    break;
                case Player: //PLAYER //4
                    cells[i].push_back(Cell({cell_width*i+cell_width/2, cell_width*j+cell_width/2}, cell_width, cell_width, Player));
                    player = {i,j};
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
