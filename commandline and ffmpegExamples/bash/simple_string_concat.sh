#!/bin/bash

GREETING=""
GREETING+=$1
GREETING+=', my name is'
GREETING+=$2
GREETING+=' '
GREETING+=$3 

echo $GREETING