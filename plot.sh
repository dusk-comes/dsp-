#!/bin/bash

PLOT=/usr/bin/gnuplot
OPTIONS=-persist
FILENAME=$1
COMMANDS="plot \"${FILENAME}\" using 1:2 with linespoints 7"

${PLOT} ${OPTIONS} << EOFMarker
    ${COMMANDS}
EOFMarker
