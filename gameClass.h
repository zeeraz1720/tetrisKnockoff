#pragma once
#include "boardClass.h"
#include "buttons.h"
#include "tetriminoClass.h"
#include <fstream>
#include <iostream>
#include <string.h>
#include <SFML/Graphics.hpp>

class Game {

public:

	void startGame() {

        Board gB;
        //gB.setSomeSq();

        sf::RenderWindow window(sf::VideoMode(800, 650), "Bootleg Tetris by Zeeshan Raza");

        // run the program as long as the window is open
        while (window.isOpen())
        {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window.pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            // clear the window with black color
            window.clear(sf::Color::Black);

            // draw everything here...
            //window.draw(gB.returnBg());
            gB.loadBoard(window);

            // end the current frame
            window.display();
        }

	}

    Tetrimino* createPiece(int pieceNo) {

        Tetrimino* piecePtr;

        if (pieceNo == 0) {
            piecePtr = new cyanLine();
        }
        else if (pieceNo == 1) {
            piecePtr = new blue_revL();
        }
        else if (pieceNo == 2) {
            piecePtr = new orangeL();
        }
        else if (pieceNo == 3) {
            piecePtr = new yellowSquare();
        }
        else if (pieceNo == 4) {
            piecePtr = new greenS();
        }
        else if (pieceNo == 5) {
            piecePtr = new purpleT();
        }
        else {
            piecePtr = new red_revS();
        }

        return piecePtr;

    }

    void testPieces() {

        int piecesNum[2];
        Tetrimino pieces[2];
        int pieceNo;

        for (int i = 0; i < 2; i++) {

            pieceNo = rand() % 7;
            piecesNum[i] = pieceNo;

            if (pieceNo == 0) {
                pieces[i] = cyanLine();
            }
            else if (pieceNo == 1) {
                pieces[i] = blue_revL();
            }
            else if (pieceNo == 1) {
                pieces[i] = orangeL();
            }
            else if (pieceNo == 1) {
                pieces[i] = yellowSquare();
            }
            else if (pieceNo == 1) {
                pieces[i] = greenS();
            }
            else if (pieceNo == 1) {
                pieces[i] = purpleT();
            }
            else {
                pieces[i] = red_revS();
            }

        }

        Board gB;

        sf::RenderWindow window(sf::VideoMode(800, 650), "Bootleg Tetris by Zeeshan Raza");

        // run the program as long as the window is open
        while (window.isOpen())
        {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window.pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window.close();

                // "key pressed" event: move the pieces based on the key presses
                if (event.type == sf::Event::EventType::KeyPressed) {

                    //pieces[0].movementInput(event);
                    pieces[0].movementInput(event);

                }

            }

            // clear the window with black color
            window.clear(sf::Color::Black);

            // draw everything here...
            gB.loadBoard(window);
            pieces[0].loadPiece(window);

            // end the current frame
            window.display();
        }
    }

    void testPieces_1() {

        srand(time(0));

        int gameWidth = 800;
        int gameHeight = 650;

        int lvl = 1;
        int totalScore = 0;
        int linesDeleted = 0;
        float fallTime = float(pow(0.9, (lvl - 1)));
        bool startGame = false;
        bool cantGoLower = false;
        bool lostTheGame = false;
        bool crossedLvl8 = false;
        bool WatB = false;

        int mousePos;

        string writtenName = "";
        string playerName = "Guest";

        sf::Clock clock;
        sf::Time elapsed;

        sf::Font gO_font1;
        gO_font1.loadFromFile("Robus-BWqOd.otf");

        sf::Font gO_font2;
        gO_font2.loadFromFile("BruceForeverRegular-X3jd2.ttf");

        sf::Texture titleScreen;
        sf::Texture endScreen;
        titleScreen.loadFromFile("tetrisTitleScreen.png");
        endScreen.loadFromFile("tetrisEndScreen.png");
        titleScreen.setSmooth(true);
        endScreen.setSmooth(true);

        sf::Text gO_text(sf::String("Game Over"), gO_font1, 200);
        gO_text.setPosition((gameWidth / 2) - 350, (gameHeight / 2) - 300);
        gO_text.setFillColor(sf::Color::White);

        sf::Text gO_text2(sf::String("Enter name here (to save highscore)\nTo keep the same name, leave blank"), gO_font2, 20);
        gO_text2.setPosition((gameWidth / 2) - 271, (gameHeight / 2) - 25);
        gO_text2.setFillColor(sf::Color::White);

        sf::Text gO_text3(sf::String("Press ENTER to start over"), gO_font2, 15);
        gO_text3.setPosition((gameWidth / 2) - 153, (gameHeight / 2) + 135);
        gO_text3.setFillColor(sf::Color::White);

        sf::Text gO_text4(sf::String("Press ESC to leave the game"), gO_font2, 10);
        gO_text4.setPosition((gameWidth / 2) - 113, (gameHeight / 2) + 160);
        gO_text4.setFillColor(sf::Color::White);

        sf::Text pSL0_1(sf::String("Next"), gO_font2, 25);
        sf::Text pSL0_2(sf::String("Piece"), gO_font2, 25);
        pSL0_1.setPosition((gameWidth / 2) + 20, (gameHeight / 2) - 218);
        pSL0_2.setPosition((gameWidth / 2) + 18, (gameHeight / 2) - 182);
        pSL0_1.setFillColor(sf::Color::White);
        pSL0_2.setFillColor(sf::Color::White);

        sf::Text pSL1(sf::String("Name:"), gO_font2, 25);
        sf::Text pSL2(sf::String("Score:"), gO_font2, 25);
        sf::Text pSL3(sf::String("Level:"), gO_font2, 25);
        sf::Text pSL4(sf::String("Lines:"), gO_font2, 25);
        pSL1.setPosition((gameWidth / 2) + 10, (gameHeight / 2) - 5);
        pSL2.setPosition((gameWidth / 2) + 10, (gameHeight / 2) + 85);
        pSL3.setPosition((gameWidth / 2) + 10, (gameHeight / 2) + 157);
        pSL4.setPosition((gameWidth / 2) + 10, (gameHeight / 2) + 230);
        pSL1.setFillColor(sf::Color::White); pSL2.setFillColor(sf::Color::White);
        pSL3.setFillColor(sf::Color::White); pSL4.setFillColor(sf::Color::White);

        sf::Text nameTxt(sf::String(playerName), gO_font2, 25);
        sf::Text scoreTxt(sf::String(to_string(totalScore)), gO_font2, 25);
        sf::Text lvlTxt(sf::String(to_string(lvl)), gO_font2, 25);
        sf::Text linesTxt(sf::String(to_string(linesDeleted)), gO_font2, 25);
        nameTxt.setPosition((gameWidth / 2) + 125, (gameHeight / 2) - 5);
        scoreTxt.setPosition((gameWidth / 2) + 135, (gameHeight / 2) + 85);
        lvlTxt.setPosition((gameWidth / 2) + 120, (gameHeight / 2) + 157);
        linesTxt.setPosition((gameWidth / 2) + 120, (gameHeight / 2) + 230);
        nameTxt.setFillColor(sf::Color::White); scoreTxt.setFillColor(sf::Color::White);
        lvlTxt.setFillColor(sf::Color::White); linesTxt.setFillColor(sf::Color::White);

        sf::Text writingText(sf::String(playerName), gO_font2, 30);
        writingText.setPosition(250.f, 550.f);
        writingText.setFillColor(sf::Color::White);

        sf::RectangleShape darkenEverything;
        darkenEverything.setSize(sf::Vector2f(gameWidth, gameHeight));
        darkenEverything.setFillColor(sf::Color::Black);

        sf::RectangleShape gO_nameSpace(sf::Vector2f(500.f, 60.f));
        gO_nameSpace.setOutlineThickness(5);
        gO_nameSpace.setPosition(sf::Vector2f(152.f, 377.f));
        gO_nameSpace.setFillColor(sf::Color::Black);
        gO_nameSpace.setOutlineColor(sf::Color::White);

        sf::RectangleShape nextPieceRect(sf::Vector2f(344.f, 194.f));
        nextPieceRect.setOutlineThickness(5);
        nextPieceRect.setPosition(sf::Vector2f(390.f, 48.f));
        nextPieceRect.setFillColor(sf::Color::Black);
        nextPieceRect.setOutlineColor(sf::Color::White);

        sf::RectangleShape nameRect(sf::Vector2f(340.f, 58.f));
        nameRect.setOutlineThickness(5);
        nameRect.setPosition(sf::Vector2f(392.f, 307.f));
        nameRect.setFillColor(sf::Color::Black);
        nameRect.setOutlineColor(sf::Color::White);

        sf::RectangleShape scoreRect(sf::Vector2f(340.f, 58.f));
        scoreRect.setOutlineThickness(5);
        scoreRect.setPosition(sf::Vector2f(392.f, 397.f));
        scoreRect.setFillColor(sf::Color::Black);
        scoreRect.setOutlineColor(sf::Color::White);

        sf::RectangleShape lvlRect(sf::Vector2f(340.f, 58.f));
        lvlRect.setOutlineThickness(5);
        lvlRect.setPosition(sf::Vector2f(392.f, 469.f));
        lvlRect.setFillColor(sf::Color::Black);
        lvlRect.setOutlineColor(sf::Color::White);

        sf::RectangleShape linesRect(sf::Vector2f(340.f, 58.f));
        linesRect.setOutlineThickness(5);
        linesRect.setPosition(sf::Vector2f(392.f, 542.f));
        linesRect.setFillColor(sf::Color::Black);
        linesRect.setOutlineColor(sf::Color::White);

        sf::RectangleShape titleRect(sf::Vector2f(390.f, 90.f));
        titleRect.setOutlineThickness(5);
        titleRect.setPosition(sf::Vector2f(200.f, 500.f));
        titleRect.setFillColor(sf::Color::Black);
        titleRect.setOutlineColor(sf::Color(150, 150, 150));

        sf::Sprite BCKGRND;
        sf::Sprite BCKGRND_END;
        BCKGRND.setTexture(titleScreen);
        BCKGRND_END.setTexture(endScreen);

        sf::Vector2i localPos;

        PlayButton pB(gO_font2);

        Board gB;

        int currentType = rand() % 7;
        int nextType = rand() % 7;

        Tetrimino* currentPiece = createPiece(currentType);
        Tetrimino* nextPiece = createPiece(nextType);

        sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "Bootleg Tetris by Zeeshan Raza");
        writtenName = "";
        clock.restart();
        elapsed = clock.restart();
        string newname1 = "";
        // run the program as long as the window is open
        while (window.isOpen())
        {

            elapsed += clock.restart();
            localPos = sf::Mouse::getPosition(window);

            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window.pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window.close();
                if (startGame == false || lostTheGame == true) {

                    if (event.key.code == sf::Keyboard::Enter) {

                        startGame = true;
                    }
                    if (event.type == sf::Event::TextEntered) {
                        if (event.text.unicode < 127 && event.text.unicode > 31 && event.key.code != sf::Keyboard::BackSpace)
                        {
                            writtenName += event.text.unicode;
                        }
                        
                        playerName = writtenName;


                    }
                    else if (event.type == sf::Event::KeyPressed) {

                        if (event.key.code == sf::Keyboard::Backspace) {
                            cout << "here";
                            int nameSize = writtenName.length();
                            if (nameSize != 0) {
                                string newName = writtenName.substr(0, nameSize - 1);
                                //newName[nameSize - 1] = '\0';
                                writtenName = newName;
                            }
                            playerName = writtenName;
                        }

                    }
                }
                    // "key pressed" event: move the pieces based on the key presses
                    if (event.type == sf::Event::KeyPressed) {

                        if (!(currentPiece->checkForOverLapping(gB.returnBoardNum()))) {
                            //I.movementInput(event);
                            currentPiece->movementInput3(event, gB.returnBoardNum());
                            if (!(currentPiece->checkForBounds_down(gB.returnBoardNum()))) { currentPiece->lastMoveOver(); }
                        }
                        else {

                            if (event.key.code == sf::Keyboard::Enter) {

                                gB.resetBoard();
                                lvl = 1;
                                totalScore = 0;
                                linesDeleted = 0;
                                elapsed = clock.restart();

                                currentType = rand() % 7;
                                nextType = rand() % 7;

                                currentPiece = createPiece(currentType);
                                nextPiece = createPiece(nextType);
                                lostTheGame = false;

                            }
                            else if (event.key.code == sf::Keyboard::Escape) {

                                window.close();

                            }

                        }

                    }

                    if (event.type == sf::Event::EventType::MouseMoved) {

                        //cout << localPos.x << " ";

                        if (!(currentPiece->checkForOverLapping2(gB.returnBoardNum())) && localPos.x > 0.f &&
                            localPos.x < 360.f && localPos.y > 25.f && localPos.y < 619.f) {

                            if (localPos.x < 50.f) {

                                if (currentPiece->checkForBounds_right(gB.returnBoardNum(), -2, currentPiece->returnYPos()) == 0
                                    && currentPiece->checkForBounds_left(gB.returnBoardNum(), -2, currentPiece->returnYPos()) == 0) {

                                    currentPiece->setXPos(-2);

                                }
                                else if (currentPiece->checkForBounds_right(gB.returnBoardNum(), -1, currentPiece->returnYPos()) == 0
                                    && currentPiece->checkForBounds_left(gB.returnBoardNum(), -1, currentPiece->returnYPos()) == 0) {

                                    currentPiece->setXPos(-1);

                                }
                            }
                            else if (localPos.x >= 50.f && localPos.x < 77.f) {

                                if (currentPiece->checkForBounds_right(gB.returnBoardNum(), 0, currentPiece->returnYPos()) == 0
                                    && currentPiece->checkForBounds_left(gB.returnBoardNum(), 0, currentPiece->returnYPos()) == 0) {

                                    //cout << "here is working" << endl;
                                    currentPiece->setXPos(0);

                                }
                            }
                            else if (localPos.x >= 79.f && localPos.x < 106.f) {

                                if (currentPiece->checkForBounds_right(gB.returnBoardNum(), 1, currentPiece->returnYPos()) == 0
                                    && currentPiece->checkForBounds_left(gB.returnBoardNum(), 1, currentPiece->returnYPos()) == 0) {

                                    //cout << "here is working2" << endl;
                                    currentPiece->setXPos(1);

                                }
                            }
                            else if (localPos.x >= 108.f && localPos.x < 135.f) {
                                if (currentPiece->checkForBounds_right(gB.returnBoardNum(), 2, currentPiece->returnYPos()) == 0
                                    && currentPiece->checkForBounds_left(gB.returnBoardNum(), 2, currentPiece->returnYPos()) == 0) {

                                    currentPiece->setXPos(2);

                                }
                            }
                            else if (localPos.x >= 137.f && localPos.x < 164.f) {
                                if (currentPiece->checkForBounds_right(gB.returnBoardNum(), 3, currentPiece->returnYPos()) == 0
                                    && currentPiece->checkForBounds_left(gB.returnBoardNum(), 3, currentPiece->returnYPos()) == 0) {

                                    currentPiece->setXPos(3);

                                }
                            }
                            else if (localPos.x >= 166.f && localPos.x < 193.f) {
                                if (currentPiece->checkForBounds_right(gB.returnBoardNum(), 4, currentPiece->returnYPos()) == 0
                                    && currentPiece->checkForBounds_left(gB.returnBoardNum(), 4, currentPiece->returnYPos()) == 0) {

                                    currentPiece->setXPos(4);

                                }
                            }
                            else if (localPos.x >= 195.f && localPos.x < 222.f) {
                                if (currentPiece->checkForBounds_right(gB.returnBoardNum(), 5, currentPiece->returnYPos()) == 0
                                    && currentPiece->checkForBounds_left(gB.returnBoardNum(), 5, currentPiece->returnYPos()) == 0) {

                                    currentPiece->setXPos(5);

                                }
                            }
                            else if (localPos.x >= 224.f && localPos.x < 251.f) {
                                if (currentPiece->checkForBounds_right(gB.returnBoardNum(), 6, currentPiece->returnYPos()) == 0
                                    && currentPiece->checkForBounds_left(gB.returnBoardNum(), 6, currentPiece->returnYPos()) == 0) {

                                    currentPiece->setXPos(6);

                                }
                            }
                            else if (localPos.x >= 253.f && localPos.x < 280.f) {
                                if (currentPiece->checkForBounds_right(gB.returnBoardNum(), 7, currentPiece->returnYPos()) == 0
                                    && currentPiece->checkForBounds_left(gB.returnBoardNum(), 7, currentPiece->returnYPos()) == 0) {

                                    currentPiece->setXPos(7);

                                }
                            }
                            else if (localPos.x >= 282.f && localPos.x < 309.f) {
                                if (currentPiece->checkForBounds_right(gB.returnBoardNum(), 8, currentPiece->returnYPos()) == 0
                                    && currentPiece->checkForBounds_left(gB.returnBoardNum(), 8, currentPiece->returnYPos()) == 0) {

                                    currentPiece->setXPos(8);

                                }
                            }
                            else if (localPos.x >= 311.f && localPos.x < 338.f) {
                                if (currentPiece->checkForBounds_right(gB.returnBoardNum(), 9, currentPiece->returnYPos()) == 0
                                    && currentPiece->checkForBounds_left(gB.returnBoardNum(), 9, currentPiece->returnYPos()) == 0) {

                                    currentPiece->setXPos(9);

                                }
                            }
                            else if (localPos.x >= 338.f) {
                                if (currentPiece->checkForBounds_right(gB.returnBoardNum(), 10, currentPiece->returnYPos()) == 0
                                    && currentPiece->checkForBounds_left(gB.returnBoardNum(), 10, currentPiece->returnYPos()) == 0) {

                                    currentPiece->setXPos(10);

                                }
                                else if (currentPiece->checkForBounds_right(gB.returnBoardNum(), 11, currentPiece->returnYPos()) == 0
                                    && currentPiece->checkForBounds_left(gB.returnBoardNum(), 11, currentPiece->returnYPos()) == 0) {

                                    currentPiece->setXPos(11);

                                }

                            }

                        }

                    }

                    if (event.type == sf::Event::EventType::MouseButtonPressed) {

                        if (startGame == false) {

                            /*if (localPos.x < pB.x_pos && localPos.x > pB.otherX() && localPos.y < pB.y_pos && localPos.y > pB.otherY()) {

                                startGame = true;

                            }*/

                        }
                        else {

                            if (localPos.x > 40.f && localPos.x < 348.f && localPos.y > 25.f && localPos.y < 619.f) {

                                while (!(cantGoLower)) { cantGoLower = currentPiece->moveDown2(gB.returnBoardNum()); }

                            }

                        }

                    }
                }
            if (startGame == false) {

                writingText.setPosition(250.f, 550.f);
                writingText.setString(writtenName);
                elapsed = clock.restart();
                window.clear(sf::Color::Black);
                window.draw(BCKGRND);
                window.draw(titleRect);
                window.draw(writingText);
                window.display();

            }
            else {

                playerName = writtenName;

                if (currentPiece->checkForBounds_down(gB.returnBoardNum()) != 0) {

                    if (WatB == false) {
                        WatB = true;
                        elapsed = clock.restart();
                    }

                    if (elapsed.asSeconds() < (fallTime * 0.75)) {

                        elapsed += clock.restart();

                        if (currentPiece->checkForBounds_down(gB.returnBoardNum())) { currentPiece->signalLastMove(); }
                        else { currentPiece->lastMoveOver(); }
                    }
                    else {
                        elapsed = clock.restart();
                        currentPiece->lastMoveOver();
                        cantGoLower = true;
                    }

                }
                else if (elapsed.asSeconds() >= fallTime) {

                    currentPiece->lastMoveOver();

                    elapsed -= sf::seconds(fallTime);
                    //currentPiece->moveDown(gB.returnBoardNum());
                    cantGoLower = currentPiece->moveDown2(gB.returnBoardNum());
                }

                if (cantGoLower) {

                    gB.addPiecesToBoard(currentPiece->returnPieceNum(), currentPiece->returnSize(), currentPiece->returnXPos(), currentPiece->returnYPos());
                    currentType = nextType;
                    nextType = rand() % 7;

                    currentPiece = createPiece(currentType);
                    if (currentType == 4) { currentPiece->placeAt(4, -1); }
                    else { currentPiece->placeAt(4, 0); }

                    nextPiece = createPiece(nextType);

                    cantGoLower = false;
                    WatB = false;

                }

                totalScore += gB.clearFullRows(linesDeleted);

                if (lvl == 1 && totalScore == 1000) { lvl = 2; }
                else if (lvl == 2 && totalScore == 2000) { lvl = 3; }
                else if (lvl == 3 && totalScore == 3000) { lvl = 4; }
                else if (lvl == 4 && totalScore == 4000) { lvl = 5; }
                else if (lvl == 5 && totalScore == 5000) { lvl = 6; }
                else if (lvl == 6 && totalScore == 6000) { lvl = 7; }
                else if (lvl == 7 && totalScore == 7000) { lvl = 8; }
                else if (lvl == 8 && totalScore == 8000) { lvl = 1; }

                nameTxt.setString(playerName);
                scoreTxt.setString(to_string(totalScore));
                lvlTxt.setString(to_string(lvl));
                linesTxt.setString(to_string(linesDeleted));

                // clear the window with black color
                window.clear(sf::Color::Black);

                if (!(currentPiece->checkForOverLapping(gB.returnBoardNum()))) {

                    // draw everything here...
                    gB.loadBoard(window);

                    window.draw(nextPieceRect);
                    window.draw(pSL0_1);
                    window.draw(pSL0_2);
                    window.draw(nameRect);
                    window.draw(pSL1);
                    window.draw(nameTxt);
                    window.draw(scoreRect);
                    window.draw(pSL2);
                    window.draw(scoreTxt);
                    window.draw(lvlRect);
                    window.draw(pSL3);
                    window.draw(lvlTxt);
                    window.draw(linesRect);
                    window.draw(pSL4);
                    window.draw(linesTxt);

                    currentPiece->loadPiece2(window);
                    //nextPiece->loadPiece2(window, 19, 2);
                    if (nextType == 0) { nextPiece->loadPiece2(window, 605.f, 78.f); }
                    else if (nextType == 1) { nextPiece->loadPiece2(window, 605.f, 93.f); }
                    else if (nextType == 2) { nextPiece->loadPiece2(window, 605.f, 93.f); }
                    else if (nextType == 3) { nextPiece->loadPiece2(window, 605.f, 108.f); }
                    else if (nextType == 5) { nextPiece->loadPiece2(window, 605.f, 78.f); }
                    else if (nextType == 6) { nextPiece->loadPiece2(window, 605.f, 78.f); }
                    else { nextPiece->loadPiece2(window, 605.f, 108.f); }

                    // end the current frame
                    window.display();

                }
                else {


                    if (!(lostTheGame)) {

                        lostTheGame = true;

                        gB.addPiecesToBoard(currentPiece->returnPieceNum(), currentPiece->returnSize(), currentPiece->returnXPos(), currentPiece->returnYPos());
                        nextType = rand() % 7;

                        nextPiece = createPiece(nextType);
                        currentPiece->signalOverLap();

                        // draw everything here...
                        gB.loadBoard(window);

                        window.draw(nextPieceRect);
                        window.draw(pSL0_1);
                        window.draw(pSL0_2);
                        window.draw(nameRect);
                        window.draw(pSL1);
                        window.draw(nameTxt);
                        window.draw(scoreRect);
                        window.draw(pSL2);
                        window.draw(scoreTxt);
                        window.draw(lvlRect);
                        window.draw(pSL3);
                        window.draw(lvlTxt);
                        window.draw(linesRect);
                        window.draw(pSL4);
                        window.draw(linesTxt);

                        currentPiece->loadPiece2(window);
                        //nextPiece->loadPiece2(window, 19, 2);
                        if (nextType == 0) { nextPiece->loadPiece2(window, 605.f, 78.f); }
                        else if (nextType == 1) { nextPiece->loadPiece2(window, 605.f, 93.f); }
                        else if (nextType == 2) { nextPiece->loadPiece2(window, 605.f, 93.f); }
                        else if (nextType == 3) { nextPiece->loadPiece2(window, 605.f, 108.f); }
                        else if (nextType == 5) { nextPiece->loadPiece2(window, 605.f, 78.f); }
                        else if (nextType == 6) { nextPiece->loadPiece2(window, 605.f, 78.f); }
                        else { nextPiece->loadPiece2(window, 605.f, 108.f); }

                        // end the current frame
                        window.display();

                    }

                    elapsed = clock.restart();

                    while (elapsed.asSeconds() < (fallTime / 2)) {
                        elapsed += clock.restart();
                    }

                    currentPiece->overlapOver();

                    window.draw(BCKGRND_END);

                    writingText.setPosition(sf::Vector2f(200.f, 380.f));
                    writingText.setString(writtenName);
                    window.draw(gO_text);
                    window.draw(gO_text2);
                    window.draw(gO_nameSpace);
                    window.draw(gO_text3);
                    window.draw(gO_text4);
                    window.draw(writingText);

                    window.display();

                }

            }

        }

        delete currentPiece;
        delete nextPiece;

    }

    void testPieces_working3() {

        srand(time(0));

        int gameWidth = 800;
        int gameHeight = 650;

        int lvl = 1;
        int totalScore = 0;
        int linesDeleted = 0;
        float fallTime = float(pow(0.9, (lvl - 1)));
        bool startGame = false;
        bool cantGoLower = false;
        bool lostTheGame = false;
        bool crossedLvl8 = false;
        bool WatB = false;

        string playerName = "ZtheKey";

        sf::Clock clock;
        sf::Time elapsed;

        sf::Font gO_font1;
        gO_font1.loadFromFile("Robus-BWqOd.otf");

        sf::Font gO_font2;
        gO_font2.loadFromFile("BruceForeverRegular-X3jd2.ttf");

        sf::Text gO_text(sf::String("Game Over"), gO_font1, 200);
        gO_text.setPosition((gameWidth / 2) - 350, (gameHeight / 2) - 300);
        gO_text.setFillColor(sf::Color::White);

        sf::Text gO_text2(sf::String("Enter name here (to save highscore)\nTo keep the same name, leave blank"), gO_font2, 20);
        gO_text2.setPosition((gameWidth / 2) - 271, (gameHeight / 2) - 25);
        gO_text2.setFillColor(sf::Color::White);

        sf::Text gO_text3(sf::String("Press ENTER to start over"), gO_font2, 15);
        gO_text3.setPosition((gameWidth / 2) - 153, (gameHeight / 2) + 135);
        gO_text3.setFillColor(sf::Color::White);

        sf::Text gO_text4(sf::String("Press ESC to leave the game"), gO_font2, 10);
        gO_text4.setPosition((gameWidth / 2) - 113, (gameHeight / 2) + 160);
        gO_text4.setFillColor(sf::Color::White);

        sf::Text pSL0_1(sf::String("Next"), gO_font2, 25);
        sf::Text pSL0_2(sf::String("Piece"), gO_font2, 25);
        pSL0_1.setPosition((gameWidth / 2) + 20, (gameHeight / 2) - 218);
        pSL0_2.setPosition((gameWidth / 2) + 18, (gameHeight / 2) - 182);
        pSL0_1.setFillColor(sf::Color::White);
        pSL0_2.setFillColor(sf::Color::White);

        sf::Text pSL1(sf::String("Name:"), gO_font2, 25);
        sf::Text pSL2(sf::String("Score:"), gO_font2, 25);
        sf::Text pSL3(sf::String("Level:"), gO_font2, 25);
        sf::Text pSL4(sf::String("Lines:"), gO_font2, 25);
        pSL1.setPosition((gameWidth / 2) + 10, (gameHeight / 2) - 5);
        pSL2.setPosition((gameWidth / 2) + 10, (gameHeight / 2) + 85);
        pSL3.setPosition((gameWidth / 2) + 10, (gameHeight / 2) + 157);
        pSL4.setPosition((gameWidth / 2) + 10, (gameHeight / 2) + 230);
        pSL1.setFillColor(sf::Color::White); pSL2.setFillColor(sf::Color::White);
        pSL3.setFillColor(sf::Color::White); pSL4.setFillColor(sf::Color::White);

        sf::Text nameTxt(sf::String(playerName), gO_font2, 25);
        sf::Text scoreTxt(sf::String(to_string(totalScore)), gO_font2, 25);
        sf::Text lvlTxt(sf::String(to_string(lvl)), gO_font2, 25);
        sf::Text linesTxt(sf::String(to_string(linesDeleted)), gO_font2, 25);
        nameTxt.setPosition((gameWidth / 2) + 125, (gameHeight / 2) - 5);
        scoreTxt.setPosition((gameWidth / 2) + 135, (gameHeight / 2) + 85);
        lvlTxt.setPosition((gameWidth / 2) + 120, (gameHeight / 2) + 157);
        linesTxt.setPosition((gameWidth / 2) + 120, (gameHeight / 2) + 230);
        nameTxt.setFillColor(sf::Color::White); scoreTxt.setFillColor(sf::Color::White);
        lvlTxt.setFillColor(sf::Color::White); linesTxt.setFillColor(sf::Color::White);

        sf::RectangleShape darkenEverything;
        darkenEverything.setSize(sf::Vector2f(gameWidth, gameHeight));
        darkenEverything.setFillColor(sf::Color::Black);

        sf::RectangleShape gO_nameSpace(sf::Vector2f(500.f, 80.f));
        gO_nameSpace.setOutlineThickness(5);
        gO_nameSpace.setPosition(sf::Vector2f(152.f, 367.f));
        gO_nameSpace.setFillColor(sf::Color::Transparent);
        gO_nameSpace.setOutlineColor(sf::Color::White);

        sf::RectangleShape nextPieceRect(sf::Vector2f(344.f, 194.f));
        nextPieceRect.setOutlineThickness(5);
        nextPieceRect.setPosition(sf::Vector2f(390.f, 48.f));
        nextPieceRect.setFillColor(sf::Color::Black);
        nextPieceRect.setOutlineColor(sf::Color::White);

        sf::RectangleShape nameRect(sf::Vector2f(340.f, 58.f));
        nameRect.setOutlineThickness(5);
        nameRect.setPosition(sf::Vector2f(392.f, 307.f));
        nameRect.setFillColor(sf::Color::Black);
        nameRect.setOutlineColor(sf::Color::White);

        sf::RectangleShape scoreRect(sf::Vector2f(340.f, 58.f));
        scoreRect.setOutlineThickness(5);
        scoreRect.setPosition(sf::Vector2f(392.f, 397.f));
        scoreRect.setFillColor(sf::Color::Black);
        scoreRect.setOutlineColor(sf::Color::White);

        sf::RectangleShape lvlRect(sf::Vector2f(340.f, 58.f));
        lvlRect.setOutlineThickness(5);
        lvlRect.setPosition(sf::Vector2f(392.f, 469.f));
        lvlRect.setFillColor(sf::Color::Black);
        lvlRect.setOutlineColor(sf::Color::White);

        sf::RectangleShape linesRect(sf::Vector2f(340.f, 58.f));
        linesRect.setOutlineThickness(5);
        linesRect.setPosition(sf::Vector2f(392.f, 542.f));
        linesRect.setFillColor(sf::Color::Black);
        linesRect.setOutlineColor(sf::Color::White);

        sf::Vector2i localPos;

        PlayButton pB(gO_font2);

        Board gB;

        int currentType = rand() % 7;
        int nextType = rand() % 7;

        Tetrimino* currentPiece = createPiece(currentType);
        Tetrimino* nextPiece = createPiece(nextType);

        sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "Bootleg Tetris by Zeeshan Raza");

        clock.restart();
        elapsed = clock.restart();
        //cout << "Fall Time: " << fallTime << " seconds" << endl << endl;

        // run the program as long as the window is open
        while (window.isOpen())
        {

            elapsed += clock.restart();
            localPos = sf::Mouse::getPosition(window);

            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window.pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window.close();

                // "key pressed" event: move the pieces based on the key presses
                if (event.type == sf::Event::EventType::KeyPressed) {

                    if (!(currentPiece->checkForOverLapping(gB.returnBoardNum()))) {
                        //I.movementInput(event);
                        currentPiece->movementInput3(event, gB.returnBoardNum());
                        if (!(currentPiece->checkForBounds_down(gB.returnBoardNum()))) { currentPiece->lastMoveOver(); }
                    }
                    else {

                        if (event.key.code == sf::Keyboard::Enter) {

                            gB.resetBoard();
                            lvl = 1;
                            totalScore = 0;
                            linesDeleted = 0;
                            elapsed = clock.restart();

                            currentType = rand() % 7;
                            nextType = rand() % 7;

                            currentPiece = createPiece(currentType);
                            nextPiece = createPiece(nextType);
                            lostTheGame = false;

                        }
                        else if (event.key.code == sf::Keyboard::Escape) {

                            window.close();

                        }

                    }

                }

                if (event.type == sf::Event::EventType::MouseButtonPressed) {

                    if (startGame == false) {

                        cout << "";

                    }

                }

            }

            if (currentPiece->checkForBounds_down(gB.returnBoardNum()) != 0) {

                if (WatB == false) {
                    WatB = true;
                    elapsed = clock.restart();
                }

                if (elapsed.asSeconds() < (fallTime * 0.75)) {

                    elapsed += clock.restart();

                    if (currentPiece->checkForBounds_down(gB.returnBoardNum())) { currentPiece->signalLastMove(); }
                    else { currentPiece->lastMoveOver(); }
                }
                else {
                    elapsed = clock.restart();
                    currentPiece->lastMoveOver();
                    cantGoLower = true;
                }

            }
            else if (elapsed.asSeconds() >= fallTime) {

                currentPiece->lastMoveOver();

                elapsed -= sf::seconds(fallTime);
                //currentPiece->moveDown(gB.returnBoardNum());
                cantGoLower = currentPiece->moveDown2(gB.returnBoardNum());
            }

            if (cantGoLower) {

                gB.addPiecesToBoard(currentPiece->returnPieceNum(), currentPiece->returnSize(), currentPiece->returnXPos(), currentPiece->returnYPos());
                currentType = nextType;
                nextType = rand() % 7;

                currentPiece = createPiece(currentType);
                if (currentType == 4) { currentPiece->placeAt(4, -1); }
                else { currentPiece->placeAt(4, 0); }

                nextPiece = createPiece(nextType);

                cantGoLower = false;
                WatB = false;

            }

            totalScore += gB.clearFullRows(linesDeleted);

            if (lvl == 1 && totalScore == 1000) { lvl = 2; }
            else if (lvl == 2 && totalScore == 2000) { lvl = 3; }
            else if (lvl == 3 && totalScore == 3000) { lvl = 4; }
            else if (lvl == 4 && totalScore == 4000) { lvl = 5; }
            else if (lvl == 5 && totalScore == 5000) { lvl = 6; }
            else if (lvl == 6 && totalScore == 6000) { lvl = 7; }
            else if (lvl == 7 && totalScore == 7000) { lvl = 8; }
            else if (lvl == 8 && totalScore == 8000) { lvl = 1; }

            scoreTxt.setString(to_string(totalScore));
            lvlTxt.setString(to_string(lvl));
            linesTxt.setString(to_string(linesDeleted));

            // clear the window with black color
            window.clear(sf::Color::Black);

            if (!(currentPiece->checkForOverLapping(gB.returnBoardNum()))) {

                // draw everything here...
                gB.loadBoard(window);

                window.draw(nextPieceRect);
                window.draw(pSL0_1);
                window.draw(pSL0_2);
                window.draw(nameRect);
                window.draw(pSL1);
                window.draw(nameTxt);
                window.draw(scoreRect);
                window.draw(pSL2);
                window.draw(scoreTxt);
                window.draw(lvlRect);
                window.draw(pSL3);
                window.draw(lvlTxt);
                window.draw(linesRect);
                window.draw(pSL4);
                window.draw(linesTxt);

                currentPiece->loadPiece2(window);
                //nextPiece->loadPiece2(window, 19, 2);
                if (nextType == 0) { nextPiece->loadPiece2(window, 605.f, 78.f); }
                else if (nextType == 1) { nextPiece->loadPiece2(window, 605.f, 93.f); }
                else if (nextType == 2) { nextPiece->loadPiece2(window, 605.f, 93.f); }
                else if (nextType == 3) { nextPiece->loadPiece2(window, 605.f, 108.f); }
                else if (nextType == 5) { nextPiece->loadPiece2(window, 605.f, 78.f); }
                else if (nextType == 6) { nextPiece->loadPiece2(window, 605.f, 78.f); }
                else { nextPiece->loadPiece2(window, 605.f, 108.f); }

                // end the current frame
                window.display();

            }
            else {


                if (!(lostTheGame)) {

                    lostTheGame = true;

                    gB.addPiecesToBoard(currentPiece->returnPieceNum(), currentPiece->returnSize(), currentPiece->returnXPos(), currentPiece->returnYPos());
                    nextType = rand() % 7;

                    nextPiece = createPiece(nextType);
                    currentPiece->signalOverLap();

                    // draw everything here...
                    gB.loadBoard(window);

                    window.draw(nextPieceRect);
                    window.draw(pSL0_1);
                    window.draw(pSL0_2);
                    window.draw(nameRect);
                    window.draw(pSL1);
                    window.draw(nameTxt);
                    window.draw(scoreRect);
                    window.draw(pSL2);
                    window.draw(scoreTxt);
                    window.draw(lvlRect);
                    window.draw(pSL3);
                    window.draw(lvlTxt);
                    window.draw(linesRect);
                    window.draw(pSL4);
                    window.draw(linesTxt);

                    currentPiece->loadPiece2(window);
                    //nextPiece->loadPiece2(window, 19, 2);
                    if (nextType == 0) { nextPiece->loadPiece2(window, 605.f, 78.f); }
                    else if (nextType == 1) { nextPiece->loadPiece2(window, 605.f, 93.f); }
                    else if (nextType == 2) { nextPiece->loadPiece2(window, 605.f, 93.f); }
                    else if (nextType == 3) { nextPiece->loadPiece2(window, 605.f, 108.f); }
                    else if (nextType == 5) { nextPiece->loadPiece2(window, 605.f, 78.f); }
                    else if (nextType == 6) { nextPiece->loadPiece2(window, 605.f, 78.f); }
                    else { nextPiece->loadPiece2(window, 605.f, 108.f); }

                    // end the current frame
                    window.display();

                }

                elapsed = clock.restart();

                while (elapsed.asSeconds() < (fallTime / 2)) {
                    elapsed += clock.restart();
                }

                currentPiece->overlapOver();

                window.draw(darkenEverything);

                window.draw(gO_text);
                window.draw(gO_text2);
                window.draw(gO_nameSpace);
                window.draw(gO_text3);
                window.draw(gO_text4);

                window.display();

            }

        }

        delete currentPiece;
        delete nextPiece;

    }

    void testPieces_working2() {

        srand(time(0));

        int gameWidth = 800;
        int gameHeight = 650;

        int lvl = 1;
        int totalScore = 0;
        float fallTime = float(pow(0.9, (lvl - 1)));
        bool cantGoLower = false;
        bool crossedLvl8 = false;

        sf::Clock clock;
        sf::Time elapsed;

        sf::Font gO_font;
        gO_font.loadFromFile("Robus-BWqOd.otf");

        sf::Font gO_font2;
        gO_font2.loadFromFile("BruceForeverRegular-X3jd2.ttf");

        sf::Text gO_text;
        gO_text.setFont(gO_font);
        gO_text.setString("Game Over");
        gO_text.setPosition((gameWidth / 2) - 350, (gameHeight / 2) - 300);
        gO_text.setCharacterSize(200);
        gO_text.setFillColor(sf::Color::White);

        sf::Text gO_text2;
        gO_text2.setFont(gO_font2);
        gO_text2.setString("Press ENTER to start over");
        gO_text2.setPosition((gameWidth / 2) - 150, (gameHeight / 2) - 25);
        gO_text2.setCharacterSize(15);
        gO_text2.setFillColor(sf::Color::White);

        sf::Text gO_text3;
        gO_text3.setFont(gO_font2);
        gO_text3.setString("Press ESC to leave the game");
        gO_text3.setPosition((gameWidth / 2) - 150, (gameHeight / 2) + 15);
        gO_text3.setCharacterSize(15);
        gO_text3.setFillColor(sf::Color::White);

        Board gB;

        int currentType = rand() % 7;
        int nextType = rand() % 7;

        Tetrimino* currentPiece = createPiece(currentType);
        Tetrimino* nextPiece = createPiece(nextType);

        sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight), "Bootleg Tetris by Zeeshan Raza");

        clock.restart();
        elapsed = clock.restart();
        //cout << "Fall Time: " << fallTime << " seconds" << endl << endl;

        // run the program as long as the window is open
        while (window.isOpen())
        {

            elapsed += clock.restart();

            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window.pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window.close();

                // "key pressed" event: move the pieces based on the key presses
                if (event.type == sf::Event::EventType::KeyPressed) {

                    if (!(gB.checkForLoss())) {
                        //I.movementInput(event);
                        currentPiece->movementInput2(event, gB.returnBoardNum());
                    }
                    else {

                        if (event.key.code == sf::Keyboard::Enter) {

                            gB.resetBoard();
                            lvl = 1;
                            totalScore = 0;
                            elapsed = clock.restart();

                            currentType = rand() % 7;
                            nextType = rand() % 7;

                            currentPiece = createPiece(currentType);
                            nextPiece = createPiece(nextType);

                        }
                        else if (event.key.code == sf::Keyboard::Escape) {

                            window.close();

                        }

                    }

                }

            }

            if (elapsed.asSeconds() >= fallTime) {
                elapsed -= sf::seconds(fallTime);
                //currentPiece->moveDown(gB.returnBoardNum());
                cantGoLower = currentPiece->moveDown2(gB.returnBoardNum());
            }

            if (cantGoLower) {

                gB.addPiecesToBoard(currentPiece->returnPieceNum(), currentPiece->returnSize(), currentPiece->returnXPos(), currentPiece->returnYPos());
                currentType = nextType;
                nextType = rand() % 7;

                currentPiece = createPiece(currentType);
                if (currentType == 4) { currentPiece->placeAt(4, -1); }
                else { currentPiece->placeAt(4, 0); }

                nextPiece = createPiece(nextType);

                cantGoLower = false;

            }

            totalScore += gB.clearFullRows();

            if (lvl == 8) { lvl = 1; crossedLvl8 = true; }
            if (totalScore % 1000 == 0 && !(crossedLvl8)) { lvl++; }

            // clear the window with black color
            window.clear(sf::Color::Black);

            if (!(gB.checkForLoss())) {

                // draw everything here...
                gB.loadBoard(window);
                currentPiece->loadPiece2(window);
                nextPiece->loadPiece2(window, 13, 4);

                // end the current frame
                window.display();

            }
            else {

                window.draw(gO_text);
                window.draw(gO_text2);
                window.draw(gO_text3);

                window.display();

            }

            /*while (gB.checkForLoss()) {

                cout << "Entered da function" << endl;

                window.clear(sf::Color::Black);

                window.draw(gO_text);
                window.draw(gO_text2);

                window.display();

                if (event.type == sf::Event::EventType::KeyPressed) {

                    if (event.key.code == sf::Keyboard::Enter) {

                        window.clear(sf::Color::Black);

                        gB.resetBoard();

                        currentType = rand() % 7;
                        nextType = rand() % 7;

                        currentPiece = createPiece(currentType);
                        nextPiece = createPiece(nextType);

                        gB.loadBoard(window);
                        currentPiece->loadPiece2(window);
                        nextPiece->loadPiece2(window, 13, 4);

                    }

                }

            }*/

        }

        delete currentPiece;
        delete nextPiece;

    }


    void testPieces_working1() {

        int lvl = 1;
        int score = 0;
        float fallTime = float(pow(0.9, (lvl - 1)));
        //bool cantGoLower;

        sf::Clock clock;
        sf::Time elapsed;

        Board gB;

        cyanLine I;
        blue_revL _l;
        orangeL L;
        yellowSquare O;
        greenS s;
        purpleT t;
        red_revS z;

        sf::RenderWindow window(sf::VideoMode(800, 650), "Bootleg Tetris by Zeeshan Raza");

        clock.restart();
        elapsed = clock.restart();

        // run the program as long as the window is open
        while (window.isOpen())
        {

            elapsed += clock.restart();

            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window.pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window.close();

                // "key pressed" event: move the pieces based on the key presses
                if (event.type == sf::Event::EventType::KeyPressed) {

                    //I.movementInput(event);
                    z.movementInput2(event, gB.returnBoardNum());

                }

            }

            if (elapsed.asSeconds() >= fallTime) {
                elapsed -= sf::seconds(fallTime);
                z.moveDown(gB.returnBoardNum());
            }



            // clear the window with black color
            window.clear(sf::Color::Black);

            // draw everything here...
            gB.loadBoard(window);
            z.loadPiece2(window);

            // end the current frame
            window.display();
        }
    }

    void testPieces_working() {

        Board gB;

        cyanLine I;
        blue_revL _l;
        orangeL L;
        yellowSquare O;
        greenS s;
        purpleT t;
        red_revS z;

        sf::RenderWindow window(sf::VideoMode(800, 650), "Bootleg Tetris by Zeeshan Raza");

        // run the program as long as the window is open
        while (window.isOpen())
        {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window.pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window.close();

                // "key pressed" event: move the pieces based on the key presses
                if (event.type == sf::Event::EventType::KeyPressed) {

                    //s.movementInput(event);
                    s.movementInput2(event, gB.returnBoardNum());

                }

            }

            // clear the window with black color
            window.clear(sf::Color::Black);

            // draw everything here...
            gB.loadBoard(window);
            s.loadPiece(window);

            // end the current frame
            window.display();
        }
    }

};
