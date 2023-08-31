#include <fstream>
int score;
int sscore;
using namespace std;
#include <cstring>;
#include <algorithm> 
#include<string.h>
static long long int killscore;


struct Player {
	char name[20];
    int score;

    Player() {}

    Player(char playerName[], int killScore) {
		strcpy(name,playerName);
        score = killScore;
    }
    void setPlayer(Player x)
    {
		strcpy(name,x.name);
        score=x.score;
    }
};

long long int getScore()
{
	return killscore;
}


const int numPlayers = 6;
Player p[numPlayers];

void SortPlayer(int n)
{
    for(int j=0;j<n-1;j++)
    {
        for(int k=0;k<n-1-j;k++)
        {
            if(p[k].score<=p[k+1].score)
            {
                Player temp=p[k];
                p[k]=p[k+1];
                p[k+1]=temp;
            }
        }
    }
}



char* stringConverter(int killpoint)
{
	char *ch = new char[3000];
	itoa(killpoint, ch, 10);
	return ch;
}






void showscore()
{
	iSetColor(255, 255, 255);
	iText(250, 200, p[4].name, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(700, 200, stringConverter(p[4].score), GLUT_BITMAP_TIMES_ROMAN_24);

	iText(250, 250, p[3].name, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(700, 250, stringConverter(p[3].score), GLUT_BITMAP_TIMES_ROMAN_24);

	iText(250, 300, p[2].name, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(700, 300, stringConverter(p[2].score), GLUT_BITMAP_TIMES_ROMAN_24);

	iText(250, 350, p[1].name, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(700, 350, stringConverter(p[1].score), GLUT_BITMAP_TIMES_ROMAN_24);

	iText(250, 400, p[0].name, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(700, 400, stringConverter(p[0].score), GLUT_BITMAP_TIMES_ROMAN_24);
}


void scorecounter()
{
	iSetColor(255, 0, 0);
	iText(500, 550, "SCORE:", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(600, 550,stringConverter(killscore) , GLUT_BITMAP_TIMES_ROMAN_24);
}
