#include <GL/glut.h>
#include "Sierpinski.h"
#include "main.h"



Sierpinski3D sierpinski3D;
Console console;
float rotationSpeed = 1.0f;
int depth = 2;

GLfloat farPlane = 100.0f;
GLfloat nearPlane = 1.0f;

// Actual definitions of global variables
Viewport viewport = {1280, 720, 1920 - 1280, 1080 - 720};
Mouse mouse;
Rotation rotation = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
Camera cameras[4] = {
    Camera(5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f),
    Camera(10.0f, 45.0f, 45.0f, 0.0f, 0.0f, 0.0f),
    Camera(70.0f, 0.0f, 90.0f, 0.0f, 0.0f, 0.0f),
    Camera(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)  // Free roam mode
};

FreeCamera freeCamera = {0.0f, 1.5f, 5.0f,  // Camera Position
              0.0f, 0.0f, -1.0f, // Camera Direction (looking forward)
              0.0f, 1.0f, 0.0f,  // Up vector
              0.1f, 0.00001f};       // Movement speed and sensitivity


int currentCameraIndex = 0;
bool isDragging = false;
bool freeRoam = false;


void renderGUI() {
    ImGui_ImplOpenGL2_NewFrame();
    ImGui_ImplGLUT_NewFrame();
    ImGui::NewFrame();

    // Render each panel separately
    RenderMainControls();
   console.Render();

    // Finish ImGui frame
    ImGui::Render();
    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
}


void RenderMainControls() {
    ImGui::Begin("Controls");

    ImGui::Text("Perspective:");
    ImGui::SliderFloat("Near Plane", &nearPlane, -5.0f, 10.0f);
    ImGui::SliderFloat("Far Plane", &farPlane, 1.0f, 100.0f);

    ImGui::Text("Rotation Speeds:");
    ImGui::SliderFloat("Speed X", &rotation.speedX, -5.0f, 5.0f);
    ImGui::SliderFloat("Speed Y", &rotation.speedY, -5.0f, 5.0f);
    ImGui::SliderFloat("Speed Z", &rotation.speedZ, -5.0f, 5.0f);
    ImGui::SliderInt("Depth", &depth, 2, 8);

    if (ImGui::Button("Reset Rotation")) {
        rotation.angleX = rotation.angleY = rotation.angleZ = 0.0f;
        rotation.speedX = rotation.speedY = rotation.speedZ = 0.0f;
    }

    ImGui::Checkbox("Show Origin Axes", &showOriginAxes);
    ImGui::Checkbox("Show Object Axes", &showObjectAxes);
    ImGui::Checkbox("Free Roam", &freeRoam);

    const char* cameraNames[] = {"Default", "Side View", "Top-Down", "Free Roam"};
    ImGui::Combo("Camera", &currentCameraIndex, cameraNames, IM_ARRAYSIZE(cameraNames));

    ImGui::End();
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
    gluPerspective(45.0, (float)viewportWidth / (float)viewportHeight, nearPlane, farPlane);
    glMatrixMode(GL_MODELVIEW);

}
void keyboardDown(unsigned char key, int x, int y) {
    ImGuiIO& io = ImGui::GetIO();
    
    // Pass all keys to ImGui when it's capturing input
    if (io.WantCaptureKeyboard) {
        io.AddInputCharacter(key);
        return;
    }

    // Game controls if ImGui isn't focused
    keyStates[key] = true;
}

void keyboardUp(unsigned char key, int x, int y) {
    ImGuiIO& io = ImGui::GetIO();
    
    if (io.WantCaptureKeyboard) {
        return;
    }
    keyStates[key] = false;
}



void display() {
    // Clear buffers and reset transformations
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    updateViewPort();

    if(!freeRoam){
        cameras[currentCameraIndex].applyView();
    }
    else{
        updateFreeCamera();
    }

    drawGrid(10.0f, 20, -2);
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


    bool isInside = insideViewport(x, invertedY, viewport);
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



    bool isInside = insideViewport(x, invertedY, viewport);

    // Pass all events to ImGui first
    ImGui_ImplGLUT_MotionFunc(x, y);

    // Object manipulation only if inside the viewport
    if (isInside && isDragging) {
        int dx = x - mouse.mouseX;
        int dy = y - mouse.mouseY;

        cameras[currentCameraIndex].angleX += dx * 0.5f;
        cameras[currentCameraIndex].angleY += dy * 0.5f;

        if (cameras[currentCameraIndex].angleY > 89.0f) cameras[currentCameraIndex].angleY = 89.0f;
        if (cameras[currentCameraIndex].angleY < -89.0f) cameras[currentCameraIndex].angleY = -89.0f;

        mouse.mouseX = x;
        mouse.mouseY = y;

        glutPostRedisplay();
    }
}


void mouseMotionRoam(int x, int y) {
    if (!freeRoam) return;  // Exit if not in free roam mode

    ImGuiIO& io = ImGui::GetIO();
    int invertedY = glutGet(GLUT_WINDOW_HEIGHT) - y;

    // Capture mouse only when inside the viewport
    if (isMouseInViewport(x, invertedY)) {
        io.WantCaptureMouse = false;  // Enable camera control
    } else {
        io.WantCaptureMouse = true;
    }

    if (!io.WantCaptureMouse) {
        static bool warp = false;

        if (warp) {
            warp = false;
            return;
        }

        // Calculate viewport center
        int centerX = viewport.viewportX + viewport.viewportWidth / 2;
        int centerY = viewport.viewportHeight / 2;


        // Clamp mouse position within viewport bounds
  
        // Calculate relative mouse position


        // Debugging output
        std::cout << "Viewport Center: " << centerX << ", " << centerY << std::endl;
        std::cout << "Mouse: " << x << ", " << y << std::endl;

        // Calculate deltas (difference from center)
        int dx = x - centerX;
        int dy = centerY -y;  // **Fixed Y Inversion**

        // Adjust yaw and pitch
        freeCamera.dirX += dx * freeCamera.sensitivity;
        freeCamera.dirY += dy * freeCamera.sensitivity;  // Inverted for natural pitch

        // Clamp pitch to avoid flipping
        if (freeCamera.dirY > 89.9f) freeCamera.dirY = 89.9f;
        if (freeCamera.dirY < -89.9f) freeCamera.dirY = -89.9f;

        // Debug output for direction
        std::cout << "Direction: " << freeCamera.dirX << ", " << freeCamera.dirY << std::endl;

        // Re-center the mouse cursor inside the viewport
        warp = true;
        glutWarpPointer(centerX, centerY);
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
    glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);
    glutPassiveMotionFunc(mouseMotionRoam);

    // Main loop
    glutMainLoop();

    // Cleanup
    ImGui_ImplOpenGL2_Shutdown();
    ImGui_ImplGLUT_Shutdown();
    ImGui::DestroyContext();
}
