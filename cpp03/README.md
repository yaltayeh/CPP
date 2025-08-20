# Movement Debugger with ncurses TUI

## Overview
A C++98-compatible Text User Interface (TUI) debugger that uses **offset-based member access** to capture and navigate through Test class movement states. Enhanced with ncurses for professional terminal interface.

## Features

### 🎨 **Enhanced ncurses Interface**
- **ASCII arrow decorations** throughout the interface (`<== ==>`, `> >`, `^ v`)
- **Box-drawn value display** with `+===+` borders for better readability
- **Progress bar** showing current position with `[###---]` visual indicator
- **Dynamic navigation indicators** (`< PREV | NEXT >`) based on current position
- **Status bar** with real-time messages and arrow decorations
- **Blinking error notifications** with directional cues

### 🎮 **Navigation Controls**
- **`n/N` or `↓/→`** - Navigate to next state
- **`p/P` or `↑/←`** - Navigate to previous state  
- **`q/Q` or `ESC`** - Quit debugger

### 🔧 **Technical Features**
- **Offset-only access**: All values retrieved via `offsetof()` and pointer arithmetic
- **C++98 compatible**: No modern C++ features
- **Fixed-size storage**: Array-based state management
- **Memory-safe**: Bounds checking on navigation

## Files

- `simple_tui.cpp` - Main implementation with ncurses
- `ncurses_tui` - Compiled executable  
- `ncurses_demo.sh` - Demo script with instructions

## Compilation

```bash
g++ -std=c++98 -Wall -Wextra -o ncurses_tui simple_tui.cpp -lncurses
```

## Usage

```bash
# Run with demo script
./ncurses_demo.sh

# Or run directly
./ncurses_tui
```

## Code Structure

### Attribute Definition
```cpp
struct attr_type {
    const char* name;    // "x", "y", "name"
    size_t offset;       // offsetof(Test, member)  
    const char* type;    // "int", "string"
};
```

### Offset-Based Access
```cpp
int getValue(Test* obj, size_t offset) {
    char* base = (char*)obj;
    return *(int*)(base + offset);
}
```

### ncurses Display Features
- **Color pairs** for different UI elements
- **Box drawing** around values
- **Status messages** at screen bottom
- **Arrow key support** for navigation

## Debug States Captured

1. **Initial state**: `x=10, y=20`
2. **move(10, 21)**: First movement
3. **move(11, 20)**: Second movement  
4. **move(12, 20)**: Third movement
5. **move(12, 21)**: Fourth movement
6. **move(12, 22)**: Fifth movement
7. **move(12, 23)**: Final movement

## Requirements

- **ncurses library**: `sudo apt-get install libncurses5-dev`
- **C++98 compiler**: gcc/g++ with C++98 support
- **Terminal**: VT100-compatible terminal emulator

## Screenshot Layout

```
<== Movement Debugger ==>

State: 3/7          < PREV    NEXT >
Operation: move(12, 20)

> Current Values (via offsets):
  +==================+
  | > x: 12          |
  | > y: 20          |
  +==================+

> Navigation Controls:
  ^ UP [p/P] Previous state
  v DOWN [n/N] Next state
  < > Arrow keys also work
  X [q/Q/ESC] Quit

Progress: [######--------------]

<< Use arrows or keys to navigate >>
```

The interface demonstrates how to build a professional debugging tool using only offset-based member access, perfect for low-level debugging and memory inspection scenarios.
