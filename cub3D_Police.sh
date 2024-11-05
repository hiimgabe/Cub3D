#!/bin/bash

VALID_MAPS_DIR="assets/maps/valid"
INVALID_MAPS_DIR="assets/maps/invalid"
CUB3D="./cub3D"
OUTPUT_FILE="cub3D_police_report.txt"

GREEN="\033[38;5;47m"
YELLOW="\033[38;5;226m"
RED="\033[38;5;196m"
CYAN="\033[1;36m"
RESET="\033[0m"
BLUE="\033[0;34m"
PURPLE="\033[38;5;93m"
ORANGE="\033[38;5;202m"

cub3D_Police_valid()
{
	clear
	echo -e "\n👮 STOP! CUB3D POLICE!! 👮\n"
	echo -e "\n🚨 Starting valid maps check 🚨\n"
	for MAP_PATH in "$VALID_MAPS_DIR"/*; do
		MAP_NAME=$(basename "$MAP_PATH")
		echo -e "${YELLOW}Inspecting${RESET} 👮🔍 $MAP_NAME"
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes $CUB3D "$MAP_PATH" &> "$OUTPUT_FILE" & CUB3D_PID=$!
		CUB3D_WINDOW=$(xdotool search --pid $CUB3D_PID | head -n 1)
		sleep 5
		xdotool key f
		xdotool key space
		sleep 3
		xdotool key Escape
		wait $CUB3D_PID
		if grep -q "Exiting game." "$OUTPUT_FILE" && grep -q "All heap blocks were freed -- no leaks are possible" "$OUTPUT_FILE" && grep -q "FILE DESCRIPTORS: 3 open (3 std) at exit." "$OUTPUT_FILE"; then
        	echo -e "[${GREEN}OK${RESET}] $MAP_NAME\n"
        else
            echo -e "[${RED}FAIL${RESET}] $MAP_NAME\n"
			break
        fi
	done

}


cub3D_Police_invalid()
{
	echo -e "\n🚨 Starting invalid maps check 🚨\n"
	for MAP_PATH in "$INVALID_MAPS_DIR"/*; do
		MAP_NAME=$(basename "$MAP_PATH")
		echo -e "${YELLOW}Inspecting${RESET} 👮🔍 $MAP_NAME"
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes $CUB3D "$MAP_PATH" &> "$OUTPUT_FILE" & CUB3D_PID=$!
		wait $CUB3D_PID
		if grep -q "All heap blocks were freed -- no leaks are possible" "$OUTPUT_FILE" && grep -q "FILE DESCRIPTORS: 3 open (3 std) at exit." "$OUTPUT_FILE" && grep -q "Error:" "$OUTPUT_FILE"; then
        	echo -e "[${GREEN}OK${RESET}] $MAP_NAME\n"
        else
            echo -e "[${RED}FAIL${RESET}] $MAP_NAME\n"
			break
        fi
	done

}

cub3D_Police_valid
cub3D_Police_invalid