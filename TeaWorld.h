#pragma once
#include "TWE.h"

void Countdown(char CountFiller, char FieldFiller, int count) {
	switch(count) {
	case 3:
		FillMainField(FieldFiller);
		CreateObject(10, 12, 2, 6, CountFiller);
		CreateObject(10, 11, 3, 3, FieldFiller);
		CreateObject(10, 11, 5, 5, FieldFiller);
		CreateText(4, 8, "'A' 'D' TO MOVE");
		CreateText(6, 9, "'Q' TO PAUSE");
		break;
	case 2:
		FillMainField(FieldFiller);
		CreateObject(10, 12, 2, 6, CountFiller);
		CreateObject(10, 11, 3, 3, FieldFiller);
		CreateObject(11, 12, 5, 5, FieldFiller);
		CreateText(4, 8, "'A' 'D' TO MOVE");
		CreateText(6, 9, "'Q' TO PAUSE");
		break;
	case 1:
		FillMainField(FieldFiller);
		CreateObject(11, 11, 2, 6, CountFiller);
		CreateText(4, 8, "'A' 'D' TO MOVE");
		CreateText(6, 9, "'Q' TO PAUSE");
		break;
	case 0:
		FillMainField(FieldFiller);
		CreateObject(10, 12, 2, 6, CountFiller);
		CreateObject(11, 11, 3, 5, FieldFiller);
		CreateText(4, 8, "'A' 'D' TO MOVE");
		CreateText(6, 9, "'Q' TO PAUSE");
		break;
	}
}

void PrintGame(char FieldFiller, char Filler, int Score, int Combo) {
	char ScoreChar[8];
	sprintf(ScoreChar, "%07d", Score);

	char ComboChar[6];
	sprintf(ComboChar, "%05d", Combo);

	FillMainField(FieldFiller);
	CreateObject(7, 9, 1, 9, Filler);
	CreateText(11, 1, "SCORE:");
	CreateText(11, 2, ScoreChar);
	CreateText(11, 4, "COMBO:");
	CreateText(11, 5, ComboChar);
}

void PrintMainMenu(int ButtonPos, int BestScore) {
	char BestScoreChar[8];
	sprintf(BestScoreChar, "%07d", BestScore);

	FillMainField(' ');
	CreateText(6, 1, "-TEA WORLD-");
	CreateText(1, 2, "BEST SCORE:");
	CreateText(13, 2, BestScoreChar);
	CreateText(7, 4, "START");
	CreateText(7, 5, "BUILD WORLD");
	CreateText(7, 6, "ABOUT");
	CreateText(7, 7, "EXIT");
	CreateText(1, 9, "'W' 'S' TO MOVE");
	CreateText(1, 10, "'ENTER' TO SELECT");
	CreateObject(6, 6, ButtonPos+3, ButtonPos+3, '>');
}

void PrintPauseMenu(char FieldFiller, int ButtonPos, int Score, int BestScore) {
	char ScoreChar[8];
	sprintf(ScoreChar, "%07d", Score);

	char BestScoreChar[8];
	sprintf(BestScoreChar, "%07d", BestScore);

	FillMainField(FieldFiller);
	CreateText(8, 1, "-PAUSE-");
	CreateText(1, 3, "SCORE:");
	CreateText(8, 3, ScoreChar);
	CreateText(1, 4, "BEST:");
	CreateText(8, 4, BestScoreChar);
	CreateText(7, 6, "CONTINUE");
	CreateText(7, 7, "RESTART");
	CreateText(7, 8, "TO MENU");
	CreateObject(6, 6, ButtonPos+5, ButtonPos+5, '>');
}

void PrintIntrodusion() {
	FillMainField(' ');
	CreateObject(3, 5, 1, 1, '#');
	CreateObject(2, 2, 2, 4, '#');
	CreateObject(6, 6, 2, 4, '#');
	CreateObject(4, 4, 3, 7, '#');
	CreateObject(4, 6, 7, 7, '#');
	CreateObject(12, 18, 2, 2, '#');
	CreateObject(20, 20, 2, 7, '#');
	CreateObject(16, 18, 4, 4, '#');
	CreateObject(15, 18, 7, 7, '#');
	CreateObject(16, 16, 2, 7, '#');
	CreateObject(14, 14, 2, 6, '#');
	CreateObject(13, 13, 7, 7, '#');
	CreateObject(12, 12, 4, 6, '#');
	CreateText(1, 9, "MADE WITH TWE1");
	CreateText(1, 10, "BY CYBERLOCKED");
}

void PrintTeaWorld(char Filler, int WorldFiller) {
	FillMainField(Filler);
	CreateObject(1, 10, 10 - WorldFiller, 10, '#');
	CreateObject(1, 3, 1, 1, Filler);
	CreateObject(8, 10, 1, 1, Filler);
	CreateObject(1, 3, 10, 10, Filler);
	CreateObject(8, 10, 10, 10, Filler);
	CreateObject(1, 1, 1, 3, Filler);
	CreateObject(1, 1, 8, 10, Filler);
	CreateObject(10, 10, 1, 3, Filler);
	CreateObject(10, 10, 8, 10, Filler);

	CreateText(11, 10, "\'Q\' TO QUIT");
}

void PrintPlayer(int PlayerPos, char FieldFiller) {
	CreateObject(7, 9, 10, 10, FieldFiller);
	CreateObject(PlayerPos+6, PlayerPos+6, 10, 10, 'U');
}

void PrintAbout() {
	printf("TEAWORLD IS AN TEST PROJECT\n");
	printf("MADE WITH MICROENGINE \"TWE1\"\n\n");

	printf("IN THIS GAME YOU NEED TO COLLECT\n");
	printf("TEA LEAFS (\'9\' & \'6\')\n");
	printf("TEA LEAFS WILL RISE YOUR SCORE\n");
	printf("SCORE IS NEDDED FOR BUILDING WORLD\n");
	printf("YOU NEED 1000000000 LEAFS TO BUILD WORLD\n\n");

	printf("/'Q/' TO QUIT TO MAIN MENU");
}

int GetSavedScoreCount() {
	int Output;
	Output = TWReadFile("BestScore.txt");

	return Output;
}

int GetSavedTotalScore() {
	int Output;
	Output = TWReadFile("TotalScore.txt");

	return Output;
}

int SaveScoreCount(int Score) {
	int BestScore = GetSavedScoreCount();
	if(BestScore >= Score) {
		return 0;
	}
	else if(BestScore < Score) {
		char ScoreChar[8];
		sprintf(ScoreChar, "%07d", Score);

		TWWriteFile("BestScore.txt", ScoreChar);
		return 0;
	}
}

void SaveTotalScore(int AddScore) {
	int TotalScore = GetSavedTotalScore();
	TotalScore += AddScore;
	char TotalScoreChar[11];

	sprintf(TotalScoreChar, "%d", TotalScore);
	TWWriteFile("TotalScore.txt", TotalScoreChar);
}