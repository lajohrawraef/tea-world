/*
Tea World Engine version 1.2
(version 1 is made for console projects)
*/

#pragma once
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

//Introdusion bool
bool IntrodusionHasBeenMade = false;

//Main output field properties
int MainFieldWidth;
int MainFieldHeight;
char MainFieldArray[36][36];

//Time for updating field output
int OldTime = 0;
int GlobalTime = 0;

//Testing
void PrintHello() {
	printf("Hello TeaWorld!\n");
}

//Fills main output field with char
void FillMainField(char Filler) {
	for(int y = 0; y < MainFieldHeight; y++) {
		for(int x = 0; x < MainFieldWidth; x++) {
			MainFieldArray[y][x] = Filler;
		}
		MainFieldArray[y][MainFieldWidth] = '\0';
	}
}

//Fills some part of main output field with char
int CreateObject(int PosX1, int PosX2, int PosY1, int PosY2, char Filler) {
	if(PosX1 > 0 && PosX2 > 0 && PosY1 > 0 && PosY2 > 0) {
		for(int y = PosY1-1; y < PosY2; y++) {
			for(int x = PosX1-1; x < PosX2; x++) {
				MainFieldArray[y][x] = Filler;
			}
		}
	}
	else {
		return 0;
	}
}

//Fills some part of main output with text
void CreateText(int PosX, int PosY, char FillerText[36]) {
	int textint = 0;
	for(int i = PosX-1; i < 36; i++) {
		if(FillerText[textint] != NULL) {
			MainFieldArray[PosY-1][i] = FillerText[textint];
			textint++;
		}
	}
}

//Outputs main field array
void PrintMainField() {
	for(int i = 0; i < MainFieldHeight; i++) {
		printf("%s\n", MainFieldArray[i]);
	}
}

//Gets pressed key and return true or false
bool GetKey(char KeyCode) {
	if (GetKeyState(KeyCode) < 0) {
		return true;
	}
	else {
		return false;
	}
}

//Gets time in seconds and returns it as integer
int TimeInSeconds() {
	struct tm tm;
	time_t now = time(0);
	localtime_s(&tm, &now);
	return tm.tm_sec;
}

//Returns true if one second has passed (also changes the 'OldTime' and 'GlobalTime' values)
bool TimeIsChanged() {
	struct tm tm;
	time_t now = time(0);
	localtime_s(&tm, &now);
	int timeis = tm.tm_sec;
	if(OldTime != timeis) {
		OldTime = timeis;
		GlobalTime++;
		return true;
	}
	else {
		return false;
	}
}

//Creates a file with text
void TWWriteFile(char FileName[32], char Input[256]) {
	FILE *f;
	fopen_s(&f, FileName, "w");
	fprintf_s(f, "%s", Input);
	fclose(f);
}

//Reads file text and returns it as integer
int TWReadFile(char FileName[32]){
	FILE *f;
	errno_t err;
	if((err = fopen_s(&f, FileName, "r")) != 0) {
		fopen_s(&f, FileName, "w");
		err = fclose(f);
		return 0;
	}
	else {
		int Output = 0;

		fscanf_s(f, "%d", &Output);
		err = fclose(f);

		return Output;
	}
}

//Returns random number
int RandomNumber(int Seed, int MaxValue) {
	int num = 0;
	srand(Seed);
	num = rand() % MaxValue;
	return num;
}

//Prints engine and creator (creator is optional)
int PrintIntrodusion(char Creator[31]) {
	if(IntrodusionHasBeenMade) {
		return 0;
	}
	else {
		int TimeForIntodusion = 5;
		MainFieldWidth = 20;
		MainFieldHeight = 11;

		while(TimeForIntodusion > 0) {
			if(TimeIsChanged()) {
				system("cls");
				FillMainField(' ');

				CreateObject(3, 5, 2, 2, '#');
				CreateObject(2, 2, 3, 5, '#');
				CreateObject(6, 6, 3, 5, '#');
				CreateObject(4, 4, 4, 8, '#');
				CreateObject(5, 6, 8, 8, '#');
				
				CreateObject(10, 17, 3, 3, '#');
				CreateObject(12, 12, 4, 7, '#');
				CreateObject(11, 11, 8, 8, '#');
				CreateObject(10, 10, 5, 7, '#');
				CreateObject(13, 17, 8, 8, '#');
				CreateObject(14, 14, 4, 7, '#');
				CreateObject(15, 17, 5, 5, '#');
				CreateObject(19, 19, 3, 8, '#');
			
				CreateText(1, 10, "MADE WITH TWE");
				CreateText(1, 11, "BY");
				CreateText(4, 11, Creator);
				
				PrintMainField();
				TimeForIntodusion--;
			}
		}
		IntrodusionHasBeenMade = true;
		return 0;
	}
}