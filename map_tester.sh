#!/bin/bash

################################################################################
#	Automatic tester for so_long		V2	Nathanael Ervin		20/3/22 14:14  #
################################################################################

################################################################################
#	Edit your path here! 													   #
#		path	-	where your maps are stored (maps/basic.ber)				   #
#		program	-	where your so_long program is stored (so_long)			   #
################################################################################
path="maps"
program="bin/so_long"

#	Colors
GREEN=$(tput setaf 2)
NORMAL=$(tput sgr0)
CYAN=$(tput setaf 6)

printf "${GREEN}Starting tests\n${NORMAL}"
for map in $(find $path -type f); do
	printf "Current Map: ${CYAN}%s\n\n${NORMAL}" "$map"
	./$program $map
	printf "\n\n"
done

printf "${GREEN}Stopping tests\n${NORMAL}"
