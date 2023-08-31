
#include <iostream>
#include <Windows.h>
#include"loadimage.h"
#include <cmath>
#include "menu.h"
#include"Healthbar.h"
#include <string.h>
#include "score.h"



using namespace std;

#define screenWidth 1000
#define screenHeight 600

bool loadImage2;
int gamestage;
bool musicOn1 = true;
bool bulletVisible = false;
bool musicOn2=true;


bool isHurt = false;
bool isZom1Hurt=false;
bool isZom2Hurt=false;
bool isZom3Hurt=false;


int backgroundImagePosX = 0;


int currentDogFrame = 0;
int currentHurtDogFrame = 0;


int currentzom1Frame = 0;
int currentHurtzom1Frame = 0;




int currentzom3Frame = 0;



int dogPosY = 90;
int dogWidth = 80;
int dogHeight = 80;
int dogPosX = 1000;

int zom1PosY = 90;
int zom1Width = 80;
int zom1Height = 100;
int zom2Width=80;
int zom2Height = 100;
int zom2PosY = 90;

int zom1PosX = 1000+rand()%1000;
int zom2PosX =1000+rand()%1000;


int zom3PosY = 90;
int zom3Width = 70;
int zom3Height = 70;
int zom3PosX = 1000+rand()%1000;



int characterPosX = 100;
int characterPosY = 80;
int characterWidth = 80;
int characterHeight = 120;
int CharacterFrame = 0;
int standingFrame = 0;
int image10PosX = characterPosX;
int image10PosY = characterPosY;
int jumpHeight = 150;
int jumpSpeed = 4;
int jumpStartTime;
bool isJumping = false;
bool canJump = true;
int isShootingcounter=0;

static int characterlife=1000;



int backgroundSpeed = 1;
int bulletPosX = image10PosX + 60;
int bulletPosY=image10PosY;
int bulletWidth = 40;
int bulletHeight = 40;
int bulletSpeed = 50;

bool standingposition = true;
bool shoot = false;
bool isMovingRight = false;
bool isMovingLeft = false;
bool isStandingRight = true;
bool isStandingLeft = false;
bool isShooting = false;
int  standcounter=0;

bool *musicOn1Ptr = &musicOn1;
bool gunSound=false;



static long long int currentscore;


	 
	

bool dogattack=false;
bool zom1attack=false;
bool zom2attack=false;
bool zom3attack=false;
bool boss1attack=false;


bool doggenerate=false;
bool zom1generate=false;
bool zom2generate=false;
int x=0;

bool showPause=false;
bool gamestart=false;

static int dognumber=1;
static int zom1number=1;
static int zom2number=1;

int level=1;

char str[100];
bool nation =true;
int len=0;
struct bullet{
   int bulletPosX ;
   int bulletPosY;
   bool bulletVisible ;

   bullet()
   {
   }
   bullet( int bulletPosX,int bulletPosY, bool bulletVisible )
   {
    bulletPosX=bulletPosX ;
    bulletPosY= bulletPosY;
    bulletVisible=bulletVisible;


   }
};

bullet bullets[1000];


bool isColliding(int x1, int y1, int width1, int height1, int x2, int y2, int width2, int height2)
{
    
    if (x1 + width1 >= x2 && x1 <= x2 + width2 &&
        y1 + height1 >= y2 && y1 <= y2 + height2)
    {
        return true; 
    }
    return false; 
}

void resetgame(){
	 
 bulletVisible = false;


 isHurt = false;
 isZom1Hurt=false;
 isZom2Hurt=false;
 isZom3Hurt=false;
 

 backgroundImagePosX = 0;


 currentDogFrame = 0;
 currentHurtDogFrame = 0;

 currentzom1Frame = 0;
 currentHurtzom1Frame = 0;
 
 




 currentzom3Frame = 0;

 x=0;

 dogPosY = 90;
 dogWidth = 80;
 dogHeight = 80;
 dogPosX = 1000+rand()%1000;

 zom1PosY = 90;
 zom1Width = 80;
 zom1Height = 100;
 zom1PosX = 1000+rand()%1000;
 zom2PosX = 1000+rand()%1000;

 zom3PosY = 90;
 zom3Width = 70;
 zom3Height = 70;
 zom3PosX = 1000+rand()%1000;


 characterPosX = 100;
 characterPosY = 80;
 characterWidth = 80;
 characterHeight = 120;
 CharacterFrame = 0;
 standingFrame = 0;
 image10PosX = characterPosX;
 image10PosY = characterPosY;
 jumpHeight = 150;
 jumpSpeed = 4;
 jumpStartTime;
 isJumping = false;
 canJump = true;
 isShootingcounter=0;




 backgroundSpeed = 1;
 bulletPosX = image10PosX + 60;
 bulletPosY=image10PosY;
 bulletWidth = 40;
 bulletHeight = 40;
 bulletSpeed = 50;

 standingposition = true;
 shoot = false;
 isMovingRight = false;
 isMovingLeft = false;
 isStandingRight = true;
 isStandingLeft = false;
 isShooting = false;
 standcounter=0;

 


 dogattack=false;
 zom1attack=false;
 zom2attack=false;
 zom3attack=false;
 boss1attack=false;

 doggenerate=false;
 zom1generate=false;
 zom2generate=false;

 

 dognumber=1;
 zom1number=1;
 zom2number=1;



 str[100];
 nation =true;
 len=0;


}
void FrameTimer()
{   
	 currentDogFrame++;
    if (currentDogFrame >= 11)
    {
        currentDogFrame = 0;
    }

    currentzom1Frame++;
    if (currentzom1Frame >= 10)
    {
        currentzom1Frame = 0;
    }

	currentzom3Frame++;
    if (currentzom3Frame >= 6)
    {
        currentzom3Frame = 0;
    }


	
	CharacterFrame++;
    if (CharacterFrame >= 3)
    {
        CharacterFrame = 0;
    }
	currentHurtDogFrame++;
    if (currentHurtDogFrame >= 5)
    {
        currentHurtDogFrame = 0;
    }

	currentHurtzom1Frame++;
    if (currentHurtzom1Frame >= 4)
    {
        currentHurtzom1Frame = 0;
    }
	
}


void resume(){
	  iResumeTimer(0);
	  iResumeTimer(1);
	  iResumeTimer(2);
	  


}
void pause(){

	  iPauseTimer(0);
	  iPauseTimer(1);
	  iPauseTimer(2);

	  
	  

	  

}
 
void iPassiveMouse(int mx, int my)
{
   
    
}

void iMouseMove(int mx, int my)
{
    
}
void iMouse(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
		
	if(gamestage==0)
{

	if (mx > 466 && mx < 570 && my > 263 && my < 277)
{
	gamestage = 1;
	musicOn1=false;
			*musicOn1Ptr=false;
			
			
			//PlaySound(0, 0, 0);
			musicOn2=true;
			if(musicOn2)
			PlaySound("sound//3.wav", NULL, SND_ASYNC | SND_LOOP);
			
			

}
	else if (mx > 460 && mx < 575 && my > 215 && my < 235)
{
            gamestage = 2;
           musicOn2=false;
     musicOn1=true;
	 *musicOn1Ptr=true;
	
	 PlaySound("sound//1.wav", NULL, SND_ASYNC | SND_LOOP);
			
}
	else if (mx > 415 && mx < 585 && my > 180 && my < 200)
{
     gamestage = 3;
	  musicOn2=false;
     musicOn1=true;
	 *musicOn1Ptr=true;
	
	 PlaySound("sound//1.wav", NULL, SND_ASYNC | SND_LOOP);
}
	else if (mx > 450 && mx < 580 && my > 140 && my < 160)
{
    gamestage = 4;
    musicOn1=true;
	*musicOn1Ptr=true;
	PlaySound("sound//1.wav", NULL, SND_ASYNC | SND_LOOP);
}
	else if (mx > 485 && mx < 555 && my > 100 && my < 125)
{
    gamestage = 5;
	 musicOn2=false;
    musicOn1=true;
	*musicOn1Ptr=true;
    PlaySound("sound//1.wav", NULL, SND_ASYNC | SND_LOOP);
}
	else
{
   gamestage = 0;
    musicOn2=false;
   
   musicOn1=true;
   *musicOn1Ptr=true;
   PlaySound("sound//1.wav", NULL, SND_ASYNC | SND_LOOP);
}
}
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
    }
}
void iSpecialKeyboard(unsigned char key)
{
    if (key == GLUT_KEY_END)
    {
        exit(0);
    }
	else if(key==GLUT_KEY_RIGHT)
	{
	
        if (image10PosX < 600)
        {
            image10PosX += 1;
            isMovingRight = true;
            isMovingLeft = false;
            isStandingRight = false;
            isStandingLeft = false;
            isShooting = false;
            
        }
		backgroundImagePosX -= backgroundSpeed;
        if (backgroundImagePosX <= -1000)
            backgroundImagePosX = 0;
	
	}
	else if(key==GLUT_KEY_LEFT){
	if (image10PosX > 0)
            image10PosX -= 2;
        backgroundImagePosX += backgroundSpeed;
        isMovingRight = false;
        isMovingLeft = true;
        isStandingRight = false;
        isStandingLeft = false;
        isShooting = false;
        if (backgroundImagePosX >= 1000)
            backgroundImagePosX = 0;
	
	}
	else if(key==GLUT_KEY_UP){
	    if (canJump && !isJumping) 
        {
            isJumping = true;
            jumpStartTime = GetTickCount();
			

        }
    }
	
	
	}


void jump()
{
    if (isJumping)
    {
        int timeElapsed = GetTickCount() - jumpStartTime;
        if (timeElapsed <= 1200)
        {
            image10PosY += jumpSpeed;
           
        }
        else
        {
            isJumping = false;
            canJump = false; 
        }
    }
    else
    {
        image10PosY -= jumpSpeed;
        if (image10PosY<= 100)
        {
            image10PosY= 100;
            canJump = true;
    }
}
}

void gamestage2()
{ 
	pause();
	x++;
	
	
	if(x>100 && !showPause){
	
	 resume();
	  
	}
	else{
	 pause();
	}
	if(characterlife>1){

	
	

	if(level==1 && level!=2 && level!=3  ){
    iShowImage(0, 0, 1000, 600, image5);
    int backgroundWidth = 1000;
    int backgroundHeight = 600;
	int backgroundImage1PosX = backgroundImagePosX % backgroundWidth;
    int backgroundImage2PosX = (backgroundImagePosX + backgroundWidth) % backgroundWidth;

    iShowImage(backgroundImage1PosX, 130, backgroundWidth, backgroundHeight, image11);
    iShowImage(backgroundImage2PosX, 130, backgroundWidth, backgroundHeight, image11);

    if (backgroundImagePosX <= -backgroundWidth || backgroundImagePosX>0)
    {
        backgroundImagePosX = 0;
    }
	
	
	  
	
	 scorecounter();
	 
	  if(doggenerate){
	  dognumber++;
	  doggenerate=false;
	  }

	  if(zom1generate){
	  zom1number++;
	  zom1generate=false;
	  }

	  if(zom2generate){
	  zom2number++;
	  zom2generate=false;
	  
	  }


	
	if(dogattack){
	characterlife=characterlife-100;
	dogattack=false;
	}
	 if(zom1attack)
	{
	characterlife=characterlife-50;
	zom1attack=false;
	
	}
	if(zom2attack){
	characterlife=characterlife-50;
	zom2attack=false;
	}

	 if(zom3attack){
	characterlife=characterlife-200;
	zom3attack=false;
	}
	 
	
	 
	

    for (int i = 0; i <1000; i++) {
        if (bullets[i].bulletVisible) {
            iShowImage(bullets[i].bulletPosX, bullets[i].bulletPosY + 40, bulletWidth, bulletHeight, image9);
        }
    }

	if (!isShooting && !isMovingRight && !isMovingLeft)
    {
        if (isStandingRight)
        {
            iShowImage(image10PosX, image10PosY, 100, 100, standingImageRight[CharacterFrame]);
        }
        else if (isStandingLeft)
        {
            iShowImage(image10PosX, image10PosY, 100, 100, standingImageLeft[CharacterFrame]);
        }
    }
    else
    {
        if (isShooting)
        {
            if (isMovingRight||isStandingRight)
            {
                iShowImage(image10PosX, image10PosY, 100, 100, shootImage[CharacterFrame]);
				isShootingcounter++;
				if(isShootingcounter>=30){
                  isShooting=false;
				  isShootingcounter=0;
				
				}
            }
        }
        else
        {
            if (isMovingRight)
            {
                iShowImage(image10PosX, image10PosY, 100, 100, runImageRight[CharacterFrame]);
				standcounter++;
				if(standcounter>=100){
				isMovingRight=false;
				isStandingRight=true;
				standcounter=0;
				}
				
            }
            else if (isMovingLeft)
            {
                iShowImage(image10PosX, image10PosY, 100, 100, runImageLeft[CharacterFrame]);
				standcounter++;
				if(standcounter>=100){
				isMovingLeft=false;
				isStandingLeft=true;
				standcounter=0;
				}
            }
            else if (isStandingRight)
            {
                iShowImage(image10PosX, image10PosY, 100, 100, standingImageRight[CharacterFrame]);
            }
            else if (isStandingLeft)
            {
                iShowImage(image10PosX, image10PosY, 100, 100, standingImageLeft[CharacterFrame]);
            }
			else if(isJumping){
				
				iShowImage(image10PosX, image10PosY, 100, 100, jumpImages[CharacterFrame]);
			}
        }
    }

	 
    if (isHurt)
    {
        iShowImage(dogPosX, dogPosY, dogWidth, dogHeight, dogHurtImages[currentHurtDogFrame]);
    }
    else
    {
        iShowImage(dogPosX, dogPosY, dogWidth, dogHeight, dogImages[currentDogFrame]);
    }
	if (isZom1Hurt)
    {
        iShowImage(zom1PosX, zom1PosY, zom1Width, zom1Height, zom1HurtImages[currentHurtzom1Frame]);
	
    }
    else
    {
        iShowImage(zom1PosX, zom1PosY, zom1Width, zom1Height, zom1Images[currentzom1Frame]);
    }
	if (isZom2Hurt)
    {
        iShowImage(zom2PosX, zom1PosY, zom1Width, zom1Height, zom1HurtImages[currentHurtzom1Frame]);
    }
    else
    {
        iShowImage(zom2PosX, zom1PosY, zom1Width, zom1Height, zom1Images[currentzom1Frame]);
    }
	if (isZom3Hurt)
    {
        iShowImage(zom3PosX, zom3PosY, zom3Width, zom3Height, zom3Images[currentzom3Frame]);
    }
    else
    {
        iShowImage(zom3PosX, zom3PosY, zom3Width, zom3Height, zom3Images[currentzom3Frame]);
	}


	

	
   
    if (isColliding(image10PosX, image10PosY+30, characterWidth, characterHeight,
                    dogPosX+50, dogPosY, dogWidth-50, dogHeight-20))
    {
         dogattack=true;
		 dogPosX=1000+rand()%1000;
		 doggenerate=true;
		
		
    }

   
    if (isColliding(image10PosX, image10PosY+30, characterWidth, characterHeight,
                    zom1PosX+40, zom1PosY-20, zom1Width-90, zom1Height-40))
    {
       zom1attack=true;
	   zom1PosX=1000+rand()%1000;
	   zom1generate=true;
	    

    }
    
   
    if (isColliding(image10PosX, image10PosY+30, characterWidth, characterHeight,
                    zom2PosX+40, zom1PosY-20, zom1Width-90, zom1Height-40))
    {
        zom2attack=true;
		zom2PosX=1000+rand()%1000;
		zom2generate=true;
		
	    

	}
	if (isColliding(image10PosX, image10PosY+30, characterWidth, characterHeight,
                    zom3PosX+40, zom3PosY, zom3Width-90, zom3Height))
    {
        zom3attack=true;
		zom3PosX=1000+rand()%1000;
	    

	}

	 
     
    iShowImage(backgroundImage1PosX, 0, 1100, 760, image8);
	iShowImage(backgroundImage2PosX, 0, 1100, 760, image8);

	if(showPause){
	iSetColor(0,0,0);
	iFilledRectangle(400,200,200,100);
	iSetColor(255,0,0);
	iText(430, 250, "Game is pause", GLUT_BITMAP_TIMES_ROMAN_24);}

	drawHealthBar( characterlife);
	if(dognumber>4 && zom1number>3 && zom2number>3){
	
	resetgame();
	level=2;

	
	}

     
}
else if(level==2 &&level!=1 &&level!=3){
	 
	
	iShowImage(0, 0, 1000, 600, image13);
    int backgroundWidth = 1000;
    int backgroundHeight = 600;
	int backgroundImage1PosX = backgroundImagePosX % backgroundWidth;
    int backgroundImage2PosX = (backgroundImagePosX + backgroundWidth) % backgroundWidth;

    iShowImage(backgroundImage1PosX, 100, backgroundWidth, backgroundHeight, image14);
    iShowImage(backgroundImage2PosX, 100, backgroundWidth, backgroundHeight, image14);

    if (backgroundImagePosX <= -backgroundWidth || backgroundImagePosX>0)
    {
        backgroundImagePosX = 0;
    }
	
	
	  
	
	 scorecounter();
	 
	  if(doggenerate){
	  dognumber++;
	  doggenerate=false;
	  }

	  if(zom1generate){
	  zom1number++;
	  zom1generate=false;
	  }

	  if(zom2generate){
	  zom2number++;
	  zom2generate=false;
	  
	  }


	
	if(dogattack){
	characterlife=characterlife-100;
	dogattack=false;
	}
	 if(zom1attack)
	{
	characterlife=characterlife-50;
	zom1attack=false;
	
	}
	if(zom2attack){
	characterlife=characterlife-50;
	zom2attack=false;
	}

	 if(zom3attack){
	characterlife=characterlife-200;
	zom3attack=false;
	}
	

    for (int i = 0; i <1000; i++) {
        if (bullets[i].bulletVisible) {
            iShowImage(bullets[i].bulletPosX, bullets[i].bulletPosY + 40, bulletWidth, bulletHeight, image9);
        }
    }

	if (!isShooting && !isMovingRight && !isMovingLeft)
    {
        if (isStandingRight)
        {
            iShowImage(image10PosX, image10PosY-30, 100, 100, standingImageRight[CharacterFrame]);
        }
        else if (isStandingLeft)
        {
            iShowImage(image10PosX, image10PosY-30, 100, 100, standingImageLeft[CharacterFrame]);
        }
    }
    else
    {
        if (isShooting)
        {
            if (isMovingRight||isStandingRight)
            {
                iShowImage(image10PosX, image10PosY-30, 100, 100, shootImage[CharacterFrame]);
				isShootingcounter++;
				if(isShootingcounter>=100){
                  isShooting=false;
				  isShootingcounter=0;
				
				}
            }
        }
        else
        {
            if (isMovingRight)
            {
                iShowImage(image10PosX, image10PosY-30, 100, 100, runImageRight[CharacterFrame]);
				standcounter++;
				if(standcounter>=500){
				isMovingRight=false;
				isStandingRight=true;
				standcounter=0;
				}
				
            }
            else if (isMovingLeft)
            {
                iShowImage(image10PosX, image10PosY-30, 100, 100, runImageLeft[CharacterFrame]);
				standcounter++;
				if(standcounter>=500){
				isMovingLeft=false;
				isStandingLeft=true;
				standcounter=0;
				}
            }
            else if (isStandingRight)
            {
                iShowImage(image10PosX, image10PosY-30, 100, 100, standingImageRight[CharacterFrame]);
            }
            else if (isStandingLeft)
            {
                iShowImage(image10PosX, image10PosY-30, 100, 100, standingImageLeft[CharacterFrame]);
            }
			else if(isJumping){
				
				iShowImage(image10PosX, image10PosY-30, 100, 100, jumpImages[CharacterFrame]);
			}
        }
    }

	 
    if (isHurt)
    {
        iShowImage(dogPosX, dogPosY-30, dogWidth, dogHeight, dogHurtImages[currentHurtDogFrame]);
    }
    else
    {
        iShowImage(dogPosX, dogPosY-30, dogWidth, dogHeight, dogImages[currentDogFrame]);
    }
	if (isZom1Hurt)
    {
        iShowImage(zom1PosX, zom1PosY-30, zom1Width, zom1Height, zom1HurtImages[currentHurtzom1Frame]);
	
    }
    else
    {
        iShowImage(zom1PosX, zom1PosY-30, zom1Width, zom1Height, zom1Images[currentzom1Frame]);
    }
	if (isZom2Hurt)
    {
        iShowImage(zom2PosX, zom1PosY-30, zom1Width, zom1Height, zom1HurtImages[currentHurtzom1Frame]);
    }
    else
    {
        iShowImage(zom2PosX, zom1PosY-30, zom1Width, zom1Height, zom1Images[currentzom1Frame]);
    }
	if (isZom3Hurt)
    {
        iShowImage(zom3PosX, zom3PosY-30, zom3Width, zom3Height, zom3Images[currentzom3Frame]);
    }
    else
    {
        iShowImage(zom3PosX, zom3PosY-30, zom3Width, zom3Height, zom3Images[currentzom3Frame]);
	}
	

	
   
    if (isColliding(image10PosX, image10PosY, characterWidth, characterHeight,
                    dogPosX+50, dogPosY-30, dogWidth-50, dogHeight-20))
    {
         dogattack=true;
		 dogPosX=1000+rand()%1000;
		 doggenerate=true;
		
		
    }

   
    if (isColliding(image10PosX, image10PosY, characterWidth, characterHeight,
                    zom1PosX+40, zom1PosY-50, zom1Width-90, zom1Height-40))
    {
       zom1attack=true;
	   zom1PosX=1000+rand()%1000;
	   zom1generate=true;
	    

    }
    
   
    if (isColliding(image10PosX, image10PosY, characterWidth, characterHeight,
                    zom2PosX+40, zom1PosY-50, zom1Width-90, zom1Height-40))
    {
        zom2attack=true;
		zom2PosX=1000+rand()%1000;
		zom2generate=true;
		
	    

	}
	if (isColliding(image10PosX, image10PosY, characterWidth, characterHeight,
                    zom3PosX+40, zom3PosY-30, zom3Width-90, zom3Height))
    {
        zom3attack=true;
		zom3PosX=1000+rand()%1000;
	    

	}
	
	if(dognumber >2 && zom1number>3 && zom2number>3 ){
	   resetgame();
	
	  level=3;
	

	
	}
	if(showPause){
	iSetColor(0,0,0);
	iFilledRectangle(400,200,200,100);
	iSetColor(255,0,0);
	iText(430, 250, "Game is pause", GLUT_BITMAP_TIMES_ROMAN_24);}


	drawHealthBar( characterlife);
	

}
else if(level==3 &&level!=1 &&level!=2){
	
	iShowImage(0,-200, 1000, 800, image15);
    int backgroundWidth = 1000;
    int backgroundHeight = 600;
	int backgroundImage1PosX = backgroundImagePosX % backgroundWidth;
    int backgroundImage2PosX = (backgroundImagePosX + backgroundWidth) % backgroundWidth;

    iShowImage(backgroundImage1PosX, 150, backgroundWidth, backgroundHeight, image16);
    iShowImage(backgroundImage2PosX, 150, backgroundWidth, backgroundHeight, image16);

    if (backgroundImagePosX <= -backgroundWidth || backgroundImagePosX>0)
    {
        backgroundImagePosX = 0;
    }
	
	
	  
	
	 scorecounter();
	 
	  if(doggenerate){
	  dognumber++;
	  doggenerate=false;
	  }

	  if(zom1generate){
	  zom1number++;
	  zom1generate=false;
	  }

	  if(zom2generate){
	  zom2number++;
	  zom2generate=false;
	  
	  }


	
	if(dogattack){
	characterlife=characterlife-100;
	dogattack=false;
	}
	 if(zom1attack)
	{
	characterlife=characterlife-50;
	zom1attack=false;
	
	}
	if(zom2attack){
	characterlife=characterlife-50;
	zom2attack=false;
	}

	 if(zom3attack){
	characterlife=characterlife-200;
	zom3attack=false;
	}
	
	 

    for (int i = 0; i <1000; i++) {
        if (bullets[i].bulletVisible) {
            iShowImage(bullets[i].bulletPosX, bullets[i].bulletPosY + 40, bulletWidth, bulletHeight, image9);
        }
    }

	if (!isShooting && !isMovingRight && !isMovingLeft)
    {
        if (isStandingRight)
        {
            iShowImage(image10PosX, image10PosY-30, 100, 100, standingImageRight[CharacterFrame]);
        }
        else if (isStandingLeft)
        {
            iShowImage(image10PosX, image10PosY-30, 100, 100, standingImageLeft[CharacterFrame]);
        }
    }
    else
    {
        if (isShooting)
        {
            if (isMovingRight||isStandingRight)
            {
                iShowImage(image10PosX, image10PosY-30, 100, 100, shootImage[CharacterFrame]);
				isShootingcounter++;
				if(isShootingcounter>=100){
                  isShooting=false;
				  isShootingcounter=0;
				
				}
            }
        }
        else
        {
            if (isMovingRight)
            {
                iShowImage(image10PosX, image10PosY-30, 100, 100, runImageRight[CharacterFrame]);
				standcounter++;
				if(standcounter>=500){
				isMovingRight=false;
				isStandingRight=true;
				standcounter=0;
				}
				
            }
            else if (isMovingLeft)
            {
                iShowImage(image10PosX, image10PosY-30, 100, 100, runImageLeft[CharacterFrame]);
				standcounter++;
				if(standcounter>=500){
				isMovingLeft=false;
				isStandingLeft=true;
				standcounter=0;
				}
            }
            else if (isStandingRight)
            {
                iShowImage(image10PosX, image10PosY-30, 100, 100, standingImageRight[CharacterFrame]);
            }
            else if (isStandingLeft)
            {
                iShowImage(image10PosX, image10PosY-30, 100, 100, standingImageLeft[CharacterFrame]);
            }
			else if(isJumping){
				
				iShowImage(image10PosX, image10PosY-30, 100, 100, jumpImages[CharacterFrame]);
			}
        }
    }

	 
    if (isHurt)
    {
        iShowImage(dogPosX, dogPosY-30, dogWidth, dogHeight, dogHurtImages[currentHurtDogFrame]);
    }
    else
    {
        iShowImage(dogPosX, dogPosY-30, dogWidth, dogHeight, dogImages[currentDogFrame]);
    }
	if (isZom1Hurt)
    {
        iShowImage(zom1PosX, zom1PosY-30, zom1Width, zom1Height, zom1HurtImages[currentHurtzom1Frame]);
	
    }
    else
    {
        iShowImage(zom1PosX, zom1PosY-30, zom1Width, zom1Height, zom1Images[currentzom1Frame]);
    }
	if (isZom2Hurt)
    {
        iShowImage(zom2PosX, zom1PosY-30, zom1Width, zom1Height, zom1HurtImages[currentHurtzom1Frame]);
    }
    else
    {
        iShowImage(zom2PosX, zom1PosY-30, zom1Width, zom1Height, zom1Images[currentzom1Frame]);
    }
	if (isZom3Hurt)
    {
        iShowImage(zom3PosX, zom3PosY-30, zom3Width, zom3Height, zom3Images[currentzom3Frame]);
    }
    else
    {
        iShowImage(zom3PosX, zom3PosY-30, zom3Width, zom3Height, zom3Images[currentzom3Frame]);
	}
	

	
   
    if (isColliding(image10PosX, image10PosY, characterWidth, characterHeight,
                    dogPosX+50, dogPosY-30, dogWidth-50, dogHeight-20))
    {
         dogattack=true;
		 dogPosX=1000+rand()%1000;
		 doggenerate=true;
		
		
    }

   
    if (isColliding(image10PosX, image10PosY, characterWidth, characterHeight,
                    zom1PosX+40, zom1PosY-50, zom1Width-90, zom1Height-40))
    {
      zom1attack=true;
	   zom1PosX=1000+rand()%1000;
	   zom1generate=true;
	    

    }
    
   
    if (isColliding(image10PosX, image10PosY, characterWidth, characterHeight,
                    zom2PosX+40, zom1PosY-50, zom1Width-90, zom1Height-40))
    {
        zom2attack=true;
		zom2PosX=1000+rand()%1000;
		zom2generate=true;
		
	    

	}
	if (isColliding(image10PosX, image10PosY, characterWidth, characterHeight,
                    zom3PosX+40, zom3PosY-30, zom3Width-90, zom3Height))
    {
        zom3attack=true;
		zom3PosX=1000+rand()%1000;
	    

	}

	if(showPause){
	iSetColor(0,0,0);
	iFilledRectangle(400,200,200,100);
	iSetColor(255,0,0);
	iText(430, 250, "Game is pause", GLUT_BITMAP_TIMES_ROMAN_24);}



	drawHealthBar( characterlife);
	if(dognumber>3 && zom1number>3 && zom2number>2){
	nation=false;
	
	
	}

}


}
else{
	  
	
	 nation =false;
}

}
   


void iKeyboard(unsigned char key)
{
    if (key == 'q')
    {  
		
		exit(0);
    }

    if (key == 32  && gamestage!=1)
    {
        loadImage2 = true;
        gamestage = 0;
    }
    if (key == 'f'&&nation) {

         isShooting = true;
		 if(gunSound){
		     musicOn1=false;
			*musicOn1Ptr=false;
			
			

			PlaySound("sound//gun.wav", NULL, SND_ASYNC);
			gunSound=false;

	}
		     musicOn1=false;
			*musicOn1Ptr=false;
			
			
			if(musicOn2)
			PlaySound("sound//3.wav", NULL, SND_ASYNC | SND_LOOP);

         int index = -1;
         for (int i = 0; i < 1000; i++) {
            if (!bullets[i].bulletVisible) {
                index = i;
                break;
            }
        }

		 if (index != -1) {
            bullets[index].bulletPosX = image10PosX + 60;
			if(level==1){
				bullets[index].bulletPosY = image10PosY-10;}
			 else if(level ==2 || level ==3){
			 bullets[index].bulletPosY = image10PosY-30;
			
			}
            bullets[index].bulletVisible = true;
        }
		  
}
    if (key == 'd'&&nation)
    {
        if (image10PosX < 600)
        {
            image10PosX += 2;
            isMovingRight = true;
            isMovingLeft = false;
            isStandingRight = false;
            isStandingLeft = false;
            isShooting = false;
            
        }
		backgroundImagePosX -= backgroundSpeed;
        if (backgroundImagePosX <= -1000)
            backgroundImagePosX = 0;
    }
    if (key == 'a'&& nation)
    {
        if (image10PosX > 0)
            image10PosX -= 5;
        backgroundImagePosX += backgroundSpeed;
        isMovingRight = false;
        isMovingLeft = true;
        isStandingRight = false;
        isStandingLeft = false;
        isShooting = false;
        if (backgroundImagePosX >= 1000)
            backgroundImagePosX = 0;
    }
	if (key == 'w'&&nation) 
    {
        if (canJump && !isJumping) 
        {
            isJumping = true;
			bulletPosY = image10PosY;
            jumpStartTime = GetTickCount();
			
        }
    }
	if(key=='m' && nation ){
	   


	  showPause=false;
	  
	  resume();

	  musicOn2=true;
	  if(musicOn2)
			PlaySound("sound//3.wav", NULL, SND_ASYNC | SND_LOOP);

	  
	  
	
	
	}
	if(key=='n' && nation ){
	  

	  showPause=true;
	  pause();

	  PlaySound(0, 0, 0);
	  musicOn2=false;
	  
	
	
	}	
	
	if(!nation)
	{
		if(key == '\r')
        {     
			int e;
            str[len]='\0';
			p[5].score=getScore();
            strcpy_s(p[5].name, str);
            SortPlayer(6);
            for(e = 0; e < len; e++)
                str[e] = 0;
            len = 0;
            FILE *fp=fopen("score.bin","wb");
			for(int j=0;j<5;j++)
			fwrite(p+j,sizeof(Player),1,fp);
			fclose(fp);
			
			nation=true;
			if(nation){
			  gamestage =0;
			  characterlife=1000;
			  killscore=0;
			   level=1;
			  resetgame();
			  gunSound=false;

			  PlaySound(0, 0, 0);
			  musicOn2=true;
			  if(musicOn1)
			PlaySound("sound//1.wav", NULL, SND_ASYNC | SND_LOOP);
			 


			}
			
			

        }
        else
        {
            if(key>='a'&&key<='z')
            {
                str[len++] = key;
            }
            else if(key>='A'&&key<='Z')
            {
                str[len++] = key;
            }
        }
	}
}



void zomMovementTimer()
{
    if (isZom1Hurt)
    {   
		killscore=killscore+30;
		
        zom1PosX = 1000+rand()%1000;;
		zom1generate=true;
        currentzom1Frame = 0;
        isZom1Hurt = false;
    }
    else
    {
        zom1PosX -= 30;
    }

    if (zom1PosX <= -zom1Width)
    {
        zom1PosX = 1000+rand()%1000;;
		zom1generate=true;
        currentzom1Frame = 0;
    }

    for (int i = 0; i < 1000; i++) {
        if (bullets[i].bulletVisible) {
            bullets[i].bulletPosX += bulletSpeed;

   if (bullets[i].bulletPosX + bulletWidth >= zom1PosX && bullets[i].bulletPosX <= zom1PosX + zom1Width &&
                bullets[i].bulletPosY + bulletHeight >= zom1PosY && bullets[i].bulletPosY <= zom1PosY + zom1Height) {
                isZom1Hurt= true;
                bullets[i].bulletVisible = false;
                bullets[i].bulletPosX = image10PosX + 60;
                bullets[i].bulletPosY = image10PosY;
            }


       
         if (bullets[i].bulletPosX >= screenWidth) {
                bullets[i].bulletVisible = false;
                bullets[i].bulletPosX = image10PosX + 60;
                bullets[i].bulletPosY = image10PosY;
            }
        }
    }

  if (isZom2Hurt)
    {
		killscore=killscore+30;
		
        zom2PosX = 1000+rand()%1000;
		zom2generate=true;
        currentzom1Frame = 0;
        isZom2Hurt = false;
    }
    else
    {
        zom2PosX -= 30;
    }

    if (zom2PosX <= -zom1Width)
    {
        zom2PosX = 1000+rand()%1000;
		zom2generate=true;
        currentzom1Frame = 0;
    }

    for (int i = 0; i < 1000; i++) {
        if (bullets[i].bulletVisible) {
            bullets[i].bulletPosX += bulletSpeed;

     if (bullets[i].bulletPosX + bulletWidth >= zom2PosX && bullets[i].bulletPosX <= zom2PosX + zom2Width &&
      bullets[i].bulletPosY + bulletHeight >= zom2PosY && bullets[i].bulletPosY <= zom2PosY + zom2Height) {
      isZom2Hurt = true;
                bullets[i].bulletVisible = false;
                bullets[i].bulletPosX = image10PosX + 60;
                bullets[i].bulletPosY = image10PosY;
            }


       
         if (bullets[i].bulletPosX >= screenWidth) {
                bullets[i].bulletVisible = false;
                bullets[i].bulletPosX = image10PosX + 60;
                bullets[i].bulletPosY = image10PosY;
            }
        }
    }

	if (isZom3Hurt)
    {
        zom3PosX = 1000+rand()%1000;
        currentzom3Frame = 0;
        isZom3Hurt = false;
    }
    else
    {
        zom3PosX -= 30;
    }

    if (zom3PosX <= -zom3Width)
    {
        zom3PosX = 1000+rand()%1000;
        currentzom3Frame = 0;
    }

    for (int i = 0; i < 1000; i++) {
        if (bullets[i].bulletVisible) {
            bullets[i].bulletPosX += bulletSpeed;

   if (bullets[i].bulletPosX + bulletWidth >= zom2PosX && bullets[i].bulletPosX <= zom2PosX + zom1Width &&
                bullets[i].bulletPosY + bulletHeight >= zom1PosY && bullets[i].bulletPosY <= zom1PosY + zom1Height) {
                isZom3Hurt = false;
                bullets[i].bulletVisible = false;
                bullets[i].bulletPosX = image10PosX + 60;
                bullets[i].bulletPosY = image10PosY;
            }


       
         if (bullets[i].bulletPosX >= screenWidth) {
                bullets[i].bulletVisible = false;
                bullets[i].bulletPosX = image10PosX + 60;
                bullets[i].bulletPosY = image10PosY;
            }
        }
    }
	if (isHurt)
    {    
		killscore=killscore+50;
		
        dogPosX = 1000+rand()%1000; 
		doggenerate=true;
        currentDogFrame = 0;
        isHurt = false;
    }
    else
    {
        dogPosX -= 50;
    }

    if (dogPosX <= -dogWidth)
    {
        dogPosX = 1000+rand()%1000;
		doggenerate=true;
        currentDogFrame = 0;
    }

   
        
for (int i = 0; i < 1000; i++) {
        if (bullets[i].bulletVisible) {
            bullets[i].bulletPosX += bulletSpeed;

   if (bullets[i].bulletPosX + bulletWidth >= dogPosX && bullets[i].bulletPosX <= dogPosX + dogWidth &&
                bullets[i].bulletPosY + bulletHeight >= dogPosY && bullets[i].bulletPosY <= dogPosY + dogHeight) {
                isHurt = true;
                bullets[i].bulletVisible = false;
                bullets[i].bulletPosX = image10PosX + 60;
                bullets[i].bulletPosY = image10PosY;
            }


       
         if (bullets[i].bulletPosX >= screenWidth) {
                bullets[i].bulletVisible = false;
                bullets[i].bulletPosX = image10PosX + 60;
                bullets[i].bulletPosY = image10PosY;
            }
        }
    }


    

}
void gameOver()
{        
	if(characterlife>1){
	   iShowImage(0, 0, 1000, 600, image17);
	}
	else{
		iShowImage(0, 0, 1000, 600, image12);
	}
		iSetColor(0, 0, 0);
		
		iFilledRectangle(250, 200, 450, 120);
		iSetColor(255, 255, 255);
		iText(290, 230, "Name:", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 255, 255);
		iText(260, 270, "Your score is :", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 255, 255);
		iText(410, 270,stringConverter(killscore) , GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(150, 150, 150);
        iRectangle(400, 230, 250, 30);
        iSetColor(255, 255, 255);
        iText(410, 240, str);
		 musicOn1=true;
			  if (musicOn1){
				  PlaySound("sound//1.wav", NULL, SND_ASYNC | SND_LOOP);}

		
}
 void isettimer(){
    iSetTimer(20, jump);
    
    
	iSetTimer(200, FrameTimer);
    
    iSetTimer(500, zomMovementTimer);
	
    iSetTimer(500, blinkText);
	


	}

void iDraw()
{ 
	
    iClear();
	 
	
	
	

    if (loadImage2)
    {
        switch (gamestage)
        {
        case 0:
            menubar();
			pause();
            break;
        case 1:
			
			gamestage2();
            break;
        case 2:
           story(); 
			
            break;
        case 3:
            instruction();
            break;
        case 4:
            us();
            break;
        case 5:
            highscore();
			showscore();
            break;
        default:
            break;
        }
    }
    else
    {
        Startingpage();
    }
	if(nation==false)
	{
		gameOver();
		
	}
	
    iSetColor(255, 0, 0);
    iText(50, 10, "Press q to exit", GLUT_BITMAP_TIMES_ROMAN_24);
}



  
int main()
{    
	
	
	
    
	Player xyz;
	int j=0;
    FILE *fp=fopen("score.bin","rb");
    while(fread(&xyz,sizeof(Player),1,fp))
    {
      p[j++].setPlayer(xyz);
    }
	fclose(fp);
	

	if(level==1||level==3||level==2){
	 
		isettimer();
	
	}

	

	
    iInitialize(screenWidth, screenHeight, "Game");
    loadImage();

    loadImage2 = false;
	  

    gamestage = 0;
    if (musicOn1)
        PlaySound("sound//1.wav", NULL, SND_ASYNC | SND_LOOP);

    iStart();

    return 0;
}