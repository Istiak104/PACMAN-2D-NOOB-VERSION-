#include<windows.h>
#include "iGraphics.h"
#include<math.h>
int MUSIC_strt,sound=0,rules,rules_time,qx=0,game_strt,posx,posy,GAMEOVER,NAMETAKEN,len,WIN,HIGH,dot=184,new_x=120;
char str[20],str2[20];
FILE *file,*F;
int screenWidth=1200,boxLength=30,screenHeight=810,pressed,keey[2],static_pacmouth,target_x,target_y,tim;
int mini1,mini2,mini3,mini4,g_l,g_r,g_u,g_d,mini,maxi,maxi1,maxi2,maxi3,maxi4,flee_r,flee_l,flee_d,flee_u;
int mazewidth=570,mazeheight=630,score;
int scatter_mode,frightened_mode;
int hide_mode,speed_mode,pause_mode_for_ghosts,call,call2,speed=2,call3,call4,call5,call6,PAUSE,fire_l,fire_r,fire_u,fire_d,gameover_calltime,fire_x,fire_y,fire_mode;
char DIE[4][10]={"gd1.bmp","gd2.bmp","gad1.bmp","gad2.bmp"};
char death[4][8]={"e1.bmp","e2.bmp","e3.bmp","e4.bmp"};
char pacman_pic[4][3][100]={{"p1l.bmp","p2l.bmp","p3l.bmp"},{"p1d.bmp","p2d.bmp","p3d.bmp"},{"p1r.bmp","p2r.bmp","p3r.bmp"},{"p1u.bmp","p2u.bmp","p3u.bmp"}};
char red_[8][10]={"r1-1.bmp","r2-1.bmp","r3-1.bmp","r4-1.bmp","r1-2.bmp","r2-2.bmp","r3-2.bmp","r4-2.bmp"};
char blue_[8][10]={"b1-1.bmp","b2-1.bmp","b3-1.bmp","b4-1.bmp","b1-2.bmp","b2-2.bmp","b3-2.bmp","b4-2.bmp"};
char orange_[8][10]={"o1-1.bmp","o2-1.bmp","o3-1.bmp","o4-1.bmp","o1-2.bmp","o2-2.bmp","o3-2.bmp","o4-2.bmp"};
char pink_[8][10]={"pi1-1.bmp","pi2-1.bmp","pi3-1.bmp","pi4-1.bmp","pi1-2.bmp","pi2-2.bmp","pi3-2.bmp","pi4-2.bmp"};
char FIRE[8][15]={"FIRE_R.bmp","FIRE_U.bmp","FIRE_L.bmp","FIRE_D.bmp"};
char cover[3][15]={"BACKground.bmp"};
char food[3][12]={"cherry.bmp","apple.bmp","candy.bmp"};
char PD[11][10]={"pd1.bmp","pd2.bmp","pd3.bmp","pd4.bmp","pd5.bmp","pd6.bmp","pd7.bmp","pd8.bmp","pd9.bmp","pd10.bmp","pd11.bmp"};
int pac,pac_no;
int die=3;
int start,resume,pause_game,continue_game;
int music_1,music_2,music_3,music_4,music_5,music_6;
char s[12],t[12];
typedef struct{
    int right=0;
    int left=0;
    int up=0;
    int down=0;
    int xx;
    int yy;
    int pox=120+(screenHeight-mazeheight)/2;
    int poy=30+(screenHeight-mazeheight)/2;
}pacman;
pacman pacc;
typedef struct{
    int px;
    int py;
    int _x;
    int _y;
    int return_x;
    int return_y;
    int state;
    char dir;
    int cnt;
    int ghost_mode;
    int die_mode;
    int no;
    int initial;
    int scatter_x;
    int scatter_y;
    int a[20][20];
}ghost;
ghost blinky,inky,pinky,clyde;
ghost V[]={blinky,pinky,inky,clyde};
void pacman_moveleft();
void pacman_move_down();
void pacman_move_up();
void pacman_move_right();
void pacman_move();
void ghost_move();
int ara[24][22]={
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1},
        {1,0,0,0,0,1,3,0,0,1,0,0,0,1,0,0,0,0,1},
        {1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1},
        {1,0,0,1,0,6,0,0,0,0,0,0,0,0,0,1,0,0,1},
        {1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,0,1},
        {1,0,0,0,0,0,0,0,0,1,0,0,0,0,3,0,0,0,1},
        {1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1},
        {-1,-1,-1,1,0,1,0,0,0,0,0,0,0,1,0,1,-1,-1,-1},
        {1,1,1,1,0,1,3,1,1,1,1,1,0,1,0,1,1,1,1},
        {-1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,-1},
        {1,1,1,1,0,1,0,1,1,0,1,1,0,1,0,1,1,1,1},
        {-1,-1,-1,1,0,1,0,0,0,0,0,0,0,1,0,1,-1,-1,-1},
        {1,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1},
        {1,0,0,0,0,1,0,0,0,1,7,0,0,1,0,0,0,0,1},
        {1,3,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,0,1},
        {1,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,0,1},
        {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };
typedef struct{
    char score[12];
    char name[20];
}highscore;
highscore h[12];
void chk_ara()
{
    int cnt=0;
    for(int i=0;i<21;i++)
    {
        for(int j=0;j<19;j++)
        {
            if(ara[i][j]!=1&&ara[i][j]!=-1&&ara[i][j]==2)
            {
                cnt++;
            }
        }
    }
    //printf("%d\n",cnt);
    if(cnt==dot)
    {
        WIN=1;
    }
}
void getHighscore()
{
    file=fopen("highscores.txt","r");
    for(int i=0;i<10;i++)
    {
        fgets(h[i].name,20,file);
    }
    for(int i=0;i<10;i++)
    {
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
    }
    for(int i=0; i<10; i++)
    {
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
void initialize()
{
    screenWidth=870,boxLength=30,screenHeight=810,pressed=0,keey[2]={0},static_pacmouth=0,target_x=0,target_y=0,tim=0;
    mini1=0,mini2=0,mini3=0,mini4=0,g_l=0,g_r=0,g_u=0,g_d=0,mini=0,maxi=0,maxi1=0,maxi2=0,maxi3=0,maxi4=0,flee_r=0,flee_l=0,flee_d=0,flee_u=0;
    mazewidth=570,mazeheight=630,score=0;
    scatter_mode=0,frightened_mode=0;
    hide_mode=0,speed_mode=0,pause_mode_for_ghosts=0,call=0,call2=0,speed=2,call3=0,call4=0,call5=0,call6=0,PAUSE=0,fire_l=0,fire_r=0,fire_u=0,fire_d=0,gameover_calltime=0,fire_x=0,fire_y=0,fire_mode=0;
    pacc.right=0;
    pacc.left=0;
    pacc.up=0;
    pacc.down=0;
    pacc.xx;
    pacc.yy;
    pacc.pox=120+(screenHeight-mazeheight)/2;
    pacc.poy=30+(screenHeight-mazeheight)/2;
    pac_no=0;
    pac=0;
    V[0].px=350;
    V[0].py=480;
    V[0]._x;
    V[0]._y;
    V[0].return_x=350;
    V[0].return_y=480;
    V[0].state=0;
    V[0].dir='k';
    V[0].ghost_mode=1;
    V[0].die_mode=2;
    V[1].px=330;
    V[1].py=420;
    V[1]._x;
    V[1]._y;
    V[1].return_x=330;
    V[1].return_y=420;
    V[1].state=0;
    V[1].dir='k';
    V[1].ghost_mode=1;
    V[1].die_mode=0;
    V[2].px=360;
    V[2].py=420;
    V[2]._x;
    V[2]._y;
    V[2].return_x=360;
    V[2].return_y=420;
    V[2].state=0;
    V[2].dir='k';
    V[2].ghost_mode=1;
    V[2].die_mode=2;
    V[3].px=390;
    V[3].py=420;
    V[3]._x;
    V[3]._y;
    V[3].return_x=390;
    V[3].return_y=420;
    V[3].state;
    V[3].dir='k';
    V[3].ghost_mode=1;
    V[3].die_mode=2;
    V[0].initial=0;
    V[1].initial=0;
    V[2].initial=0;
    V[3].initial=0;
    V[0].no;
    V[1].no;
    V[2].no;
    V[3].no;
    V[0].scatter_x=150;
    V[0].scatter_y=330;
    V[1].scatter_x=150;
    V[1].scatter_y=570;
    V[2].scatter_x=480;
    V[2].scatter_y=630;
    V[3].scatter_x=240;
    V[3].scatter_y=390;
    V[0].a[12][9]=0;
    V[1].a[12][9]=0;
    V[2].a[12][9]=0;
    V[3].a[12][9]=0;
    die=3;
    WIN=0;
    GAMEOVER=0;
    NAMETAKEN=0;
    HIGH=0;
    start=0,resume=0,pause_game=0,continue_game=0;
    int temp[24][22]={
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1},
        {1,0,0,0,0,1,3,0,0,1,0,0,0,1,0,0,0,0,1},
        {1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1},
        {1,0,0,1,0,6,0,0,0,0,0,0,0,0,0,1,0,0,1},
        {1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,0,1},
        {1,0,0,0,0,0,0,0,0,1,0,0,0,0,3,0,0,0,1},
        {1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1},
        {-1,-1,-1,1,0,1,0,0,0,0,0,0,0,1,0,1,-1,-1,-1},
        {1,1,1,1,0,1,3,1,1,1,1,1,0,1,0,1,1,1,1},
        {-1,0,0,0,0,0,0,1,-1,-1,-1,1,0,0,0,0,0,0,-1},
        {1,1,1,1,0,1,0,1,1,-1,1,1,0,1,0,1,1,1,1},
        {-1,-1,-1,1,0,1,0,0,0,0,0,0,0,1,0,1,-1,-1,-1},
        {1,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1},
        {1,0,0,0,0,1,0,0,0,1,7,0,0,1,0,0,0,0,1},
        {1,3,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,0,1},
        {1,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,0,1},
        {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };
    for(int i=0;i<24;i++)
    {
        for(int j=0;j<22;j++)
        {
            ara[i][j]=temp[i][j];
        }
    }
}
void music()
{
    if(music_2)
    {
        if(sound) PlaySound("pacman_eatfruit.wav",NULL,SND_ASYNC);
        music_2=0;
    }
    else if(music_3)
    {
        if(sound) PlaySound("pacman_eatfruit.wav",NULL,SND_ASYNC);
        music_3=0;
    }
    else if(music_4)
    {
        if(sound) PlaySound("pacman_death.wav",NULL,SND_ASYNC);
        music_4=0;
    }
    else if(music_5)
    {
        if(sound) PlaySound("pacman_eatghost.wav",NULL,SND_ASYNC);
        music_5=0;
    }
    else if(music_6)
    {
        if(sound) PlaySound("pacman_chomp.wav",NULL,SND_ASYNC);
        music_6=0;
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
    for(int i=0;i<24;i++)
    {
        for(int j=0;j<22;j++)
        {
            fprintf(file,"%d\n",ara[i][j]);
        }
    }
    fprintf(file,"%d\n%d\n%d\n%d\n",die,WIN,GAMEOVER,NAMETAKEN);
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
        for(int i=0;i<24;i++)
        {
            for(int j=0;j<22;j++)
            {
                fscanf(file,"%d",&ara[i][j]);
            }
        }
        fscanf(file,"%d%d",&die,&WIN);
        fprintf(file,"%d%d%d%d",&die,&WIN,&GAMEOVER,&NAMETAKEN);
        fclose(file);
}
void strt_()
{
    posx+=3;
    posy=360;
}
void pac_type()
{
    if((pacc.left||pacc.right||pacc.down||pacc.up))
    {
        pac++;
        if(static_pacmouth) pac=2;
        if(pac>2)
        {
            pac=0;
        }
    }
    else if(game_strt==0)
    {
        pac++;
        if(pac>2)
        {
            pac=0;
        }
    }
}
void pacman_move_right(){
    if(pacc.right)
    {
        pacc.xx=(pacc.pox-(screenHeight-mazeheight)/2)/boxLength;
        pacc.yy=(pacc.poy-(screenHeight-mazeheight)/2)/boxLength;
        if(ara[pacc.yy][pacc.xx+1]!=1&&pacc.poy%boxLength==0)
        {
            static_pacmouth=0;
            if(speed_mode) speed=3;
            if(speed_mode==0)
            {
                if(pacc.pox%2) pacc.pox++;
                speed=2;
            }
            pacc.pox+=speed;
            if(pacc.pox%boxLength==0&&pacc.poy%boxLength==0)
            {
                if(ara[pacc.yy][pacc.xx+1]==0)
                {
                    score+=10;
                }
                if(ara[pacc.yy][pacc.xx+1]==3)
                {
                    music_3=1;
                    score+=30;
                    music();
                    frightened_mode=1;
                    if(V[0].die_mode!=1) V[0].ghost_mode=0;
                    if(V[1].die_mode!=1) V[1].ghost_mode=0;
                    if(V[2].die_mode!=1) V[2].ghost_mode=0;
                    if(V[3].die_mode!=1) V[3].ghost_mode=0;
                    for(int idx=0;idx<4;idx++)
                    {
                        V[idx].initial=0;
                    }

                }
                if(ara[pacc.yy][pacc.xx+1]==5)
                {
                    score+=30;
                    speed_mode=1;
                    music_2=1;
                    music();
                    if(pacc.pox%3)
                    {
                        pacc.pox-=pacc.pox-pacc.pox%3;
                    }
                }
                if(ara[pacc.yy][pacc.xx+1]==6)
                {
                    score+=30;
                    pause_mode_for_ghosts=1;
                    music_2=1;
                    music();
                }
                if(ara[pacc.yy][pacc.xx+1]==7)
                {
                    score+=30;
                    hide_mode=1;
                    music_2=1;
                    music();
                }
                ara[pacc.yy][pacc.xx+1]=2;
            }

        }
        else
        {
            static_pacmouth=1;
            pacc.right=0;
            pac=2;

        }
    }
}
void pacman_move_up(){
    if(pacc.up)
    {
        pacc.xx=(pacc.pox-(screenHeight-mazeheight)/2)/boxLength;
        pacc.yy=(pacc.poy-(screenHeight-mazeheight)/2)/boxLength;
        if(ara[pacc.yy+1][pacc.xx]!=1&&pacc.pox%boxLength==0)
        {
            static_pacmouth=0;
            if(speed_mode) speed=3;
            if(speed_mode==0)
            {
                if(pacc.poy%2) pacc.poy++;
                speed=2;
            }
            pacc.poy+=speed;
            if(pacc.pox%boxLength==0&&pacc.poy%boxLength==0)
            {
                if(ara[pacc.yy+1][pacc.xx]==0)
                {
                    score+=10;
                }
                if(ara[pacc.yy+1][pacc.xx]==3)
                {
                    score+=30;
                    frightened_mode=1;
                    music_3=1;
                    music();
                    if(V[0].die_mode!=1) V[0].ghost_mode=0;
                    if(V[1].die_mode!=1) V[1].ghost_mode=0;
                    if(V[2].die_mode!=1) V[2].ghost_mode=0;
                    if(V[3].die_mode!=1) V[3].ghost_mode=0;
                    for(int idx=0;idx<4;idx++)
                    {
                        V[idx].initial=0;
                    }

                }
                if(ara[pacc.yy+1][pacc.xx]==5)
                {
                    score+=30;
                    speed_mode=1;
                    music_2=1;
                    music();
                    if(pacc.poy%3)
                    {
                        pacc.poy+=pacc.poy-pacc.poy%3;
                    }
                }
                if(ara[pacc.yy+1][pacc.xx]==6)
                {
                    score+=30;
                    pause_mode_for_ghosts=1;
                    music_2=1;
                    music();
                }
                if(ara[pacc.yy+1][pacc.xx]==7)
                {
                    score+=30;
                    hide_mode=1;
                    music_2=1;
                    music();
                }
                ara[pacc.yy+1][pacc.xx]=2;
            }

        }
        else
        {
            static_pacmouth=1;
            pacc.up=0;
            pac=2;

        }
    }
}
void pacman_move_down(){
    if(pacc.down){
        pacc.xx=(pacc.pox-(screenHeight-mazeheight)/2)/boxLength;
        pacc.yy=(pacc.poy-1-(screenHeight-mazeheight)/2)/boxLength;
        if(ara[pacc.yy][pacc.xx]!=1&&pacc.pox%boxLength==0)
        {
            static_pacmouth=0;
            if(speed_mode) speed=3;
            if(speed_mode==0)
            {
                if(pacc.poy%2) pacc.poy--;
                speed=2;
            }
            pacc.poy-=speed;
            if(pacc.pox%boxLength==0&&pacc.poy%boxLength==0)
            {
                if(ara[pacc.yy][pacc.xx]==0)
                {
                    score+=10;
                }
                if(ara[pacc.yy][pacc.xx]==3)
                {
                    score+=30;
                    music_3=1;
                    music();
                    frightened_mode=1;
                    if(V[0].die_mode!=1) V[0].ghost_mode=0;
                    if(V[1].die_mode!=1) V[1].ghost_mode=0;
                    if(V[2].die_mode!=1) V[2].ghost_mode=0;
                    if(V[3].die_mode!=1) V[3].ghost_mode=0;
                    for(int idx=0;idx<4;idx++)
                    {
                        V[idx].initial=0;
                    }

                }
                if(ara[pacc.yy][pacc.xx]==5)
                {
                    score+=30;
                    speed_mode=1;
                    music_2=1;
                    music();
                    if(pacc.poy%3)
                    {
                        pacc.poy+=pacc.poy-pacc.poy%3;
                    }
                }
                if(ara[pacc.yy][pacc.xx]==6)
                {
                    score+=30;
                    music_2=1;
                    music();
                    pause_mode_for_ghosts=1;
                }
                if(ara[pacc.yy][pacc.xx]==7)
                {
                    score+=30;
                    hide_mode=1;
                    music_2=1;
                    music();
                }
                ara[pacc.yy][pacc.xx]=2;
            }
        }
        else
        {
            static_pacmouth=1;
            pac=2;
            pacc.down=0;
        }
    }
}
void pacman_move_left(){
    if(pacc.left)
    {
        pacc.xx=(pacc.pox-1-(screenHeight-mazeheight)/2)/boxLength;
        pacc.yy=(pacc.poy-(screenHeight-mazeheight)/2)/boxLength;
        if(ara[pacc.yy][pacc.xx]!=1&&pacc.poy%boxLength==0)
        {

            static_pacmouth=0;
            if(speed_mode) speed=3;
            if(speed_mode==0)
            {
                if(pacc.pox%2) pacc.pox--;
                speed=2;
            }
            pacc.pox-=speed;
            if(pacc.pox%boxLength==0&&pacc.poy%boxLength==0)
            {
                if(ara[pacc.yy][pacc.xx]==0)
                {
                    score+=10;
                }
                if(ara[pacc.yy][pacc.xx]==3)
                {
                    music_3=1;
                    score+=30;
                    music();
                    frightened_mode=1;
                    if(V[0].die_mode!=1) V[0].ghost_mode=0;
                    if(V[1].die_mode!=1) V[1].ghost_mode=0;
                    if(V[2].die_mode!=1) V[2].ghost_mode=0;
                    if(V[3].die_mode!=1) V[3].ghost_mode=0;
                    for(int idx=0;idx<4;idx++)
                    {
                        V[idx].initial=0;
                    }

                }
                if(ara[pacc.yy][pacc.xx]==5)
                {
                    score+=30;
                    speed_mode=1;
                    music_2=1;
                    music();
                    if(pacc.pox%3)
                    {
                        pacc.pox-=pacc.pox-pacc.pox%3;
                    }
                }
                if(ara[pacc.yy][pacc.xx]==6)
                {
                    score+=30;
                    music_2=1;
                    music();
                    pause_mode_for_ghosts=1;
                }
                if(ara[pacc.yy][pacc.xx]==7)
                {
                    score+=30;
                    music_2=1;
                    music();
                    hide_mode=1;
                }
                ara[pacc.yy][pacc.xx]=2;
            }

        }
        else
        {
            static_pacmouth=1;
            pac=2;
            pacc.left=0;
        }
    }
}
void pacman_move()
{
    chk_ara();
    if(die&&WIN!=1){
        if(start||resume){
            if(PAUSE==0){
                if(pause_mode_for_ghosts) call4++;
                if(speed_mode) call3++;
                if(hide_mode) call5++;
                if(keey[0]==keey[1]&&keey[1]==1)
                {
                    pac_no=2;
                    pacman_move_right();
                    if(pacc.right==0) keey[0]=0;
                }
                if(keey[0]==keey[1]&&keey[1]==2)
                {
                    pac_no=3;
                    pacman_move_up();
                    if(pacc.up==0) keey[0]=0;
                }
                if(keey[0]==keey[1]&&keey[1]==3)
                {
                    pac_no=0;
                    pacman_move_left();
                    if(pacc.left==0) keey[0]=0;
                }
                if(keey[0]==keey[1]&&keey[1]==4)
                {
                    pacc.xx=(pacc.pox-(screenHeight-mazeheight)/2)/boxLength;
                    pacc.yy=(pacc.poy-1-(screenHeight-mazeheight)/2)/boxLength;
                    if(pacc.xx==9&&pacc.yy==12)
                    {
                        keey[1]=keey[0];
                        pac=2;
                    }
                    else
                    {
                        pac_no=1;
                        pacman_move_down();
                        if(pacc.down==0) keey[0]=0;
                    }
                }
                if(keey[0]==1&&keey[1]==2)
                {
                    pacc.xx=(pacc.pox-(screenHeight-mazeheight)/2)/boxLength;
                    pacc.yy=(pacc.poy-(screenHeight-mazeheight)/2)/boxLength;
                    if(ara[pacc.yy+1][pacc.xx]!=1&&pacc.pox%boxLength==0)
                    {
                        keey[0]=keey[1];
                    }
                    else
                    {
                        pac_no=2;
                        pacman_move_right();
                        if(pacc.right==0)
                        {
                            keey[0]=0;
                        }
                    }
                }
                if(keey[0]==2&&keey[1]==1)
                {
                    pacc.xx=(pacc.pox-(screenHeight-mazeheight)/2)/boxLength;
                    pacc.yy=(pacc.poy-(screenHeight-mazeheight)/2)/boxLength;
                    if(ara[pacc.yy][pacc.xx+1]!=1&&pacc.poy%boxLength==0)
                    {
                        keey[0]=keey[1];
                    }
                    else
                    {
                        pac_no=3;
                        pacman_move_up();
                        if(pacc.up==0)
                        {
                            keey[0]=0;
                        }
                    }
                }
                if(keey[0]==1&&keey[1]==3)
                {
                    pac_no=0;
                    pacman_move_left();
                    keey[0]=keey[1];
                }
                if(keey[0]==3&&keey[1]==1)
                {
                    pac_no=2;
                    pacman_move_right();
                    keey[0]=keey[1];
                }
                if(keey[0]==1&&keey[1]==4)
                {
                    pacc.xx=(pacc.pox-(screenHeight-mazeheight)/2)/boxLength;
                    pacc.yy=(pacc.poy-1-(screenHeight-mazeheight)/2)/boxLength;
                    if(ara[pacc.yy][pacc.xx]!=1&&pacc.pox%boxLength==0)
                    {
                        keey[0]=keey[1];
                    }
                    else
                    {
                        pac_no=2;
                        pacman_move_right();
                        if(pacc.right==0)
                        {
                            keey[0]=0;
                        }
                    }
                }
                if(keey[0]==4&&keey[1]==1)
                {
                    pacc.xx=(pacc.pox-(screenHeight-mazeheight)/2)/boxLength;
                    pacc.yy=(pacc.poy-(screenHeight-mazeheight)/2)/boxLength;
                    if(ara[pacc.yy][pacc.xx+1]!=1&&pacc.poy%boxLength==0)
                    {
                        keey[0]=keey[1];
                    }
                    else
                    {
                        pacc.xx=(pacc.pox-(screenHeight-mazeheight)/2)/boxLength;
                        pacc.yy=(pacc.poy-1-(screenHeight-mazeheight)/2)/boxLength;
                        if(pacc.xx==9&&pacc.yy==12)
                        {
                            keey[1]=keey[0];
                            pac=2;
                        }
                        else{
                            pac_no=1;
                            pacman_move_down();
                            if(pacc.down==0)
                            keey[0]=0;
                        }
                    }
                }
                if(keey[0]==2&&keey[1]==3)
                {
                    pacc.xx=(pacc.pox-1-(screenHeight-mazeheight)/2)/boxLength;
                    pacc.yy=(pacc.poy-(screenHeight-mazeheight)/2)/boxLength;
                    if(ara[pacc.yy][pacc.xx]!=1&&pacc.poy%boxLength==0)
                    {
                        keey[0]=keey[1];
                    }
                    else
                    {
                        pac_no=3;
                        pacman_move_up();
                        if(pacc.up==0)
                        {
                            keey[0]=0;
                        }
                    }
                }
                if(keey[0]==3&&keey[1]==2)
                {
                    pacc.xx=(pacc.pox-(screenHeight-mazeheight)/2)/boxLength;
                    pacc.yy=(pacc.poy-(screenHeight-mazeheight)/2)/boxLength;
                    if(ara[pacc.yy+1][pacc.xx]!=1&&pacc.pox%boxLength==0)

                    {
                        keey[0]=keey[1];
                    }
                    else
                    {
                        pac_no=0;
                        pacman_move_left();
                        if(pacc.left==0)
                        {
                            keey[0]=0;
                        }
                    }
                }
                if(keey[0]==2&&keey[1]==4)
                {
                    pac_no=1;
                    pacman_move_down();
                    keey[0]=keey[1];
                }
                if(keey[0]==4&&keey[1]==2)
                {
                    pac_no=3;
                    pacman_move_up();
                    keey[0]=keey[1];
                }
                if(keey[0]==4&&keey[1]==3)
                {
                    pacc.xx=(pacc.pox-1-(screenHeight-mazeheight)/2)/boxLength;
                    pacc.yy=(pacc.poy-(screenHeight-mazeheight)/2)/boxLength;
                    if(ara[pacc.yy][pacc.xx]!=1&&pacc.poy%boxLength==0)
                    {
                        keey[0]=keey[1];
                    }
                    else
                    {
                        pacc.xx=(pacc.pox-(screenHeight-mazeheight)/2)/boxLength;
                        pacc.yy=(pacc.poy-1-(screenHeight-mazeheight)/2)/boxLength;
                        if(pacc.xx==9&&pacc.yy==12)
                        {
                            keey[1]=keey[0];
                            pac=2;
                        }
                        else{
                            pac_no=1;
                            pacman_move_down();
                            if(pacc.down==0)
                            {
                                keey[0]=0;
                            }
                        }
                    }
                }
                if(keey[0]==3&&keey[1]==4)
                {
                    pacc.xx=(pacc.pox-(screenHeight-mazeheight)/2)/boxLength;
                    pacc.yy=(pacc.poy-1-(screenHeight-mazeheight)/2)/boxLength;
                    if(ara[pacc.yy][pacc.xx]!=1&&pacc.pox%boxLength==0)
                    {
                        keey[0]=keey[1];
                    }
                    else
                    {
                        pac_no=0;
                        pacman_move_left();
                        if(pacc.left==0)
                        {
                            keey[0]=0;
                        }
                    }
                }
                if(call3>500) speed_mode=0;
                if(call4>500) pause_mode_for_ghosts=0;
                if(call5>500) hide_mode=0;

            }
        }
    }


}
void ghost_move()
{
    if(die&&WIN!=1){
        if(start||resume){
            if(ara[(fire_y-(screenHeight-mazeheight)/2)/boxLength][((fire_x-(screenHeight-mazeheight)/2)/boxLength)+1]==1&&fire_r)
            {
                fire_mode=0;
                fire_l=0,fire_r=0,fire_u=0,fire_d=0;
            }
            if(ara[(fire_y-(screenHeight-mazeheight)/2)/boxLength][(fire_x-1-(screenHeight-mazeheight)/2)/boxLength]==1&&fire_l)
            {
                fire_mode=0;
                fire_l=0,fire_r=0,fire_u=0,fire_d=0;
            }
            if(ara[((fire_y-(screenHeight-mazeheight)/2)/boxLength)+1][(fire_x-(screenHeight-mazeheight)/2)/boxLength]==1&&fire_u)
            {
                fire_mode=0;
                fire_l=0,fire_r=0,fire_u=0,fire_d=0;
            }
            if(ara[(fire_y-1-(screenHeight-mazeheight)/2)/boxLength][(fire_x-(screenHeight-mazeheight)/2)/boxLength]==1&&fire_d)
            {
                fire_mode=0;
                fire_l=0,fire_r=0,fire_u=0,fire_d=0;
            }
            if(pause_mode_for_ghosts==0&&PAUSE==0){
                for(int i=0;i<4;i++)
                {
                    if(V[i].ghost_mode==1||V[i].die_mode==1)
                    {
                        if(i==0&&V[i].ghost_mode)
                        {
                            target_x=pacc.pox;
                            target_y=pacc.poy;
                        }
                        if(i==1&&V[i].ghost_mode)
                        {
                            if(pacc.right)
                            {
                                target_x=pacc.pox+120;
                                target_y=pacc.poy;
                            }
                            else if(pacc.left)
                            {
                                target_x=pacc.pox-120;
                                target_y=pacc.poy;
                            }
                            else if(pacc.up)
                            {
                                target_x=pacc.pox;
                                target_y=pacc.poy+120;
                            }
                            else if(pacc.down)
                            {
                                target_x=pacc.pox;
                                target_y=pacc.poy-120;
                            }
                            else
                            {
                                target_x=pacc.pox+60;
                                target_y=pacc.poy+60;
                            }
                        }
                        if(i==2&&V[i].ghost_mode)
                        {
                            target_x=(2*pacc.pox-V[i].px);
                            target_y=(2*pacc.poy-V[i].py);
                            if(target_x<(screenHeight-mazeheight)/2)
                            {
                                target_x=(screenHeight-mazeheight)/2;
                            }
                            if(target_x>570+(screenHeight-mazeheight)/2)
                            {
                                target_x=570+(screenHeight-mazeheight)/2;
                            }
                            if(target_y<(screenHeight-mazeheight)/2)
                            {
                                target_y=(screenHeight-mazeheight)/2;
                            }
                            if(target_y>630+(screenHeight-mazeheight)/2)
                            {
                                target_y=630+(screenHeight-mazeheight)/2;
                            }
                        }
                        if(i==3&&V[i].ghost_mode)
                        {
                            if(pacc.right)
                            {
                                target_x=pacc.pox-120;
                                target_y=pacc.poy;
                            }
                            else if(pacc.left)
                            {
                                target_x=pacc.pox+120;
                                target_y=pacc.poy;
                            }
                            else if(pacc.up)
                            {
                                target_x=pacc.pox;
                                target_y=pacc.poy-120;
                            }
                            else if(pacc.down)
                            {
                                target_x=pacc.pox;
                                target_y=pacc.poy+120;
                            }
                            else
                            {
                                target_x=pacc.pox+60;
                                target_y=pacc.poy+60;
                            }
                        }
                        if((call>=0&&call<=500||hide_mode)&&V[i].ghost_mode)
                        {
                            target_x=V[i].scatter_x;
                            target_y=V[i].scatter_y;
                        }
                        if(V[i].die_mode==1&&V[i].px==360&&V[i].py==450)
                        {
                            V[i].ghost_mode=1;
                            V[i].die_mode=0;
                            V[i].initial=0;
                        }
                        mini=1e9;
                        mini1=1e9,mini2=1e9,mini3=1e9,mini4=1e9;
                        g_d=0;g_l=0,g_r=0,g_u=0;
                        //for right move
                        V[i]._x=(V[i].px-(screenHeight-mazeheight)/2)/boxLength;
                        V[i]._y=(V[i].py-(screenHeight-mazeheight)/2)/boxLength;
                        if(ara[V[i]._y][V[i]._x+1]!=1&&V[i].py%boxLength==0)
                        {
                            mini1=((V[i]._x+1)*boxLength-target_x)*((V[i]._x+1)*boxLength-target_x)+((V[i]._y)*boxLength-target_y)*((V[i]._y)*boxLength-target_y);
                        }
                        //for left move
                        V[i]._x=(V[i].px-1-(screenHeight-mazeheight)/2)/boxLength;
                        V[i]._y=(V[i].py-(screenHeight-mazeheight)/2)/boxLength;
                        if(ara[V[i]._y][V[i]._x]!=1&&V[i].py%boxLength==0)
                        {
                            mini2=((V[i]._x)*boxLength-target_x)*((V[i]._x)*boxLength-target_x)+((V[i]._y)*boxLength-target_y)*((V[i]._y)*boxLength-target_y);
                        }
                        //for up move
                        V[i]._x=(V[i].px-(screenHeight-mazeheight)/2)/boxLength;
                        V[i]._y=(V[i].py-(screenHeight-mazeheight)/2)/boxLength;
                        if(ara[V[i]._y+1][V[i]._x]!=1&&V[i].px%boxLength==0)
                        {
                            mini3=((V[i]._x)*boxLength-target_x)*((V[i]._x)*boxLength-target_x)+((V[i]._y+1)*boxLength-target_y)*((V[i]._y+1)*boxLength-target_y);
                        }
                        //for down move
                        V[i]._x=(V[i].px-(screenHeight-mazeheight)/2)/boxLength;
                        V[i]._y=(V[i].py-1-(screenHeight-mazeheight)/2)/boxLength;
                        if(ara[V[i]._y][V[i]._x]!=1&&V[i].px%boxLength==0)
                        {
                            mini4=((V[i]._x)*boxLength-target_x)*((V[i]._x)*boxLength-target_x)+(V[i]._y*boxLength-target_y)*((V[i]._y)*boxLength-target_y);
                        }
                        if(ara[V[i]._y][V[i]._x]!=1&&V[i]._x==9&&V[i]._y==12&&V[i].px%boxLength==0)
                        {
                            mini4=1e9;
                        }
                        if(mini1<mini&&V[i].die_mode!=1)
                        {
                            if(V[i].initial==0)
                            {
                                g_r=1;
                                V[i].dir='r';
                                mini=mini1;
                                V[i].initial=1;
                            }
                            else
                            {
                                if(V[i].dir!='l')
                                {
                                    mini=mini1;
                                    g_r=1;
                                    g_d=0,g_l=0,g_u=0;
                                }
                            }
                        }
                        if(mini>mini3&&V[i].die_mode!=1)
                        {
                            if(V[i].initial==0)
                            {
                                g_u=1;
                                V[i].dir='u';
                                mini=mini3;
                                V[i].initial=1;
                            }
                            else
                            {
                                if(V[i].dir!='d')
                                {
                                    mini=mini3;
                                    g_u=1;
                                    g_d=0,g_l=0,g_r=0;
                                }
                            }
                        }
                        if(mini>mini2&&V[i].die_mode!=1)
                        {
                            if(V[i].initial==0)
                            {
                                g_l=1;
                                V[i].dir='l';
                                mini=mini2;
                                V[i].initial=1;
                            }
                            else
                            {
                                if(V[i].dir!='r')
                                {
                                    mini=mini2;
                                    g_l=1;
                                    g_d=0,g_r=0,g_u=0;
                                }
                            }
                        }
                        if(mini>mini4&&V[i].die_mode!=1)
                        {
                            if(V[i].initial==0)
                            {
                                g_d=1;
                                V[i].dir='d';
                                mini=mini4;
                                V[i].initial=1;
                            }
                            else
                            {
                                if(V[i].dir!='u')
                                {
                                    mini=mini4;
                                    g_d=1;
                                    g_r=0,g_l=0,g_u=0;
                                }
                            }
                        }
                        if(V[i].px==360&&V[i].py==450&&V[i].ghost_mode)
                        {
                            g_u=1;
                            g_l=0;
                            g_r=0;
                            g_d=0;
                        }
                        if(g_r&&V[i].die_mode!=1)
                        {
                            V[i]._x=(V[i].px-(screenHeight-mazeheight)/2)/boxLength;
                            V[i]._y=(V[i].py-(screenHeight-mazeheight)/2)/boxLength;
                            if(ara[V[i]._y][V[i]._x+1]!=1&&V[i].py%boxLength==0){
                                if(/*pacc.pox>V[i].px&&i==0&&/*pacc.poy==V[i].py&&*/fire_mode==0&&i==0)
                                {
                                    fire_mode=1;
                                    fire_r=1;
                                    fire_l=0;
                                    fire_u=0;
                                    fire_d=0;
                                    fire_x=V[i].px;
                                    fire_y=V[i].py;
                                }
                                V[i].dir='r';
                                if(V[i].px%2) V[i].px++;
                                else if(V[i].px%2==0) V[i].px+=2;
                                V[i].state++;
                                if((V[i].state/10)%2)
                                    V[i].no=0;
                                else V[i].no=4;
                            }
                        }
                        else if(g_l&&V[i].die_mode!=1)
                        {
                            V[i]._x=(V[i].px-1-(screenHeight-mazeheight)/2)/boxLength;
                            V[i]._y=(V[i].py-(screenHeight-mazeheight)/2)/boxLength;
                            if(ara[V[i]._y][V[i]._x]!=1&&V[i].py%boxLength==0){
                                if(/*pacc.pox<V[i].px&&i==0&&/*V[i].py==pacc.poy&&*/fire_mode==0&&i==0)
                                {
                                    fire_mode=1;
                                    fire_r=0;
                                    fire_l=1;
                                    fire_u=0;
                                    fire_d=0;
                                    fire_x=V[i].px;
                                    fire_y=V[i].py;
                                }
                                V[i].dir='l';
                                if(V[i].px%2) V[i].px--;
                                else if(V[i].px%2==0) V[i].px-=2;
                                V[i].state++;
                                if(V[i].die_mode==1)
                                {
                                    V[i].no=2;
                                }
                                if((V[i].state/10)%2) V[i].no=2;
                                else V[i].no=6;
                            }
                        }
                        else if(g_u&&V[i].die_mode!=1)
                        {
                            V[i]._x=(V[i].px-(screenHeight-mazeheight)/2)/boxLength;
                            V[i]._y=(V[i].py-(screenHeight-mazeheight)/2)/boxLength;
                            if(ara[V[i]._y+1][V[i]._x]!=1&&V[i].px%boxLength==0){
                                if(/*pacc.poy>V[i].py&&i==0&&/*pacc.pox==V[i].px&&*/fire_mode==0&&i==0)
                                {
                                    fire_mode=1;
                                    fire_r=0;
                                    fire_l=0;
                                    fire_u=1;
                                    fire_d=0;
                                    fire_x=V[i].px;
                                    fire_y=V[i].py;
                                }
                                V[i].dir='u';
                                if(V[i].py%2) V[i].py++;
                                else if(V[i].py%2==0) V[i].py+=2;
                                V[i].state++;
                                if((V[i].state/10)%2) V[i].no=1;
                                else V[i].no=5;
                            }
                        }

                        else if(g_d&&V[i].die_mode!=1)
                        {
                            V[i]._x=(V[i].px-(screenHeight-mazeheight)/2)/boxLength;
                            V[i]._y=(V[i].py-1-(screenHeight-mazeheight)/2)/boxLength;
                            if(ara[V[i]._y][V[i]._x]!=1&&V[i].px%boxLength==0){
                                if(/*pacc.poy<V[i].py&&i==0&&pacc.pox==V[i].px&&*/fire_mode==0&&i==0)
                                {
                                    fire_mode=1;
                                    fire_r=0;
                                    fire_l=0;
                                    fire_u=0;
                                    fire_d=1;
                                    fire_x=V[i].px;
                                    fire_y=V[i].py;
                                }
                                V[i].dir='d';
                                if(V[i].py%2) V[i].py--;
                                else if(V[i].py%2==0) V[i].py-=2;
                                V[i].state++;
                                if((V[i].state/10)%2)
                                    V[i].no=3;
                                else V[i].no=7;
                            }
                        }
                        else if(V[i].die_mode==1)
                        {
                            target_x=360;
                            target_y=450;
                            flee_r=0,flee_l=0,flee_u=0,flee_d=0;
                            V[i]._x=(V[i].px-(screenHeight-mazeheight)/2)/boxLength;
                            V[i]._y=(V[i].py-(screenHeight-mazeheight)/2)/boxLength;
                            if(ara[V[i]._y][V[i]._x+1]!=1&&V[i].py%boxLength==0&&target_x>V[i].px&&V[i].dir!='l')
                            {
                                flee_u=0;
                                flee_d=0;
                                flee_r=1;
                                flee_l=0;
                            }
                            else if(V[i].dir!='r'&&target_x<V[i].px&&ara[(V[i].py-(screenHeight-mazeheight)/2)/boxLength][(V[i].px-1-(screenHeight-mazeheight)/2)/boxLength]!=1&&V[i].py%boxLength==0)
                            {
                                flee_u=0;
                                flee_d=0;
                                flee_r=0;
                                flee_l=1;
                            }
                            else if(V[i].dir!='d'&&target_y>V[i].py&&ara[((V[i].py-(screenHeight-mazeheight)/2)/boxLength)+1][(V[i].px-(screenHeight-mazeheight)/2)/boxLength]!=1&&V[i].px%boxLength==0)
                            {

                                flee_u=1;
                                flee_d=0;
                                flee_r=0;
                                flee_l=0;
                            }
                            else if(V[i].dir!='u'&&target_y<V[i].py&&ara[(V[i].py-1-(screenHeight-mazeheight)/2)/boxLength][(V[i].px-(screenHeight-mazeheight)/2)/boxLength]!=1&&V[i].px%boxLength==0)
                            {
                                flee_u=0;
                                flee_d=1;
                                flee_r=0;
                                flee_l=0;

                            }
                            else if(ara[V[i]._y][V[i]._x+1]!=1&&V[i].dir!='l'&&V[i].py%boxLength==0)
                            {
                                flee_r=1;
                            }
                            else if(ara[(V[i].py-(screenHeight-mazeheight)/2)/boxLength][(V[i].px-1-(screenHeight-mazeheight)/2)/boxLength]!=1&&V[i].dir!='r'&&V[i].py%boxLength==0)
                            {
                                flee_l=1;
                            }
                            else if(ara[((V[i].py-(screenHeight-mazeheight)/2)/boxLength)+1][(V[i].px-(screenHeight-mazeheight)/2)/boxLength]!=1&&V[i].dir!='d'&&V[i].px%boxLength==0)
                            {
                                flee_u=1;
                            }
                            else if(ara[(V[i].py-1-(screenHeight-mazeheight)/2)/boxLength][(V[i].px-(screenHeight-mazeheight)/2)/boxLength]!=1&&V[i].dir!='u'&&V[i].px%boxLength==0)
                            {
                                flee_d=1;
                            }
                            if(flee_r)
                            {
                                V[i].no=0;
                                V[i].dir='r';
                                if(V[i].px%3) V[i].px+=(3-V[i].px%3);
                                else
                                    V[i].px+=3;
                            }
                            if(flee_l)
                            {
                                V[i].no=2;
                                V[i].dir='l';
                                if(V[i].px%3) V[i].px-=(V[i].px%3);
                                else
                                    V[i].px-=3;
                            }
                            if(flee_u)
                            {
                                V[i].no=1;
                                V[i].dir='u';
                                if(V[i].py%3) V[i].py+=(3-V[i].py%3);
                                else
                                    V[i].py+=3;
                            }
                            if(flee_d)
                            {
                                V[i].no=3;
                                V[i].dir='d';
                                if(V[i].py%3) V[i].py-=(V[i].py%3);
                                else
                                    V[i].py-=3;
                            }
                        }
                        if(V[i].px+boxLength>570+(screenHeight-mazeheight)/2)
                        {
                            V[i].px=(screenHeight-mazeheight)/2;
                            V[i].state=(V[i].state+1)%2;
                            V[i].initial=0;
                            V[i].dir='k';
                            if(V[i].die_mode==1)
                            {
                                V[i].no=0;
                            }
                            else if(V[i].die_mode!=1) {
                                if(V[i].state%2)
                                {
                                    V[i].no=0;
                                }
                                else V[i].no=4;
                            }
                        }
                        else if(V[i].px<(screenHeight-mazeheight)/2)
                        {
                            V[i].initial=0;
                            V[i].dir='k';
                            V[i].px=570-boxLength+(screenHeight-mazeheight)/2;
                            V[i].state=(V[i].state+1)%2;
                            if(V[i].die_mode==1)
                            {
                                V[i].no=2;
                            }
                            else if(V[i].die_mode!=1){
                                if(V[i].state%2)
                                {
                                    V[i].no=2;
                                }
                                else V[i].no=6;
                            }
                        }

                    }
                }
                if(frightened_mode)
                {
                    call2++;
                    for(int i=0;i<4;i++)
                    {
                            if(i==0&&(V[i].die_mode==0||V[i].die_mode==2)&&V[i].ghost_mode==0)
                            {
                                target_x=pacc.pox;
                                target_y=pacc.poy;
                                V[i].a[12][9]=1;
                            }
                            if(i==1&&(V[i].die_mode==0||V[i].die_mode==2)&&V[i].ghost_mode==0)
                            {

                                V[i].a[12][9]=1;
                                if(pacc.right)
                                {
                                    target_x=pacc.pox+120;
                                    target_y=pacc.poy;
                                }
                                else if(pacc.left)
                                {
                                    target_x=pacc.pox-120;
                                    target_y=pacc.poy;
                                }
                                else if(pacc.up)
                                {
                                    target_x=pacc.pox;
                                    target_y=pacc.poy+120;
                                }
                                else if(pacc.down)
                                {
                                    target_x=pacc.pox;
                                    target_y=pacc.poy-120;
                                }
                                else
                                {
                                    target_x=pacc.pox+60;
                                    target_y=pacc.poy+60;
                                }
                            }
                            if(i==2&&(V[i].die_mode==0||V[i].die_mode==2)&&V[i].ghost_mode==0)
                            {
                                V[i].a[12][9]=1;
                                target_x=(2*pacc.pox-V[i].px);
                                target_y=(2*pacc.poy-V[i].py);
                                if(target_x<(screenHeight-mazeheight)/2)
                                {
                                    target_x=(screenHeight-mazeheight)/2;
                                }
                                if(target_x>570+(screenHeight-mazeheight)/2)
                                {
                                    target_x=570+(screenHeight-mazeheight)/2;
                                }
                                if(target_y<(screenHeight-mazeheight)/2)
                                {
                                    target_y=(screenHeight-mazeheight)/2;
                                }
                                if(target_y>630+(screenHeight-mazeheight)/2)
                                {
                                    target_y=630+(screenHeight-mazeheight)/2;
                                }
                            }
                            if(i==3&&(V[i].die_mode==0||V[i].die_mode==2)&&V[i].ghost_mode==0)
                            {
                                V[i].a[12][9]=1;
                                if(pacc.right)
                                {
                                    target_x=pacc.pox-120;
                                    target_y=pacc.poy;
                                }
                                else if(pacc.left)
                                {
                                    target_x=pacc.pox+120;
                                    target_y=pacc.poy;
                                }
                                else if(pacc.up)
                                {
                                    target_x=pacc.pox;
                                    target_y=pacc.poy-120;
                                }
                                else if(pacc.down)
                                {
                                    target_x=pacc.pox;
                                    target_y=pacc.poy+120;
                                }
                                else
                                {
                                    target_x=pacc.pox+60;
                                    target_y=pacc.poy+60;
                                }
                            }
                            maxi=0;
                            maxi1=0,maxi2=0,maxi3=0,maxi4=0;
                            g_d=0;g_l=0,g_r=0,g_u=0;
                            //for right move
                            V[i]._x=(V[i].px-(screenHeight-mazeheight)/2)/boxLength;
                            V[i]._y=(V[i].py-(screenHeight-mazeheight)/2)/boxLength;
                            if(ara[V[i]._y][V[i]._x+1]!=1&&V[i].py%boxLength==0)
                            {
                                maxi1=((V[i]._x+1)*boxLength-target_x)*((V[i]._x+1)*boxLength-target_x)+((V[i]._y)*boxLength-target_y)*((V[i]._y)*boxLength-target_y);
                            }
                            //for left move
                            V[i]._x=(V[i].px-1-(screenHeight-mazeheight)/2)/boxLength;
                            V[i]._y=(V[i].py-(screenHeight-mazeheight)/2)/boxLength;
                            if(ara[V[i]._y][V[i]._x]!=1&&V[i].py%boxLength==0)
                            {
                                maxi2=((V[i]._x)*boxLength-target_x)*((V[i]._x)*boxLength-target_x)+((V[i]._y)*boxLength-target_y)*((V[i]._y)*boxLength-target_y);
                            }
                            //for up move
                            V[i]._x=(V[i].px-(screenHeight-mazeheight)/2)/boxLength;
                            V[i]._y=(V[i].py-(screenHeight-mazeheight)/2)/boxLength;
                            if(ara[V[i]._y+1][V[i]._x]!=1&&V[i].px%boxLength==0)
                            {
                                maxi3=((V[i]._x)*boxLength-target_x)*((V[i]._x)*boxLength-target_x)+((V[i]._y+1)*boxLength-target_y)*((V[i]._y+1)*boxLength-target_y);
                            }
                            //for down move
                            V[i]._x=(V[i].px-(screenHeight-mazeheight)/2)/boxLength;
                            V[i]._y=(V[i].py-1-(screenHeight-mazeheight)/2)/boxLength;
                            if(ara[V[i]._y][V[i]._x]!=1&&V[i].px%boxLength==0)
                            {
                                maxi4=((V[i]._x)*boxLength-target_x)*((V[i]._x)*boxLength-target_x)+(V[i]._y*boxLength-target_y)*((V[i]._y)*boxLength-target_y);
                            }
                            if(ara[V[i]._y][V[i]._x]!=1&&V[i]._x==9&&V[i]._y==12&&V[i].px%boxLength==0)
                            {
                                maxi4=0;
                            }
                            if(maxi1>maxi)
                            {
                                if(V[i].initial==0)
                                {
                                    g_r=1;
                                    V[i].dir='r';
                                    maxi=maxi1;
                                    V[i].initial=1;
                                }
                                else
                                {
                                    if(V[i].dir!='l')
                                    {
                                        maxi=maxi1;
                                        g_r=1;
                                        g_d=0,g_l=0,g_u=0;
                                    }
                                }
                            }
                            if(maxi<maxi3)
                            {
                                if(V[i].initial==0)
                                {
                                    g_u=1;
                                    V[i].dir='u';
                                    maxi=maxi3;
                                    V[i].initial=1;
                                }
                                else
                                {
                                    if(V[i].dir!='d')
                                    {
                                        maxi=maxi3;
                                        g_u=1;
                                        g_d=0,g_l=0,g_r=0;
                                    }
                                }
                            }
                            if(maxi<maxi2)
                            {
                                if(V[i].initial==0)
                                {
                                    g_l=1;
                                    V[i].dir='l';
                                    maxi=maxi2;
                                    V[i].initial=1;
                                }
                                else
                                {
                                    if(V[i].dir!='r')
                                    {
                                        maxi=maxi2;
                                        g_l=1;
                                        g_d=0,g_r=0,g_u=0;
                                    }
                                }
                            }
                            if(maxi<maxi4)
                            {
                                if(V[i].initial==0)
                                {
                                    g_d=1;
                                    V[i].dir='d';
                                    maxi=maxi4;
                                    V[i].initial=1;
                                }
                                else
                                {
                                    if(V[i].dir!='u')
                                    {
                                        maxi=maxi4;
                                        g_d=1;
                                        g_r=0,g_l=0,g_u=0;
                                    }
                                }
                            }
                            if(g_r&&V[i].ghost_mode!=1&&V[i].die_mode!=1)
                            {
                                V[i]._x=(V[i].px-(screenHeight-mazeheight)/2)/boxLength;
                                V[i]._y=(V[i].py-(screenHeight-mazeheight)/2)/boxLength;
                                if(ara[V[i]._y][V[i]._x+1]!=1&&V[i].py%boxLength==0){
                                    V[i].dir='r';
                                    V[i].state=(V[i].state+1)%2;
                                    if(call2==500&&V[i].px%2) V[i].px+=2;
                                    else V[i].px++;
                                }
                            }
                            else if(g_l&&V[i].ghost_mode!=1&&V[i].die_mode!=1)
                            {
                                V[i]._x=(V[i].px-1-(screenHeight-mazeheight)/2)/boxLength;
                                V[i]._y=(V[i].py-(screenHeight-mazeheight)/2)/boxLength;
                                if(ara[V[i]._y][V[i]._x]!=1&&V[i].py%boxLength==0){
                                    V[i].dir='l';
                                    V[i].state=(V[i].state+1)%2;
                                    if(call2==500&&V[i].px%2) V[i].px-=2;
                                    else V[i].px--;
                                }
                            }
                            else if(g_u&&V[i].ghost_mode!=1&&V[i].die_mode!=1)
                            {
                                V[i]._x=(V[i].px-(screenHeight-mazeheight)/2)/boxLength;
                                V[i]._y=(V[i].py-(screenHeight-mazeheight)/2)/boxLength;
                                if(ara[V[i]._y+1][V[i]._x]!=1&&V[i].px%boxLength==0){
                                    V[i].dir='u';
                                    V[i].state=(V[i].state+1)%2;
                                    if(call2==500&&V[i].py%2) V[i].py+=2;
                                    else V[i].py++;

                                }
                            }
                            else if(g_d&&V[i].ghost_mode!=1&&V[i].die_mode!=1)
                            {
                                V[i]._x=(V[i].px-(screenHeight-mazeheight)/2)/boxLength;
                                V[i]._y=(V[i].py-1-(screenHeight-mazeheight)/2)/boxLength;
                                if(ara[V[i]._y][V[i]._x]!=1&&V[i].px%boxLength==0){
                                    V[i].dir='d';
                                    V[i].state=(V[i].state+1)%2;
                                    if(call2==500&&V[i].py%2) V[i].py-=2;
                                    else V[i].py--;
                                }
                            }
                            if(V[i].px+boxLength>570+(screenHeight-mazeheight)/2&&V[i].ghost_mode!=1&&V[i].die_mode!=1)
                            {
                                V[i].px=(screenHeight-mazeheight)/2;
                                V[i].state=(V[i].state+1)%2;
                                V[i].initial=0;
                                V[i].dir='k';
                            }
                            else if(V[i].px<(screenHeight-mazeheight)/2&&V[i].ghost_mode!=1&&V[i].die_mode!=1)
                            {
                                V[i].initial=0;
                                V[i].px=570-boxLength+(screenHeight-mazeheight)/2;
                                V[i].state=(V[i].state+1)%2;
                                V[i].dir='k';
                            }
                        }
                }
            }
            if(fire_mode&&PAUSE==0)
            {
                if(fire_l)
                {
                    if(fire_x%3)
                    {
                        fire_x-=(fire_x%3);
                    }
                    else fire_x-=3;
                }
                if(fire_r)
                {
                    if(fire_x%3)
                    {
                        fire_x+=(3-fire_x%3);
                    }
                    else fire_x+=3;
                }
                if(fire_u)
                {
                    if(fire_y%3)
                    {
                        fire_y+=(3-fire_y%3);
                    }
                    else fire_y+=3;
                }
                if(fire_d)
                {
                    if(fire_y%3)
                    {
                        fire_y-=(fire_y%3);
                    }
                    else fire_y-=3;
                }
            }
            if(call2>500)
            {
                call2=0;
                for(int idx=0;idx<4;idx++)
                {
                    //V[idx].initial=0;
                    if(V[idx].die_mode!=1) V[idx].ghost_mode=1;
                }
                frightened_mode=0;
            }
            call++;
            if(PAUSE==0){
                for(int idx=0;idx<4;idx++)
                {
                    if(abs(pacc.pox-V[idx].px)<=10&&abs(pacc.poy-V[idx].py)<=10&&V[idx].ghost_mode==0&&V[idx].die_mode!=1)
                    {
                        score+=100;
                        V[idx].die_mode=1;
                        V[idx].ghost_mode=0;
                        V[idx].initial=0;
                        V[idx].dir='k';
                        V[idx].a[12][9]=0;
                        music_5=1;
                        music();
                    }
                    else if(abs(fire_x-pacc.pox)<=10&&abs(fire_y-pacc.poy)<=10&&fire_mode&&hide_mode==0)
                    {
                        music_4=1;
                        music();
                        die--;
                        PAUSE=1;
                        break;
                    }
                    else if(hide_mode==0&&((abs(pacc.pox-V[idx].px)<=10&&abs(pacc.poy-V[idx].py)<=10&&V[idx].ghost_mode==1)||(fire_mode&&abs(fire_x-pacc.pox)<=10&&abs(fire_y-pacc.poy)<=10)))
                    {
                        music_4=1;
                        music();
                        die--;
                        PAUSE=1;
                        break;
                    }
                }
            }
            if(PAUSE)
            {
                pac=2;
                PAUSE++;
            }
            if(PAUSE==100)
            {
                for(int idx=0;idx<4;idx++)
                {
                    V[idx].px=V[idx].return_x;
                    V[idx].py=V[idx].return_y;
                    V[idx].ghost_mode=1;
                    V[idx].die_mode=2;
                    V[idx].a[12][9]=0;
                    V[idx].initial=0;
                    pause_mode_for_ghosts=0;
                    hide_mode=0;
                    speed_mode=0;
                }
                frightened_mode=0;
                PAUSE=0;
                pacc.pox=120+(screenHeight-mazeheight)/2;
                pacc.poy=30+(screenHeight-mazeheight)/2;
                call=0;
                call2=0;
                call3=0;
                call4=0;
                call5=0;
                pressed=0;
                pacc.left=0;
                pacc.right=0;
                pacc.up=0;
                pacc.down=0;
                pac=0;
                pac_no=0;
                fire_mode=0,fire_l=0,fire_r=0,fire_u=0,fire_d=0;
                music_1=0;
                music_2=0;
                music_3=0;
                music_4=0;
                music_5=0;
            }
        }
    }
}
void DRAW()
{
        int x=0;
        iSetColor(155,155,155);
        for(int i=90;i<mazeheight+(screenHeight-mazeheight)/2;i+=boxLength)
        {
            int y=0;
            for(int j=90;j<mazewidth+(screenHeight-mazeheight)/2;j+=boxLength)
            {
                if(ara[x][y]==1)
                {
                    if(x==12&&y==9);
                    else {
                            iSetColor(120,120,125);
                            iFilledRectangle(j,i,boxLength,boxLength);
                    }
                }
                    //else
                    //{
                        if(ara[x][y]==0)
                        {
                            iSetColor(255,0,0);
                            iFilledCircle(j+boxLength/2,i+boxLength/2,2);
                        }
                        if(ara[x][y]==3)
                        {
                            iSetColor(255,0,0);
                            iFilledCircle(j+boxLength/2,i+boxLength/2,6);
                        }
                        if(ara[x][y]==5)
                        {
                            iShowBMP2(j,i,food[1],0);
                        }
                        if(ara[x][y]==6)
                        {
                            iShowBMP2(j,i,food[0],0);
                        }
                        if(ara[x][y]==7)
                        {
                            iShowBMP2(j,i,food[2],0);
                        }
                    //}
                y++;
            }
            x++;
        }
        iSetColor(50,200,250);
        iFilledRectangle(360,475,30,5);
        if(pacc.pox+boxLength>570+(screenHeight-mazeheight)/2&&pacc.right)
        {
            pacc.pox=(screenHeight-mazeheight)/2;
        }
        else if(pacc.pox<(screenHeight-mazeheight)/2&&pacc.left)
        {
            pacc.pox=570-boxLength+(screenHeight-mazeheight)/2;
        }
        if(fire_mode)
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
        if(frightened_mode)
        {
            for(int idx=0;idx<4;idx++)
            {
                if((V[idx].die_mode==0||V[idx].die_mode==2)&&V[idx].ghost_mode==0) {
                    if(call2<350||(call2>400&&call2<450)) iShowBMP2(V[idx].px,V[idx].py,DIE[V[idx].state%2],0);
                    else if((call2>=350&&call2<=400)||(call2>=450&&call2<=500)) iShowBMP2(V[idx].px,V[idx].py,DIE[3],0);
                }
            }
        }
        iSetColor(0,255,255);
        iText(360,760,t,GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,0,0);
        iText(490+120,760,"Score",GLUT_BITMAP_TIMES_ROMAN_24);
        itoa(score,s,10);
        iText(590+120,760,s,GLUT_BITMAP_TIMES_ROMAN_24);
        int q=0;
        for(int idx=0;idx<die;idx++)
        {
            iShowBMP2(710+120+q,620,pacman_pic[2][2],0);
            q+=40;
        }
        iSetColor(120,120,125);
        iFilledRectangle(690+120,280,120,30);
        iFilledRectangle(690+120,230,120,30);
        iSetColor(0,0,0);
        iText(710+120,285,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(710+120,235,"MENU",GLUT_BITMAP_TIMES_ROMAN_24);
}
void show_score()
{
    int x=330,y=740;
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
void iDraw()
{
    iClear();
    if(game_strt)
    {
        if((start||resume)&&die&&qx==0&&WIN==0)
        {
            if(sound){
                if(music_1){
                    PlaySound("pacman_beginning.wav",NULL,SND_ASYNC);
                    music_1=0;
                }
            }
            DRAW();
            if(PAUSE==0) iShowBMP2(pacc.pox,pacc.poy,pacman_pic[pac_no][pac],0);
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
                    iText(350,500,"YOUR SCORE  ",GLUT_BITMAP_TIMES_ROMAN_24);
                    iText(550,500,s,GLUT_BITMAP_TIMES_ROMAN_24);
                    iText(350,450,t,GLUT_BITMAP_TIMES_ROMAN_24);
                }
                else if(!NAMETAKEN)
                {
                    iSetColor(0,0,0);
                    iFilledRectangle(0,0,screenWidth,screenHeight);
                    iSetColor(255,255,255);
                    iText(35,500,"TYPE YOUR NAME : ",GLUT_BITMAP_TIMES_ROMAN_24);
                    iRectangle(270,480,500,50);
                    iText(290,500,str,GLUT_BITMAP_TIMES_ROMAN_24);

                }
                else if(NAMETAKEN)
                {
                    save_game();
                    if(!HIGH&&!rules)
                    {
                        iShowBMP(0,0,cover[0]);
                        iSetColor(0,0,0);
                        iText(20,20,"Press < to see rules",GLUT_BITMAP_HELVETICA_18);
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
                iShowBMP(0,0,cover[0]);
                iSetColor(255,255,255);
                iText(20,80,"Press < to see rules",GLUT_BITMAP_HELVETICA_18);
            }
            if(music_1==0)
            {
                PlaySound("Immigrant.wav",NULL,SND_LOOP|SND_ASYNC);
                music_1=1;
            }
            if(qx)
            {
                iShowBMP(225,480,"SOUND.bmp");
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
void iMouseMove(int buttonx, int buttony)
{

}

void iMouse(int button, int state, int mx, int my){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(mx>=60&&mx<=320&&my>=690&&my<=730&&qx==0)
        {
            initialize();
            start=1;
            continue_game=0;
            pause_game=0;
            resume=0;
        }
        if(mx>=55&&mx<=310&&my>=640&&my<=668&&qx==0)
        {
            start=1;
            continue_game=1;
            load_game();
            pause_game=0;
            resume=0;
        }
        if(mx>=70&&mx<=300&&my>=580&&my<=610&&qx==0)
        {
            getHighscore();
            HIGH=1;
        }
        if(mx>=90&&mx<=215&&my>=530&&my<=560)
        {
            qx=1;
        }
        if(mx>=90&&mx<=200&&my>=490&&my<=520)
        {
            putHighscore();
            if((die==0||WIN)&&NAMETAKEN==1)
            {
                initialize();
            }
            save_game();
            exit(0);
        }
        if(mx>=800&&mx<=930&&my>=280&&my<=310)
        {
            putHighscore();
            if((die==0||WIN)&&NAMETAKEN==1)
            {
                initialize();
            }
            save_game();
            exit(0);
        }
        if(mx>=800&&mx<=930&&my>=230&&my<=260)
        {
            if((die==0||WIN)&&NAMETAKEN==1)
            {
                initialize();
            }
            save_game();
            start=0;
        }

        if(mx>=235&&mx<=275&&my>=520&&my<=540&&qx==1)
        {
           qx=0;
           sound=1;
        }
        if(mx>=285&&mx<=320&&my>=520&&my<=540&&qx==1)
        {
           qx=0;
           sound=0;
        }

    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {

    }
}

void iKeyboard(unsigned char key)
{
    if(!NAMETAKEN&&!HIGH&&GAMEOVER==500)
    {
            if(key=='\r')
            {
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
    }
    else if(key=='<'&&!HIGH)
    {
        rules=(rules+1)%2;
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
	//place your codes for other keys here
}
void change()
{
    if(resume||start) tim++;
    //printf("%d\n",tim );
}
int main()
{
        V[0].px=350;
        V[0].py=480;
        V[0]._x;
        V[0]._y;
        V[0].return_x=350;
        V[0].return_y=480;
        V[0].state=0;
        V[0].dir='k';
        V[0].ghost_mode=1;
        V[0].die_mode=2;
        V[1].px=330;
        V[1].py=420;
        V[1]._x;
        V[1]._y;
        V[1].return_x=330;
        V[1].return_y=420;
        V[1].state=0;
        V[1].dir='k';
        V[1].ghost_mode=1;
        V[1].die_mode=0;
        V[2].px=360;
        V[2].py=420;
        V[2]._x;
        V[2]._y;
        V[2].return_x=360;
        V[2].return_y=420;
        V[2].state=0;
        V[2].dir='k';
        V[2].ghost_mode=1;
        V[2].die_mode=2;
        V[3].px=390;
        V[3].py=420;
        V[3]._x;
        V[3]._y;
        V[3].return_x=390;
        V[3].return_y=420;
        V[3].state;
        V[3].dir='k';
        V[3].ghost_mode=1;
        V[3].die_mode=2;
        V[0].initial=0;
        V[1].initial=0;
        V[2].initial=0;
        V[3].initial=0;
        V[0].no;
        V[1].no;
        V[2].no;
        V[3].no;
        V[0].scatter_x=150;
        V[0].scatter_y=330;
        V[1].scatter_x=150;
        V[1].scatter_y=570;
        V[2].scatter_x=480;
        V[2].scatter_y=630;
        V[3].scatter_x=240;
        V[3].scatter_y=390;
        V[0].a[12][9]=0;
        V[1].a[12][9]=0;
        V[2].a[12][9]=0;
        V[3].a[12][9]=0;
        iSetTimer(40,strt_);
        iSetTimer(120,pac_type);
        iSetTimer(10,pacman_move);
        iSetTimer(15,ghost_move);
        iSetTimer(1000,change);
        iInitialize(1200,810, "pacman");
        return 0;
}
