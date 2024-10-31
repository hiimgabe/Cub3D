#!/bin/bash

VALID_MAPS_DIR="assets/maps/valid"
INVALID_MAPS_DIR="assets/maps/invalid"
EXECUTABLE="./cub3D"

run_test() {
    local map_path=$1
    local expected_error=$2

    valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes $EXECUTABLE $map_path > valgrind_output.txt 2>&1

    if [ "$expected_error" = "no" ]; then
        if grep -q "Error:" valgrind_output.txt; then
            echo "Test failed for valid map: $map_path"
            return 1
        fi
        if ! grep -q "All heap blocks were freed -- no leaks are possible" valgrind_output.txt; then
            echo "Memory leaks detected for valid map: $map_path"
            return 1
        fi
    else
        if ! grep -q "Error:" valgrind_output.txt; then
            echo "Test failed for invalid map: $map_path"
            return 1
        fi
        if ! grep -q "All heap blocks were freed -- no leaks are possible" valgrind_output.txt; then
            echo "Memory leaks detected for invalid map: $map_path"
            return 1
        fi
    fi

    echo "Test passed for map: $map_path"
    return 0
}

if [ "$1" = "valid" ]; then
    # Test valid maps
    for map in $VALID_MAPS_DIR/*; do
        run_test $map "no"
    done
elif [ "$1" = "invalid" ]; then
    # Test invalid maps
    for map in $INVALID_MAPS_DIR/*; do
        run_test $map "yes"
    done
else
    echo "Usage: $0 <test-type>"
    echo "test-type: valid or invalid"
    exit 1
fi

echo "All tests completed."
