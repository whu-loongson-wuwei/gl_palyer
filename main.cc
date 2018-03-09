#include"gl_helper/offscreen_context.h"
#include"picture/bmp.h"
int main(int argc, const char* argv[]){
    Context.Init();
    glClearColor(0.0,0.25,0.5,0.5);
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT); 
    glFlush();
    unsigned char *a = (unsigned char *)malloc(3*800*600);
    Context.GetPixels(a); 
    SaveBmp("test.bmp",a,800,600);
    return 0;
}
