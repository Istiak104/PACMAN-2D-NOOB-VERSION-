#include<windows.h>
#include<bits/stdc++.h>
#include"Pacman_move.cpp"
using namespace std ;

void ghost_move()
{
    if(die&&WIN!=1&&q==0){
        if(start||resume){
            if(ara[maze][level][(fire_y-(screenHeight-mazeheight)/2)/boxLength][((fire_x-(screenHeight-mazeheight)/2)/boxLength)+1]==1&&fire_r)
            {
                fire_mode=0;
                fire_l=0,fire_r=0,fire_u=0,fire_d=0;
            }
            if(ara[maze][level][(fire_y-(screenHeight-mazeheight)/2)/boxLength][(fire_x-1-(screenHeight-mazeheight)/2)/boxLength]==1&&fire_l)
            {
                fire_mode=0;
                fire_l=0,fire_r=0,fire_u=0,fire_d=0;
            }
            if(ara[maze][level][((fire_y-(screenHeight-mazeheight)/2)/boxLength)+1][(fire_x-(screenHeight-mazeheight)/2)/boxLength]==1&&fire_u)
            {
                fire_mode=0;
                fire_l=0,fire_r=0,fire_u=0,fire_d=0;
            }
            if(ara[maze][level][(fire_y-1-(screenHeight-mazeheight)/2)/boxLength][(fire_x-(screenHeight-mazeheight)/2)/boxLength]==1&&fire_d)
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
                            target_x=pacc.pox;    target_y=pacc.poy;
                        }
                        if(i==1&&V[i].ghost_mode)
                        {
                            if(pacc.right)
                            {
                                target_x=pacc.pox+120;    target_y=pacc.poy;
                            }
                            else if(pacc.left)
                            {
                                target_x=pacc.pox-120;    target_y=pacc.poy;
                            }
                            else if(pacc.up)
                            {
                                target_x=pacc.pox;    target_y=pacc.poy+120;
                            }
                            else if(pacc.down)
                            {
                                target_x=pacc.pox;    target_y=pacc.poy-120;
                            }
                            else
                            {
                                target_x=pacc.pox+60;    target_y=pacc.poy+60;
                            }
                        }
                        if(i==2&&V[i].ghost_mode)
                        {
                            target_x=(2*pacc.pox-V[i].px);
                            target_y=(2*pacc.poy-V[i].py);
                            if(target_x<(screenHeight-mazeheight)/2)    target_x=(screenHeight-mazeheight)/2;
                            if(target_x>540+(screenHeight-mazeheight)/2)    target_x=540+(screenHeight-mazeheight)/2;
                            if(target_y<(screenHeight-mazeheight)/2)    target_y=(screenHeight-mazeheight)/2;
                            if(target_y>630+(screenHeight-mazeheight)/2)    target_y=630+(screenHeight-mazeheight)/2;
                        }
                        if(i==3&&V[i].ghost_mode)
                        {
                            if(pacc.right)
                            {
                                target_x=pacc.pox-120;    target_y=pacc.poy;
                            }
                            else if(pacc.left)
                            {
                                target_x=pacc.pox+120;     target_y=pacc.poy;
                            }
                            else if(pacc.up)
                            {
                                target_x=pacc.pox;   target_y=pacc.poy-120;
                            }
                            else if(pacc.down)
                            {
                                target_x=pacc.pox;   target_y=pacc.poy+120;
                            }
                            else
                            {
                                target_x=pacc.pox+60;   target_y=pacc.poy+60;
                            }
                        }
                        if((call>=0&&call<=500||hide_mode)&&V[i].ghost_mode)
                        {
                            target_x=V[i].scatter_x;   target_y=V[i].scatter_y;
                        }
                        if(V[i].die_mode==1&&V[i].px==360&&V[i].py==420)
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
                        if(ara[maze][level][V[i]._y][V[i]._x+1]!=1&&V[i].py%boxLength==0)
                        {
                            mini1=((V[i]._x+1)*boxLength-target_x)*((V[i]._x+1)*boxLength-target_x)+((V[i]._y)*boxLength-target_y)*((V[i]._y)*boxLength-target_y);
                        }
                        //for left move
                        V[i]._x=(V[i].px-1-(screenHeight-mazeheight)/2)/boxLength;
                        V[i]._y=(V[i].py-(screenHeight-mazeheight)/2)/boxLength;
                        if(ara[maze][level][V[i]._y][V[i]._x]!=1&&V[i].py%boxLength==0)
                        {
                            mini2=((V[i]._x)*boxLength-target_x)*((V[i]._x)*boxLength-target_x)+((V[i]._y)*boxLength-target_y)*((V[i]._y)*boxLength-target_y);
                        }
                        //for up move
                        V[i]._x=(V[i].px-(screenHeight-mazeheight)/2)/boxLength;
                        V[i]._y=(V[i].py-(screenHeight-mazeheight)/2)/boxLength;
                        if(ara[maze][level][V[i]._y+1][V[i]._x]!=1&&V[i].px%boxLength==0)
                        {
                            mini3=((V[i]._x)*boxLength-target_x)*((V[i]._x)*boxLength-target_x)+((V[i]._y+1)*boxLength-target_y)*((V[i]._y+1)*boxLength-target_y);
                        }
                        //for down move
                        V[i]._x=(V[i].px-(screenHeight-mazeheight)/2)/boxLength;
                        V[i]._y=(V[i].py-1-(screenHeight-mazeheight)/2)/boxLength;
                        if(ara[maze][level][V[i]._y][V[i]._x]!=1&&V[i].px%boxLength==0)
                        {
                            mini4=((V[i]._x)*boxLength-target_x)*((V[i]._x)*boxLength-target_x)+(V[i]._y*boxLength-target_y)*((V[i]._y)*boxLength-target_y);
                        }
                        if(ara[maze][level][V[i]._y][V[i]._x]!=1&&V[i]._x==9&&V[i]._y==11&&V[i].px%boxLength==0)
                        {
                            mini4=1e9;
                            g_d=0;
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
                        if(g_r&&V[i].die_mode!=1)
                        {
                            V[i]._x=(V[i].px-(screenHeight-mazeheight)/2)/boxLength;
                            V[i]._y=(V[i].py-(screenHeight-mazeheight)/2)/boxLength;
                            if(ara[maze][level][V[i]._y][V[i]._x+1]!=1&&V[i].py%boxLength==0){
                                if((fire_mode==0&&i==0&&level>5&&maze==0)||(fire_mode==0&&i==0&&level>1&&maze!=0))
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
                                if((level<=3&&maze==0)||(level<1&&maze!=0)){
                                    if(V[i].px%2) V[i].px+=1;
                                    else if(V[i].px%2==0) V[i].px+=1;
                                }
                                else if((level>3&&maze==0)||(level>=1&&maze!=0))
                                {
                                    if(V[i].px%2) V[i].px+=1;
                                    else V[i].px+=2;
                                }
                                if(V[i].state>=1000)    V[i].state=0;
                                V[i].state++;
                                if((V[i].state/4)%2)    V[i].no=0;
                                else V[i].no=4;
                            }
                        }
                        else if(g_l&&V[i].die_mode!=1)
                        {
                            V[i]._x=(V[i].px-1-(screenHeight-mazeheight)/2)/boxLength;
                            V[i]._y=(V[i].py-(screenHeight-mazeheight)/2)/boxLength;
                            if(ara[maze][level][V[i]._y][V[i]._x]!=1&&V[i].py%boxLength==0){
                                if((fire_mode==0&&i==0&&level>5&&maze==0)||(fire_mode==0&&i==0&&level>1&&maze!=0))
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
                                if((level<=3&&maze==0)||(level<1&&maze!=0)){
                                    if(V[i].px%2) V[i].px-=1;
                                    else if(V[i].px%2==0) V[i].px-=1;
                                }
                                else if((level>3&&maze==0)||(level>=1&&maze!=0))
                                {
                                    if(V[i].px%2) V[i].px-=1;
                                    else V[i].px-=2;
                                }
                                if(V[i].state>=1000)  V[i].state=0;
                                V[i].state++;
                                if((V[i].state/4)%2) V[i].no=2;
                                else V[i].no=6;
                            }
                        }
                        else if(g_u&&V[i].die_mode!=1)
                        {
                            V[i]._x=(V[i].px-(screenHeight-mazeheight)/2)/boxLength;
                            V[i]._y=(V[i].py-(screenHeight-mazeheight)/2)/boxLength;
                            if(ara[maze][level][V[i]._y+1][V[i]._x]!=1&&V[i].px%boxLength==0){
                                if((fire_mode==0&&i==0&&level>5&&maze==0)||(fire_mode==0&&i==0&&level>1&&maze!=0))
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
                                if((level<=3&&maze==0)||(level<1&&maze!=0)){
                                    if(V[i].py%2) V[i].py+=1;
                                    else if(V[i].py%2==0) V[i].py+=1;
                                }
                                else if((level>3&&maze==0)||(level>=1&&maze!=0))
                                {
                                    if(V[i].py%2) V[i].py+=1;
                                    else V[i].py+=2;
                                }
                                if(V[i].state>=1000)  V[i].state=0;
                                V[i].state++;
                                if((V[i].state/4)%2) V[i].no=1;
                                else V[i].no=5;
                            }
                        }

                        else if(g_d&&V[i].die_mode!=1)
                        {
                            V[i]._x=(V[i].px-(screenHeight-mazeheight)/2)/boxLength;
                            V[i]._y=(V[i].py-1-(screenHeight-mazeheight)/2)/boxLength;
                            if(ara[maze][level][V[i]._y][V[i]._x]!=1&&V[i].px%boxLength==0){
                                if((fire_mode==0&&i==0&&level>5&&maze==0)||(fire_mode==0&&i==0&&level>1&&maze!=0))
                                {
                                    //pacc.poy<V[i].py&&i==0&&pacc.pox==V[i].px&&
                                    fire_mode=1;
                                    fire_r=0;
                                    fire_l=0;
                                    fire_u=0;
                                    fire_d=1;
                                    fire_x=V[i].px;
                                    fire_y=V[i].py;
                                }
                                V[i].dir='d';
                                if((level<=3&&maze==0)||(level<1&&maze!=0)){
                                    if(V[i].py%2) V[i].py-=1;
                                    else if(V[i].py%2==0) V[i].py-=1;
                                }
                                else if((level>3&&maze==0)||(level>=1&&maze!=0))
                                {
                                    if(V[i].py%2) V[i].py-=1;
                                    else V[i].py-=2;
                                }
                                if(V[i].state>=1000) V[i].state=0;
                                V[i].state++;
                                if((V[i].state/4)%2)
                                    V[i].no=3;
                                else V[i].no=7;
                            }
                        }
                        else if(V[i].die_mode==1)
                        {
                            target_x=360;
                            target_y=420;
                            flee_r=0,flee_l=0,flee_u=0,flee_d=0;
                            V[i]._x=(V[i].px-(screenHeight-mazeheight)/2)/boxLength;
                            V[i]._y=(V[i].py-(screenHeight-mazeheight)/2)/boxLength;
                            if(ara[maze][level][V[i]._y][V[i]._x+1]!=1&&V[i].py%boxLength==0&&target_x>V[i].px&&V[i].dir!='l')
                            {
                                flee_u=0;
                                flee_d=0;
                                flee_r=1;
                                flee_l=0;
                            }
                            else if(V[i].dir!='r'&&target_x<V[i].px&&ara[maze][level][(V[i].py-(screenHeight-mazeheight)/2)/boxLength][(V[i].px-1-(screenHeight-mazeheight)/2)/boxLength]!=1&&V[i].py%boxLength==0)
                            {
                                flee_u=0;
                                flee_d=0;
                                flee_r=0;
                                flee_l=1;
                            }
                            else if(V[i].dir!='d'&&target_y>V[i].py&&ara[maze][level][((V[i].py-(screenHeight-mazeheight)/2)/boxLength)+1][(V[i].px-(screenHeight-mazeheight)/2)/boxLength]!=1&&V[i].px%boxLength==0)
                            {

                                flee_u=1;
                                flee_d=0;
                                flee_r=0;
                                flee_l=0;
                            }
                            else if(V[i].dir!='u'&&target_y<V[i].py&&ara[maze][level][(V[i].py-1-(screenHeight-mazeheight)/2)/boxLength][(V[i].px-(screenHeight-mazeheight)/2)/boxLength]!=1&&V[i].px%boxLength==0)
                            {
                                flee_u=0;
                                flee_d=1;
                                flee_r=0;
                                flee_l=0;

                            }
                            else if(ara[maze][level][V[i]._y][V[i]._x+1]!=1&&V[i].dir!='l'&&V[i].py%boxLength==0)
                            {
                                flee_r=1;
                            }
                            else if(ara[maze][level][(V[i].py-(screenHeight-mazeheight)/2)/boxLength][(V[i].px-1-(screenHeight-mazeheight)/2)/boxLength]!=1&&V[i].dir!='r'&&V[i].py%boxLength==0)
                            {
                                flee_l=1;
                            }
                            else if(ara[maze][level][((V[i].py-(screenHeight-mazeheight)/2)/boxLength)+1][(V[i].px-(screenHeight-mazeheight)/2)/boxLength]!=1&&V[i].dir!='d'&&V[i].px%boxLength==0)
                            {
                                flee_u=1;
                            }
                            else if(ara[maze][level][(V[i].py-1-(screenHeight-mazeheight)/2)/boxLength][(V[i].px-(screenHeight-mazeheight)/2)/boxLength]!=1&&V[i].dir!='u'&&V[i].px%boxLength==0)
                            {
                                flee_d=1;
                            }
                            if(flee_r)
                            {
                                V[i].no=0;
                                V[i].dir='r';
                                if(V[i].px%5) V[i].px+=(5-V[i].px%5);
                                else
                                    V[i].px+=5;
                            }
                            if(flee_l)
                            {
                                V[i].no=2;
                                V[i].dir='l';
                                if(V[i].px%5) V[i].px-=(V[i].px%5);
                                else
                                    V[i].px-=5;
                            }
                            if(flee_u)
                            {
                                V[i].no=1;
                                V[i].dir='u';
                                if(V[i].py%5) V[i].py+=(5-V[i].py%5);
                                else
                                    V[i].py+=5;
                            }
                            if(flee_d)
                            {
                                V[i].no=3;
                                V[i].dir='d';
                                if(V[i].py%5) V[i].py-=(V[i].py%5);
                                else
                                    V[i].py-=5;
                            }
                        }
                        if(V[i].px+boxLength>570+(screenHeight-mazeheight)/2)
                        {
                            V[i].px=(screenHeight-mazeheight)/2;
                            if(V[i].state>=1000) V[i].state=0;
                            V[i].state++;
                            if(V[i].die_mode==1) V[i].no=0;
                            else if(V[i].die_mode!=1) {
                                if((V[i].state/4)%2) V[i].no=0;
                                else V[i].no=4;
                            }
                        }
                        else if(V[i].px<(screenHeight-mazeheight)/2)
                        {
                            //V[i].initial=0;
                            //V[i].dir='k';
                            V[i].px=570-boxLength+(screenHeight-mazeheight)/2;
                            if(V[i].state>=1000) V[i].state=0;
                            V[i].state++;
                            if(V[i].die_mode==1) V[i].no=2;
                            else if(V[i].die_mode!=1){
                                if((V[i].state/4)%2)  V[i].no=2;
                                else V[i].no=6;
                            }
                        }
                        //cout<<V[i].px<<" "<<V[i].py<<" "<<ara[level][(V[i].py-90+30)/30][(V[i].px-90)/30]<<endl;
                        //cout<<g_l<<g_r<<g_u<<g_d<<endl;

                    }
                }
                if(frightened_mode)
                {
                    call2++;
                    for(int i=0;i<4;i++)
                    {
                            if(i==0&&(V[i].die_mode==0||V[i].die_mode==2)&&V[i].ghost_mode==0)
                            {
                                target_x=pacc.pox;    target_y=pacc.poy;
                                V[i].a[11][9]=1;
                            }
                            if(i==1&&(V[i].die_mode==0||V[i].die_mode==2)&&V[i].ghost_mode==0)
                            {

                                V[i].a[11][9]=1;
                                if(pacc.right)
                                {
                                    target_x=pacc.pox+120;    target_y=pacc.poy;
                                }
                                else if(pacc.left)
                                {
                                    target_x=pacc.pox-120;    target_y=pacc.poy;
                                }
                                else if(pacc.up)
                                {
                                    target_x=pacc.pox;    target_y=pacc.poy+120;
                                }
                                else if(pacc.down)
                                {
                                    target_x=pacc.pox;    target_y=pacc.poy-120;
                                }
                                else
                                {
                                    target_x=pacc.pox+60;    target_y=pacc.poy+60;
                                }
                            }
                            if(i==2&&(V[i].die_mode==0||V[i].die_mode==2)&&V[i].ghost_mode==0)
                            {
                                V[i].a[11][9]=1;
                                target_x=(2*pacc.pox-V[i].px);
                                target_y=(2*pacc.poy-V[i].py);
                                if(target_x<(screenHeight-mazeheight)/2)
                                {
                                    target_x=(screenHeight-mazeheight)/2;
                                }
                                if(target_x>540+(screenHeight-mazeheight)/2)
                                {
                                    target_x=540+(screenHeight-mazeheight)/2;
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
                                V[i].a[11][9]=1;
                                if(pacc.right)
                                {
                                    target_x=pacc.pox-120;    target_y=pacc.poy;
                                }
                                else if(pacc.left)
                                {
                                    target_x=pacc.pox+120;    target_y=pacc.poy;
                                }
                                else if(pacc.up)
                                {
                                    target_x=pacc.pox;    target_y=pacc.poy-120;
                                }
                                else if(pacc.down)
                                {
                                    target_x=pacc.pox;    target_y=pacc.poy+120;
                                }
                                else
                                {
                                    target_x=pacc.pox+60;    target_y=pacc.poy+60;
                                }
                            }
                            maxi=0;
                            maxi1=0,maxi2=0,maxi3=0,maxi4=0;
                            g_d=0;g_l=0,g_r=0,g_u=0;
                            //for right move
                            V[i]._x=(V[i].px-(screenHeight-mazeheight)/2)/boxLength;
                            V[i]._y=(V[i].py-(screenHeight-mazeheight)/2)/boxLength;
                            if(ara[maze][level][V[i]._y][V[i]._x+1]!=1&&V[i].py%boxLength==0)
                            {
                                maxi1=((V[i]._x+1)*boxLength-target_x)*((V[i]._x+1)*boxLength-target_x)+((V[i]._y)*boxLength-target_y)*((V[i]._y)*boxLength-target_y);
                            }
                            //for left move
                            V[i]._x=(V[i].px-1-(screenHeight-mazeheight)/2)/boxLength;
                            V[i]._y=(V[i].py-(screenHeight-mazeheight)/2)/boxLength;
                            if(ara[maze][level][V[i]._y][V[i]._x]!=1&&V[i].py%boxLength==0)
                            {
                                maxi2=((V[i]._x)*boxLength-target_x)*((V[i]._x)*boxLength-target_x)+((V[i]._y)*boxLength-target_y)*((V[i]._y)*boxLength-target_y);
                            }
                            //for up move
                            V[i]._x=(V[i].px-(screenHeight-mazeheight)/2)/boxLength;
                            V[i]._y=(V[i].py-(screenHeight-mazeheight)/2)/boxLength;
                            if(ara[maze][level][V[i]._y+1][V[i]._x]!=1&&V[i].px%boxLength==0)
                            {
                                maxi3=((V[i]._x)*boxLength-target_x)*((V[i]._x)*boxLength-target_x)+((V[i]._y+1)*boxLength-target_y)*((V[i]._y+1)*boxLength-target_y);
                            }
                            //for down move
                            V[i]._x=(V[i].px-(screenHeight-mazeheight)/2)/boxLength;
                            V[i]._y=(V[i].py-1-(screenHeight-mazeheight)/2)/boxLength;
                            if(ara[maze][level][V[i]._y][V[i]._x]!=1&&V[i].px%boxLength==0)
                            {
                                maxi4=((V[i]._x)*boxLength-target_x)*((V[i]._x)*boxLength-target_x)+(V[i]._y*boxLength-target_y)*((V[i]._y)*boxLength-target_y);
                            }
                            if(ara[maze][level][V[i]._y][V[i]._x]!=1&&V[i]._x==9&&V[i]._y==11&&V[i].px%boxLength==0)
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
                                if(ara[maze][level][V[i]._y][V[i]._x+1]!=1&&V[i].py%boxLength==0){
                                    V[i].dir='r';
                                    if(V[i].state>=1000)   V[i].state=0;
                                    V[i].state++;
                                    V[i].px++;
                                }
                            }
                            else if(g_l&&V[i].ghost_mode!=1&&V[i].die_mode!=1)
                            {
                                V[i]._x=(V[i].px-1-(screenHeight-mazeheight)/2)/boxLength;
                                V[i]._y=(V[i].py-(screenHeight-mazeheight)/2)/boxLength;
                                if(ara[maze][level][V[i]._y][V[i]._x]!=1&&V[i].py%boxLength==0){
                                    V[i].dir='l';
                                    if(V[i].state>=1000)    V[i].state=0;
                                    V[i].state++;
                                    V[i].px--;
                                }
                            }
                            else if(g_u&&V[i].ghost_mode!=1&&V[i].die_mode!=1)
                            {
                                V[i]._x=(V[i].px-(screenHeight-mazeheight)/2)/boxLength;
                                V[i]._y=(V[i].py-(screenHeight-mazeheight)/2)/boxLength;
                                if(ara[maze][level][V[i]._y+1][V[i]._x]!=1&&V[i].px%boxLength==0){
                                    V[i].dir='u';
                                    if(V[i].state>=1000)  V[i].state=0;
                                    V[i].state++;
                                    V[i].py++;

                                }
                            }
                            else if(g_d&&V[i].ghost_mode!=1&&V[i].die_mode!=1)
                            {
                                V[i]._x=(V[i].px-(screenHeight-mazeheight)/2)/boxLength;
                                V[i]._y=(V[i].py-1-(screenHeight-mazeheight)/2)/boxLength;
                                if(ara[maze][level][V[i]._y][V[i]._x]!=1&&V[i].px%boxLength==0){
                                    V[i].dir='d';
                                    if(V[i].state>=1000) V[i].state=0;
                                    V[i].state++;
                                    V[i].py--;
                                }
                            }
                            if(V[i].px+boxLength>570+(screenHeight-mazeheight)/2&&V[i].ghost_mode!=1&&V[i].die_mode!=1)
                            {
                                V[i].px=(screenHeight-mazeheight)/2;
                                if(V[i].state>=1000)  V[i].state=0;
                                V[i].state++;
                                //V[i].initial=0;
                                //V[i].dir='k';
                            }
                            else if(V[i].px<(screenHeight-mazeheight)/2&&V[i].ghost_mode!=1&&V[i].die_mode!=1)
                            {
                                //V[i].initial=0;
                                V[i].px=570-boxLength+(screenHeight-mazeheight)/2;
                                if(V[i].state>=1000)  V[i].state=0;
                                V[i].state++;
                                //V[i].dir='k';
                            }
                        }
                }
            }
            if(fire_mode&&PAUSE==0)
            {
                if(fire_l)
                {
                    if(fire_x%3) fire_x-=(fire_x%3);
                    else fire_x-=3;
                }
                if(fire_r)
                {
                    if(fire_x%3) fire_x+=(3-fire_x%3);

                    else fire_x+=3;
                }
                if(fire_u)
                {
                    if(fire_y%3) fire_y+=(3-fire_y%3);
                    else fire_y+=3;
                }
                if(fire_d)
                {
                    if(fire_y%3) fire_y-=(fire_y%3);
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
                        V[idx].a[11][9]=0;
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
                    V[idx].a[11][9]=0;
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
