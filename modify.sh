find src -name "*.c" -exec sed -i 's|#include "../include/|#include "|g' {} +
echo "Process exited success[0]"
