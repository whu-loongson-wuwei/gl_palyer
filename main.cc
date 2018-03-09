#include"gl_helper/offscreen_context.h"
#include"picture/bmp.h"
int main(int argc, const char* argv[]){
    glClearColor(0,0.25,0.5,0.25);
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT); 
    unsigned char *a = (char *)malloc(3*800*600);
	glReadPixels(0,0,800,600,GL_RGB, GL_UNSIGNED_BYTE,a);
	char *b = (char*)malloc(800*600);
	glReadPixels(0,0,800,600,GL_ALPHA,GL_BYTE,b);
	SaveBmp("test.bmp",800,600)
	printf("%d,%d,%d,%d,%d,%d\n",a[0],a[1],a[2],a[800*600+1],b[0],b[1]);
 	return 0;
}
