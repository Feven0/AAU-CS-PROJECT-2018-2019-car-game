//#include<mmsystem.h>........ p.s. we will add audio file later
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<conio.h>

using namespace std;


void makecar(int x, int y)    // creating the car
   {
      rectangle(x+1,y,x+49,y+100);
      rectangle(x+1,y+25,x+49,y+75);
      setfillstyle(SOLID_FILL,15);
      floodfill((x+x+50)/2,(y+y+100)/2,15);
   }

//function that clears the screen
void clear(int x,int y)
   {
      setcolor(3);
      rectangle(x+1,y,x+49,y+100);
      rectangle(x+1,y+25,x+49,y+75);
      setfillstyle(SOLID_FILL,3);
      floodfill((x+x+50)/2,(y+y+100)/2,3);
      setcolor(15);
   }
 void startGame()
 {


    //initwindow(screen_width, screen_height, "Welcome to Car Race Game", 50, 50);

    int x=300,y=350,ch,life=3,score=0;
    char choice;
    cleardevice();//clearing the screen every time we start

    setcolor(WHITE);
    rectangle(20,60,200,120);
    rectangle(249,0,401,getmaxy());
    setfillstyle(SOLID_FILL,3);
    floodfill(325,getmaxy()/2,WHITE);
    outtextxy(30, 300, "Press <Esc> to Exit");
    for(int level=1;(level<=5)&&(life>0);level++)
    {
        if(level==1){
            outtextxy(30, 65, "Your Game Starts Now");
            outtextxy(30, 85, "All the best");
        }

        delay(300);//2 seconds

        for(int i=0;(i<15)&&(life>0);i++)
           {
              if((level==5)&&(i==14))
                 {
                    outtextxy(30, 550, "You have won!");
                    outtextxy(30, 600, "Do you want to continue? (y/n)");
                    choice = getch();
                    exit(0);
                 }

            //converting integers to string
            char levelStr[5], lifeStr[5],scoreStr[5], msgStr[100];
            sprintf(levelStr, "%d", level);
            sprintf(lifeStr, "%d", life);
            sprintf(scoreStr, "%d", score);
            sprintf(msgStr, "You have lost %d life(s)", (3-life)+1);


            setcolor(WHITE);
            rectangle(420,125,600,300);

            outtextxy(440, 150, "Level = ");
            outtextxy(500, 150, levelStr);


            outtextxy(440, 200, "Lives = ");
            outtextxy(500, 200, lifeStr);

            outtextxy(440, 250, "Scores = ");
            outtextxy(500, 250, scoreStr);

            int accident=0;
            int y1=1,x1=250+((rand()%3)*50);
            int y2=1,x2=250+((rand()%3)*50);
            score += 10;

      while(y1<getmaxy()+5)
            {
                clear(x1,y1);
                clear(x2,y2);
                y1++;
                y2++;
                makecar(x1,y1);
                makecar(x2,y2);
                makecar(x,y);

                delay(5-level); //speed changer
                if(kbhit())
                {
                    makecar(x,y);
                    ch=getch();
                    switch(ch)
                    {
                        case 27: //escape key
                            exit(0);
                            break;
                        case 75:
                            clear(x,y);
                            if(x>250)
                                x=x-50;
                            makecar(x,y);
                            break;
                        case 77:
                            clear(x,y);
                            if(x<350)
                                x=x+50;
                            makecar(x,y);
                            break;
                    }
                }

                if((x==x1)||(x==x2))
                    if( ( ((y-y1)<100)&&((y-y1)>0) ) || ( ((y-y2)<100)&&((y-y2)>0) ) )
                        accident=1;
            }

	  if(accident==1) //if car crashed
	  {
	    life = life-1;
	    if(life==0)
	    {
            outtextxy(30, 100, msgStr);
            setcolor(WHITE);
            sprintf(lifeStr, "%d", life);
            outtextxy(500, 200, lifeStr);
            setcolor(WHITE);
            outtextxy(70, 400, "GAME OVER!");
            outtextxy(50, 420, "TRY ANOTHER TIME");
            outtextxy(30, 440, "PRESS ANY KEY TO QUIT!");
            getch();
            closegraph();
            exit(0);
        }

	    outtextxy(30, 100, msgStr);
	    delay(100);//0.5 seconds
      }
    }
  }
 }

void welcomeWindow()
 {
   //getting screen width
    DWORD screen_width = 700;//GetSystemMetrics(SM_CXSCREEN)/2;
    DWORD screen_height = 500;//GetSystemMetrics(SM_CYSCREEN)/2;

    initwindow(screen_width, screen_height, "Welcome to Car Race Game", 100, 100);

    setcolor(WHITE);

    outtextxy(300, 20,  "This is Addis Ababa University");
    outtextxy(300, 40,  "Elshaday and Feven Presents");
    outtextxy(300, 150,  ":):):):):):):):):):):):):):):)");
    outtextxy(400, 200,        "WELCOME TO DOJU");
    outtextxy(300, 120, ":):):):):):):):):):):):):):):)");


    rectangle(200, 200, 350, 250);
    outtextxy(250,220, "PLAY");

    rectangle(400, 200, 500, 250);
    outtextxy(440,220, "QUIT");

    POINT cursorPosition;
    int mX, mY;

    while(1) //infinite loop for listening mouse click event
    {
        if(GetAsyncKeyState(VK_LBUTTON)) //left click mouse event
        {
            GetCursorPos(&cursorPosition);
            mX = cursorPosition.x;
            mY = cursorPosition.y;

            //if clicked coordinations is between button
            if((mX >= 200 && mX <= 350) || (mY >= 200 && mY <= 250)){ //IF BUTTON CLICKED
                //closegraph();
                startGame();
            }

            /*if((mX >= 200 && mX <= 350) || (mY >= 200 && mY <= 250)){ //IF BUTTON CLICKED
                closegraph();
                exit(0);
            }*/
            //circle(mX, mY, 100);
            delay(100);
        }
    }
 }

//main function
int main()
{
  welcomeWindow();
  return 0;
}
