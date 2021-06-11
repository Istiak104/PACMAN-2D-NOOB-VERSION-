#define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"
#include "GameEngine.h"

Vector AdditionalForce = Vector(10, 0);

class Track{
    std::vector <Point> trackPoint;
    std::vector <LineSegment> trackLine;
public:
    const int WIDTH_PER_BLOCK = 100;

    Track(std::vector <Point> in)
    {
        trackPoint = in;

        for(int i=1; i<trackPoint.size(); i++)
        {
            trackLine.push_back(LineSegment(trackPoint[i-1], trackPoint[i]));
        }
    }

    LineSegment getLine(int index)
    {
        return trackLine[index];
    }

    Point getInitialPoint(int index)
    {
        return trackPoint[index];
    }

    void insert(Point n)
    {
        trackPoint.push_back(n);
        trackLine.push_back(LineSegment(trackPoint[trackPoint.size()-2], trackPoint[trackPoint.size()-1]));
    }

    void draw(int CamX = camX)
    {
        for(int i=0; i<trackLine.size(); i++) trackLine[i].draw(CamX);
    }

    int getIndex(double x)
    {
        return int(x/WIDTH_PER_BLOCK);
    }
};

Track gameTrack = Track({Point(0, 10), Point(100, 10)});

class Wheel{
    double radius = 10.0;
public:
    Motion movement = Motion(Vector(50.0, HEIGHT/4), 10);

    Vector AdditionalForce = Vector(10, 0);

    Wheel()
    {
        movement.setVelocity(Vector(120, 0));
        movement.setEngineForces(0);
        movement.setOnSurface(0, -PI/4);
    }

    int getLowIndexOfTrack()
    {
        return gameTrack.getIndex(movement.getMovementX()-radius);
    }

    int getHighIndexOfTrack()
    {
        return gameTrack.getIndex(movement.getMovementX()+radius);
    }

    int setCollusionStatus()
    {
        int lo = getLowIndexOfTrack();
        int hi = getHighIndexOfTrack();

        if (lo==hi) /// Check a single Line
        {
            movement.collusionLine(gameTrack.getLine(lo), radius);
        }
        else /// between an intersection
        {
            movement.collusion2Line(gameTrack.getLine(lo), gameTrack.getLine(hi), radius);
        }
    }

    void draw(double CamX = camX) const
    {
        iCircle(movement.getMovementX()-CamX, movement.getMovementY(), radius);
    }
};



class Bike
{
    double bikeAngle = 0; /// With X-Axis
    const double wheelDistance = 25;

public:
    Wheel backWheel, frontWheel;
    LineSegment connector = LineSegment(backWheel.movement.getCenter(), frontWheel.movement.getCenter());


    void fixFrontWheel()
    {
        Point newPoint;

        connector = LineSegment(backWheel.movement.getCenter(), frontWheel.movement.getCenter());
        bikeAngle = connector.getSlopeAngle();

        newPoint.setRTheta(wheelDistance, bikeAngle, backWheel.movement.getCenter());
        frontWheel.movement.setCenter(newPoint);

        connector = LineSegment(backWheel.movement.getCenter(), frontWheel.movement.getCenter());
    }

    void fixCameraPosition()
    {
        camX = backWheel.movement.getMovementX()-WIDTH/2;
    }

    void startMovement()
    {
        backWheel.movement.activate();
        backWheel.setCollusionStatus();

        frontWheel.movement.activate();
        frontWheel.setCollusionStatus();
    }

    void draw()
    {
        backWheel.draw();
        frontWheel.draw();
        connector.draw(camX);
    }

    void log()
    {
        printf("%.2fi + %.2fj | %.2f %.2f\n", frontWheel.movement.cf.getX()/FORCE_FACTOR, backWheel.movement.cf.getY()/FORCE_FACTOR, frontWheel.movement.getMovementX(), frontWheel.movement.getMovementY());
    }

} myBike;

char converted_1[20], converted_2[20];

void iDraw() {
	iClear();
	gameTrack.draw();
	sprintf(converted_1, "Engine: %.1f", myBike.backWheel.movement.getEngineForce()/FORCE_FACTOR);
	sprintf(converted_2, "Friction: %.1f", myBike.backWheel.movement.getFrictionForce()/FORCE_FACTOR);
    iText(100, 100, converted_1);
    iText(100, 80, converted_2);
    myBike.draw();
}

void iMouseMove(int mx, int my) {

}

void iMouse(int button, int state, int mx, int my) {
    if(button == GLUT_LEFT && state == GLUT_DOWN)
    {

    }
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
    if(key=='a'){
        myBike.backWheel.movement.addEngineForce(-AdditionalForce.getValue());
    }
    if(key=='s'){
        myBike.backWheel.movement.addForces(Vector(0, -10));
    }
    if(key=='d'){
        myBike.backWheel.movement.addEngineForce(AdditionalForce.getValue());
    }
    if(key=='w'){
        myBike.backWheel.movement.addForces(Vector(0, 10));
    }
    if(key=='p')
    {
        iPauseTimer(0);
    }
    if(key=='o')
    {
        iResumeTimer(0);
    }
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
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	if(key == GLUT_KEY_RIGHT){

	}
	if(key == GLUT_KEY_LEFT){

	}
	//place your codes for other keys here
}


void varInitialize()
{
    srand(clock()%1000);

    myBike.fixFrontWheel();
    myBike.fixCameraPosition();

    for(int i=2; i<500; i++)
        gameTrack.insert(Point(gameTrack.WIDTH_PER_BLOCK*i, rand()%int(HEIGHT/2-20)+10));
}

void Frame()
{
    myBike.fixFrontWheel();
    myBike.startMovement();
    myBike.fixCameraPosition();
    myBike.fixFrontWheel();

    myBike.log();

    //printf("POSITION: %f %f\n", myWheel.movement.getMovementX(), myWheel.movement.getMovementY());
    //camX = myWheel.movement.getMovementX()-WIDTH/2;
}

int main() {
	//place your own initialization codes here.
	varInitialize();
	//myWheel.movement.getCenter();
	iSetTimer(SecondsPerFrame*1000, Frame);
	iInitialize(WIDTH, HEIGHT, "Gravity");
	return 0;
}
