#!/bin/bash
# Script to package Windows version of BCPD

# Clean up any previous package
rm -rf package

# Create package directory
mkdir -p package/gbcpd_windows

# Copy Windows executable and README
cp win/gbcpd.exe package/gbcpd_windows/
cp win/README.md package/gbcpd_windows/

# Create a sample directory with example files
mkdir -p package/gbcpd_windows/samples
if [ -d "data" ]; then
  cp data/*.ply package/gbcpd_windows/samples/ 2>/dev/null || echo "No PLY files found in data directory"
fi

# Create a zip file
cd package
zip -r gbcpd_windows.zip gbcpd_windows/
cd ..

# Clean up temporary directory
rm -rf package/gbcpd_windows

echo "Windows package created at package/gbcpd_windows.zip"
echo "Package contains:"
unzip -l package/gbcpd_windows.zip