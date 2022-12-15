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


Bool Board::solved()
{
    for (auto const &t: targets) {

    }
}

Bool Board::allBlocked()
{

}


void Board::loadBoard(const std::string &text_file)
{
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
                    cells[i].push_back(Cell({50*i+25, 50*j+25},40,40, Corridor));
                    break;
                case Crate: //CRATE //1
                    cells[i].push_back(Cell({50*i+25, 50*j+25},40,40, Crate));
                    break;
                case Target: //TARGET //2
                    targets.push_back(Point{i,j});
                    cells[i].push_back(Cell({50*i+25, 50*j+25},40,40), Target);
                case Wall: //WALL //3
                    cells[i].push_back(Cell({50*i+25, 50*j+25}, 40, 40, Wall));
                    break;
                case Player: //PLAYER //4
                    cells[i].push_back(Cell({50*i+25, 50*j+25},40,40), Player);
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
//TODO faire que le print marche du moins !!!
void Board::printBoard(void)
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            std::cout << cells[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
