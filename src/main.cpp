#include <GL/glut.h>
#include "Sierpinski.h"
#include "main.h"



Sierpinski3D sierpinski3D;
Console console;
float rotationSpeed = 1.0f;
int depth = 2;

GLfloat farPlane = 100.0f;
GLfloat nearPlane = 1.0f;
GLfloat fov = 45.0f;
GLfloat tempDistance = cameras[currentCameraIndex].getDistance();

Viewport viewport = {1280, 720, 1920 - 1280, 1080 - 720};
Mouse mouse;
Rotation rotation = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
Camera cameras[4] = {
    Camera(5.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f),
    Camera(10.0f, 45.0f, 45.0f, 0.0f, 0.0f, 0.0f),
    Camera(70.0f, 0.0f, 90.0f, 0.0f, 0.0f, 0.0f),
    Camera(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f)  
};

FreeCamera freeCamera = {0.0f, 1.5f, 5.0f, 
              0.0f, 0.0f, -1.0f, 
              0.0f, 1.0f, 0.0f,  
              0.1f, 0.00001f};     


int currentCameraIndex = 0;
bool isDragging = false;
bool freeRoam = false;
bool showFrustrum[4] = {false, false, false, false};
Translation translation = {0.0f, 0.0f, 0.0f};


void renderGUI() {
    ImGui_ImplOpenGL2_NewFrame();
    ImGui_ImplGLUT_NewFrame();
    ImGui::NewFrame();

    RenderMainControls();
   console.Render();

    ImGui::Render();
    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
}


void RenderMainControls() {
    ImGui::Begin("Controls");

    ImGui::Text("Perspective:");
    ImGui::SliderFloat("Near Plane", &nearPlane, -5.0f, 10.0f);
    ImGui::SliderFloat("Far Plane", &farPlane, 1.0f, 100.0f);
    ImGui::SliderFloat("FOV", &fov, 10.0f, 120.0f);


    ImGui::Text("Rotation Speeds:");
    ImGui::SliderFloat("Speed X", &rotation.speedX, -5.0f, 5.0f);
    ImGui::SliderFloat("Speed Y", &rotation.speedY, -5.0f, 5.0f);
    ImGui::SliderFloat("Speed Z", &rotation.speedZ, -5.0f, 5.0f);
    ImGui::SliderInt("Depth", &depth, 2, 8);

    ImGui::Text("Translation:");
    ImGui::SliderFloat("Translation X", &translation.x, -5.0f, 5.0f);
    ImGui::SliderFloat("Translation Y", &translation.y, -5.0f, 5.0f);
    ImGui::SliderFloat("Translation Z", &translation.z, -5.0f, 5.0f);

    if (ImGui::Button("Reset Rotation")) {
        rotation.angleX = rotation.angleY = rotation.angleZ = 0.0f;
        rotation.speedX = rotation.speedY = rotation.speedZ = 0.0f;
        if(console.verboseMode){
            console.AddLog("Reset Rotation");
        }
    }

    ImGui::Checkbox("Show Origin Axes", &showOriginAxes);
    ImGui::Checkbox("Show Object Axes", &showObjectAxes);
    ImGui::Checkbox("Free Roam", &freeRoam);


    if (ImGui::SliderFloat("Camera Distance", &tempDistance, 1.0f, 100.0f)) {
        std::cout << "Preview Distance: " << tempDistance << std::endl;
    }

    if (ImGui::IsItemDeactivatedAfterEdit()) {
        cameras[currentCameraIndex].setDistance(tempDistance);
        tempDistance = cameras[currentCameraIndex].getDistance();

    }

    const char* cameraNames[] = {"Default", "Side View", "Top-Down", "Free Roam"};
   if( ImGui::Combo("Camera", &currentCameraIndex, cameraNames, IM_ARRAYSIZE(cameraNames))){
        tempDistance = cameras[currentCameraIndex].getDistance();
        if(console.verboseMode){
            console.AddLog("Current Camera Index %d", currentCameraIndex);
        }
   }
    ImGui::Checkbox("Show Frustrum Cam Default", &showFrustrum[0]);
    ImGui::Checkbox("Show Frustrum Cam Side View", &showFrustrum[1]);
    ImGui::Checkbox("Show Frustrum Cam Top View", &showFrustrum[2]);


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
        
        if(console.verboseMode){
            console.AddLog("Viewport %dx%d at %d,%d", viewportWidth, viewportHeight, viewportX, viewportY);
        }
        std::cout << "Viewport: " << viewportWidth << "x" << viewportHeight << " at " << viewportX << ", " << viewportY << std::endl;

    }

    glViewport(viewportX, viewportY, viewportWidth, viewportHeight);

    viewport = {viewportWidth, viewportHeight, viewportX, viewportY};

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fov, (float)viewportWidth / (float)viewportHeight, nearPlane, farPlane);
    glMatrixMode(GL_MODELVIEW);

}
void keyboardDown(unsigned char key, int x, int y) {
    ImGuiIO& io = ImGui::GetIO();
    
    if (io.WantCaptureKeyboard) {
        io.AddInputCharacter(key);
        return;
    }
    if(console.verboseMode){
        console.AddLog("Key pressed %c", key);
    }

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
    glPushMatrix();  
    glTranslatef(0.0f, 0.0f, -2.0f);  

    rotation.angleX += rotation.speedX;
    rotation.angleY += rotation.speedY;
    rotation.angleZ += rotation.speedZ;

    glRotatef(rotation.angleX, 1.0f, 0.0f, 0.0f);  
    glRotatef(rotation.angleY, 0.0f, 1.0f, 0.0f);  
    glRotatef(rotation.angleZ, 0.0f, 0.0f, 1.0f);

    glTranslatef(translation.x, translation.y, translation.z);

    sierpinski3D.drawSierpinskiObject(0.0f, 0.0f, 0.0f, 30.0f, 1.0f, depth);

    if (showObjectAxes) {
       drawAxesAt(0.0f, 0.0f, 0.0f, 1.0f);  
        drawSphere(0.0f, 0.0f, 0.0f, 0.01f, 1.0f, 1.0f, 1.0f);  
    }


    glPopMatrix();  

    if (showOriginAxes) {
        drawAxes(1.0f);
    }

    int camIndex = 0;
    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);

    for (bool frustrum : showFrustrum) {
        if(frustrum){
            cameras[camIndex].drawFrustum(nearPlane, farPlane, fov, (float)width / (float)height);
        }
        camIndex++;
    }

    renderGUI();

    glutSwapBuffers();
    glutPostRedisplay(); 
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fov, (float)width / (float)height, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);

    ImGuiIO& io = ImGui::GetIO();
    io.DisplaySize = ImVec2((float)width, (float)height);
}

void mouseButton(int button, int state, int x, int y) {

    if (button == 4) {
        cameras[currentCameraIndex].setDistance(cameras[currentCameraIndex].getDistance() + 2.0f);

    } else if(button == 3) {
        cameras[currentCameraIndex].setDistance(cameras[currentCameraIndex].getDistance() - 2.0f);

    }



    int invertedY = glutGet(GLUT_WINDOW_HEIGHT) - y;


    bool isInside = insideViewport(x, invertedY, viewport);
    ImGui_ImplGLUT_MouseFunc(button, state, x, y);

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
    glutPostRedisplay();

}

void mouseMotion(int x, int y) {
    int invertedY = glutGet(GLUT_WINDOW_HEIGHT) - y;

    bool isInside = insideViewport(x, invertedY, viewport);

    ImGui_ImplGLUT_MotionFunc(x, y);

    if (isInside && isDragging) {
        int dx = x - mouse.mouseX;
        int dy = y - mouse.mouseY;

        cameras[currentCameraIndex].angleX += dx * 0.5f;
        cameras[currentCameraIndex].angleY += dy * 0.5f;

        if (cameras[currentCameraIndex].angleY > 89.0f) cameras[currentCameraIndex].angleY = 89.0f;
        if (cameras[currentCameraIndex].angleY < -89.0f) cameras[currentCameraIndex].angleY = -89.0f;

        mouse.mouseX = x;
        mouse.mouseY = y;
        
        if(console.verboseMode){
            console.AddLog("Cam Angle %d:%d",
        cameras[currentCameraIndex].angleX, 
        cameras[currentCameraIndex].angleY);
        }

        glutPostRedisplay();
    }
}


void mouseMotionRoam(int x, int y) {
    if (!freeRoam) return;  

    ImGuiIO& io = ImGui::GetIO();
    int invertedY = glutGet(GLUT_WINDOW_HEIGHT) - y;

    if (isMouseInViewport(x, invertedY)) {
        io.WantCaptureMouse = false; 
    } else {
        io.WantCaptureMouse = true;
    }

    if (!io.WantCaptureMouse) {
        static bool warp = false;

        if (warp) {
            warp = false;
            return;
        }

        int centerX = viewport.viewportX + viewport.viewportWidth / 2;
        int centerY = viewport.viewportHeight / 2;


        std::cout << "Viewport Center: " << centerX << ", " << centerY << std::endl;
        std::cout << "Mouse: " << x << ", " << y << std::endl;

        int dx = x - centerX;
        int dy = centerY -y;  

        freeCamera.dirX += dx * freeCamera.sensitivity;
        freeCamera.dirY += dy * freeCamera.sensitivity;  // Inverted for natural pitch

        if (freeCamera.dirY > 89.9f) freeCamera.dirY = 89.9f;
        if (freeCamera.dirY < -89.9f) freeCamera.dirY = -89.9f;

        std::cout << "Direction: " << freeCamera.dirX << ", " << freeCamera.dirY << std::endl;

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
