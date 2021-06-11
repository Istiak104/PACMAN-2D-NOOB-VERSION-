/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"
#include<math.h>
#include<windows.h>


//==========================================
//      controls
//==========================================

// a for amp decrease
// A for amp increase
// f for f increase
// F for freq decrease
// q for backscreen









int baseCurve(int amp,double freq,int x,double phase);
int sumCurve(int x, double phase);

int x[100];
int y[100];
int total;
int ballCount=1;
int amp=100;
int freq=2*3.1416*50;
int showLine=1;
int xSpeed=3;
int screen=1;
int a=3;
int direction=1; //right is 1 left is 2
int curvesAmpArray[]={100,200,300,100,200,500};
double curvesFreqArray[]={2*3.1416*1000,2*3.1416*2000,2*3.1416*3000,2*3.1416*2500,2*3.1416*300,2*3.1416*3500};
int ballsX[]={0,0,0,0,0,0};
int ballsY[]={500,500,500,500,500,500};
int ballSumX=0;
int ballSumY=0;
int ballSumExist=0;
int ballsExist[]={0,0,0,0,0,0};
int ballsColor[]={0xE62272,0xE62272,0xE62272,0xA7FF83,0x9C1DE7,0xC5E3F6};
double phase[]={0,1,0,1,0,0};
double lambda[]={.020,200,200,200,.002};
/*
	function iDraw() is called again and again by the system.
*/

void changeBall(){
    if(screen==2){
            //we create all the balls and waves but don't show them
        for(int i=0;i<6;i++){
           /* if(ballsX[i]>1000){
                xSpeed=-a;
            }
            if (ballsX[i]<0){
                xSpeed=a;
            }
            ballsX[i]+=xSpeed;
            */
            //if(ballsX[i]>1000) xSpeed=-xSpeed;
            //if(ballsX[i]<=0) ballsX[i]+=xSpeed;
            //if(ballsX[i]>=1000) ballsX[i]+=xSpeedNeg
            if(ballsX[i]<0) direction=1;
            if(ballsX[i]>1000) direction=2;
            if(direction==1) ballsX[i]+=a;
            if(direction==2) ballsX[i]-=a;
            ballsY[i]=baseCurve(curvesAmpArray[i],curvesFreqArray[i],ballsX[i],phase[i])+500;
        }

        if(ballSumX<0) direction=1;
            if(ballSumX>1000) direction=2;
            if(direction==1) ballSumX+=a;
            if(direction==2) ballSumX-=a;
            ballSumY=sumCurve(ballSumX,phase[0])+500;


    }

}




int baseCurve(int amp,double freq,int x,double phase){
    return (amp*sin(freq*x+(phase*1.57)));

}
int sumCurve(int x, double phase){
    int sum=0;
    for(int i=0;i<ballCount;i++){
        sum+=baseCurve(curvesAmpArray[i],curvesFreqArray[i],x,phase);
    }
    return sum;

}

void firstScreen(){
        iClear();
        //iShowBMP (500,900,"1.bmp") ;

        //iShowBMP2(250,800,"F:/C Files/CSE 102/iGraphics/IGraphics-master/1.bmp",0xFFFFFF);
        //iShowBMP2(300,600,"F:/C Files/CSE 102/iGraphics/IGraphics-master/2.bmp",0xFFFFFF);
        //iShowBMP2(300,400,"F:/C Files/CSE 102/iGraphics/IGraphics-master/3.bmp",0xFFFFFF);
        //iShowBMP2(300,200,"F:/C Files/CSE 102/iGraphics/IGraphics-master/4.bmp",0xFFFFFF);
        iText(300,725,"WaveSim",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(350,700,"The best Wave simulator in town",GLUT_BITMAP_TIMES_ROMAN_24);
        //iText(400,525,"Boring version");
        iRectangle(300,500,300,50);
        iText(400,525,"Basic version");
        iRectangle(300,400,300,50);
        iText(390,425,"Enter graph type");
        iRectangle(300,300,300,50);
        iText(415,325,"Play Pong");
        iRectangle(300,200,300,50);
        iText(405,225,"Instructions");



        iText(10,10,"Salman Sayeed | 1905079");






        //iText(500,900,"Best peiodic GUI ever");
        //iText(600,880,"Salman Sayeed | 1905079");
}





void basicScreen(){
        iClear();
        if(showLine){

            for(int i=0;i<ballCount;i++){
                for(int j=0;j<1200;j++){
                    //iLine(j,(baseCurve(curvesAmpArray[i], curvesFreqArray[i], j, phase[i])+500),j+1,(baseCurve(curvesAmpArray[i], curvesFreqArray[i], j+1, phase[i])+500));
                    iPoint(j,(baseCurve(curvesAmpArray[i], curvesFreqArray[i], j, phase[i])+500));
                }

            }

        }
        //=============================SUM GRAPH===================================
        iSetColor(255,20,20);
        for(int j=0;j<1200;j++){
                    //iLine(j,(baseCurve(curvesAmpArray[i], curvesFreqArray[i], j, phase[i])+500),j+1,(baseCurve(curvesAmpArray[i], curvesFreqArray[i], j+1, phase[i])+500));
                    iPoint(j,(sumCurve(j, phase[0])+500));
                }

        iSetColor(255,255,255);
        if(ballSumExist) iFilledCircle(ballSumX,ballSumY,5);
        for(int i=0;i<ballCount;i++){
            //iCircle (ballsX[i],ballsY[i], 20,100);
            if(ballsExist[i]==1){
                if(i==0) iSetColor(255,0,0);
                if(i==1) iSetColor(0,255,0);
                if(i==2) iSetColor(0,0,255);
                if(i==3) iSetColor(72, 201, 176);
                if(i==4) iSetColor(156, 175, 249);
                if(i==5) iSetColor( 230, 134, 255 );
                if(i==6) iSetColor(156, 223, 229 );
                if(i==7) iSetColor(0,0,255);
                if(i==8) iSetColor(0,0,255);
                if(i==9) iSetColor(0,0,255);

                iFilledCircle (ballsX[i],ballsY[i], 5) ;
            }

        }
        iSetColor(255,255,255);

    }

//=====================
//  Screen 4
//=====================
int select1=0;
int select2=0;
int select3=0;
void graphScreen(){
    iClear();
    iText(380, 970, "Choose the type of your graph ");
    if(select1) iSetColor(150,150,150);
    else iSetColor(255,255,255);
    iText(190, 800, "Phase Difference 0deg");
    iText(190, 750, "Phase Difference 90deg");
    iText(190, 700, "Phase Difference 180deg");
    iText(190, 650, "Phase Difference 270deg");
    iText(210, 600, "First graph");


    iRectangle(180,780,200,50);
    iRectangle(180,730,200,50);
    iRectangle(180,680,200,50);
    iRectangle(180,630,200,50);

    if(select2) iSetColor(150,150,150);
    else iSetColor(255,255,255);
    iText(440, 800, "Phase Difference 0deg");
    iText(440, 750, "Phase Difference 90deg");
    iText(440, 700, "Phase Difference 180deg");
    iText(440, 650, "Phase Difference 270deg");
    iText(460, 600, "Second Graph");

    iRectangle(430,780,200,50);
    iRectangle(430,730,200,50);
    iRectangle(430,680,200,50);
    iRectangle(430,630,200,50);

    if(select3) iSetColor(150,150,150);
    else iSetColor(255,255,255);
    iText(690, 800, "Phase Difference 0deg");
    iText(690, 750, "Phase Difference 90deg");
    iText(690, 700, "Phase Difference 180deg");
    iText(690, 650, "Phase Difference 270deg");
    iText(710, 600, "Third Graph");

    iRectangle(680,780,200,50);
    iRectangle(680,730,200,50);
    iRectangle(680,680,200,50);
    iRectangle(680,630,200,50);


    iText(20, 10, "Press 'Enter' to continue");

}

//=====================
//  Global variables for pong
//=====================

int pong1y=200;
int pong2y=200;
int pongSpeed=30;
int ballx=500;
int bally=500;
int ballAmp=450;
double ballFreq=2*3.1416*500;
int ballSpeed=3;
int ballphase=0;
int ampChange=20;
int score1=0;
int score2=0;
int gameEnded=0;
int winner;


void pongScreen(){
    if(gameEnded){
        iClear();
        iSetColor(255,255,255);
        iText(450,500,"Game Ended");
        iSetColor(0,0,155);
        if(winner==1) iText(440,480,"Player 1 won");
        if(winner==2) iText(440,480,"Player 2 won");
    }else{
        iClear();
        iSetColor(255,255,255);
        iFilledRectangle(0,pong1y,20,200);
        iFilledRectangle(980,pong2y,20,200);
        iSetColor(255,0,0);
        iFilledCircle (ballx,bally, 10) ;

        //scores
        iSetColor(255,255,255);
        if(score1==0) iText(100,950,"0",GLUT_BITMAP_HELVETICA_18);
        if(score1==1) iText(100,950,"1",GLUT_BITMAP_HELVETICA_18);
        if(score1==2) iText(100,950,"2",GLUT_BITMAP_HELVETICA_18);
        if(score1==3) iText(100,950,"3",GLUT_BITMAP_HELVETICA_18);
        if(score1==4) iText(100,950,"4",GLUT_BITMAP_HELVETICA_18);

        if(score2==0) iText(900,950,"0",GLUT_BITMAP_HELVETICA_18);
        if(score2==1) iText(900,950,"1",GLUT_BITMAP_HELVETICA_18);
        if(score2==2) iText(900,950,"2",GLUT_BITMAP_HELVETICA_18);
        if(score2==3) iText(900,950,"3",GLUT_BITMAP_HELVETICA_18);
        if(score2==4) iText(900,950,"4",GLUT_BITMAP_HELVETICA_18);


    }
}
void pong1moveUp(){
    if(pong1y<800) pong1y+=pongSpeed;

}
void pong1moveDown(){
    if(pong1y>0) pong1y-=pongSpeed;
}


void pong2moveUp(){
    if(pong2y<800) pong2y+=pongSpeed;

}
void pong2moveDown(){
    if(pong2y>0) pong2y-=pongSpeed;
}
void pongScore(){
    if(ballx==20&&bally>=pong1y&&bally<=pong1y+200){
        ballSpeed=3;
        ballAmp-=ampChange;
        if(ballAmp<450&&ballAmp>350) ballAmp-=ampChange;
        else ampChange*=-1;

    }
    if(ballx==980&&bally>=pong2y&&bally<=pong2y+200){
        ballSpeed=-3;
        if(ballAmp<450&&ballAmp>350) ballAmp-=ampChange*=-1;

    }
    if(ballx>980){
        score1+=1;
        ballx=500;
        //printf("Score 1= %d score 2 = %d",score1,score2);
        Sleep(1000);
    }
    if(ballx<20){
        score2+=1;
        ballx=500;
        //printf("Score 1= %d score 2 = %d",score1,score2);
        Sleep(1000);
    }
    if(score1>4){
        printf("1 won!!");
        winner=1;
        gameEnded=1;
    }
    if(score2>4){
        printf("2 won!!");
        winner=2;
        gameEnded=1;
    }

}
void pongBallMove(){
    if(screen==3){
        ballx+=ballSpeed;
        bally=baseCurve(ballAmp,ballFreq,ballx,ballphase)+500;
        pongScore();

    }

}

void dampedScreen(){
       iClear();
        if(showLine){

            for(int i=0;i<ballCount;i++){
                for(int j=0;j<1200;j++){
                    //iLine(j,(baseCurve(curvesAmpArray[i], curvesFreqArray[i], j, phase[i])+500),j+1,(baseCurve(curvesAmpArray[i], curvesFreqArray[i], j+1, phase[i])+500));
                    if((curvesAmpArray[i]-j)>=0) {
                            //iPoint(j,(baseCurve(curvesAmpArray[i]-j, curvesFreqArray[i]*90, j, phase[i])+500));
                            iPoint(j*10,(baseCurve(curvesAmpArray[i]-j, curvesFreqArray[i]*25, j, phase[i])+500));
                            //iLine(j*10,(baseCurve(curvesAmpArray[i]-j, curvesFreqArray[i]*25, j, phase[i])+500),j*10+1,(baseCurve(curvesAmpArray[i]-j+1, curvesFreqArray[i]*25, j+1, phase[i])+500));
                    }
                }

            }

        }
        for(int i=0;i<ballCount;i++){
            //iCircle (ballsX[i],ballsY[i], 20,100);
            if(ballsExist[i]==1){
                if(i==0) iSetColor(255,0,0);
                if(i==1) iSetColor(0,255,0);
                if(i==2) iSetColor(0,0,255);
                if(i==3) iSetColor(72, 201, 176);
                if(i==4) iSetColor(156, 175, 249);
                if(i==5) iSetColor( 230, 134, 255 );
                if(i==6) iSetColor(156, 223, 229 );
                if(i==7) iSetColor(0,0,255);
                if(i==8) iSetColor(0,0,255);
                if(i==9) iSetColor(0,0,255);

                iFilledCircle (ballsX[i],ballsY[i], 5) ;
            }

        }
        iSetColor(255,255,255);






}

void instructions(){
    iClear();
    iText(100,880,"=========================================INSTRUCTIONS=========================================");
    iText(100,800,"Press 'q' to go to the previous screen");
    iText(100,780,"Press 'x' to quit app");
    iText(100,760,"");
    iText(100,740,"Press '+' to increase the velocity");
    iText(100,720,"Press '-' to decrease the velocity");
    iText(100,700,"Press 'pageUp' to add new waves");
    iText(100,680,"Press 'pageDown' to remove a wave");
    iText(100,660,"Press 'rightArrow' to increase phase by 30deg");
    iText(100,640,"Press 'leftArray' to decrease phase by 30deg");
    iText(100,620,"");
    iText(100,600,"Press 'a' to decrease amplitude");
    iText(100,580,"Press 'A' to increase amplitude");
    iText(100,560,"Press 'f' to increase frequency");
    iText(100,540,"Press 'F' to increase frequency");
    iText(100,520,"Press '1' '2' '3' '4' '5' '6' to show/hide corresponding ball");
    iText(100,500,"Press '0' to show/hide sum curve ball");
    iText(100,480,"");
    iText(100,460,"Press 'S' to show the curve lines");
    iText(100,440,"Press 's' to hide the curve lines");
    iText(100,420,"Press 'p' to pause the ball movement");
    iText(100,400,"Press 'r' to resume the ball movement");

}






void iDraw(){

	//place your drawing codes here

	if(screen==1) firstScreen();
	if(screen==2) basicScreen();
    if(screen==3) pongScreen();
    if(screen==4) graphScreen();
    if(screen==5) dampedScreen();
    if(screen==6) instructions();

}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(screen==1 && (mx>=300&&mx<=600)&&(my>=500&&my<=550))  screen=2;
    if(screen==1&&(mx>=300&&mx<=600)&&(my>=400&&my<=450))  screen=4;
    if(screen==1&&(mx>=300&&mx<=600)&&(my>=300&&my<=350))  screen=3;
    if(screen==1&&(mx>=300&&mx<=600)&&(my>=200&&my<=250))  screen=6;

    //==================================
    //  For screen 4
    //==================================
    if(screen==4 &&(mx>=180&&mx<=380)&&(my>=780&&my<=830)) {phase[0]=0; select1=1;}
    if(screen==4 &&(mx>=180&&mx<=380)&&(my>=730&&my<=780)) {phase[0]=1; select1=1;}
    if(screen==4 &&(mx>=180&&mx<=380)&&(my>=680&&my<=730)) {phase[0]=2; select1=1;}
    if(screen==4 &&(mx>=180&&mx<=380)&&(my>=630&&my<=680)) {phase[0]=3; select1=1;}

    if(screen==4 &&(mx>=430&&mx<=630)&&(my>=780&&my<=830)) {phase[1]=0; select2=1;}
    if(screen==4 &&(mx>=430&&mx<=630)&&(my>=730&&my<=780)) {phase[1]=1; select2=1;}
    if(screen==4 &&(mx>=430&&mx<=630)&&(my>=680&&my<=730)) {phase[1]=2; select2=1;}
    if(screen==4 &&(mx>=430&&mx<=630)&&(my>=630&&my<=680)) {phase[1]=3; select2=1;}

    if(screen==4 &&(mx>=680&&mx<=880)&&(my>=780&&my<=830)) {phase[2]=0; select3=1;}
    if(screen==4 &&(mx>=680&&mx<=880)&&(my>=730&&my<=780)) {phase[2]=1; select3=1;}
    if(screen==4 &&(mx>=680&&mx<=880)&&(my>=680&&my<=730)) {phase[2]=2; select3=1;}
    if(screen==4 &&(mx>=680&&mx<=880)&&(my>=630&&my<=680)) {phase[2]=3; select3=1;}


}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'x')
	{
		//do something with 'x'
		exit(0);
	}
	//======================================
	//  Code for screen 2
	//======================================

	if(screen==2&&key=='a'){
        for(int i=0;i<6;i++){
            curvesAmpArray[i]/=2;
        }
	}
	if(screen==2&&key=='A'){
        for(int i=0;i<6;i++){
            curvesAmpArray[i]*=2;
        }
	}
	if(screen==2&&key=='F'){
        for(int i=0;i<6;i++){
            curvesFreqArray[i]/=2;
        }
	}
	if(screen==2&&key=='f'){
        for(int i=0;i<6;i++){
            curvesFreqArray[i]*=2;
        }
	}
	if(screen==2&&key=='1'){
       if(ballsExist[0]==0){
            ballsExist[0]=1;
        }else{
            ballsExist[0]=0;
        }
	}
	if(screen==2&&key=='2'){
        if(ballsExist[1]==0){
            ballsExist[1]=1;
        }else{
            ballsExist[1]=0;
        }
	}
	if(screen==2&&key=='3'){
        if(ballsExist[2]==0){
            ballsExist[2]=1;
        }else{
            ballsExist[2]=0;
        }
	}
	if(screen==2&&key=='4'){
        if(ballsExist[3]==0){
            ballsExist[3]=1;
        }else{
            ballsExist[3]=0;
        }
	}
	if(screen==2&&key=='5'){
        if(ballsExist[4]==0){
            ballsExist[4]=1;
        }else{
            ballsExist[4]=0;
        }
	}
	if(screen==2&&key=='6'){
        if(ballsExist[5]==0){
            ballsExist[5]=1;
        }else{
            ballsExist[5]=0;
        }
	}
	if(screen==2&&key=='7'){
        if(ballsExist[6]==0){
            ballsExist[6]=1;
        }else{
            ballsExist[6]=0;
        }
	}
	if(screen==2&&key=='0'){
        if(ballSumExist==0){
            ballSumExist=1;
        }else{
            ballSumExist=0;
        }
	}
	if(screen==2 && key=='s') showLine=0;
	if(screen==2 && key=='S') showLine=1;
	if(screen==2 && key=='p') iPauseTimer(0);
	if(screen==2 && key=='r') iResumeTimer(0);

	if(screen==2&& key=='+'){
        if(a<7) a++;
	}
	if(screen==2&& key=='-'){
        if(a>0) a--;
	}


    //======================================
	//  Code for screen 3
	//======================================

	if(screen==3&&key=='w')   pong1moveUp();
	if(screen==3&&key=='s')   pong1moveDown();

	//======================================
	//  Code for screen 4
	//======================================
	if(screen==4&&key=='\r')  {
            screen=2;
            select1=0;
            select2=0;
            select3=0;
    }
	if(screen==4&&key=='q')   {
            screen=1;
            select1=0;
            select2=0;
            select3=0;
    }


    //======================================
	//  Code for screen 5
	//======================================

	if(screen==5&&key=='a'){
        for(int i=0;i<3;i++){
            curvesAmpArray[i]/=2;
        }
	}
	if(screen==5&&key=='A'){
        for(int i=0;i<3;i++){
            curvesAmpArray[i]*=2;
        }
	}
	if(screen==5&&key=='F'){
        for(int i=0;i<3;i++){
            curvesFreqArray[i]/=2;
        }
	}
	if(screen==5&&key=='f'){
        for(int i=0;i<3;i++){
            curvesFreqArray[i]*=2;
        }
	}
	if(screen==5&&key=='1'){
       if(ballsExist[0]==0){
            ballsExist[0]=1;
        }else{
            ballsExist[0]=0;
        }
	}
	if(screen==5&&key=='2'){
        if(ballsExist[1]==0){
            ballsExist[1]=1;
        }else{
            ballsExist[1]=0;
        }
	}
	if(screen==5&&key=='3'){
        if(ballsExist[2]==0){
            ballsExist[2]=1;
        }else{
            ballsExist[2]=0;
        }
	}
	if(screen==5&&key=='4'){
        if(ballsExist[3]==0){
            ballsExist[3]=1;
        }else{
            ballsExist[3]=0;
        }
	}
	if(screen==5&&key=='5'){
        if(ballsExist[4]==0){
            ballsExist[4]=1;
        }else{
            ballsExist[4]=0;
        }
	}
	if(screen==5&&key=='6'){
        if(ballsExist[5]==0){
            ballsExist[5]=1;
        }else{
            ballsExist[5]=0;
        }
	}
	if(screen==5&&key=='7'){
        if(ballsExist[6]==0){
            ballsExist[6]=1;
        }else{
            ballsExist[6]=0;
        }
	}
	if(screen==5 && key=='s') showLine=0;
	if(screen==5 && key=='S') showLine=1;

	if(screen==5&& key=='+'){
        if(a<7) a++;
	}
	if(screen==5&& key=='-'){
        if(a>0) a--;
	}

	//======================================
	//  Code for screen change
	//======================================
	if(screen==2 && key=='q') screen=1;
	if(screen==3 && key=='q') screen=1;
	if(screen==6 && key=='q') screen=1;
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	if(screen==3&&key==GLUT_KEY_UP)   pong2moveUp();
	if(screen==3&&key==GLUT_KEY_DOWN)   pong2moveDown();
	//place your codes for other keys
	//second screen
	if(screen==2&&key==GLUT_KEY_PAGE_UP){
        if (ballCount<7) ballCount++;
	}
	if(screen==2&&key==GLUT_KEY_PAGE_DOWN){
        if (ballCount>0) ballCount--;
	}
	if(screen==2&&key==GLUT_KEY_RIGHT){
        for(int i=0;i<6;i++){
            phase[i]+=.2;
        }
	}
	if(screen==2&&key==GLUT_KEY_LEFT){
        for(int i=0;i<6;i++){
            phase[i]-=.2;
        }
	}
	//screen 5
	if(screen==5&&key==GLUT_KEY_PAGE_UP){
        if (ballCount<7) ballCount++;
	}
	if(screen==5&&key==GLUT_KEY_PAGE_DOWN){
        if (ballCount>0) ballCount--;
	}
	if(screen==5&&key==GLUT_KEY_RIGHT){
        for(int i=0;i<6;i++){
            phase[i]+=.2;
        }
	}
	if(screen==5&&key==GLUT_KEY_LEFT){
        for(int i=0;i<6;i++){
            phase[i]-=.2;
        }
	}

}



int main()
{
	//place your own initialization codes here.
	total = 0;

	//timer needs to be before initialize
	iSetTimer(5,changeBall);
	iSetTimer(5,pongBallMove);

    //iSetTimer(5,allTimers);


	iInitialize(1000, 1000, "Curves 1905079");

	//iSetTimer(500,changeBall);
	return 0;
}
