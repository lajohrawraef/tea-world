#include "TeaWorld.h"

char LeafChar = '9';
bool LeafRot = false;
int timebeforegame = 5;
int RandLeafPos = 0;

int main();

int RandomateLeaf() {
	int LeafPosX = 0;

	RandLeafPos = RandomNumber(RandLeafPos, 300);
	if(RandLeafPos < 100) {
		LeafPosX = 1;
	}
	else if(RandLeafPos > 10 && RandLeafPos < 200) {
		LeafPosX = 2;
	}
	else if(RandLeafPos > 200) {
		LeafPosX = 3;
	}

	return LeafPosX;
}

void RotateLeaf() {
	if(LeafRot) {
		LeafChar = '6';
		LeafRot = false;
	}
	else {
		LeafChar = '9';
		LeafRot = true;
	}
}

void CreateLeaf(int PosX, int PosY) {
	CreateObject(PosX+6, PosX+6, PosY, PosY, LeafChar);
}

int GameCicle() {
	int Score = 0;
	int Combo = 0;
	int TotalTimeInGame = 0;
	int PlayerPos = 1;
	int count = 3;
	int ButtonPos = 1;
	int LeafPos1 = -2; // 12
	int LeafPosX1 = RandomateLeaf();
	int LeafPos2 = -20; // 6
	int LeafPosX2 = RandomateLeaf();
	int LeafPos3 = -34; // 4
	int LeafPosX3 = RandomateLeaf();
	int LeafPos4 = -43; // 7
	int LeafPosX4 = RandomateLeaf();
	int LeafPos5 = -59; // 3
	int LeafPosX5 = RandomateLeaf();
	int LeafPos6 = -73; // 1
	int LeafPosX6 = RandomateLeaf();
	int LeafPos7 = -77; // 9
	int LeafPosX7 = RandomateLeaf();
	int LeafPos8 = -88; // 10
	int LeafPosX8 = RandomateLeaf();
	int LeafPos9 = -108; // 2
	int LeafPosX9 = RandomateLeaf();
	int LeafPos10 = -117; // 5
	int LeafPosX10 = RandomateLeaf();
	int LeafPos11 = -123; // 11
	int LeafPosX12 = RandomateLeaf();
	int LeafPos12 = -138; // 8
	int LeafPosX11 = RandomateLeaf();

	int BestScore = GetSavedScoreCount();

	while(1) {
		if(count > -1 && count != 4) {
			if(TimeIsChanged()) {
				system("cls");
				Countdown('#', ' ', count);
				PrintMainField();
				count--;
			}
		}
		if(count <= -1){
			if(TimeIsChanged()) {
				TotalTimeInGame++;

				RotateLeaf();
				if(LeafPos1 >= 9) {
					if(PlayerPos == LeafPosX1) {
						Combo += 1;
						Score += 10 + Combo;
					}
					else {
						Combo = 0;
					}

					LeafPos1 = -2;
					LeafPosX1 = RandomateLeaf();
				}
				else {
					LeafPos1++;
				}
				
				if(LeafPos2 >= 9) {
					if(PlayerPos == LeafPosX2) {
						Combo += 1;
						Score += 10 + Combo;
					}
					else {
						Combo = 0;
					}

					LeafPos2 = -2;
					LeafPosX2 = RandomateLeaf();
				}
				else {
					LeafPos2++;
				}

				if(LeafPos3 >= 9) {
					if(PlayerPos == LeafPosX3) {
						Combo += 1;
						Score += 10 + Combo;
					}
					else {
						Combo = 0;
					}

					LeafPos3 = -2;
					LeafPosX3 = RandomateLeaf();
				}
				else {
					LeafPos3++;
				}

				if(LeafPos4 >= 9) {
					if(PlayerPos == LeafPosX4) {
						Combo += 1;
						Score += 10 + Combo;
					}
					else {
						Combo = 0;
					}

					LeafPos4 = -2;
					LeafPosX4 = RandomateLeaf();
				}
				else {
					LeafPos4++;
				}

				if(LeafPos5 >= 9) {
					if(PlayerPos == LeafPosX5) {
						Combo += 1;
						Score += 10 + Combo;
					}
					else {
						Combo = 0;
					}

					LeafPos5 = -2;
					LeafPosX5 = RandomateLeaf();
				}
				else {
					LeafPos5++;
				}

				if(LeafPos6 >= 9) {
					if(PlayerPos == LeafPosX6) {
						Combo += 1;
						Score += 10 + Combo;
					}
					else {
						Combo = 0;
					}

					LeafPos6 = -2;
					LeafPosX6 = RandomateLeaf();
				}
				else {
					LeafPos6++;
				}

				if(LeafPos7 >= 9) {
					if(PlayerPos == LeafPosX7) {
						Combo += 1;
						Score += 10 + Combo;
					}
					else {
						Combo = 0;
					}

					LeafPos7 = -2;
					LeafPosX7 = RandomateLeaf();
				}
				else {
					LeafPos7++;
				}

				if(LeafPos8 >= 9) {
					if(PlayerPos == LeafPosX8) {
						Combo += 1;
						Score += 10 + Combo;
					}
					else {
						Combo = 0;
					}

					LeafPos8 = -2;
					LeafPosX8 = RandomateLeaf();
				}
				else {
					LeafPos8++;
				}

				if(LeafPos9 >= 9) {
					if(PlayerPos == LeafPosX9) {
						Combo += 1;
						Score += 10 + Combo;
					}
					else {
						Combo = 0;
					}

					LeafPos9 = -2;
					LeafPosX9 = RandomateLeaf();
				}
				else {
					LeafPos9++;
				}

				if(LeafPos10 >= 9) {
					if(PlayerPos == LeafPosX10) {
						Combo += 1;
						Score += 10 + Combo;
					}
					else {
						Combo = 0;
					}

					LeafPos10 = -2;
					LeafPosX10 = RandomateLeaf();
				}
				else {
					LeafPos10++;
				}

				if(LeafPos11 >= 9) {
					if(PlayerPos == LeafPosX11) {
						Combo += 1;
						Score += 10 + Combo;
					}
					else {
						Combo = 0;
					}

					LeafPos11 = -2;
					LeafPosX11 = RandomateLeaf();
				}
				else {
					LeafPos11++;
				}

				if(LeafPos12 >= 9) {
					if(PlayerPos == LeafPosX12) {
						Combo += 1;
						Score += 10 + Combo;
					}
					else {
						Combo = 0;
					}

					LeafPos12 = -2;
					LeafPosX12 = RandomateLeaf();
				}
				else {
					LeafPos12++;
				}

				if(Score > 9999999) {
					Score -= 9999999;
				}
				if(Combo > 99999) {
					Combo--;
				}
				
				system("cls");
				PrintGame(' ', '.', Score, Combo);
				PrintPlayer(PlayerPos, ' ');

				CreateLeaf(LeafPosX1, LeafPos1);
				CreateLeaf(LeafPosX2, LeafPos2);
				CreateLeaf(LeafPosX3, LeafPos3);
				CreateLeaf(LeafPosX4, LeafPos4);
				CreateLeaf(LeafPosX5, LeafPos5);
				CreateLeaf(LeafPosX6, LeafPos6);
				CreateLeaf(LeafPosX7, LeafPos7);
				CreateLeaf(LeafPosX8, LeafPos8);
				CreateLeaf(LeafPosX9, LeafPos9);
				CreateLeaf(LeafPosX10, LeafPos10);
				CreateLeaf(LeafPosX11, LeafPos11);
				CreateLeaf(LeafPosX12, LeafPos12);

				PrintMainField();
			}
			if(GetKey('A') && PlayerPos > 1) {
				PlayerPos--;
				system("cls");
				PrintPlayer(PlayerPos, ' ');
				PrintMainField();
			}
			if(GetKey('D') && PlayerPos < 3) {
				PlayerPos++;
				system("cls");
				PrintPlayer(PlayerPos, ' ');
				PrintMainField();
			}
			if(GetKey('Q')) {
				count = 4;
			}
		}
		if(count == 4) {
			if(TimeIsChanged()) {
				system("cls");
				PrintPauseMenu(' ', ButtonPos, Score, BestScore);
				PrintMainField();
			}
			if(GetKey('W') && ButtonPos > 1) {
				ButtonPos--;
				system("cls");
				PrintPauseMenu(' ', ButtonPos, Score, BestScore);
				PrintMainField();
			}
			if(GetKey('S') && ButtonPos < 3) {
				ButtonPos++;
				system("cls");
				PrintPauseMenu(' ', ButtonPos, Score, BestScore);
				PrintMainField();
			}
			if(GetKey(13)) {
				switch(ButtonPos) {
				case 1:
					count = 3;
					break;
				case 2:
					SaveScoreCount(Score);
					SaveTotalScore(Score);
					GameCicle();
					return 0;
				case 3:
					LeafPos1 = 0;
					SaveScoreCount(Score);
					SaveTotalScore(Score);
					main();
					return 0;
				}
			}
		}
	}
}

int BuildTeaWorldCicle() {
	int TotalScore = GetSavedTotalScore();
	int count1 = 0;
	int count2 = 0;
	int worldcount = 0;
	char count1char[4];
	char count2char[3];

	worldcount = TotalScore/100000000;

	while(TotalScore >= 100000) {
		count1++;
		TotalScore -= 100000;
	}
	while(TotalScore >= 1000) {
		count2++;
		TotalScore -= 1000;
	}

	sprintf(count1char, "%03d", count1);
	sprintf(count2char, "%02d", count2);

	while(!GetKey('Q')) {
		if(TimeIsChanged()) {
			system("cls");
			PrintTeaWorld(' ', worldcount-1);
			CreateText(13, 2, count1char);
			CreateText(16, 2, ".");
			CreateText(17, 2, count2char);
			CreateText(19, 2, "%");
			PrintMainField();
		}
	}
	main();
	return 0;
}

int AboutCicle() {
	system("cls");
	PrintAbout();

	while(1) {
		if(GetKey('Q')) {
			main();
			return 0;
		}
	}
}

int MainMenuCicle() {
	int BestScore = GetSavedScoreCount();
	int ButtonPos = 1;
	system("cls");
	PrintMainMenu(ButtonPos, BestScore);
	PrintMainField();
	while(1) {
		if(GetKey('W') && ButtonPos > 1) {
			ButtonPos--;
			system("cls");
			PrintMainMenu(ButtonPos, BestScore);
			PrintMainField();
		}
		if(GetKey('S') && ButtonPos < 4) {
			ButtonPos++;
			system("cls");
			PrintMainMenu(ButtonPos, BestScore);
			PrintMainField();
		}
		if(GetKey(13)) {
			switch(ButtonPos) {
			case 1:
				RandomateLeaf();
				return 1;
			case 2:
				return 2;
			case 3:
				return 3;
			case 4:
				return 0;
			}
		}
	}
}

int main() {
	MainFieldWidth = 21;
	MainFieldHeight = 10;

	PrintIntrodusion("CYBERLOCKED96");

	switch(MainMenuCicle()) {
	case 1:
		GameCicle(); 
		break;
	case 2:
		BuildTeaWorldCicle();
		break;
	case 3:
		AboutCicle();
		break;
	case 0:
		return 0;
	}
	return 0;
}