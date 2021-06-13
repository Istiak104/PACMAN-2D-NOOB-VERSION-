

                                        /*AUTHOR:- KAZI ISTIAK UDDIN TORIQE ( With .)
                                        CSE 102 LEVEL-1 TERM-1  PROJECT*/

#include<windows.h>
#include<bits/stdc++.h>
#include "iGraphics.h"
#include"Ghost_Move.cpp"
#include<math.h>

using namespace std ;

void getHighscore()
{
    file=fopen("highscores.txt","r");
    for(int i=0;i<10;i++)
    {
        fgets(h[i].name,20,file);
        fgets(h[i].score,12,file);
    }
    fclose(file);
}


void putHighscore()
{
    file=fopen("highscores.txt","w");
    for(int i=0;i<10;i++)
    {
        fputs(h[i].name,file);
        fputs(h[i].score,file);
    }
    fclose(file);
}

void Sort_Highscore()
{
    char t1[12],t2[20];
    for(int i=0;i<11;i++)
    {
        for(int j=i+1;j<11; j++)
        {
            if(atoi(h[i].score)<atoi(h[j].score))
            {
                strcpy(t1,h[i].score);
                strcpy(t2,h[i].name);
                strcpy(h[i].score,h[j].score);
                strcpy(h[i].name,h[j].name);
                strcpy(h[j].score,t1);
                strcpy(h[j].name,t2);
            }
        }
    }
}

void save_game()
{
    file=fopen("S.txt","w");
    fprintf(file,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",screenHeight,screenWidth,pressed,keey[0],keey[1],boxLength,static_pacmouth,tim,target_x,target_y);
    fprintf(file,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",mini,mini1,mini2,mini3,mini4,maxi,maxi1,maxi2,maxi3,maxi4,g_u,g_l,g_r,g_d,flee_u,flee_l,flee_r,flee_d);
    fprintf(file,"%d\n%d\n%d\n",mazewidth,mazeheight,score);
    fprintf(file,"%d\n%d\n",scatter_mode,frightened_mode);
    fprintf(file,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",hide_mode,speed_mode,pause_mode_for_ghosts,call,call2,speed,call3,call4,call5,call6,PAUSE,fire_l,fire_r,fire_u,fire_d,gameover_calltime,fire_x,fire_y,fire_mode);
    fprintf(file,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",pac,pac_no,pacc.pox,pacc.poy,pacc.right,pacc.left,pacc.up,pacc.down,pacc.xx,pacc.yy);
    for(int i=0;i<4;i++)
    {
        fprintf(file,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",V[i].px,V[i].py,V[i]._x,V[i]._y,V[i].return_x,V[i].return_y,V[i].state,V[i].cnt,V[i].ghost_mode,V[i].die_mode,V[i].initial,V[i].scatter_x,V[i].scatter_y,V[i].no,V[i].a[12][9]);
    }
    for(int z=0;z<7;z++){
        for(int k=0;k<10;k++){
            for(int i=0;i<24;i++)
            {
                for(int j=0;j<22;j++)
                {
                    fprintf(file,"%d\n",ara[z][k][i][j]);
                }
            }
        }
    }
    fprintf(file,"%d\n%d\n%d\n%d\n",die,WIN,GAMEOVER,NAMETAKEN);
    fprintf(file,"%d\n%d\n%d\n",level,maze);
    fclose(file);
}


void load_game()
{
        file=fopen("S.txt","r");
        fscanf(file,"%d%d%d%d%d%d%d%d%d%d",&screenHeight,&screenWidth,&pressed,&keey[0],&keey[1],&boxLength,&static_pacmouth,&tim,&target_x,&target_y);
        fscanf(file,"%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",&mini,&mini1,&mini2,&mini3,&mini4,&maxi,&maxi1,&maxi2,&maxi3,&maxi4,&g_u,&g_l,&g_r,&g_d,&flee_u,&flee_l,&flee_r,&flee_d);
        fscanf(file,"%d%d%d",&mazewidth,&mazeheight,&score);
        fscanf(file,"%d%d",&scatter_mode,&frightened_mode);
        fscanf(file,"%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",&hide_mode,&speed_mode,&pause_mode_for_ghosts,&call,&call2,&speed,&call3,&call4,&call5,&call6,&PAUSE,&fire_l,&fire_r,&fire_u,&fire_d,&gameover_calltime,&fire_x,&fire_y,&fire_mode);
        fscanf(file,"%d%d%d%d%d%d%d%d%d%d",&pac,&pac_no,&pacc.pox,&pacc.poy,&pacc.right,&pacc.left,&pacc.up,&pacc.down,&pacc.xx,&pacc.yy);
        for(int i=0;i<4;i++)
        {
            fscanf(file,"%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",&V[i].px,&V[i].py,&V[i]._x,&V[i]._y,&V[i].return_x,&V[i].return_y,&V[i].state,&V[i].cnt,&V[i].ghost_mode,&V[i].die_mode,&V[i].initial,&V[i].scatter_x,&V[i].scatter_y,&V[i].no,&V[i].a[12][9]);
        }
        for(int z=0;z<7;z++){
            for(int k=0;k<10;k++){
                for(int i=0;i<24;i++)
                {
                    for(int j=0;j<22;j++)
                    {
                        fscanf(file,"%d",&ara[z][k][i][j]);
                    }
                }
            }
        }
        fscanf(file,"%d%d%d%d",&die,&WIN,&GAMEOVER,&NAMETAKEN);
        fscanf(file,"%d%d",&level,&maze);
        fclose(file);
}


void fm(int x,int y)
{
    nn=x;  mm=810-y;
}


void DRAW()
{
        if(q==1)
        {
            lvt++;
            if(lvt==200)
            {
                lvt=0;  q=0;
            }
        }
        int x=0;
        //iSetColor(155,155,155);
        for(int i=90;i<mazeheight+(screenHeight-mazeheight)/2;i+=boxLength)
        {
            int y=0;
            for(int j=90;j<mazewidth+(screenHeight-mazeheight)/2;j+=boxLength)
            {
                if(ara[maze][level][x][y]==1)
                {
                    //if(x==12&&y==9);
                    //else {
                    if(q==0)
                            {iSetColor(0,20,150);
                            iFilledRectangle(j,i,boxLength,boxLength);}
                        else
                        {
                            if(lvt%2){
                                iSetColor(255,255,255);
                                iFilledRectangle(j,i,boxLength,boxLength);
                            }
                            else
                            {
                                iSetColor(0,20,150);
                                iFilledRectangle(j,i,boxLength,boxLength);
                            }
                        }
                    //}
                }
                    //else
                    //{
                        if(ara[maze][level][x][y]==0)
                        {
                            iSetColor(255,0,0);
                            iFilledCircle(j+boxLength/2,i+boxLength/2,3);
                        }
                        if(ara[maze][level][x][y]==3)
                        {
                            iSetColor(255,0,0);
                            iFilledCircle(j+boxLength/2,i+boxLength/2,6);
                        }
                        if(ara[maze][level][x][y]==5)
                        {
                            iShowBMP2(j,i,food[1],0);
                        }
                        if(ara[maze][level][x][y]==6)
                        {
                            iShowBMP2(j,i,food[0],0);
                        }
                        if(ara[maze][level][x][y]==7)
                        {
                            iShowBMP2(j,i,food[2],0);
                        }
                    //}
                y++;
            }
            x++;
        }
        x=0;
        for(int i=90;i<mazeheight+(screenHeight-mazeheight)/2;i+=boxLength)
        {
            int y=0;
            for(int j=90;j<mazewidth+(screenHeight-mazeheight)/2;j+=boxLength)
            {
                if(ara[maze][level][x][y]==1)
                {
                    //if(x==12&&y==9);
                    //else {
                            //iSetColor(0,20,110);
                            //iFilledRectangle(j,i,boxLength,boxLength);
                            if(maze==0)
                            {
                                iSetColor(0,0,0);
                            }
                            if(maze==1)
                            {
                                iSetColor(154,80,50);
                            }
                            if(maze==2)
                            {
                                iSetColor(160,150,90);
                            }
                            if(maze==3)
                            {
                                iSetColor(165,50,190);
                            }
                            if(maze==4)
                            {
                                iSetColor(100,30,200);
                            }
                            if(maze==5)
                            {
                                iSetColor(140,200,50);
                            }
                            if(maze==6)
                            {
                                iSetColor(120,120,120);
                            }
                            iFilledRectangle(j+5,i+5,20,20);
                            //if(x+1==12&&y==9) ;
                            //if(x==12&&y+1==9) ;
                            //else {
                                if(ara[maze][level][x][y+1]==1)
                                {
                                    iFilledRectangle(j+25,i+5,30,20);
                                }
                                if(ara[maze][level][x+1][y]==1)
                                {
                                    iFilledRectangle(j+5,i+25,20,30);
                                }
                            //}
                    //}
                }
                y++;
            }
            x++;
        }
        iSetColor(50,200,250);
        iFilledRectangle(360,445,30,5);
        if(pacc.pox+boxLength>570+(screenHeight-mazeheight)/2&&pacc.right&&q==0)
        {
            pacc.pox=(screenHeight-mazeheight)/2;
        }
        else if(pacc.pox<(screenHeight-mazeheight)/2&&pacc.left&&q==0)
        {
            pacc.pox=570-boxLength+(screenHeight-mazeheight)/2;
        }
        if(pacc.poy+boxLength>630+(screenHeight-mazeheight)/2&&pacc.up&&q==0)
        {
            pacc.poy=(screenHeight-mazeheight)/2;
        }
        else if(pacc.poy<(screenHeight-mazeheight)/2&&pacc.down&&q==0)
        {
            pacc.poy=630-boxLength+(screenHeight-mazeheight)/2;
        }
        for(int i=0;i<4;i++)
        {
                if(V[i].px>570+(screenHeight-mazeheight)/2&&q==0)
                {
                    V[i].px=(screenHeight-mazeheight)/2;
                }
                else if(V[i].px<(screenHeight-mazeheight)/2&&q==0)
                {
                    V[i].px=570-boxLength+(screenHeight-mazeheight)/2;
                }
                if(V[i].py+boxLength>630+(screenHeight-mazeheight)/2&&q==0)
                {
                    V[i].py=(screenHeight-mazeheight)/2;
                }
                else if(V[i].py<(screenHeight-mazeheight)/2&&q==0)
                {
                    V[i].py=630-boxLength+(screenHeight-mazeheight)/2;
                }
        }
        if(fire_mode&&q==0)
        {
            if(fire_l) iShowBMP2(fire_x,fire_y,FIRE[2],0);
            if(fire_r) iShowBMP2(fire_x,fire_y,FIRE[0],0);
            if(fire_u) iShowBMP2(fire_x,fire_y,FIRE[1],0);
            if(fire_d) iShowBMP2(fire_x,fire_y,FIRE[3],0);

        }
        if(V[0].ghost_mode) iShowBMP2(V[0].px,V[0].py,red_[V[0].no],0);
        if(V[1].ghost_mode) iShowBMP2(V[1].px,V[1].py,pink_[V[1].no],0);
        if(V[2].ghost_mode) iShowBMP2(V[2].px,V[2].py,blue_[V[2].no],0);
        if(V[3].ghost_mode) iShowBMP2(V[3].px,V[3].py,orange_[V[3].no],0);
        if(V[0].die_mode==1) iShowBMP2(V[0].px,V[0].py,death[V[0].no%4],0);
        if(V[1].die_mode==1)iShowBMP2(V[1].px,V[1].py,death[V[1].no%4],0);
        if(V[2].die_mode==1)iShowBMP2(V[2].px,V[2].py,death[V[2].no%4],0);
        if(V[3].die_mode==1)iShowBMP2(V[3].px,V[3].py,death[V[3].no%4],0);
        t[0]='T';
        t[1]='i';
        t[2]='m';
        t[3]='e';
        t[4]=' ';
        t[5]=(tim/60)/10+'0';
        t[6]=(tim/60)%10+'0';
        t[7]=':';
        t[8]=(tim%60)/10+'0';
        t[9]=(tim%60)%10+'0';
        t[10]='\0';
        if(frightened_mode&&q==0)
            {
                for(int idx=0;idx<4;idx++)
                {
                    if((V[idx].die_mode==0||V[idx].die_mode==2)&&V[idx].ghost_mode==0) {
                        if(call2<350||(call2>400&&call2<450)) iShowBMP2(V[idx].px,V[idx].py,DIE[(V[idx].state/4)%2],0);
                        else if((call2>=350&&call2<=400)||(call2>=450&&call2<=500)) iShowBMP2(V[idx].px,V[idx].py,DIE[3],0);
                    }
                }
        }
        iSetColor(0,255,255);
        iText(90,760,t,GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,0,0);
        iText(280,760,"Score",GLUT_BITMAP_TIMES_ROMAN_24);
        itoa(score,s,10);
        char xd[12];
        itoa(level+1,xd,10);
        iText(380,760,s,GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(120,120,100);
        iText(520,760,"LEVEL : ",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(620,760,xd,GLUT_BITMAP_TIMES_ROMAN_24);
        int q=0;
        for(int idx=0;idx<die;idx++)
        {
            iShowBMP2(710+120+q,620,pacman_pic[2][2],0);
            q+=40;
        }
        iSetColor(120,120,125);
        //iFilledRectangle(690+120,280,120,30);
        iFilledRectangle(690+120,230,120,30);
        iSetColor(0,0,0);
        iText(710+120,235,"MENU",GLUT_BITMAP_TIMES_ROMAN_24);
        if(sound)
        {
            iShowBMP2(850,280,"sound on.bmp",0);
        }
        else
        {
            iShowBMP2(850,280,"sound off.bmp",0);
        }
}


void show_score()
{
    int x=460,y=640;
    iShowBMP(0,0,"hscore.bmp");
    iSetColor(255,0,0);
    iText(x,y,"NAME",GLUT_BITMAP_HELVETICA_18);
    iText(x+300,y,"SCORE",GLUT_BITMAP_HELVETICA_18);
    iSetColor(255,255,255);
    y-=50;
    for(int i=0;i<10;i++)
    {
        iText(x,y,h[i].name,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(x+300,y,h[i].score,GLUT_BITMAP_TIMES_ROMAN_24);
        y=y-50;
    }
    iText(120,155,"PRESS C TO CONTINUE",GLUT_BITMAP_HELVETICA_18);
}


void MENU1()
{
                iShowBMP(0,0,cover[0]);
                if(ok==0)
                {
                    iSetColor(180,200,220);
                }
                if(ok)
                {
                    //iSetColor(100,100,100);
                    ok=0;
                }
                for(int y=600;y>=420;y-=60)
                {
                    iFilledRectangle(90,y,150,40);
                }
                int y=600;
                if(nn>=90&&nn<=240&&mm>=y&&mm<=y+40)
                {
                    iSetColor(100,100,100);
                    iFilledRectangle(90,y,150,40);
                }
                y-=60;
                if(nn>=90&&nn<=240&&mm>=y&&mm<=y+40)
                {
                    iSetColor(100,100,100);
                    iFilledRectangle(90,y,150,40);
                }
                y-=60;
                if(nn>=90&&nn<=240&&mm>=y&&mm<=y+40)
                {
                    iSetColor(100,100,100);
                    iFilledRectangle(90,y,150,40);
                }
                y-=60;
                if(nn>=90&&nn<=240&&mm>=y&&mm<=y+40)
                {
                    iSetColor(100,100,100);
                    iFilledRectangle(90,y,150,40);
                }
                iSetColor(0,0,0);
                iText(100,610,"NEW GAME",GLUT_BITMAP_HELVETICA_18);
                iText(100,550,"CONTINUE",GLUT_BITMAP_HELVETICA_18);
                iText(100,490,"HIGHSCORE",GLUT_BITMAP_HELVETICA_18);
                iText(100,430,"EXIT",GLUT_BITMAP_HELVETICA_18);
                iSetColor(255,255,255);
                iText(20,80,"Press < to see rules",GLUT_BITMAP_HELVETICA_18);
}



void iDraw()
{
    iClear();
    glutPassiveMotionFunc(fm);
    if(game_strt)
    {
        if(aaa)
        {
            option_show();
        }
        else if((start||resume)&&die&&qx==0&&WIN==0)
        {
            if(sound){
                if(music_1){
                    PlaySound("pacman_beginning.wav",NULL,SND_ASYNC);
                    music_1=0;
                }
            }
            if(nn>=850&&nn<=900&&mm>=280&&mm<=330)
            {
                iSetColor(120,120,120);
                iFilledRectangle(830,280,90,75);
            }
            DRAW();
            if(nn>=800&&nn<=930&&mm>=230&&mm<=260)
            {
                iSetColor(255,255,255);
                iFilledRectangle(800,230,130,30);
                iSetColor(0,0,0);
                iText(710+120,235,"MENU",GLUT_BITMAP_TIMES_ROMAN_24);
            }
            if(PAUSE==0) iShowBMP2(pacc.pox,pacc.poy,pacman_pic[pac_no][pac],0);
            if(hide_mode){
                iSetColor(120,120,120);
                iFilledCircle(pacc.pox+15,pacc.poy+15,5);
            }
            if(PAUSE)
            {
                iShowBMP2(pacc.pox,pacc.poy,PD[PAUSE/10],0);
            }

        }
        else if(die==0||WIN)
        {
            if(PAUSE<400)
            {
                PAUSE++;
                PAUSE=min(PAUSE,400);
                if(die==0){
                    DRAW();
                    if(PAUSE==0) iShowBMP2(pacc.pox,pacc.poy,pacman_pic[pac_no][pac],0);
                    if(PAUSE)
                    {
                        iShowBMP2(pacc.pox,pacc.poy,PD[PAUSE/40],0);
                    }
                }
                else if(WIN)
                {
                    iShowBMP(0,0,"WIN.bmp");
                }

            }
            else {
                if(GAMEOVER<500)
                {
                    GAMEOVER++;
                    GAMEOVER=min(GAMEOVER,500);
                    iShowBMP(0,0,"GAMEOVER.bmp");
                    iSetColor(255,255,255);
                    iText(350,550,"YOUR SCORE  ",GLUT_BITMAP_TIMES_ROMAN_24);
                    iText(550,550,s,GLUT_BITMAP_TIMES_ROMAN_24);
                    iText(350,500,t,GLUT_BITMAP_TIMES_ROMAN_24);
                }
                else if(!NAMETAKEN)
                {
                    if(maze==0){
                        iSetColor(0,0,0);
                        iFilledRectangle(0,0,screenWidth,screenHeight);
                        iSetColor(255,255,255);
                        iText(35,500,"TYPE YOUR NAME : ",GLUT_BITMAP_TIMES_ROMAN_24);
                        iRectangle(270,480,500,50);
                        iText(290,500,str,GLUT_BITMAP_TIMES_ROMAN_24);
                    }
                    else
                    {
                        NAMETAKEN=1;
                        yes=0;
                    }

                }
                else if(NAMETAKEN)
                {
                    yes=0;
                    //initialize();
                    save_game();
                    if(!HIGH&&!rules)
                    {
                        //iShowBMP(0,0,cover[0]);
                        MENU1();
                    }
                    if(qx)
                    {
                        iShowBMP(195,480,"SOUND.bmp");
                    }
                    if(music_1==0)
                    {
                        PlaySound("Immigrant.wav",NULL,SND_LOOP|SND_ASYNC);
                        music_1=1;
                    }
                    if(HIGH)
                    {
                        show_score();
                        rules=0;
                    }
                    if(rules)
                    {
                        HIGH=0;
                        iShowBMP(0,0,"RULES.bmp");
                        iSetColor(0,0,0);
                        iText(20,100,"Press < to continue",GLUT_BITMAP_HELVETICA_18);
                    }
                }
            }
        }
        else
        {
            if(!HIGH&&!rules)
            {
                MENU1();
            }
            if(music_1==0)
            {
                PlaySound("Immigrant.wav",NULL,SND_LOOP|SND_ASYNC);
                music_1=1;
            }
            if(HIGH)
            {
                show_score();
                rules=0;
            }
            if(rules)
            {
                iShowBMP(0,0,"RULES.bmp");
                 iSetColor(0,0,0);
                iText(20,80,"Press < to continue",GLUT_BITMAP_HELVETICA_18);
            }
        }
    }
    else
    {
        if(MUSIC_strt==0)
        {
            PlaySound("pacman_beginning.wav",NULL,SND_ASYNC);
            MUSIC_strt=1;
        }
        strt_();
        iShowBMP(0,0,"strt.bmp");
        iSetColor(0,0,0);
        iShowBMP2(posx,posy,pacman_pic[2][pac],0);
        if(posx+30>=1200)
        {
            game_strt=1;
            pac=0;
        }
    }

}



void option_show()
{
    iShowBMP(50,500,"CLASSIC.bmp");
    iShowBMP(300,500,"NUMBERS.bmp");
    iShowBMP(550,500,"CHOCOLATE.bmp");
    iShowBMP(800,500,"BHOOT.bmp");
    iShowBMP(50,250,"BALOONS.bmp");
    iShowBMP(300,250,"RAINY.bmp");
    iShowBMP(550,250,"VOLCANO.bmp");
    if(nn>=50&&nn<=250&&mm>=500&&mm<=700)
    {
        iShowBMP(0,450,"CLASSIC1.bmp");
    }
        if(nn>=300&&nn<=500&&mm>=500&&mm<=700)
    {
        iShowBMP(250,450,"NUMBERS1.bmp");
    }
        if(nn>=550&&nn<=750&&mm>=500&&mm<=700)
    {
        iShowBMP(500,450,"CHOCOLATE1.bmp");
    }
        if(nn>=800&&nn<=1000&&mm>=500&&mm<=700)
    {
        iShowBMP(750,450,"BHOOT1.bmp");
    }
        if(nn>=50&&nn<=250&&mm>=250&&mm<=450)
    {
        iShowBMP(0,200,"BALOONS1.bmp");
    }
        if(nn>=300&&nn<=500&&mm>=250&&mm<=450)
    {
        iShowBMP(250,200,"RAINY1.bmp");
    }
        if(nn>=550&&nn<=750&&mm>=250&&mm<=450)
    {
        iShowBMP(500,200,"VOLCANO1.bmp");
    }
        if(nn>=50&&nn<=250&&mm>=500&&mm<=700)
    {
        iShowBMP(0,450,"CLASSIC1.bmp");
    }
        if(nn>=300&&nn<=500&&mm>=500&&mm<=700)
    {
        iShowBMP(250,450,"NUMBERS1.bmp");
    }
        if(nn>=550&&nn<=750&&mm>=500&&mm<=700)
    {
        iShowBMP(500,450,"CHOCOLATE1.bmp");
    }
        if(nn>=800&&nn<=1000&&mm>=500&&mm<=700)
    {
        iShowBMP(750,450,"BHOOT1.bmp");
    }
        if(nn>=50&&nn<=250&&mm>=250&&mm<=450)
    {
        iShowBMP(0,200,"BALOONS1.bmp");
    }
        if(nn>=300&&nn<=500&&mm>=250&&mm<=450)
    {
        iShowBMP(250,200,"RAINY1.bmp");
    }
        if(nn>=550&&nn<=750&&mm>=250&&mm<=450)
    {
        iShowBMP(500,200,"VOLCANO1.bmp");
    }

}



void iMouseMove(int buttonx, int buttony)
{

}
void iMouse(int button, int state, int mx, int my){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(mx>=90&&mx<=240&&my>=600&&my<=640&&qx==0&&yes==0)
        {
            yes=1;
            ok=1;
            initialize();
            aaa=1;
            //cout<<aaa<<endl;
            continue_game=0;
            pause_game=0;
            resume=0;
        }
        else if(mx>=90&&mx<=240&&my>=540&&my<=580&&qx==0&&yes==0)
        {
            yes=1;
            ok=1;
            continue_game=1;
            load_game();
            pause_game=0;
            cout<<"MAZEEEEEE"<<maze<<endl;
            if(maze==-1)
            {
                aaa=1;
                //cout<<"Mazeeeeee"<<maze<<endl;
            }
            else
            {
                start=1;
            }
            //resume=0;*/
        }
        else if(mx>=90&&mx<=240&&my>=480&&my<=520&&qx==0&&yes==0)
        {
            ok=1;
            getHighscore();
            HIGH=1;
            yes=1;
        }
        else if(mx>=90&&mx<=240&&my>=420&&my<=460&&yes==0)
        {
            ok=1;
            putHighscore();
            if((die==0||WIN)&&NAMETAKEN==1)
            {
                initialize();
            }
            save_game();
            cout<<"MAZEEEEE"<<maze<<endl;
            exit(0);
        }
        else if(mx>=50&&mx<=250&&my>=500&&my<=700&&aaa==1)
        {
            maze=0;
            start=1;
            aaa=0;
            cout<<mx<<" "<<my<<endl;
            yes=1;
        }
         else if(mx>=300&&mx<=500&&my>=500&&my<=700&&aaa==1)
        {
            maze=1;
            start=1;
            aaa=0;
            yes=1;
            cout<<mx<<" "<<my<<endl;
        }
        else if(mx>=550&&mx<=750&&my>=500&&my<=700&&aaa==1)
        {
            maze=2;start=1;aaa=0;
            cout<<mx<<" "<<my<<endl;
            yes=1;
        }
        else if(mx>=800&&mx<=1000&&my>=500&&my<=700&&aaa==1)
        {
            maze=3;start=1;aaa=0;
            cout<<mx<<" "<<my<<endl;
            yes=1;
        }
        else if(mx>=50&&mx<=250&&my>=250&&my<=450&&aaa==1)
        {
            maze=4;start=1;aaa=0;
            cout<<mx<<" "<<my<<endl;
            yes=1;
        }
        else if(mx>=300&&mx<=500&&my>=250&&my<=450&&aaa==1)
        {
            maze=5;start=1;aaa=0;
            cout<<mx<<" "<<my<<endl;
            yes=1;
        }
        else if(mx>=550&&mx<=750&&my>=250&&my<=450&&aaa==1)
        {
            maze=6;start=1;aaa=0;
            cout<<mx<<" "<<my<<endl;
            yes=1;
        }
        //cout<<ok<<" "<<yes<<" "<<endl;
        else if(mx>=800&&mx<=930&&my>=230&&my<=260)
        {
            ok=1;
            if((die==0||WIN)&&NAMETAKEN==1)
            {
                initialize();
            }
            save_game();
            yes=0;
            start=0;
        }
        else if(mx>=800&&mx<=930&&my>=280&&my<=330&&qx==0&&yes==1)
        {
           sound=(sound+1)%2;
        }
        cout<<"    "<<sound<<endl;

    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {

    }
    //cout<<mx<<" "<<my<<endl;
}



void iKeyboard(unsigned char key)
{
    if(!NAMETAKEN&&!HIGH&&GAMEOVER==500&&maze==0)
    {
            if(key=='\r')
            {
                yes=0;
                getHighscore();
                NAMETAKEN=1;
                strcpy(str2,str);
                strcat(s,"\n\0");
                strcat(str2,"\n\0");
                strcpy(h[10].name,str2);
                strcpy(h[10].score,s);
                for(int i=0;i<len;i++)
                    str[i]=0;
                len=0;
                Sort_Highscore();
                putHighscore();
            }
            else if(key=='\b'&&len>0)
            {
                str[len-1]=key;
                len--;
            }
            else
            {
                str[len]=key;
                len++;
            }
    }
    if(key=='C'&&HIGH)
    {
        HIGH=0;
        yes=0;
    }
    else if(key=='<'&&!HIGH)
    {
        rules=(rules+1)%2;
        yes=(yes+1)%2;
    }

}



void iSpecialKeyboard(unsigned char key)
{
    if(key == GLUT_KEY_END)
    {
        putHighscore();
        if(die==0&&NAMETAKEN==1)
        {
            initialize();
        }
        save_game();
        exit(0);
    }
    if(q==0){
        if(start||resume){
            if(!pressed){
                if(key==GLUT_KEY_DOWN)
                {
                    pacc.down=1;
                    keey[0]=4;
                    keey[1]=4;
                }
                if(key==GLUT_KEY_LEFT)
                {
                    pacc.left=1;
                    keey[0]=3;
                    keey[1]=3;
                }
                if(key==GLUT_KEY_RIGHT)
                {
                    pacc.right=1;
                    keey[0]=1;
                    keey[1]=1;
                }
                if(key==GLUT_KEY_UP)
                {
                    pacc.up=1;
                    keey[0]=2;
                    keey[1]=2;
                }
                pressed=1;
            }
            if(pressed)
            {
                if(key==GLUT_KEY_DOWN)
                {
                    pacc.down=1;
                    keey[1]=4;
                }
                if(key==GLUT_KEY_LEFT)
                {
                    pacc.left=1;
                    keey[1]=3;
                }
                if(key==GLUT_KEY_RIGHT)
                {
                    pacc.right=1;
                    keey[1]=1;
                }
                if(key==GLUT_KEY_UP)
                {
                    pacc.up=1;
                    keey[1]=2;
                }
                if(keey[0]==0) keey[0]=keey[1];
            }
        }
    }
	//place your codes for other keys here
}



void change()
{
    if(resume||start) tim++;
    //printf("%d\n",tim );
}



int main()
{
        iSetTimer(30,strt_);
        iSetTimer(50,pac_type);
        iSetTimer(15,pacman_move);
        iSetTimer(15,ghost_move);
        iSetTimer(1000,change);
        iInitialize(1200,810, "pacman");
        return 0;
}
/*# include "iGraphics.h"
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
int ara[21][19];
void iDraw()
{
    iClear();
    iSetColor(255,255,255);
    iFilledRectangle(0,0,570,630);
    int x=0,y=0;
    for(int i=0;i<=630;i+=30)
    {
        y=0;
        for(int j=0;j<=570;j+=30)
        {
            if(ara[x][y]==0)
            {
                iSetColor(0,0,0);
                iRectangle(j,i,30,30);
                y++;
            }
            else
            {
                if(ara[x][y]==1)
                iSetColor(0,0,0);
                else if(ara[x][y]==-1)
                {
                    iSetColor(0,0,255);
                }
                iFilledRectangle(j,i,30,30);
                y++;
            }
        }
        x++;
    }
}
void iMouseMove(int mx, int my)
{
    if(ara[my/30][mx/30]==0)
    {
        ara[my/30][mx/30]=1;
    }
}
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(ara[my/30][mx/30]==0)
        {
            ara[my/30][mx/30]=1;
        }
        else if(ara[my/30][mx/30]==1)
        {
            ara[my/30][mx/30]=0;
        }
        //cout<<ara[my/30][mx/30]<<endl;
    }
    if(button==GLUT_RIGHT_BUTTON&&state==GLUT_DOWN)
    {
        if(ara[my/30][mx/30]==0)
        {
            ara[my/30][mx/30]=-1;
        }
    }
}
void iKeyboard(unsigned char key)
{
    if(key=='a')
    {
        for(int i=0;i<21;i++)
        {
            cout<<"{";
            for(int j=0;j<19;j++)
            {
                if(j<18)
                {
                    cout<<ara[i][j]<<",";
                }
                else
                {
                    cout<<ara[i][j]<<"},"<<endl;
                }
            }
        }
    }
}
void iSpecialKeyboard(unsigned char key)
{
    //place your codes for other keys here
}
int main()
{
    iInitialize(570,630, "Path Finder");
    return 0;
}*/
