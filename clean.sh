#!/bin/bash
find ./ -name "*.o" -type f -delete
find ./ -name "*.a" -type f -delete
echo "--- BUILT FILES REMOVED ---"
