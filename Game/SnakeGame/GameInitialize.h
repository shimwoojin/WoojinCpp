//GameInitialize.h

#pragma once

const int MAPWIDTH = 30;
const int MAPHEIGHT = 25;

void SetConsoleView();

void CursorView();

void SetTextColor(char);

void gotoxy(int x, int y);

void make_random(int* random, int start, int end);

void print_map();