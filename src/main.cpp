#include <GL/glut.h>
#include "Sierpinski.h"
#include "main.h"


Sierpinski3D sierpinski3D;
float rotationSpeed = 1.0f;
int depth = 2;


void renderGUI() {
    ImGui_ImplOpenGL2_NewFrame();
    ImGui_ImplGLUT_NewFrame();
    ImGui::NewFrame();

    // Rotation Control Panel
    ImGui::Begin("Controls");

    // Adjust Rotation Speed
    ImGui::Text("Rotation Speeds:");
    ImGui::SliderFloat("Speed X", &rotation.speedX, -5.0f, 5.0f);
    ImGui::SliderFloat("Speed Y", &rotation.speedY, -5.0f, 5.0f);
    ImGui::SliderFloat("Speed Z", &rotation.speedZ, -5.0f, 5.0f);
    ImGui::SliderInt("Depth", &depth, 2, 8);


    // Reset Button for Angles
    if (ImGui::Button("Reset Rotation")) {
        rotation.angleX = rotation.angleY = rotation.angleZ = 0.0f;
        rotation.speedX = rotation.speedY = rotation.speedZ = 0.0f;
    }


    ImGui::Checkbox("Show Origin Axes", &showOriginAxes);  // Toggle axes
    ImGui::Checkbox("Show Object Axes", &showObjectAxes);  // Toggle axes
    
    ImGui::End();


    ImGui::Render();
    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
}



void updateViewPort(){

    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);

    double screenScaleFactor = (1920.0 / width); 

    int viewportWidth = 1280 / screenScaleFactor;
    int viewportHeight = 720 / screenScaleFactor;
    int viewportX = width - viewportWidth;
    int viewportY = height - viewportHeight;

    if(viewportWidth != viewport.viewportWidth || viewportHeight != viewport.viewportHeight || viewportX != viewport.viewportX || viewportY != viewport.viewportY){
        std::cout << "Viewport: " << viewportWidth << "x" << viewportHeight << " at " << viewportX << ", " << viewportY << std::endl;

    }

    glViewport(viewportX, viewportY, viewportWidth, viewportHeight);

    viewport = {viewportWidth, viewportHeight, viewportX, viewportY};

    // Set projection matrix for the smaller viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)viewportWidth / (float)viewportHeight, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);

}

void display() {
    // Clear buffers and reset transformations
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();


    updateViewPort();

    // Camera transformations
    GLfloat radX = cam.cameraAngleX * M_PI / 180.0f;
    GLfloat radY = cam.cameraAngleY * M_PI / 180.0f;
    GLfloat camX = cam.cameraDistance * cos(radY) * sin(radX);
    GLfloat camY = cam.cameraDistance * sin(radY);
    GLfloat camZ = cam.cameraDistance * cos(radY) * cos(radX);

    gluLookAt(camX, camY, camZ,  // Camera position
              0.0f, 0.0f, 0.0f,  // Look-at point
              0.0f, 1.0f, 0.0f); // Up vector

// Apply object rotations
    glPushMatrix();  // Save the current transformation state
    glTranslatef(0.0f, 0.0f, -2.0f);  // Move object into the scene

    // Rotate around different axes
    rotation.angleX += rotation.speedX;
    rotation.angleY += rotation.speedY;
    rotation.angleZ += rotation.speedZ;

    glRotatef(rotation.angleX, 1.0f, 0.0f, 0.0f);  // Rotate around X-axis
    glRotatef(rotation.angleY, 0.0f, 1.0f, 0.0f);  // Rotate around Y-axis
    glRotatef(rotation.angleZ, 0.0f, 0.0f, 1.0f);  // Rotate around Z-axis

    // Draw the Sierpinski object
    sierpinski3D.drawSierpinskiObject(0.0f, 0.0f, 0.0f, 30.0f, 1.0f, depth);

    if (showObjectAxes) {
       drawAxesAt(0.0f, 0.0f, 0.0f, 1.0f);  // Axes and sphere at object center
        drawSphere(0.0f, 0.0f, 0.0f, 0.01f, 1.0f, 1.0f, 1.0f);  // Red sphere at origin
    }


    glPopMatrix();  // Restore previous transformation state

    if (showOriginAxes) {
        drawAxes(1.0f);  // Axis length
    }
    // Draw ImGui GUI overlay **AFTER** the OpenGL rendering
    renderGUI();

    glutSwapBuffers();
    glutPostRedisplay();  // Trigger continuous rendering (required for ImGui)
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)width / (float)height, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);

    // Update ImGui display size to match the window
    ImGuiIO& io = ImGui::GetIO();
    io.DisplaySize = ImVec2((float)width, (float)height);
}

void mouseButton(int button, int state, int x, int y) {
    int invertedY = glutGet(GLUT_WINDOW_HEIGHT) - y;


    bool isInside = insideViewport(x, invertedY, viewport.viewportX, viewport.viewportY, viewport.viewportWidth, viewport.viewportHeight);
    // Pass all events to ImGui first
    ImGui_ImplGLUT_MouseFunc(button, state, x, y);

    // If inside viewport, allow object control
    if (isInside) {
        if (button == GLUT_LEFT_BUTTON) {
            if (state == GLUT_DOWN) {
                isDragging = true;
                mouse.mouseX = x;
                mouse.mouseY = y;
            } else {
                isDragging = false;
            }
        }
    }
}

void mouseMotion(int x, int y) {
    int invertedY = glutGet(GLUT_WINDOW_HEIGHT) - y;


    bool isInside = insideViewport(x, invertedY, viewport.viewportX, viewport.viewportY, viewport.viewportWidth, viewport.viewportHeight);

    // Pass all events to ImGui first
    ImGui_ImplGLUT_MotionFunc(x, y);

    // Object manipulation only if inside the viewport
    if (isInside && isDragging) {
        int dx = x - mouse.mouseX;
        int dy = y - mouse.mouseY;

        cam.cameraAngleX += dx * 0.5f;
        cam.cameraAngleY += dy * 0.5f;

        if (cam.cameraAngleY > 89.0f) cam.cameraAngleY = 89.0f;
        if (cam.cameraAngleY < -89.0f) cam.cameraAngleY = -89.0f;

        mouse.mouseX = x;
        mouse.mouseY = y;

        glutPostRedisplay();
    }
}


int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(0, 0);

    glutCreateWindow("OpenViz");

    // Init ImGui
    ImGui::CreateContext();
    ImGui_ImplGLUT_Init();
    ImGui_ImplOpenGL2_Init();

    glEnable(GL_DEPTH_TEST);

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMotion);

    // Main loop
    glutMainLoop();

    // Cleanup
    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplGLUT_Shutdown();
    ImGui::DestroyContext();
}
