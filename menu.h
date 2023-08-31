

char name[] = "Enter space for menu  ";
bool showText = true;

void Startingpage()
{
    iShowImage(0, 0, 1000, 600, image1);
    iSetColor(255, 255, 255);


    if (showText)
        iText(400, 100, name, GLUT_BITMAP_TIMES_ROMAN_24);
}

void blinkText()
{
    showText = !showText;
}

void menubar()
{
    iShowImage(0, 0, 1000, 600, image2);
    iSetColor(255, 255, 255);
    if (showText)
        iText(350, 50, "Left Press to select any option ", GLUT_BITMAP_TIMES_ROMAN_24);
}

void story()
{
    iShowImage(0, 0, 1000, 600, image3);
    iSetColor(255, 255, 255);
    if (showText)
        iText(350, 10, "Enter space for menu", GLUT_BITMAP_TIMES_ROMAN_24);
}

void instruction()
{
    iShowImage(0, 0, 1000, 600, image4);
    iSetColor(255, 255, 255);
    if (showText)
        iText(350, 10, "Enter space for menu", GLUT_BITMAP_TIMES_ROMAN_24);
}

void highscore()
{   
    iShowImage(0, 0, 1000, 600, image7);
    iSetColor(255, 255, 255);
    if (showText)
        iText(400, 50, "Enter space for menu", GLUT_BITMAP_TIMES_ROMAN_24);
	
	
	
}

void us()
{
    iShowImage(0, 0, 1000, 600, image18);
    iSetColor(255, 255, 255);
    if (showText)
        iText(350, 10, "Enter space for menu", GLUT_BITMAP_TIMES_ROMAN_24);
}
