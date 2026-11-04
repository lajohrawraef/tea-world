# Introduction

This is a game project that I worked on back in 2022 when I was 15. I think the first release version of this project was ready in a month or so. I also tried working on some updates at that point, specifically some version 1.2, for which I don't think I have any files since it was never released.

The theme of the game was based on something of an inside joke, where I had a group chat with my friends titled "Tea-sippers" (a very crude translation), because we liked tea.

At the time, I intended it to be a game engine or at least used to develop my further projects.

The game is still available on Game Jolt at [https://gamejolt.com/games/cl96-tw1/722436], it is free and the downloaded archive file has the exact same source code included.

# Overview

The program was developed as a console application for Windows.

I made it a short while after learning the basics of programming in C, so a lot it's not really good in terms of implementations. (Yes, the source code is a C++ file, but the code is still written in C)

It starts with a five-second "animation" displaying the logo for the "Tea World Engine", a source code file which I, at that point, intended to be its own game engine. It shows the main menu right afterwards.

Controls are done via keyboard keys: WASD, Q, and Enter.

In the main game you play as a cup, moving between three lines and trying to collect tea leaves. Collecting each without missing any will increase your combo score, which will give you a bonus to gained score from each collected leaf. Missing a single leaf will reset the combo score.

The "about" screen simply displays some information about the game.

The "build world" screen displays your overall pogress in the game.

The goal of the game is to collect 1 billion tea leaves. (really not sure why I went with a number that high. You should be able to edit the created `TotalScoe.txt` file to cheat the score in)

the game creates two files to store its data:
- `BestScore.txt` stores best score
- `TotalScore.txt` stores total score

# Documentation

The code is written in C.

The game is compiled from three source code files:
- TeaWorld.cpp
- TeaWorld.h
- TWE.h (Tea World Engine)

Again, I wrote it when I was 15, hence, the there are a lot of grammatical errors in comments and some identifiers, the code is full of redundancies or unthought/obsolete implementations.

I am not going to edit the code to make it better neither will I write any new comments to explain it better in source files simply for the sake of preserving this project as it was written. I will probably make either a branch of this repository to rewrite the code.

## TWE.h

Against the proper rules of C, this header declares a ton of global variables, which it shouldn't do.

The game uses "draw fields" to output user interface elements, specifically it declares a "main field" for visual output, which is a statically allocated two-dimensional array of characters. Any further mention of "drawing" refers to setting character values in that buffer.

`IntrodusionHasBeenMade` - a flag that determines whether the menu was alread shown

`MainFieldWidth` - drawing field width
`MainFieldHeight` - drawing field height
`MainFieldArray` - drawing field buffer

`OldTime` - stores previous instance of `GlobalTime`
`GlobalTime` - current time, specifically the second counter (can only be between 0 and 59)

`PrintHello()` - testing procedure that outpuse "Hello Teaworld!" into the console

`FillMainField()` - fills the Field buffer with a given character
`CreateObject()` - "draws" a rectangle of characters in the Field buffer
`CreateText()` - writes text in the Field buffer
`PrintMainField()` - outputs the Field buffer, one line at a time

`GetKey()` - checks whether a certain key is pressed

`TimeInSeconds()` - returns current local time, specifically the seconds only
`TimeIsChanged()` - checks "delta time" by checking the difference for old and current time in seconds

`TWWriteFile()` - opens/creates a file for writing and writes a given array of characters
`TWReadFile()` - opens a file for reading and uses fscanf, which only returns the stored first word

`RandomNumber()` - returns a random number in range from 0 to specified value

`PrintIntrodusion()` - prints the introduction five-second "animation" with creator credentials

## TeaWorld.h

`Countdown()` - draws numbers as a countdown before the game starts
`PrintGame()` - draws the scoreboard with the current score and combo
`PrintMainMenu()` - draws the main menu with the active button position
`PrintPauseMenu()` - prints pause menu with current and best score
`PrintIntrodusion()` - just does the same thing as the one in TWE.h? I think?
`PrintTeaWorld()` - draws the "world"
`PrintPlayer()` - draws a symbol at a given position
`PrintAbout()` - just prints the about text to the console

`GetSavedScoreCount()` - is used to read the stored score value from BestScore.txt
`GetSavedTotalScore()` - works the same as the former, except from TotalScore.txt
`SaveScoreCount()` - reads BestScore.txt, saves score to BestScore.txt if it is a new best
`SaveTotalScore()` - reads score from TotalScore.txt, adds the new score, and stores it back

## TeaWorld.cpp

`LeafChar` - char filler to draw leaves
`LeafRot` - determines the rotation state of leaves
`timebeforegame` - stores the amount of time before the game starts
`RandLeafPos` - stores random number for `RandomateLeaf`

`RandomateLeaf()` - randomises the line that the leaf is on
`RotateLeaf()` - changes leaf filler character between '9' and '6'
`CreateLeaf()` - uses `CreateObject` to draw a leaf

`GameCicle()` - the main game cycle, which updates the screen, takes input, shows pause menu, etc.

`BuildTeaWorldCicle()` - displays the "world" and progress percentage based on total score.
`AboutCicle()` - displays the about page until Q is pressed
`MainMenuCicle()` - displays score and menu options, checks inputs and current selection

`main()` - displays intro and begins a main loop swapping between states for the main game, about screen, and the build world screen

# Sentiment

As I already mentioned, the game was developed in 2022 back when I was 15. It has been 5 years since and I have learned a lot more about programming, computer science, and software developed.
At the time, I was really excited to finally finish it and publish it on gamejolt.

I would like to remake the project to either improve the source code or to create proper visuals.

Tt is still interesting to look back at my ambitions for my projects and my knowledge over software development at the time. I have since learned so much more.
