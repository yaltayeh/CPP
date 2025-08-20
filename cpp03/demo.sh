#!/bin/bash

echo "=== Movement Debugger TUI Demo ==="
echo "This TUI debugger demonstrates:"
echo "1. Storing Test class values using only the attrs offset array"
echo "2. Navigation between different movement states"
echo "3. C++98 compatible implementation"
echo ""
echo "Commands:"
echo "  n - Next state"
echo "  p - Previous state" 
echo "  q - Quit"
echo ""
echo "The program captures 7 movement states and lets you navigate through them."
echo "All values are accessed via memory offsets defined in the attrs array."
echo ""
echo "Press Enter to start the TUI..."
read

./simple_tui
