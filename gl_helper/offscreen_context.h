#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <GL/gl.h>
#include <GL/glx.h>
class Context{
    public:
        typedef GLXContext (*glXCreateContextAttribsARBProc)(Display*, GLXFBConfig, GLXContext, Bool, const int*);
        typedef Bool (*glXMakeContextCurrentARBProc)(Display*, GLXDrawable, GLXDrawable, GLXContext);
        static void Init()
    {
            glXCreateContextAttribsARBProc glXCreateContextAttribsARB ;
            glXMakeContextCurrentARBProc glXMakeContextCurrentARB;
            static int visual_attribs[] = { None };
            int context_attribs[] = {
                GLX_CONTEXT_MAJOR_VERSION_ARB, 3,
                GLX_CONTEXT_MINOR_VERSION_ARB, 0,
                None
            };
            Display* dpy = XOpenDisplay(0);
            int fbcount = 0;
            GLXFBConfig* fbc = NULL;
            GLXContext ctx;
            GLXPbuffer pbuf;
            if ( ! (dpy = XOpenDisplay(0)) ){
                fprintf(stderr, "Failed to open display\n");
                exit(1);
            }
            if ( !(fbc = glXChooseFBConfig(dpy, DefaultScreen(dpy), visual_attribs, &fbcount) ) ){
                fprintf(stderr, "Failed to get FBConfig\n");
                exit(1);
            }
            glXCreateContextAttribsARB = (glXCreateContextAttribsARBProc)glXGetProcAddressARB( (const GLubyte *) "glXCreateContextAttribsARB");
            glXMakeContextCurrentARB = (glXMakeContextCurrentARBProc)glXGetProcAddressARB( (const GLubyte *) "glXMakeContextCurrent");
            if ( !(glXCreateContextAttribsARB && glXMakeContextCurrentARB) ){
                fprintf(stderr, "missing support for GLX_ARB_create_context\n");
                XFree(fbc);
                exit(1);
            }
            if ( !( ctx = glXCreateContextAttribsARB(dpy, fbc[0], 0, True, context_attribs)) ){
                fprintf(stderr, "Failed to create opengl context\n");
                XFree(fbc);
                exit(1);
            }
            int pbuffer_attribs[] = {
                GLX_PBUFFER_WIDTH, 800,
                GLX_PBUFFER_HEIGHT, 600,
                None
            };
            pbuf = glXCreatePbuffer(dpy, fbc[0], pbuffer_attribs);
 
            XFree(fbc);
            XSync(dpy, False);
            if ( !glXMakeContextCurrent(dpy, pbuf, pbuf, ctx) ){
                if ( !glXMakeContextCurrent(dpy, DefaultRootWindow(dpy), DefaultRootWindow(dpy), ctx) ){
                        fprintf(stderr, "failed to make current\n");
                        exit(1);
                }
            }
        }
     
	static void GetPixels(void *data)
	{
		glReadPixels(0,0,800,600,GL_RGB,GL_UNSIGNED_BYTE,data);
	}
 };

