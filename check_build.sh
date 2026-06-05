#!/bin/bash

echo "=== ERROR ==="
grep -i -n "error:" build.log

echo
echo "=== FAILURE ==="
grep -i -n "failed\|failure" build.log

echo
echo "=== CMAKE ==="
grep -i -n "cmake error" build.log

echo
echo "=== INJECTOR.CPP ==="
grep -i -n "injector.cpp" build.log

echo
echo "=== LAST 100 LINES ==="
tail -100 build.log
