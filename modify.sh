#!/bin/bash

# Check if the src directory exists
if [ ! -d "src" ]; then
    echo "src directory does not exist."
    exit 1
fi

find src -name "*.c" -exec sed -i 's|#include "../include/|#include "|g' {} +
echo "Process exited success[0]"
