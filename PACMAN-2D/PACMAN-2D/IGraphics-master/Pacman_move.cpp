#include<bits/stdc++.h>
#include<math.h>
#include<windows.h>
#include"Initial_State.cpp"


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
        if(pac>2)   pac=0;
    }
}



void pacman_move_right(){
    if(pacc.right)
    {
        pacc.xx=(pacc.pox-(screenHeight-mazeheight)/2)/boxLength;
        pacc.yy=(pacc.poy-(screenHeight-mazeheight)/2)/boxLength;
        if(ara[maze][level][pacc.yy][pacc.xx+1]!=1&&pacc.poy%boxLength==0)
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
                if(ara[maze][level][pacc.yy][pacc.xx+1]==3)
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
                if(ara[maze][level][pacc.yy][pacc.xx+1]==5)
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
                if(ara[maze][level][pacc.yy][pacc.xx+1]==6)
                {
                    score+=30;
                    pause_mode_for_ghosts=1;
                    music_2=1;
                    music();
                }
                if(ara[maze][level][pacc.yy][pacc.xx+1]==7)
                {
                    score+=30;
                    hide_mode=1;
                    music_2=1;
                    music();
                }
                ara[maze][level][pacc.yy][pacc.xx+1]=2;
            }

        }
        else
        {
            static_pacmouth=1;
            pacc.right=0; pac=2;

        }
    }
}



void pacman_move_up(){
    if(pacc.up)
    {
        pacc.xx=(pacc.pox-(screenHeight-mazeheight)/2)/boxLength;
        pacc.yy=(pacc.poy-(screenHeight-mazeheight)/2)/boxLength;
        if(ara[maze][level][pacc.yy+1][pacc.xx]!=1&&pacc.pox%boxLength==0)
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
                if(ara[maze][level][pacc.yy+1][pacc.xx]==0)
                {
                    score+=10;
                }
                if(ara[maze][level][pacc.yy+1][pacc.xx]==3)
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
                if(ara[maze][level][pacc.yy+1][pacc.xx]==5)
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
                if(ara[maze][level][pacc.yy+1][pacc.xx]==6)
                {
                    score+=30; pause_mode_for_ghosts=1;
                    music_2=1; music();
                }
                if(ara[maze][level][pacc.yy+1][pacc.xx]==7)
                {
                    score+=30; hide_mode=1;
                    music_2=1; music();
                }
                ara[maze][level][pacc.yy+1][pacc.xx]=2;
            }

        }
        else
        {
            static_pacmouth=1;
            pacc.up=0; pac=2;

        }
    }
}




void pacman_move_down(){
    if(pacc.down){
        pacc.xx=(pacc.pox-(screenHeight-mazeheight)/2)/boxLength;
        pacc.yy=(pacc.poy-1-(screenHeight-mazeheight)/2)/boxLength;
        if(ara[maze][level][pacc.yy][pacc.xx]!=1&&pacc.pox%boxLength==0)
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
                if(ara[maze][level][pacc.yy][pacc.xx]==0)
                {
                    score+=10;
                }
                if(ara[maze][level][pacc.yy][pacc.xx]==3)
                {
                    score+=30;
                    music_3=1; music();
                    frightened_mode=1;
                    if(V[0].die_mode!=1) V[0].ghost_mode=0;
                    if(V[1].die_mode!=1) V[1].ghost_mode=0;
                    if(V[2].die_mode!=1) V[2].ghost_mode=0;
                    if(V[3].die_mode!=1) V[3].ghost_mode=0;
                    for(int idx=0;idx<4;idx++)
                        V[idx].initial=0;
                }
                if(ara[maze][level][pacc.yy][pacc.xx]==5)
                {
                    score+=30; speed_mode=1;
                    music_2=1; music();
                    if(pacc.poy%3)
                        pacc.poy+=pacc.poy-pacc.poy%3;
                }
                if(ara[maze][level][pacc.yy][pacc.xx]==6)
                {
                    score+=30; music_2=1;
                    music(); pause_mode_for_ghosts=1;
                }
                if(ara[maze][level][pacc.yy][pacc.xx]==7)
                {
                    score+=30; hide_mode=1;
                    music_2=1; music();
                }
                ara[maze][level][pacc.yy][pacc.xx]=2;
            }
        }
        else
        {
            static_pacmouth=1;
            pac=2; pacc.down=0;
        }
    }
}




void pacman_move_left(){
    if(pacc.left)
    {
        pacc.xx=(pacc.pox-1-(screenHeight-mazeheight)/2)/boxLength;
        pacc.yy=(pacc.poy-(screenHeight-mazeheight)/2)/boxLength;
        if(ara[maze][level][pacc.yy][pacc.xx]!=1&&pacc.poy%boxLength==0)
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
                if(ara[maze][level][pacc.yy][pacc.xx]==0)
                {
                    score+=10;
                }
                if(ara[maze][level][pacc.yy][pacc.xx]==3)
                {
                    score+=30;
                    music_3=1; music();
                    frightened_mode=1;
                    if(V[0].die_mode!=1) V[0].ghost_mode=0;
                    if(V[1].die_mode!=1) V[1].ghost_mode=0;
                    if(V[2].die_mode!=1) V[2].ghost_mode=0;
                    if(V[3].die_mode!=1) V[3].ghost_mode=0;
                    for(int idx=0;idx<4;idx++)
                        V[idx].initial=0;
                }
                if(ara[maze][level][pacc.yy][pacc.xx]==5)
                {
                    score+=30; speed_mode=1;
                    music_2=1; music();
                    if(pacc.pox%3)
                        pacc.pox-=pacc.pox-pacc.pox%3;
                }
                if(ara[maze][level][pacc.yy][pacc.xx]==6)
                {
                    score+=30;
                    music_2=1; music();
                    pause_mode_for_ghosts=1;
                }
                if(ara[maze][level][pacc.yy][pacc.xx]==7)
                {
                    score+=30;
		    music_2=1; music();
                    hide_mode=1;
                }
                ara[maze][level][pacc.yy][pacc.xx]=2;
            }

        }
        else
        {
            static_pacmouth=1; pac=2;
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
                    if(pacc.xx==9&&pacc.yy==11)
                    {
                        keey[1]=keey[0]; pac=2;
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
                    if(ara[maze][level][pacc.yy+1][pacc.xx]!=1&&pacc.pox%boxLength==0)
                    {
                        keey[0]=keey[1];
                    }
                    else
                    {
                        pac_no=2;
                        pacman_move_right();
                        if(pacc.right==0) keey[0]=0;
                    }
                }
                if(keey[0]==2&&keey[1]==1)
                {
                    pacc.xx=(pacc.pox-(screenHeight-mazeheight)/2)/boxLength;
                    pacc.yy=(pacc.poy-(screenHeight-mazeheight)/2)/boxLength;
                    if(ara[maze][level][pacc.yy][pacc.xx+1]!=1&&pacc.poy%boxLength==0) keey[0]=keey[1];
                    else
                    {
                        pac_no=3;
                        pacman_move_up();
                        if(pacc.up==0) keey[0]=0;
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
                    if(ara[maze][level][pacc.yy][pacc.xx]!=1&&pacc.pox%boxLength==0)  keey[0]=keey[1];
                    else
                    {
                        pac_no=2;
                        pacman_move_right();
                        if(pacc.right==0) keey[0]=0;
                    }
                }
                if(keey[0]==4&&keey[1]==1)
                {
                    pacc.xx=(pacc.pox-(screenHeight-mazeheight)/2)/boxLength;
                    pacc.yy=(pacc.poy-(screenHeight-mazeheight)/2)/boxLength;
                    if(ara[maze][level][pacc.yy][pacc.xx+1]!=1&&pacc.poy%boxLength==0) keey[0]=keey[1];
                    else
                    {
                        pacc.xx=(pacc.pox-(screenHeight-mazeheight)/2)/boxLength;
                        pacc.yy=(pacc.poy-1-(screenHeight-mazeheight)/2)/boxLength;
                        if(pacc.xx==9&&pacc.yy==11)
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
                    if(ara[maze][level][pacc.yy][pacc.xx]!=1&&pacc.poy%boxLength==0) keey[0]=keey[1];
                    else
                    {
                        pac_no=3;
                        pacman_move_up();
                        if(pacc.up==0) keey[0]=0;
                    }
                }
                if(keey[0]==3&&keey[1]==2)
                {
                    pacc.xx=(pacc.pox-(screenHeight-mazeheight)/2)/boxLength;
                    pacc.yy=(pacc.poy-(screenHeight-mazeheight)/2)/boxLength;
                    if(ara[maze][level][pacc.yy+1][pacc.xx]!=1&&pacc.pox%boxLength==0) keey[0]=keey[1];
                    else
                    {
                        pac_no=0;
                        pacman_move_left();
                        if(pacc.left==0) keey[0]=0;
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
                    if(ara[maze][level][pacc.yy][pacc.xx]!=1&&pacc.poy%boxLength==0) keey[0]=keey[1];
                    else
                    {
                        pacc.xx=(pacc.pox-(screenHeight-mazeheight)/2)/boxLength;
                        pacc.yy=(pacc.poy-1-(screenHeight-mazeheight)/2)/boxLength;
                        if(pacc.xx==9&&pacc.yy==11)
                        {
                            keey[1]=keey[0];
                            pac=2;
                        }
                        else{
                            pac_no=1;
                            pacman_move_down();
                            if(pacc.down==0) keey[0]=0;
                        }
                    }
                }
                if(keey[0]==3&&keey[1]==4)
                {
                    pacc.xx=(pacc.pox-(screenHeight-mazeheight)/2)/boxLength;
                    pacc.yy=(pacc.poy-1-(screenHeight-mazeheight)/2)/boxLength;
                    if(ara[maze][level][pacc.yy][pacc.xx]!=1&&pacc.pox%boxLength==0) keey[0]=keey[1];
                    else
                    {
                        pac_no=0;
                        pacman_move_left();
                        if(pacc.left==0)  keey[0]=0;
                    }
                }
                if(call3>500) speed_mode=0;
                if(call4>500) pause_mode_for_ghosts=0;
                if(call5>500) hide_mode=0;

            }
        }
    }


}
