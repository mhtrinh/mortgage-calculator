#!/bin/bash -x

set -e

/opt/mxe/usr/bin/i686-w64-mingw32.static-qmake-qt5 ../MorgageCalculator.pro

make 

