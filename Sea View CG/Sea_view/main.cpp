#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;

float moveX = 0.0f; // boat
float cloudX = 0.0f;
float cloudX2 = 0.5f;   // start from different position

float sunX = -0.8f;
float sunY = -0.2f;

bool isNight = false;
int scene = 1;




// for scene 2

//for boat

float boat2X = 0.0f; //boat1
bool boatMove = false;


float boat3X = 0.5f; //boat2
bool boat2Move = false;

//for night/day
bool scene2Night = false;

// windmill variable
float windmillAngle = 0.0f;

//mouse variable
float boatSpeed = 0.001f;
float cloudSpeed = 0.0015f;

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // pressing 1, scene 1 will shift
    if(scene == 1)
    {


    //sky start from here

    if(isNight)
        glColor3f(0.02f, 0.02f, 0.15f); // dark blue night
    else
        glColor3f(0.4f, 0.7f, 1.0f); // day sky

    glBegin(GL_QUADS);
        glVertex2f(-1.0f,  1.0f);
        glVertex2f( 1.0f,  1.0f);
        glVertex2f( 1.0f,  0.1f);
        glVertex2f(-1.0f,  0.1f);
    glEnd();





    // sun or moon
    glPushMatrix();

    // moving position
    glTranslatef(sunX, sunY, 0.0f);

    float r = 0.12f;

    // day will appear sun
    if(!isNight)
    {
        glColor3f(1.0f, 1.0f, 0.0f);

        glBegin(GL_POLYGON);
        for(int i=0; i<360; i++)
        {
            float A = i * 3.1416f / 180.0f;
            glVertex2f(r*cos(A), r*sin(A));
        }
        glEnd();
    }

    // here, night will appear moon
    else
    {
        // white circle
        glColor3f(1,1,1);

        glBegin(GL_POLYGON);
        for(int i=0; i<360; i++)
        {
            float A = i * 3.1416f / 180.0f;
            glVertex2f(r*cos(A), r*sin(A));
        }
        glEnd();

        // cut for crescent moon
        glColor3f(0.02f, 0.02f, 0.15f);

        glBegin(GL_POLYGON);
        for(int i=0; i<360; i++)
        {
            float A = i * 3.1416f / 180.0f;

            glVertex2f(
                0.05f + r*cos(A),
                0.02f + r*sin(A)
            );
        }
        glEnd();
    }

    glPopMatrix();



    //cloud that moving left
    glPushMatrix();
    glTranslatef(cloudX, 0.6f, 0.0f); // y = 0.6 (inside sky)

    glColor3f(1.0f, 1.0f, 1.0f); // white

    // circle 1
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        float A = i * 3.1416f / 180.0f;
        glVertex2f(0.0f + 0.08f * cos(A), 0.0f + 0.08f * sin(A));
    }
    glEnd();

    // circle 2
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        float A = i * 3.1416f / 180.0f;
        glVertex2f(0.10f + 0.10f * cos(A), 0.02f + 0.10f * sin(A));
    }
    glEnd();

    // circle 3
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        float A = i * 3.1416f / 180.0f;
        glVertex2f(0.22f + 0.08f * cos(A), 0.0f + 0.08f * sin(A));
    }
    glEnd();

    glPopMatrix();




    cloudX -= 0.0015f; // move LEFT

    if(cloudX < -1.3f)
        cloudX = 1.3f; // reset from right




        //cloud 2
    glPushMatrix();
    glTranslatef(cloudX2, 0.75f, 0.0f); // slightly higher than cloud 1

    glColor3f(1.0f, 1.0f, 1.0f);

    // circle 1
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        float A = i * 3.1416f / 180.0f;
        glVertex2f(0.0f + 0.07f * cos(A), 0.0f + 0.07f * sin(A));
    }
    glEnd();

    // circle 2
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        float A = i * 3.1416f / 180.0f;
        glVertex2f(0.09f + 0.09f * cos(A), 0.02f + 0.09f * sin(A));
    }
    glEnd();

    // circle 3
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        float A = i * 3.1416f / 180.0f;
        glVertex2f(0.18f + 0.07f * cos(A), 0.0f + 0.07f * sin(A));
    }
    glEnd();

    glPopMatrix();


    // cloud 3. stable cloud

    glPushMatrix();
    glTranslatef(-0.2f, 0.8f, 0.0f); // fixed position (you can change)

    glColor3f(1.0f, 1.0f, 1.0f);

    // circle 1
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        float A = i * 3.1416f / 180.0f;
        glVertex2f(0.0f + 0.06f * cos(A), 0.0f + 0.06f * sin(A));
    }
    glEnd();

    // circle 2
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        float A = i * 3.1416f / 180.0f;
        glVertex2f(0.08f + 0.08f * cos(A), 0.02f + 0.08f * sin(A));
    }
    glEnd();

    // circle 3
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        float A = i * 3.1416f / 180.0f;
        glVertex2f(0.16f + 0.06f * cos(A), 0.0f + 0.06f * sin(A));
    }
    glEnd();

    glPopMatrix();





        // sea
    if(isNight)
        glColor3f(0.02f, 0.08f, 0.15f); // dark night water
    else
        glColor3f(0.0f, 0.5f, 0.8f); // day water

    glBegin(GL_QUADS);
        glVertex2f(-1.0f,  0.1f);
        glVertex2f( 1.0f,  0.1f);
        glVertex2f( 1.0f, -0.4f);
        glVertex2f(-1.0f, -0.4f);
    glEnd();






    // Yacht start from here
    glPushMatrix();
    glTranslatef(moveX, 0.17f, 0.0f);

    // main body
    if(isNight)
        glColor3f(0.08f, 0.08f, 0.08f); // black night yacht
    else
        glColor3f(1.0f, 1.0f, 1.0f); // day white

    glBegin(GL_POLYGON);
        glVertex2f(-0.55f,  0.02f);
        glVertex2f( 0.55f,  0.02f);
        glVertex2f( 0.65f, -0.25f);
        glVertex2f(-0.35f, -0.25f);
        glVertex2f(-0.48f, -0.12f);
    glEnd();


    //lower body of yacht
    if(isNight)
        glColor3f(0.12f, 0.12f, 0.12f);
    else
        glColor3f(0.85f, 0.95f, 0.92f);

    glBegin(GL_POLYGON);
        glVertex2f(-0.48f, -0.12f);
        glVertex2f(-0.35f, -0.25f);
        glVertex2f( 0.65f, -0.25f);
        glVertex2f( 0.60f, -0.20f);
        glVertex2f( 0.10f, -0.18f);
        glVertex2f(-0.20f, -0.14f);
    glEnd();


    // cabin window
    if(isNight)
        glColor3f(1.0f, 1.0f, 0.0f); // yellow light
    else
        glColor3f(0.7f, 0.95f, 1.0f); // blue glass

    glBegin(GL_POLYGON);
        glVertex2f(-0.02f, 0.02f);
        glVertex2f( 0.40f, 0.02f);
        glVertex2f( 0.45f, 0.20f);
        glVertex2f( 0.12f, 0.24f);
    glEnd();


    // cabin roof
    if(isNight)
        glColor3f(0.05f, 0.05f, 0.05f);
    else
        glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_POLYGON);
        glVertex2f(0.12f, 0.24f);
        glVertex2f(0.45f, 0.20f);
        glVertex2f(0.47f, 0.28f);
        glVertex2f(0.18f, 0.31f);
    glEnd();




    // window 1
    if(isNight)
        glColor3f(1.0f, 1.0f, 0.0f); // yellow light
    else
        glColor3f(0.7f, 0.95f, 1.0f); // blue glass

    glBegin(GL_QUADS);
        glVertex2f(0.00f, -0.14f);
        glVertex2f(0.08f, -0.14f);
        glVertex2f(0.08f, -0.08f);
        glVertex2f(0.00f, -0.08f);
    glEnd();



    // window 2
    if(isNight)
        glColor3f(1.0f, 1.0f, 0.0f); // yellow light
    else
        glColor3f(0.7f, 0.95f, 1.0f); // blue glass

    glBegin(GL_QUADS);
        glVertex2f(0.18f, -0.14f);
        glVertex2f(0.26f, -0.14f);
        glVertex2f(0.26f, -0.08f);
        glVertex2f(0.18f, -0.08f);
    glEnd();


    // window3
    if(isNight)
        glColor3f(1.0f, 1.0f, 0.0f); // yellow light
    else
        glColor3f(0.7f, 0.95f, 1.0f); // blue glass

    glBegin(GL_QUADS);
        glVertex2f(0.36f, -0.14f);
        glVertex2f(0.44f, -0.14f);
        glVertex2f(0.44f, -0.08f);
        glVertex2f(0.36f, -0.08f);
    glEnd();


    // black color stripe
    glColor3f(0.1f, 0.1f, 0.1f);

    glBegin(GL_QUADS);
        glVertex2f(-0.30f, -0.03f);
        glVertex2f( 0.50f, -0.03f);
        glVertex2f( 0.48f, -0.06f);
        glVertex2f(-0.28f, -0.06f);
    glEnd();

    glPopMatrix();







    //sand start from here
    if(isNight)
        glColor3f(0.25f, 0.25f, 0.25f); // dark sand
    else
        glColor3f(0.94f, 0.86f, 0.51f); // day sand

    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.4f);
        glVertex2f( 1.0f, -0.4f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f(-1.0f, -1.0f);
    glEnd();

    //Umbrella start from here
    // umbrella pole
    glColor3f(0.6f, 0.4f, 0.2f);
    glLineWidth(4);
    glBegin(GL_LINES);
        glVertex2f(-0.7f, -0.9f);   // bottom
        glVertex2f(-0.7f,  0.15f);  // top
    glEnd();




    // Segment 1
    glColor3f(0.9f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.7f, 0.15f);
        glVertex2f(-1.18f, -0.18f);
        glVertex2f(-0.98f, -0.14f);
    glEnd();

    // Segment 2
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
        glVertex2f(-0.7f, 0.15f);
        glVertex2f(-0.98f, -0.14f);
        glVertex2f(-0.88f, -0.13f);
    glEnd();

    // Segment 3
    glColor3f(0.9f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.7f, 0.15f);
        glVertex2f(-0.88f, -0.13f);
        glVertex2f(-0.75f, -0.12f);
    glEnd();

    // Segment 4
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
        glVertex2f(-0.7f, 0.15f);
        glVertex2f(-0.75f, -0.12f);
        glVertex2f(-0.60f, -0.13f);
    glEnd();

    // Segment 5
    glColor3f(0.9f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.7f, 0.15f);
        glVertex2f(-0.60f, -0.13f);
        glVertex2f(-0.45f, -0.15f);
    glEnd();

    // Segment 6
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
        glVertex2f(-0.7f, 0.15f);
        glVertex2f(-0.45f, -0.15f);
        glVertex2f(-0.28f, -0.18f);
    glEnd();

    }


    // from here, scene 2 code start
    if(scene == 2)
    {
         // sky
    if(scene2Night)
        glColor3f(0.02f, 0.02f, 0.15f); // night sky
    else
        glColor3f(0.4f, 0.7f, 1.0f); // day sky

    glBegin(GL_QUADS);
        glVertex2f(-1.0f,  1.0f);
        glVertex2f( 1.0f,  1.0f);
        glVertex2f( 1.0f,  0.15f);
        glVertex2f(-1.0f,  0.15f);
    glEnd();

    //adding cloud to scene2
    if(scene == 2)
    {
        //cloud1
    glPushMatrix();

    glTranslatef(cloudX, 0.70f, 0.0f);

    glColor3f(1.0f, 1.0f, 1.0f);

    // circle 1
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        float A = i * 3.1416f / 180.0f;
        glVertex2f(0.0f + 0.07f * cos(A),
                   0.0f + 0.07f * sin(A));
    }
    glEnd();

    // circle 2
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        float A = i * 3.1416f / 180.0f;
        glVertex2f(0.09f + 0.09f * cos(A),
                   0.02f + 0.09f * sin(A));
    }
    glEnd();

    // circle 3
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        float A = i * 3.1416f / 180.0f;
        glVertex2f(0.18f + 0.07f * cos(A),
                   0.0f + 0.07f * sin(A));
    }
    glEnd();

    glPopMatrix();



    // cloud 2



    glPushMatrix();

    glTranslatef(cloudX2, 0.82f, 0.0f);

    glColor3f(1.0f, 1.0f, 1.0f);

    // circle 1
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        float A = i * 3.1416f / 180.0f;
        glVertex2f(0.0f + 0.06f * cos(A),
                   0.0f + 0.06f * sin(A));
    }
    glEnd();

    // circle 2
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        float A = i * 3.1416f / 180.0f;
        glVertex2f(0.08f + 0.08f * cos(A),
                   0.02f + 0.08f * sin(A));
    }
    glEnd();

    // circle 3
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++) {
        float A = i * 3.1416f / 180.0f;
        glVertex2f(0.16f + 0.06f * cos(A),
                   0.0f + 0.06f * sin(A));
    }
    glEnd();

    glPopMatrix();

    }

        // adding sun and moon in scene 2
        if(scene == 2)
        {
    //sun/moon

    glPushMatrix();

    glTranslatef(sunX, sunY, 0.0f);

    float r = 0.10f;

    // day will appear sun
    if(!scene2Night)
    {
        glColor3f(1.0f, 1.0f, 0.0f);

        glBegin(GL_POLYGON);
        for(int i=0; i<360; i++)
        {
            float A = i * 3.1416f / 180.0f;
            glVertex2f(r*cos(A), r*sin(A));
        }
        glEnd();
    }

    // night will appear moon
    else
    {
        // moon body
        glColor3f(1.0f, 1.0f, 1.0f);

        glBegin(GL_POLYGON);
        for(int i=0; i<360; i++)
        {
            float A = i * 3.1416f / 180.0f;
            glVertex2f(r*cos(A), r*sin(A));
        }
        glEnd();

        // moon cut
        glColor3f(0.02f, 0.02f, 0.15f);

        glBegin(GL_POLYGON);
        for(int i=0; i<360; i++)
        {
            float A = i * 3.1416f / 180.0f;

            glVertex2f(
                0.04f + r*cos(A),
                0.02f + r*sin(A)
            );
        }
        glEnd();
    }

    glPopMatrix();
    }






    // water position
    if(scene2Night)
        glColor3f(0.02f, 0.08f, 0.15f); // dark water
    else
        glColor3f(0.0f, 0.35f, 0.7f);

    glBegin(GL_QUADS);
        glVertex2f(-1.0f,  0.15f);
        glVertex2f( 1.0f,  0.15f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f(-1.0f, -1.0f);
    glEnd();



    // sand curve
    if(scene2Night)
        glColor3f(0.30f, 0.30f, 0.30f);
    else
        glColor3f(0.90f, 0.80f, 0.45f);

    glBegin(GL_POLYGON);

        glVertex2f(-1.0f, -0.35f);
        glVertex2f(-1.0f, -0.05f);
        glVertex2f(-0.80f, -0.05f);
        glVertex2f(-0.55f, -0.08f);
        glVertex2f(-0.30f, -0.12f);
        glVertex2f(-0.05f, -0.18f);
        glVertex2f( 0.20f, -0.28f);
        glVertex2f( 0.45f, -0.45f);
        glVertex2f( 0.70f, -0.60f);
        glVertex2f( 1.00f, -0.78f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f(-1.0f, -1.0f);
    glEnd();


    // house 1 start from here


    // foundation
    if(scene2Night)
        glColor3f(0.12f, 0.12f, 0.12f);
    else
        glColor3f(0.45f, 0.72f, 0.55f);

    glBegin(GL_QUADS);
        glVertex2f(-0.86f, -0.30f);
        glVertex2f(-0.54f, -0.30f);
        glVertex2f(-0.54f, -0.27f);
        glVertex2f(-0.86f, -0.27f);
    glEnd();


    // main body
    if(scene2Night)
        glColor3f(0.12f, 0.12f, 0.12f);
    else
        glColor3f(0.55f, 0.18f, 0.12f);

    glBegin(GL_QUADS);
        glVertex2f(-0.84f, -0.27f);
        glVertex2f(-0.56f, -0.27f);
        glVertex2f(-0.56f, -0.01f);
        glVertex2f(-0.84f, -0.01f);
    glEnd();


    // chimney
    if(scene2Night)
        glColor3f(0.12f, 0.12f, 0.12f);
    else
        glColor3f(0.45f, 0.25f, 0.10f);

    glBegin(GL_QUADS);
        glVertex2f(-0.79f, 0.08f);
        glVertex2f(-0.75f, 0.08f);
        glVertex2f(-0.75f, 0.18f);
        glVertex2f(-0.79f, 0.18f);
    glEnd();


    // chimney top
    if(scene2Night)
        glColor3f(0.12f, 0.12f, 0.12f);
    else
        glColor3f(0.55f, 0.35f, 0.18f);

    glBegin(GL_QUADS);
        glVertex2f(-0.80f, 0.18f);
        glVertex2f(-0.74f, 0.18f);
        glVertex2f(-0.74f, 0.21f);
        glVertex2f(-0.80f, 0.21f);
    glEnd();


    // roof (wider)
    if(scene2Night)
        glColor3f(0.12f, 0.12f, 0.12f);
    else
        glColor3f(0.45f, 0.45f, 0.45f);

    glBegin(GL_TRIANGLES);
        glVertex2f(-0.90f, -0.01f);
        glVertex2f(-0.70f, 0.18f);
        glVertex2f(-0.50f, -0.01f);
    glEnd();


    // left window
    if(scene2Night)
        glColor3f(1.0f, 1.0f, 0.0f); // yellow light
    else
        glColor3f(0.60f, 0.88f, 1.0f); // blue glass

    glBegin(GL_QUADS);
        glVertex2f(-0.80f, -0.18f);
        glVertex2f(-0.74f, -0.18f);
        glVertex2f(-0.74f, -0.10f);
        glVertex2f(-0.80f, -0.10f);
    glEnd();


    // right window
    glBegin(GL_QUADS);
        glVertex2f(-0.66f, -0.18f);
        glVertex2f(-0.60f, -0.18f);
        glVertex2f(-0.60f, -0.10f);
        glVertex2f(-0.66f, -0.10f);
    glEnd();


    // door
    if(scene2Night)
        glColor3f(0.12f, 0.12f, 0.12f);
    else
        glColor3f(0.45f, 0.25f, 0.10f);

    glBegin(GL_QUADS);
        glVertex2f(-0.73f, -0.27f);
        glVertex2f(-0.67f, -0.27f);
        glVertex2f(-0.67f, -0.12f);
        glVertex2f(-0.73f, -0.12f);
    glEnd();





    // 2nd house


    // foundation
    if(scene2Night)
        glColor3f(0.12f, 0.12f, 0.12f);
    else
        glColor3f(0.75f, 0.75f, 0.75f);

    glBegin(GL_QUADS);
        glVertex2f(-0.64f, -0.34f);
        glVertex2f(-0.22f, -0.34f);
        glVertex2f(-0.22f, -0.30f);
        glVertex2f(-0.64f, -0.30f);
    glEnd();


    // main body
    if(scene2Night)
        glColor3f(0.12f, 0.12f, 0.12f);
    else
        glColor3f(0.96f, 0.92f, 0.82f);

    glBegin(GL_QUADS);
        glVertex2f(-0.62f, -0.30f);
        glVertex2f(-0.24f, -0.30f);
        glVertex2f(-0.24f,  0.04f);
        glVertex2f(-0.62f,  0.04f);
    glEnd();


    // upper floor
    if(scene2Night)
        glColor3f(0.12f, 0.12f, 0.12f);
    else
        glColor3f(0.92f, 0.88f, 0.78f);

    glBegin(GL_QUADS);
        glVertex2f(-0.57f, 0.04f);
        glVertex2f(-0.29f, 0.04f);
        glVertex2f(-0.29f, 0.25f);
        glVertex2f(-0.57f, 0.25f);
    glEnd();


    // roof
    if(scene2Night)
        glColor3f(0.12f, 0.12f, 0.12f);
    else
        glColor3f(0.75f, 0.20f, 0.10f);

    glBegin(GL_TRIANGLES);
        glVertex2f(-0.70f, 0.25f);
        glVertex2f(-0.16f, 0.25f);
        glVertex2f(-0.43f, 0.50f);
    glEnd();

    // upper left window
    if(scene2Night)
        glColor3f(1.0f, 1.0f, 0.0f); // yellow light
    else
        glColor3f(0.60f, 0.88f, 1.0f); // blue glass
    glBegin(GL_QUADS);
        glVertex2f(-0.54f, 0.13f);
        glVertex2f(-0.47f, 0.13f);
        glVertex2f(-0.47f, 0.20f);
        glVertex2f(-0.54f, 0.20f);
    glEnd();


    // upper right window
    glBegin(GL_QUADS);
        glVertex2f(-0.39f, 0.13f);
        glVertex2f(-0.32f, 0.13f);
        glVertex2f(-0.32f, 0.20f);
        glVertex2f(-0.39f, 0.20f);
    glEnd();


    // lower left window
    glBegin(GL_QUADS);
        glVertex2f(-0.57f, -0.20f);
        glVertex2f(-0.49f, -0.20f);
        glVertex2f(-0.49f, -0.08f);
        glVertex2f(-0.57f, -0.08f);
    glEnd();


    // lower right window
    glBegin(GL_QUADS);
        glVertex2f(-0.37f, -0.20f);
        glVertex2f(-0.29f, -0.20f);
        glVertex2f(-0.29f, -0.08f);
        glVertex2f(-0.37f, -0.08f);
    glEnd();


    // door
    if(scene2Night)
        glColor3f(0.12f, 0.12f, 0.12f);
    else
        glColor3f(0.45f, 0.25f, 0.05f);

    glBegin(GL_QUADS);
        glVertex2f(-0.46f, -0.30f);
        glVertex2f(-0.39f, -0.30f);
        glVertex2f(-0.39f, -0.03f);
        glVertex2f(-0.46f, -0.03f);
    glEnd();





    // 3rd house start from here:

    // foundation
    if(scene2Night)
        glColor3f(0.12f, 0.12f, 0.12f);
    else
        glColor3f(0.70f, 0.70f, 0.70f);

    glBegin(GL_QUADS);
        glVertex2f(-0.18f, -0.35f);
        glVertex2f( 0.18f, -0.35f);
        glVertex2f( 0.18f, -0.31f);
        glVertex2f(-0.18f, -0.31f);
    glEnd();


    // main body
    if(scene2Night)
        glColor3f(0.12f, 0.12f, 0.12f);
    else
        glColor3f(0.90f, 0.82f, 0.65f);

    glBegin(GL_QUADS);
        glVertex2f(-0.16f, -0.31f);
        glVertex2f( 0.16f, -0.31f);
        glVertex2f( 0.16f,  0.00f);
        glVertex2f(-0.16f,  0.00f);
    glEnd();


    // upper floor
    if(scene2Night)
        glColor3f(0.12f, 0.12f, 0.12f);
    else
        glColor3f(0.85f, 0.76f, 0.58f);

    glBegin(GL_QUADS);
        glVertex2f(-0.16f, 0.00f);
        glVertex2f( 0.16f, 0.00f);
        glVertex2f( 0.16f, 0.15f);
        glVertex2f(-0.16f, 0.15f);
    glEnd();


    // roof
    if(scene2Night)
        glColor3f(0.12f, 0.12f, 0.12f);
    else
        glColor3f(0.40f, 0.18f, 0.10f);

    glBegin(GL_TRIANGLES);
        glVertex2f(-0.22f, 0.15f);
        glVertex2f( 0.22f, 0.15f);
        glVertex2f( 0.00f, 0.34f);
    glEnd();


    // left window
    if(scene2Night)
        glColor3f(1.0f, 1.0f, 0.0f); // yellow light
    else
        glColor3f(0.60f, 0.88f, 1.0f); // blue glass

    glBegin(GL_QUADS);
        glVertex2f(-0.12f, -0.21f);
        glVertex2f(-0.04f, -0.21f);
        glVertex2f(-0.04f, -0.10f);
        glVertex2f(-0.12f, -0.10f);
    glEnd();


    // right window
    glBegin(GL_QUADS);
        glVertex2f(0.04f, -0.21f);
        glVertex2f(0.12f, -0.21f);
        glVertex2f(0.12f, -0.10f);
        glVertex2f(0.04f, -0.10f);
    glEnd();


    // upper window
    glBegin(GL_QUADS);
        glVertex2f(-0.04f, 0.04f);
        glVertex2f( 0.04f, 0.04f);
        glVertex2f( 0.04f, 0.11f);
        glVertex2f(-0.04f, 0.11f);
    glEnd();


    // door
    if(scene2Night)
        glColor3f(0.12f, 0.12f, 0.12f);
    else
        glColor3f(0.45f, 0.25f, 0.08f);

    glBegin(GL_QUADS);
        glVertex2f(-0.03f, -0.31f);
        glVertex2f( 0.04f, -0.31f);
        glVertex2f( 0.04f, -0.07f);
        glVertex2f(-0.03f, -0.07f);
    glEnd();

    //windmill

    glPushMatrix();

    // position beside house 1 (left side)
    glTranslatef(-0.95f, -0.02f, 0.0f);

    // scaling
    glScalef(0.35f, 0.35f, 1.0f);


    // tower
    if(scene2Night)
        glColor3f(0.05f, 0.05f, 0.05f);
    else
        glColor3f(0.55f, 0.35f, 0.15f);

    glBegin(GL_POLYGON);
        glVertex2f(-0.05f, -0.80f);
        glVertex2f( 0.05f, -0.80f);
        glVertex2f( 0.03f,  0.00f);
        glVertex2f(-0.03f,  0.00f);
    glEnd();


    // move to top
    glPushMatrix();

    glTranslatef(0.0f, 0.0f, 0.0f);

    // rotation
    glRotatef(windmillAngle, 0.0f, 0.0f, 1.0f);


    // blade 1
    glColor3f(0.8f, 0.2f, 0.2f);

    glBegin(GL_POLYGON);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.45f, 0.04f);
        glVertex2f(0.45f,-0.04f);
    glEnd();


    // blade 2
    glRotatef(90,0,0,1);

    glBegin(GL_POLYGON);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.45f, 0.04f);
        glVertex2f(0.45f,-0.04f);
    glEnd();


    // blade 3
    glRotatef(90,0,0,1);

    glBegin(GL_POLYGON);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.45f, 0.04f);
        glVertex2f(0.45f,-0.04f);
    glEnd();


    // blade 4
    glRotatef(90,0,0,1);

    glBegin(GL_POLYGON);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.45f, 0.04f);
        glVertex2f(0.45f,-0.04f);
    glEnd();


    // center circle
    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);

    for(int i=0; i<360; i++)
    {
        float A = i * 3.1416f / 180.0f;

        glVertex2f(
            0.06f*cos(A),
            0.06f*sin(A)
        );
    }

    glEnd();

    glPopMatrix();
    glPopMatrix();




    // boat start from here:

    glPushMatrix();

    glTranslatef(boat2X - 0.12f, 0.08f, 0.0f);   // moved boat a bit LEFT


    // boat body
    glColor3f(0.45f, 0.20f, 0.05f);

    glBegin(GL_POLYGON);
        glVertex2f(0.48f, -0.38f);
        glVertex2f(0.76f, -0.38f);
        glVertex2f(0.69f, -0.49f);
        glVertex2f(0.55f, -0.49f);
    glEnd();


    // upper white body
    glColor3f(0.92f, 0.92f, 0.92f);

    glBegin(GL_QUADS);
        glVertex2f(0.56f, -0.31f);
        glVertex2f(0.69f, -0.31f);
        glVertex2f(0.69f, -0.38f);
        glVertex2f(0.56f, -0.38f);
    glEnd();


    // boat pole
    glColor3f(0.25f, 0.15f, 0.05f);

    glBegin(GL_QUADS);
        glVertex2f(0.62f, -0.31f);
        glVertex2f(0.63f, -0.31f);
        glVertex2f(0.63f, -0.08f);
        glVertex2f(0.62f, -0.08f);
    glEnd();


    // sail
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_TRIANGLES);
        glVertex2f(0.63f, -0.08f);
        glVertex2f(0.74f, -0.22f);
        glVertex2f(0.63f, -0.22f);
    glEnd();

    glPopMatrix();




    //2nd boat start from here:

    glPushMatrix();


    // starts near the dock
    glTranslatef(boat3X, 0.02f, 0.0f);


    // boat body
    glColor3f(0.35f, 0.18f, 0.04f);

    glBegin(GL_POLYGON);
        glVertex2f(0.48f, -0.38f);
        glVertex2f(0.76f, -0.38f);
        glVertex2f(0.69f, -0.49f);
        glVertex2f(0.55f, -0.49f);
    glEnd();


    // upper body
    glColor3f(0.85f, 0.85f, 0.88f);

    glBegin(GL_QUADS);
        glVertex2f(0.56f, -0.31f);
        glVertex2f(0.69f, -0.31f);
        glVertex2f(0.69f, -0.38f);
        glVertex2f(0.56f, -0.38f);
    glEnd();


    // pole
    glColor3f(0.28f, 0.16f, 0.06f);

    glBegin(GL_QUADS);
        glVertex2f(0.62f, -0.31f);
        glVertex2f(0.63f, -0.31f);
        glVertex2f(0.63f, -0.08f);
        glVertex2f(0.62f, -0.08f);
    glEnd();


    // sail
    glColor3f(0.95f, 0.95f, 0.95f);

    glBegin(GL_TRIANGLES);
        glVertex2f(0.63f, -0.08f);
        glVertex2f(0.74f, -0.22f);
        glVertex2f(0.63f, -0.22f);
    glEnd();

    glPopMatrix();



        }


        glutSwapBuffers();
    }













// keyboard event handler function
void handleKeyboard(unsigned char key, int x, int y)
{
    // night scene
    if(key == 'n' || key == 'N')
    {
        isNight = true;
    }

    // day scene
    if(key == 'm' || key == 'M')   // changed from D to M
    {
        isNight = false;
    }

    // scene 1
    if(key == '1')
    {
        scene = 1;
    }

    // scene 2
    if(key == '2')
    {
        scene = 2;
    }

    // first boat move
    if(key == 's' || key == 'S')
    {
        boatMove = true;
    }

    // second boat move
    if(key == 'd' || key == 'D')
    {
        boat2Move = true;
    }


    // Scene 2 NIGHT
    if(key == 'v' || key == 'V')
    {
        scene2Night = true;
    }

    // Scene 2 DAY
    if(key == 'b' || key == 'B')
    {
        scene2Night = false;
    }




    glutPostRedisplay();
}

//    glutPostRedisplay();
//}



// Update
void update(int value)
{
    moveX -= boatSpeed;
    cloudX -= cloudSpeed;

    // reset positions
    if(moveX < -1.5f)
        moveX = 1.5f;

    if(cloudX < -1.3f)
        cloudX = 1.3f;

    cloudX2 -= 0.0012f;

    if(cloudX2 < -1.3f)
        cloudX2 = 1.3f;

    // SUN / MOON movement
    sunX += 0.0008f;
    sunY += 0.0005f;

    // reset after going out of sky
    if(sunX > 1.2f)
    {
        isNight = !isNight;

        sunX = -0.8f;
        sunY = -0.2f;
    }

    // 1st boat move
    if(boatMove)
    {
        boat2X += 0.002f;

        if(boat2X > 1.2f)
        {
            boat2X = 0.0f;
        }
    }

    // 2nd boat move
    if(boat2Move)
    {
        boat3X -= 0.002f;

        // stop beside the deck
        if(boat3X <= -0.02f)
        {
            boat3X = -0.02f;
            boat2Move = false;
        }
    }

    // windmill rotation
    windmillAngle += 2.0f;

    if(windmillAngle > 360)
        windmillAngle -= 360;

    glutPostRedisplay();
    glutTimerFunc(10, update, 0);
}






//mouse event handeller function


void handleMouseR(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN) {

        // RIGHT CLICK → SPEED UP
        if (button == GLUT_RIGHT_BUTTON) {
            boatSpeed += 0.001f;
            cloudSpeed += 0.001f;
        }

        // LEFT CLICK → SLOW DOWN
        if (button == GLUT_LEFT_BUTTON) {
            boatSpeed -= 0.001f;
            cloudSpeed -= 0.001f;

            // minimum speed (so it doesn't stop or go backward)
            if (boatSpeed < 0.0001f) boatSpeed = 0.0001f;
            if (cloudSpeed < 0.0001f) cloudSpeed = 0.0001f;
        }
    }
}

// main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 700);
    glutCreateWindow("Beach Scene");

    glutMouseFunc(handleMouseR); //this if for mouse function
    glutKeyboardFunc(handleKeyboard);// this is for keyboard

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1,1,-1,1);

    glutDisplayFunc(drawScene);
    glutTimerFunc(20, update, 0);
    glutMainLoop();
    return 0;
}
