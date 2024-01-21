#include <GL/glut.h>
#include <math.h>

// Ball properties
float ballRadius = 0.1f;
float ballX = 0.0f;
float ballY = 0.0f;
float ballSpeedX = 0.02f;
float ballSpeedY = 0.02f;

// Update function to move the ball
void update(int value) {
    // Update ball position
    ballX += ballSpeedX;
    ballY += ballSpeedY;

    // Reverse direction if ball reaches the window boundaries
    if (ballX + ballRadius > 1.0f || ballX - ballRadius < -1.0f) {
        ballSpeedX = -ballSpeedX;
    }
    if (ballY + ballRadius > 1.0f || ballY - ballRadius < -1.0f) {
        ballSpeedY = -ballSpeedY;
    }

    // Redraw
    glutPostRedisplay();
    // Call update function again after 16 milliseconds (60 frames per second)
    glutTimerFunc(16, update, 0);
}

// Display function to draw the ball
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Draw the ball
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(ballX, ballY); // Center of the circle
    for (int i = 0; i <= 360; i++) {
        float angle = 3.1415926 * i / 180.0;
        float x = ballX + ballRadius * cos(angle);
        float y = ballY + ballRadius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    // Swap buffers to display the rendered image
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Moving Ball");
    
    // Set up the viewport
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    
    // Set the display and update functions
    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0); // Call update every 25 milliseconds
    
    // Enter the GLUT event processing loop
    glutMainLoop();
    
    return 0;
}
