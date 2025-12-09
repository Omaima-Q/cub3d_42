# 1. Explain what you're doing
echo "I'll demonstrate no memory leaks using the leaks command..."

# 2. Run the test
echo "Running: leaks -atExit -- ./cub3d scene.cub"
leaks -atExit -- ./cub3d scene.cub

# 3. While it's running, interact with the program
echo "Now I'll move around and interact extensively to stress-test memory..."
# (Move around, rotate, etc.)

# 4. Exit the program (ESC)
# 5. Point out the results when they appear
