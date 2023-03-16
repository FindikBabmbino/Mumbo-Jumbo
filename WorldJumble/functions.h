#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<iostream>
#include <string>
#include<ctime>

const int ARRAY_SIZE = 136;

bool ContinuePlaying();
void ExplainRulesOfTheGame();
void GameLoop();
void PressEnterToContinue();

std::string GetAnswer();
std::string GetRandomWord();
std::string GenerateJumbledWord(std::string originalWord);
std::string* GetWordArray();

bool CheckAnswer(std::string compareWord, std::string answerToCheck);


#endif 