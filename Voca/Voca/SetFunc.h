#pragma once

class Voca;

void gotoxy(int x, int y);
void SetConsoleView();
void PrintMain();
void make_random(int* random, int start, int end);
void make_voca(Voca& v);
void read_voca(std::vector<Voca>& voca_in, std::ifstream& fin);