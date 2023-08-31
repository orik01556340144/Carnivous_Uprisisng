
#include "iGraphics.h"
int image1, image2, image3, image4, image5, image6, image7, image8, image9, image10, image11,image12,image13,image14,image15,image16,image17,image18;

int dogImages[11];
int dogHurtImages[5];

int zom1HurtImages[4];
int zom1Images[10];

int zom3Images[6];

int standingImageRight[3];
int standingImageLeft[3];
int runImageRight[3];
int runImageLeft[3];
int shootImage[3];
int jumpImages[3];

int healthbar[10];


void loadImage()
{
    image1 = iLoadImage("images\\bc\\1.png");
    image2 = iLoadImage("images\\bc\\2.png");
    image3 = iLoadImage("images\\bc\\3.png");
    image4 = iLoadImage("images\\bc\\4.png");
    image5 = iLoadImage("images\\bc\\5.png");
    image6 = iLoadImage("images\\bc\\6.png");
    image7 = iLoadImage("images\\bc\\7.png");
	image11 = iLoadImage("images\\bc\\9.png");
    image8 = iLoadImage("images\\bc\\car1.png");
    image9 = iLoadImage("images\\1.png");
    image10 = iLoadImage("images\\1.bmp");
	image12=  iLoadImage("images\\bc\\8.jpg");
	image13= iLoadImage("images\\bc\\10.png");
	image14= iLoadImage("images\\bc\\11.png");
	image15= iLoadImage("images\\bc\\12.png");
	image16= iLoadImage("images\\bc\\13.png");
	image17= iLoadImage("images\\bc\\win.png");
	image18= iLoadImage("images\\bc\\us.png");

    dogImages[0] = iLoadImage("images\\dog\\1.png");
    dogImages[1] = iLoadImage("images\\dog\\2.png");
    dogImages[2] = iLoadImage("images\\dog\\3.png");
    dogImages[3] = iLoadImage("images\\dog\\4.png");
    dogImages[4] = iLoadImage("images\\dog\\5.png");
    dogImages[5] = iLoadImage("images\\dog\\6.png");
    dogImages[6] = iLoadImage("images\\dog\\7.png");
    dogImages[7] = iLoadImage("images\\dog\\8.png");
    dogImages[8] = iLoadImage("images\\dog\\9.png");
    dogImages[9] = iLoadImage("images\\dog\\10.png");
    dogImages[10] = iLoadImage("images\\dog\\11.png");
    dogHurtImages[0] = iLoadImage("images\\dog\\12.png");
    dogHurtImages[1] = iLoadImage("images\\dog\\13.png");
    dogHurtImages[2] = iLoadImage("images\\dog\\14.png");
    dogHurtImages[3] = iLoadImage("images\\dog\\15.png");
    dogHurtImages[4] = iLoadImage("images\\dog\\16.png");


	standingImageRight[0] = iLoadImage("images\\standingright\\1.png");
    standingImageRight[1] = iLoadImage("images\\standingright\\2.png");
    standingImageRight[2] = iLoadImage("images\\standingright\\3.png");

    standingImageLeft[0] = iLoadImage("images\\standingleft\\1.png");
    standingImageLeft[1] = iLoadImage("images\\standingleft\\2.png");
    standingImageLeft[2] = iLoadImage("images\\standingleft\\3.png");

    runImageRight[0] = iLoadImage("images\\Runningright\\1.png");
    runImageRight[1] = iLoadImage("images\\Runningright\\2.png");
    runImageRight[2] = iLoadImage("images\\Runningright\\3.png");
   

    runImageLeft[0] = iLoadImage("images\\runningleft\\1.png");
    runImageLeft[1] = iLoadImage("images\\runningleft\\2.png");
    runImageLeft[2] = iLoadImage("images\\runningleft\\3.png");
    

    shootImage[0] = iLoadImage("images\\Shooting\\1.png");
    shootImage[1] = iLoadImage("images\\Shooting\\2.png");
    shootImage[2] = iLoadImage("images\\Shooting\\3.png");

	jumpImages[0] = iLoadImage("images\\zom1\\1.png");
    jumpImages[1] = iLoadImage("images\\zom1\\1.png");
    jumpImages[2] = iLoadImage("images\\zom1\\1.png");

	zom1Images[0] = iLoadImage("images\\zom1\\1.png");
    zom1Images[1] = iLoadImage("images\\zom1\\2.png");
    zom1Images[2] = iLoadImage("images\\zom1\\3.png");
    zom1Images[3] = iLoadImage("images\\zom1\\4.png");
    zom1Images[4] = iLoadImage("images\\zom1\\5.png");
    zom1Images[5] = iLoadImage("images\\zom1\\6.png");
    zom1Images[6] = iLoadImage("images\\zom1\\7.png");
    zom1Images[7] = iLoadImage("images\\zom1\\8.png");
    zom1Images[8] = iLoadImage("images\\zom1\\9.png");
    zom1Images[9] = iLoadImage("images\\zom1\\10.png");
   
    zom1HurtImages[0] = iLoadImage("images\\zom1\\11.png");
    zom1HurtImages[1] = iLoadImage("images\\zom1\\12.png");
    zom1HurtImages[2] = iLoadImage("images\\zom1\\13.png");
    zom1HurtImages[3] = iLoadImage("images\\zom1\\14.png");

	zom3Images[0] = iLoadImage("images\\zom3\\1.png");
    zom3Images[1] = iLoadImage("images\\zom3\\2.png");
    zom3Images[2] = iLoadImage("images\\zom3\\3.png");
    zom3Images[3] = iLoadImage("images\\zom3\\4.png");
    zom3Images[4] = iLoadImage("images\\zom3\\5.png");
    zom3Images[5] = iLoadImage("images\\zom3\\6.png");

	healthbar[9] = iLoadImage("images\\healthbar\\1.png");
	healthbar[8] = iLoadImage("images\\healthbar\\2.png");
	healthbar[7] = iLoadImage("images\\healthbar\\3.png");
	healthbar[6] = iLoadImage("images\\healthbar\\4.png");
	healthbar[5] = iLoadImage("images\\healthbar\\5.png");
	healthbar[4] = iLoadImage("images\\healthbar\\6.png");
	healthbar[3] = iLoadImage("images\\healthbar\\7.png");
	healthbar[2] = iLoadImage("images\\healthbar\\8.png");
	healthbar[1] = iLoadImage("images\\healthbar\\9.png");
	healthbar[0] = iLoadImage("images\\healthbar\\10.png");
	
	
	
    
    

}