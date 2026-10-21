#!/bin/sh
# Author: Amittai Aviram - aviram@bc.edu

# Variable definitions
PROG=eagle_scanner
HW=pa2
INPUT=input_${HW}
OUTPUT=output.txt
EXPECTED=expected_${HW}.txt

# Remove any remaining artifacts from a previous test run.
make clean > /dev/null
rm -f ${OUTPUT} > /dev/null

# Build the executable (with all warnings and with warnings treated as errors).
make > /dev/null

# Run the program with a valid argument.
# Redirect output to the output file by appending.
./${PROG} ${INPUT}.txt > ${OUTPUT} 2>&1

# Test whether the actual output file matches the
# expected output file.
if diff -q --strip-trailing-cr ${OUTPUT} ${EXPECTED} &> /dev/null
then
    echo "PASSED"
else
    echo "FAILED"
fi

# Clean up.
make clean > /dev/null
rm -f ${OUTPUT} > /dev/null

