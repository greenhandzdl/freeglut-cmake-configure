# FreeGLUT Template

A cross-platform FreeGLUT template project with CMake build configuration.

## Features

- Cross-platform support (macOS with XQuartz, Linux)
- CMake build system with Homebrew integration on macOS
- Clean project structure (src/build/output separation)
- Build and clean scripts
- Basic rotating cube demo

## Prerequisites

### macOS

1. Install XQuartz (required for X11 support):
   ```bash
   brew install --cask xquartz
   ```

2. Install FreeGLUT (optional - can use native macOS GLUT instead):
   ```bash
   brew install freeglut
   ```

3. Install OpenGL (usually comes with Xcode command line tools):
   ```bash
   xcode-select --install
   ```

4. **Recommended: Use native macOS GLUT for better compatibility**
   ```bash
   # Clone and build with native GLUT
   mkdir -p build && cd build
   cmake -DUSE_FREEGLUT=OFF -DCMAKE_BUILD_TYPE=Release ..
   cmake --build . --config Release

   # Run
   cd ..
   ./output/FreeGLUT_Template
   ```

   **Why use native GLUT?** FreeGLUT has known compatibility issues with XQuartz on macOS that can cause segmentation faults. Native macOS GLUT, while deprecated, is more stable.

### Linux (Ubuntu/Debian)

```bash
sudo apt-get install freeglut3-dev libgl1-mesa-dev libglu1-mesa-dev
```

Or on Fedora:
```bash
sudo dnf install freeglut-devel mesa-libGL-devel mesa-libGLU-devel
```

## Project Structure

```
freeglut-template/
├── CMakeLists.txt      # Main CMake configuration
├── README.md           # This file
├── src/                # Source code
│   ├── main.cpp        # Main application
│   └── common.h        # Common headers and macros
├── build/              # Build directory (generated)
├── output/             # Compiled binaries (generated)
└── scripts/            # Utility scripts
    ├── build.sh        # Build script
    ├── clean.sh        # Clean script
    └── run.sh          # Run script
```

## Building

### Quick Build (macOS & Linux)

```bash
# Build (Release mode)
./scripts/build.sh

# Build (Debug mode)
./scripts/build.sh debug

# Run the application
./scripts/run.sh

# Clean build artifacts
./scripts/clean.sh
```

### Manual CMake Build (Recommended for macOS)

**Important for macOS users:** Use native GLUT for better compatibility.

```bash
# Create and navigate to build directory
mkdir -p build && cd build

# Configure (macOS: use native GLUT)
cmake -DUSE_FREEGLUT=OFF -DCMAKE_BUILD_TYPE=Release ..

# Build (IMPORTANT: use this exact command)
cmake --build . --config Release

# Navigate back and run
cd ..
./output/FreeGLUT_Template
```

**For Linux users:**

```bash
# Create and navigate to build directory
mkdir -p build && cd build

# Configure
cmake -DCMAKE_BUILD_TYPE=Release ..

# Build
cmake --build . --config Release

# Navigate back and run
cd ..
./output/FreeGLUT_Template
```

## Controls

| Key | Action |
|-----|--------|
| R | Toggle rotation |
| Space | Reset rotation |
| ESC | Exit |

## Configuration

### Changing the executable name

Edit `CMakeLists.txt` and modify:
```cmake
set(TARGET_NAME "your_app_name")
```

### Using system GLUT instead of FreeGLUT

```bash
cmake -DUSE_FREEGLUT=OFF ..
```

## Troubleshooting

### macOS: Segmentation fault (Exit code: 139)

This is a known issue with FreeGLUT and XQuartz on macOS due to Apple DRI (Direct Rendering Infrastructure) compatibility problems.

**Solutions:**

1. **Restart XQuartz completely:**
   ```bash
   # Kill XQuartz
   killall Xquartz

   # Start XQuartz fresh
   open -a Xquartz

   # Wait a few seconds, then run your program
   ./output/FreeGLUT_Template
   ```

2. **Update XQuartz to the latest version:**
   ```bash
   brew upgrade xquartz
   ```

3. **Use software rendering (slower but more stable):**
   ```bash
   LIBGL_ALWAYS_SOFTWARE=1 ./output/FreeGLUT_Template
   ```

4. **Alternative: Use native macOS GLUT instead of FreeGLUT:**
   Edit `CMakeLists.txt` and set:
   ```cmake
   option(USE_FREEGLUT "Use FreeGLUT instead of system GLUT" OFF)
   ```
   Then rebuild:
   ```bash
   ./scripts/clean.sh
   ./scripts/build.sh
   ```
   Note: macOS native GLUT is deprecated but may be more stable.

5. **Check XQuartz preferences:**
   - Open XQuartz
   - Go to Preferences > Security
   - Enable "Allow connections from network clients"
   - Restart XQuartz

### macOS: "libglut.dylib not found"

Ensure FreeGLUT is installed via Homebrew:
```bash
brew install freeglut
brew link freeglut
```

### macOS: Display issues with XQuartz

1. Start XQuartz first:
   ```bash
   open -a Xquartz
   ```

2. In XQuartz preferences, enable "Allow connections from network clients"

3. Restart XQuartz

### Linux: Missing GLX

Install the required packages:
```bash
# Ubuntu/Debian
sudo apt-get install libglx-mesa0 libglx0

# Fedora
sudo dnf install mesa-libGLX
```

## License

This template is provided as-is for educational purposes.
