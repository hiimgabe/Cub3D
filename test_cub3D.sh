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

run_tests() {
    local test_type=$1

    if [ "$test_type" = "valid" ] || [ -z "$test_type" ]; then
        echo "Running tests for valid maps..."
        for map in $VALID_MAPS_DIR/*; do
            run_test $map "no"
        done
    fi

    if [ "$test_type" = "invalid" ] || [ -z "$test_type" ]; then
        echo "Running tests for invalid maps..."
        for map in $INVALID_MAPS_DIR/*; do
            run_test $map "yes"
        done
    fi
}

if [ -z "$1" ]; then
    run_tests
else
    if [ "$1" = "valid" ] || [ "$1" = "invalid" ]; then
        run_tests $1
    else
        echo "Usage: $0 [test-type]"
        echo "test-type: valid or invalid"
        exit 1
    fi
fi

echo "All tests completed."
