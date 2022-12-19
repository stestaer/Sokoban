//
// Created by sacha on 10-11-22.
//
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#pragma once

enum CellType { Corridor, Crate, Target, Wall, Player, CrateOnTarget, PlayerOnTarget };

const Fl_Color wall_color = fl_rgb_color(165,165,165);

const Fl_Color crate_Color = fl_rgb_color(165,42,42);

const Fl_Color corridor_color = fl_rgb_color(255,255,255);

const Fl_Color player_color = FL_RED;

const Fl_Color crate_on_target_color = fl_rgb_color(184, 134, 11);

const Fl_Color target_color = fl_rgb_color(253, 253, 150);

const int cell_width = 40;

const int player_radius = cell_width/2-(cell_width/10);