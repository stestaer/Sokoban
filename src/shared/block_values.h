//
// Created by sacha on 10-11-22.
//
#ifndef F202_BLOCK_VALUES_H
#define F202_BLOCK_VALUES_H

#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>

enum CellType { Corridor, Crate, Target, Wall, Player, CrateOnTarget, PlayerOnTarget };

enum GameState { Lost, Won, Playing };

const Fl_Color wall_color = fl_rgb_color(165,165,165);

const Fl_Color crate_Color = fl_rgb_color(165,42,42);

const Fl_Color corridor_color = fl_rgb_color(255,255,255);

const Fl_Color player_color = FL_RED;

const Fl_Color crate_on_target_color = fl_rgb_color(184, 134, 11);

const Fl_Color target_color = fl_rgb_color(253, 253, 150);


const int cell_width = 50;

const int y_gap = cell_width;

const int player_radius = cell_width/2-(cell_width/10);

#endif //F202_BLOCK_VALUES_H
