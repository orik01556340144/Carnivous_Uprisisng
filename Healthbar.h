void drawHealthBar(int characterlife) {
    int numSegments = (characterlife ) / 100;

   
    numSegments = max(1, min(numSegments, 10));

   
    
     if (numSegments == 1) {
        iShowImage(650, 520, 300, 50, healthbar[0]);
    } else if (numSegments == 2) {
        iShowImage(650, 520, 300, 50, healthbar[1]);
    } else if (numSegments == 3) {
        iShowImage(650, 520, 300, 50, healthbar[2]);
    } else if (numSegments == 4) {
        iShowImage(650, 520, 300, 50, healthbar[3]);
    } else if (numSegments == 5) {
        iShowImage(650, 520, 300, 50, healthbar[4]);
    } else if (numSegments == 6) {
        iShowImage(650, 520, 300, 50, healthbar[5]);
    } else if (numSegments == 7) {
        iShowImage(650, 520, 300, 50, healthbar[6]);
    } else if (numSegments == 8) {
        iShowImage(650, 520, 300, 50, healthbar[7]);
    } else if (numSegments == 9) {
        iShowImage(650, 520, 300, 50, healthbar[8]);
    } else {
        iShowImage(650, 520, 300, 50, healthbar[9]); 
    }
}