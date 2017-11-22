#ifndef JUDGE_H
#define JUDGE_H

#include <vector>
#include <algorithm>

const int TEXT_LENGTH_MAX=100;

void Judge(char *_name,std::vector<bool> *tests_results);

bool Compare_files(char *first_filename,char *second_filename);

bool Compare(char *first,char *second);

#endif // JUDGE_H
