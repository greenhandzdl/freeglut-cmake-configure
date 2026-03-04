#ifndef FREEGLUT_TEMPLATE_COMMON_H
#define FREEGLUT_TEMPLATE_COMMON_H

// Platform-specific includes for FreeGLUT/GLUT
// The build system defines USE_FREEGLUT when using FreeGLUT

#ifdef __APPLE__
    #define GL_SILENCE_DEPRECATION

    #ifdef USE_FREEGLUT
        // Using FreeGLUT from Homebrew
        #include <GL/freeglut.h>
    #else
        // Using macOS native GLUT framework
        #include <GLUT/glut.h>
    #endif
#else
    // Linux and other platforms use FreeGLUT
    #include <GL/freeglut.h>
#endif

// Common macros and utilities
#define APP_NAME "FreeGLUT Template"
#define APP_VERSION "1.0.0"

// Window defaults
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "FreeGLUT Template Application"

#endif // FREEGLUT_TEMPLATE_COMMON_H
